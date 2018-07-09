//Authors : Lee Jeong Seop

//This program installs dropbox sdk to Mobile C app.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if(access(__APP_DIR__ "/bin/pip", F_OK) == -1)
	{
		printf("%s", "Error : Install pip first, by running 'install_python_pip.c' located in the same folder.\n");
		return 0;
	}
	
	system("pip install dropbox");
	
	return 0;
}
