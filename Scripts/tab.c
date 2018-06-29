#include <ccr.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		int tabSize = ccrGetTextOutputTabSize();
		printf("Tab size : %d\n", tabSize);
		return 0;
	}

	int tabSize = atoi(argv[1]);
	ccrSetTextOutputTabSize(tabSize);

	return 0;
}