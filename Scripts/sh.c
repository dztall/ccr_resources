#include "shell.h"

int main(void)
{
	environ_default = env__copy(environ);
	// execution is disabled by default, enable it
	shell.exe = true;
	shell.exebackground = false;
	shell.debug = false;
	shell.debug_calls = false;
	//test_all(1);
	printf("Welcome to %s %s!\n", shell.name, shell.version);
	while(1)
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
		parse(input);
	}
	free(environ_default);
	return 0;
}
