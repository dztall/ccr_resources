FILE * yyin
%{
size_t line = 1;
#define shcommand 0
#define shident 1
#define shnewline 2
#define shand 3
#define shfunction 4
#define shcommand2 5
#define shblockstart 6
#define shblockend 7
#define sharray 8
#define shvar 9
#define shcommandsubstitution 10

%}
%option never-interactive
%option nodefault
%option nounistd
%option nounput
%option noyywrap
%option yylineno

%%
<<EOF>>						{ return EOF; /* valid */ }
[a-zA-Z]*"()" 				{ return shfunction; /* valid */}
"{" 									{ return shblockstart; /* valid */}
"}" 									{ return shblockend; /* valid */}
"${"*"[]"*"}"				{ return sharray; }
"$"*[a-zA-Z]*" " 		{ return shvar; }
"$"*[a-zA-Z]*"\n" 		{ line++; return shvar; }
"$("*")"							{ return shcommandsubstitution; }
[a-zA-Z]+   					{ return shident; /* valid */}
"&&"        						{ return shand; /* valid */}
";"        							{ return shcommand; /* valid */}
"\n"        						{ line++; return shcommand2; /* valid */}
.           							{ /* skip everything else */ }
%%

void parsefile(const char * file, int lines)
{
	yyin = fopen(file, "r");
	#ifdef __CCR__
	// for files created on C Mobile the first 3 bytes of the file are unknown and cannot be represented in printable ascii, we skip those
	fseek(yyin, 3, SEEK_SET );
	#endif
	int token, vtok;
	token = yylex();
	int keepgoing = 1;
    while (keepgoing) {
		printf("token line = %d", line);
		if (line > lines) { keepgoing = 0; break;}
		switch(token) {
			case shvar: printf(", variable: \"%s\"", yytext); break;
			case sharray: printf(", array: \"%s\"", yytext); break;
			case shcommandsubstitution: printf(", shcommandsubstitution: \"%s\"", yytext); break;
			case shident: printf(", identifier: \"%s\"", yytext); break;
			case shand: printf(", AND: \"%s\"", yytext);  break;
			case shcommand: printf(", command: \"%s\"", yytext); break;
			case shcommand2: printf(", command: \"<new-line>\""); break;
			case shfunction: printf(", function: \"%s\"\n", yytext); break;
			case EOF: keepgoing = 0; break;
		}
    	printf(", token = %d (%s)\n", token, yytext);
    	token = yylex();
    }
	fclose(yyin);
}

int main()
{
	parsefile("test.sh", 6);
	return 1;
}