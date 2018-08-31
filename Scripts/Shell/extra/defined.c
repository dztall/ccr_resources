#include <stdio.h>
#include <assert.h>

int main(void)
{
	#ifdef foo
	puts("foo defined");
	#endif
	#ifdef foo2
	puts("foo2 defined");
	#endif
	printf("Welcome!\n");
	return 0;
}
