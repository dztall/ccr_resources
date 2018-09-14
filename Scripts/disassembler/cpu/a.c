#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

int main()
{
    char *d=mmap(0,4096,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_PRIVATE|MAP_ANON,-1,0);
    memset (d,0xc3,4096);
    ((void(*)(void))d)();
    return 0;
}
