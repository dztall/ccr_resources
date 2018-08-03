#ifndef shell__builtins
#define shell__builtins
#ifndef SHELL
struct shell {
	char * name;
} shell;
shell.name = "Shell";
#endif


#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEBUG2
#define DEBUG2
#endif

#ifndef DEBUG_SLEEP
#define DEBUG_SLEEP /* printf("sleeping for 2 seconds\n") ; sleep(2) ; */
#endif

#include "colors.h"

#ifndef PASSED
#define PASSED DEBUG2 DEBUG_SLEEP fprintf(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#endif

#ifndef PASSED_COLORS
#define PASSED_COLORS
#define PASSED_B DEBUG2 DEBUG_SLEEP fprintf_b(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#define PASSED_R DEBUG2 DEBUG_SLEEP fprintf_r(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#define PASSED_M DEBUGw DEBUG_SLEEP fprintf_m(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#endif

#ifndef CURRENT_FUNCTION
#define CURRENT_FUNCTION DEBUG2 printf("->called %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#endif

/*

#if !defined(_INTTYPES_H_)
#define _INTTYPES_H_

#  define __PRI_8_LENGTH_MODIFIER__ "hh"
#  define __PRI_64_LENGTH_MODIFIER__ "ll"
#  define __SCN_64_LENGTH_MODIFIER__ "ll"
#  define __PRI_MAX_LENGTH_MODIFIER__ "j"
#  define __SCN_MAX_LENGTH_MODIFIER__ "j"

#  define PRId8         __PRI_8_LENGTH_MODIFIER__ "d"
#  define PRIi8         __PRI_8_LENGTH_MODIFIER__ "i"
#  define PRIo8         __PRI_8_LENGTH_MODIFIER__ "o"
#  define PRIu8         __PRI_8_LENGTH_MODIFIER__ "u"
#  define PRIx8         __PRI_8_LENGTH_MODIFIER__ "x"
#  define PRIX8         __PRI_8_LENGTH_MODIFIER__ "X"

#  define PRId16        "hd"
#  define PRIi16        "hi"
#  define PRIo16        "ho"
#  define PRIu16        "hu"
#  define PRIx16        "hx"
#  define PRIX16        "hX"

#  define PRId32        "d"
#  define PRIi32        "i"
#  define PRIo32        "o"
#  define PRIu32        "u"
#  define PRIx32        "x"
#  define PRIX32        "X"

#  define PRId64        __PRI_64_LENGTH_MODIFIER__ "d"
#  define PRIi64        __PRI_64_LENGTH_MODIFIER__ "i"
#  define PRIo64        __PRI_64_LENGTH_MODIFIER__ "o"
#  define PRIu64        __PRI_64_LENGTH_MODIFIER__ "u"
#  define PRIx64        __PRI_64_LENGTH_MODIFIER__ "x"
#  define PRIX64        __PRI_64_LENGTH_MODIFIER__ "X"

#  define PRIdLEAST8    PRId8
#  define PRIiLEAST8    PRIi8
#  define PRIoLEAST8    PRIo8
#  define PRIuLEAST8    PRIu8
#  define PRIxLEAST8    PRIx8
#  define PRIXLEAST8    PRIX8

#  define PRIdLEAST16   PRId16
#  define PRIiLEAST16   PRIi16
#  define PRIoLEAST16   PRIo16
#  define PRIuLEAST16   PRIu16
#  define PRIxLEAST16   PRIx16
#  define PRIXLEAST16   PRIX16

#  define PRIdLEAST32   PRId32
#  define PRIiLEAST32   PRIi32
#  define PRIoLEAST32   PRIo32
#  define PRIuLEAST32   PRIu32
#  define PRIxLEAST32   PRIx32
#  define PRIXLEAST32   PRIX32

#  define PRIdLEAST64   PRId64
#  define PRIiLEAST64   PRIi64
#  define PRIoLEAST64   PRIo64
#  define PRIuLEAST64   PRIu64
#  define PRIxLEAST64   PRIx64
#  define PRIXLEAST64   PRIX64

#  define PRIdFAST8     PRId8
#  define PRIiFAST8     PRIi8
#  define PRIoFAST8     PRIo8
#  define PRIuFAST8     PRIu8
#  define PRIxFAST8     PRIx8
#  define PRIXFAST8     PRIX8

#  define PRIdFAST16    PRId16
#  define PRIiFAST16    PRIi16
#  define PRIoFAST16    PRIo16
#  define PRIuFAST16    PRIu16
#  define PRIxFAST16    PRIx16
#  define PRIXFAST16    PRIX16

#  define PRIdFAST32    PRId32
#  define PRIiFAST32    PRIi32
#  define PRIoFAST32    PRIo32
#  define PRIuFAST32    PRIu32
#  define PRIxFAST32    PRIx32
#  define PRIXFAST32    PRIX32

#  define PRIdFAST64    PRId64
#  define PRIiFAST64    PRIi64
#  define PRIoFAST64    PRIo64
#  define PRIuFAST64    PRIu64
#  define PRIxFAST64    PRIx64
#  define PRIXFAST64    PRIX64

// int32_t is 'int', but intptr_t is 'long'.
#  define PRIdPTR       "ld"
#  define PRIiPTR       "li"
#  define PRIoPTR       "lo"
#  define PRIuPTR       "lu"
#  define PRIxPTR       "lx"
#  define PRIXPTR       "lX"

#  define PRIdMAX        __PRI_MAX_LENGTH_MODIFIER__ "d"
#  define PRIiMAX        __PRI_MAX_LENGTH_MODIFIER__ "i"
#  define PRIoMAX        __PRI_MAX_LENGTH_MODIFIER__ "o"
#  define PRIuMAX        __PRI_MAX_LENGTH_MODIFIER__ "u"
#  define PRIxMAX        __PRI_MAX_LENGTH_MODIFIER__ "x"
#  define PRIXMAX        __PRI_MAX_LENGTH_MODIFIER__ "X"

#  define SCNd8         __PRI_8_LENGTH_MODIFIER__ "d"
#  define SCNi8         __PRI_8_LENGTH_MODIFIER__ "i"
#  define SCNo8         __PRI_8_LENGTH_MODIFIER__ "o"
#  define SCNu8         __PRI_8_LENGTH_MODIFIER__ "u"
#  define SCNx8         __PRI_8_LENGTH_MODIFIER__ "x"

#  define SCNd16        "hd"
#  define SCNi16        "hi"
#  define SCNo16        "ho"
#  define SCNu16        "hu"
#  define SCNx16        "hx"

#  define SCNd32        "d"
#  define SCNi32        "i"
#  define SCNo32        "o"
#  define SCNu32        "u"
#  define SCNx32        "x"

#  define SCNd64        __SCN_64_LENGTH_MODIFIER__ "d"
#  define SCNi64        __SCN_64_LENGTH_MODIFIER__ "i"
#  define SCNo64        __SCN_64_LENGTH_MODIFIER__ "o"
#  define SCNu64        __SCN_64_LENGTH_MODIFIER__ "u"
#  define SCNx64        __SCN_64_LENGTH_MODIFIER__ "x"

#  define SCNdLEAST8    SCNd8
#  define SCNiLEAST8    SCNi8
#  define SCNoLEAST8    SCNo8
#  define SCNuLEAST8    SCNu8
#  define SCNxLEAST8    SCNx8

#  define SCNdLEAST16   SCNd16
#  define SCNiLEAST16   SCNi16
#  define SCNoLEAST16   SCNo16
#  define SCNuLEAST16   SCNu16
#  define SCNxLEAST16   SCNx16

#  define SCNdLEAST32   SCNd32
#  define SCNiLEAST32   SCNi32
#  define SCNoLEAST32   SCNo32
#  define SCNuLEAST32   SCNu32
#  define SCNxLEAST32   SCNx32

#  define SCNdLEAST64   SCNd64
#  define SCNiLEAST64   SCNi64
#  define SCNoLEAST64   SCNo64
#  define SCNuLEAST64   SCNu64
#  define SCNxLEAST64   SCNx64

#  define SCNdFAST8     SCNd8
#  define SCNiFAST8     SCNi8
#  define SCNoFAST8     SCNo8
#  define SCNuFAST8     SCNu8
#  define SCNxFAST8     SCNx8

#  define SCNdFAST16    SCNd16
#  define SCNiFAST16    SCNi16
#  define SCNoFAST16    SCNo16
#  define SCNuFAST16    SCNu16
#  define SCNxFAST16    SCNx16

#  define SCNdFAST32    SCNd32
#  define SCNiFAST32    SCNi32
#  define SCNoFAST32    SCNo32
#  define SCNuFAST32    SCNu32
#  define SCNxFAST32    SCNx32

#  define SCNdFAST64    SCNd64
#  define SCNiFAST64    SCNi64
#  define SCNoFAST64    SCNo64
#  define SCNuFAST64    SCNu64
#  define SCNxFAST64    SCNx64

#  define SCNdPTR       "ld"
#  define SCNiPTR       "li"
#  define SCNoPTR       "lo"
#  define SCNuPTR       "lu"
#  define SCNxPTR       "lx"

#  define SCNdMAX       __SCN_MAX_LENGTH_MODIFIER__ "d"
#  define SCNiMAX       __SCN_MAX_LENGTH_MODIFIER__ "i"
#  define SCNoMAX       __SCN_MAX_LENGTH_MODIFIER__ "o"
#  define SCNuMAX       __SCN_MAX_LENGTH_MODIFIER__ "u"
#  define SCNxMAX       __SCN_MAX_LENGTH_MODIFIER__ "x"
*/

#include <inttypes.h>

#define puint64(x) printf("%s = %" PRIu64 "\n", #x, x);
#define puint32(x) printf("%s = %" PRIu32 "\n", #x, x);
#define puint16(x) printf("%s = %" PRIu16 "\n", #x, x);
#define puint8(x)  printf("%s = %" PRIu8 "\n", #x, x);

#define pc(x)      printf("%s = %c\n", #x, x);
#define puc(x)     printf("%s = %c\n", #x, x);
#define ps(x)      printf("%s = %s\n", #x, x);
#define pus(x)     printf("%s = %s\n", #x, x);
#define pi(x)      printf("%s = %d\n", #x, x);
#define pui(x)     printf("%s = %u\n", #x, x);
#define pd(x)      printf("%s = %f\n", #x, x);
#define pud(x)     printf("%s = %f\n", #x, x);
#define pl(x)      printf("%s = %l\n", #x, x);
#define pul(x)     printf("%s = %lu\n", #x, x);
#define pll(x)     printf("%s = %ll\n", #x, x);
#define pull(x)    printf("%s = %llu\n", #x, x);
#define psize_t(x) printf("%s = %zu\n", #x, x);
#define pp(x)      printf("%s = %p\n", #x, x);
#define px(x)      printf("%s = %02x\n", #x, x);
#define p(x)       printf(#x);

#define dothis(what, times) {\
	for(int i = 0;i<times;i++) { what }; \
}


#include "libstring.h"
#include "env.h"
#include <SDL.h>
#include <inttypes.h>
#include "regex.h"
#include "argv.h"
#include "grep.h" // not needed but included if it ever is
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef __CCR__
#include <ccr.h>
#endif
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include "clock.h"

#define ift if (has_time == true)

#define iftime(x) { ift { timefunc(x); } else { x; } } 

int getline_stdin(char ** input) {
	int total;
	char * t = malloc(4096);
	char charcurrent = 0;
	while(charcurrent!='\n') {
		charcurrent = getchar();
		if (charcurrent != '\n') total = sprintf(t, "%s%c", t, charcurrent);
	}
	if (!total) {
		free(t);
		return 0;
	}
	total++;
	*input = malloc(total);
	memset(*input, 0, total);
	strncpy(*input, t, total-1);
	free(t);
	return total-1;
}


char * quote (char * str) { 
	char * p = malloc(strlen(str)+3); 
	sprintf(p, "\"%s\"", str); 
	return p;
}

#define mq(a, b) char * a = quote(b)

#ifndef SPLIT
#define SPLIT
int split (const char *strconst, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;
    char * str = strdup(strconst);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }
    *arr = NULL;

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL) {
    	free(str);
        return -1;
    }

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL) {
		    	free(str);
		        return -1;
		    }

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL) {
		free(str);
		return -1;
	}

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }
    *t = '\0';
    
    free(str);

    return count;
}

void freesplit(int c, char *** a) {
	for (int i = 0; i < c; i++) free((*a)[i]);
	free(*a);
}

#endif

int builtin__CPU_Info(void) {
	Uint64 PerformanceCounter = SDL_GetPerformanceCounter();
	Uint64 PerformanceFrequency = SDL_GetPerformanceFrequency();
	int CPUCount = SDL_GetCPUCount();
	int CPUCacheLineSize = SDL_GetCPUCacheLineSize();
	int RAM = SDL_GetSystemRAM();
	int seconds, pct;
	SDL_GetPowerInfo(&seconds, &pct);
	printf("System Information:\n    CPU Count: %d\n    CPU Cache Line Size: %d\n    Performance Counter: %zd\n    Performance Frequency: %zd\n    RAM: %d\n",
	CPUCount,
	CPUCacheLineSize,
	PerformanceCounter,
	PerformanceFrequency,
	RAM
	);
	return 0;
}

//Original source code found at : http://c2.com/cgi/wiki?HexDumpInManyProgrammingLanguages
#define cat 0
#define hex 1
#define both 2
#define json 3

int mode;

char * builtin__whereis(char ** f, const char * extention, int skip_arg0);

void __hexdump(unsigned char *buffer, unsigned long index, unsigned long width)
{
	unsigned long i;
	if (mode == both || mode == hex) {
	for (i = 0; i < index; i++)
		printf("%02x ", buffer[i]);
	}
	if (mode == both) {
	for (unsigned long spacer = index; spacer < width; spacer++)
		printf("\t");
	printf(": ");
	}
	if (mode == cat || mode == both || mode == json) {
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

int __cathex(const char **args)
{
	mq(qt, args[1]);
	ps(qt)
	free(qt);
	int result;
	const char * file;
	if (args[1] == NULL || strcmp(args[1], "") ==  0) {
		char ** a;
		int c = split("Built-Ins/Built-Ins", ' ', &a);
		file = builtin__whereis(a, ".h", false);
		freesplit(c, &a);
	}
	else file = args[1];
	if (mode == cat || mode == hex || mode == json) {
		char * buf;
		size_t size;
		read__(file, &buf, &size);
		result = __hexdump((unsigned char *)buf, (unsigned long)size, 0);
	}
	else if (mode == both) {
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

struct BOM {
	int is_BOM;
	int length;
	int type;
	char * type_as_string;
	char * BOM;
}

int matches(char * BOM_, char * string_, int length_) {
	char * b = BOM_+1;
	for(int i = 0; i < length_; i++) {
		if (string_[i] == b[i]) matches = 1;
		else {
			matches = 0;
			break;
		}
	}
	return matches;
}

#define ifbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_, string_) if (matches(BOM_, string_, length_)) { \
	bom_struct.is_BOM = is_BOM_; \
	bom_struct.length = length_; \
	bom_struct.type = type_; \
	bom_struct.type_as_string = type_as_string_; \
	bom_struct.BOM = BOM_+1 /* remove the ^ at the start */ ; \
}

#define elifbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_, string_) else ifbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_, string_)

#define elbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_) else { \
	bom_struct.is_BOM = is_BOM_; \
	bom_struct.length = length_; \
	bom_struct.type = type_; \
	bom_struct.type_as_string = type_as_string_; \
	bom_struct.BOM = BOM_; \
}

#define builtin__BOM_print(bom_struct) { \
	printf("%s.is_BOM = %s\n%s.length = %d\n%s.type = %d\n%s.type_as_string = %s\n%s.BOM = ", #bom_struct, bom_struct.is_BOM?"yes":"no", #bom_struct, bom_struct.length, #bom_struct, bom_struct.type, #bom_struct,bom_struct.type_as_string, #bom_struct); \
	mode = both; \
	__hexdump_string(bom_struct.BOM, 0,bom_struct.length, 5); \
}


struct BOM builtin__BOM_get(char * string) {
	struct BOM bom;
	ifbom(bom, true, 3, 1, "UTF-8", "^\xef\xbb\xbf", string)
	elifbom(bom, true, 2, 2, "UTF-16 (BE)", "^\xfe\xff", string)
	elifbom(bom, true, 2, 3, "UTF-16 (LE)", "^\xff\xfe", string)
	elifbom(bom, true, 4, 4, "UTF-32 (BE)", "^\x00\x00\xfe\xff", string)
	elifbom(bom, true, 4, 5, "UTF-32 (LE)", "^\xff\xfe\x00\x00", string)
	elifbom(bom, true, 5, 6, "UTF-7", "^\x2b\x2f\x76\x38\x3d", string)
	elifbom(bom, true, 4, 7, "UTF-7", "^\x2b\x2f\x76\x38", string)
	elifbom(bom, true, 4, 8, "UTF-7", "^\x2b\x2f\x76\x39", string)
	elifbom(bom, true, 4, 9, "UTF-7", "^\x2b\x2f\x76\x2b", string)
	elifbom(bom, true, 4, 10, "UTF-7", "^\x2b\x2f\x76\x2f", string)
	elifbom(bom, true, 3, 11, "UTF-1", "^\xf7\x64\x4c", string)
	elifbom(bom, true, 4, 12, "UTF-EBCDIC", "^\xdd\x73\x66\x73", string)
	elifbom(bom, true, 3, 13, "SCSU", "^\x0e\xfe\xff", string)
	elifbom(bom, true, 3, 14, "BOCU-1", "^\xfb\xee\x28", string)
	elifbom(bom, true, 4, 15, "GB-18030", "^\x84\x31\x95\x33", string)
	elbom(bom, false, 0, 0, "Not present", "Not present")
	
	return (struct BOM) bom;
}

char * __cathexj(const char **args)
{
	unsigned char * buffer;
	unsigned long * len;
	const char * file;
	if (args[1] == NULL || strcmp(args[1], "") ==  0) {
		char ** a;
		int c = split("Built-Ins/Built-Ins", ' ', &a);
		file = builtin__whereis(a, ".h", false);
		freesplit(c, &a);
	}
	else file = args[1];
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


int builtin__hex(const char **args) {
	mode = hex;
	return __cathex(args);
}

int builtin__cat(const char **args) {
	mode = cat;
	return __cathex(args);
}

int builtin__xxd(const char **args) {
	mode = both;
	return __cathex(args);
}

char * builtin__json(const char **args) {
	mode = json;
	return __cathexj(args);
}

char * filetostring(char * file) {
	char * buf;
	size_t size;
	read__(file, &buf, &size);
	buf[size] = NULL;
	return strdup(buf);
}

char * chartostring(char c) {
	char cc[2];
	cc[0] = c;
	cc[1] = '\0';
	return strdup(cc);
}

void builtin__coliru(char * mode, char * file, char * cmd, char * out)
{
	if(access(file, F_OK) == -1) {
		printf(file);
		puts(" must be accessable");
		return;
	}
	if ((strcmp(mode, "compile") != 0 && strcmp(mode, "share") == 0) || (strcmp(mode, "compile") == 0 && strcmp(mode, "share") != 0));
	else {
		puts("must specify either \"compile\" or \"share\"");
		return;
	}
	if (file == NULL) {
		puts("must specify a file");
		return;
	}
	if (cmd == NULL) {
		puts("must specify a command (\" \" is allowed)");
		return;
	}
	char ** args = env__add(env__add(env__new(), "default"), file);
	char * s4 = builtin__json(args);
	free(args);
	char * s1 = "curl 'http://coliru.stacked-crooked.com/";
	char * s2 = "' --data-binary '{\"cmd\":\"";
	char * s3 = "\
\",\"src\":\"";
	char * s5;
	if (out == NULL) {
		s5 = "\"}'";
		out = "";
	}
	else {
		s5 = "\"}' -o ";
	}
	char * line = malloc(
	strlen(s1)+
	strlen(mode)+
	strlen(s2)+
	strlen(cmd)+
	strlen(s3)+
	strlen(s4)+
	strlen(s5)+
	strlen(out)
	);
	sprintf(line, "%s%s%s%s%s%s%s%s", s1, mode, s2, cmd, s3, s4, s5, out);
	//puts(line);
	if (strcmp(mode, "share") == 0) printf("http://coliru.stacked-crooked.com/a/");
	system(line);
	puts("");
}

char * __find_unknown(int type) {
	char unknown[10+16];
	sprintf(unknown, "unknown (%d)", type);
	return unknown;
}

char * __find_gettype (int type) {
	if (type==8) return "file";
	else if (type==4) return "folder";
	else return __find_unknown(type);
}

int builtin__ls(const char ** args) {
	DIR *pDir;
	struct dirent *ent;
	char * path = args[1]==NULL?"./":args[1];
	pDir = opendir(path);
	if (pDir)
	{
		while ((ent = readdir(pDir)) != NULL) printf("%s : %s\n", ent->d_name, __find_gettype(ent->d_type));
		closedir(pDir);
	}
	else {
		printf("Access to %s was denied\n", path);
		return -1;
	}
	return 0;
}

#define file__path 1
#define file__relative 2
#define file__directory 3

char * builtin__whereis(char ** f, const char * extention, int skip_arg0) {
	int mode, arg_number;
	if(*f[skip_arg0] == '.' && *f[skip_arg0]+1 == '/') mode = file__relative;
	else if (*f[skip_arg0] == '/') mode = file__directory;
	else {
		char ** tt;
		int c = split(f[skip_arg0], '/', &tt);
    	if (c == 1 && *f[skip_arg0] != '.') mode = file__path;
    	freesplit(c, &tt);
	}
	
	char * file = f[skip_arg0];
	
	if (mode == file__relative || mode == file__directory) return strdup(f[skip_arg0]);
	else {
		char * path = env__get(environ_default?environ_default:environ, "PATH");
		char ph[4096];
	  	if (!path) path = "/bin:/usr/bin:/usr/local/bin";
		sprintf(path, "%s:%s/CCR/Scripts", path, env__get(environ_default?environ_default:environ, "CPP_RESOURCE_DIR"));
		if (path == NULL) {
			puts("environment variable PATH is unset; cannot proceed");
			return NULL;
		}
		char *hardcoded_platform_specific_path_separator = ":";
		char * pathtmp = strdup(path);
		for (char *tok = strtok(pathtmp, hardcoded_platform_specific_path_separator); tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
			sprintf(ph, "/var/%s/%s%s", tok+4, file, extention);
			DEBUG printf("trying %s\n", ph);
			if (access(ph, F_OK) == 0) {
	      		if (shell.builtin) printf("found '%s' at '%s'\n", file, ph);
	      		return ph;
	      	}
		}
		free(pathtmp);
		pathtmp = strdup(path);
		for (char *tok = strtok(pathtmp, hardcoded_platform_specific_path_separator); tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
			sprintf(ph, "/var/%s/%s.proj%s", tok+4, file, extention);
			DEBUG printf("trying %s\n", ph);
			if (access(ph, F_OK) == 0) {
	      		if (shell.builtin) printf("found '%s' at '%s'\n", file, ph);
	      		return ph;
	      	}
		}
		free(pathtmp); // update puts .proj in named folders, we search both for compatibility with older versions
		pathtmp = strdup(path);
		for (char *tok = strtok(pathtmp, hardcoded_platform_specific_path_separator); tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
			sprintf(ph, "/var/%s/%s/%s.proj%s", tok+4, file, file, extention);
			DEBUG printf("trying %s\n", ph);
			if (access(ph, F_OK) == 0) {
	      		if (shell.builtin) printf("found '%s' at '%s'\n", file, ph);
	      		return ph;
	      	}
		}
		free(pathtmp);
		sprintf(ph, "./%s%s", file, extention);
		DEBUG printf("trying %s\n", ph);
		if (access(ph, F_OK) == 0) {
	      	if (shell.builtin) printf("found '%s' at '%s'\n", file, ph);
	      		return ph;
	    }
		sprintf(ph, "./%s.proj%s", file, extention);
		DEBUG printf("trying %s\n", ph);
	      if (access(ph, F_OK) == 0) {
	      	if (shell.builtin) printf("found '%s' at '%s'\n", file, ph);
	      		return ph;
	      }
	}
	printf("%s: %s not found\n", skip_arg0?file:shell.name, file);
	return NULL;
}

// for gcc builtin to be timed in detail, we need to set up seperate timers for each step, but what should we identify as a "step"?

/*

clock__add(timefunc_start);
clock__add(timefunc_end);

#define timefunc(func) { \
	clock__set(timefunc_start); \
	func; \
	clock__set(timefunc_end); \
	printf("cpu time: %.2f seconds\n", clock__calculate(timefunc_start, timefunc_end)); \
}



to time a initiation such as

int a = clock();

we could change this to

int a;
timefunc(a = clock())

tho additional time may be spent during the assignment of the variable

*/



// we enum to allow for preprocessing of #x as definition string of the define itself instead of its value
enum {
	// prepend _ to allow for preprocessing (if any) to still work on these defines
	
	_CPP_NO_ERROR=CPP_NO_ERROR,
	_CPP_OUT_OF_MEMORY=CPP_OUT_OF_MEMORY,
	_CPP_INVALID_ARGUMENTS=CPP_INVALID_ARGUMENTS,
	_CPP_INTERNAL_ERROR=CPP_INTERNAL_ERROR,
	_CPP_PARSING_ERROR=CPP_PARSING_ERROR,
	_CPP_LINKING_ERROR=CPP_LINKING_ERROR,
	_CPP_RUNNING_ERROR=CPP_RUNNING_ERROR
}

#define __return(function) printf("%s returned %d\n", #function, function);

#define retv(ret, x) if(ret == x) return #x+1; // trim the leading _

#define retc(x) retv(x, _CPP_INTERNAL_ERROR) retv(x, _CPP_INVALID_ARGUMENTS) retv(x, _CPP_LINKING_ERROR) retv(x, _CPP_NO_ERROR) retv(x, _CPP_OUT_OF_MEMORY) retv(x, _CPP_PARSING_ERROR) retv(x, _CPP_RUNNING_ERROR)

const char * return_cpp_error_code(int ret) {
	retc(ret)
	return "(null)";
}

CPPenum cpp_y;
const char * cpp_z;

#define cpp_check1(x) printf("%s returned %s\n", #x, return_cpp_error_code(x));

// same code above but with proper error checking

// cpp_check shall recieve a start clock and a end clock to eliminate time taken for debug calls when timing x itself, currently defines as invalid operand
#define cpp_check(x, clock_start, clock_end) { \
	/*clock_start = clock();*/ \
	cpp_y = x; \
	/*clock_end = clock();*/ \
	cpp_z = return_cpp_error_code(cpp_y); \
	if (strcmp(cpp_z, cpp_y==_CPP_NO_ERROR?"CPP_NO_ERROR":"NULL") != 0) { \
		printf("%s returned %s\n", #x, cpp_z); \
		return -1; \
	} \
}

const char *userHeaderSearchPaths[] = {};
const char *defines[] = { "#define DEVNULLSOMETHINGFOOBAR" };

void attachSourceFile(CPPuint programID, const char *fileName);
const char *getFileExtension(const char *fileName);

CPPuint programID = 0;

#define attachSourceFile(x, y) { \
	CPPuint objectID = cppCreateObject(); \
\
	/* Set user header search paths. */ \
	for (int i = 0; i < sizeof(userHeaderSearchPaths) / sizeof(userHeaderSearchPaths[0]); i++) \
		cpp_check(cppObjectAddUserHeaderSearchPath(objectID, userHeaderSearchPaths[i])); \
\
	/* Macro definitions... */ \
	for (int i = 0; i < sizeof(defines) / sizeof(defines[0]); i++) \
		cpp_check(cppObjectAddPrologue(objectID, defines[i])); \
\
	cpp_check(cppObjectSourceFile(objectID, y)); \
	cpp_check(cppCompileObject(objectID)); \
	cpp_check(cppAttachObject(x, objectID)); \
	cpp_check(cppDeleteObject(objectID)); \
}
	
	
	
	

int builtin__gcc(const char **args) {
	ift clock__init();
	const char * file;
	// time whereis first
	clock__add(whereis_start);
	clock__add(whereis_end);
	ift clock__set(whereis_start);
	file = builtin__whereis(args, ".c", true);
	ift clock__set(whereis_end);
	ps(file)
	if (strcmp(file,"NULL") == 0) {
		printf("%s: error: input is NULL\n", args[0]);
		return -1;
	}
	clock__add(create_start);
	clock__add(create_end);
	ift clock__set(create_start);
	programID = cppCreateProgram();
	ift clock__set(create_end);
	clock__add(build_start);
	clock__add(build_end);
	ift clock__set(build_start);
	//attachSourceFile(programID, "wrappers.h"); // add our wrapper file first
	attachSourceFile(programID, file);
	ift clock__set(build_end);
	DEBUG printf("Compiling and linking...\n");
	clock__add(link_start);
	clock__add(link_end);
	ift clock__set(link_start);
	cpp_check(cppLinkProgram(programID), clock__get(link_start), clock__get(link_end));
	ift clock__set(link_end);
	DEBUG printf("Running...\n");
	clock__add(run_start);
	clock__add(run_end);
	ift clock__set(run_start);
	cpp_check(cppRunProgram(programID), clock__get(run_start), clock__get(run_end));
	ift clock__set(run_end);
	DEBUG printf("Finished running.\n");
	clock__add(delete_start);
	clock__add(delete_end);
	if (programID) {
		ift clock__set(delete_start);
		cppDeleteProgram(programID);
		ift clock__set(delete_end);
	}
	ift clock__total(clock__shorten(whereis), clock__shorten(create), clock__shorten(build), clock__shorten(link), clock__shorten(run), clock__shorten(delete));
	return 0;
}


#endif
