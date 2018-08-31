#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <inttypes.h>
#include <sys/syscall.h>
#include <sys/sysctl.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>

int printf(const char *fmt, ...) {
	// we do not && here even tho it seems like we should, logically mkdir depends on the non existence of ./FD and should not be created if it exists
	if(access("./FD", F_OK) == -1) if (mkdir("./FD", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0) {
		printf("./FD could not be created");
		return -1;
	}
	FILE * printf_stdin = fopen("./FD/0", "a+");
	FILE * printf_stdout = fopen("./FD/1", "a+");
	FILE * printf_stderr = fopen("./FD/2", "a+");
    va_list ap;
    va_start(ap, fmt);
    int bytes = vfprintf (printf_stdout, fmt, ap);
    va_end(ap);
    fclose(printf_stdin);
    fclose(printf_stdout);
    fclose(printf_stderr);
    return bytes;
}

void redirect(int fd, const char * file) {
	printf("fcntl(%d, F_GETFL) returned %d\n", fd, fcntl(fd, F_GETFL));
    printf("redirecting fd %d to %s\n", fd, file);
    int newfd = open(file ,O_RDWR | O_CREAT, 0777);
    printf("newfd returned %d\n", newfd);
    int ret = dup2(fd, newfd);
    printf("ret returned %d\n", ret);
    printf("closing fd %d\n", fd);
    ret = close(fd);
    printf("ret returned %d\n", ret);
}

void mass_redirect(int limit) {
	
	char path[4096];
	char ichar[16];
	for (int i = 0; i <= limit; i++) {
		sprintf(ichar, "%d", i);
		sprintf(path, "./FD/%s", ichar);
		printf("redirecting %s to %s\n", ichar, path);
		redirect(i, path);
	}
}

int pfork(char * app) {
	int status;
	int ret;
	pid_t pid;
	printf("\nexecuting %s\n", app);
    pid = fork();
    printf("pid after fork %d\n", getpid());
    printf("fork returned: %d\n", pid);

    if (pid < 0)
    {
        perror("fork failed");  
    }
    if (pid==0) printf("pid == 0\n");
    else if (pid!=0) printf("pid != 0\n");
    if (pid==0)
    {
        printf("I am the child with pid %d, getpid %d\n", pid, (int)getpid());
		printf("getpid: %d pthread_self: %lu tid: %lu\n", getpid(), pthread_self(), syscall(SYS_gettid));
        printf("executing %s...\n", app);
        char * p[2];
        p[0] = app;
        p[1] = NULL;
        ret = execvp(p[0], p); // should return 42
        
    }
    wait(&status);
    int returned = 0;
	if (WIFEXITED(status)){
      	returned = WEXITSTATUS(status);
      	printf("exited normally with status %d\n",returned);
	}
    printf("ret is %d\n", ret);
    printf("I am the parent with pid %d, getpid %d, waiting for the child\n", pid, (int)getpid());
    //wait(NULL);
    waitpid(pid,&status,0);
    printf("Parent ending status is %d. \n", WEXITSTATUS(status));
	return returned;
}

int main()
{
	printf("fileno(__stdinp) is %d, fileno(stdin) is %d, STDIN_FILENO is %d\n", fileno(__stdinp), fileno(stdin), STDIN_FILENO);
	printf("fileno(__stdoutp) is %d, fileno(stdout) is %d, STDOUT_FILENO is %d\n", fileno(__stdoutp), fileno(stdout), STDOUT_FILENO);
	printf("fileno(__stderrp) is %d, fileno(stderr) is %d, STDERR_FILENO is %d\n", fileno(__stderrp), fileno(stderr), STDERR_FILENO);
	mass_redirect(2);
    printf("I am: %d\n", (int)getpid());
    printf("pid before fork %d\n", getpid());
	printf("getpid: %d pthread_self: %lu\n", getpid(), pthread_self());
	
	pfork("true");
	pfork("false");
	pfork("ls");
    return 42;
}
