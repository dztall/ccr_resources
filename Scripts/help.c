#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char scriptsPath[1024];

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

bool is_directory(const char *localFileName)
{
	char *buf;
	size_t len;

	len = strlen(scriptsPath) + strlen(localFileName) + 2;
	buf = malloc(len);

	if (buf)
	{
		snprintf(buf, len, "%s/%s", scriptsPath, localFileName);

		struct stat statbuf;
		if (!stat(buf, &statbuf))
		{
			free(buf);
			if (S_ISDIR(statbuf.st_mode))
				return true;
		}
		else
			free(buf);
	}
	return false;
}

void list_commands()
{
	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir(scriptsPath)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (!is_directory(ent->d_name))
			{
				char fileName[512];
				strcpy(fileName, ent->d_name);
				char *str_found = NULL;
				if ((str_found = strstr_backward(fileName, ".")) != NULL)
				{
					*str_found = 0;
					if (*(str_found + 1) == 'h')
						continue;
				}
				if ((str_found = strstr_backward(fileName, ".")) != NULL)
					*str_found = 0;
				printf("%s ", fileName);
			}
		}
		closedir(dir);
	}
	else
	{
		perror(scriptsPath);
		return;
	}
}

int main()
{
	strcpy(scriptsPath, getenv("CCR_RESOURCE_DIR"));
	strcat(scriptsPath, "/CCR/Scripts");

	printf("Available commands : \n");
	list_commands();
	printf("\n");
	return 0;
}