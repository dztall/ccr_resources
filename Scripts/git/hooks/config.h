//hook the global directory to check for an alternative directory instead of $HOME

char * git_global_config_directory;

extern char git_buf__initbuf[];
extern char git_buf__oom[];

/* Use to initialize buffer structure when git_buf is on stack */
#define GIT_BUF_INIT { git_buf__initbuf, 0, 0 }


#define ENSURE_SIZE(b, d) \
	if ((d) > (b)->asize && git_buf_grow((b), (d)) < 0)\
		return -1;
	
#define GITERR_CHECK_ERROR(code) do { int _err = (code); if (_err) return _err; } while (0)

/** Declare a function as always inlined. */
#if defined(_MSC_VER)
# define GIT_INLINE(type) static __inline type
#else
# define GIT_INLINE(type) static inline type
#endif

/* Use clang/gcc compiler intrinsics whenever possible */
#if (SIZE_MAX == ULONG_MAX) && __has_builtin(__builtin_uaddl_overflow)
# define git__add_sizet_overflow(out, one, two) \
	__builtin_uaddl_overflow(one, two, out)
# define git__multiply_sizet_overflow(out, one, two) \
	__builtin_umull_overflow(one, two, out)
#elif (SIZE_MAX == UINT_MAX) && __has_builtin(__builtin_uadd_overflow)
# define git__add_sizet_overflow(out, one, two) \
	__builtin_uadd_overflow(one, two, out)
# define git__multiply_sizet_overflow(out, one, two) \
	__builtin_umul_overflow(one, two, out)
#else

/**
 * Sets `one + two` into `out`, unless the arithmetic would overflow.
 * @return true if the result fits in a `size_t`, false on overflow.
 */
GIT_INLINE(bool) git__add_sizet_overflow(size_t *out, size_t one, size_t two)
{
	if (SIZE_MAX - one < two)
		return true;
	*out = one + two;
	return false;
}

/**
 * Sets `one * two` into `out`, unless the arithmetic would overflow.
 * @return true if the result fits in a `size_t`, false on overflow.
 */
GIT_INLINE(bool) git__multiply_sizet_overflow(size_t *out, size_t one, size_t two)
{
	if (one && SIZE_MAX / one < two)
		return true;
	*out = one * two;
	return false;
}

#endif


/** Check for additive overflow, setting an error if would occur. */
#define GIT_ADD_SIZET_OVERFLOW(out, one, two) \
	(git__add_sizet_overflow(out, one, two) ? (giterr_set_oom(), 1) : 0)

/** Check for additive overflow, setting an error if would occur. */
#define GIT_MULTIPLY_SIZET_OVERFLOW(out, nelem, elsize) \
	(git__multiply_sizet_overflow(out, nelem, elsize) ? (giterr_set_oom(), 1) : 0)

/** Check for additive overflow, failing if it would occur. */
#define GITERR_CHECK_ALLOC_ADD(out, one, two) \
	if (GIT_ADD_SIZET_OVERFLOW(out, one, two)) { return -1; }

#define GITERR_CHECK_ALLOC_ADD3(out, one, two, three) \
	if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
		GIT_ADD_SIZET_OVERFLOW(out, *(out), three)) { return -1; }

#define GITERR_CHECK_ALLOC_ADD4(out, one, two, three, four) \
	if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
		GIT_ADD_SIZET_OVERFLOW(out, *(out), three) || \
		GIT_ADD_SIZET_OVERFLOW(out, *(out), four)) { return -1; }

#define GITERR_CHECK_ALLOC_ADD5(out, one, two, three, four, five) \
	if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
		GIT_ADD_SIZET_OVERFLOW(out, *(out), three) || \
		GIT_ADD_SIZET_OVERFLOW(out, *(out), four) || \
		GIT_ADD_SIZET_OVERFLOW(out, *(out), five)) { return -1; }

/** Check for multiplicative overflow, failing if it would occur. */
#define GITERR_CHECK_ALLOC_MULTIPLY(out, nelem, elsize) \
	if (GIT_MULTIPLY_SIZET_OVERFLOW(out, nelem, elsize)) { return -1; }

/* NOTE: other giterr functions are in the public errors.h header file */


int git_buf_put(git_buf *buf, const char *data, size_t len)
{
	if (len) {
		size_t new_size;

		assert(data);

		GITERR_CHECK_ALLOC_ADD(&new_size, buf->size, len);
		GITERR_CHECK_ALLOC_ADD(&new_size, new_size, 1);
		ENSURE_SIZE(buf, new_size);
		memmove(buf->ptr + buf->size, data, len);
		buf->size += len;
		buf->ptr[buf->size] = '\0';
	}
	return 0;
}

int git_buf_puts(git_buf *buf, const char *string)
{
	assert(string);
	return git_buf_put(buf, string, strlen(string));
}

void git_buf_clear(git_buf *buf)
{
	buf->size = 0;

	if (!buf->ptr) {
		buf->ptr = git_buf__initbuf;
		buf->asize = 0;
	}

	if (buf->asize > 0)
		buf->ptr[0] = '\0';
}

int git__getenv(git_buf *out, const char *name)
{
	const char *val = env__get(environ, name);
	ps(val)

	git_buf_clear(out);

	if (!val)
		return GIT_ENOTFOUND;

	return git_buf_puts(out, val);
}

int git_sysdir_guess_global_dirs(git_buf *out) {
	giterr(git__getenv(out, git_global_config_directory));
	return 0;
}

struct git_sysdir__dir {
	git_buf buf;
	int (*guess)(git_buf *out);
};

struct git_sysdir__dir git_sysdir__dirs[] = {
	{ GIT_BUF_INIT, git_sysdir_guess_global_dirs },
	{ GIT_BUF_INIT, git_sysdir_guess_global_dirs },
	{ GIT_BUF_INIT, git_sysdir_guess_global_dirs },
	{ GIT_BUF_INIT, git_sysdir_guess_global_dirs },
	{ GIT_BUF_INIT, git_sysdir_guess_global_dirs },
};

typedef enum {
	GIT_SYSDIR_SYSTEM = 0,
	GIT_SYSDIR_GLOBAL = 1,
	GIT_SYSDIR_XDG    = 2,
	GIT_SYSDIR_PROGRAMDATA = 3,
	GIT_SYSDIR_TEMPLATE = 4,
	GIT_SYSDIR__MAX   = 5,
} git_sysdir_t;

#ifndef ARRAY_SIZE
# define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif


static int git_sysdir_check_selector(git_sysdir_t which)
{
	if (which < ARRAY_SIZE(git_sysdir__dirs))
		return 0;
	return -1;
}

int git_buf_len(const struct git_buf *buf)
{
	return strlen(buf->ptr);
}

int git_sysdir_get(const git_buf **out, git_sysdir_t which)
{
	assert(out);

	*out = NULL;

	GITERR_CHECK_ERROR(git_sysdir_check_selector(which));

	git_sysdir__dirs[which].guess(&git_sysdir__dirs[which].buf);
	*out = &git_sysdir__dirs[which].buf;
	//*out = '/';
	pp(*out)
	pp(out)
	pi(which)
	pi(git_buf_len(*out))
	return 0;
}

#define p_access(p,m) access(p,m)

bool git_path_exists(const char *path)
{
	assert(path);
	return p_access(path, F_OK) == 0;
}

char git_buf__oom[1];


static git_error g_git_oom_error = {
	"Out of memory",
	GITERR_NOMEMORY
};


#define GIT_UNUSED(x) ((void)(x))

static void *stdalloc__realloc(void *ptr, size_t size, const char *file, int line)
{
	void *new_ptr = realloc(ptr, size);

	GIT_UNUSED(file);
	GIT_UNUSED(line);

	if (!new_ptr) giterr_set_oom();
	return new_ptr;
}

#define git__realloc(ptr, size)               stdalloc__realloc(ptr, size, __FILE__, __LINE__)

#define git__free                             free

int git_buf_try_grow(
	git_buf *buf, size_t target_size, bool mark_oom)
{
	char *new_ptr;
	size_t new_size;

	if (buf->ptr == git_buf__oom)
		return -1;

	if (buf->asize == 0 && buf->size != 0) {
		puts("cannot grow a borrowed buffer");
		return GIT_EINVALID;
	}

	if (!target_size)
		target_size = buf->size;

	if (target_size <= buf->asize)
		return 0;

	if (buf->asize == 0) {
		new_size = target_size;
		new_ptr = NULL;
	} else {
		new_size = buf->asize;
		new_ptr = buf->ptr;
	}

	/* grow the buffer size by 1.5, until it's big enough
	 * to fit our target size */
	while (new_size < target_size)
		new_size = (new_size << 1) - (new_size >> 1);

	/* round allocation up to multiple of 8 */
	new_size = (new_size + 7) & ~7;

	if (new_size < buf->size) {
		if (mark_oom)
			buf->ptr = git_buf__oom;

		return -1;
	}

	new_ptr = git__realloc(new_ptr, new_size);

	if (!new_ptr) {
		if (mark_oom) {
			if (buf->ptr && (buf->ptr != git_buf__initbuf))
				git__free(buf->ptr);
			buf->ptr = git_buf__oom;
		}
		return -1;
	}

	buf->asize = new_size;
	buf->ptr   = new_ptr;

	/* truncate the existing buffer size if necessary */
	if (buf->size >= buf->asize)
		buf->size = buf->asize - 1;
	buf->ptr[buf->size] = '\0';

	return 0;
}

int git_buf_grow(git_buf *buffer, size_t target_size)
{
	return git_buf_try_grow(buffer, target_size, true);
}

int git_buf_init(git_buf *buf, size_t initial_size)
{
	buf->asize = 0;
	buf->size = 0;
	buf->ptr = git_buf__initbuf;

	ENSURE_SIZE(buf, initial_size);

	return 0;
}

void git_buf_dispose(git_buf *buf)
{
	if (!buf) return;

	if (buf->asize > 0 && buf->ptr != NULL && buf->ptr != git_buf__oom)
		git__free(buf->ptr);

	git_buf_init(buf, 0);
}

int git_buf_join(
	git_buf *buf,
	char separator,
	const char *str_a,
	const char *str_b)
{
	size_t strlen_a = str_a ? strlen(str_a) : 0;
	size_t strlen_b = strlen(str_b);
	size_t alloc_len;
	int need_sep = 0;
	ssize_t offset_a = -1;

	/* not safe to have str_b point internally to the buffer */
	assert(str_b < buf->ptr || str_b >= buf->ptr + buf->size);

	/* figure out if we need to insert a separator */
	if (separator && strlen_a) {
		while (*str_b == separator) { str_b++; strlen_b--; }
		if (str_a[strlen_a - 1] != separator)
			need_sep = 1;
	}

	/* str_a could be part of the buffer */
	if (str_a >= buf->ptr && str_a < buf->ptr + buf->size)
		offset_a = str_a - buf->ptr;

	GITERR_CHECK_ALLOC_ADD(&alloc_len, strlen_a, strlen_b);
	GITERR_CHECK_ALLOC_ADD(&alloc_len, alloc_len, need_sep);
	GITERR_CHECK_ALLOC_ADD(&alloc_len, alloc_len, 1);
	ENSURE_SIZE(buf, alloc_len);

	/* fix up internal pointers */
	if (offset_a >= 0)
		str_a = buf->ptr + offset_a;

	/* do the actual copying */
	if (offset_a != 0 && str_a)
		memmove(buf->ptr, str_a, strlen_a);
	if (need_sep)
		buf->ptr[strlen_a] = separator;
	memcpy(buf->ptr + strlen_a + need_sep, str_b, strlen_b);

	buf->size = strlen_a + strlen_b + need_sep;
	buf->ptr[buf->size] = '\0';

	return 0;
}

GIT_INLINE(int) git_buf_joinpath(git_buf *buf, const char *a, const char *b)
{
	return git_buf_join(buf, '/', a, b);
}


int git_buf_set(git_buf *buf, const void *data, size_t len)
{
	size_t alloclen;

	if (len == 0 || data == NULL) {
		git_buf_clear(buf);
	} else {
		if (data != buf->ptr) {
			GITERR_CHECK_ALLOC_ADD(&alloclen, len, 1);
			ENSURE_SIZE(buf, alloclen);
			memmove(buf->ptr, data, len);
		}

		buf->size = len;
		if (buf->asize > buf->size)
			buf->ptr[buf->size] = '\0';

	}
	return 0;
}


GIT_INLINE(const char *) git_buf_cstr(const git_buf *buf)
{
	ps(buf->ptr)
	return buf->ptr;
}

static int git_sysdir_find_in_dirlist(
	git_buf *path,
	const char *name,
	git_sysdir_t which,
	const char *label)
{
	size_t len;
	const char *scan, *next = NULL;
	const git_buf *syspath;

	GITERR_CHECK_ERROR(git_sysdir_get(&syspath, which));
	
	pi(!syspath)
	pi(!git_buf_len(syspath))
	
	if (!syspath || !git_buf_len(syspath)) {
		puts("goto done -> return GIT_ENOTFOUND;");
		goto done;
	}
	ps(syspath->ptr)
	for (scan = git_buf_cstr(syspath); scan; scan = next) {
		/* find unescaped separator or end of string */
		for (next = scan; *next; ++next) {
			if (*next == GIT_PATH_LIST_SEPARATOR &&
				(next <= scan || next[-1] != '\\'))
				break;
		}

		len = (size_t)(next - scan);
		next = (*next ? next + 1 : NULL);
		if (!len)
			continue;
		ps(scan)
		GITERR_CHECK_ERROR(git_buf_set(path, scan, len));
		ps(name)
		if (name)
			GITERR_CHECK_ERROR(git_buf_joinpath(path, path->ptr, name));
		ps(path->ptr)
		if (git_path_exists(path->ptr))
			return 0;
	}

done:
	git_buf_dispose(path);
	return GIT_ENOTFOUND;
}

int git_sysdir_find_global_file(git_buf *path, const char *filename)
{
	return git_sysdir_find_in_dirlist(
		path, filename, GIT_SYSDIR_GLOBAL, "global");
}



void git_buf_sanitize(git_buf *buf)
{
	if (buf->ptr == NULL) {
		assert(buf->size == 0 && buf->asize == 0);
		buf->ptr = git_buf__initbuf;
	} else if (buf->asize > buf->size)
		buf->ptr[buf->size] = '\0';
}


#define GIT_CONFIG_FILENAME_PROGRAMDATA "config"
#define GIT_CONFIG_FILENAME_SYSTEM "gitconfig"
#define GIT_CONFIG_FILENAME_GLOBAL ".gitconfig"
#define GIT_CONFIG_FILENAME_XDG    "config"

#define GIT_CONFIG_FILENAME_INREPO "config"
#define GIT_CONFIG_FILE_MODE 0666


int git_config_find_global(git_buf *path)
{
	git_buf_sanitize(path);
	return git_sysdir_find_global_file(path, GIT_CONFIG_FILENAME_GLOBAL);
}

int git_config__global_location(git_buf *buf)
{
	const git_buf *paths;
	const char *sep, *start;

	if (git_sysdir_get(&paths, GIT_SYSDIR_GLOBAL) < 0)
		return -1;

	/* no paths, so give up */
	if (!paths || !git_buf_len(paths))
		return -1;

	/* find unescaped separator or end of string */
	for (sep = start = git_buf_cstr(paths); *sep; ++sep) {
		if (*sep == GIT_PATH_LIST_SEPARATOR &&
			(sep <= start || sep[-1] != '\\'))
			break;
	}

	if (git_buf_set(buf, start, (size_t)(sep - start)) < 0)
		return -1;

	return git_buf_joinpath(buf, buf->ptr, GIT_CONFIG_FILENAME_GLOBAL);
}

int git_config_open_default(git_config **out)
{
	int error;
	git_config *cfg = NULL;
	git_buf buf = GIT_BUF_INIT;

	if ((error = git_config_new(&cfg)) < 0)
		return error;

	if (!git_config_find_global(&buf) || !git_config__global_location(&buf)) {
		error = git_config_add_file_ondisk(cfg, buf.ptr,
			GIT_CONFIG_LEVEL_GLOBAL, NULL, 0);
	}

	if (!error && !git_config_find_xdg(&buf))
		error = git_config_add_file_ondisk(cfg, buf.ptr,
			GIT_CONFIG_LEVEL_XDG, NULL, 0);

	if (!error && !git_config_find_system(&buf))
		error = git_config_add_file_ondisk(cfg, buf.ptr,
			GIT_CONFIG_LEVEL_SYSTEM, NULL, 0);

	if (!error && !git_config_find_programdata(&buf))
		error = git_config_add_file_ondisk(cfg, buf.ptr,
			GIT_CONFIG_LEVEL_PROGRAMDATA, NULL, 0);

	git_buf_dispose(&buf);

	if (error) {
		git_config_free(cfg);
		cfg = NULL;
	}

	*out = cfg;

	return error;
}

