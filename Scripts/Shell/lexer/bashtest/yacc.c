#include "../../Built-Ins/Built-Ins.h"
int main(void)
{
	builtin__coliru("compile", "./parse.y", "mkdir lex ;cd lex ; mv ../main.cpp yacc.y ; mkdir builtins ; touch config.h bashtypes.h bashansi.h filecntl.h chartypes.h memalloc.h bashintl.h shell.h typemax.h trap.h flags.h parser.h mailcheck.h test.h builtins.h builtins/common.h builtins/stdc.h stdc.h builtins/builtext.h shmbutil.h ; echo \\\"/* compiling yacc file\\\"; echo ; yacc --help ; echo ; yacc yacc.y ; echo ; ls -lh ; echo ; gcc y.tab.c ; echo \\\"yacc file compiled */\\\" ; cat y.tab.c", "yy.tab.c");
	//system("./yy.tab.c");
	exit (0);
}
