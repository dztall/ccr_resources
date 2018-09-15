#include "encoding_arm_structures.h"
#include "psuedosyntax.h"
#include "encoding_arm_cond.h"
// instructions will be in alphabetical order hopefully
// a b c d e f g h i j k l m n o p q r s t u v w x y z
void decode(char * instruction, char * type, char * encoding) {
	APSR  = encoding;
	extract(cond, encoding, 31, 28);
	ifc {
		if (ConditionPassed(cond)) conditionalcolour
	}
	printf("%s ", instruction);
	if (type) printf("(%s) ", type);
	
	if (!strcmp(instruction, "B")) {
		int32_t imm32 = SIGN_EXTEND(32,23, string_to_bin(32, encoding+shift_by_bits32(2)));
		printf(" 0x%x ", imm32);
	}
	else if (!strcmp(instruction, "RSB")) {
		if (type) {
			if (!strcmp(type, "register")) {
				// A8-578
				// RSB{S} <Rd>, <Rn>, <Rm>{, <shift>}
				int32_t S = binary(20, 20, encoding);
				uint32_t Rd = (uint32_t) binary(15, 12, encoding);
				uint32_t Rn = (uint32_t) binary(19, 16, encoding);
				uint32_t imm5 = (uint32_t) binary(11, 7, encoding);
				extract(imm5S, encoding, 11, 7);
				uint32_t type = (uint32_t) binary(6, 5, encoding);
				extract(typeS, encoding, 6, 5);
				uint32_t Rm = (uint32_t) binary(3, 0, encoding);
				if (Rn == binary(0, 4, "1111") && S == binary(0,0,"1")) printf("see SUBS, PC, LR, and related instructions ");
				printf("{%u} <%u> <%u> <%u>{, <shift> (type=%s,imm5=%s)}", S, Rd, Rn, Rm, typeS, imm5S);
			}
		}
	}
	else if (!strcmp(instruction, "SVC")) {
		int32_t imm32 = ZERO_EXTEND(32,23,string_to_bin(32, encoding));
		printf(" #0x%x ", imm32);
	}
	ifc printf(colors_RESET);
	printf("(");
	if (ConditionPassed(cond)) conditionaltext
	printf(")");
	if (disassembler_decode_cond) {
		puts("");
		program_info(encoding);
	}
}
