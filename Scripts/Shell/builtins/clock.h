//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include <stdio.h>
#include <stdarg.h>

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)

/* C99-style: anonymous argument referenced by __VA_ARGS__, empty arg not OK */

# define N_ARGS(...) N_ARGS_HELPER1(__VA_ARGS__, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
# define N_ARGS_HELPER1(...) N_ARGS_HELPER2(__VA_ARGS__)
# define N_ARGS_HELPER2(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, n, ...) n

# define foo(...) foo_helper(N_ARGS(__VA_ARGS__), __VA_ARGS__)
# define clock__total(...) clock__total_h(N_ARGS(__VA_ARGS__), __VA_ARGS__)

#elif defined(__GNUC__)

/* GCC-style: named argument, empty arg is OK */

# define N_ARGS(args...) N_ARGS_HELPER1(args, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
# define N_ARGS_HELPER1(args...) N_ARGS_HELPER2(args)
# define N_ARGS_HELPER2(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, n, x...) n

# define foo(args...) foo_helper(N_ARGS(args), args)
# define clock__total(args...) clock_total__h(N_ARGS(args), args)

#else

#error variadic macros for your compiler here

#endif

static inline void foo_helper(unsigned int n_args, ...)
{
	unsigned int i, arg;
	va_list ap;
	va_start(ap, n_args);
	printf("%u argument(s):\n", n_args);
	for (i = 0; i < n_args; i++) {
		arg = va_arg(ap, unsigned int);
		printf("  %u\n", arg);
	}
	va_end(ap);
}


#include <time.h>
#include <stdbool.h>

bool has_time = false;

#define clock__get(clock) builtin_clock_##clock
#define clock__add(clocka) clock_t clock__get(clocka) = 0
#define clock__calculate(clock_start, clock_end) (double)(clock__get(clock_end) - clock__get(clock_start)) / CLOCKS_PER_SEC
#define clock__set(clockb) clock__get(clockb) = clock()
#define clock__shorten(x) #x, builtin_clock_##x##_start, builtin_clock_##x##_end

clock__add(timefunc_start);
clock__add(timefunc_end);
clock__add (base);

#define clock__init() clock__set(base)

#define timefunc(func) { \
	clock__set(timefunc_start); \
	func; \
	clock__set(timefunc_end); \
	printf("cpu time: %.3f seconds\n", clock__calculate(timefunc_start, timefunc_end)); \
}

#define timefuncret(func) { \
	clock__set(timefunc_start); \
	int ret = func; \
	clock__set(timefunc_end); \
	printf("cpu time: %.3f seconds\n", clock__calculate(timefunc_start, timefunc_end)); \
	return ret; \
}

// for functions that return void or a variable integer such as strlen
#define timefuncretc(func, ret) { \
	clock__set(timefunc_start); \
	func; \
	clock__set(timefunc_end); \
	printf("cpu time: %.3f seconds\n", clock__calculate(timefunc_start, timefunc_end)); \
	return ret; \
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static inline void clock__total_h(unsigned int n_args, ...)
{
	unsigned int i;
	clock__add(arg1);
	clock__add(arg2);
	clock__add(total_last);
	clock__add(total_current);
	clock__add(largest);
	clock__get(total_last) = 0;
	clock__get(total_current) = 0;
	va_list ap;
	va_start(ap, n_args);
	printf("%u argument(s):\n", n_args);
	for (i = 0; i < n_args; i++) {
		char * name = va_arg(ap, char *);
		clock__get(total_current) += clock__get(arg2) - clock__get(arg1);
		clock__get(arg1) = va_arg(ap, clock_t);
		if (clock__get(arg1)>clock__get(largest)) clock__get(largest)=clock__get(arg1);
		
		clock__get(arg2) = va_arg(ap, clock_t);
		if (clock__get(arg2)>clock__get(largest)) clock__get(largest)=clock__get(arg2);
		clock__get(total_last) = clock__get(arg1) - clock__get(arg2);
		printf("%s cpu time: %.3f seconds\n", name, clock__calculate(arg1, arg2));
	}
	printf("total cpu time: %.3f seconds\n", clock__calculate(total_last, total_current));
	printf("total real cpu time: %.3f seconds\n", clock__calculate(base, largest));
	va_end(ap);
}
