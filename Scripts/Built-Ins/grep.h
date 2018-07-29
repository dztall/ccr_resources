int limit = 100; // how many times should grep allow the buffer to be refilled until a recursive loop (resulting in endlessly refilling the buffer) is detected

#define WITHOUT_LZMA
#define WITHOUT_FASTMATCH

#ifndef CURRENT_FUNCTION
#define GCURRENT_FUNCTION
#else
#define GCURRENT_FUNCTION //CURRENT_FUNCTION
#endif

/*	$NetBSD: grep.h,v 1.5 2011/02/27 17:33:37 joerg Exp $	*/
/*	$OpenBSD: grep.h,v 1.15 2010/04/05 03:03:55 tedu Exp $	*/
/*	$FreeBSD: src/usr.bin/grep/grep.h,v 1.10 2011/12/07 12:25:28 gabor Exp $	*/

/*-
 * Copyright (c) 1999 James Howard and Dag-Erling Co챦dan Sm첩rgrav
 * Copyright (c) 2008-2009 Gabor Kovesdan <gabor@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

//dztall
#ifndef WITHOUT_BZIP2
#include <bzlib.h>
#endif
#include <limits.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <zlib.h>

#ifndef WITHOUT_FASTMATCH
#include "fastmatch.h"
#endif

#ifdef WITHOUT_NLS
#define getstr(n)	 errstr[n]
#else
#include <nl_types.h>

extern nl_catd		 catalog;
#define getstr(n)	 catgets(catalog, 1, n, errstr[n])
#endif

extern const char		*errstr[];

#define VERSION		"2.5.1-FreeBSD"

#define GREP_FIXED	0
#define GREP_BASIC	1
#define GREP_EXTENDED	2

#define BINFILE_BIN	0
#define BINFILE_SKIP	1
#define BINFILE_TEXT	2

#define FILE_STDIO	0
#define FILE_MMAP	1
#define FILE_GZIP	2
#define FILE_BZIP	3
#define FILE_XZ		4
#define FILE_LZMA	5

#define DIR_READ	0
#define DIR_SKIP	1
#define DIR_RECURSE	2

#define DEV_READ	0
#define DEV_SKIP	1

#define LINK_READ	0
#define LINK_EXPLICIT	1
#define LINK_SKIP	2

#define EXCL_PAT	0
#define INCL_PAT	1

#ifdef __APPLE__
#define MIN_LINE_MATCHES	32
#define MAX_LINE_MATCHES	1073741824
#else
#define MAX_LINE_MATCHES	32
#endif

struct file {
	int		 fd;
	bool		 binary;
};

struct str {
	off_t		 off;
	size_t		 len;
	char		*dat;
	char		*file;
	int		 line_no;
};

struct pat {
	char		*pat;
	int		 len;
};

struct epat {
	char		*pat;
	int		 mode;
};

/* Flags passed to regcomp() and regexec() */
extern int	 cflags, eflags;

/* Command line flags */
extern bool	 Eflag, Fflag, Gflag, Hflag, Lflag,
		 bflag, cflag, hflag, iflag, lflag, mflag, nflag, oflag,
		 qflag, sflag, vflag, wflag, xflag;
extern bool	 dexclude, dinclude, fexclude, finclude, lbflag, nullflag;
extern unsigned long long Aflag, Bflag;
extern long long mcount;
extern char	*label;
extern const char *color;
extern int	 binbehave, devbehave, dirbehave, filebehave, grepbehave, linkbehave;

extern bool	 file_err, first, matchall, prev;
extern int	 tail;
extern unsigned int dpatterns, fpatterns, patterns;
extern struct pat *pattern, *empty;
extern struct epat *dpattern, *fpattern, *fempty;
extern regex_t	*er_pattern, *r_pattern;
#ifndef WITHOUT_FASTMATCH
extern fastmatch_t *fg_pattern;
#endif

/* For regex errors  */
#define RE_ERROR_BUF	512
extern char	 re_error[RE_ERROR_BUF + 1];	/* Seems big enough */

/* util.c */
bool	 file_matching(const char *fname);
int	 procfile(const char *fn);
int	 grep_tree(char **argv);
void	*grep_malloc(size_t size);
void	*grep_calloc(size_t nmemb, size_t size);
void	*grep_realloc(void *ptr, size_t size);
char	*grep_strdup(const char *str);
void	 printline(struct str *line, int sep, regmatch_t *matches, int m);

/* queue.c */
void	 enqueue(struct str *x);
void	 printqueue(void);
void	 clearqueue(void);

/* file.c */
void		 grep_close(struct file *f);
struct file	*grep_open(const char *path);
char		*grep_fgetln(struct file *f, size_t *len);

/*	$NetBSD: file.c,v 1.5 2011/02/16 18:35:39 joerg Exp $	*/
/*	$FreeBSD: src/usr.bin/grep/file.c,v 1.7 2011/10/11 22:27:23 gabor Exp $	*/
/*	$OpenBSD: file.c,v 1.11 2010/07/02 20:48:48 nicm Exp $	*/

/*-
 * Copyright (c) 1999 James Howard and Dag-Erling Co챦dan Sm첩rgrav
 * Copyright (C) 2008-2010 Gabor Kovesdan <gabor@FreeBSD.org>
 * Copyright (C) 2010 Dimitry Andric <dimitry@andric.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/grep/file.c,v 1.7 2011/10/11 22:27:23 gabor Exp $");

#include <sys/param.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#ifndef WITHOUT_LZMA
#include <lzma.h>
#endif
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>
#include <zlib.h>

#ifndef WITHOUT_BZIP2
#include <bzlib.h>
#endif

#define	MAXBUFSIZ	(32 * 1024)
#define	LNBUFBUMP	80

static gzFile gzbufdesc;
#ifndef WITHOUT_LZMA
static lzma_stream lstrm = LZMA_STREAM_INIT;
#endif
#ifndef WITHOUT_BZIP2
static BZFILE* bzbufdesc;
#endif

static unsigned char *buffer;
static unsigned char *bufpos;
static size_t bufrem;
static size_t fsiz;

static unsigned char *lnbuf;
static size_t lnbuflen;

static inline int
grep_refill(struct file *f)
{
	GCURRENT_FUNCTION
	ssize_t nr;

	if (filebehave == FILE_MMAP)
		return (0);

	bufpos = buffer;
	bufrem = 0;

	if (filebehave == FILE_GZIP) {
		nr = gzread(gzbufdesc, buffer, MAXBUFSIZ);
#ifndef WITHOUT_BZIP2
	} else if (filebehave == FILE_BZIP && bzbufdesc != NULL) {
		int bzerr;

		nr = BZ2_bzRead(&bzerr, bzbufdesc, buffer, MAXBUFSIZ);
		switch (bzerr) {
		case BZ_OK:
		case BZ_STREAM_END:
			/* No problem, nr will be okay */
			break;
		case BZ_DATA_ERROR_MAGIC:
			/*
			 * As opposed to gzread(), which simply returns the
			 * plain file data, if it is not in the correct
			 * compressed format, BZ2_bzRead() instead aborts.
			 *
			 * So, just restart at the beginning of the file again,
			 * and use plain reads from now on.
			 */
			BZ2_bzReadClose(&bzerr, bzbufdesc);
			bzbufdesc = NULL;
			if (lseek(f->fd, 0, SEEK_SET) == -1)
				return (-1);
			nr = read(f->fd, buffer, MAXBUFSIZ);
			break;
		default:
			/* Make sure we exit with an error */
			nr = -1;
		}
#endif
#ifndef WITHOUT_LZMA
	} else if ((filebehave == FILE_XZ) || (filebehave == FILE_LZMA)) {
		lzma_action action = LZMA_RUN;
		uint8_t in_buf[MAXBUFSIZ];
		lzma_ret ret;

		ret = (filebehave == FILE_XZ) ?
		    lzma_stream_decoder(&lstrm, UINT64_MAX,
		    LZMA_CONCATENATED) :
		    lzma_alone_decoder(&lstrm, UINT64_MAX);

		if (ret != LZMA_OK)
			return (-1);

		lstrm.next_out = buffer;
		lstrm.avail_out = MAXBUFSIZ;
		lstrm.next_in = in_buf;
		nr = read(f->fd, in_buf, MAXBUFSIZ);

		if (nr < 0)
			return (-1);
		else if (nr == 0)
			action = LZMA_FINISH;

		lstrm.avail_in = nr;
		ret = lzma_code(&lstrm, action);

		if (ret != LZMA_OK && ret != LZMA_STREAM_END)
			return (-1);
		bufrem = MAXBUFSIZ - lstrm.avail_out;
		return (0);
#endif
	} else {
		nr = read(f->fd, buffer, MAXBUFSIZ);
		assert(buffer != NULL);
		assert(bufpos != NULL);
	}

	if (nr < 0)
		return (-1);

	bufrem = nr;
	return (0);
}

static size_t bufremlst;
int lns, lst, stk;
int ext;
static inline int
grep_refills(char *f)
{
	lns++;
	assert(lns<limit);
	GCURRENT_FUNCTION
	ssize_t nr;

	if (filebehave == FILE_MMAP)
		return (0);
	
	bufpos = buffer;
	memcpy(&bufremlst, &bufrem, sizeof(bufrem));
	bufrem = 0;
	if (buffer == NULL) buffer = malloc(MAXBUFSIZ);
	int sz = lst!=1?MAXBUFSIZ:bufremlst;
	nr = snprintf(buffer, sz, "%s", f);
	lseek_string(&f, stk, 0);
	if (nr > sz) {
		nr = 0;
		memset(buffer, 0, MAXBUFSIZ);
		lst = 0;
		sz = 0;
		stk = 0;
		lns = 0;
		bufremlst = 0;
		ext = 1;
	}
	if(nr < MAXBUFSIZ) lst = 1;
	bufpos = buffer;
	stk += nr;
	assert(buffer != NULL);
	assert(bufpos != NULL);
	if (nr < 0)
		return (-1);

	bufrem = nr;
	return (0);
}


static inline int
grep_lnbufgrow(size_t newlen)
{
	GCURRENT_FUNCTION

	if (lnbuflen < newlen) {
		lnbuf = grep_realloc(lnbuf, newlen);
		lnbuflen = newlen;
	}

	return (0);
}

char *
grep_fgetln(struct file *f, size_t *lenp)
{
	GCURRENT_FUNCTION
	unsigned char *p;
	char *ret;
	size_t len;
	size_t off;
	ptrdiff_t diff;

	/* Fill the buffer, if necessary */
	if (bufrem == 0 && grep_refill(f) != 0)
		goto error;

	if (bufrem == 0) {
		/* Return zero length to indicate EOF */
		*lenp = 0;
#ifdef __APPLE__
		return (char *)(bufpos);
#else
		return (bufpos);
#endif
	}

	/* Look for a newline in the remaining part of the buffer */
	if ((p = memchr(bufpos, '\n', bufrem)) != NULL) {
		++p; /* advance over newline */
#ifdef __APPLE__
		ret = (char *)bufpos;
#else
		ret = bufpos;
#endif
		len = p - bufpos;
		bufrem -= len;
		bufpos = p;
		*lenp = len;
		return (ret);
	}

	/* We have to copy the current buffered data to the line buffer */
	for (len = bufrem, off = 0; ; len += bufrem) {
		/* Make sure there is room for more data */
		if (grep_lnbufgrow(len + LNBUFBUMP))
			goto error;
		memcpy(lnbuf + off, bufpos, len - off);
		off = len;
		if (grep_refill(f) != 0)
			goto error;
		if (bufrem == 0)
			/* EOF: return partial line */
			break;
		if ((p = memchr(bufpos, '\n', bufrem)) == NULL)
			continue;
		/* got it: finish up the line (like code above) */
		++p;
		diff = p - bufpos;
		len += diff;
		if (grep_lnbufgrow(len))
		    goto error;
		memcpy(lnbuf + off, bufpos, diff);
		bufrem -= diff;
		bufpos = p;
		break;
	}
	*lenp = len;
#ifdef __APPLE__
	return (char *)(lnbuf);
#else
	return (lnbuf);
#endif

error:
	*lenp = 0;
	return (NULL);
}

char *
grep_fgetlns(char * f, size_t *lenp)
{
	GCURRENT_FUNCTION
	unsigned char *p;
	char *ret;
	size_t len;
	size_t off;
	ptrdiff_t diff;

	/* Fill the buffer, if necessary */
	if (bufrem == 0 && grep_refills(f) != 0) {
		goto error;
	}
	assert(bufpos != NULL);
	if (bufrem == 0) {
		/* Return zero length to indicate EOF */
		*lenp = 0;
#ifdef __APPLE_
		return (char *)(bufpos);
#else
		return (bufpos);
#endif
	}

	/* Look for a newline in the remaining part of the buffer */
	assert(bufpos != NULL);
	if ((p = memchr(bufpos, '\n', bufrem)) != NULL) {
		++p; /* advance over newline */
#ifdef __APPLE__
		ret = (char *)bufpos;
#else
		ret = bufpos;
#endif
		len = p - bufpos;
		bufrem -= len;
		bufpos = p;
		*lenp = len;
		return (ret);
	}

	/* We have to copy the current buffered data to the line buffer */
	for (len = bufrem, off = 0; ; len += bufrem) {
		/* Make sure there is room for more data */
		if (grep_lnbufgrow(len + LNBUFBUMP)) {
			goto error;
		}
		memcpy(lnbuf + off, bufpos, len - off);
		off = len;
		if (grep_refills(f) != 0) {
			goto error;
		}
		if (bufrem == 0)
			/* EOF: return partial line */
			break;
		if ((p = memchr(bufpos, '\n', bufrem)) == NULL)
			continue;
		/* got it: finish up the line (like code above) */
		++p;
		diff = p - bufpos;
		len += diff;
		if (grep_lnbufgrow(len)) {
		    goto error;
		}
		memcpy(lnbuf + off, bufpos, diff);
		bufrem -= diff;
		bufpos = p;
		break;
	}
	*lenp = len;
#ifdef __APPLE__
	return (char *)(lnbuf);
#else
	return (lnbuf);
#endif

error:
	*lenp = 0;
	return (NULL);
}

/*
 * Opens a file for processing.
 */
struct file *
grep_open(const char *path)
{
	GCURRENT_FUNCTION
	struct file *f;

	f = grep_malloc(sizeof *f);
	memset(f, 0, sizeof *f);
	if (path == NULL) {
		/* Processing stdin implies --line-buffered. */
		lbflag = true;
		f->fd = STDIN_FILENO;
	} else if ((f->fd = open(path, O_RDONLY)) == -1)
		goto error1;

	if (filebehave == FILE_MMAP) {
		struct stat st;

		if ((fstat(f->fd, &st) == -1) || (st.st_size > OFF_MAX) ||
		    (!S_ISREG(st.st_mode)))
			filebehave = FILE_STDIO;
		else {
#ifdef __APPLE__
			int flags = MAP_PRIVATE | MAP_NOCACHE;
#else
			int flags = MAP_PRIVATE | MAP_NOCORE | MAP_NOSYNC;
#endif
#ifdef MAP_PREFAULT_READ
			flags |= MAP_PREFAULT_READ;
#endif
			fsiz = st.st_size;
			buffer = mmap(NULL, fsiz, PROT_READ, flags,
			     f->fd, (off_t)0);
			if (buffer == MAP_FAILED)
				filebehave = FILE_STDIO;
			else {
				bufrem = st.st_size;
				bufpos = buffer;
				madvise(buffer, st.st_size, MADV_SEQUENTIAL);
			}
		}
	}

	if ((buffer == NULL) || (buffer == MAP_FAILED))
		buffer = grep_malloc(MAXBUFSIZ);

	if (filebehave == FILE_GZIP &&
	    (gzbufdesc = gzdopen(f->fd, "r")) == NULL)
		goto error2;

#ifndef WITHOUT_BZIP2
	if (filebehave == FILE_BZIP &&
	    (bzbufdesc = BZ2_bzdopen(f->fd, "r")) == NULL)
		goto error2;
#endif

	/* Fill read buffer, also catches errors early */
	if (bufrem == 0 && grep_refill(f) != 0)
		goto error2;

	/* Check for binary stuff, if necessary */
	if (binbehave != BINFILE_TEXT && memchr(bufpos, '\0', bufrem) != NULL)
	f->binary = true;

	return (f);

error2:
	close(f->fd);
error1:
	free(f);
	return (NULL);
}

/*
 * Closes a file.
 */
void
grep_close(struct file *f)
{
	GCURRENT_FUNCTION

	close(f->fd);

	/* Reset read buffer and line buffer */
	if (filebehave == FILE_MMAP) {
		munmap(buffer, fsiz);
		buffer = NULL;
	}
	bufpos = buffer;
	bufrem = 0;

	free(lnbuf);
	lnbuf = NULL;
	lnbuflen = 0;
}

/*	$NetBSD: queue.c,v 1.2 2011/02/16 01:31:33 joerg Exp $	*/
/*	$FreeBSD: src/usr.bin/grep/queue.c,v 1.5 2011/04/07 13:03:35 gabor Exp $	*/

/*-
 * Copyright (c) 1999 James Howard and Dag-Erling Co챦dan Sm첩rgrav
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * A really poor man's queue.  It does only what it has to and gets out of
 * Dodge.  It is used in place of <sys/queue.h> to get a better performance.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/grep/queue.c,v 1.5 2011/04/07 13:03:35 gabor Exp $");

#include <sys/param.h>
#include <sys/queue.h>

#include <stdlib.h>
#include <string.h>


struct qentry {
	STAILQ_ENTRY(qentry)	list;
	struct str	 	data;
};

static STAILQ_HEAD(, qentry)	queue = STAILQ_HEAD_INITIALIZER(queue);
static unsigned long long	count;

static struct qentry	*dequeue(void);

void
enqueue(struct str *x)
{
	GCURRENT_FUNCTION
	struct qentry *item;

	item = grep_malloc(sizeof(struct qentry));
	item->data.dat = grep_malloc(sizeof(char) * x->len);
	item->data.len = x->len;
	item->data.line_no = x->line_no;
	item->data.off = x->off;
	memcpy(item->data.dat, x->dat, x->len);
	item->data.file = x->file;

	STAILQ_INSERT_TAIL(&queue, item, list);

	if (++count > Bflag)
		free(dequeue());
}

static struct qentry *
dequeue(void)
{
	GCURRENT_FUNCTION
	struct qentry *item;

	item = STAILQ_FIRST(&queue);
	if (item == NULL)
		return (NULL);

	STAILQ_REMOVE_HEAD(&queue, list);
	--count;
	return (item);
}

void
printqueue(void)
{
	GCURRENT_FUNCTION
	struct qentry *item;

	while ((item = dequeue()) != NULL) {
		printline(&item->data, '-', (regmatch_t *)NULL, 0);
		free(item);
	}
}

void
clearqueue(void)
{
	GCURRENT_FUNCTION
	struct qentry *item;

	while ((item = dequeue()) != NULL)
		free(item);
}

/*	$NetBSD: util.c,v 1.9 2011/02/27 17:33:37 joerg Exp $	*/
/*	$FreeBSD: src/usr.bin/grep/util.c,v 1.19 2011/12/07 12:25:28 gabor Exp $	*/
/*	$OpenBSD: util.c,v 1.39 2010/07/02 22:18:03 tedu Exp $	*/

/*-
 * Copyright (c) 1999 James Howard and Dag-Erling Co챦dan Sm첩rgrav
 * Copyright (C) 2008-2010 Gabor Kovesdan <gabor@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/grep/util.c,v 1.19 2011/12/07 12:25:28 gabor Exp $");

#include <sys/stat.h>
#include <sys/types.h>
#ifdef __APPLE__
#include <sys/param.h>
#endif

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <fnmatch.h>
#include <fts.h>
#include <libgen.h>
#ifdef __APPLE__
#include <locale.h>
#endif /* __APPLE__ */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>

#ifndef WITHOUT_FASTMATCH
#include "fastmatch.h"
#endif

static int	 linesqueued;
static int	 procline(struct str *l, int);

bool
file_matching(const char *fname)
{
	GCURRENT_FUNCTION
	char *fname_base;
	bool ret;

	ret = finclude ? false : true;
#ifdef __APPLE__
	fname_base = basename((char *)fname);
#else
	fname_base = basename(fname);
#endif

	for (unsigned int i = 0; i < fpatterns; ++i) {
		if (fnmatch(fpattern[i].pat, fname, 0) == 0 ||
		    fnmatch(fpattern[i].pat, fname_base, 0) == 0) {
			if (fpattern[i].mode == EXCL_PAT)
				return (false);
			else
				ret = true;
		}
	}
	return (ret);
}

static inline bool
dir_matching(const char *dname)
{
	GCURRENT_FUNCTION
	bool ret;

	ret = dinclude ? false : true;

	for (unsigned int i = 0; i < dpatterns; ++i) {
		if (dname != NULL &&
		    fnmatch(dpattern[i].pat, dname, 0) == 0) {
			if (dpattern[i].mode == EXCL_PAT)
				return (false);
			else
				ret = true;
		}
	}
	return (ret);
}

/*
 * Processes a directory when a recursive search is performed with
 * the -R option.  Each appropriate file is passed to procfile().
 */
int
grep_tree(char **argv)
{
	GCURRENT_FUNCTION
	FTS *fts;
	FTSENT *p;
	int c, fts_flags;
	bool ok;

	c = fts_flags = 0;

	switch(linkbehave) {
	case LINK_EXPLICIT:
		fts_flags = FTS_COMFOLLOW;
		break;
	case LINK_SKIP:
		fts_flags = FTS_PHYSICAL;
		break;
	default:
		fts_flags = FTS_LOGICAL;
			
	}

	fts_flags |= FTS_NOSTAT | FTS_NOCHDIR;

	if (!(fts = fts_open(argv, fts_flags, NULL)))
		err(2, "fts_open");
	while ((p = fts_read(fts)) != NULL) {
		switch (p->fts_info) {
		case FTS_DNR:
			/* FALLTHROUGH */
		case FTS_ERR:
			file_err = true;
			if(!sflag)
				warnx("%s: %s", p->fts_path, strerror(p->fts_errno));
			break;
		case FTS_D:
			/* FALLTHROUGH */
		case FTS_DP:
			if (dexclude || dinclude)
				if (!dir_matching(p->fts_name) ||
				    !dir_matching(p->fts_path))
					fts_set(fts, p, FTS_SKIP);
			break;
		case FTS_DC:
			/* Print a warning for recursive directory loop */
			warnx("warning: %s: recursive directory loop",
				p->fts_path);
			break;
		default:
			/* Check for file exclusion/inclusion */
			ok = true;
			if (fexclude || finclude)
				ok &= file_matching(p->fts_path);

			if (ok)
				c += procfile(p->fts_path);
			break;
		}
	}

	fts_close(fts);
	return (c);
}

/*
 * Opens a file and processes it.  Each file is processed line-by-line
 * passing the lines to procline().
 */
int
procfile(const char *fn)
{
	GCURRENT_FUNCTION
	struct file *f;
	struct stat sb;
	struct str ln;
	mode_t s;
	int c, t;

	if (mflag && (mcount <= 0))
		return (0);

	if (strcmp(fn, "-") == 0) {
#ifdef __APPLE__
		/* 4053512, 10290183 */
		if (dirbehave == DIR_RECURSE && isatty(STDIN_FILENO)) {
			warnx("warning: recursive search of stdin");
		}
#endif
		fn = label != NULL ? label : getstr(1);
		f = grep_open(NULL);
	} else {
		if (!stat(fn, &sb)) {
			/* Check if we need to process the file */
			s = sb.st_mode & S_IFMT;
			if (s == S_IFDIR && dirbehave == DIR_SKIP)
				return (0);
			if ((s == S_IFIFO || s == S_IFCHR || s == S_IFBLK
				|| s == S_IFSOCK) && devbehave == DEV_SKIP)
					return (0);
		}
		f = grep_open(fn);
	}
	if (f == NULL) {
		file_err = true;
		if (!sflag)
			warn("%s", fn);
		return (0);
	}

	ln.file = grep_malloc(strlen(fn) + 1);
	strcpy(ln.file, fn);
	ln.line_no = 0;
	ln.len = 0;
	linesqueued = 0;
	tail = 0;
	ln.off = -1;

	for (c = 0;  c == 0 || !(lflag || qflag); ) {
		ln.off += ln.len + 1;
		if ((ln.dat = grep_fgetln(f, &ln.len)) == NULL || ln.len == 0) {
			if (ln.line_no == 0 && matchall)
				return (0);
			else
				break;
		}
		if (ln.len > 0 && ln.dat[ln.len - 1] == '\n')
			--ln.len;
		ln.line_no++;

		/* Return if we need to skip a binary file */
		if (f->binary && binbehave == BINFILE_SKIP) {
			grep_close(f);
			free(ln.file);
			free(f);
			return (0);
		}
		/* Process the file line-by-line */
		if ((t = procline(&ln, f->binary)) == 0 && Bflag > 0) {
			enqueue(&ln);
			linesqueued++;
		}
		c += t;
		if (mflag && mcount <= 0)
			break;
	}
	if (Bflag > 0)
		clearqueue();
	grep_close(f);

#ifdef __APPLE__
	/* 10680370 */
	if (cflag && !qflag) {
#else
	if (cflag) {
#endif
		if (!hflag)
			printf("%s:", ln.file);
		printf("%u\n", c);
	}
	if (lflag && !qflag && c != 0)
		printf("%s%c", fn, nullflag ? 0 : '\n');
	if (Lflag && !qflag && c == 0)
		printf("%s%c", fn, nullflag ? 0 : '\n');
	if (c && !cflag && !lflag && !Lflag &&
	    binbehave == BINFILE_BIN && f->binary && !qflag && stk == 0)
		printf(getstr(8), fn);

	free(ln.file);
	free(f);
	return (c);
}

int
procstring(char *f)
{
	const char * fn = "string";
	GCURRENT_FUNCTION
	struct stat sb;
	struct str ln;
	mode_t s;
	int c, t;

	if (mflag && (mcount <= 0))
		return (0);

	if (f == NULL) {
		file_err = true;
		if (!sflag)
			warn("%s", fn);
		return (0);
	}

	ln.file = grep_malloc(strlen(f) + 1);
	strcpy(ln.file, f);
	ln.line_no = 0;
	ln.len = 0;
	linesqueued = 0;
	tail = 0;
	ln.off = -1;

	for (c = 0;  c == 0 || !(lflag || qflag); ) {
		ln.off += ln.len + 1;
		if ((ln.dat = grep_fgetlns(f, &ln.len)) == NULL || ln.len == 0) {
			if (ln.line_no == 0 && matchall)
				return (0);
			else
				break;
		}
		if (ln.len > 0 && ln.dat[ln.len - 1] == '\n')
			--ln.len;
		ln.line_no++;

		/* Process the file line-by-line */
		if ((t = procline(&ln, false)) == 0 && Bflag > 0) {
			enqueue(&ln);
			linesqueued++;
		}
		c += t;
		if (mflag && mcount <= 0)
			break;
	}
	if (Bflag > 0)
		clearqueue();

#ifdef __APPLE__
	/* 10680370 */
	if (cflag && !qflag) {
#else
	if (cflag) {
#endif
		if (!hflag)
			printf("%s:", ln.file);
		printf("%u\n", c);
	}
	if (lflag && !qflag && c != 0)
		printf("%s%c", fn, nullflag ? 0 : '\n');
	if (Lflag && !qflag && c == 0)
		printf("%s%c", fn, nullflag ? 0 : '\n');
	if (c && !cflag && !lflag && !Lflag &&
	    binbehave == BINFILE_BIN && f && !qflag && stk == 0 && ext == 0)
		printf(getstr(8), fn);
	
	free(ln.file);
	return (c);
}

#ifdef __APPLE__
static int
mbtowc_reverse(wchar_t *pwc, const char *s, size_t n)
{
	GCURRENT_FUNCTION
	int result;
	size_t i;

	result = -1;
	for (i = 1; i <= n; i++) {
		result = mbtowc(pwc, s - i, i);
		if (result != -1) {
			break;
		}
	}

	return result;
}
#endif

#define iswword(x)	(iswalnum((x)) || (x) == L'_')

/*
 * Processes a line comparing it with the specified patterns.  Each pattern
 * is looped to be compared along with the full string, saving each and every
 * match, which is necessary to colorize the output and to count the
 * matches.  The matching lines are passed to printline() to display the
 * appropriate output.
 */
static int
procline(struct str *l, int nottext)
{
	GCURRENT_FUNCTION
#ifdef __APPLE__
	int nmatches;
	regmatch_t *matches;
#else
	regmatch_t matches[MAX_LINE_MATCHES];
#endif
	regmatch_t pmatch;
	size_t st = 0;
	unsigned int i;
	int c = 0, m = 0, r = 0;

#ifdef __APPLE__
	nmatches = MIN_LINE_MATCHES;
	matches = grep_malloc(nmatches * sizeof(regmatch_t));
#endif

	/* Loop to process the whole line */
	do {
#ifdef WITHOUT_FASTMATCH
		if (matchall) {
			c = !vflag;
			break;
		}
#endif

		pmatch.rm_so = st;
		pmatch.rm_eo = l->len;

		/* Loop to compare with all the patterns */
		for (i = 0; i < patterns; i++) {
#ifdef __APPLE__
			/* 10462853: Treat binary files as binary. */
			if (nottext) {
				setlocale(LC_ALL, "C");
			}
#endif /* __APPLE__ */
#ifndef WITHOUT_FASTMATCH
			if (fg_pattern[i].pattern)
				r = fastexec(&fg_pattern[i],
				    l->dat, 1, &pmatch, eflags);
			else
#endif
				r = regexec(&r_pattern[i], l->dat, 1,
				    &pmatch, eflags);
#ifdef __APPLE__
			if (nottext) {
				setlocale(LC_ALL, "");
			}
#endif /* __APPLE__ */
			r = (r == 0) ? 0 : REG_NOMATCH;
			st = (cflags & REG_NOSUB)
				? (size_t)l->len
				: (size_t)pmatch.rm_eo;
			if (r == REG_NOMATCH)
				continue;
			/* Check for full match */
			if (r == 0 && xflag)
				if (pmatch.rm_so != 0 ||
				    (size_t)pmatch.rm_eo != l->len)
					r = REG_NOMATCH;
			/* Check for whole word match */
#ifndef WITHOUT_FASTMATCH
			if (r == 0 && (wflag || fg_pattern[i].word)) {
#else
			if (r == 0 && (wflag)) {
#endif
				wchar_t wbegin, wend;

				wbegin = wend = L' ';
				if (pmatch.rm_so != 0 &&
#ifdef __APPLE__
				    mbtowc_reverse(&wbegin, &l->dat[pmatch.rm_so], MAX(MB_CUR_MAX, pmatch.rm_so)) == -1)
#else
				    sscanf(&l->dat[pmatch.rm_so - 1],
				    "%lc", &wbegin) != 1)
#endif
					r = REG_NOMATCH;
				else if ((size_t)pmatch.rm_eo !=
				    l->len &&
#ifdef __APPLE__
				    mbtowc(&wend, &l->dat[pmatch.rm_eo], MAX(MB_CUR_MAX, l->len - (size_t)pmatch.rm_eo)) == -1)
#else
				    sscanf(&l->dat[pmatch.rm_eo],
				    "%lc", &wend) != 1)
#endif
					r = REG_NOMATCH;
				else if (iswword(wbegin) ||
				    iswword(wend))
					r = REG_NOMATCH;
			}
			if (r == 0) {
				if (m == 0)
					c++;
#ifdef __APPLE__
				if (m < MAX_LINE_MATCHES) {
					if (m >= nmatches) {
						nmatches += MIN_LINE_MATCHES;
						matches = grep_realloc(matches, nmatches * sizeof(regmatch_t));
					}
					matches[m++] = pmatch;
				}
#else
				if (m < MAX_LINE_MATCHES)
					matches[m++] = pmatch;
#endif
				/* matches - skip further patterns */
				if ((color == NULL && !oflag) ||
				    qflag || lflag)
					break;
			}
		}

		if (vflag) {
			c = !c;
			break;
		}

		/* One pass if we are not recording matches */
#ifdef __APPLE__
		/* 10593340: If -w didn't match, keep going. */
		if (!(wflag && r == REG_NOMATCH) && ((color == NULL && !oflag) || qflag || lflag))
#else
		if ((color == NULL && !oflag) || qflag || lflag)
#endif
			break;

		if (st == (size_t)pmatch.rm_so)
			break; 	/* No matches */
	} while (st < l->len);


	/* Count the matches if we have a match limit */
	if (mflag)
		mcount -= c;

	if (c && binbehave == BINFILE_BIN && nottext) {
#ifdef __APPLE__
		free(matches);
#endif
		return (c); /* Binary file */
	}

	/* Dealing with the context */
	if ((tail || c) && !cflag && !qflag && !lflag && !Lflag) {
		if (c) {
			if (!first && !prev && !tail && Aflag)
				printf("--\n");
			tail = Aflag;
			if (Bflag > 0) {
				if (!first && !prev)
					printf("--\n");
				printqueue();
			}
			linesqueued = 0;
			printline(l, ':', matches, m);
		} else {
			printline(l, '-', matches, m);
			tail--;
		}
	}

	if (c) {
		prev = true;
		first = false;
	} else
		prev = false;

#ifdef __APPLE__
	free(matches);
#endif
	return (c);
}

/*
 * Safe malloc() for internal use.
 */
void *
grep_malloc(size_t size)
{
	GCURRENT_FUNCTION
	void *ptr;

	if ((ptr = malloc(size)) == NULL)
		err(2, "malloc");
	return (ptr);
}

/*
 * Safe calloc() for internal use.
 */
void *
grep_calloc(size_t nmemb, size_t size)
{
	GCURRENT_FUNCTION
	void *ptr;

	if ((ptr = calloc(nmemb, size)) == NULL)
		err(2, "calloc");
	return (ptr);
}

/*
 * Safe realloc() for internal use.
 */
void *
grep_realloc(void *ptr, size_t size)
{
	GCURRENT_FUNCTION

	if ((ptr = realloc(ptr, size)) == NULL)
		err(2, "realloc");
	return (ptr);
}

/*
 * Safe strdup() for internal use.
 */
char *
grep_strdup(const char *str)
{
	GCURRENT_FUNCTION
	char *ret;

	if ((ret = strdup(str)) == NULL)
		err(2, "strdup");
	return (ret);
}

/*
 * Prints a matching line according to the command line options.
 */
void
printline(struct str *line, int sep, regmatch_t *matches, int m)
{
	GCURRENT_FUNCTION
	size_t a = 0;
	int i, n = 0;

	if (!hflag) {
		if (!nullflag) {
			fputs(line->file, stdout);
			++n;
		} else {
			printf("%s", line->file);
			putchar(0);
		}
	}
	if (nflag) {
		if (n > 0)
			putchar(sep);
		printf("%d", line->line_no);
		++n;
	}
	if (bflag) {
		if (n > 0)
			putchar(sep);
		printf("%lld", (long long)line->off);
		++n;
	}
	if (n)
		putchar(sep);
	/* --color and -o */
	if ((oflag || color) && m > 0) {
		for (i = 0; i < m; i++) {
			if (!oflag)
				fwrite(line->dat + a, matches[i].rm_so - a, 1,
				    stdout);
			if (color)
				fprintf(stdout, "\33[%sm\33[K", color);

				fwrite(line->dat + matches[i].rm_so,
				    matches[i].rm_eo - matches[i].rm_so, 1,
				    stdout);
			if (color)
				fprintf(stdout, "\33[m\33[K");
			a = matches[i].rm_eo;
			if (oflag)
				putchar('\n');
		}
		if (!oflag) {
			if (line->len - a > 0)
				fwrite(line->dat + a, line->len - a, 1, stdout);
			putchar('\n');
		}
	} else {
		fwrite(line->dat, line->len, 1, stdout);
		putchar('\n');
	}
}

/*	$NetBSD: grep.c,v 1.4 2011/02/16 01:31:33 joerg Exp $	*/
/* 	$FreeBSD: src/usr.bin/grep/grep.c,v 1.16 2012/01/15 17:01:28 eadler Exp $	*/
/*	$OpenBSD: grep.c,v 1.42 2010/07/02 22:18:03 tedu Exp $	*/

/*-
 * Copyright (c) 1999 James Howard and Dag-Erling Co챦dan Sm첩rgrav
 * Copyright (C) 2008-2009 Gabor Kovesdan <gabor@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/grep/grep.c,v 1.16 2012/01/15 17:01:28 eadler Exp $");

#include <sys/stat.h>
#include <sys/types.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <limits.h>
#include <libgen.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef WITHOUT_FASTMATCH
#include "fastmatch.h"
#endif

#ifndef WITHOUT_NLS
#include <nl_types.h>
nl_catd	 catalog;
#endif

/*
 * Default messags to use when NLS is disabled or no catalogue
 * is found.
 */
const char	*errstr[] = {
	"",
/* 1*/	"(standard input)",
/* 2*/	"cannot read bzip2 compressed file",
/* 3*/	"unknown %s option",
#ifdef __APPLE__
/* 4*/	"usage: %s [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n",
#else
/* 4*/	"usage: %s [-abcDEFGHhIiJLlmnOoPqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n",
#endif
/* 5*/	"\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n",
/* 6*/	"\t[--context[=num]] [--directories=action] [--label] [--line-buffered]\n",
/* 7*/	"\t[--null] [pattern] [file ...]\n",
/* 8*/	"Binary file %s matches\n",
/* 9*/	"%s (BSD grep) %s\n",
};

/* Flags passed to regcomp() and regexec() */
int		 cflags = REG_NOSUB;
int		 eflags = REG_STARTEND;

/* Shortcut for matching all cases like empty regex */
bool		 matchall;

/* Searching patterns */
unsigned int	 patterns, pattern_sz;
struct pat	*pattern;
regex_t		*r_pattern;
#ifndef WITHOUT_FASTMATCH
fastmatch_t	*fg_pattern;
#endif

/* Filename exclusion/inclusion patterns */
unsigned int	 fpatterns, fpattern_sz;
unsigned int	 dpatterns, dpattern_sz;
struct epat	*dpattern, *fpattern;

/* For regex errors  */
char	 re_error[RE_ERROR_BUF + 1];

/* Command-line flags */
unsigned long long Aflag;	/* -A x: print x lines trailing each match */
unsigned long long Bflag;	/* -B x: print x lines leading each match */
bool	 Hflag;		/* -H: always print file name */
bool	 Lflag;		/* -L: only show names of files with no matches */
bool	 bflag;		/* -b: show block numbers for each match */
bool	 cflag;		/* -c: only show a count of matching lines */
bool	 hflag;		/* -h: don't print filename headers */
bool	 iflag;		/* -i: ignore case */
bool	 lflag;		/* -l: only show names of files with matches */
bool	 mflag;		/* -m x: stop reading the files after x matches */
long long mcount;	/* count for -m */
bool	 nflag;		/* -n: show line numbers in front of matching lines */
bool	 oflag;		/* -o: print only matching part */
bool	 qflag;		/* -q: quiet mode (don't output anything) */
bool	 sflag;		/* -s: silent mode (ignore errors) */
bool	 vflag;		/* -v: only show non-matching lines */
bool	 wflag;		/* -w: pattern must start and end on word boundaries */
bool	 xflag;		/* -x: pattern must match entire line */
bool	 lbflag;	/* --line-buffered */
bool	 nullflag;	/* --null */
char	*label;		/* --label */
const char *color;	/* --color */
int	 grepbehave = GREP_BASIC;	/* -EFGP: type of the regex */
int	 binbehave = BINFILE_BIN;	/* -aIU: handling of binary files */
int	 filebehave = FILE_STDIO;	/* -JZ: normal, gzip or bzip2 file */
int	 devbehave = DEV_READ;		/* -D: handling of devices */
int	 dirbehave = DIR_READ;		/* -dRr: handling of directories */
int	 linkbehave = LINK_READ;	/* -OpS: handling of symlinks */

bool	 dexclude, dinclude;	/* --exclude-dir and --include-dir */
bool	 fexclude, finclude;	/* --exclude and --include */

enum {
	BIN_OPT = CHAR_MAX + 1,
	COLOR_OPT,
	HELP_OPT,
	MMAP_OPT,
	LINEBUF_OPT,
	LABEL_OPT,
	NULL_OPT,
	R_EXCLUDE_OPT,
	R_INCLUDE_OPT,
	R_DEXCLUDE_OPT,
	R_DINCLUDE_OPT
};

static inline const char	*init_color(const char *);

/* Housekeeping */
bool	 first = true;	/* flag whether we are processing the first match */
bool	 prev;		/* flag whether or not the previous line matched */
int	 tail;		/* lines left to print */
bool	 file_err;	/* file reading error */

/*
 * Prints usage information and returns 2.
 */
static int
usage(void)
{
	GCURRENT_FUNCTION
	fprintf(stderr, getstr(4), getprogname());
	fprintf(stderr, "%s", getstr(5));
	fprintf(stderr, "%s", getstr(6));
	fprintf(stderr, "%s", getstr(7));
	return(2);
}

static const char	*optstr = "0123456789A:B:C:D:EFGHIJMLOPSRUVZabcd:e:f:hilm:nopqrsuvwxXy";

static const struct option long_options[] =
{
	{"binary-files",	required_argument,	NULL, BIN_OPT},
	{"help",		no_argument,		NULL, HELP_OPT},
	{"mmap",		no_argument,		NULL, MMAP_OPT},
	{"line-buffered",	no_argument,		NULL, LINEBUF_OPT},
	{"label",		required_argument,	NULL, LABEL_OPT},
	{"null",		no_argument,		NULL, NULL_OPT},
	{"color",		optional_argument,	NULL, COLOR_OPT},
	{"colour",		optional_argument,	NULL, COLOR_OPT},
	{"exclude",		required_argument,	NULL, R_EXCLUDE_OPT},
	{"include",		required_argument,	NULL, R_INCLUDE_OPT},
	{"exclude-dir",		required_argument,	NULL, R_DEXCLUDE_OPT},
	{"include-dir",		required_argument,	NULL, R_DINCLUDE_OPT},
	{"after-context",	required_argument,	NULL, 'A'},
	{"text",		no_argument,		NULL, 'a'},
	{"before-context",	required_argument,	NULL, 'B'},
	{"byte-offset",		no_argument,		NULL, 'b'},
	{"context",		optional_argument,	NULL, 'C'},
	{"count",		no_argument,		NULL, 'c'},
	{"devices",		required_argument,	NULL, 'D'},
        {"directories",		required_argument,	NULL, 'd'},
	{"extended-regexp",	no_argument,		NULL, 'E'},
	{"regexp",		required_argument,	NULL, 'e'},
	{"fixed-strings",	no_argument,		NULL, 'F'},
	{"file",		required_argument,	NULL, 'f'},
	{"basic-regexp",	no_argument,		NULL, 'G'},
	{"no-filename",		no_argument,		NULL, 'h'},
	{"with-filename",	no_argument,		NULL, 'H'},
	{"ignore-case",		no_argument,		NULL, 'i'},
	{"bz2decompress",	no_argument,		NULL, 'J'},
	{"files-with-matches",	no_argument,		NULL, 'l'},
	{"files-without-match", no_argument,            NULL, 'L'},
	{"max-count",		required_argument,	NULL, 'm'},
	{"lzma",		no_argument,		NULL, 'M'},
	{"line-number",		no_argument,		NULL, 'n'},
	{"only-matching",	no_argument,		NULL, 'o'},
	{"quiet",		no_argument,		NULL, 'q'},
	{"silent",		no_argument,		NULL, 'q'},
	{"recursive",		no_argument,		NULL, 'r'},
	{"no-messages",		no_argument,		NULL, 's'},
	{"binary",		no_argument,		NULL, 'U'},
	{"unix-byte-offsets",	no_argument,		NULL, 'u'},
	{"invert-match",	no_argument,		NULL, 'v'},
	{"version",		no_argument,		NULL, 'V'},
	{"word-regexp",		no_argument,		NULL, 'w'},
	{"line-regexp",		no_argument,		NULL, 'x'},
	{"xz",			no_argument,		NULL, 'X'},
	{"decompress",          no_argument,            NULL, 'Z'},
	{NULL,			no_argument,		NULL, 0}
};

/*
 * Adds a searching pattern to the internal array.
 */
static void
add_pattern(char *pat, size_t len)
{
	GCURRENT_FUNCTION

	/* Do not add further pattern if we already match everything */
	if (matchall)
	  return;

	/* Check if we can do a shortcut */
	if (len == 0) {
		matchall = true;
#ifndef WITHOUT_FASTMATCH
		for (unsigned int i = 0; i < patterns; i++) {
			free(pattern[i].pat);
		}
		pattern = grep_realloc(pattern, sizeof(struct pat));
		pattern[0].pat = NULL;
		pattern[0].len = 0;
		patterns = 1;
#endif
		return;
	}
	/* Increase size if necessary */
	if (patterns == pattern_sz) {
		pattern_sz *= 2;
		pattern = grep_realloc(pattern, ++pattern_sz *
		    sizeof(struct pat));
	}
	if (len > 0 && pat[len - 1] == '\n')
		--len;
	/* pat may not be NUL-terminated */
	pattern[patterns].pat = grep_malloc(len + 1);
	memcpy(pattern[patterns].pat, pat, len);
	pattern[patterns].len = len;
	pattern[patterns].pat[len] = '\0';
	++patterns;
}

/*
 * Adds a file include/exclude pattern to the internal array.
 */
static void
add_fpattern(const char *pat, int mode)
{
	GCURRENT_FUNCTION

	/* Increase size if necessary */
	if (fpatterns == fpattern_sz) {
		fpattern_sz *= 2;
		fpattern = grep_realloc(fpattern, ++fpattern_sz *
		    sizeof(struct epat));
	}
	fpattern[fpatterns].pat = grep_strdup(pat);
	fpattern[fpatterns].mode = mode;
	++fpatterns;
}

/*
 * Adds a directory include/exclude pattern to the internal array.
 */
static void
add_dpattern(const char *pat, int mode)
{
	GCURRENT_FUNCTION

	/* Increase size if necessary */
	if (dpatterns == dpattern_sz) {
		dpattern_sz *= 2;
		dpattern = grep_realloc(dpattern, ++dpattern_sz *
		    sizeof(struct epat));
	}
	dpattern[dpatterns].pat = grep_strdup(pat);
	dpattern[dpatterns].mode = mode;
	++dpatterns;
}

/*
 * Adds search patterns from arguments.
 */
static void
add_arg_patterns(const char *arg)
{
	GCURRENT_FUNCTION
	char *argcopy, *pattern;

	argcopy = grep_strdup(arg);
	while ((pattern = strsep(&argcopy, "\n")) != NULL) {
		add_pattern(pattern, strlen(pattern));
	}
	free(argcopy);
}

/*
 * Reads searching patterns from a file and adds them with add_pattern().
 */
static void
read_patterns(const char *fn)
{
	GCURRENT_FUNCTION
	struct stat st;
	FILE *f;
	char *line;
	size_t len;

	if ((f = fopen(fn, "r")) == NULL)
		err(2, "%s", fn);
	if ((fstat(fileno(f), &st) == -1) || (S_ISDIR(st.st_mode))) {
		fclose(f);
		return;
	}
        while ((line = fgetln(f, &len)) != NULL)
		add_pattern(line, line[0] == '\n' ? 0 : len);
	if (ferror(f))
		err(2, "%s", fn);
	fclose(f);
}

static inline const char *
init_color(const char *d)
{
	GCURRENT_FUNCTION
	char *c;

	c = getenv("GREP_COLOR");
	return (c != NULL && c[0] != '\0' ? c : d);
}

int
_grep(int argc, char *argv[])
{
	GCURRENT_FUNCTION
	pattern = empty;
	fpattern = fempty;
	dpattern = fempty;
	patterns = 0;
	fpatterns = 0;
	dpatterns = 0;
	pattern_sz = 0;
	fpattern_sz = 0;
	dpattern_sz = 0;
	qflag = 0;
	char **aargv, **eargv, *eopts;
	char *ep;
	const char *pn;
	unsigned long long l;
	unsigned int aargc, eargc, i;
	int c, lastc, needpattern, newarg, prevoptind;

	setlocale(LC_ALL, "");

#ifndef WITHOUT_NLS
	catalog = catopen("grep", NL_CAT_LOCALE);
#endif

	/* Check what is the program name of the binary.  In this
	   way we can have all the funcionalities in one binary
	   without the need of scripting and using ugly hacks. */
	pn = getprogname();
	if (pn[0] == 'b' && pn[1] == 'z') {
		filebehave = FILE_BZIP;
		pn += 2;
	} else if (pn[0] == 'x' && pn[1] == 'z') {
		filebehave = FILE_XZ;
		pn += 2;
	} else if (pn[0] == 'l' && pn[1] == 'z') {
		filebehave = FILE_LZMA;
		pn += 2;
	} else if (pn[0] == 'z') {
		filebehave = FILE_GZIP;
		pn += 1;
	}
	switch (pn[0]) {
	case 'e':
		grepbehave = GREP_EXTENDED;
		break;
	case 'f':
		grepbehave = GREP_FIXED;
		break;
	}

	lastc = '\0';
	newarg = 1;
	prevoptind = 1;
	needpattern = 1;

	eopts = getenv("GREP_OPTIONS");

	/* support for extra arguments in GREP_OPTIONS */
	eargc = 0;
	if (eopts != NULL && eopts[0] != '\0') {
		char *str;

		/* make an estimation of how many extra arguments we have */
		for (unsigned int j = 0; j < strlen(eopts); j++)
			if (eopts[j] == ' ')
				eargc++;

		eargv = (char **)grep_malloc(sizeof(char *) * (eargc + 1));

		eargc = 0;
		/* parse extra arguments */
		while ((str = strsep(&eopts, " ")) != NULL)
			if (str[0] != '\0')
				eargv[eargc++] = grep_strdup(str);

		aargv = (char **)grep_calloc(eargc + argc + 1,
		    sizeof(char *));

		aargv[0] = argv[0];
		for (i = 0; i < eargc; i++)
			aargv[i + 1] = eargv[i];
		for (int j = 1; j < argc; j++, i++)
			aargv[i + 1] = argv[j];

		aargc = eargc + argc;
	} else {
		aargv = argv;
		aargc = argc;
	}
	

	optind = 1;
	while (((c = getopt_long(aargc, aargv, optstr, long_options, NULL)) !=
	    -1)) {
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if (newarg || !isdigit(lastc))
				Aflag = 0;
			else if (Aflag > LLONG_MAX / 10) {
				errno = ERANGE;
				err(2, NULL);
			}
			Aflag = Bflag = (Aflag * 10) + (c - '0');
			break;
		case 'C':
			if (optarg == NULL) {
				Aflag = Bflag = 2;
				break;
			}
			/* FALLTHROUGH */
		case 'A':
			/* FALLTHROUGH */
		case 'B':
			errno = 0;
			l = strtoull(optarg, &ep, 10);
			if (((errno == ERANGE) && (l == ULLONG_MAX)) ||
			    ((errno == EINVAL) && (l == 0)))
				err(2, NULL);
			else if (ep[0] != '\0') {
				errno = EINVAL;
				err(2, NULL);
			}
			if (c == 'A')
				Aflag = l;
			else if (c == 'B')
				Bflag = l;
			else
				Aflag = Bflag = l;
			break;
		case 'a':
			binbehave = BINFILE_TEXT;
			break;
		case 'b':
			bflag = true;
			break;
		case 'c':
			cflag = true;
			break;
		case 'D':
			if (strcasecmp(optarg, "skip") == 0)
				devbehave = DEV_SKIP;
			else if (strcasecmp(optarg, "read") == 0)
				devbehave = DEV_READ;
			else
				errx(2, getstr(3), "--devices");
			break;
		case 'd':
			if (strcasecmp("recurse", optarg) == 0) {
				Hflag = true;
				dirbehave = DIR_RECURSE;
			} else if (strcasecmp("skip", optarg) == 0)
				dirbehave = DIR_SKIP;
			else if (strcasecmp("read", optarg) == 0)
				dirbehave = DIR_READ;
			else
				errx(2, getstr(3), "--directories");
			break;
		case 'E':
			grepbehave = GREP_EXTENDED;
			break;
		case 'e':
			add_arg_patterns(optarg);
			needpattern = 0;
			break;
		case 'F':
			grepbehave = GREP_FIXED;
			break;
		case 'f':
			read_patterns(optarg);
			needpattern = 0;
			break;
		case 'G':
			grepbehave = GREP_BASIC;
			break;
		case 'H':
			Hflag = true;
			break;
		case 'h':
			Hflag = false;
			hflag = true;
			break;
		case 'I':
			binbehave = BINFILE_SKIP;
			break;
		case 'i':
		case 'y':
			iflag =  true;
			cflags |= REG_ICASE;
			break;
		case 'J':
#ifdef WITHOUT_BZIP2
			errno = EOPNOTSUPP;
			err(2, "bzip2 support was disabled at compile-time");
#endif
			filebehave = FILE_BZIP;
			break;
		case 'L':
			lflag = false;
			Lflag = true;
			break;
		case 'l':
			Lflag = false;
			lflag = true;
			break;
		case 'm':
			mflag = true;
			errno = 0;
			mcount = strtoll(optarg, &ep, 10);
			if (((errno == ERANGE) && (mcount == LLONG_MAX)) ||
			    ((errno == EINVAL) && (mcount == 0)))
				err(2, NULL);
			else if (ep[0] != '\0') {
				errno = EINVAL;
				err(2, NULL);
			}
			break;
		case 'M':
#ifdef WITHOUT_LZMA
			errno = EOPNOTSUPP;
			err(2, "lzma support was disabled at compile-time");
#endif
			filebehave = FILE_LZMA;
			break;
		case 'n':
			nflag = true;
			break;
		case 'O':
			linkbehave = LINK_EXPLICIT;
			break;
		case 'o':
			oflag = true;
			cflags &= ~REG_NOSUB;
			break;
		case 'p':
			linkbehave = LINK_SKIP;
			break;
		case 'q':
			qflag = true;
			break;
		case 'S':
			linkbehave = LINK_READ;
			break;
		case 'R':
		case 'r':
			dirbehave = DIR_RECURSE;
			Hflag = true;
			break;
		case 's':
			sflag = true;
			break;
		case 'U':
			binbehave = BINFILE_BIN;
			break;
		case 'u':
		case MMAP_OPT:
#ifndef __APPLE__
			/* mmap mode is buggy (10789286) */
			filebehave = FILE_MMAP;
#endif
			break;
		case 'V':
			printf(getstr(9), getprogname(), VERSION);
			return(0);
		case 'v':
			vflag = true;
			break;
		case 'w':
			wflag = true;
			cflags &= ~REG_NOSUB;
			break;
		case 'x':
			xflag = true;
			cflags &= ~REG_NOSUB;
			break;
		case 'X':
#ifdef WITHOUT_LZMA
			errno = EOPNOTSUPP;
			err(2, "xz support was disabled at compile-time");
#endif
			filebehave = FILE_XZ;
			break;
		case 'Z':
			filebehave = FILE_GZIP;
			break;
		case BIN_OPT:
			if (strcasecmp("binary", optarg) == 0)
				binbehave = BINFILE_BIN;
			else if (strcasecmp("without-match", optarg) == 0)
				binbehave = BINFILE_SKIP;
			else if (strcasecmp("text", optarg) == 0)
				binbehave = BINFILE_TEXT;
			else
				errx(2, getstr(3), "--binary-files");
			break;
		case COLOR_OPT:
			color = NULL;
			if (optarg == NULL || strcasecmp("auto", optarg) == 0 ||
			    strcasecmp("tty", optarg) == 0 ||
			    strcasecmp("if-tty", optarg) == 0) {
				char *term;

				term = getenv("TERM");
				if (isatty(STDOUT_FILENO) && term != NULL &&
				    strcasecmp(term, "dumb") != 0)
					color = init_color("01;31");
			} else if (strcasecmp("always", optarg) == 0 ||
			    strcasecmp("yes", optarg) == 0 ||
			    strcasecmp("force", optarg) == 0) {
				color = init_color("01;31");
			} else if (strcasecmp("never", optarg) != 0 &&
			    strcasecmp("none", optarg) != 0 &&
			    strcasecmp("no", optarg) != 0)
				errx(2, getstr(3), "--color");
			cflags &= ~REG_NOSUB;
			break;
		case LABEL_OPT:
			label = optarg;
			break;
		case LINEBUF_OPT:
			lbflag = true;
			break;
		case NULL_OPT:
			nullflag = true;
			break;
		case R_INCLUDE_OPT:
			finclude = true;
			add_fpattern(optarg, INCL_PAT);
			break;
		case R_EXCLUDE_OPT:
			fexclude = true;
			add_fpattern(optarg, EXCL_PAT);
			break;
		case R_DINCLUDE_OPT:
			dinclude = true;
			add_dpattern(optarg, INCL_PAT);
			break;
		case R_DEXCLUDE_OPT:
			dexclude = true;
			add_dpattern(optarg, EXCL_PAT);
			break;
		case HELP_OPT:
		default:
			return usage();
		}
		lastc = c;
		newarg = optind != prevoptind;
		prevoptind = optind;
	}
	aargc -= optind;
	aargv += optind;

	/* Empty pattern file matches nothing */
#ifndef WITHOUT_FASTMATCH
	if (!needpattern && (patterns == 0))
#else
	if (!needpattern && (patterns == 0) && !matchall)
#endif
		return(1);

	/* Fail if we don't have any pattern */
	if (aargc == 0 && needpattern) {
		return usage();
	}

	/* Process patterns from command line */
	if (aargc != 0 && needpattern) {
		add_arg_patterns(*aargv);
		--aargc;
		++aargv;
	}

	switch (grepbehave) {
	case GREP_BASIC:
#ifdef __APPLE__
		//dztall
		//cflags |= REG_ENHANCED;
#endif
		break;
	case GREP_FIXED:
		/* XXX: header mess, REG_LITERAL not defined in gnu/regex.h */
		cflags |= 0020;
		break;
	case GREP_EXTENDED:
		cflags |= REG_EXTENDED;
#ifdef __APPLE__
		//dztall
		//cflags |= REG_ENHANCED;
#endif
		break;
	default:
		/* NOTREACHED */
		return usage();
	}

#ifndef WITHOUT_FASTMATCH
	fg_pattern = grep_calloc(patterns, sizeof(*fg_pattern));
#endif
	r_pattern = grep_calloc(patterns, sizeof(*r_pattern));

	/* Check if cheating is allowed (always is for fgrep). */
	for (i = 0; i < patterns; ++i) {
#ifndef WITHOUT_FASTMATCH
		if (fastncomp(&fg_pattern[i], pattern[i].pat,
		    pattern[i].len, cflags) != 0) {
#endif
			/* Fall back to full regex library */
			c = regcomp(&r_pattern[i], pattern[i].pat, cflags);
			if (c != 0) {
				regerror(c, &r_pattern[i], re_error,
				    RE_ERROR_BUF);
				errx(2, "%s", re_error);
			}
#ifndef WITHOUT_FASTMATCH
		}
#endif
	}

	if (lbflag)
		setlinebuf(stdout);

	if ((aargc == 0 || aargc == 1) && !Hflag)
		hflag = true;

	if (aargc == 0)
		return(!procfile("-"));

	if (dirbehave == DIR_RECURSE)
		c = grep_tree(aargv);
	else
		for (c = 0; aargc--; ++aargv) {
			if ((finclude || fexclude) && !file_matching(*aargv))
				continue;
			c+= procfile(*aargv);
		}

#ifndef WITHOUT_NLS
	catclose(catalog);
#endif

	/* Find out the correct return value according to the
	   results and the command line option. */
	return(c ? (file_err ? (qflag ? 0 : 2) : 0) : (file_err ? 2 : 1));
}


int
_grep_string(int argc, char *argv[], char * h)
{
	GCURRENT_FUNCTION
	pattern = empty;
	fpattern = fempty;
	dpattern = fempty;
	patterns = 0;
	fpatterns = 0;
	dpatterns = 0;
	pattern_sz = 0;
	fpattern_sz = 0;
	dpattern_sz = 0;
	qflag = 0;
	char **aargv, **eargv, *eopts;
	char *ep;
	const char *pn;
	unsigned long long l;
	unsigned int aargc, eargc, i;
	int c, lastc, needpattern, newarg, prevoptind;

	setlocale(LC_ALL, "");

#ifndef WITHOUT_NLS
	catalog = catopen("grep", NL_CAT_LOCALE);
#endif

	/* Check what is the program name of the binary.  In this
	   way we can have all the funcionalities in one binary
	   without the need of scripting and using ugly hacks. */
	pn = getprogname();
	if (pn[0] == 'b' && pn[1] == 'z') {
		filebehave = FILE_BZIP;
		pn += 2;
	} else if (pn[0] == 'x' && pn[1] == 'z') {
		filebehave = FILE_XZ;
		pn += 2;
	} else if (pn[0] == 'l' && pn[1] == 'z') {
		filebehave = FILE_LZMA;
		pn += 2;
	} else if (pn[0] == 'z') {
		filebehave = FILE_GZIP;
		pn += 1;
	}
	switch (pn[0]) {
	case 'e':
		grepbehave = GREP_EXTENDED;
		break;
	case 'f':
		grepbehave = GREP_FIXED;
		break;
	}

	lastc = '\0';
	newarg = 1;
	prevoptind = 1;
	needpattern = 1;

	eopts = getenv("GREP_OPTIONS");

	/* support for extra arguments in GREP_OPTIONS */
	eargc = 0;
	if (eopts != NULL && eopts[0] != '\0') {
		char *str;

		/* make an estimation of how many extra arguments we have */
		for (unsigned int j = 0; j < strlen(eopts); j++)
			if (eopts[j] == ' ')
				eargc++;

		eargv = (char **)grep_malloc(sizeof(char *) * (eargc + 1));

		eargc = 0;
		/* parse extra arguments */
		while ((str = strsep(&eopts, " ")) != NULL)
			if (str[0] != '\0')
				eargv[eargc++] = grep_strdup(str);

		aargv = (char **)grep_calloc(eargc + argc + 1,
		    sizeof(char *));

		aargv[0] = argv[0];
		for (i = 0; i < eargc; i++)
			aargv[i + 1] = eargv[i];
		for (int j = 1; j < argc; j++, i++)
			aargv[i + 1] = argv[j];

		aargc = eargc + argc;
	} else {
		aargv = argv;
		aargc = argc;
	}
	

	// If all command-line options have been parsed, then getopt() returns -1
	// The variable optind is the index of the next element to be processed in argv. The system initializes this value to 1. The caller can reset it to 1 to restart scanning of the same argv, or when scanning a new argument vector.
	optind = 1;
	while (((c = getopt_long(aargc, aargv, optstr, long_options, NULL)) !=
	    -1)) {
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if (newarg || !isdigit(lastc))
				Aflag = 0;
			else if (Aflag > LLONG_MAX / 10) {
				errno = ERANGE;
				err(2, NULL);
			}
			Aflag = Bflag = (Aflag * 10) + (c - '0');
			break;
		case 'C':
			if (optarg == NULL) {
				Aflag = Bflag = 2;
				break;
			}
			/* FALLTHROUGH */
		case 'A':
			/* FALLTHROUGH */
		case 'B':
			errno = 0;
			l = strtoull(optarg, &ep, 10);
			if (((errno == ERANGE) && (l == ULLONG_MAX)) ||
			    ((errno == EINVAL) && (l == 0)))
				err(2, NULL);
			else if (ep[0] != '\0') {
				errno = EINVAL;
				err(2, NULL);
			}
			if (c == 'A')
				Aflag = l;
			else if (c == 'B')
				Bflag = l;
			else
				Aflag = Bflag = l;
			break;
		case 'a':
			binbehave = BINFILE_TEXT;
			break;
		case 'b':
			bflag = true;
			break;
		case 'c':
			cflag = true;
			break;
		case 'D':
			if (strcasecmp(optarg, "skip") == 0)
				devbehave = DEV_SKIP;
			else if (strcasecmp(optarg, "read") == 0)
				devbehave = DEV_READ;
			else
				errx(2, getstr(3), "--devices");
			break;
		case 'd':
			if (strcasecmp("recurse", optarg) == 0) {
				Hflag = true;
				dirbehave = DIR_RECURSE;
			} else if (strcasecmp("skip", optarg) == 0)
				dirbehave = DIR_SKIP;
			else if (strcasecmp("read", optarg) == 0)
				dirbehave = DIR_READ;
			else
				errx(2, getstr(3), "--directories");
			break;
		case 'E':
			grepbehave = GREP_EXTENDED;
			break;
		case 'e':
			add_arg_patterns(optarg);
			needpattern = 0;
			break;
		case 'F':
			grepbehave = GREP_FIXED;
			break;
		case 'f':
			read_patterns(optarg);
			needpattern = 0;
			break;
		case 'G':
			grepbehave = GREP_BASIC;
			break;
		case 'H':
			Hflag = true;
			break;
		case 'h':
			Hflag = false;
			hflag = true;
			break;
		case 'I':
			binbehave = BINFILE_SKIP;
			break;
		case 'i':
		case 'y':
			iflag =  true;
			cflags |= REG_ICASE;
			break;
		case 'J':
#ifdef WITHOUT_BZIP2
			errno = EOPNOTSUPP;
			err(2, "bzip2 support was disabled at compile-time");
#endif
			filebehave = FILE_BZIP;
			break;
		case 'L':
			lflag = false;
			Lflag = true;
			break;
		case 'l':
			Lflag = false;
			lflag = true;
			break;
		case 'm':
			mflag = true;
			errno = 0;
			mcount = strtoll(optarg, &ep, 10);
			if (((errno == ERANGE) && (mcount == LLONG_MAX)) ||
			    ((errno == EINVAL) && (mcount == 0)))
				err(2, NULL);
			else if (ep[0] != '\0') {
				errno = EINVAL;
				err(2, NULL);
			}
			break;
		case 'M':
#ifdef WITHOUT_LZMA
			errno = EOPNOTSUPP;
			err(2, "lzma support was disabled at compile-time");
#endif
			filebehave = FILE_LZMA;
			break;
		case 'n':
			nflag = true;
			break;
		case 'O':
			linkbehave = LINK_EXPLICIT;
			break;
		case 'o':
			oflag = true;
			cflags &= ~REG_NOSUB;
			break;
		case 'p':
			linkbehave = LINK_SKIP;
			break;
		case 'q':
			qflag = true;
			break;
		case 'S':
			linkbehave = LINK_READ;
			break;
		case 'R':
		case 'r':
			dirbehave = DIR_RECURSE;
			Hflag = true;
			break;
		case 's':
			sflag = true;
			break;
		case 'U':
			binbehave = BINFILE_BIN;
			break;
		case 'u':
		case MMAP_OPT:
#ifndef __APPLE__
			/* mmap mode is buggy (10789286) */
			filebehave = FILE_MMAP;
#endif
			break;
		case 'V':
			printf(getstr(9), getprogname(), VERSION);
			return(0);
		case 'v':
			vflag = true;
			break;
		case 'w':
			wflag = true;
			cflags &= ~REG_NOSUB;
			break;
		case 'x':
			xflag = true;
			cflags &= ~REG_NOSUB;
			break;
		case 'X':
#ifdef WITHOUT_LZMA
			errno = EOPNOTSUPP;
			err(2, "xz support was disabled at compile-time");
#endif
			filebehave = FILE_XZ;
			break;
		case 'Z':
			filebehave = FILE_GZIP;
			break;
		case BIN_OPT:
			if (strcasecmp("binary", optarg) == 0)
				binbehave = BINFILE_BIN;
			else if (strcasecmp("without-match", optarg) == 0)
				binbehave = BINFILE_SKIP;
			else if (strcasecmp("text", optarg) == 0)
				binbehave = BINFILE_TEXT;
			else
				errx(2, getstr(3), "--binary-files");
			break;
		case COLOR_OPT:
			color = NULL;
			if (optarg == NULL || strcasecmp("auto", optarg) == 0 ||
			    strcasecmp("tty", optarg) == 0 ||
			    strcasecmp("if-tty", optarg) == 0) {
				char *term;

				term = getenv("TERM");
				if (isatty(STDOUT_FILENO) && term != NULL &&
				    strcasecmp(term, "dumb") != 0)
					color = init_color("01;31");
			} else if (strcasecmp("always", optarg) == 0 ||
			    strcasecmp("yes", optarg) == 0 ||
			    strcasecmp("force", optarg) == 0) {
				color = init_color("01;31");
			} else if (strcasecmp("never", optarg) != 0 &&
			    strcasecmp("none", optarg) != 0 &&
			    strcasecmp("no", optarg) != 0)
				errx(2, getstr(3), "--color");
			cflags &= ~REG_NOSUB;
			break;
		case LABEL_OPT:
			label = optarg;
			break;
		case LINEBUF_OPT:
			lbflag = true;
			break;
		case NULL_OPT:
			nullflag = true;
			break;
		case R_INCLUDE_OPT:
			finclude = true;
			add_fpattern(optarg, INCL_PAT);
			break;
		case R_EXCLUDE_OPT:
			fexclude = true;
			add_fpattern(optarg, EXCL_PAT);
			break;
		case R_DINCLUDE_OPT:
			dinclude = true;
			add_dpattern(optarg, INCL_PAT);
			break;
		case R_DEXCLUDE_OPT:
			dexclude = true;
			add_dpattern(optarg, EXCL_PAT);
			break;
		case HELP_OPT:
		default:
			return usage();
		}
		lastc = c;
		newarg = optind != prevoptind;
		prevoptind = optind;
	}
	aargc -= optind;
	aargv += optind;

	/* Empty pattern file matches nothing */
#ifndef WITHOUT_FASTMATCH
	if (!needpattern && (patterns == 0))
#else
	if (!needpattern && (patterns == 0) && !matchall)
#endif
		return(1);

	/* Fail if we don't have any pattern */
	if (aargc == 0 && needpattern) {
		return usage();
	}

	/* Process patterns from command line */
	if (aargc != 0 && needpattern) {
		add_arg_patterns(*aargv);
		--aargc;
		++aargv;
	}

	switch (grepbehave) {
	case GREP_BASIC:
#ifdef __APPLE__
		//dztall
		//cflags |= REG_ENHANCED;
#endif
		break;
	case GREP_FIXED:
		/* XXX: header mess, REG_LITERAL not defined in gnu/regex.h */
		cflags |= 0020;
		break;
	case GREP_EXTENDED:
		cflags |= REG_EXTENDED;
#ifdef __APPLE__
		//dztall
		//cflags |= REG_ENHANCED;
#endif
		break;
	default:
		/* NOTREACHED */
		return usage();
	}

#ifndef WITHOUT_FASTMATCH
	fg_pattern = grep_calloc(patterns, sizeof(*fg_pattern));
#endif
	r_pattern = grep_calloc(patterns, sizeof(*r_pattern));

	/* Check if cheating is allowed (always is for fgrep). */
	for (i = 0; i < patterns; ++i) {
#ifndef WITHOUT_FASTMATCH
		if (fastncomp(&fg_pattern[i], pattern[i].pat,
		    pattern[i].len, cflags) != 0) {
#endif
			/* Fall back to full regex library */
			c = regcomp(&r_pattern[i], pattern[i].pat, cflags);
			if (c != 0) {
				regerror(c, &r_pattern[i], re_error,
				    RE_ERROR_BUF);
				errx(2, "%s", re_error);
			}
#ifndef WITHOUT_FASTMATCH
		}
#endif
	}

	if (lbflag)
		setlinebuf(stdout);

	if ((aargc == 0 || aargc == 1) && !Hflag)
		hflag = true;

	if (aargc == 0)
		return(!procstring(h));

	if (dirbehave == DIR_RECURSE)
		c = grep_tree(aargv);
	else
		for (c = 0; aargc--; ++aargv) {
			if ((finclude || fexclude) && !file_matching(*aargv))
				continue;
			c+= procstring(h);
		}

#ifndef WITHOUT_NLS
	catclose(catalog);
#endif

	/* Find out the correct return value according to the
	   results and the command line option. */
	return(c ? (file_err ? (qflag ? 0 : 2) : 0) : (file_err ? 2 : 1));
}

int grep(char * s) {
	lst = 0;
	char * str = malloc(4906);
	memset(str, 0, 4096);
	str = strcatb(str, "grep --color=always ");
	str = strcatb(str, s);
	int argc;
	char ** argv;
	string_to_argv(str, &argc, &argv);
	free(str);
	return _grep(argc, argv);
}

int grep_string(char * s, char*strb) {
	// grep requires a new line to be present at the end of a string
	if (strb[strlen(strb)-1] != '\n') strb = strcatb(strb, "\n");
	lst = 0;
	char * str = malloc(4906);
	memset(str, 0, 4096);
	str = strcatb(str, "grep --color=always ");
	str = strcatb(str, s);
	int argc;
	char ** argv;
	string_to_argv(str, &argc, &argv);
	free(str);
	return _grep_string(argc, argv, strb);
}
