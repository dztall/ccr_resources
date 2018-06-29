#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *strstr_backward(char *str, const char *str_find)
{
	char *str_found_backward = NULL;
	char *str_found = NULL;
	size_t position = 0;

	while ((str_found = strstr(str + position, str_find)) != NULL)
	{
		str_found_backward = str_found;
		position = (str_found - str) + 1;
	}

	return str_found_backward;
}

void up_command()
{
	char cwd[1024];
	getcwd(cwd, 1024);

	char *str_found = NULL;
	if ((str_found = strstr_backward(cwd, "/")) != NULL)
		*str_found = 0;

	chdir(cwd);
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
		return 0;

	char *target = argv[1];

	if (!strcmp(target, "."))
		return 0;
	else if (!strcmp(target, ".."))
		up_command();
	else if (!strcmp(target, "~"))
		chdir(__DOC_DIR__);
	else if (!strcmp(target, "/"))
		chdir(getenv("HOME"));
	else
	{
		char cwd[1024];
		getcwd(cwd, 1024);

		if (cwd[0])
			strcat(cwd, "/");

		strcat(cwd, target);
		if (chdir(cwd) == -1)
			printf("%s : No such directory\n", target);
	}

	return 0;
}