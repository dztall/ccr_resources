//Original source code found at : https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix

//For detailed information, search internet with 'ANSI Escape sequences' keyword.

#include <stdio.h>
#include <stdarg.h>

#ifdef nocolor

#define RED   ""
#define GRN   ""
#define YEL   ""
#define BLU   ""
#define MAG   ""
#define CYN   ""
#define WHT   ""
#define RESET ""
#define CLEARSCREEN ""

#else

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37;40m"
#define RESET "\x1B[0m"
#define CLEARSCREEN "\x1b[2J"

#endif


int color_test()
{
	printf("This should not display.");
	printf(CLEARSCREEN);

    printf("\x1b[5;20H");
	printf(RED "red\n" RESET);
	printf("\x1b[6;20H");
	printf(GRN "green\n" RESET);
	printf("\x1b[7;20H");
	printf(YEL "yellow\n" RESET);
	printf("\x1b[8;20H");
	printf(BLU "blue\n" RESET);
	printf("\x1b[9;20H");
	printf(MAG "magenta\n" RESET);
	printf("\x1b[10;20H");
	printf(CYN "cyan\n" RESET);
	printf("\x1b[11;20H");
	printf(WHT "white\n" RESET);

	return 0;
}

int comment_asm(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(GRN " ; ");
    int bytes = vprintf (fmt, ap);
    printf(RESET);
    va_end(ap);
    return bytes;
}

int printf_b(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(BLU);
    int bytes = vprintf (fmt, ap);
    printf(RESET);
    va_end(ap);
    return bytes;
}

int printf_r(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(RED);
    int bytes = vprintf (fmt, ap);
    printf(RESET);
    va_end(ap);
    return bytes;
}

int printf_m(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(MAG);
    int bytes = vprintf (fmt, ap);
    printf(RESET);
    va_end(ap);
    return bytes;
}

int fprintf_b(FILE * a, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(a, BLU);
    int bytes = vfprintf (a, fmt, ap);
    fprintf(a, RESET);
    va_end(ap);
    return bytes;
}

int fprintf_r(FILE * a, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(a, RED);
    int bytes = vfprintf (a, fmt, ap);
    fprintf(a, RESET);
    va_end(ap);
    return bytes;
}

int fprintf_m(FILE * a, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(a, MAG);
    int bytes = vfprintf (a, fmt, ap);
    fprintf(a, RESET);
    va_end(ap);
    return bytes;
}

