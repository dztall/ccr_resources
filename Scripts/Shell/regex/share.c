#include "../Built-Ins/Built-Ins.h"
int main(void)
{
	builtin__coliru("share", "../Built-Ins/bom.c", "mv ./main.cpp main.c ; gcc main.c; ./a.out", NULL);
	builtin__coliru("compile", "../Built-Ins/bom.c", "mv ./main.cpp main.c ; gcc main.c; ./a.out", NULL);
	exit (0);
}
