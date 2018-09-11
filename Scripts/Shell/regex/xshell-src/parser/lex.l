%{
#include <stdio.h>
#include "y.tab.h"
%}
/* http://www.lysator.liu.se/c/ANSI-C-grammar-l.html */
STRINGLITERAL [a-zA-Z_]?\"(\\.|[^\\"])*\"
USERNAME ((^|[ \t\n\r]+)\~[0-9a-zA-Z/:.~\-?*"]*)
VAR [0-9a-zA-Z/:.~\-?*]
%%

"|"					return '|';
"{"					return '{';
"}"					return '}';
";"					return ';';
"$"					return '$';
"&"					return '&';
"~"					return '~';
"<"					return '<';
">"					return '>';
">>"				return STDOUTAPPEND;
"2>&1"				return STDERROUT;
"2>"				return STDERR;

{USERNAME}			{
						yylval.strval = (char*)calloc(strlen(yytext)-1, sizeof(char));
						strncpy(yylval.strval, &yytext[2], strlen(yytext)-1);
						return USERNAME;
					}

{STRINGLITERAL}		{
						yylval.strval = (char*)calloc(strlen(yytext)-1, sizeof(char));
						strncpy(yylval.strval, &yytext[1], strlen(yytext)-2);
						return STRINGLITERAL;
					}

{VAR}+ 				yylval.strval = strdup(yytext); return VAR;

\n					return 0;
[ \t\r]+			/* whitespace */;
. 					yyerror("input is not valid");
%%

