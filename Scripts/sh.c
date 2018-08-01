#include "shell.h"

int main(void)
{
	// execution is disabled by default, enable it
	shell.exe = true;
	printf("Welcome to %s %s!\n", shell.name, shell.version);
	int status = 0;
	while(status == 0)
	{
		// clear last input
		memset(input, 0, MAX);
		prompt();
		charcurrent = 0;
		while(charcurrent!='\n') {
			charcurrent = getchar();
			if (charcurrent != '\n') sprintf(input, "%s%c", input, charcurrent);
		}
		DEBUG printf("recieved %s\n", quote(input));
		status = parse(input);
		DEBUG pi(status);
	}
	
	return 0;
}
