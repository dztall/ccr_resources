#include "wrappers.h"

int main(int argc, char *argv[])
{
	fprintf(stdin, "test\n");
	fprintf(stdout, "test\n");
	fprintf(stderr, "test\n");
	putchar('a');
	puts("b");
	putc('c', stdout);
	putw('d', stdout);
	fputc('e', stdout);
	fputs("f", stdout);
	return 0;
}
