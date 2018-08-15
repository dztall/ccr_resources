//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#ifndef shell__builtins
#define shell__builtins
#ifndef SHELL
struct shell {
	char * name;
} shell = { "Shell" };
#endif

#include "libstring.h"
#include <SDL.h>
#include <inttypes.h>
#include "regex.h"
#include "argv.h"
#define itta(x) list_array(x, #x)
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
#define iftimeret(x) { ift { timefuncret(x); } else { return x; } }
#define iftimeretc(x, ret) { ift { timefuncretc(x, ret); } else { x; return ret; } }

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

int builtin__CPU_Info(const int argc, const char * argv[]) {
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

#define whereis_mode_print_all 1
#define whereis_mode_return_first 2
#define whereis_mode_return_all_as_path 3
#define whereis_mode_return_all_as_string 4

char * builtin__whereis(const int argc, const char * argv[], const char * extention, int skip_arg0, char * optional_path, int mode);

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


int builtin__hex(const int argc, const char * argv[]) {
	mode = hex;
	return __cathex(argc, argv);
}

int builtin__cat(const int argc, const char * argv[]) {
	mode = cat;
	return __cathex(argc, argv);
}

int builtin__xxd(const int argc, const char * argv[]) {
	mode = both;
	return __cathex(argc, argv);
}

char * builtin__json(const int argc, const char * argv[]) {
	mode = json;
	return __cathexj(argc, argv);
}

char * filetostring(char * file) {
	char * buf;
	size_t size;
	read__(file, &buf, &size);
	buf[size] = NULL;
	return strdup(buf);
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
	char ** argv = env__add(env__add(env__new(), "default"), file);
	int argc = 2;
	char * s4 = builtin__json(argc, argv);
	free(argv);
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

int builtin__ls(const int argc, const char * argv[]) {
	DIR *pDir;
	struct dirent *ent;
	char * path = argc==1?"./":argv[1];
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

#include "whereis.h"

#include "gcc.h"

#endif
 
