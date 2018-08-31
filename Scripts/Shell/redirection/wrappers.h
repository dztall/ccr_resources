// create wrappers for io redirection

#ifndef redirection_wrappers
#define redirection_wrappers

// include needed headers

#include <stdarg.h>
#include <unistd.h> // access
#include <sys/stat.h> // mkdir
#include <stdio.h>

FILE * printf_stdin;
FILE * printf_stdout;
FILE * printf_stderr;

// defines

// we do not && here even tho it seems like we should, logically mkdir depends on the non existence of ./FD and should not be created if it exists
#define wrapper__proc__fd_init if(access("./FD", F_OK) == -1) { if (mkdir("./FD", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0) { printf("./FD could not be created"); return -1; } }

#define wrapper__stdio__init printf_stdin = fopen("./FD/0", "a+"); printf_stdout = fopen("./FD/1", "a+"); printf_stderr = fopen("./FD/2", "a+");
#define wrapper__stdio__close fclose(printf_stdin); fclose(printf_stdout); fclose(printf_stderr);

FILE * wrapper__stdio__file (FILE * n) {
		 if (fileno(n)==STDIN_FILENO ) return printf_stdin;
	else if (fileno(n)==STDOUT_FILENO) return printf_stdout;
	else if (fileno(n)==STDERR_FILENO) return printf_stderr;
	else return n;
}

int wrapper__stdio__fd (int n) {
		 if (n==STDIN_FILENO ) return fileno(printf_stdin);
	else if (n==STDOUT_FILENO) return fileno(printf_stdout);
	else if (n==STDERR_FILENO) return fileno(printf_stderr);
	else return n;
}

//create wrapper functions

int printf(const char *fmt, ...) {
	wrapper__proc__fd_init
	wrapper__stdio__init
    va_list ap;
    va_start(ap, fmt);
    int bytes = vfprintf (printf_stdout, fmt, ap);
    va_end(ap);
    wrapper__stdio__close
    return bytes;
}

int fprintf(FILE * n, const char *fmt, ...) {
	wrapper__proc__fd_init
	wrapper__stdio__init
	va_list ap;
    va_start(ap, fmt);
    int bytes = vfprintf(wrapper__stdio__file(n), fmt, ap);
    va_end(ap);
    wrapper__stdio__close
    return bytes;
}

int puts(const char * s) {
	return printf("%s\n", s);
}

#define putc(x, y) \
wrapper__proc__fd_init wrapper__stdio__init putc(x, wrapper__stdio__file(y)); wrapper__stdio__close
#define putw(x, y) putc(x, y)
#define putchar(x) putc(x, stdout)
#define fputc(x, y) \
wrapper__proc__fd_init wrapper__stdio__init fputc(x, wrapper__stdio__file(y)); wrapper__stdio__close
#define fputs(x, y) \
wrapper__proc__fd_init wrapper__stdio__init fputs(x, wrapper__stdio__file(y)); wrapper__stdio__close
#define fwrite(a,b,c,d) \
wrapper__proc__fd_init wrapper__stdio__init fwrite(a,b,c,wrapper__stdio__file(d)); wrapper__stdio__close
#define write(a,b,c) \
wrapper__proc__fd_init wrapper__stdio__init write(wrapper__stdio__fd(a),b,c); wrapper__stdio__close

#endif
