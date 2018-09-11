



/*

shell info

http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18

https://www.gnu.org/software/bash/manual/bash.html



*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>

const char * replaces(const char * str, const char delim) {
	if (str == NULL) return NULL;
	char tmp[4096];
    for (int i = 0; str[i] != 0 ; i++) {
		if (str[i] == delim) { // assuming delim is ;
			if (i == 0) sprintf(tmp, "%c", str[i]); // ";"
			else if (i == 0 && str[i+1] != ' ') sprintf(tmp, "%c ", str[i]); // ";a"
			else if (str[i-1] == ' ' && str[i+1] == ' ') sprintf(tmp, "%s%c", tmp, str[i]); // " ; " do nothing
			else if (str[i-1] != ' ' && str[i+1] == '\0') sprintf(tmp, "%s %c",  tmp, str[i]); // "a;"
			else if (str[i-1] == ' ' && str[i+1] == '\0') sprintf(tmp, "%s%c",   tmp, str[i]); // "a ;"
			else if (str[i+1] == delim) sprintf(tmp, "%s %c",  tmp, str[i]); // ";;"
			else if (str[i-1] != ' ' && str[i+1] == ' ') sprintf(tmp, "%s %c",  tmp, str[i]); // "a; "
			else if (str[i-1] == ' ' && str[i+1] != ' ') sprintf(tmp, "%s%c ",  tmp, str[i]); // " ;a"
			else if (str[i-1] != ' ' && str[i+1] != ' ') sprintf(tmp, "%s %c ", tmp, str[i]); // "a;a"
			else {
			    sprintf(tmp, "%s%c", tmp, str[i]);
		    }
		}
		else {
			sprintf(tmp, "%s%c", tmp, str[i]);
		}
	}
	str = strdup(tmp);
	return str;
}


#ifdef __CCR__
#include "../Built-Ins/Built-Ins.h"
#endif
#ifndef __CCR__
// supply the functions if used
char * chartostring(char c) {
	char cc[2];
	cc[0] = c;
	cc[1] = '\0';
	return strdup(cc);
}
int getbitgroupcount(int bit) {
	/*
	if (bit == 0) return 1;
	int n; 
	int count=0; 
	for( n = 0; n < (sizeof(bit)*2); n++ ) if( bit & ( 0xF << (n*4) ) ) count=n+1;
	return count;
	*/
	return snprintf(stdout, 0, "%d", bit);
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

#endif

int debug_tok = 0;
int debug_char = 0;
int debug_scope = 0;

struct ret {
	int type;
	int start_pos;
	int end_pos;
	int length;
};

#define type_parenthesis  		// ()
#define type_curly_brackets 	// {}
#define type_brackets 			// []
#define type_single_quote 		// ''
#define type_double_quote 		// ""
#define type_hash 				// #
#define dollar_char   '$'
#define dollar_string "$"

/*

rules: attempt to follow the bash parse.y closely, modifying as desired

all returns shall have a type, length, start position, and end position

if dollar occurs we return it and its scope if applicable

if function scope we return the function name and its scope

if normal scope we return it

*/

struct scope
{
	int is_parenthesis; 	// ()
	int is_curly_brackets;	// {}
	int is_brackets;		// []
	int is_single_quote;	// ''
	int is_double_quote;	// ""
	int is_hash;			// #
	int is_scope_start;
	int is_not_scope;
	int current_scope;
	int last_scope[256];
	int scope_depth;
	int scope_state;
	int toggle;
	int got;
} a;

char * token;
int token_column;
int token_line;
char * last_token;
int last_token_column;
int last_token_line;
char * last_token_before_that;
int last_token_before_that_column;
int last_token_before_that_line;
char * word;
int word_column;
char * last_word;
int last_word_column;
char * last_word_before_that;
int last_word_before_that_column;


int line_global = 0;
int column_global = 0;

// macro definitions

#define tok if (state != 2) { \
			if ((a.current_scope == -1 || a.scope_depth == 0) && token == NULL) { \
				char * register_token = chartostring(ii.string[(ii.index-1)]); \
				if (debug_tok) printf("state: %d, at line/column %d/%d, registering token: %s\n", state, line_local, column_local, register_token); \
				token = register_token; \
				token_column = column_local; \
				token_line = line_local; \
			} \
			else if((a.current_scope == -1 || a.scope_depth == 0) && token != NULL) { \
				char * register_token = chartostring(ii.string[(ii.index-1)]); \
				if (debug_tok) printf("state: %d, at line/column %d/%d, registering token: %s\n", state, line_local, column_local, register_token); \
				if (debug_tok) printf("state: %d, at line/column %d/%d, registering last_token: %s\n", state, line_local, column_local, token); \
				if (debug_tok) printf("state: %d, at line/column %d/%d, registering last_token_before_that: %s\n", state, line_local, column_local, last_token); \
				last_token_before_that = strdup(last_token); \
				last_token_before_that_column = column_local-2>=0?column_local-2:0; \
				last_token_before_that_line = line_local; \
				last_token = strdup(token); \
				last_token_column = column_local-1>=0?column_local-1:0; \
				last_token_line = line_local; \
				token = register_token; \
				token_column = column_local; \
				token_line = line_local; \
			} \
} \
else if (state == 2) state = 0;

#define seperate_double_operator_start1(op, i, p, y, x) \
	if (op == 0 && i[p-1] != ' ' && i[p-1] != x && i[p] == x) { \
		str_insert_char(y, y.index, ' '); \
		if (debug_tok) str_info(y); \
		op = 1; \
		state = 1; \
		p--; \
		column_local--; \
		column_global--; \
	}
	
#define seperate_double_operator_start2(op, i, p, y, x) \
	else if (op == 0 && i[p-1] == x && i[p-2] == x && i[p] != ' ') { \
		str_insert_char(y, y.index, ' '); \
		if (debug_tok) str_info(y); \
		op = 1; \
		state = 2; \
		p--; \
		column_local--; \
		column_global--; \
	}
	
#define seperate_double_operator_start2_new(op, i, p, y, x) \
	else if (op == 0 && i[p-1] != ' ' && i[p-1] != x && i[p] == x) { \
		str_insert_char(y, y.index, ' '); \
		if (debug_tok) str_info(y); \
		op = 1; \
		state = 3; \
		p--; \
		column_local--; \
		column_global--; \
	}

#define seperate_double_operator_end(op, i, p, y) \
	else str_insert_char(y, y.index, i[p]); \
	if (op == 2) op = 0; \
	if (op == 1) op = 2;

#define tokp if (debug_tok) { if(token != NULL) printf("token = \"%s\", token_column = %d, ", token, token_column); \
				if(last_token != NULL) printf("last_token = \"%s\", last_token_column = %d, ", last_token, last_token_column); \
				if(last_token_before_that != NULL) printf("last_token_before_that = \"%s\", last_token_before_that_column= %d, ", last_token_before_that, last_token_before_that_column); \
				if(word != NULL) printf("word = \"%s\", word_column = %d, ", word, word_column); \
				if(last_word != NULL) printf("last_word = \"%s\", last_word_column = %d, ", last_word, last_word_column); \
				if(last_word_before_that != NULL) printf("last_word_before_that = \"%s\", last_word_before_that_column = %d, ", last_word_before_that, last_word_before_that_column); }
			
#define scope_enter(x) a.scope_state = 1; \
				a.scope_depth++; \
				a.last_scope[a.scope_depth] = a.current_scope; \
				a.current_scope=x;
				
#define scope_exit a.scope_state = 2; \
				a.scope_depth--; \
				a.last_scope[a.scope_depth] = a.last_scope[a.scope_depth+1];
			
#define scope_toggle_enter(x) a.toggle = 1; \
				a.scope_state = 8;\
				a.scope_depth++; \
				a.last_scope[a.scope_depth] = a.current_scope; \
				a.current_scope=x;
			
#define scope_toggle_exit a.toggle = -1; \
				a.scope_state = 2; \
				a.scope_depth--; \
				a.last_scope[a.scope_depth] = a.last_scope[a.scope_depth+1]; 
			
int which_token_int(char * desired) {
	if (strcmp(token, desired) == 0) return 0;
	else if (strcmp(last_token, desired) == 0) return 0;
	else if (strcmp(last_token_before_that, desired) == 0) return 0;
	else return -1;
}

int which_token_order_int(char * desired1, char * desired2) {
	// token order is reversed
	if (strcmp(token, desired2) == 0) {
		if (strcmp(last_token, desired1) == 0) {
			return 0;
		}
		return -1;
	}
	else if (strcmp(last_token, desired2) == 0) {
		if (strcmp(last_token_before_that, desired1) == 0) {
			return 0;
		}
		return -1;
	}
	else return -1;
}

int which_token_position_order_int(int desired1, int desired2) {
	// token order is reversed
	if (token_column == desired2) {
		if (last_token_column == desired1) {
			return 0;
		}
		return -1;
	}
	else if (last_token_column == desired2) {
		if (last_token_before_that_column == desired1) {
			return 0;
		}
		return -1;
	}
	else return -1;
}

int which_token_line_order_int(int desired1, int desired2) {
	// token order is reversed
	if (token_line == desired2) {
		if (last_token_line == desired1) {
			return 0;
		}
		return -1;
	}
	else if (last_token_line == desired2) {
		if (last_token_before_that_line == desired1) {
			return 0;
		}
		return -1;
	}
	else return -1;
}

char * which_token_char(char * desired) {
	if (which_token_int(desired) == -1) return "(null)";
	else if (strcmp(token, desired) == 0) return token;
	else if (strcmp(last_token, desired) == 0) return last_token;
	else if (strcmp(last_token_before_that, desired) == 0) return last_token_before_that;
	else return NULL;
}

#define reset(x) memset(x, 0, strlen(x))

int get_longest_line(char * file) {
	int p = 0,longest = 0, column_local = 0;
	while(file[p]) {
		if(file[p] == '\n')
		{
			if (longest < column_local) longest = column_local;
			column_local = 0;
		}
		else column_local++;
		p++;
	}
	if (longest < column_local) longest = column_local;
	return longest;
}

int get_lines(char * file) {
	int p = 0, lines = 0;
	while(file[p]) {
		if(file[p] == '\n') lines++;
		p++;
	}
	if (lines == 0) lines = 1;
	return lines;
}

char * fill_int(int pad, char fill, int i) {
	str_new(is);
	str_insert_int(is,is.index,i);
	int to_pad = 0, k = 0, kk = 0, iik = getbitgroupcount(i), ii = 0, l = 0;
	memcpy(&ii, &iik, sizeof(ii));
	if (pad < ii) to_pad = 0;
	else to_pad = pad-ii;
	char * string;
	zmalloc(string, to_pad+ii+1);
	for (int j = 0; j < to_pad+ii; j++) {
		for (; kk < to_pad; kk++) {
			string[j] = fill;
			j++;
		}
		string[j] = is.string[l];
		l++;
	}
	str_free(is);
	return string;
}

void parse(char * i, char * delim) {
	char local_fill = ' ';
	int input_len = strlen(i);
	int line_local = 0;
	int line_local_max = getbitgroupcount(get_lines(i));
	int column_local = 0;
	int column_local_max = getbitgroupcount(get_longest_line(i));
	if (strcmp(delim, "(") == 0 || strcmp(delim, ")") == 0 || strcmp(delim, "{") == 0 || strcmp(delim, "}") == 0 || strcmp(delim, "[") == 0 || strcmp(delim, "]") == 0 || strcmp(delim, "'") == 0 || strcmp(delim, "\"") == 0 || strcmp(delim, "#") == 0 || strcmp(delim, dollar_string) == 0 || strcmp(delim, "=") == 0) {
		puts("delimiter cannot be a reserved scope delimiter");
		return;
	};
	a.toggle = -1;
	a.is_parenthesis == -1;
	a.is_curly_brackets == -1;
	a.is_brackets == -1;
	a.is_single_quote == -1;
	a.is_double_quote == -1;
	a.is_hash == -1;
	a.current_scope	= -1;
	a.got = -1;
	int sh = -1;
	int hash = -1;
	int p = 0;
	char * buffer = malloc( input_len );
	int buffer_start;
	char * bufferb = malloc( input_len );
	char * input = malloc( input_len );
	
	token = malloc(10);
	last_token = malloc(10);
	last_token_before_that = malloc(10);
	word = malloc( input_len );
	last_word = malloc( input_len );
	last_word_before_that = malloc( input_len );
	
	token_column = 0;
	token_line = 0;
	last_token_column = 0;
	last_token_line = 0;
	last_token_before_that_column = 0;
	last_token_before_that_line = 0;
	word_column = 0;
	last_word_column = 0;
	last_word_before_that_column = 0;
	
	printf("original: \"%s\"\n", i);
	
	// shall be read line by line
	/*
	int h = 0;
	while(i[h]) {
		if (i[h] != '\0' || i[h] != '\n') strcat(input, chartostring(i[h]));
		if ((i[h] == '\0' || i[h] == '\n') && input != 0) {
			input = replaces(replaces(input, '&'), '|');
			printf("line = %s", input);
			reset(input);
			usleep(1000);
		}
		h++;
	}
	if (input) free(input);
	*/
	str_new(ii);
	int op = 0;
	int state = 0;
	while(i[p]) {
		if (strcmp(buffer, "") == 0) buffer_start = column_local;
		strcat(bufferb, chartostring(i[p]));
		
		seperate_double_operator_start1(op, i, p, ii, '&')
		seperate_double_operator_start2(op, i, p, ii, '&')
		seperate_double_operator_start2_new(op, i, p, ii, '|')
		seperate_double_operator_start2(op, i, p, ii, '|')
		seperate_double_operator_end(op, i, p, ii)
		 
		if (debug_char) printf("ii.string[%0*d] = %c, buffer = %s\n", getbitgroupcount(input_len), (ii.index-1), ii.string[(ii.index-1)], buffer);
		
		if (a.toggle == -1 && a.is_parenthesis == -1 && a.is_curly_brackets == -1 && a.is_brackets == -1 && a.is_single_quote == -1 && a.is_double_quote == -1 && a.is_hash == -1 && sh == -1) {}
		else a.got = 1;
		
		if (a.is_parenthesis == -1 && a.is_curly_brackets == -1 && a.is_brackets == -1 && a.is_single_quote == -1 && a.is_double_quote == -1 && a.is_hash == -1) a.current_scope = -1;
		else a.is_not_scope = 1;
		
		if(a.current_scope == -1 && ii.string[(ii.index-1)-1] == '\n')
		{
			line_global++;
			column_global = 0;
			line_local++;
			column_local = 0;
			reset(token);
			reset(last_token);
			reset(last_token_before_that);
			reset(word);
			reset(last_word);
			reset(last_word_before_that);
			token_column = 0;
			last_token_column = 0;
			last_token_before_that_column = 0;
			word_column = 0;
			last_word_column = 0;
			last_word_before_that_column = 0;
		}
		
		if (sh == 1) {}
		else if (a.current_scope == -1 && isspace(ii.string[(ii.index-1)-1])) {
			if (ii.string[(ii.index-1)] == '(') {}
			else if (ii.string[(ii.index-1)] == ')') {}
			else if (ii.string[(ii.index-1)] == '{') {}
			else if (ii.string[(ii.index-1)] == '}') {}
			else if (ii.string[(ii.index-1)] == '=') {}
			else if (ii.string[(ii.index-1)] == '<') {}
			else if (ii.string[(ii.index-1)] == '[') {}
			else if (ii.string[(ii.index-1)] == ']') {}
			else if (ii.string[(ii.index-1)] == '"') {}
			else if (ii.string[(ii.index-1)] == '\'') {}
			else if (ii.string[(ii.index-1)] == '#') {}
			else if (ii.string[(ii.index-1)] == '!') {}
			else if (ii.string[(ii.index-1)] == '&') {}
			else if (ii.string[(ii.index-1)] == dollar_char) {}
			else if (ii.string[(ii.index-1)] == '-' || isalnum(ii.string[(ii.index-1)])) {
				last_word_before_that = strdup(last_word);
				memcpy(&last_word_before_that_column, &last_word_column, sizeof(last_word_before_that_column));
				last_word_before_that_column = last_word_column;
				last_word = strdup(word);
				memcpy(&last_word_column, &word_column, sizeof(last_word_column));
				reset(word);
				strcat(word, chartostring(ii.string[(ii.index-1)]));
				memcpy(&word_column, &column_local, sizeof(word_column));
			}
		}
		else if(a.current_scope == -1 && isalnum(ii.string[(ii.index-1)])) {
			strcat(word, chartostring(ii.string[(ii.index-1)]));
		}
		
		if (ii.string[(ii.index-1)] == '(') {
			tok;
			scope_enter(1);
			a.is_parenthesis++;
		}
		else if (ii.string[(ii.index-1)] == ')') {
			scope_exit
			tok
			a.is_parenthesis--;
		}
		else if (ii.string[(ii.index-1)] == '{') {
			tok
			scope_enter(2);
			a.is_curly_brackets++;
		}
		else if (ii.string[(ii.index-1)] == '}') {
			tok
			scope_exit
			a.is_curly_brackets--;
		}
		else if (ii.string[(ii.index-1)] == '[') {
			tok
			scope_enter(3);
			a.is_brackets++;
		}
		else if (ii.string[(ii.index-1)] == ']') {
			tok
			scope_exit
			a.is_brackets--;
		}
		else if (ii.string[(ii.index-1)] == '=') {
			tok
		}
		else if (ii.string[(ii.index-1)] == '<') {
			tok
		}
		else if (ii.string[(ii.index-1)] == '!') {
			tok
		}
		else if (ii.string[(ii.index-1)] == '"') {
			if (a.toggle == -1) {
				tok
				scope_toggle_enter(5);
				a.is_double_quote++;
			}
			else if (a.toggle == 1) {
				tok
				scope_toggle_exit
				a.is_double_quote--;
			}
		}
		else if (ii.string[(ii.index-1)] == '\'') {
			if (a.toggle == -1) {
				tok
				scope_toggle_enter(6);
				a.is_single_quote++;
			}
			else if (a.toggle == 1) {
				tok
				scope_toggle_exit
				a.is_single_quote--;
			}
		}
		else if (i[p] == '&') {
			tok
		}
		else if (i[p] == '|') {
			tok
		}
		else if(ii.string[(ii.index-1)] == dollar_char && a.current_scope == -1) {
			tok
			//printf("dollar detected, ");
			sh = 1;
		}
		else if(ii.string[(ii.index-1)] == '#' && a.current_scope == -1) {
			tok
			//printf("dollar detected, ");
			hash = 1;
			a.is_hash++;
		}
		if ((sh == 1 || hash == 1) && a.current_scope == -1 && ii.string[(ii.index-1)] != '\0' && ii.string[(ii.index-1)] != ' ' && ii.string[(ii.index-1)] != '\n') strcat(buffer, chartostring(ii.string[(ii.index-1)]));
		else if (sh == 1 && a.current_scope == -1 && (ii.string[(ii.index-1)] == '\0' || ii.string[(ii.index-1)] == ' ' || ii.string[(ii.index-1)] == '\n')) {
			sh = -1;
			if (buffer != NULL && strcmp(buffer, "") != 0) {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, word_column));
				tokp
				if (which_token_int("=") == 0 && word != NULL) printf("assignment: %s%s%s\n", word, which_token_char("="), buffer);
				else printf("shell variable reference: %s\n", buffer);
			}
			reset(buffer);
		}
		else if (hash == 1 && a.current_scope == -1 && (ii.string[(ii.index-1)] == '\0' || ii.string[(ii.index-1)] == ' ' || ii.string[(ii.index-1)] == '\n')) {
			hash = -1;
			if (buffer != NULL && strcmp(buffer, "") != 0 && which_token_order_int("#", "!") == 0 && which_token_position_order_int(0, 1) == 0 && which_token_line_order_int(0, 0) == 0) {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
				tokp
				printf("shebang: %s\n", buffer);
			}
			else {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
				tokp
				printf("comment: %s\n", buffer);
			}
			reset(buffer);
		}
		if (a.current_scope != -1) {
			strcat(buffer, chartostring(ii.string[(ii.index-1)]));
			if (debug_scope) printf("(scope state: %d, scope depth:%d, current scope: %d, last scope: %d) i[%d] = %c\n", a.scope_state, a.scope_depth, a.current_scope, a.last_scope[a.scope_depth], p, ii.string[(ii.index-1)]);
		}
		if (a.scope_state == 1) a.scope_state = 3;
		else if (a.scope_state == 2) {
			a.scope_state = 4;
			if (a.scope_depth == 0) {
				a.current_scope = -1;
				if (buffer != NULL) {
					if (sh = 1 && which_token_int("=") == 0 && word != NULL) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, word_column));
						tokp
						printf("assignment: %s%s%s\n", word, which_token_char("="), buffer);
					}
					// if dollar is detected we do not scope, however not scoping then brings up more problems so instead we detect it from the scope itself
					else if (which_token_order_int(dollar_string, "(") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("shell variable command substitution reference: %s\n", buffer);
					}
					else if (which_token_order_int("<", "(") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("process substitution: <%s\n", buffer);
					}
					else if (which_token_order_int(dollar_string, "{") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("shell variable array reference: %s\n", buffer);
					}
					else if (which_token_order_int("(", ")") == 0 && word != NULL) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, word_column));
						tokp
						printf("function declaration: %s%s\n", word, buffer);
					}
					else if (which_token_order_int("(", ")") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("compound command: %s\n", buffer);
					}
					else if (which_token_int("[") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("test statement: %s\n", buffer);
					}
					else if (which_token_int("{") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("code block: %s\n", buffer);
					}
					else if (which_token_int("\"") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("double quotes: %s\n", buffer);
					}
					else if (which_token_int("'") == 0) {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("single quotes: %s\n", buffer);
					}
					else {
						printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, buffer_start));
						tokp
						printf("unknown: %s\n", buffer);
					}
				}
    			reset(buffer);
			}
			else a.current_scope=a.last_scope[a.scope_depth];
		}
		else if (a.current_scope == -1 && (ii.string[(ii.index-1)] == '\0' || ii.string[(ii.index-1)] == ' ' || ii.string[(ii.index-1)] == '\n')) {
			if (ii.string[(ii.index-1)] == ' ' && word && which_token_order_int("&", "&") == 0 && strcmp(last_word,"") != 0) {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, last_word_column));
				tokp
				printf("logical AND: %s%s%s%s\n", last_word, token, last_token, word);
				reset(token);
				reset(last_token);
				reset(last_word);
			}
			else if (word && which_token_order_int("&", "&") == 0 && strcmp(last_word,"") != 0) {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, last_word_column));
				tokp
				printf("logical AND: %s%s%s%s\n", last_word, token, last_token, word);
			}
			else if (ii.string[(ii.index-1)] == ' ' && word && which_token_order_int("|", "|") == 0 && strcmp(last_word,"") != 0) {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, last_word_column));
				tokp
				printf("logical OR : %s%s%s%s\n", last_word, token, last_token, word);
				reset(token);
				reset(last_token);
				reset(last_word);
			}
			else if (word && which_token_order_int("|", "|") == 0 && strcmp(last_word,"") != 0) {
				printf("line: %s, column: %s, ", fill_int(line_local_max, local_fill, line_local), fill_int(column_local_max, local_fill, last_word_column));
				tokp
				printf("logical OR: %s%s%s%s\n", last_word, token, last_token, word);
			}
		}
		p++;
		column_global++;
		column_local++;
	}
	free(token);
	free(last_token);
	str_free(ii);
}


int main() {
	#ifndef __CCR__
	// supply the file as json compatible (or quote safe) string
	char * string = "#!/bin/bash\na && b\ng && j || h && s\ng&&j||h&&s\nstrippath()\n{\n    realpath1=$(readlink -f $1)\n    pathdir1=$(dirname \"$realpath1\")\n    pathdir1=\"$pathdir1/\"\n    echo $pathdir1\n}\n\nif [[ -d $path ]]; then\n    echo $path is a directory\n    stripped=$(strippath $path)\n    pathreal=$(readlink -f $path)\n    mapfile -d \'\' -t filesreal < <(find \"${pathreal[0]}\" -type f -print0)\n    mapfile -d \'\' -t dirsreal < <(find \"${pathreal[0]}\" -type d -print0)\n    echo execute function: preinitmulti\n    count=1\n    for i in ${!filesreal[@]} ; do\n    pathdir=$(dirname \"${filesreal[i]}\")\n    pathdir=\"$pathdir/\"\n    pathbase=(\"${filesreal[i]#$pathdir}\")\n    pathstripped=(\"${pathdir#$stripped}\")\n    echo\n    echo \"execute function: objectconvertMulti with arguments (full file path:) ${filesreal[i]}, (identifier to avoid object collisions:) $i, (directory to be created on extraction:) $pathstripped, (file to be created on extraction:) ${pathbase[0]}\"\n    echo\n    echo ${filesreal[i]} processed\n    done\n    echo execute function: fin\n    echo execute function: compilemulti\n    echo execute function: finishmulti\n    exit\nfi\n\npath=$@\n";
	#endif
	#ifdef __CCR__
	// else obtain it natively via built-ins header
	char * string = filetostring("test.sh");
	#endif
    
	parse(string, " ");
	
    return 0;
}
