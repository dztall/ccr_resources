//Authors : Lee Jeong Seop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ccr.h>

char *strstr_backward(char *str, const char *str_find)
{
	char *str_found_backward = NULL;
	char *str_found = NULL;
	size_t position = 0;

	while ((str_found = (char *)strstr(str + position, str_find)) != NULL)
	{
		str_found_backward = str_found;
		position = (str_found - str) + 1;
	}

	return str_found_backward;
}

char *GetLastPathComponent(const char *path)
{
	char parentDir[512];
	strcpy(parentDir, path);
	char *str_found = NULL;
	if ((str_found = strstr_backward(parentDir, "/")) != NULL)
		return str_found + 1;
	return "";
}

char *getcwd(char *buf, size_t size);
int main()
{
	printf("Mobile C Shell 1.0.0\n");
	printf("Type 'help' to see available commands.\n");
	printf("\n");

	while (ccrGetEvent(true) != CCR_EVENT_QUIT)
	{
		char cwd[1024] = { 0, };
		getcwd(cwd, 1024);
		printf("%s> ", GetLastPathComponent(cwd));
		char line[1024];
		scanf("%[^\n]%*c", line);
		cppRunSystemCommand(line, false, false);
		if (ccrGetTextOutputLastCharacter() != '\n')
		{
			//TRICK : Append space before new line for scanf not to return.
			printf(" \n");
		}
	}

	return 0;
}
