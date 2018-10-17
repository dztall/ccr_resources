//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int getbitgroupcount(int bit) {
	return snprintf(stdout, 0, "%d", bit);
}

struct regex_string_structure
{
	char * string;
	int index;
	int len;
	int malloced;
};

struct regex_string
{
	char * string;
	struct regex_string_structure escaped;
	struct regex_string_structure json;
	struct regex_string_structure c_define;
	int index;
	int len;
	int malloced;
};

#define str_malloc_(y, z) \
	y.string = malloc(z); \
	memset(y.string, 0, z); \
	y.malloced = z; \
	y.len = 0; \
	y.index = 0;

#define str_mallocr(y, z) \
	str_malloc_(y, z); \
	str_malloc_(y.escaped, z); \
	str_malloc_(y.json, z); \
	str_malloc_(y.c_define, z); \
	
#define str_malloc(y, z) \
	struct regex_string y; \
	str_mallocr(y, z);

#define str_new(str) \
	str_malloc(str, 1) \
	
#define str_free_(y) \
		memset(y.string, 0, y.malloced); \
		free(y.string); \
		y.malloced = 0; \
		y.len = 0; \
		y.index = 0; \

#define str_free(y) \
	{ \
		str_free_(y); \
		str_free_(y.escaped); \
		str_free_(y.json); \
		str_free_(y.c_define); \
	}
	
#define str_reset_(str) { \
	str_free_(str) \
	str_malloc_(str, 1) \
}

#define str_reset(str) { \
	str_reset_(str) \
	str_reset_(str.escaped) \
	str_reset_(str.json) \
	str_reset_(str.c_define) \
}

#define str_realloc(y, z) \
	y.string = realloc(y.string, z); \
	if (y.malloced < z) { \
		memset(y.string+y.malloced, 0, y.malloced-z); \
	} \
	y.malloced = z;
	
#define str_info_(str) \
		printf("%s.index = %d\n", #str, str.index); \
		printf("%s.len = %d\n", #str, str.len); \
		printf("%s.malloced = %d\n", #str, str.malloced); \
		printf("%s.string = %s\n", #str, str.string); \

#define str_info(str) { \
	str_info_(str) \
	str_info_(str.escaped) \
	str_info_(str.json) \
	str_info_(str.c_define) \
}


#define str_insert_char(str, ch) { \
	str_realloc(str, str.malloced+1); \
	str.string[str.index] = ch; \
	str.index++; \
	str.len = strlen(str.string); \
}
#define rng(s, e) ( uch >= s && uch <= e)

#define str_insert_string(str, string) { \
	const unsigned char * s = string; \
	const unsigned int size = strlen(string); \
	int c; \
	unsigned char uch; \
	str_insert_char(str.c_define, '#') \
	str_insert_char(str.c_define, 'd') \
	str_insert_char(str.c_define, 'e') \
	str_insert_char(str.c_define, 'f') \
	str_insert_char(str.c_define, 'i') \
	str_insert_char(str.c_define, 'n') \
	str_insert_char(str.c_define, 'e') \
	str_insert_char(str.c_define, ' ') \
	for (int i = 0; i < size; ++i) { \
		c = s[i]; \
		uch = (unsigned char) s[i]; \
		str_insert_char(str, c); \
		\
		/* escape sequences under gnu gcc are interperated by both cc1, and the terminal, assembling a string containing an invalid sequence will print as if it does not have the \ before it*/ \
		\
		if (isalnum(c) ) { \
			str_insert_char(str.c_define, c); \
		} \
		else str_insert_char(str.c_define, '_'); \
		if (c == '\a') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 'a'); \
		} \
		else if (c == '\b') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 'b'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, 'b'); \
		} \
		else if (c == '\f') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 'f'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, 'f'); \
		} \
		else if (c == '\n') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 'n'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, 'n'); \
		} \
		else if (c == '\r') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 'r'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, 'r'); \
		} \
		else if (c == '\t') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 't'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, 't'); \
		} \
		else if (c == '\v') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, 'v'); \
		} \
		else if (c == '\\') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, '\\'); \
		} \
		else if (c == '\'') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, '\''); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, '\''); \
		} \
		else if (c == '"') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, '"'); \
			str_insert_char(str.json, '\\'); \
			str_insert_char(str.json, '"'); \
		} \
		else if (c == '\?') { \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, '?'); \
		} \
		else if (c >= ' ' && c <= 0x7e) { \
			str_insert_char(str.escaped, c); \
			str_insert_char(str.json, c); \
		} \
		else if (c >= '0' && c <= '9' ) { \
			/* Print \ooo */ \
			str_insert_char(str.escaped, '\\'); \
			str_insert_char(str.escaped, '0' + (c >> 6)); \
			str_insert_char(str.escaped, '0' + ((c >> 3) & 0x7)); \
			str_insert_char(str.escaped, '0' + (c & 0x7)); \
		} else { \
			/* Print \[[o]o]o */ \
			str_insert_char(str.escaped, '\\'); \
			if ((c >> 3) != 0) { \
				if ((c >> 6) != 0) str_insert_char(str.escaped, '0' + (c >> 6)); \
				str_insert_char(str.escaped, '0' + ((c >> 3) & 0x7)); \
			} \
			str_insert_char(str.escaped, '0' + (c & 0x7)); \
		} \
	} \
	str_insert_char(str.c_define, '\n'); \
}

#define str_int2string(x,y) \
	char * x = malloc(getbitgroupcount(y)); \
	sprintf(x, "%d", y);
	
#define str_insert_int(str, integer) { \
	str_int2string(j, integer); \
	str_insert_string(str, j); \
	free(j); \
}

int reverseBool(int val) {
	if (val == 1 || val == 0) return val^1;
	else return val;
}

void str_output(struct regex_string * str, const char * file);

void str_output_append(struct regex_string * str, const char * file);

#define str_output(str, file) { \
	FILE * stream = stdout; \
	int isfile = 0; \
	if (strcmp("stdin" file) == 0) stream = stdin; \
	else if(strcmp("stdout" file) == 0) stream = stdout; \
	else if(strcmp("stderr" file) == 0) stream = stderr; \
	else isfile = 1; \
	if (isfile) stream = fopen(file, "w"); \
	fwrite(str.string,str.len, 1, stream); \
	if (isfile) fclose(stream); \
}

#define str_output_append(str, file) { \
	FILE * stream = stdout; \
	int isfile = 0; \
	if (strcmp("stdin" file) == 0) stream = stdin; \
	else if(strcmp("stdout" file) == 0) stream = stdout; \
	else if(strcmp("stderr" file) == 0) stream = stderr; \
	else isfile = 1; \
	if (isfile) stream = fopen(file, "a"); \
	fwrite(str.string,str.len, 1, stream); \
	if (isfile) fclose(stream); \
}
