
#define arm2index(x) x-(regexEngine_max_bit_length-regexEngine_bit_start)

#define shift_to_bit32(x) ((31-x)*sizeof(char))
#define shift_by_bits32(x) (x*sizeof(char))

int32_t string_to_bin(int len, char * s) {
	int32_t x = 0;
	for(int i = 0; i < len; i++) x = (x << 1) | (s[i] == '1' ? 1 : 0);
	return x;
}

uint64_t string_to_bin64(int len, char * s) {
	uint64_t x = 0;
	for(int i = 0; i < len; i++) x = (x << 1) | (s[i] == '1' ? 1 : 0);
	return x;
}

int32_t binary(int start, int end, char * s) {
	int32_t x = 0;
	for(int i = end; i <= start; i++) x = (x << 1) | (s[arm2index(i)] == '1' ? 1 : 0);
	return x;
}

#define SIGN_EXTEND(to, from, value) ( \
	( \
		( \
			(value) << (to - from) \
		) \
		>> (to - from) \
	) \
)
	
#define ZERO_EXTEND(to, from, value) ( \
	( \
		(unsigned)( \
			(value) << (to - from) \
		) \
		>> (to - from) \
	) \
)

	
void extract_h(char * to, char * from, int locationstart,int locationend) {
	int ii = 0;
	for (int i = locationend; i <= locationstart; i++) {
		to[ii] = from[arm2index(i)];
		ii++;
	}
	to[ii] = 0;
}
#define extract(to,from,locationstart,locationend) char to[(locationstart-locationend)+2]; extract_h(to,from,locationstart,locationend)

bool ConditionPassed(char * cond) {
	bool result;
	ifregexEngine("3-1,000", cond) result = (APSR->Z == '1');
	else ifregexEngine("3-1,001", cond) result = (APSR->C == '1');
	else ifregexEngine("3-1,010", cond) result = (APSR->N == '1');
	else ifregexEngine("3-1,011", cond) result = (APSR->V == '1');
	else ifregexEngine("3-1,100", cond) result = (APSR->C == '1' && APSR->Z == '0');
	else ifregexEngine("3-1,101", cond) result = (APSR->N == APSR->V);
	else ifregexEngine("3-1,110", cond) result = (APSR->N == APSR->V && APSR->Z == '0');
	else ifregexEngine("3-1,111", cond) result = true;
	if(cond[3] == '1' && strcmp(cond, "1111") == -1) result = !result;
	return result;
}
