

#define alloc_nr(x) (((x)+16)*3/2)


static int memory_limit_check(size_t size, int gentle)
{
	static size_t limit = 0;
	if (!limit) {
		//limit = git_env_ulong("GIT_ALLOC_LIMIT", 0);
		if (!limit)
			limit = SIZE_MAX;
	}
	if (size > limit) {
		if (gentle) {
			giterrornomessage("attempting to allocate %"PRIuMAX" over limit %"PRIuMAX,
			      (uintmax_t)size, (uintmax_t)limit);
			return -1;
		} else
			giterrornomessage("attempting to allocate %"PRIuMAX" over limit %"PRIuMAX,
			    (uintmax_t)size, (uintmax_t)limit);
	}
	return 0;
}

#define bitsizeof(x)  (CHAR_BIT * sizeof(x))

#define maximum_signed_value_of_type(a) \
    (INTMAX_MAX >> (bitsizeof(intmax_t) - bitsizeof(a)))

#define maximum_unsigned_value_of_type(a) \
    (UINTMAX_MAX >> (bitsizeof(uintmax_t) - bitsizeof(a)))

/*
 * Signed integer overflow is undefined in C, so here's a helper macro
 * to detect if the sum of two integers will overflow.
 *
 * Requires: a >= 0, typeof(a) equals typeof(b)
 */
#define signed_add_overflows(a, b) \
    ((b) > maximum_signed_value_of_type(a) - (a))

#define unsigned_add_overflows(a, b) \
    ((b) > maximum_unsigned_value_of_type(a) - (a))

/*
 * Returns true if the multiplication of "a" and "b" will
 * overflow. The types of "a" and "b" must match and must be unsigned.
 * Note that this macro evaluates "a" twice!
 */
#define unsigned_mult_overflows(a, b) \
    ((a) && (b) > maximum_unsigned_value_of_type(a) / (a))


static inline size_t st_mult(size_t a, size_t b)
{
	if (unsigned_mult_overflows(a, b))
		giterrornomessage("size_t overflow: %"PRIuMAX" * %"PRIuMAX,
		    (uintmax_t)a, (uintmax_t)b);
	return a * b;
}
