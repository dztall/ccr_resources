//Authors : Lee Jeong Seop

//This program installs and updates a pip python tool to Mobile C app.

#include <stdlib.h>

int main()
{
	system("python -m ensurepip --default-pip");
	system("python -m pip install --upgrade pip setuptools wheel");
	
	return 0;
}
