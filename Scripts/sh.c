//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Shell/shell.h"

int main(void)
{
	shell.exe = true;
	shell.exebackground = false;
	shell.debug = false;
	shell.debug_calls = false;
	printf("Welcome to %s %s!\n", shell.name, shell.version);
	int status = 0;
	while(status == 0)
	{
		// clear last input
		prompt();
		getline_stdin(&input);
		DEBUG printf("recieved %s\n", quote(input));
		status = parse(input);
		DEBUG pi(status);
	}
	free(input);
	return 0;
}
