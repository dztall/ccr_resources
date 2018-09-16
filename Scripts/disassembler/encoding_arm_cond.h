
bool disassembler_decode_cond = false;

void decode_cond(char * ME, char * MI, char * MFP, char * CF) {
	if (disassembler_decode_cond) printf("Mnemomic extention: %s\nMeaning (integer): %s\nMeaning (floating point){a}: %s\na. Unordered means at least one NaN operand\nCondition flags: %s\n", ME, MI, MFP, CF);
}

void process_cond(char * cond);

void program_info(char * e) {
	APSR_info(e);
	CPSR_info(e);
	extract(cond, e, 31, 28);
	ps(cond)
	process_cond(cond);
}

#define conditionaltext printf("conditional execution passes"); else printf("conditional execution fails");
#define conditionalcolour printf(colors_GREEN); else printf(colors_RED);


void process_cond(char * cond) {
	bool result;
	if (strcmp(cond, "0000") == 0) {
		decode_cond("EQ", "Equal", "Equal", "Z == 1");
		result = (APSR->Z == '1');
	}
	else if (strcmp(cond, "0001") == 0) {
		decode_cond("NE", "Not equal", "Not equal, or unordered", "Z == 0");
		result = (APSR->Z == '0');
	}
	else if (strcmp(cond, "0010") == 0) {
		decode_cond("CS{b}\nb. HS (unsigned higher or same) is a synonym for CS", "Carry Set", "Greater than, equal, or unordered", "C == 1");
		result = (APSR->C == '1');
	}
	else if (strcmp(cond, "0011") == 0) {
		decode_cond("CC{c}\nc. LO (unsigned lower) is a synonym for CC", "Carry clear", "Less than", "C == 0");
		result = (APSR->C == '0');
	}
	else if (strcmp(cond, "0100") == 0) {
		decode_cond("MI", "Minus, negative", "Less than", "N == 1");
		result = (APSR->N == '1');
	}
	else if (strcmp(cond, "0101") == 0) {
		decode_cond("PL", "Plus, positive, or zero", "Greater than, equal, or unordered", "N == O");
		result = (APSR->N == '0');
	}
	else if (strcmp(cond, "0110") == 0) {
		decode_cond("VS", "Overflow", "Unordered", "V == 1");
		result = (APSR->V == '1');
	}
	else if (strcmp(cond, "0111") == 0) {
		decode_cond("VC", "No overflow", "Not unordered", "V == 0");
		result = (APSR->V == '0');
	}
	else if (strcmp(cond, "1000") == 0) {
		decode_cond("HI", "Unsigned higher", "Greater than, or unordered", "C == 1 and Z == 0");
		result = (APSR->C == '1' && APSR->Z == '0');
	}
	else if (strcmp(cond, "1001") == 0) {
		decode_cond("LS", "Unsigned lower or same", "Less than or equal", "C == 0 and Z == 1");
		result = (APSR->C == '0' && APSR->Z == '1');
	}
	else if (strcmp(cond, "1010") == 0) {
		decode_cond("GE", "Signed greater than or equal", "Greater than or equal", "N == V");
		result = (APSR->N == APSR->V);
	}
	else if (strcmp(cond, "1011") == 0) {
		decode_cond("LT", "Signed less than", "Less than, or unordered", "N != V");
		result = (APSR->N != APSR->V);
	}
	else if (strcmp(cond, "1100") == 0) {
		decode_cond("GT", "Signed greater than", "Greater than", "Z == 0 and N == V");
		result = (APSR->Z == '0' && APSR->N == APSR->V);
	}
	else if (strcmp(cond, "1101") == 0) {
		decode_cond("LE", "Signed less than or equal", "Less than, equal, or unordered", "Z == 1 or N != V");
		result = (APSR->Z == '1' || APSR->N != APSR->V);
	}
	else if (strcmp(cond, "1110") == 0) {
		decode_cond("None (AL){d}\nd. AL is an optional mnemonic extention for always, except in IT instructions", "Always (unconditional)", "Always (unconditional)", "Any");
		result = true;
	}
	else {}
	if(cond[3] == '1' && strcmp(cond, "1111") == -1) result = !result;
	if (result) conditionaltext
}
