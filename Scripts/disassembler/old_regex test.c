//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#define PCRE2_CODE_UNIT_WIDTH 8

#include <stdio.h>
#include <string.h>
#include <pcre2.h>
#include <stdbool.h>

int regex(char * RegexStr, char * source)
{
	bool Found = false;
	pcre2_code *re;
	PCRE2_SPTR pattern;
	PCRE2_SPTR subject;
	int errornumber;
	int rc;
	PCRE2_SIZE erroroffset;
	PCRE2_SIZE *ovector;
	size_t subject_length;
	pcre2_match_data *match_data;
	
	pattern = (PCRE2_SPTR)RegexStr;// <<<<< This is where you pass your REGEX 
	subject = (PCRE2_SPTR)source;// <<<<< This is where you pass your bufer that will be checked. 
	subject_length = strlen((char *)subject);
	re = pcre2_compile(
	  pattern,               /* the pattern */
	  PCRE2_ZERO_TERMINATED, /* indicates pattern is zero-terminated */
	  0,                     /* default options */
	  &errornumber,          /* for error number */
	  &erroroffset,          /* for error offset */
	  NULL);                 /* use default compile context */
	
	/* Compilation failed: print the error message and exit. */
	if (re == NULL)
	{
	  PCRE2_UCHAR buffer[256];
	  pcre2_get_error_message(errornumber, buffer, sizeof(buffer));
	  printf("PCRE2 compilation failed at offset %d: %s\n", (int)erroroffset,buffer);
	  return 1;
	}
	
	
	match_data = pcre2_match_data_create_from_pattern(re, NULL);
	
	rc = pcre2_match(
	  re,
	  subject,              /* the subject string */
	  subject_length,       /* the length of the subject */
	  0,                    /* start at offset 0 in the subject */
	  0,                    /* default options */
	  match_data,           /* block for storing the result */
	  NULL)==-1?-1:0;
  	pcre2_match_data_free(match_data);   /* Release memory used for the match */
 	pcre2_code_free(re);
	return rc;
}

#define pi(x) printf("%s = %d\n", #x, x);
#define pc(x) printf("%s = %c\n", #x, x);
#define ps(x) printf("%s = %s\n", #x, x);

int getbitgroupcount(int bit) {
	/*
	if (bit == 0) return 1;
	int n; 
	int count=0; 
	for( n = 0; n < (sizeof(bit)*2); n++ ) if( bit & ( 0xF << (n*4) ) ) count=n+1;
	return count;
	*/
	return snprintf(stdout, 0, "%d", bit)
}

struct regex_string
{
	char * string;
	int index;
	int len;
	int malloced;
};

#define xmalloc(x, y, z) { \
	x y = malloc(z); \
	memset(y, 0, z); \
}

#define zmalloc(y, z) { \
	y = malloc(z); \
	memset(y, 0, z); \
}

#define str_malloc(y, z) \
	struct regex_string y; \
	y.string = malloc(z); \
	memset(y.string, 0, z); \
	y.malloced = z; 
	
#define str_mallocr(y, z) \
	y.string = malloc(z); \
	memset(y.string, 0, z); \
	y.malloced = z; 
	
#define str_new(str) \
	str_malloc(str, 1) \
	str.len = 0; \
	str.index = 0;
	
#define str_free(y) \
	{ \
		free(y.string); \
		y.malloced = 0; \
		y.len = 0; \
		y.index = 0; \
	}
	
#define str_reset(str) { \
	str_free(str) \
	str_mallocr(str, 1) \
	str.len = 0; \
	str.index = 0; \
}

#define str_realloc(y, z) \
	y.string = realloc(y.string, z); \
	if (y.malloced < z) { \
		memset(y.string+y.malloced, 0, y.malloced-z); \
	} \
	y.malloced = z;
	
#define str_info(str) \
	{ \
		printf("%s.index = %d\n", #str, str.index); \
		printf("%s.len = %d\n", #str, str.len); \
		printf("%s.malloced = %d\n", #str, str.malloced); \
		printf("%s.string = %s\n", #str, str.string); \
	}


#define str_insert_char(str, index, ch) { \
	str_realloc(str, str.malloced+1); \
	str.string[index] = ch; \
	index++; \
	str.len = strlen(str.string); \
}

#define str_insert_string(str, index, string) { \
	char * s = string; \
	for(int i = 0; s[i]; i++) \
		str_insert_char(str, index, s[i]); \
}

#define str_int2string(x,y) \
	char * x = malloc(getbitgroupcount(y)); \
	sprintf(x, "%d", y);
	
#define str_insert_int(str, index, integer) { \
	str_int2string(j, integer); \
	str_insert_string(str, index, j); \
	free(j); \
}

int reverseBool(int val) {
	if (val == 1 || val == 0) return val^1;
	else return val;
}

int regex_gen_max_bit_length = 0;
int regex_gen_bit_start = 0;
bool regex_gen_Debug = false;

#define inv(swap) swap = swap^1;

char * regex_gen(char * fmt) {
	if (regex_gen_Debug) pi(regex_gen_max_bit_length)
	if (regex_gen_Debug) pi(regex_gen_bit_start)
	if (regex_gen_Debug) printf("string to parse = %s\n", fmt);
	str_new(range0)
	str_new(range1)
	str_new(reg)
	str_new(expression)
	bool swap_next=0, range=0, range_next=0, is_range=1, is_regex=0;
	int offset = regex_gen_max_bit_length-regex_gen_bit_start;
	int regex_gen_bit_end = regex_gen_max_bit_length-offset;
	int index=offset, add = 0, skip = 0;
	while (fmt && *fmt) {
		/*
		assumptions:
		1. the formatting is always in pairs, comma delimited
		1. first pair is bit range
		*/
		// handle comma
		if(swap_next) {
			inv(swap_next)
			if (is_regex) inv(range)
			inv(is_regex)
			inv(is_range)
		}
		if (*fmt == ',' ) {
			if (!range && is_range) {
				//str_insert_string(range1, range1.index, range0.string)
			}
			inv(swap_next)
			inv(range_next)
		}
		
		// handle range
		if (range_next) {
			inv(range_next)
			inv(range)
		}
		if (*fmt == '-' && is_range) inv(range_next)
		
		// parse string
		if(is_range && !range_next && !swap_next) { !range?str_insert_char(range0, range0.index, *fmt):str_insert_char(range1, range1.index, *fmt) }
		if(is_regex && !swap_next) {
			// if regex contains a not, we go the easy way and replace it with a !
			if (regex_gen_Debug) pi(skip)
			if (skip) skip--;
			if (*(fmt) == 'n' && *(fmt+1) == 'o' && *(fmt+2) == 't') {
				skip += *(fmt+3)==' '?4:3;
			}
			if (skip) {
				if (skip == 1) str_insert_char(reg, reg.index, '!')
			}
			else str_insert_char(reg, reg.index, *fmt=='x'?'.':*fmt) // if regex contains 'x' or '-' replace with '.'
		}
		if (regex_gen_Debug) {
			pc(*fmt)
			pi(swap_next)
			pi(range)
			pi(range_next)
			pi(is_range)
			pi(is_regex)
		}
		*fmt++;
		
		
		
		if ((is_regex && swap_next) || (!*fmt)) {
			int r0 = atoi(range0.string);
			int r1 = atoi(range1.string);
			if (regex_gen_Debug) {
				puts("");
				ps(reg.string)
				pi(index)
				pi(regex_gen_max_bit_length-(regex_gen_max_bit_length-r0))
				pi(regex_gen_max_bit_length-(regex_gen_max_bit_length-r1))
				str_info(reg) // should always end in an expression
			}
			/*
			once we have all required information we form part of the regex expression
			
			first we handle the range specification
			
			to handle the range we must first know what the maximum range is
			
			then we calculate the offset according to the following rule:
			if the bit indexes start at zero instead of one, the same must also be applied to the string range
			
			once we have this offset we correct the ranges by adding it to both ranges, we do this later
			
			*/
			
			// if index is 0, we insert a ^
			if (!(index-offset)) str_insert_char(expression, expression.index, '^');
			if (r0 != regex_gen_bit_start) { 
				add = (regex_gen_max_bit_length-(index))-r0;
				if (regex_gen_Debug) pi(add)
				if (add) {
					str_insert_string(expression, expression.index, ".{");
					str_insert_int(expression, expression.index, add);
					str_insert_char(expression, expression.index, '}');
					index += add;
				}
			}
			
			if (strstr(reg.string, "!") && !(strstr(reg.string, "!") == reg.string)) {
				str_insert_string(expression, expression.index, "(?");
				str_insert_string(expression, expression.index, strstr(reg.string, "!"));
				str_insert_char(expression, expression.index, ')');
				if (regex_gen_Debug) {
					pi(index)
					str_info(expression)
				}
				reg.len -= strlen(strstr(reg.string, "!")-1);
				//reg.string[strlen(reg.string)-strlen(strstr(reg.string, "!"))-1] = 0;
				memset(reg.string+(strlen(reg.string)-strlen(strstr(reg.string, "!"))-1), 0, strlen(strstr(reg.string, "!")))
			}
			// if regex starts with ! then we regex look ahead and skip
			
			if(strcmp(reg.string, "-") != 0) {
				if (reg.string[0] == '!') str_insert_string(expression, expression.index, "(?");
				str_insert_string(expression, expression.index, reg.string);
				if (reg.string[0] == '!') str_insert_char(expression, expression.index, ')');
			}
			if(strcmp(reg.string, "-") == 0) {
				//str_insert_string(reg, reg.index, strdup(reg.string));
				//str_insert_char(reg, 0, '!');
			}
			if (regex_gen_Debug)  {
				pi(index)
				pi(offset)
				pi(regex_gen_max_bit_length-(index-offset))
				pi(index)
			}
			index += reg.string[0] == '!'||strcmp(reg.string, "-") == 0?reg.len-1:reg.len;
			if (regex_gen_Debug) {
				pi(reg.len-1)
				pi(index)
				pi(offset)
				pi(reg.len)
				pi(regex_gen_max_bit_length-(index-offset))
				pi((regex_gen_max_bit_length-(index-offset))-r1)
				pi(r0)
				pi(r1)
				pi(index)
			}
			add = (regex_gen_max_bit_length-(index-offset))-r1;
			if (add < 0) {
				printf("error: regex pattern \"%s\" cannot fit, requested length: %d, needed length: %d\n", reg.string, (r0-r1)-offset, (reg.len-1));
				break;	
			}
			if (reg.string[0] == '!' ||strcmp(reg.string, "-") == 0|| add != 0) {
				if (regex_gen_Debug) pi(index)
				index += add;
				if (regex_gen_Debug) {
					pi(index)
					pi(regex_gen_max_bit_length-(index-offset))
					pi(add)
					pi((reg.len-1)+add)
				}
				str_insert_string(expression, expression.index, ".{");
				str_insert_int(expression, expression.index, reg.string[0] == '!'?(reg.len-1)+add:add);
				str_insert_char(expression, expression.index, '}');
			}
			if (regex_gen_Debug) {
				pi(index)
				str_info(expression)
			}
			// reset the strings
			str_reset(range0)
			str_reset(range1)
			str_reset(reg)
		}
	}
	str_free(range0)
	str_free(range1)
	str_free(reg)
	char * r = strdup(expression.string);
	str_free(expression)
	return r;
}

#define ifreg(x, y) if (!regex(regex_gen(x), y))


int main(void)
{
	regex_gen_Debug = false;
	regex_gen_max_bit_length = 32;
	regex_gen_bit_start = 31;
	// target regex is "^(?!1111).{4}00..{20}..{4}"

	char * re = "31-28,not 1111,27-25,00x,4,-";
	char * result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^(?!1111).{4}00..{20}.{5}"))
	
	re = "27-25,00x,4,-";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^.{4}00..{20}.{5}"))
	
	re = "31-28,not 1111";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^(?!1111).{4}"))
	
	re = "31-28,not 1111";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^(?!1111).{4}"))
	
	re = "4,-";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^.{27}.{5}"))
	
	re = "31-27,..0.0 not 0.010";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^(?!0.010)..0.0"))
	
	re = "31-27,..0.0 not 0.010";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^(?!0.010)..0.0"))
	
	re = "31-28,1110 not 1111,27-25,00x not 001,4,-";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^(?!1111)1110(?!001)00..{20}.{5}"))
	
	re = "27-25,00x not 001,4,-";
	result = regex_gen(re);
	ps(re);
	ps(result);
	pi(strcmp(result, "^.{4}(?!001)00..{20}.{5}"))

	ps(regex_gen("31-28,not 1111"))
	ps(regex_gen("31-28,not 1111"))
	ps(regex_gen("31-28,!1111"))
	ps(regex_gen("31-28,!1111"))
	return 0;
}
