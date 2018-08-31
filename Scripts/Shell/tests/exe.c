#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char ** a = malloc(1);
	a[0] = "/var//mobile/Containers/Data/Application/D306DF46-6C9B-4E6D-90C4-D19B1DA7868D/Documents/Data/CCR/Scripts/argv.c";
	a[1] = NULL;
	execvp(a[0], a);
	free(a);
	return 0;
}
