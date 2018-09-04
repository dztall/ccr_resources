%{
#include "shell.h"
extern int yyterminate;

void yyerror(const char* str) {
	fprintf(stderr, KRED "[xshell] %s \n" RESET, str);
	// unusable command chain
	chainReset(chainTable);
}

int yywrap() {
	return 1;
}

%}
%error-verbose
%union {
	int intvar;
	char* strval;
	void* linkedlist;
}
%token STDOUTAPPEND STDERROUT STDERR BACKGROUND
%token <strval> VAR
%token <strval> USERNAME
%token <strval> STRINGLITERAL
%type <linkedlist> arguments
%type <strval> ignore
%type <strval> argument
%%

commands: 
	/* blank */
	| commands command;

command:
	arguments {
		chainPush(chainTable, $1);
		YYACCEPT;
	};

arguments:
	argument {
		// First word
		ll* list = llCreate(1);
		llPush(list, $1, NULL);
		$$ = list;
	}
	| ignore {
		ll* list = llCreate(1);
		$$ = list;
	}
	| arguments '|' {
		chainPush(chainTable, $1);
		chainTable->piped = 1;
		$$ = llCreate(1);
	}
	| arguments ignore {
		/*if (chainTable->background == 1 && chainTable->parsed == 0) {
			// make sure & is last thing processed
			yyerror("& must be placed at the end of commands.");
			YYERROR;
		}*/

		$$ = $1;
	}
	| arguments argument {
		/*if (chainTable->background == 1) {
			// make sure & is last thing processed
			yyerror("& must be placed at the end of commands.");
			YYERROR;
		}*/
		if ((chainTable->fileIn != NULL || chainTable->fileOut != NULL ||
			(chainTable->fileErrorOut == NULL && chainTable->fileErrorStdout == 1) ||
			(chainTable->fileErrorOut != NULL && chainTable->fileErrorStdout == 0)) &&
			chainTable->parsed == 0
		) {
			// make sure any IO redirection is after aruguments
			yyerror("IO redirection must be placed after any commands.");
			YYERROR;
		}
	
		llPush($1, $2, NULL);
		$$ = $1;
	};

ignore:
	STDERROUT {
		//printf("srderr to stdout \n");
		chainTable->fileErrorOut = NULL;
		chainTable->fileErrorStdout = 1;
	}
	| STDERR VAR {
		//printf("srderr to file \n");
		chainTable->fileErrorOut = $2;
		chainTable->fileErrorStdout = 0;
	}
	| '&' {
		//printf("external run plz \n");
		chainTable->background = 1;
	}
	| '<' VAR {
		//printf("file in \n");
		chainTable->fileIn = $2;
	}
	| STDOUTAPPEND VAR {
		chainTable->fileOut = $2;
		chainTable->fileOutMode = 1;
	}
	| '>' VAR {
		chainTable->fileOut = $2;
		chainTable->fileOutMode = 0;
	};
	
argument:
	USERNAME {
		if (strcmp($1, "") == 0) {
			$$ = getenv("HOME");
		}
		else {
			char* str = strdup($1);
			char* slash = strstr(str, "/");
			char* username;
			
			// get username
			if (slash == NULL) username = str;
			else {
				if (slash - str < 1) {
					$$ = getenv("HOME");
				}

				username = malloc(sizeof(char) * (slash - str) + 1);
				strncpy(username, str, slash - str);
			}

			// get working dir
			struct passwd* userinfo = getpwnam(username);

			if (userinfo == NULL) {
				fprintf(stderr, "[xshell] user %s was not found. \n", username);
				$$ = $1;
			}
			else {
				char* workingDir = userinfo->pw_dir;
				char* newStr = malloc(strlen(str) + strlen(workingDir) + 1);
				strcpy(newStr, workingDir);
				
				int i;
				for (i = 0; i < strlen(str); i++) {
					newStr[strlen(workingDir) + i] = str[strlen(username) + i];
				}
	
				//printf("user path lookup [%s] \n", newStr);
				$$ = newStr;
			}
		}
	}
	| STRINGLITERAL {
		$$ = $1;
	}
	| VAR {
		// so 4204666
		char* str = strdup($1);
		char* wildcard = strstr(str, "*");
		char* question = strstr(str, "?");

		if (wildcard != NULL || question != NULL) {
			int found = 0;
			DIR *d;
			struct dirent *dir;
			d = opendir(".");
			if (d) {
				while ((dir = readdir(d)) != NULL) {
					if (dir->d_type == DT_REG) {
						// is really a file, now match
						if (match(str, dir->d_name)) {
							found = 1;
							fprintf(stderr, KBLU "[xshell] replacing %s with %s \n" RESET, str, dir->d_name);
							str = strdup(dir->d_name);
							break;
						}
						//else printf("not a match [%s] \n", dir->d_name);
					}
				}
				closedir(d);
				//printf("%s", str);
				$$ = str;
			}
			
			if (found == 0) {
				// remove *
				if (wildcard != NULL) {
					int idxToDel = wildcard - str;
					memmove(&str[idxToDel], &str[idxToDel + 1], strlen(str) - idxToDel);
					//printf("[%d] %s\n", idxToDel, str);
				}
			}
		}
		
		$$ = str;		
	};
%%

