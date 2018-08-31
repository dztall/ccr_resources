//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123



#define itta2 env__list

#include "../shell.h"
int main(int argc, char *argv[])
{
	shell.debug = 1;
	parse("gcc -I / -I ../extra -D foo -D foo2 defined.c");
	return 0;
}
