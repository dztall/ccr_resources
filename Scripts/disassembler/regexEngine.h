/*
this shall accept input in the notation of the reg_gen
syntax: from(-to),to_match,...
to do so we will use the existing code from reg_gen and modify it
*/
#ifndef shell__builtins
#include "../Shell/builtins/printfmacro.h"
#include "../Shell/builtins/regex_str.h"
#endif

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int regexEngine_max_bit_length = 0;
int regexEngine_bit_start = 0;
bool regexEngine_Debug = false;
int regexEngine_Total_Calls = 0;

#define ifregexEngine(x, y) if (!regexEngine(x,y))

#define inv(swap) swap = swap^1;

int regexEngine(char * fmt, char * string) {
	regexEngine_Total_Calls++;
	if (regexEngine_Debug) pi(regexEngine_max_bit_length)
	if (regexEngine_Debug) pi(regexEngine_bit_start)
	if (regexEngine_Debug) printf("string to parse = %s\n", fmt);
	int limit = regexEngine_max_bit_length*2;
	int limit_multiplierrange0 = 1;
	int limit_multiplierrange1 = 1;
	int limit_multiplierreg = 1;
	str_malloc(range0, limit*limit_multiplierrange0)
	range0.len = 0;
	range0.index = 0;
	str_malloc(range1, limit*limit_multiplierrange1)
	range1.len = 0;
	range1.index = 0;
	str_malloc(reg, limit*limit_multiplierreg)
	reg.len = 0;
	reg.index = 0;
	bool swap_next=0, range=0, range_next=0, is_range=1, is_regex=0, is_not = false, has_look = false;
	int offset = regexEngine_max_bit_length-regexEngine_bit_start;
	int regexEngine_bit_end = regexEngine_max_bit_length-offset, index=offset, add = 0, skip = 0, ii = 0, matches = -1, iitmp = 0, reglen = 0, number_of_matches = 0, number_to_pass = 0;
	while (fmt && *fmt) {
		
		// handle comma
		if(swap_next) {
			inv(swap_next)
			if (is_range) number_to_pass++;
			if (is_regex) inv(range)
			inv(is_regex)
			inv(is_range)
		}
		if (*fmt == ',' ) {
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
		if(is_range && !range_next && !swap_next) {
			if (!range){
				if (range0.index == limit*limit_multiplierrange0) {
					p(reallocating);
					limit_multiplierrange0++;
					str_realloc(range0, limit*limit_multiplierrange0);
				}
				range0.string[range0.index] = *fmt;
				range0.index++;
			}else{
				if (range1.index == limit*limit_multiplierrange1) {
					p(reallocating);
					limit_multiplierrange1++;
					str_realloc(range1, limit*limit_multiplierrange1);
				}
				range1.string[range1.index] = *fmt;
				range1.index++;
			}
		}
		if(is_regex && !swap_next) {
			// if regex contains a not, we go the easy way and replace it with a !
			if (skip) skip--;
			if (*(fmt) == 'n' && *(fmt+1) == 'o' && *(fmt+2) == 't') {
				skip += *(fmt+3)==' '?4:3;
			}
			if (skip) {
				if (skip == 1) {
					if (reg.index == limit*limit_multiplierreg) {
						p(reallocating);
						limit_multiplierreg++;
						str_realloc(reg, limit*limit_multiplierreg);
					}
					reg.string[reg.index] = '!';
					reg.index++;
				}
			}
			else {
				if (reg.index == limit*limit_multiplierreg) {
					p(reallocating);
					limit_multiplierreg++;
					str_realloc(reg, limit*limit_multiplierreg);
				}
				reg.string[reg.index] = *fmt=='x'||*fmt=='-'?'.':*fmt;
				reg.index++;
			} // if regex contains 'x' or '-' replace with '.'
		}
		*fmt++;
		
		
		if ((is_regex && swap_next) || (!*fmt)) {
			is_not = false;
			if (reg.string[0] == '!') is_not = true;
			int r0 = atoi(range0.string);
			int r1 = atoi(range1.string);
			if (!r1) r1=r0;
			if (regexEngine_Debug) ps(reg.string)
			
			// to handle the range we must first know what the maximum range is
			
			// then we calculate the offset according to the following rule:
			// if the bit indexes start at zero instead of one, the same must also be applied to the string range
			
			// once we have this offset we correct the ranges by adding it to both ranges, we do this later
			
			if (strstr(reg.string, "!") && !(strstr(reg.string, "!") == reg.string)) {
				has_look = true;
				if (regexEngine_Debug) ps(strstr(reg.string, "!"))
				if (regexEngine_Debug) pi(index)
				reglen = strlen(strstr(reg.string, "!")-1);
			}
			
			// if index is 0, we insert a ^
			if (r0 != regexEngine_bit_start) { 
				add = (regexEngine_max_bit_length-(index))-r0;
				if (regexEngine_Debug) pi(add)
				if (add) index += add;
			}
			index--;
			if (regexEngine_Debug) pi(index)
			ii=0;
			iitmp=0;
			matches = -1;
			for (int i = r1; i <= r0; i++) {
				if (has_look == true) {
					reg.string += reglen;
					for (int iii = r1; iii <= r0; iii++) {
						if (matches == -1 || matches == 0) {
							if (regexEngine_Debug) {
								pc(string[index+iitmp])
								pc(reg.string[iitmp])
							}
							if (string[index+iitmp] == reg.string[iitmp] || reg.string[iitmp] == '.') matches = 0;
							else {
								matches = 1;
								break;
							}
						}
						if (regexEngine_Debug) pi(matches);
						iitmp++;
					}
					reg.string -= reglen;
					has_look = false;
					matches = reverseBool(matches);
				}
				if (matches == -1 || matches == 0) {
					if (regexEngine_Debug) {
						pc(string[index+ii])
						pc(reg.string[is_not==true?ii+1:ii])
					}
					if (string[index+ii] == reg.string[is_not==true?ii+1:ii] || reg.string[is_not==true?ii+1:ii] == '.') matches = 0;
					else {
						matches = 1;
					}
				}
				else break;
				if (regexEngine_Debug) pi(matches);
				ii++;
			}
			if (is_not == true) matches = reverseBool(matches);
			if (regexEngine_Debug) {
				pi(matches);
				puts("");
			}
			if (matches == 0) number_of_matches++;
			// reset the strings
			memset(range0.string, 0, limit*limit_multiplierrange0); 
			memset(range1.string, 0, limit*limit_multiplierrange1); 
			memset(reg.string, 0, limit*limit_multiplierreg); 
			range0.index = 0;
			range1.index = 0;
			reg.index = 0;
			
		}
	}
	str_free(range0)
	str_free(range1)
	str_free(reg)
	if (number_of_matches == number_to_pass) return 0;
	return -1;
}
