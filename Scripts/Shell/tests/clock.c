/*

1 argument(s):
  0
3 argument(s):
  10
  20
  30
9 argument(s):
  1
  2
  3
  4
  5
  6
  7
  8
  9
cpu time: 0.00 seconds
cpu time: 0.36 seconds
cpu time: 0.000 seconds
cpu time: 0.360 seconds
cpu time: 0.344 seconds
cpu time: 0.331 seconds
total cpu time: 1.035 seconds
total real cpu time: 1.035 seconds


*/

#include <stdio.h>
#include <stdarg.h>

/*
clock__total(
clock__get(whereis_start), 
clock__get(whereis_end), 
clock__get(create_start), 
clock__get(create_end), 
clock__get(build_start), 
clock__get(build_end), 
clock__get(link_start), 
clock__get(link_end), 
clock__get(run_start), 
clock__get(run_end), 
clock__get(delete_start), 
clock__get(delete_end));
*/
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)

/* C99-style: anonymous argument referenced by __VA_ARGS__, empty arg not OK */

# define N_ARGS(...) N_ARGS_HELPER1(__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
# define N_ARGS_HELPER1(...) N_ARGS_HELPER2(__VA_ARGS__)
# define N_ARGS_HELPER2(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, n, ...) n

# define foo(...) foo_helper(N_ARGS(__VA_ARGS__), __VA_ARGS__)
# define clock__total(...) clock__total_h(N_ARGS(__VA_ARGS__), __VA_ARGS__)

#elif defined(__GNUC__)

/* GCC-style: named argument, empty arg is OK */

# define N_ARGS(args...) N_ARGS_HELPER1(args, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
# define N_ARGS_HELPER1(args...) N_ARGS_HELPER2(args)
# define N_ARGS_HELPER2(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, n, x...) n

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

clock__add(timefunc_start);
clock__add(timefunc_end);

#define timefunc(func) { \
	clock__set(timefunc_start); \
	func; \
	clock__set(timefunc_end); \
	printf("cpu time: %.2f seconds\n", clock__calculate(timefunc_start, timefunc_end)); \
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

clock__add (base);
#define clock__init() clock__set(base)
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
	for (i = 0; i < n_args; i++) {
		clock__get(total_current) += clock__get(arg2) - clock__get(arg1);
		clock__get(arg1) = va_arg(ap, clock_t);
		if (clock__get(arg1)>clock__get(largest)) clock__get(largest)=clock__get(arg1);
		
		clock__get(arg2) = va_arg(ap, clock_t);
		if (clock__get(arg2)>clock__get(largest)) clock__get(largest)=clock__get(arg2);
		clock__get(total_last) = clock__get(arg1) - clock__get(arg2);
		printf("cpu time: %.3f seconds\n", clock__calculate(arg1, arg2));
		i++;
	}
	printf("total cpu time: %.3f seconds\n", clock__calculate(total_last, total_current));
	printf("total real cpu time: %.3f seconds\n", clock__calculate(base, largest));
	va_end(ap);
}

#include <unistd.h>

#define fc(x) builtin_clock_##x##_end

int main(void)
{
	clock__set(base);
	clock__add(a);
	clock__add(b);
	clock__set(a);
	foo(0);
	foo(10, 20, 30);
	foo(1, 2, 3, 4, 5, 6, 7, 8, 9);
	clock__set(b);
	printf("cpu time: %.2f seconds\n", clock__calculate(a, b));
	timefunc(sleep(1))
	clock__add(sleep1);
	clock__add(sleep2);
	clock__add(sleep3);
	clock__add(sleep4);
	clock__set(sleep1);
	sleep(1);
	clock__set(sleep2);
	clock__set(sleep3);
	sleep(1);
	clock__set(sleep4);
	clock__total(clock__get(a), clock__get(b), clock__get(timefunc_start), fc(timefunc), clock__get(sleep1),clock__get(sleep2),clock__get(sleep3),clock__get(sleep4));
	return 0;
}

