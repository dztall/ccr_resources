#include "Garbage_Collector/gc.h"
/*
 * Copyright (c) 1989, 1993
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
 */

#ifndef lint
static char const copyright[] =
"@(#) Copyright (c) 1989, 1993\n\
	The Regents of the University of California.  All rights reserved.\n";
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)echo.c	8.1 (Berkeley) 5/31/93";
#endif
#endif /* not lint */
#include <sys/cdefs.h>
__RCSID("$FreeBSD: src/bin/echo/echo.c,v 1.13 2002/06/30 05:13:53 obrien Exp $");

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#define usage_print(x) printf("%s\n", x);
#define usage_print_command(x) printf("\t%s\n", x);
#define usage_print_command_info(x) printf("\t\t\t\t%s\n", x);

/* ARGSUSED */

void usage(void) {
	usage_print("echo [-o file] [-n] given text");
	usage_print_command("-o file");
	usage_print_command_info("writes given text to a given output file, creating it if it does not exist otherwise truncating it to zero");
	usage_print_command("-n");
	usage_print_command_info("appends a new line to the end of the given text");
}
int
main(int argc, char *argv[])
{
	int nflag;	/* if not set, output a trailing newline. */
	FILE * stream = stdout;
	int isfile = 0;
	/* This utility may NOT do getopt(3) option parsing. */
	
	if (argc == 1) {
		usage();
		return 0;
	}
	
	if (strcmp(argv[1], "-o") == 0) {
		if (argc == 2) {
			puts("-o requires a filename");
			Garbage_Collector_Shutdown();
			return -1;
		}
		if (strcmp(argv[2], "--stdin") == 0) stream = stdin;
		else if (strcmp(argv[2], "--stdout") == 0) stream = stdout;
		else if (strcmp(argv[2], "--stderr") == 0) stream = stderr;
		else {
			isfile=1;
			stream = fopen(argv[2], "w");
		}
		argv+=2;
	}

	if (argv[1] != NULL) {
		if (!strcmp(argv[1], "-n")) {
			argv+=1;
			nflag = 1;
		}
		else nflag = 0;
	}
	argv+=1;
	

	while (argv[0] != NULL) {

		/*
		 * If the next argument is NULL then this is this
		 * the last argument, therefore we need to check
		 * for a trailing \c.
		 */
		if (argv[1] == NULL) {
			size_t len;
			
			len = strlen(argv[0]);
			/* is there room for a '\c' and is there one? */
			if (len >= 2 &&
			    argv[0][len - 2] == '\\' &&
			    argv[0][len - 1] == 'c') {
				/* chop it and set the no-newline flag. */
				argv[0][len - 2] = '\0';
				nflag = 1;
			}
		}
		fprintf(stream, "%s", argv[0]);
		if (*++argv) fprintf(stream, " ");
	}
	if (nflag) fprintf(stream, "\n");
	if (isfile) fclose(stream);
	Garbage_Collector_Shutdown();
	return 0;
}
