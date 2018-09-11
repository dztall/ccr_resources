//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Garbage_Collector/gc.h"
int main(int argc, char *argv[])
{
	printf("argument count: %d\n", argc);
	puts("start of argument list");
	for (int i = 0; i< argc; i++) printf("argv[%i] = %s\n", i, argv[i]);
	puts("end of argument list");
	return 0;
}
