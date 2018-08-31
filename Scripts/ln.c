//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include <unistd.h>
#include <stdio.h>
#include "Shell/builtins/printfmacro.h"
#include <string.h>
#include <errno.h>
int main(int argc, char *argv[])
{
	char * from, * to;
	if (argc != 3) {
		printf("usage: %s [from] [to]\ndefaulting to %s symlink_example_from symlink_example_to\n", argv[0], argv[0]);
		from = "symlink_example_from";
		to = "symlink_example_from";
	}
	else {
		from = argv[1];
		to = argv[2];
	}
	fclose(fopen(from, "a"));
	pi(symlink(from, to))
	ps(strerror(errno))
	pi(symlink(to, from))
	ps(strerror(errno))
	return 0;
}
