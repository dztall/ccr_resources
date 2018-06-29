#include <stdio.h>
#include <unistd.h>
#include <ccr.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("error : no input file.\n");
		return 0;
	}

	char *fileName = argv[1];

	if (access(fileName, F_OK) == -1)
	{
		//Create empty text file.
		fclose(fopen(fileName, "wt"));
	}

	ccrEditFile(fileName);

	return 0;
}