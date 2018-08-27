#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define mode_cat 0
#define mode_hex 1
#define mode_both 2
#define mode_json 3

int mode;

#ifndef SHELL
	#define SHELLtmpb
	#ifndef shell__builtins
		#ifndef shell__builtinstmpb
			#define shell__builtinstmpb
			char * quote (char * str) { 
				char * p = malloc(strlen(str)+3); 
				sprintf(p, "\"%s\"", str); 
				return p;
			}
			#define mq(a, b) char * a = quote(b)
			int read__(char *file, char **p, size_t *q) {
			    int fd;
			    size_t len = 0;
			    char *o;
			    if (!(fd = open(file, O_RDONLY)))
			    {
			        fprintf(stderr, "open() failure\n");
			        return (1);
			    }
			    len = lseek(fd, 0, SEEK_END);
			    lseek(fd, 0, 0);
			    if (!(o = malloc(len))) {
			        fprintf(stderr, "failure to malloc()\n");
			    }
			    if ((read(fd, o, len)) == -1) {
			        fprintf(stderr, "failure to read()\n");
			    }
			    int cl = close(fd);
			    if (cl < 0) {
			        fprintf(stderr, "cannot close \"%s\", returned %i\n", file, cl);
			        return -1;
			    }
			    *p = o;
			    *q = len;
			    return len;
			}
		#endif
	#endif
#else
	#ifndef shell__builtins
		#ifndef shell__builtinstmpb
			#define shell__builtinstmpb
			char * quote (char * str) { 
				char * p = malloc(strlen(str)+3); 
				sprintf(p, "\"%s\"", str); 
				return p;
			}
			#define mq(a, b) char * a = quote(b)
			int read__(char *file, char **p, size_t *q) {
			    int fd;
			    size_t len = 0;
			    char *o;
			    if (!(fd = open(file, O_RDONLY)))
			    {
			        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "open() failure\n");
			        return (1);
			    }
			    len = lseek(fd, 0, SEEK_END);
			    lseek(fd, 0, 0);
			    if (!(o = malloc(len))) {
			        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "failure to malloc()\n");
			    }
			    if ((read(fd, o, len)) == -1) {
			        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "failure to read()\n");
			    }
			    int cl = close(fd);
			    if (cl < 0) {
			        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "cannot close \"%s\", returned %i\n", file, cl);
			        return -1;
			    }
			    *p = o;
			    *q = len;
			    return len;
			}
		#endif
	#endif
#endif

#define whereis_mode_print_all 1
#define whereis_mode_return_first 2
#define whereis_mode_return_all_as_path 3
#define whereis_mode_return_all_as_string 4

#include "whereis.h"

void __hexdump(unsigned char *buffer, unsigned long index, unsigned long width)
{
	unsigned long i;
	if (mode == mode_both || mode == mode_hex) {
	for (i = 0; i < index; i++)
		printf("%02x ", buffer[i]);
	}
	if (mode == mode_both) {
	for (unsigned long spacer = index; spacer < width; spacer++)
		printf("\t");
	printf(": ");
	}
	if (mode == mode_cat || mode == mode_both || mode == mode_json) {
	for (i = 0; i < index; i++)
	{
		if (buffer[i] < 32 || buffer[i] >= 127)
			printf(".");
		else
			printf("%c", buffer[i]);
	}
	}
	printf("\n");
}

int __hexdump_file(FILE *infile, unsigned long start, unsigned long stop, unsigned long width)
{
	char ch;
	unsigned long f_index = 0;
	unsigned long bb_index = 0;
	unsigned char *byte_buffer = malloc(width);
	if (byte_buffer == NULL)
	{
		printf("Could not allocate memory for byte_buffer\n");
		return -1;
	}
	while (!feof(infile))
	{
		ch = getc(infile);
		if ((f_index >= start) && (f_index <= stop))
		{
			byte_buffer[bb_index] = ch;
			bb_index++;
		}
		if (bb_index >= width)
		{
			__hexdump(byte_buffer, bb_index, width);
			bb_index = 0;
		}
		f_index++;
	}
	if (bb_index)
		__hexdump(byte_buffer, bb_index, width);
	fclose(infile);
	free(byte_buffer);
	return 0;
}

int __hexdump_string(char *infile, unsigned long start, unsigned long stop, unsigned long width)
{
	char ch;
	unsigned long f_index = 0;
	unsigned long bb_index = 0;
	unsigned char *byte_buffer = malloc(width);
	if (byte_buffer == NULL)
	{
		printf("Could not allocate memory for byte_buffer\n");
		return -1;
	}
	while (*infile)
	{
		ch = *infile;
		if ((f_index >= start) && (f_index <= stop))
		{
			byte_buffer[bb_index] = ch;
			bb_index++;
		}
		if (bb_index >= width)
		{
			__hexdump(byte_buffer, bb_index, width);
			bb_index = 0;
		}
		f_index++;
		infile++;
	}
	if (bb_index)
		__hexdump(byte_buffer, bb_index, width);
	free(byte_buffer);
	return 0;
}

int __cathex(const int argc, const char * argv[])
{
	mq(qt, argv[1]);
	ps(qt)
	free(qt);
	int result;
	const char * file;
	if (argc < 2) {
		char ** a;
		int c = split("Built-Ins/Built-Ins", ' ', &a);
		file = builtin__whereis(c, a, ".h", false, NULL, whereis_mode_return_first);
		freesplit(c, &a);
	}
	else file = argv[1];
	if (mode == mode_cat || mode == mode_hex || mode == mode_json) {
		char * buf;
		size_t size;
		read__(file, &buf, &size);
		result = __hexdump((unsigned char *)buf, (unsigned long)size, 0);
	}
	else if (mode == mode_both) {
	int start = 0, width = 16+8;
	size_t length;
	char * disregard;
	read__(file, &disregard, &length);
	FILE *infile = fopen(file, "rb");
	if (infile == (FILE *)NULL)
	{
		printf("Error opening input file %s\n", file);
		return 0;
	}
	result = __hexdump_file(infile, start, start + (int)length, width);
	}
	return result;
}

char * __cathexj(const int argc, const char * argv[])
{
	unsigned char * buffer;
	unsigned long * len;
	const char * file;
	if (argc < 2) {
		char ** a;
		int c = split("Built-Ins/Built-Ins", ' ', &a);
		file = builtin__whereis(c, a, ".h", false, NULL, whereis_mode_return_first);
		freesplit(c, &a);
	}
	else file = argv[1];
	read__(file, (char *)&buffer, (size_t *)&len);
	struct BOM d = builtin__BOM_get(buffer);
	buffer += d.length;
	len -= d.length;
/*

The following characters are reserved in JSON and must be properly escaped to be used in strings:

Backspace is replaced with \b
Form feed is replaced with \f
Newline is replaced with \n
Carriage return is replaced with \r
Tab is replaced with \t
Double quote is replaced with \"
Backslash is replaced with \\
	
*/
	
	// small sacrifice, should be done in memory

	unsigned long i;
	remove("./json");
	FILE * printf_stdoutjjjjjjj = fopen("./json", "a+");
	for (i = 0; i < len; i++)
	{
		if ( buffer[i] == '\\' && buffer[i+1] == '\n' && i+2 == len ) fprintf(printf_stdoutjjjjjjj, "\\\n");
		else if ( buffer[i] == '\\' && buffer[i+1] == '\n' ) fprintf(printf_stdoutjjjjjjj, "\\\\\\n");
		else if ( buffer[i-1] == '\\' && buffer[i] == '\n' ) {}
		else if ( buffer[i] == '\n' && i+1 == len ) fprintf(printf_stdoutjjjjjjj, "\\n");
		else if ( buffer[i] == '\n' ) fprintf(printf_stdoutjjjjjjj, "\\n");
		else if ( buffer[i] == '\t' ) fprintf(printf_stdoutjjjjjjj, "\\t");
		else if ( buffer[i] == '\r' ) fprintf(printf_stdoutjjjjjjj, "\\r");
		else if ( buffer[i] == '\f' ) fprintf(printf_stdoutjjjjjjj, "\\f");
		else if ( buffer[i] == '\b' ) fprintf(printf_stdoutjjjjjjj, "\\b");
		else if ( buffer[i] == '"' ) fprintf(printf_stdoutjjjjjjj, "\\\"");
		else if ( buffer[i] == '\'' ) fprintf(printf_stdoutjjjjjjj, "\\'");
		else if ( buffer[i] == '\\' ) fprintf(printf_stdoutjjjjjjj, "\\\\");
		else if ( buffer[i] < 32 || buffer[i] >= 127 ) {}
			//fprintf(printf_stdoutjjjjjjj, "\
/* UNPRINTABLE CHARACTER %d */\
", buffer[i]);
		else
			fprintf(printf_stdoutjjjjjjj, "%c", buffer[i]);
	}
	fclose(printf_stdoutjjjjjjj);
	char * buf;
	size_t * size;
	read__("./json", &buf, &size);
	d = builtin__BOM_get(buf);
	buf += d.length;
	size -= d.length;
	buf[size] = NULL;
	
	return strdup(buf);
}

char * builtin__json(const int argc, const char * argv[]) {
	mode = mode_json;
	return __cathexj(argc, argv);
}

int builtin__hex(const int argc, const char * argv[]) {
	mode = mode_hex;
	return __cathex(argc, argv);
}

int builtin__cat(const int argc, const char * argv[]) {
	mode = mode_cat;
	return __cathex(argc, argv);
}

int builtin__xxd(const int argc, const char * argv[]) {
	mode = mode_both;
	return __cathex(argc, argv);
}

