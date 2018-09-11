#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void f();

int dup(int oldfd) {
    return fcntl(oldfd, F_DUPFD, 7);
}

int dup2(int oldfd, int newfd) {

    if(oldfd == newfd)
        return oldfd;

    if(fcntl(oldfd, F_GETFD) == -1)
        return -1;

    if(close(newfd) == -1 && errno != EBADF)
        return -1;

    fcntl(oldfd, F_DUPFD, newfd);

    return newfd;
}

int main()
{
	
	//int stdofd = fileno(stdo);
	//if (stdofd == 0) printf("stdofd is NULL\n");
	//else printf("fileno(stdo) = %d\n", stdofd);
    int    fd;
    fpos_t pos;

    printf("stdout, ");

    fflush(stdout);
    fgetpos(stdout, &pos);
    fd = dup(fileno(stdout));
    freopen("stdout.out", "w", stdout);

    f();

    fflush(stdout);
    dup2(fileno(stdout), fd);
    close(fd);
    clearerr(stdout);
    fsetpos(stdout, &pos);        /* for C9X */

    printf("stdout again\n");
}

void f()
{
printf("stdout in f()");
}
