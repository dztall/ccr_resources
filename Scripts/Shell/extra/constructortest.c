#include <stdio.h>
void __attribute__ ((__constructor__ (0)))
initstd(void) {
	/*if(access("./FD", F_OK) == -1) if (mkdir("./FD", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0) {
		// we cannot use printf here
		exit(1);
	}*/
	//__stdinp = fopen("./0", "r+");
	//__stdoutp = fopen("./1", "r+");
	//__stderrp = fopen("./2", "r+");
	printf("test\n");
}
