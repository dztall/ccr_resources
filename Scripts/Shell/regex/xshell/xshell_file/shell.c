//
// Shell Project
//
#include "shell.h"

//
// Built-ins
//
void xsetenv(char* name, char* value) {
	int success = setenv(name, value, 1);
	if (success == 0) printf("Variable %s set to %s. \n", name, value);
	else printf(KRED "[xshell] could not set %s as %s. \n" RESET, name, value);
}

void xprintenv() {
	int i = 0;
	while (environ[i]) {
		printf("%s \n", environ[i++]);
	}
}

void xunsetenv(char* name) {
	int success = unsetenv(name);
	if (success != 0) printf(KRED "[xshell] could not remove %s. \n" RESET, name);
}

void xcd(char* path) {
	if (path == NULL) {
		char* home = getenv("HOME");
		chdir(home);
	}
	else {
		if (chdir(path) == -1) {
			printf(KRED "[xshell] %s is not a valid directory. \n" RESET, path);
		}
	}
}
	
char* xgetalias(char* name) {
	char* temp = llGetAlias(aliasTable, name);
	//if (temp == NULL) printf(KRED "[xshell] %s was not found or is circular. \n" RESET, name);
	return temp;
}

void xsetalias(char* name, char* value) {
	printf("Alias %s set to %s. \n", name, value);
	llPushAlias(aliasTable, name, value);
}

void xprintalias() {
	llPrint(aliasTable);
}

void xunalias(char* name) {
	printf("Alias %s removed. \n", name);
	llRemove(aliasTable, name);
}

void xbye() {
	printf(KBLU "leaving [xshell]\n" RESET);
	llFree(aliasTable);
	chainReset(chainTable);
	free(chainTable);
	exit(0);
}

//
// Externals
//
void xexecute(ll* list) {
	//fprintf(stderr, KGRN "Executing %s \n" RESET, list->start->name);

	// See if command exists
	char* path = xpathlookup(list->start->name);

	if (path != NULL) {
		// matched command from path
		list->start->name = path;
	}
	else {
		// invalid command, exit
		fprintf(stderr, KRED "[xshell] could not find command %s. \n" RESET, list->start->name);
		return;
	}

	// Time to execute
	int status;
	int background = chainTable->background; // 0 - not in background, 1 - in bg
	pid_t pid = fork();

	if (pid == -1) {
		// error
		fprintf(stderr, KRED "[xshell] could not fork %s. \n" RESET, list->start->name);
		perror("error creating fork");
		return;
	}

	if (pid == 0) {
		signal(SIGQUIT, SIG_DFL); // to quit child if nes
		signal(SIGINT, SIG_DFL);
		
		// dont show output in shell if not redirected and in background
		if (background == 1 && chainTable->fileOut == NULL) freopen("/dev/null", "w", stdout);
		if (background == 1 && (chainTable->fileErrorOut == NULL && chainTable->fileErrorStdout == 0)) freopen("/dev/null", "w", stderr);
		
		node* current = list->start;

		// Parse list into argv
		char** argv = calloc(list->count + 1, sizeof(char*));
		argv[list->count] = NULL; // NULL terminator

		int i;
		// no while loop, we need an index for argv
		for (i = 0; i < list->count; i++) {
			argv[i] = current->name;
			current = current->next;
		}

		execve(argv[0], argv, environ);

		exit(0); // quit so your child doesn't end up in the main program
	}
	else {
		// in parent
		llFree(list); // no longer needed
		if ((chainTable->piped == 0 && background == 0) || (chainTable->piped == 1 && chainTable->firstpiped == 1 && background == 0)) {
			waitpid(pid, &status, 0);
		}
	}
}

char* xpathlookup(char* command) {
	// command already absolute, works as given
	if (access(command, X_OK) == 0) return command;

	// look if command is in one of the paths
	char* path = strdup(getenv("PATH"));
	char* parsedPath = strtok(path, ":");

	while (parsedPath != NULL) {
		char* result = malloc(strlen(command) + strlen(parsedPath) + 2); // +1 for null, +1 for slash
		strcpy(result, parsedPath);
		strcat(result, "/");
		strcat(result, command);

		// found the winning path!
		if (access(result, X_OK) == 0) {
			return result;
		}

		// next token
		free(result);
		result = NULL;
		parsedPath = strtok(NULL, ":");
	}

	// not found
	return NULL;
}

//
// xshell code
//
void min() {
	fprintf(stderr, KRED "Missing required arguments. \n" RESET);
	return;
}

void ignore(int number) {
	if (number < 2) fprintf(stderr, KYEL "Ignoring last additional argument. \n" RESET);
	else fprintf(stderr, KYEL "Ignoring last %d additional arguments. \n" RESET, number);
}

void restoreio() {
	//printf("flush\n");
   	fflush(stdin);
   	dup2(default_stdin, STDIN_FILENO);
  	fflush(stdout);
   	dup2(default_stdout, STDOUT_FILENO);
   	fflush(stderr);
	dup2(default_stderr, STDERR_FILENO);
}

void xshell(ll* list) {
	if (list == NULL || list->start == NULL) return;
	char* command = list->start->name;
	int count = list->count;

	// Check if built in or command
	if (strcmp(command, "setenv") == 0) {
		if (count < 3) {min(); return;}
		else if (count > 3) ignore(count - 3);

		llPop(list); // ignore command name
		char *a = llPop(list), *b = llPop(list);
		xsetenv(a, b);
	}

	else if (strcmp(command, "printenv") == 0) {
		if (count > 1) ignore(count - 1);
		xprintenv();	
	}

	else if (strcmp(command, "unsetenv") == 0) {
		if (count < 2) {min(); return;}
		else if (count > 2) ignore(count - 2);

		llPop(list); // ignore command name
		xunalias(llPop(list));
	}

	else if (strcmp(command, "cd") == 0) {
		if (count > 2) ignore(count - 2);
		
		llPop(list); // ignore command name
		xcd(llPop(list));
	}

	else if (strcmp(command, "alias") == 0) {
		if (count > 3) ignore(count - 3);

		llPop(list); // ignore command name
		char* name = llPop(list);
		char* value = llPop(list);

		if (name != NULL) {
			if (value != NULL) {
				xsetalias(name, value);
			}
			else {
				xgetalias(name);
			}
		}
		else {
			xprintalias();
		}
	}

	else if (strcmp(command, "unalias") == 0) {
		if (count > 1) ignore(count - 1);
		
		llPop(list); // ignore command name
		xunalias(llPop(list));
	}

	else if (strcmp(command, "bye") == 0) {
		xbye();
	}
	
	else {
		// try executing
		xexecute(list);
	}

	// return io redirections to normal
	restoreio();
}

char* getaline() {
	// stackoverflow 314422
	char * line = malloc(100), * linep = line;
	size_t lenmax = 100, len = lenmax;
	int c;

	if(line == NULL)
		return NULL;

	for(;;) {
		c = fgetc(stdin);
		if(c == EOF)
			break;

		if(--len == 0) {
			len = lenmax;
			char * linen = realloc(linep, lenmax *= 2);

			if(linen == NULL) {
				free(linep);
				return NULL;
			}
			line = linen + (line - linep);
			linep = linen;
		}

		if((*line++ = c) == '\n')
			break;
	}
	*line = '\0';
	return linep;
}

// The main function that checks if two given strings match. The first
// string may contain wildcard characters
// geeksforgeeks.org/wildcard-character-matching
bool match(char *first, char * second) {
	// If we reach at the end of both strings, we are done
	if (*first == '\0' && *second == '\0')
		return true;
 
	// Make sure that the characters after '*' are present in second string.
	// This function assumes that the first string will not contain two
	// consecutive '*' 
	if (*first == '*' && *(first+1) != '\0' && *second == '\0')
		return false;
 
	// If the first string contains '?', or current characters of both 
	// strings match
	if (*first == '?' || *first == *second)
		return match(first+1, second+1);
 
	// If there is *, then there are two possibilities
	// a) We consider current character of second string
	// b) We ignore current character of second string.
	if (*first == '*')
		return match(first+1, second) || match(first, second+1);
	return false;
}

char* expand_aliases(char* s) {
	// based on stackoverflow 4693942 and 12460480
	char *str = strdup(s);
	char *end_str;
	char *token = strtok_r(str, " \t\n", &end_str);

	char *newStr = "";

	while (token != NULL) {
		//printf("[%s]\n", token);

		char *end_token;
		char *dup = strdup(token);

		char* alias = xgetalias(token);
		char* temp;

		if (alias != NULL) {
			temp = malloc(strlen(newStr) + strlen(alias) + 1);
			strcpy(temp, newStr);
			strcat(temp, alias);
		}
		else {
			temp = malloc(strlen(newStr) + strlen(token) + 1);
			strcpy(temp, newStr);
			strcat(temp, token);
		}

		strcat(temp, " ");
		newStr = temp;

		/*char *token2 = strtok_r(token, "&|", &end_token);

		int i = 0;
		while (token2 != NULL) {
			printf("\t[%c] %s\n", dup[token2-token-1], token2);

			char *temp;
			if (i != 0) temp = malloc(strlen(newStr) + strlen(&dup[token2-token-1]) + strlen(token2));
			else temp = malloc(strlen(newStr) + strlen(token2));
			strcpy(temp, newStr);
			if (i != 0) strcat(temp, &dup[token2-token-1]); // add delimiter
			strcat(temp, token2); // add token
			newStr = temp;

			token2 = strtok_r(NULL, "&|", &end_token);
			i++;
		}

		char *temp;
		if (i == 0) {
			temp = malloc(strlen(newStr) + strlen(token) + 1);
			strcpy(temp, newStr);
			strcat(temp, token); // add delimiter
			strcat(temp, " "); // add space
		}
		else {
			temp = malloc(strlen(newStr) + 1);
			strcpy(temp, newStr);
			strcat(temp, " "); // add space
		}
		newStr = temp;*/

		token = strtok_r(NULL, " \t\n", &end_str);
	}
	
	//printf("%s\n", newStr);
	return newStr;
}

char* expand_environment_variables(char* s) {
	// based on stackoverflow 20715800
	char* x = strstr(s, "${");
	char* xx = strstr(s, "}");
	if (x == NULL || xx == NULL) return s;

	int length = strlen(s);
	int preSize = x-s;
	int postSize = length - (xx-s) - 1; // -1 for }
	int varSize = length - preSize - postSize - 3; // -3 for ${}

	char* pre = malloc(sizeof(char) * (preSize + 2));
	char* post = malloc(sizeof(char) * (postSize + 2));
	char* var = malloc(sizeof(char) * (varSize + 2));

	int i;
	for (i = 0; s[i]; i++) {
		if (i < preSize) pre[i] = s[i];
		if (i > preSize+1 && i < preSize+varSize+2) var[i-(preSize+2)] = s[i];
		if (i > preSize+varSize+2) post[i-(preSize+varSize+3)] = s[i];
	}
	
	char* y = getenv(var);
	if (y == NULL) {
		fprintf(stderr, KRED "[xshell] %s is not a valid environment variable. \n" RESET, var);
		return s;
	}
	
	strcat(pre, y);
	strcat(pre, post);
	//if (post != NULL) free(post);
	//if (var != NULL) free(var);
	return expand_environment_variables(pre);
}

void shell_init() {
	// init storage
	aliasTable = llCreate(0);
	chainTable = chainCreate(0);

	default_stdin = dup(STDIN_FILENO);
	default_stdout = dup(STDOUT_FILENO);
	default_stderr = dup(STDERR_FILENO);

	/*llPush(aliasTable, "a", "c a");
	llPush(aliasTable, "b", "d");
	llPush(aliasTable, "c", "a");
	llPush(aliasTable, "d", "dfinal");
	llPush(aliasTable, "q", "pwd");
	llPush(aliasTable, "w", "ls");
	
	ll* a = llCreate(1);
	llPush(a, "0", NULL);
	llPush(a, "1", NULL);
	llPush(a, "2", NULL);
	
	ll* b = llCreate(1);
	llPush(a, "b", NULL);
	llPush(a, "c", NULL);
	llPush(a, "d", NULL);*/
	
	// disable anything that can kill your shell. 
	signal(SIGINT, SIG_IGN);  // Ctrl-C
	signal(SIGQUIT, SIG_IGN); // Ctrl-backslash
	signal(SIGTSTP, SIG_IGN); // Ctrl-Z
}

int recover_from_errors() {
	fprintf(stderr, KRED "[xshell] cannot continue processing, recovering... \n" RESET);
}

int main(int argc, char *argv[]) {
	shell_init();
	printf(KBLU "starting [xshell] \nbuilt %s %s\n" RESET, __DATE__, __TIME__);
	
	int redirected = 0;
	if (!isatty(STDIN_FILENO)) redirected = 1;

	/*char* input = getaline();
	while (strlen(input) != 0) {
		printf("%s\n", input);
		input = getaline();
	}*/

	while (1) {
		// print current directory
		if (redirected == 0) {
			char* pwd = get_current_dir_name();
			printf(KMAG "%s> " RESET, pwd);
		}

		// get input
		char* input = getaline();
		if (redirected == 1) {
			if (strlen(input) == 0) {
				//printf("\n");
				xbye();
			}
			//else printf("%s", input);
		}

		// process input
		input = expand_aliases(input);
		input = expand_environment_variables(input);
		
		//printf(KCYN "%lu" RESET, strlen(input));

		yy_scan_string(input);
		if (yyparse() == 1) recover_from_errors();
		chainTable->parsed = 1;

		// if there is input, reparse
		/*if (chainTable->fileIn != NULL) {
			FILE* in = freopen(chainTable->fileIn, "r", stdin);
			if (in == NULL) {
				restoreio();
				fprintf(stderr, "[xshell] problem opening %s for input. \n", chainTable->fileIn);
				chainReset(chainTable); // kill following cmds
			}
			
			char* input2 = getaline();

			while (strlen(input2) != 0) {
				//printf("%s", input2);
				yy_scan_string(input2);
				if (yyparse() == 1) recover_from_errors();
				input2 = getaline();
			}

		   	fflush(stdin);
		   	dup2(default_stdin, STDIN_FILENO);
		}*/

		// process chain
		
		// piping
		if (chainTable->piped == 1) {
			// so 8389033
			// these commands are piped
			
			// redirect all errors
			if (chainTable->fileErrorOut != NULL) {
				FILE* errout = freopen(chainTable->fileErrorOut, "a", stderr);
				if (errout == NULL) {
					// couldnt open file
					restoreio();
					fprintf(stderr, "Cannot open %s as File IO_ERR \n", chainTable->fileErrorOut);
					chainReset(chainTable); // kill following cmds
					return;
				}
				//fprintf(stderr, "STDError to %s \n", chainTable->fileErrorOut);
			}
			else if (chainTable->fileErrorStdout == 1) {
				//fprintf(stderr, "STDError to stdout \n");
				dup2(STDOUT_FILENO, STDERR_FILENO);
			}
			
			// Check for io output redirections
			if (chainTable->fileOut != NULL) {
				char* mode;
				if (chainTable->fileOutMode == 1) mode = "a";
				else mode = "w";

				FILE* out = freopen(chainTable->fileOut, mode, stdout);
				if (out == NULL) {
					// couldnt open file
					restoreio();
					fprintf(stderr, "Problem opening %s for output. \n", chainTable->fileOut);
					chainReset(chainTable); // kill following cmds
					return;
				}
			}

			int i;
			int numPipes = chainTable->count - 1;
			int pipefds[numPipes];

			for (i = 0; i <= numPipes; i++){
				if (pipe(pipefds + i*2) < 0) {
					fprintf(stderr, KRED "[xshell] problem creating pipes. \n" RESET);
					break;
				}
			}

			ll* command = chainPop(chainTable);
			int commandc = 0;
			int inputFail = 0;

			while (command != NULL) {
				// if first
				if (numPipes == chainTable->count) {
					//fprintf(stderr, KCYN "[xshell] piping commands. \n" RESET);
					chainTable->firstpiped = 1;
					
					// Check for io output redirections
					if (chainTable->fileIn != NULL) {
						FILE* in = freopen(chainTable->fileIn, "r", stdin);
						if (in == NULL) {
							restoreio();
							fprintf(stderr, "[xshell] problem opening %s for input. \n", chainTable->fileIn);
							chainReset(chainTable); // kill following cmds
							inputFail = 1;
							break;
						}
					}
				}
				else chainTable->firstpiped = 0;
			
				// child gets input from the previous command, if it's not the first command
				if (numPipes != chainTable->count) {
					if (dup2(pipefds[(commandc-1)*2], 0) < 0) {
						perror("[xshell] error in dup2");
						break;
					}
				}
				// child outputs to next command, if it's not the last command
				if (chainTable->count != 0) {
					if (dup2(pipefds[commandc*2+1], 1) < 0) {
						perror("[xshell] error in dup2");
						break;
					}
				}

				// close all pipe-fds if last
				if (chainTable->count == 0) {
					int j;
					for (j = 0; j < 2*numPipes; j++) {
						close(pipefds[j]);
					}

					if (chainTable->fileOut != NULL) {
						char* mode;
						if (chainTable->fileOutMode == 1) mode = "a";
						else mode = "w";

						FILE* out = freopen(chainTable->fileOut, mode, stdout);
						if (out == NULL) {
							// couldnt open file
							restoreio();
							fprintf(stderr, "Problem opening %s for output. \n", chainTable->fileOut);
							chainReset(chainTable); // kill following cmds
						}
					}
				}

				xshell(command);
				//fprintf(stderr, "step %d\n", i);
				command = chainPop(chainTable);
				commandc++;
			}
			
			if (inputFail == 1) return;
			
			//fprintf(stderr, "Return.");
			
			// parent closes all of its copies at the end
			for (i = 0; i < 2 * numPipes; i++){
				close(pipefds[i]);
			}
		}
		else {
			// no pipes
			
			// Check for io output redirections
			if (chainTable->fileIn != NULL) {				
				FILE* in = freopen(chainTable->fileIn, "r", stdin);
				if (in == NULL) {
					restoreio();
					fprintf(stderr, "[xshell] problem opening %s for input. \n", chainTable->fileIn);
					chainReset(chainTable); // kill following cmds
					return;
				}
			}

			if (chainTable->fileOut != NULL) {
				char* mode;
				if (chainTable->fileOutMode == 1) mode = "a";
				else mode = "w";

				FILE* out = freopen(chainTable->fileOut, mode, stdout);
				if (out == NULL) {
					// couldnt open file
					restoreio();
					fprintf(stderr, "Problem opening %s for output. \n", chainTable->fileOut);
					chainReset(chainTable); // kill following cmds
					return;
				}
			}
	
			if (chainTable->fileErrorOut != NULL) {
				FILE* errout = freopen(chainTable->fileErrorOut, "a", stderr);
				if (errout == NULL) {
					// couldnt open file
					restoreio();
					fprintf(stderr, "Cannot open %s as File IO_ERR \n", chainTable->fileErrorOut);
					chainReset(chainTable); // kill following cmds
					return;
				}
				//fprintf(stderr, "STDError to %s \n", chainTable->fileErrorOut);
			}
			else if (chainTable->fileErrorStdout == 1) {
				//fprintf(stderr, "STDError to stdout \n");
				dup2(STDOUT_FILENO, STDERR_FILENO);
			}

			if (chainTable->background == 1) {
				//fprintf(stderr, "Process in background \n");
			}
			
			ll* command = chainPop(chainTable);
			while (command != NULL) {
				xshell(command);
				command = chainPop(chainTable);
			}

			restoreio();
		}

		// free up memory
		if (strlen(input) != 0) free(input);
		chainReset(chainTable);
	}
}

