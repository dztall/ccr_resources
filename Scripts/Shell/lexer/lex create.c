#include "../Built-Ins/Built-Ins.h"
int main(void)
{
	builtin__coliru("compile", "./lex.l", "mkdir lex ;cd lex ; mv ../main.cpp lex.l ; echo \\\"/* compiling lex file\\\"; echo ; lex --help ; echo ; lex -T -p -v -d lex.l ; echo ; ls -l ; echo ; gcc lex.yy.c ; echo \\\"a && b;\\\" > test.sh ; echo \\\"a=8;\\\" >> test.sh ; cat -n test.sh ; ./a.out ; echo \\\"lex file compiled */\\\" ; cat lex.yy.c", "lex.yy.c");
	system("./lex.yy.c");
	exit (0);
}
