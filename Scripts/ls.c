#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <fts.h>
#include <string.h>

#define COLORLS

//Original source code found at : https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix

//For detailed information, search internet with 'ANSI Escape sequences' keyword.

#include <stdio.h>
#include <stdarg.h>

#ifndef COLORLS

#define RESET ""
#else

#define RESET "\x1B[0m"

#endif

#define NO_PRINT	1

#define HN_DECIMAL 0x01
#define HN_NOSPACE 0x02
#define HN_B 0x04
#define HN_DIVISOR_1000 0x08

#define HN_GETSCALE 0x10
#define HN_AUTOSCALE 0x20

extern long blocksize;		/* block size units */

extern int f_accesstime;	/* use time of last access */
extern int f_birthtime;		/* use time of file birth */
extern int f_flags;		/* show flags associated with a file */
extern int f_humanval;		/* show human-readable file sizes */
extern int f_inode;		/* print inode */
extern int f_longform;		/* long listing format */
extern int f_octal;		/* print unprintables in octal */
extern int f_octal_escape;	/* like f_octal but use C escapes if possible */
extern int f_nonprint;		/* show unprintables as ? */
extern int f_sectime;		/* print the real time for all files */
extern int f_size;		/* list size in short listing */
extern int f_slash;		/* append a '/' if the file is a directory */
extern int f_sortacross;	/* sort across rows, not down columns */
extern int f_statustime;	/* use time of last mode change */
extern int f_notabs;		/* don't use tab-separated multi-col output */
extern int f_type;		/* add type character for non-regular files */
extern int f_acl;		/* print ACLs in long format */
extern int f_xattr;		/* print extended attributes in long format  */
extern int f_group;		/* list group without owner */
extern int f_owner;		/* list owner without group */
#ifdef COLORLS
extern int f_color;		/* add type in color for non-regular files */
#endif
extern int f_numericonly;	/* don't convert uid/gid to name */

typedef struct {
	FTSENT *list;
	u_int64_t btotal;
	int bcfile;
	int entries;
	int maxlen;
	u_int s_block;
	u_int s_flags;
	u_int s_lattr;
	u_int s_group;
	u_int s_inode;
	u_int s_nlink;
	u_int s_size;
	u_int s_user;
} DISPLAY;

typedef struct {
	char *user;
	char *group;
	char *flags;
#ifndef __APPLE__
	char *lattr;
#endif /* __APPLE__ */
	char data[1];
} NAMES;

/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)extern.h	8.1 (Berkeley) 5/31/93
 * $FreeBSD: src/bin/ls/extern.h,v 1.19 2002/05/19 02:51:36 tjr Exp $
 */

int	 acccmp(const FTSENT *, const FTSENT *);
int	 revacccmp(const FTSENT *, const FTSENT *);
int	 modcmp(const FTSENT *, const FTSENT *);
int	 revmodcmp(const FTSENT *, const FTSENT *);
int	 namecmp(const FTSENT *, const FTSENT *);
int	 revnamecmp(const FTSENT *, const FTSENT *);
int	 statcmp(const FTSENT *, const FTSENT *);
int	 revstatcmp(const FTSENT *, const FTSENT *);
int	 sizecmp(const FTSENT *, const FTSENT *);
int	 revsizecmp(const FTSENT *, const FTSENT *);
int      humanize_number(char *, size_t, int64_t, const char *, int, int);
int	 birthcmp(const FTSENT *, const FTSENT *);
int	 revbirthcmp(const FTSENT *, const FTSENT *);

void	 printcol(DISPLAY *);
void	 printlong(DISPLAY *);
void	 printscol(DISPLAY *);
void	 printstream(DISPLAY *);
void	 usage(void);
int      prn_normal(const char *);
size_t	 len_octal(const char *, int);
int	 prn_octal(const char *);
int	 prn_printable(const char *);


#ifdef COLORLS
void	 parsecolors(const char *cs);
void     colorquit(int);

extern  char    *ansi_fgcol;
extern  char    *ansi_bgcol;
extern  char    *ansi_coloff;
extern  char    *attrs_off;
extern  char    *enter_bold;
#endif
 
/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if 0
#ifndef lint
static char sccsid[] = "@(#)cmp.c	8.1 (Berkeley) 5/31/93";
#endif /* not lint */
#endif
#include <sys/cdefs.h>
__RCSID("$FreeBSD: src/bin/ls/cmp.c,v 1.12 2002/06/30 05:13:54 obrien Exp $");



#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || \
    defined(_XOPEN_SOURCE) || defined(__NetBSD__)
#define ATIMENSEC_CMP(x, op, y) ((x)->st_atimensec op (y)->st_atimensec)
#define CTIMENSEC_CMP(x, op, y) ((x)->st_ctimensec op (y)->st_ctimensec)
#define MTIMENSEC_CMP(x, op, y) ((x)->st_mtimensec op (y)->st_mtimensec)
#define BTIMENSEC_CMP(x, op, y) ((x)->st_birthtimensec op (y)->st_birthtimensec)
#else
#define ATIMENSEC_CMP(x, op, y) \
	((x)->st_atimespec.tv_nsec op (y)->st_atimespec.tv_nsec)
#define CTIMENSEC_CMP(x, op, y) \
	((x)->st_ctimespec.tv_nsec op (y)->st_ctimespec.tv_nsec)
#define MTIMENSEC_CMP(x, op, y) \
	((x)->st_mtimespec.tv_nsec op (y)->st_mtimespec.tv_nsec)
#define BTIMENSEC_CMP(x, op, y) \
	((x)->st_birthtimespec.tv_nsec op (y)->st_birthtimespec.tv_nsec)
#endif

int
namecmp(const FTSENT *a, const FTSENT *b)
{
	return (strcoll(a->fts_name, b->fts_name));
}

int
revnamecmp(const FTSENT *a, const FTSENT *b)
{
	return (strcoll(b->fts_name, a->fts_name));
}

int
modcmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_mtime > a->fts_statp->st_mtime)
		return (1);
	else if (b->fts_statp->st_mtime < a->fts_statp->st_mtime)
		return (-1);
	else if (MTIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (1);
	else if (MTIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revmodcmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_mtime > a->fts_statp->st_mtime)
		return (-1);
	else if (b->fts_statp->st_mtime < a->fts_statp->st_mtime)
		return (1);
	else if (MTIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (-1);
	else if (MTIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

int
acccmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_atime > a->fts_statp->st_atime)
		return (1);
	else if (b->fts_statp->st_atime < a->fts_statp->st_atime)
		return (-1);
	else if (ATIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (1);
	else if (ATIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revacccmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_atime > a->fts_statp->st_atime)
		return (-1);
	else if (b->fts_statp->st_atime < a->fts_statp->st_atime)
		return (1);
	else if (ATIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (-1);
	else if (ATIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

int
statcmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_ctime > a->fts_statp->st_ctime)
		return (1);
	else if (b->fts_statp->st_ctime < a->fts_statp->st_ctime)
		return (-1);
	else if (CTIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (1);
	else if (CTIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revstatcmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_ctime > a->fts_statp->st_ctime)
		return (-1);
	else if (b->fts_statp->st_ctime < a->fts_statp->st_ctime)
		return (1);
	else if (CTIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (-1);
	else if (CTIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

int
sizecmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_size > a->fts_statp->st_size)
		return (1);
	if (b->fts_statp->st_size < a->fts_statp->st_size)
		return (-1);
	else
		return (namecmp(a, b));
}

int
revsizecmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_size > a->fts_statp->st_size)
		return (-1);
	if (b->fts_statp->st_size < a->fts_statp->st_size)
		return (1);
	else
		return (revnamecmp(a, b));
}

int
birthcmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_birthtime > a->fts_statp->st_birthtime)
		return (1);
	else if (b->fts_statp->st_birthtime < a->fts_statp->st_birthtime)
		return (-1);
	else if (BTIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (1);
	else if (BTIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (-1);
	else
		return (namecmp(a, b));
}

int
revbirthcmp(const FTSENT *a, const FTSENT *b)
{
	if (b->fts_statp->st_birthtime > a->fts_statp->st_birthtime)
		return (-1);
	else if (b->fts_statp->st_birthtime < a->fts_statp->st_birthtime)
		return (1);
	else if (BTIMENSEC_CMP(b->fts_statp, > , a->fts_statp))
		return (-1);
	else if (BTIMENSEC_CMP(b->fts_statp, < , a->fts_statp))
		return (1);
	else
		return (revnamecmp(a, b));
}

 
/*-
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if 0
#ifndef lint
static char sccsid[] = "@(#)util.c	8.3 (Berkeley) 4/2/94";
#endif /* not lint */
#endif
#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/bin/ls/util.c,v 1.38 2005/06/03 11:05:58 dd Exp $");

#include <sys/types.h>
#include <sys/stat.h>

#include <ctype.h>
#include <err.h>
#include <fts.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>


int
prn_normal(const char *s)
{
	mbstate_t mbs;
	wchar_t wc;
	int i, n;
	size_t clen;

	memset(&mbs, 0, sizeof(mbs));
	n = 0;
	while ((clen = mbrtowc(&wc, s, MB_LEN_MAX, &mbs)) != 0) {
		if (clen == (size_t)-2) {
			n += printf("%s", s);
			break;
		}
		if (clen == (size_t)-1) {
			memset(&mbs, 0, sizeof(mbs));
			putchar((unsigned char)*s);
			s++;
			n++;
			continue;
		}
		for (i = 0; i < (int)clen; i++)
			putchar((unsigned char)s[i]);
		s += clen;
		if (iswprint(wc))
			n += wcwidth(wc);
	}
	return (n);
}

int
prn_printable(const char *s)
{
	//dztall
	printf("%s", s);
	return strlen(s);
	/*mbstate_t mbs;
	wchar_t wc;
	int i, n;
	size_t clen;

	memset(&mbs, 0, sizeof(mbs));
	n = 0;
	while ((clen = mbrtowc(&wc, s, MB_LEN_MAX, &mbs)) != 0) {
		if (clen == (size_t)-1) {
			putchar('?');
			s++;
			n++;
			memset(&mbs, 0, sizeof(mbs));
			continue;
		}
		if (clen == (size_t)-2) {
			putchar('?');
			n++;
			break;
		}
		if (!iswprint(wc)) {
			putchar('?');
			s += clen;
			n++;
			continue;
		}
		for (i = 0; i < (int)clen; i++)
			putchar((unsigned char)s[i]);
		s += clen;
		n += wcwidth(wc);
	}
	return (n);*/
}

/*
 * The fts system makes it difficult to replace fts_name with a different-
 * sized string, so we just calculate the real length here and do the
 * conversion in prn_octal()
 *
 * XXX when using f_octal_escape (-b) rather than f_octal (-B), the
 * length computed by len_octal may be too big. I just can't be buggered
 * to fix this as an efficient fix would involve a lookup table. Same goes
 * for the rather inelegant code in prn_octal.
 *
 *                                              DES 1998/04/23
 */

size_t
len_octal(const char *s, int len)
{
	mbstate_t mbs;
	wchar_t wc;
	size_t clen, r;

	memset(&mbs, 0, sizeof(mbs));
	r = 0;
	while (len != 0 && (clen = mbrtowc(&wc, s, len, &mbs)) != 0) {
		if (clen == (size_t)-1) {
			r += 4;
			s++;
			len--;
			memset(&mbs, 0, sizeof(mbs));
			continue;
		}
		if (clen == (size_t)-2) {
			r += 4 * len;
			break;
		}
		if (iswprint(wc))
			r++;
		else
			r += 4 * clen;
		s += clen;
	}
	return (r);
}

int
prn_octal(const char *s)
{
	static const char esc[] = "\\\\\"\"\aa\bb\ff\nn\rr\tt\vv";
	const char *p;
	mbstate_t mbs;
	wchar_t wc;
	size_t clen;
	unsigned char ch;
	int goodchar, i, len, prtlen;

	memset(&mbs, 0, sizeof(mbs));
	len = 0;
	while ((clen = mbrtowc(&wc, s, MB_LEN_MAX, &mbs)) != 0) {
		goodchar = clen != (size_t)-1 && clen != (size_t)-2;
		if (goodchar && iswprint(wc) && wc != L'\"' && wc != L'\\') {
			for (i = 0; i < (int)clen; i++)
				putchar((unsigned char)s[i]);
			len += wcwidth(wc);
		}
		else if (goodchar && f_octal_escape && wc >= 0 &&
			wc <= (wchar_t)UCHAR_MAX &&
			(p = strchr(esc, (char)wc)) != NULL) {
			putchar('\\');
			putchar(p[1]);
			len += 2;
		}
		else {
			if (goodchar)
				prtlen = clen;
			else if (clen == (size_t)-1)
				prtlen = 1;
			else
				prtlen = strlen(s);
			for (i = 0; i < prtlen; i++) {
				ch = (unsigned char)s[i];
				putchar('\\');
				putchar('0' + (ch >> 6));
				putchar('0' + ((ch >> 3) & 7));
				putchar('0' + (ch & 7));
				len += 4;
			}
		}
		if (clen == (size_t)-2)
			break;
		if (clen == (size_t)-1) {
			memset(&mbs, 0, sizeof(mbs));
			s++;
		}
		else
			s += clen;
	}
	return (len);
}

void
usage(void)
{
	(void)fprintf(stderr,
#ifdef COLORLS
		"usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]"
#else
		"usage: ls [-ABCFHLOPRSTUWabcdefghiklmnopqrstuwx1]"
#endif
		" [file ...]\n");
	exit(1);
}


/*	$NetBSD: humanize_number.c,v 1.8 2004/07/27 01:56:24 enami Exp $	*/

/*
 * Copyright (c) 1997, 1998, 1999, 2002 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,
 * NASA Ames Research Center, by Luke Mewburn and by Tomas Svensson.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the NetBSD
 *      Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#include <sys/types.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <fts.h>

int
humanize_number(char *buf, size_t len, int64_t bytes,
	const char *suffix, int scale, int flags)
{
	const char *prefixes, *sep;
	int	b, i, r, maxscale, s1, s2, sign;
	int64_t	divisor, max;
	size_t	baselen;

	assert(buf != NULL);
	assert(suffix != NULL);
	assert(scale >= 0);

	if (flags & HN_DIVISOR_1000) {
		/* SI for decimal multiplies */
		divisor = 1000;
		if (flags & HN_B)
			prefixes = "B\0k\0M\0G\0T\0P\0E";
		else
			prefixes = "\0\0k\0M\0G\0T\0P\0E";
	}
	else {
		/*
		 * binary multiplies
		 * XXX IEC 60027-2 recommends Ki, Mi, Gi...
		 */
		divisor = 1024;
		if (flags & HN_B)
			prefixes = "B\0K\0M\0G\0T\0P\0E";
		else
			prefixes = "\0\0K\0M\0G\0T\0P\0E";
	}

#define	SCALE2PREFIX(scale)	(&prefixes[(scale) << 1])
	maxscale = 7;

	if (scale >= maxscale &&
		(scale & (HN_AUTOSCALE | HN_GETSCALE)) == 0)
		return (-1);

	if (buf == NULL || suffix == NULL)
		return (-1);

	if (len > 0)
		buf[0] = '\0';
	if (bytes < 0) {
		sign = -1;
		bytes *= -100;
		baselen = 3;		/* sign, digit, prefix */
	}
	else {
		sign = 1;
		bytes *= 100;
		baselen = 2;		/* digit, prefix */
	}
	if (flags & HN_NOSPACE)
		sep = "";
	else {
		sep = " ";
		baselen++;
	}
	baselen += strlen(suffix);

	/* Check if enough room for `x y' + suffix + `\0' */
	if (len < baselen + 1)
		return (-1);

	if (scale & (HN_AUTOSCALE | HN_GETSCALE)) {
		/* See if there is additional columns can be used. */
		for (max = 100, i = len - baselen; i-- > 0;)
			max *= 10;

		for (i = 0; bytes >= max && i < maxscale; i++)
			bytes /= divisor;

		if (scale & HN_GETSCALE)
			return (i);
	}
	else
		for (i = 0; i < scale && i < maxscale; i++)
			bytes /= divisor;

	/* If a value <= 9.9 after rounding and ... */
	if (bytes < 995 && i > 0 && flags & HN_DECIMAL) {
		/* baselen + \0 + .N */
		if (len < baselen + 1 + 2)
			return (-1);
		b = ((int)bytes + 5) / 10;
		s1 = b / 10;
		s2 = b % 10;
		r = snprintf(buf, len, "%d%s%d%s%s%s",
			sign * s1, localeconv()->decimal_point, s2,
			sep, SCALE2PREFIX(i), suffix);
	}
	else
		r = snprintf(buf, len, "%lld%s%s%s",
			/* LONGLONG */
		(long long)(sign * ((bytes + 50) / 100)),
			sep, SCALE2PREFIX(i), suffix);

	return (r);
}

/*
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

 //dztall
#define TARGET_OS_EMBEDDED 1
#undef __APPLE__

#if 0
#ifndef lint
static char sccsid[] = "@(#)print.c	8.4 (Berkeley) 4/17/94";
#endif /* not lint */
#endif
#include <sys/cdefs.h>
__RCSID("$FreeBSD: src/bin/ls/print.c,v 1.57 2002/08/29 14:29:09 keramida Exp $");

#include <sys/param.h>
#include <sys/stat.h>
#ifdef __APPLE__
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#if !TARGET_OS_EMBEDDED
#include <membership.h>
#include <membershipPriv.h>
#endif
#include <uuid/uuid.h>
#endif

#include <err.h>
#include <errno.h>
#include <fts.h>
#include <math.h>
#include <langinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#ifdef COLORLS
#include <ctype.h>
//#include <termcap.h>
#include <signal.h>
#endif
#include <stdint.h>		/* intmax_t */
#ifdef __APPLE__
#include <get_compat.h>
#else 
#define COMPAT_MODE(a,b) (1)
#endif /* __APPLE__ */

//dztall
#include <ccr.h>


//dztall
#ifdef _OS_ANDROID_
#define MINORBITS        20
#define MINORMASK        ((1U << MINORBITS) - 1)
#define major(dev)        ((unsigned int) ((dev) >> MINORBITS))
#define minor(dev)        ((unsigned int) ((dev) & MINORMASK))
#define mkdev(ma,mi)      (((ma) << MINORBITS) | (mi))
#endif

static int	printaname(FTSENT *, u_long, u_long);
static void	printlink(FTSENT *);
static void	printtime(time_t);
static int	printtype(u_int);
static void	printsize(size_t, off_t);
#ifdef COLORLS
static void	endcolor(int);
static int	colortype(mode_t);
#endif

#define	IS_NOPRINT(p)	((p)->fts_number == NO_PRINT)

#ifdef COLORLS
/* Most of these are taken from <sys/stat.h> */
typedef enum Colors {
	C_DIR,			/* directory */
	C_LNK,			/* symbolic link */
	C_SOCK,			/* socket */
	C_FIFO,			/* pipe */
	C_EXEC,			/* executable */
	C_BLK,			/* block special */
	C_CHR,			/* character special */
	C_SUID,			/* setuid executable */
	C_SGID,			/* setgid executable */
	C_WSDIR,		/* directory writeble to others, with sticky
				 * bit */
	C_WDIR,			/* directory writeble to others, without
				 * sticky bit */
	C_NUMCOLORS		/* just a place-holder */
} Colors;

static const char *defcolors = "exfxcxdxbxegedabagacad";

/* colors for file types */
static struct {
	int	num[2];
	int	bold;
} colors[C_NUMCOLORS];
#endif

void
printscol(DISPLAY *dp)
{
	FTSENT *p;

	if (COMPAT_MODE("bin/ls", "Unix2003")) {
		if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size))
			(void)printf("total %qu\n", (u_int64_t)howmany(dp->btotal, blocksize));
	}

	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		(void)printaname(p, dp->s_inode, dp->s_block);
		(void)putchar('\n');
	}
}

/*
 * print name in current style
 */
static int
printname(const char *name)
{
	if (f_octal || f_octal_escape)
		return prn_octal(name);
	else if (f_nonprint)
		return prn_printable(name);
	else
		return prn_normal(name);
}

//dztall
#ifdef __APPLE__
/*
 * print access control list
 */
static struct {
	acl_perm_t	perm;
	char		*name;
	int		flags;
#define ACL_PERM_DIR	(1<<0)
#define ACL_PERM_FILE	(1<<1)
} acl_perms[] = {
	{ACL_READ_DATA,		"read",		ACL_PERM_FILE},
	{ACL_LIST_DIRECTORY,	"list",		ACL_PERM_DIR},
	{ACL_WRITE_DATA,	"write",	ACL_PERM_FILE},
	{ACL_ADD_FILE,		"add_file",	ACL_PERM_DIR},
	{ACL_EXECUTE,		"execute",	ACL_PERM_FILE},
	{ACL_SEARCH,		"search",	ACL_PERM_DIR},
	{ACL_DELETE,		"delete",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_APPEND_DATA,	"append",	ACL_PERM_FILE},
	{ACL_ADD_SUBDIRECTORY,	"add_subdirectory", ACL_PERM_DIR},
	{ACL_DELETE_CHILD,	"delete_child",	ACL_PERM_DIR},
	{ACL_READ_ATTRIBUTES,	"readattr",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_ATTRIBUTES,	"writeattr",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_READ_EXTATTRIBUTES, "readextattr",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_EXTATTRIBUTES, "writeextattr", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_READ_SECURITY,	"readsecurity",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_WRITE_SECURITY,	"writesecurity", ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_CHANGE_OWNER,	"chown",	ACL_PERM_FILE | ACL_PERM_DIR},
	{0, NULL, 0}
};

static struct {
	acl_flag_t	flag;
	char		*name;
	int		flags;
} acl_flags[] = {
	{ACL_ENTRY_FILE_INHERIT, 	"file_inherit",		ACL_PERM_DIR},
	{ACL_ENTRY_DIRECTORY_INHERIT,	"directory_inherit",	ACL_PERM_DIR},
	{ACL_ENTRY_LIMIT_INHERIT,	"limit_inherit",	ACL_PERM_FILE | ACL_PERM_DIR},
	{ACL_ENTRY_ONLY_INHERIT,	"only_inherit",		ACL_PERM_DIR},
	{0, NULL, 0}
};

static void
printxattr(DISPLAY *dp, char *filename, ssize_t xattr)
{
	int flags = XATTR_NOFOLLOW;
	char *buf = malloc(xattr);

	if (NULL == buf)
		err(1, "malloc");
	if (listxattr(filename, buf, xattr, flags) > 0) {
		char *name;
		for (name = buf; name < buf + xattr; name += strlen(name) + 1) {
			ssize_t size = getxattr(filename, name, 0, 0, 0, flags);
			putchar('\t');
			printname(name);
			putchar('\t');
			printsize(dp->s_size, size);
			putchar('\n');
		}
	}
	free(buf);
}

static char *
uuid_to_name(uuid_t *uu)
{
#if TARGET_OS_EMBEDDED
	return strdup("<UNKNOWN>");
#else  /* !TARGET_OS_EMBEDDED */
	int is_gid = -1;
	struct group *tgrp = NULL;
	struct passwd *tpass = NULL;
	char *name = NULL;
	uid_t id;


#define MAXNAMETAG (MAXLOGNAME + 6) /* + strlen("group:") */
	name = (char *)malloc(MAXNAMETAG);

	if (NULL == name)
		err(1, "malloc");

	if (!f_numericonly) {
		if (0 != mbr_uuid_to_id(*uu, &id, &is_gid))
			goto errout;
	}

	switch (is_gid) {
	case ID_TYPE_UID:
		tpass = getpwuid(id);
		if (!tpass) {
			goto errout;
		}
		snprintf(name, MAXNAMETAG, "%s:%s", "user", tpass->pw_name);
		break;
	case ID_TYPE_GID:
		tgrp = getgrgid((gid_t)id);
		if (!tgrp) {
			goto errout;
		}
		snprintf(name, MAXNAMETAG, "%s:%s", "group", tgrp->gr_name);
		break;
	default:
		goto errout;
	}
	return name;
errout:
	if (0 != mbr_uuid_to_string(*uu, name)) {
		fprintf(stderr, "Unable to translate qualifier on ACL\n");
		strcpy(name, "<UNKNOWN>");
	}
	return name;
#endif	/* !TARGET_OS_EMBEDDED */
}

static void
printacl(acl_t acl, int isdir)
{
	acl_entry_t	entry = NULL;
	int		index;
	uuid_t		*applicable;
	char		*name = NULL;
	acl_tag_t	tag;
	acl_flagset_t	flags;
	acl_permset_t	perms;
	char		*type;
	int		i, first;


	for (index = 0;
		acl_get_entry(acl, entry == NULL ? ACL_FIRST_ENTRY : ACL_NEXT_ENTRY, &entry) == 0;
		index++) {
		if ((applicable = (uuid_t *)acl_get_qualifier(entry)) == NULL)
			continue;
		if (acl_get_tag_type(entry, &tag) != 0)
			continue;
		if (acl_get_flagset_np(entry, &flags) != 0)
			continue;
		if (acl_get_permset(entry, &perms) != 0)
			continue;
		name = uuid_to_name(applicable);
		acl_free(applicable);

		switch (tag) {
		case ACL_EXTENDED_ALLOW:
			type = "allow";
			break;
		case ACL_EXTENDED_DENY:
			type = "deny";
			break;
		default:
			type = "unknown";
		}

		(void)printf(" %d: %s%s %s ",
			index,
			name,
			acl_get_flag_np(flags, ACL_ENTRY_INHERITED) ? " inherited" : "",
			type);

		if (name)
			free(name);

		for (i = 0, first = 0; acl_perms[i].name != NULL; i++) {
			if (acl_get_perm_np(perms, acl_perms[i].perm) == 0)
				continue;
			if (!(acl_perms[i].flags & (isdir ? ACL_PERM_DIR : ACL_PERM_FILE)))
				continue;
			(void)printf("%s%s", first++ ? "," : "", acl_perms[i].name);
		}
		for (i = 0; acl_flags[i].name != NULL; i++) {
			if (acl_get_flag_np(flags, acl_flags[i].flag) == 0)
				continue;
			if (!(acl_flags[i].flags & (isdir ? ACL_PERM_DIR : ACL_PERM_FILE)))
				continue;
			(void)printf("%s%s", first++ ? "," : "", acl_flags[i].name);
		}

		(void)putchar('\n');
	}

}
#endif

void
printlong(DISPLAY *dp)
{
	struct stat *sp;
	FTSENT *p;
	NAMES *np;
	char buf[20];
#ifdef __APPLE__
	acl_t acl = NULL;
	acl_entry_t dummy;
	char full_path[MAXPATHLEN];
	char *filename;
	ssize_t xattr = 0;
	char str[2];
#endif
#ifdef COLORLS
	int color_printed = 0;
#endif

	if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size))
		(void)printf("total %qu\n", (u_int64_t)howmany(dp->btotal, blocksize));

	for (p = dp->list; p; p = p->fts_link) {
		if (IS_NOPRINT(p))
			continue;
		sp = p->fts_statp;
		if (f_inode)
#if _DARWIN_FEATURE_64_BIT_INODE
		(void)printf("%*llu ", dp->s_inode, (u_quad_t)sp->st_ino);
#else
			(void)printf("%*lu ", dp->s_inode, (u_long)sp->st_ino);
#endif
		if (f_size)
			(void)printf("%*qu ",
				dp->s_block, (u_int64_t)howmany(sp->st_blocks, blocksize));
		strmode(sp->st_mode, buf);
		np = p->fts_pointer;
#ifdef __APPLE__
		buf[10] = '\0';	/* make +/@ abut the mode */
		filename = p->fts_name;
		if (p->fts_level != FTS_ROOTLEVEL)
		{
			snprintf(full_path, sizeof full_path, "%s/%s",
				p->fts_parent->fts_accpath, p->fts_name);
			filename = full_path;
		}
		/* symlinks can not have ACLs */
		acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
		if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
			acl_free(acl);
			acl = NULL;
		}
		xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
		if (xattr < 0)
			xattr = 0;
		str[1] = '\0';
		if (xattr > 0)
			str[0] = '@';
		else if (acl != NULL)
			str[0] = '+';
		else
			str[0] = ' ';
#endif /* __APPLE__ */
		if (f_group && f_owner) {	/* means print neither */
#ifdef __APPLE__
			(void)printf("%s%s %*u   ", buf, str, dp->s_nlink,
				sp->st_nlink);
#else  /* ! __APPLE__ */
			(void)printf("%s %*u   ", buf, dp->s_nlink,
				sp->st_nlink);
#endif /* __APPLE__ */
		}
		else if (f_group) {
#ifdef __APPLE__
			(void)printf("%s%s %*u %-*s  ", buf, str, dp->s_nlink,
				sp->st_nlink, dp->s_group, np->group);
#else  /* ! __APPLE__ */
			(void)printf("%s %*u %-*s  ", buf, dp->s_nlink,
				sp->st_nlink, dp->s_group, np->group);
#endif /* __APPLE__ */
		}
		else if (f_owner) {
#ifdef __APPLE__
			(void)printf("%s%s %*u %-*s  ", buf, str, dp->s_nlink,
				sp->st_nlink, dp->s_user, np->user);
#else  /* ! __APPLE__ */
			(void)printf("%s %*u %-*s  ", buf, dp->s_nlink,
				sp->st_nlink, dp->s_user, np->user);
#endif /* __APPLE__ */
		}
		else {
#ifdef __APPLE__
			(void)printf("%s%s %*u %-*s  %-*s  ", buf, str, dp->s_nlink,
				sp->st_nlink, dp->s_user, np->user, dp->s_group,
				np->group);
#else  /* ! __APPLE__ */
			(void)printf("%s %*u %-*s  %-*s  ", buf, dp->s_nlink,
				sp->st_nlink, dp->s_user, np->user, dp->s_group,
				np->group);
#endif /* ! __APPLE__ */
		}
		if (f_flags)
			(void)printf("%-*s ", dp->s_flags, np->flags);
		if (S_ISCHR(sp->st_mode) || S_ISBLK(sp->st_mode))
			if (minor(sp->st_rdev) > 255 || minor(sp->st_rdev) < 0)
				(void)printf("%3d, 0x%08x ",
					major(sp->st_rdev),
					(u_int)minor(sp->st_rdev));
			else
				(void)printf("%3d, %3d ",
					major(sp->st_rdev), minor(sp->st_rdev));
		else if (dp->bcfile)
			(void)printf("%*s%*qu ",
				8 - dp->s_size, "", dp->s_size, (u_int64_t)sp->st_size);
		else
			printsize(dp->s_size, sp->st_size);
		if (f_accesstime)
			printtime(sp->st_atime);
		else if (f_statustime)
			printtime(sp->st_ctime);
		else if (f_birthtime)
			printtime(sp->st_birthtime);
		else
			printtime(sp->st_mtime);
#ifdef COLORLS
		if (f_color)
			color_printed = colortype(sp->st_mode);
#endif
		(void)printname(p->fts_name);
#ifdef COLORLS
		if (f_color && color_printed)
			endcolor(0);
#endif
		if (f_type)
			(void)printtype(sp->st_mode);
		if (S_ISLNK(sp->st_mode))
			printlink(p);
		(void)putchar('\n');
#ifdef __APPLE__
		if (f_xattr && xattr) {
			printxattr(dp, filename, xattr);
		}
		if (acl != NULL) {
			if (f_acl)
				printacl(acl, S_ISDIR(sp->st_mode));
			acl_free(acl);
			acl = NULL;
		}
#endif /* __APPLE__ */
	}
}

void
printstream(DISPLAY *dp)
{
	FTSENT *p;
	extern int termwidth;
	int chcnt;

	for (p = dp->list, chcnt = 0; p; p = p->fts_link) {
		if (p->fts_number == NO_PRINT)
			continue;
		if (strlen(p->fts_name) + chcnt +
			(p->fts_link ? 2 : 0) >= (unsigned)termwidth) {
			putchar('\n');
			chcnt = 0;
		}
		chcnt += printaname(p, dp->s_inode, dp->s_block);
		if (p->fts_link) {
			printf(", ");
			chcnt += 2;
		}
	}
	if (chcnt)
		putchar('\n');
}

void
printcol(DISPLAY *dp)
{
	extern int termwidth;
	static FTSENT **array;
	static int lastentries = -1;
	FTSENT *p;
	int base;
	int chcnt;
	int cnt;
	int col;
	int colwidth;
	int endcol;
	int num;
	int numcols;
	int numrows;
	int row;
	int tabwidth;

	if (f_notabs)
		tabwidth = 1;
	else
		tabwidth = ccrGetTextOutputTabSize();//8;

	/*
	 * Have to do random access in the linked list -- build a table
	 * of pointers.
	 */
	if (dp->entries > lastentries) {
		lastentries = dp->entries;
		if ((array =
			realloc(array, dp->entries * sizeof(FTSENT *))) == NULL) {
			warn(NULL);
			printscol(dp);
		}
	}
	for (p = dp->list, num = 0; p; p = p->fts_link)
		if (p->fts_number != NO_PRINT)
			array[num++] = p;

	colwidth = dp->maxlen;
	if (f_inode)
		colwidth += dp->s_inode + 1;
	if (f_size)
		colwidth += dp->s_block + 1;
	if (f_type)
		colwidth += 1;

	colwidth = (colwidth + tabwidth) & ~(tabwidth - 1);
	if (termwidth < 2 * colwidth) {
		printscol(dp);
		return;
	}
	numcols = termwidth / colwidth;
	numrows = num / numcols;
	if (num % numcols)
		++numrows;

	if (dp->list->fts_level != FTS_ROOTLEVEL && (f_longform || f_size))
		(void)printf("total %qu\n", (u_int64_t)howmany(dp->btotal, blocksize));

	base = 0;
	for (row = 0; row < numrows; ++row) {
		endcol = colwidth;
		if (!f_sortacross)
			base = row;
		for (col = 0, chcnt = 0; col < numcols; ++col) {
			chcnt += printaname(array[base], dp->s_inode,
				dp->s_block);
			if (f_sortacross)
				base++;
			else
				base += numrows;
			if (base >= num)
				break;
			while ((cnt = ((chcnt + tabwidth) & ~(tabwidth - 1)))
				<= endcol) {
				if (f_sortacross && col + 1 >= numcols)
					break;
				(void)putchar(f_notabs ? ' ' : '\t');
				chcnt = cnt;
			}
			endcol += colwidth;
		}
		(void)putchar('\n');
	}
}

/*
 * print [inode] [size] name
 * return # of characters printed, no trailing characters.
 */
static int
printaname(FTSENT *p, u_long inodefield, u_long sizefield)
{
	struct stat *sp;
	int chcnt;
#ifdef COLORLS
	int color_printed = 0;
#endif

	sp = p->fts_statp;
	chcnt = 0;
	if (f_inode)
#if _DARWIN_FEATURE_64_BIT_INODE
		chcnt += printf("%*llu ", (int)inodefield, (u_quad_t)sp->st_ino);
#else
		chcnt += printf("%*lu ", (int)inodefield, (u_long)sp->st_ino);
#endif
	if (f_size)
		chcnt += printf("%*qu ",
		(int)sizefield, (u_int64_t)howmany(sp->st_blocks, blocksize));
#ifdef COLORLS
	if (f_color)
		color_printed = colortype(sp->st_mode);
#endif
	chcnt += printname(p->fts_name);
#ifdef COLORLS
	if (f_color && color_printed)
		endcolor(0);
#endif
	if (f_type)
		chcnt += printtype(sp->st_mode);
	return (chcnt);
}

static void
printtime(time_t ftime)
{
	char longstring[80];
	static time_t now;
	const char *format;
	static int d_first = -1;

	if (d_first < 0)
	{
		//dztall
#ifdef D_MD_ORDER
		d_first = (*nl_langinfo(D_MD_ORDER) == 'd');
#else
		d_first = 0;
#endif
	}
	if (now == 0)
		now = time(NULL);

#define	SIXMONTHS	((365 / 2) * 86400)
	if (f_sectime)
		/* mmm dd hh:mm:ss yyyy || dd mmm hh:mm:ss yyyy */
		format = d_first ? "%e %b %T %Y " : "%b %e %T %Y ";
	else if (COMPAT_MODE("bin/ls", "Unix2003")) {
		if (ftime + SIXMONTHS > now && ftime <= now)
			/* mmm dd hh:mm || dd mmm hh:mm */
			format = d_first ? "%e %b %R " : "%b %e %R ";
		else
			/* mmm dd  yyyy || dd mmm  yyyy */
			format = d_first ? "%e %b  %Y " : "%b %e  %Y ";
	}
	else if (ftime + SIXMONTHS > now && ftime < now + SIXMONTHS)
		/* mmm dd hh:mm || dd mmm hh:mm */
		format = d_first ? "%e %b %R " : "%b %e %R ";
	else
		/* mmm dd  yyyy || dd mmm  yyyy */
		format = d_first ? "%e %b  %Y " : "%b %e  %Y ";
	strftime(longstring, sizeof(longstring), format, localtime(&ftime));
	fputs(longstring, stdout);
}

static int
printtype(u_int mode)
{

	if (f_slash) {
		if ((mode & S_IFMT) == S_IFDIR) {
			(void)putchar('/');
			return (1);
		}
		return (0);
	}

	switch (mode & S_IFMT) {
	case S_IFDIR:
		(void)putchar('/');
		return (1);
	case S_IFIFO:
		(void)putchar('|');
		return (1);
	case S_IFLNK:
		(void)putchar('@');
		return (1);
	case S_IFSOCK:
		(void)putchar('=');
		return (1);
		//dztall
#ifdef __APPLE__
	case S_IFWHT:
		(void)putchar('%');
		return (1);
#endif
	default:
		break;
	}
	if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
		(void)putchar('*');
		return (1);
	}
	return (0);
}

#ifdef COLORLS
static int
putch(int c)
{
	(void)putchar(c);
	return 0;
}

static int
writech(int c)
{
	char tmp = c;

	(void)write(STDOUT_FILENO, &tmp, 1);
	return 0;
}

static void
printcolor(Colors c)
{
	/*
	printf("called %s\n" __func__);
	printf("colors[c].bold = %d\n", colors[c].bold);
	printf("colors[c].num[0] = %d\n", colors[c].num[0]);
	printf("colors[c].num[1] = %d\n", colors[c].num[1]);
	*/
	char *ansiseq;

	
	if (colors[c].bold) {
		
	}

	if (colors[c].num[0] != -1) {
		printf("%c[0;%dm", 0x1B, colors[c].num[0] + 30);
	}
	if (colors[c].num[1] != -1) {
		printf("%c[0;%d;%dm", 0x1B, colors[c].num[0] + 30, colors[c].num[1] + 40);
	}
}

static void
endcolor(int sig)
{
	printf("%c[0m", 0x1B);
	//printf("\ncalled %s\n" __func__);
	//tputs(ansi_coloff, 1, sig ? writech : putch);
	//tputs(attrs_off, 1, sig ? writech : putch);
}

static int
colortype(mode_t mode)
{
	//printf("\ncalled %s\n" __func__);
	switch (mode & S_IFMT) {
	case S_IFDIR:
		if (mode & S_IWOTH)
			if (mode & S_ISTXT)
				printcolor(C_WSDIR);
			else
				printcolor(C_WDIR);
		else
			printcolor(C_DIR);
		return (1);
	case S_IFLNK:
		printcolor(C_LNK);
		return (1);
	case S_IFSOCK:
		printcolor(C_SOCK);
		return (1);
	case S_IFIFO:
		printcolor(C_FIFO);
		return (1);
	case S_IFBLK:
		printcolor(C_BLK);
		return (1);
	case S_IFCHR:
		printcolor(C_CHR);
		return (1);
	}
	if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
		if (mode & S_ISUID)
			printcolor(C_SUID);
		else if (mode & S_ISGID)
			printcolor(C_SGID);
		else
			printcolor(C_EXEC);
		return (1);
	}
	return (0);
}

void
parsecolors(const char *cs)
{
	//printf("\ncalled %s\n" __func__);
	int i;
	int j;
	int len;
	char c[2];
	short legacy_warn = 0;

	if (cs == NULL)
		cs = "";	/* LSCOLORS not set */
	len = strlen(cs);
	for (i = 0; i < C_NUMCOLORS; i++) {
		colors[i].bold = 0;

		if (len <= 2 * i) {
			c[0] = defcolors[2 * i];
			c[1] = defcolors[2 * i + 1];
		}
		else {
			c[0] = cs[2 * i];
			c[1] = cs[2 * i + 1];
		}
		for (j = 0; j < 2; j++) {
			/* Legacy colours used 0-7 */
			if (c[j] >= '0' && c[j] <= '7') {
				colors[i].num[j] = c[j] - '0';
				if (!legacy_warn) {
					fprintf(stderr,
						"warn: LSCOLORS should use "
						"characters a-h instead of 0-9 ("
						"see the manual page)\n");
				}
				legacy_warn = 1;
			}
			else if (c[j] >= 'a' && c[j] <= 'h')
				colors[i].num[j] = c[j] - 'a';
			else if (c[j] >= 'A' && c[j] <= 'H') {
				colors[i].num[j] = c[j] - 'A';
				colors[i].bold = 1;
			}
			else if (tolower((unsigned char)c[j] == 'x'))
				colors[i].num[j] = -1;
			else {
				fprintf(stderr,
					"error: invalid character '%c' in LSCOLORS"
					" env var\n", c[j]);
				colors[i].num[j] = -1;
			}
		}
	}
}

void
colorquit(int sig)
{
	printf("\ncalled %s\n" __func__);
	endcolor(sig);

	(void)signal(sig, SIG_DFL);
	(void)kill(getpid(), sig);
}

#endif /* COLORLS */

static void
printlink(FTSENT *p)
{
	int lnklen;
	char name[MAXPATHLEN + 1];
	char path[MAXPATHLEN + 1];

	if (p->fts_level == FTS_ROOTLEVEL)
		(void)snprintf(name, sizeof(name), "%s", p->fts_name);
	else
		(void)snprintf(name, sizeof(name),
			"%s/%s", p->fts_parent->fts_accpath, p->fts_name);
	if ((lnklen = readlink(name, path, sizeof(path) - 1)) == -1) {
		(void)fprintf(stderr, "\nls: %s: %s\n", name, strerror(errno));
		return;
	}
	path[lnklen] = '\0';
	(void)printf(" -> ");
	/*
	#ifdef COLORLS
		if (f_color)
			color_printed = colortype(sp->st_mode);
#endif
		(void)printname(p->fts_name);
#ifdef COLORLS
		if (f_color && color_printed)
			endcolor(0);
#endif
	*/
	struct stat *sp;
#ifdef COLORLS
	int color_printed = 0;
#endif
	sp = p->fts_statp;
#ifdef COLORLS
	if (f_color)
		color_printed = colortype(sp->st_mode);
#endif
	(void)printname(path);
#ifdef COLORLS
	if (f_color && color_printed)
		endcolor(0);
#endif
}

static void
printsize(size_t width, off_t bytes)
{

	if (f_humanval) {
		char buf[5];

		humanize_number(buf, sizeof(buf), (int64_t)bytes, "",
			HN_AUTOSCALE, HN_B | HN_NOSPACE | HN_DECIMAL);
		(void)printf("%5s ", buf);
	}
	else
		(void)printf("%*jd ", (u_int)width, (intmax_t)bytes);
}

/*
 * Copyright (c) 1989, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef lint
static const char copyright[] =
"@(#) Copyright (c) 1989, 1993, 1994\n\
	The Regents of the University of California.  All rights reserved.\n";
#endif /* not lint */

#if 0
#ifndef lint
static char sccsid[] = "@(#)ls.c	8.5 (Berkeley) 4/2/94";
#endif /* not lint */
#endif
#include <sys/cdefs.h>
__RCSID("$FreeBSD: src/bin/ls/ls.c,v 1.66 2002/09/21 01:28:36 wollman Exp $");

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <fts.h>
#include <grp.h>
#include <limits.h>
#include <locale.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef COLORLS
//#include <termcap.h>
#include <signal.h>
#endif
//dztall
//#ifdef __APPLE__
#if 0
#include <get_compat.h>
#else
#define COMPAT_MODE(a,b) (1)
#endif /* __APPLE__ */
/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Michael Fischbein.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)ls.h	8.1 (Berkeley) 5/31/93
 * $FreeBSD: src/bin/ls/ls.h,v 1.18 2002/05/19 02:51:36 tjr Exp $
 */


/*
 * Upward approximation of the maximum number of characters needed to
 * represent a value of integral type t as a string, excluding the
 * NUL terminator, with provision for a sign.
 */
#define	STRBUF_SIZEOF(t)	(1 + CHAR_BIT * sizeof(t) / 3 + 1)

static void	 display(FTSENT *, FTSENT *);
static u_quad_t	 makenines(u_quad_t);
static int	 mastercmp(const FTSENT **, const FTSENT **);
static void	 traverse(int, char **, int);

static void(*printfcn)(DISPLAY *);
static int(*sortfcn)(const FTSENT *, const FTSENT *);

long blocksize;			/* block size units */
int termwidth = 80;		/* default terminal width */

/* flags */
int f_accesstime;	/* use time of last access */
int f_birthtime;		/* use time of file birth */
int f_flags;		/* show flags associated with a file */
int f_humanval;		/* show human-readable file sizes */
int f_inode;		/* print inode */
static int f_kblocks;		/* print size in kilobytes */
static int f_listdir;		/* list actual directory, not contents */
static int f_listdot;		/* list files beginning with . */
int f_longform;		/* long listing format */
int f_nonprint;		/* show unprintables as ? */
static int f_nosort;		/* don't sort output */
int f_notabs;		/* don't use tab-separated multi-col output */
int f_numericonly;	/* don't convert uid/gid to name */
int f_octal;		/* show unprintables as \xxx */
int f_octal_escape;	/* like f_octal but use C escapes if possible */
static int f_recursive;		/* ls subdirectories also */
static int f_reversesort;	/* reverse whatever sort is used */
int f_sectime;		/* print the real time for all files */
static int f_singlecol;		/* use single column output */
int f_size;		/* list size in short listing */
int f_slash;		/* similar to f_type, but only for dirs */
int f_sortacross;	/* sort across rows, not down columns */
int f_statustime;	/* use time of last mode change */
int f_stream;		/* stream the output, separate with commas */
static int f_timesort;		/* sort by time vice name */
static int f_sizesort;		/* sort by size */
int f_type;		/* add type character for non-regular files */
static int f_whiteout;		/* show whiteout entries */
int f_acl;		/* show ACLs in long listing */
int f_xattr;		/* show extended attributes in long listing */
int f_group;		/* show group */
int f_owner;		/* show owner */
#ifdef COLORLS
int f_color;		/* add type in color for non-regular files */

char *ansi_bgcol;		/* ANSI sequence to set background colour */
char *ansi_fgcol;		/* ANSI sequence to set foreground colour */
char *ansi_coloff;		/* ANSI sequence to reset colours */
char *attrs_off;		/* ANSI sequence to turn off attributes */
char *enter_bold;		/* ANSI sequence to set color to bold mode */
#endif

static int rval;

int     opterr = 1,             /* if error message should be printed */
optind = 1,             /* index into parent argv vector */
optopt,                 /* character checked for validity */
optreset;               /* reset getopt */
char    *optarg;                /* argument associated with option */

#define BADCH   (int)'?'
#define BADARG  (int)':'
#define EMSG    ""

/*
* getopt --
*      Parse argc/argv argument vector.
*/
int
getopt(int nargc, char * const nargv[], const char *ostr)
{
	static char *place = EMSG;              /* option letter processing */
	const char *oli;                        /* option letter list index */

	if (optreset || !*place) {              /* update scanning pointer */
		optreset = 0;
		if (optind >= nargc || *(place = nargv[optind]) != '-') {
			place = EMSG;
			return (-1);
		}
		if (place[1] && *++place == '-') {      /* found "--" */
			++optind;
			place = EMSG;
			return (-1);
		}
	}                                       /* option letter okay? */
	if ((optopt = (int)*place++) == (int)':' ||
		!(oli = strchr(ostr, optopt))) {
		/*
		* if the user didn't specify '-' as an option,
		* assume it means -1.
		*/
		if (optopt == (int)'-')
			return (-1);
		if (!*place)
			++optind;
		if (opterr && *ostr != ':')
			(void)printf("illegal option -- %c\n", optopt);
		return (BADCH);
	}
	if (*++oli != ':') {                    /* don't need argument */
		optarg = NULL;
		if (!*place)
			++optind;
	}
	else {                                  /* need an argument */
		if (*place)                     /* no white space */
			optarg = place;
		else if (nargc <= ++optind) {   /* no arg */
			place = EMSG;
			if (*ostr == ':')
				return (BADARG);
			if (opterr)
				(void)printf("option requires an argument -- %c\n", optopt);
			return (BADCH);
		}
		else                            /* white space */
			optarg = nargv[optind];
		place = EMSG;
		++optind;
	}
	return (optopt);                        /* dump back option letter */
}

int
main(int argc, char *argv[])
{
	static char dot[] = ".", *dotav[] = { dot, NULL };
	struct winsize win;
	int ch, fts_options, notused;
	char *p;
#ifdef COLORLS
	char termcapbuf[1024];	/* termcap definition buffer */
	char tcapbuf[512];	/* capability buffer */
	char *bp = tcapbuf;
#endif

	if (argc < 1)
		usage();

	//dztall
//(void)setlocale(LC_ALL, "");

/* Terminal defaults to -Cq, non-terminal defaults to -1. */
	if (isatty(STDOUT_FILENO)) {
		termwidth = 80;
		if ((p = getenv("COLUMNS")) != NULL && *p != '\0')
			termwidth = atoi(p);
		else if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) != -1 &&
			win.ws_col > 0)
			termwidth = win.ws_col;
		f_nonprint = 1;
	}
	else {
		f_singlecol = 1;
		/* retrieve environment variable, in case of explicit -C */
		p = getenv("COLUMNS");
		if (p)
			termwidth = atoi(p);
	}

	/* Root is -A automatically. */
	if (!getuid())
		f_listdot = 1;

	fts_options = FTS_PHYSICAL;
	while ((ch = getopt(argc, argv, "1@ABCFGHLOPRSTUWabcdefghiklmnopqrstuvwx"))
		!= -1) {
		switch (ch) {
			/*
			 * The -1, -C, -x and -l options all override each other so
			 * shell aliasing works right.
			 */
		case '1':
			f_singlecol = 1;
			f_longform = 0;
			f_stream = 0;
			break;
		case 'B':
			f_nonprint = 0;
			f_octal = 1;
			f_octal_escape = 0;
			break;
		case 'C':
			f_sortacross = f_longform = f_singlecol = 0;
			break;
		case 'l':
			f_longform = 1;
			f_singlecol = 0;
			f_stream = 0;
			break;
		case 'x':
			f_sortacross = 1;
			f_longform = 0;
			f_singlecol = 0;
			break;
			/* The -c and -u options override each other. */
		case 'c':
			f_statustime = 1;
			f_accesstime = f_birthtime = 0;
			break;
		case 'u':
			f_accesstime = 1;
			f_statustime = f_birthtime = 0;
			break;
		case 'U':
			f_birthtime = 1;
			f_statustime = f_accesstime = 0;
			break;
		case 'F':
			f_type = 1;
			f_slash = 0;
			break;
		case 'H':
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				fts_options &= ~FTS_LOGICAL;
				fts_options |= FTS_PHYSICAL;
				fts_options |= FTS_COMFOLLOWDIR;
			}
			else
				fts_options |= FTS_COMFOLLOW;
			break;
		case 'G':
			setenv("CLICOLOR", "", 1);
			break;
		case 'L':
			fts_options &= ~FTS_PHYSICAL;
			fts_options |= FTS_LOGICAL;
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				fts_options &= ~(FTS_COMFOLLOW | FTS_COMFOLLOWDIR);
			}
			break;
		case 'P':
			fts_options &= ~(FTS_COMFOLLOW | FTS_COMFOLLOWDIR);
			fts_options &= ~FTS_LOGICAL;
			fts_options |= FTS_PHYSICAL;
			break;
		case 'R':
			f_recursive = 1;
			break;
		case 'a':
			fts_options |= FTS_SEEDOT;
			/* FALLTHROUGH */
		case 'A':
			f_listdot = 1;
			break;
			/* The -d option turns off the -R option. */
		case 'd':
			f_listdir = 1;
			f_recursive = 0;
			break;
		case 'f':
			f_nosort = 1;
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				fts_options |= FTS_SEEDOT;
				f_listdot = 1;
			}
			break;
		case 'g':	/* Compatibility with Unix03 */
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				f_group = 1;
				f_longform = 1;
				f_singlecol = 0;
				f_stream = 0;
			}
			break;
		case 'h':
			f_humanval = 1;
			break;
		case 'i':
			f_inode = 1;
			break;
		case 'k':
			f_kblocks = 1;
			break;
		case 'm':
			f_stream = 1;
			f_singlecol = 0;
			f_longform = 0;
			break;
		case 'n':
			f_numericonly = 1;
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				f_longform = 1;
				f_singlecol = 0;
				f_stream = 0;
			}
			break;
		case 'o':
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				f_owner = 1;
				f_longform = 1;
				f_singlecol = 0;
				f_stream = 0;
			}
			else {
				f_flags = 1;
			}
			break;
		case 'p':
			f_slash = 1;
			f_type = 1;
			break;
		case 'q':
			f_nonprint = 1;
			f_octal = 0;
			f_octal_escape = 0;
			break;
		case 'r':
			f_reversesort = 1;
			break;
		case 'S':
			/* Darwin 1.4.1 compatibility */
			f_sizesort = 1;
			break;
		case 's':
			f_size = 1;
			break;
		case 'T':
			f_sectime = 1;
			break;
		case 't':
			f_timesort = 1;
			break;
		case 'W':
			f_whiteout = 1;
			break;
		case 'v':
			/* Darwin 1.4.1 compatibility */
			f_nonprint = 0;
			break;
		case 'b':
			f_nonprint = 0;
			f_octal = 0;
			f_octal_escape = 1;
			break;
		case 'w':
			f_nonprint = 0;
			f_octal = 0;
			f_octal_escape = 0;
			break;
		case 'e':
			f_acl = 1;
			break;
		case '@':
			f_xattr = 1;
			break;
		case 'O':
			f_flags = 1;
			break;
		default:
		case '?':
			usage();
		}
	}
	argc -= optind;
	argv += optind;

	/* Enabling of colours is conditional on the environment. */
	if (getenv("CLICOLOR") &&
		(isatty(STDOUT_FILENO) || getenv("CLICOLOR_FORCE")))
#ifdef COLORLS
		/*
		if (tgetent(termcapbuf, getenv("TERM")) == 1) {
			ansi_fgcol = tgetstr("AF", &bp);
			ansi_bgcol = tgetstr("AB", &bp);
			attrs_off = tgetstr("me", &bp);
			enter_bold = tgetstr("md", &bp);

			// To switch colours off use 'op' if
			// * available, otherwise use 'oc', or
			// * don't do colours at all. 
			ansi_coloff = tgetstr("op", &bp);
			if (!ansi_coloff)
				ansi_coloff = tgetstr("oc", &bp);
			if (ansi_fgcol && ansi_bgcol && ansi_coloff)
				f_color = 1;
		}
		*/
		f_color = 1;
#else
		(void)fprintf(stderr, "Color support not compiled in.\n");
#endif /*COLORLS*/

#ifdef COLORLS
	if (f_color) {
		/*
		 * We can't put tabs and color sequences together:
		 * column number will be incremented incorrectly
		 * for "stty oxtabs" mode.
		 */
		f_notabs = 1;
		(void)signal(SIGINT, colorquit);
		(void)signal(SIGQUIT, colorquit);
		parsecolors(getenv("LSCOLORS"));
	}
#endif

	/*
	 * If not -F, -i, -l, -s or -t options, don't require stat
	 * information, unless in color mode in which case we do
	 * need this to determine which colors to display.
	 */
	if (!f_inode && !f_longform && !f_size && !f_timesort && !f_type && !f_sizesort
#ifdef COLORLS
		&& !f_color
#endif
		)
		fts_options |= FTS_NOSTAT;

	/*
	 * If not -F, -d or -l options, follow any symbolic links listed on
	 * the command line.
	 */
	if (!f_longform && !f_listdir && !f_type && !f_inode)
		fts_options |= FTS_COMFOLLOW;

	/*
	 * If -W, show whiteout entries
	 */
#ifdef FTS_WHITEOUT
	if (f_whiteout)
		fts_options |= FTS_WHITEOUT;
#endif

	/* If -l or -s, figure out block size. */
	if (f_longform || f_size) {
		if (f_kblocks)
			blocksize = 2;
		else {
			(void)getbsize(&notused, &blocksize);
			blocksize /= 512;
		}
	}
	/* Select a sort function. */
	if (f_reversesort) {
		if (f_sizesort)
			sortfcn = revsizecmp;
		else if (!f_timesort)
			sortfcn = revnamecmp;
		else if (f_accesstime)
			sortfcn = revacccmp;
		else if (f_statustime)
			sortfcn = revstatcmp;
		else if (f_birthtime)
			sortfcn = revbirthcmp;
		else		/* Use modification time. */
			sortfcn = revmodcmp;
	}
	else {
		if (f_sizesort)
			sortfcn = sizecmp;
		else if (!f_timesort)
			sortfcn = namecmp;
		else if (f_accesstime)
			sortfcn = acccmp;
		else if (f_statustime)
			sortfcn = statcmp;
		else if (f_birthtime)
			sortfcn = birthcmp;
		else		/* Use modification time. */
			sortfcn = modcmp;
	}

	/* Select a print function. */
	if (f_singlecol)
		printfcn = printscol;
	else if (f_longform)
		printfcn = printlong;
	else if (f_stream)
		printfcn = printstream;
	else
		printfcn = printcol;

	if (argc)
		traverse(argc, argv, fts_options);
	else
		traverse(1, dotav, fts_options);
	exit(rval);
}

static int output;		/* If anything output. */

/*
 * Traverse() walks the logical directory structure specified by the argv list
 * in the order specified by the mastercmp() comparison function.  During the
 * traversal it passes linked lists of structures to display() which represent
 * a superset (may be exact set) of the files to be displayed.
 */
static void
traverse(int argc, char *argv[], int options)
{
	FTS *ftsp;
	FTSENT *p, *chp;
	int ch_options, error;

	if ((ftsp =
		fts_open(argv, options, f_nosort ? NULL : mastercmp)) == NULL)
		err(1, "fts_open");

	display(NULL, fts_children(ftsp, 0));
	if (f_listdir) {
		fts_close(ftsp);
		return;
	}

	/*
	 * If not recursing down this tree and don't need stat info, just get
	 * the names.
	 */
	ch_options = !f_recursive && options & FTS_NOSTAT ? FTS_NAMEONLY : 0;

	while ((p = fts_read(ftsp)) != NULL)
		switch (p->fts_info) {
		case FTS_DC:
			warnx("%s: directory causes a cycle", p->fts_name);
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				rval = 1;
			}
			break;
		case FTS_DNR:
		case FTS_ERR:
			warnx("%s: %s", p->fts_name, strerror(p->fts_errno));
			rval = 1;
			break;
		case FTS_D:
			if (p->fts_level != FTS_ROOTLEVEL &&
				p->fts_name[0] == '.' && !f_listdot)
				break;

			/*
			 * If already output something, put out a newline as
			 * a separator.  If multiple arguments, precede each
			 * directory with its name.
			 */
			if (output)
				(void)printf("\n%s:\n", p->fts_path);
			else if (argc > 1) {
				(void)printf("%s:\n", p->fts_path);
				output = 1;
			}
			chp = fts_children(ftsp, ch_options);
			if (COMPAT_MODE("bin/ls", "Unix2003") && ((options & FTS_LOGICAL) != 0)) {
				FTSENT *curr;
				for (curr = chp; curr; curr = curr->fts_link) {
					if (curr->fts_info == FTS_SLNONE)
						curr->fts_number = NO_PRINT;
				}
			}
			display(p, chp);

			if (!f_recursive && chp != NULL)
				(void)fts_set(ftsp, p, FTS_SKIP);
			break;
		case FTS_SLNONE:	/* Same as default unless Unix conformance */
			if (COMPAT_MODE("bin/ls", "Unix2003")) {
				if ((options & FTS_LOGICAL) != 0) {	/* -L was specified */
					warnx("%s: %s", p->fts_name, strerror(p->fts_errno ? : ENOENT));
					rval = 1;
				}
			}
			break;
		default:
			break;
		}
	error = errno;
	fts_close(ftsp);
	errno = error;

	if (errno)
		err(1, "fts_read");
}

/*
 * Display() takes a linked list of FTSENT structures and passes the list
 * along with any other necessary information to the print function.  P
 * points to the parent directory of the display list.
 */
static void
display(FTSENT *p, FTSENT *list)
{
	struct stat *sp;
	DISPLAY d;
	FTSENT *cur;
	NAMES *np;
	off_t maxsize;
	u_int64_t btotal, maxblock;
	u_long lattrlen, maxlen, maxnlink, maxlattr;
	ino_t maxinode;
	int bcfile, maxflags;
	gid_t maxgroup;
	uid_t maxuser;
	size_t flen, ulen, glen;
	char *initmax;
	int entries, needstats;
	const char *user, *group;
	char *flags, *lattr = NULL;
	char buf[STRBUF_SIZEOF(u_quad_t) + 1];
	char ngroup[STRBUF_SIZEOF(uid_t) + 1];
	char nuser[STRBUF_SIZEOF(gid_t) + 1];

	/*
	 * If list is NULL there are two possibilities: that the parent
	 * directory p has no children, or that fts_children() returned an
	 * error.  We ignore the error case since it will be replicated
	 * on the next call to fts_read() on the post-order visit to the
	 * directory p, and will be signaled in traverse().
	 */
	if (list == NULL)
		return;

	needstats = f_inode || f_longform || f_size;
	flen = 0;
	btotal = 0;
	initmax = getenv("LS_COLWIDTHS");
	/* Fields match -lios order.  New ones should be added at the end. */
	maxlattr = maxblock = maxinode = maxlen = maxnlink =
		maxuser = maxgroup = maxflags = maxsize = 0;
	if (initmax != NULL && *initmax != '\0') {
		char *initmax2, *jinitmax;
		int ninitmax;

		/* Fill-in "::" as "0:0:0" for the sake of scanf. */
		jinitmax = initmax2 = malloc(strlen(initmax) * 2 + 2);
		if (jinitmax == NULL)
			err(1, "malloc");
		if (*initmax == ':')
			strcpy(initmax2, "0:"), initmax2 += 2;
		else
			*initmax2++ = *initmax, *initmax2 = '\0';
		for (initmax++; *initmax != '\0'; initmax++) {
			if (initmax[-1] == ':' && initmax[0] == ':') {
				*initmax2++ = '0';
				*initmax2++ = initmax[0];
				initmax2[1] = '\0';
			}
			else {
				*initmax2++ = initmax[0];
				initmax2[1] = '\0';
			}
		}
		if (initmax2[-1] == ':')
			strcpy(initmax2, "0");

		ninitmax = sscanf(jinitmax,
#if _DARWIN_FEATURE_64_BIT_INODE
			" %llu : %qu : %lu : %i : %i : %i : %qu : %lu : %lu ",
#else
			" %lu : %qu : %lu : %i : %i : %i : %qu : %lu : %lu ",
#endif
			&maxinode, &maxblock, &maxnlink, &maxuser,
			&maxgroup, &maxflags, &maxsize, &maxlen, &maxlattr);
		f_notabs = 1;
		switch (ninitmax) {
		case 0:
			maxinode = 0;
			/* FALLTHROUGH */
		case 1:
			maxblock = 0;
			/* FALLTHROUGH */
		case 2:
			maxnlink = 0;
			/* FALLTHROUGH */
		case 3:
			maxuser = 0;
			/* FALLTHROUGH */
		case 4:
			maxgroup = 0;
			/* FALLTHROUGH */
		case 5:
			maxflags = 0;
			/* FALLTHROUGH */
		case 6:
			maxsize = 0;
			/* FALLTHROUGH */
		case 7:
			maxlen = 0;
			/* FALLTHROUGH */
		case 8:
			maxlattr = 0;
			/* FALLTHROUGH */
#ifdef COLORLS
			if (!f_color)
#endif
				f_notabs = 0;
			/* FALLTHROUGH */
		default:
			break;
		}
		maxinode = makenines(maxinode);
		maxblock = makenines(maxblock);
		maxnlink = makenines(maxnlink);
		maxsize = makenines(maxsize);
	}
	bcfile = 0;
	flags = NULL;
	for (cur = list, entries = 0; cur; cur = cur->fts_link) {
		if (cur->fts_info == FTS_ERR || cur->fts_info == FTS_NS) {
			warnx("%s: %s",
				cur->fts_name, strerror(cur->fts_errno));
			cur->fts_number = NO_PRINT;
			rval = 1;
			continue;
		}
		/*
		 * P is NULL if list is the argv list, to which different rules
		 * apply.
		 */
		if (p == NULL) {
			/* Directories will be displayed later. */
			if (cur->fts_info == FTS_D && !f_listdir) {
				cur->fts_number = NO_PRINT;
				continue;
			}
		}
		else {
			/* Only display dot file if -a/-A set. */
			if (cur->fts_name[0] == '.' && !f_listdot) {
				cur->fts_number = NO_PRINT;
				continue;
			}
		}
		if (cur->fts_namelen > maxlen)
			maxlen = cur->fts_namelen;
		if (f_octal || f_octal_escape) {
			u_long t = len_octal(cur->fts_name, cur->fts_namelen);

			if (t > maxlen)
				maxlen = t;
		}
		if (needstats) {
			sp = cur->fts_statp;
			if (sp->st_blocks > maxblock)
				maxblock = sp->st_blocks;
			if (sp->st_ino > maxinode)
				maxinode = sp->st_ino;
			if (sp->st_nlink > maxnlink)
				maxnlink = sp->st_nlink;
			if (sp->st_size > maxsize)
				maxsize = sp->st_size;

			btotal += sp->st_blocks;
			if (f_longform) {
				if (f_numericonly) {
					(void)snprintf(nuser, sizeof(nuser),
						"%u", sp->st_uid);
					(void)snprintf(ngroup, sizeof(ngroup),
						"%u", sp->st_gid);
					user = nuser;
					group = ngroup;
				}
				else {
					user = user_from_uid(sp->st_uid, 0);
					group = group_from_gid(sp->st_gid, 0);
				}
				if ((ulen = strlen(user)) > maxuser)
					maxuser = ulen;
				if ((glen = strlen(group)) > maxgroup)
					maxgroup = glen;
				if (f_flags) {
					flags = fflagstostr(sp->st_flags);
					if (flags != NULL && *flags == '\0') {
						free(flags);
						flags = strdup("-");
					}
					if (flags == NULL)
						err(1, "fflagstostr");
					flen = strlen(flags);
					if (flen > (size_t)maxflags)
						maxflags = flen;
				}
				else
					flen = 0;
				lattr = NULL;
				lattrlen = 0;

				if ((np = malloc(sizeof(NAMES) + lattrlen +
					ulen + glen + flen + 4)) == NULL)
					err(1, "malloc");

				np->user = &np->data[0];
				(void)strcpy(np->user, user);
				np->group = &np->data[ulen + 1];
				(void)strcpy(np->group, group);

				if (S_ISCHR(sp->st_mode) ||
					S_ISBLK(sp->st_mode))
					bcfile = 1;

				if (f_flags) {
					np->flags = &np->data[ulen + glen + 2];
					(void)strcpy(np->flags, flags);
					free(flags);
				}
				cur->fts_pointer = np;
			}
		}
		++entries;
	}

	if (!entries)
		return;

	d.list = list;
	d.entries = entries;
	d.maxlen = maxlen;
	if (needstats) {
		d.bcfile = bcfile;
		d.btotal = btotal;
		(void)snprintf(buf, sizeof(buf), "%qu", (u_int64_t)maxblock);
		d.s_block = strlen(buf);
		d.s_flags = maxflags;
		d.s_lattr = maxlattr;
		d.s_group = maxgroup;
#if _DARWIN_FEATURE_64_BIT_INODE
		(void)snprintf(buf, sizeof(buf), "%llu", maxinode);
#else
		(void)snprintf(buf, sizeof(buf), "%lu", maxinode);
#endif
		d.s_inode = strlen(buf);
		(void)snprintf(buf, sizeof(buf), "%lu", maxnlink);
		d.s_nlink = strlen(buf);
		(void)snprintf(buf, sizeof(buf), "%qu", (u_int64_t)maxsize);
		d.s_size = strlen(buf);
		d.s_user = maxuser;
	}
	printfcn(&d);
	output = 1;

	if (f_longform)
		for (cur = list; cur; cur = cur->fts_link)
			free(cur->fts_pointer);
}

/*
 * Ordering for mastercmp:
 * If ordering the argv (fts_level = FTS_ROOTLEVEL) return non-directories
 * as larger than directories.  Within either group, use the sort function.
 * All other levels use the sort function.  Error entries remain unsorted.
 */
static int
mastercmp(const FTSENT **a, const FTSENT **b)
{
	int a_info, b_info;

	a_info = (*a)->fts_info;
	if (a_info == FTS_ERR)
		return (0);
	b_info = (*b)->fts_info;
	if (b_info == FTS_ERR)
		return (0);

	if (a_info == FTS_NS || b_info == FTS_NS)
		return (namecmp(*a, *b));

	if (a_info != b_info &&
		(*a)->fts_level == FTS_ROOTLEVEL && !f_listdir) {
		if (a_info == FTS_D)
			return (1);
		if (b_info == FTS_D)
			return (-1);
	}
	return (sortfcn(*a, *b));
}

/*
 * Makenines() returns (10**n)-1.  This is useful for converting a width
 * into a number that wide in decimal.
 */
static u_quad_t
makenines(u_quad_t n)
{
	u_long i;
	u_quad_t reg;

	reg = 1;
	/* Use a loop instead of pow(), since all values of n are small. */
	for (i = 0; i < n; i++)
		reg *= 10;
	reg--;

	return reg;
}
