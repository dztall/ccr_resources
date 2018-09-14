//Modified by: mgood7123 (Matthew James Good) http://github.com/mgood7123

//Original source code found at : https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix

//For detailed information, search internet with 'ANSI Escape sequences' keyword.

#include <stdio.h>
#include <stdarg.h>

#ifdef nocolor

#define colors_RED   ""
#define colors_GREEN   ""
#define colors_YELLOW   ""
#define colors_BLUE   ""
#define colors_MAG   ""
#define colors_CYAN   ""
#define colors_WHITE   ""
#define colors_RESET ""
#define colors_CLEARSCREEN ""

#else

#define colors_RED   "\x1B[31m"
#define colors_GREEN   "\x1B[32m"
#define colors_YELLOW   "\x1B[33m"
#define colors_BLUE   "\x1B[34m"
#define colors_MAG   "\x1B[35m"
#define colors_CYAN   "\x1B[36m"
#define colors_WHITE   "\x1B[37;40m"
#define colors_RESET "\x1B[0m"
#define colors_CLEARSCREEN "\x1b[2J"

#endif

// #define comment_asm(x, ...) printf(colors_GREEN " ; " x colors_RESET __VA_ARGS__)
// 
// #define printf_b(x, ...) printf(colors_BLUE x colors_RESET __VA_ARGS__)
// #define printf_r(x, ...) printf(colors_RED x colors_RESET __VA_ARGS__)
// #define printf_m(x, ...) printf(colors_MAG x colors_RESET __VA_ARGS__)
// 
// #define fprintf_b(a, x, ...) fprintf(a, colors_BLUE x colors_RESET __VA_ARGS__)
// #define fprintf_r(a, x, ...) fprintf(a, colors_RED x colors_RESET __VA_ARGS__)
// #define fprintf_m(a, x, ...) fprintf(a, colors_MAG x colors_RESET __VA_ARGS__)



int comment_asm(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(colors_GREEN " ; ");
    int bytes = vprintf (fmt, ap);
    printf(colors_RESET);
    va_end(ap);
    return bytes;
}

int printf_b(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(colors_BLUE);
    int bytes = vprintf (fmt, ap);
    printf(colors_RESET);
    va_end(ap);
    return bytes;
}

int printf_r(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(colors_RED);
    int bytes = vprintf (fmt, ap);
    printf(colors_RESET);
    va_end(ap);
    return bytes;
}

int printf_m(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf(colors_MAG);
    int bytes = vprintf (fmt, ap);
    printf(colors_RESET);
    va_end(ap);
    return bytes;
}

int fprintf_b(FILE * a, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(a, colors_BLUE);
    int bytes = vfprintf (a, fmt, ap);
    fprintf(a, colors_RESET);
    va_end(ap);
    return bytes;
}

int fprintf_r(FILE * a, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(a, colors_RED);
    int bytes = vfprintf (a, fmt, ap);
    fprintf(a, colors_RESET);
    va_end(ap);
    return bytes;
}

int fprintf_m(FILE * a, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(a, colors_MAG);
    int bytes = vfprintf (a, fmt, ap);
    fprintf(a, colors_RESET);
    va_end(ap);
    return bytes;
}


