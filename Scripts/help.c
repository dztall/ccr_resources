//Authors : Lee Jeong Seop

#include "Garbage_Collector/gc.h"
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
#include "Shell/builtins/printfmacro.h"

char scriptsPathSystem[1024];
char scriptsPathUser[1024];
char proj[2048];

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


				
bool is_dot(const char *localFileName)
{
	if (strcmp(localFileName, ".") == 0) return true;
	if (strcmp(localFileName, "..") == 0) return true;
	return false;
}


bool is_directory(const char * scriptsPath, const char *localFileName)
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

#define is(x) strcmp(str_found, x) == 0

bool print = false;

void list_commands(const char * scriptsPath)
{
	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir(scriptsPath)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			
			if (!is_dot(ent->d_name)) {
				if (!is_directory(scriptsPath, ent->d_name))
				{
					strcat(proj, scriptsPath);
					strcat(proj, "/");
					strcat(proj, ent->d_name);
					//ps(proj)
					char fileName[512];
					strcpy(fileName, ent->d_name);
					char *str_found = NULL;
					// we only remove the first dot, do not remove other dots otherwise the file cannot be executed as its name would be incorrect, eg test.h instead of test (test.h.c)
					if ((str_found = strstr_backward(fileName, ".")) != NULL)
					{
						// reinforce the fact that valid commands MUST be able to be executed
						if (
						
						// list of executable extentions
						
						// start of list
						is(".bc") ||  // LLVM Bytecode
						is(".c") ||   // C
						is(".cc") ||  // C++
						is(".cpp") || // C++
						is(".py") ||  // Python
						is(".pyc") || // Python Compiled Code
						is(".ll") ||  // LLVM Assembly
						is(".ray")    // unknown format that is apparently compilable
						// end of list
						
						) print = true;
						else print = false;
						*str_found = 0;
					}
					if (print == true) if (!access(proj, F_OK)) printf("%s ", fileName);
					memset(proj, 0, 1024);
					memset(fileName, 0, 512);
				}
				else {
					// obey project rule : .../app/app.proj.c:.../app.c
					strcat(proj, scriptsPath);
					strcat(proj, ent->d_name);
					strcat(proj, "/");
					strcat(proj, ent->d_name);
					strcat(proj, ".proj.c");
					if (!access(proj, F_OK)) printf("%s ", ent->d_name);
					memset(proj, 0, 1024);
				}
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
	strcpy(scriptsPathSystem, getenv("CCR_RESOURCE_DIR"));
	strcpy(scriptsPathUser, getenv("CCR_DATA_DIR"));
	strcat(scriptsPathSystem, "/CCR/Scripts");
	strcat(scriptsPathUser, "/CCR/Scripts");

	printf("Available commands : \n\n");
	printf("User Directory: ");
	list_commands(scriptsPathUser);
	printf("\n\nCurrent Working Directory ( ./ ): ");
	list_commands("./");
	printf("\n\nSystem Directory: ");
	list_commands(scriptsPathSystem);
	printf("\n\n");
	return 0;
}
