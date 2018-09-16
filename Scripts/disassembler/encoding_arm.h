#include "decoder_arm.h"

bool disassembler_instruction_only = false;

// since encodings can reference other encodings, each encoding shall be a function

// template definitions
#define egenaa32(x,y) encodings_arm_arch_32_##x (char * y)
#define euseaa32(x,y) encodings_arm_arch_32_##x (y)

void egenaa32(base,e);
void egenaa32(data_processing_and_miscellaneous_instructions, e);
void egenaa32(data_processing__register_, e);
void egenaa32(data_processing__register_shifted_register_, e);
void egenaa32(data_processing__immediate_, e);
void egenaa32(modified_immediate_constants_in_ARM_instructions, e);
void egenaa32(multiply_and_multiply_accumulate, e);
void egenaa32(saturating_addition_and_subtraction, e);
void egenaa32(halfword_multiply_and_multiply_accumulate, e);
void egenaa32(extra_load_store_instructions, e);
void egenaa32(extra_load_store_instructions__unprivileged, e);
void egenaa32(synchronization_primitives, e);
void egenaa32(MSR__immediate___and_hints, e);
void egenaa32(miscellaneous_instructions, e);
void egenaa32(load_store_word_and_unsigned_byte, e);
void egenaa32(media_instructions, e);
void egenaa32(signed_parallel_addition_and_subtraction_instructions, e);
void egenaa32(unsigned_parallel_addition_and_subtraction_instructions, e);
void egenaa32(packing__unpacking__saturation__and_reversal_instructions, e);
void egenaa32(signed_multiply__signed_and_unsigned_divide_instructions, e);
void egenaa32(branch__branch_with_link__and_block_data_transfer, e);
void egenaa32(coprocessor_instructions_and_supervisor_call, e);
void egenaa32(unconditional_instructions, e);
void egenaa32(memory_hints__advanced_simd_instructions__and_miscellaneous_instructions, e);

void egenaa32(base,e) {
	// where all opcodes stem from
	ifregexEngine("31-28,not 1111", e) {
		ifregexEngine("27-25,00x,4,-", e) euseaa32(data_processing_and_miscellaneous_instructions, e);
		else ifregexEngine("27-25,010,4,-", e) euseaa32(load_store_word_and_unsigned_byte, e);
		else ifregexEngine("27-25,011", e) {
			ifregexEngine("4,0", e) euseaa32(load_store_word_and_unsigned_byte, e);
			else ifregexEngine("4,1", e) euseaa32(media_instructions, e);
		}
		else ifregexEngine("27-25,10x,4,-", e) euseaa32(branch__branch_with_link__and_block_data_transfer, e);
		else ifregexEngine("27-25,11x,4,-", e) euseaa32(coprocessor_instructions_and_supervisor_call, e);
	}
	else ifregexEngine("31-28,1111,27-25,-,4,-", e) euseaa32(unconditional_instructions, e);
}

void egenaa32(data_processing_and_miscellaneous_instructions, e) {
	if (!disassembler_instruction_only) printf("data processing and miscellaneous instructions > ");
	ifregexEngine("25,0", e) {
		ifregexEngine("24-20,not 10xx0", e) {
			ifregexEngine("7-4,xxx0", e) euseaa32(data_processing__register_, e);
			else ifregexEngine("7-4,0xx1", e) euseaa32(data_processing__register_shifted_register_, e);
		}
		else ifregexEngine("24-20,10xx0", e) {
			ifregexEngine("7-4,0xxx", e) euseaa32(miscellaneous_instructions, e);
			else ifregexEngine("7-4,xxx1", e) euseaa32(halfword_multiply_and_multiply_accumulate, e);
		}
		else ifregexEngine("24-20,0xxxx", e) {
			ifregexEngine("7-4,1001", e) euseaa32(multiply_and_multiply_accumulate, e);
		}
		else ifregexEngine("24-20,1xxxx", e) {
			ifregexEngine("7-4,1001", e) euseaa32(synchronization_primitives, e);
		}
		else ifregexEngine("24-20,not 0xx1x", e) {
			ifregexEngine("7-4,1011", e) euseaa32(extra_load_store_instructions, e);
			else ifregexEngine("7-4,11x1", e) euseaa32(extra_load_store_instructions, e);
		}
		else ifregexEngine("24-20,0xx10", e) {
			ifregexEngine("7-4,11x0", e) euseaa32(extra_load_store_instructions, e);
		}
		else ifregexEngine("24-20,0xx1x", e) {
			ifregexEngine("7-4,1011", e) euseaa32(extra_load_store_instructions__unprivileged, e);
		}
		else ifregexEngine("24-20,0xx11", e) {
			ifregexEngine("7-4,11x0", e) euseaa32(extra_load_store_instructions__unprivileged, e);
		}
	}
	else ifregexEngine("25,1", e) {
		ifregexEngine("24-20,not 10xx0", e) euseaa32(data_processing__immediate_, e);
		else ifregexEngine("24-20,10000", e) decode("MOV", NULL, e);
		else ifregexEngine("24-20,10100", e) decode("MOVT", NULL, e);
		else ifregexEngine("24-20,10x10", e) euseaa32(MSR__immediate___and_hints, e);
	}
}

void egenaa32(data_processing__register_, e) {
	if (!disassembler_instruction_only) printf("data-processing (register) > ");
		 ifregexEngine("24-20,0000x", e) decode("AND", "register", e);
	else ifregexEngine("24-20,0001x", e) decode("EOR", "register", e);
	else ifregexEngine("24-20,0010x", e) decode("SUB", "register", e);
	else ifregexEngine("24-20,0011x", e) decode("RSB", "register", e);
	else ifregexEngine("24-20,0100x", e) decode("ADD", "register, ARM", e);
	else ifregexEngine("24-20,0101x", e) decode("ADC", "register", e);
	else ifregexEngine("24-20,0110x", e) decode("SBC", "register", e);
	else ifregexEngine("24-20,0111x", e) decode("RSC", "register", e);
	else ifregexEngine("24-20,10xx0", e) euseaa32(data_processing_and_miscellaneous_instructions, e);
	else ifregexEngine("24-20,10001", e) decode("TST", "register", e);
	else ifregexEngine("24-20,10011", e) decode("TEQ", "register", e);
	else ifregexEngine("24-20,10101", e) decode("CMP", "register", e);
	else ifregexEngine("24-20,10111", e) decode("CMN", "register", e);
	else ifregexEngine("24-20,1100x", e) decode("ORR", "register", e);
	else ifregexEngine("24-20,1101x", e) {
		ifregexEngine("6-5,00", e) {
				 ifregexEngine("11-7,00000", e) decode("MOV", "register, ARM", e);
			else ifregexEngine("11-7,not 00000", e) decode("LSL", "immediate", e);
		}
		else ifregexEngine("6-5,01", e) decode("LSR", "immediate", e);
		else ifregexEngine("6-5,10", e) decode("ASR", "immediate", e);
		else ifregexEngine("6-5,11", e) {
				 ifregexEngine("11-7,00000", e) decode("RRX", NULL, e);
			else ifregexEngine("11-7,not 00000", e) decode("ROR", "immediate", e);
		}
	}
	else ifregexEngine("24-20,1110x", e) decode("BIC", "register", e);
	else ifregexEngine("24-20,1111x", e) decode("MVN", "register", e);
}

void egenaa32(data_processing__register_shifted_register_, e) {
	if (!disassembler_instruction_only) printf("data-processing (register-shifted register) > ");
		 ifregexEngine("24-20,0000x", e) decode("AND", NULL, e);
	else ifregexEngine("24-20,0001x", e) decode("EOR", NULL, e);
	else ifregexEngine("24-20,0010x", e) decode("SUB", NULL, e);
	else ifregexEngine("24-20,0011x", e) decode("RSB", NULL, e);
	else ifregexEngine("24-20,0100x", e) decode("ADD", NULL, e);
	else ifregexEngine("24-20,0101x", e) decode("ADC", NULL, e);
	else ifregexEngine("24-20,0110x", e) decode("SBC", NULL, e);
	else ifregexEngine("24-20,0111x", e) decode("RSC", NULL, e);
	else ifregexEngine("24-20,10xx0", e) euseaa32(data_processing_and_miscellaneous_instructions, e);
	else ifregexEngine("24-20,10001", e) decode("TST", NULL, e);
	else ifregexEngine("24-20,10011", e) decode("TEQ", NULL, e);
	else ifregexEngine("24-20,10101", e) decode("CMP", NULL, e);
	else ifregexEngine("24-20,10111", e) decode("CMN", NULL, e);
	else ifregexEngine("24-20,1100x", e) decode("ORR", NULL, e);
	else ifregexEngine("24-20,1101x", e) {
		ifregexEngine("6-5,00", e) decode("LSL", NULL, e);
		else ifregexEngine("6-5,01", e) decode("LSR", NULL, e);
		else ifregexEngine("6-5,10", e) decode("ASR", NULL, e);
		else ifregexEngine("6-5,11", e) decode("ROR", NULL, e);
	}
	else ifregexEngine("24-20,1110x", e) decode("BIC", NULL, e);
	else ifregexEngine("24-20,1111x", e) decode("MVN", NULL, e);
}

void egenaa32(data_processing__immediate_, e) {
	if (!disassembler_instruction_only) printf("data-processing (immediate) > ");
		 ifregexEngine("24-20,0000x", e) decode("AND", NULL, e);
	else ifregexEngine("24-20,0001x", e) decode("EOR", NULL, e);
	else ifregexEngine("24-20,0010x", e) {
			 ifregexEngine("19-16,not 1111", e) decode("SUB", NULL, e);
		else ifregexEngine("19-16,1111", e) decode("ADR", NULL, e);
	}
	else ifregexEngine("24-20,0011x", e) decode("RSB", NULL, e);
	else ifregexEngine("24-20,0100x", e) {
			 ifregexEngine("19-16,not 1111", e) decode("ADD", NULL, e);
		else ifregexEngine("19-16,1111", e) decode("ADR", NULL, e);
	}
	else ifregexEngine("24-20,0101x", e) decode("ADC", NULL, e);
	else ifregexEngine("24-20,0110x", e) decode("SBC", NULL, e);
	else ifregexEngine("24-20,0111x", e) decode("RSC", NULL, e);
	else ifregexEngine("24-20,10xx0", e) euseaa32(data_processing_and_miscellaneous_instructions, e);
	else ifregexEngine("24-20,10001", e) decode("TST", NULL, e);
	else ifregexEngine("24-20,10011", e) decode("TEQ", NULL, e);
	else ifregexEngine("24-20,10101", e) decode("CMP", NULL, e);
	else ifregexEngine("24-20,10111", e) decode("CMN", NULL, e);
	else ifregexEngine("24-20,1100x", e) decode("ORR", NULL, e);
	else ifregexEngine("24-20,1101x", e) decode("MOV", NULL, e);
	else ifregexEngine("24-20,1110x", e) decode("BIC", NULL, e);
	else ifregexEngine("24-20,1111x", e) decode("MVN", NULL, e);
	// the instructions above all have modified immediate constants, rather than a simple 12-bit binary number. This provides a more useful range of values
	euseaa32(modified_immediate_constants_in_ARM_instructions, e);
}

void egenaa32(modified_immediate_constants_in_ARM_instructions, e) {
	// rotation: 11-8
	// a b c d e f g h : 7 6 5 4 3 2 1 0
	// we will deal with this later
}

void egenaa32(multiply_and_multiply_accumulate, e) {
	if (!disassembler_instruction_only) printf("Multiply and multiply accumulator > ");
		 ifregexEngine("23-20,000x", e) decode("MUL", NULL, e);
	else ifregexEngine("23-20,001x", e) decode("MLA", NULL, e);
	else ifregexEngine("23-20,0100", e) decode("UMAAL", NULL, e);
	else ifregexEngine("23-20,0101", e) decode("Undefined", NULL, e);
	else ifregexEngine("23-20,0110", e) decode("MLS", NULL, e);
	else ifregexEngine("23-20,0111", e) decode("Undefined", NULL, e);
	else ifregexEngine("23-20,100x", e) decode("UMULL", NULL, e);
	else ifregexEngine("23-20,101x", e) decode("UMLAL", NULL, e);
	else ifregexEngine("23-20,110x", e) decode("SMULL", NULL, e);
	else ifregexEngine("23-20,111x", e) decode("SMLAL", NULL, e);
}

void egenaa32(saturating_addition_and_subtraction, e) {
	if (!disassembler_instruction_only) printf("Saturating addition and subtraction > ");
		 ifregexEngine("22-21,00", e) decode("QADD", NULL, e);
	else ifregexEngine("22-21,01", e) decode("QSUB", NULL, e);
	else ifregexEngine("22-21,10", e) decode("QDADD", NULL, e);
	else ifregexEngine("22-21,11", e) decode("QDSUB", NULL, e);
}

void egenaa32(halfword_multiply_and_multiply_accumulate, e) {
	if (!disassembler_instruction_only) printf("Halfword multiply and multiply accumulate > ");
		 ifregexEngine("22-21,00", e) decode("SMLABB,SMLABT,SMLATB,SMLATT", NULL, e);
	else ifregexEngine("22-21,01", e) {
			 ifregexEngine("6,0", e) decode("SMLAWB,SMLAWT", NULL, e);
		else ifregexEngine("6,0", e) decode("SMULWB,SMULWT", NULL, e);
	}
	else ifregexEngine("22-21,10", e) decode("SMLALBB,SMLALBT,SMLALTB,SMLALTT", NULL, e);
	else ifregexEngine("22-21,11", e) decode("SMULBB,SMULBT,SMULTB,SMULTT", NULL, e);
}

void egenaa32(extra_load_store_instructions, e) {
	if (!disassembler_instruction_only) printf("Extra load/store instructions > ");
	ifregexEngine("6-5,01", e) {
		ifregexEngine("24-20,xx0x0", e) decode("STRH", NULL, e);
		else ifregexEngine("24-20,xx0x1", e) decode("LDRH", NULL, e);
		else ifregexEngine("24-20,xx1x0", e) decode("STRH", NULL, e);
		else ifregexEngine("24-20,xx1x1", e) {
				 ifregexEngine("19-16,not 1111", e) decode("LDRH", NULL, e);
			else ifregexEngine("19-16,1111", e) decode("LDRH", NULL, e);
		}
	}
	else ifregexEngine("6-5,10", e) {
		ifregexEngine("24-20,xx0x0", e) decode("LDRH", NULL, e);
		else ifregexEngine("24-20,xx0x1", e) decode("LDRSB", NULL, e);
		else ifregexEngine("24-20,xx1x0", e) {
				 ifregexEngine("19-16,not 1111", e) decode("LDRD", NULL, e);
			else ifregexEngine("19-16,1111", e) decode("LDRD", NULL, e);
		}
		else ifregexEngine("24-20,xx1x1", e) {
				 ifregexEngine("19-16,not 1111", e) decode("LDRSB", NULL, e);
			else ifregexEngine("19-16,1111", e) decode("LDRSB", NULL, e);
		}
	}
	else ifregexEngine("6-5,11", e) {
		ifregexEngine("24-20,xx0x0", e) decode("STRD", NULL, e);
		else ifregexEngine("24-20,xx0x1", e) decode("LDRSH", NULL, e);
		else ifregexEngine("24-20,xx1x0", e) decode("STRD", NULL, e);
		else ifregexEngine("24-20,xx1x1", e) {
				 ifregexEngine("19-16,not 1111", e) decode("LDRSH", NULL, e);
			else ifregexEngine("19-16,1111", e) decode("LDRSH", NULL, e);
		}
	}
}

void egenaa32(extra_load_store_instructions__unprivileged, e) {
	if (!disassembler_instruction_only) printf("Extra load/store instructions, unprivileged > ");
	ifregexEngine("6-5,01", e) {
		ifregexEngine("20,0", e) decode("STRHT", NULL, e);
		else ifregexEngine("20,1", e) decode("LDRHT", NULL, e);
	}
	else ifregexEngine("6-5,10", e) {
		ifregexEngine("20,1", e) decode("LDRSBT", NULL, e);
	}
	else ifregexEngine("6-5,11", e) {
		ifregexEngine("20,1", e) decode("LDRSHT", NULL, e);
	}
}

void egenaa32(synchronization_primitives, e) {
	if (!disassembler_instruction_only) printf("Synchronization primitives > ");
	ifregexEngine("23-20,0x00", e) decode("SWP,SWPB", NULL, e);
	else ifregexEngine("23-20,1000", e) decode("STREX", NULL, e);
	else ifregexEngine("23-20,1001", e) decode("LDREX", NULL, e);
	else ifregexEngine("23-20,1010", e) decode("STREXD", NULL, e);
	else ifregexEngine("23-20,1011", e) decode("LDREXD", NULL, e);
	else ifregexEngine("23-20,1100", e) decode("STREXB", NULL, e);
	else ifregexEngine("23-20,1101", e) decode("LDREXB", NULL, e);
	else ifregexEngine("23-20,1110", e) decode("STREXH", NULL, e);
	else ifregexEngine("23-20,1111", e) decode("LDREXH", NULL, e);
}

void egenaa32(MSR__immediate___and_hints, e) {
	if (!disassembler_instruction_only) printf("MSR (immediate), and hints > ");
	ifregexEngine("22,0", e) {
		ifregexEngine("19-16,0000", e) {
			ifregexEngine("7-0,00000000", e) decode("NOP", NULL, e);
			else ifregexEngine("7-0,00000001", e) decode("YEILD", NULL, e);
			else ifregexEngine("7-0,00000010", e) decode("WFE", NULL, e);
			else ifregexEngine("7-0,00000011", e) decode("WFI", NULL, e);
			else ifregexEngine("7-0,00000100", e) decode("SEV", NULL, e);
			else ifregexEngine("7-0,00010100", e) decode("CSDB", NULL, e);
			else ifregexEngine("7-0,1111xxxx", e) decode("DBG", NULL, e);
		}
		else ifregexEngine("19-16,0100", e) decode("MSR", NULL, e);
		else ifregexEngine("19-16,1x00", e) decode("RESERVED, SHOULD NOT BE USED", NULL, e);
		else ifregexEngine("19-16,xx01", e) decode("MSR", NULL, e);
		else ifregexEngine("19-16,xx1x", e) decode("RESERVED, SHOULD NOT BE USED", NULL, e);
	}
	else ifregexEngine("22,1", e) decode("MSR", NULL, e);
}

void egenaa32(miscellaneous_instructions, e) {
	if (!disassembler_instruction_only) printf("miscellaneous instructions > ");
	ifregexEngine("6-4,000", e) {
		ifregexEngine("9,1", e) {
			ifregexEngine("22-21,x0", e) {
				ifregexEngine("19-16,xxxx", e) decode("MRS", NULL, e);
			}
			else ifregexEngine("22-21,x1", e) {
				ifregexEngine("19-16,xxxx", e) decode("MSR", NULL, e);
			}
		}
		else ifregexEngine("9,0", e) {
			ifregexEngine("22-21,x0", e) {
				ifregexEngine("19-16,xxxx", e) decode("MRS", NULL, e);
			}
			else ifregexEngine("22-21,01", e) {
				ifregexEngine("19-16,xx00", e) decode("MSR", NULL, e);
				ifregexEngine("19-16,xx01", e) decode("MSR", NULL, e);
				ifregexEngine("19-16,xx1x", e) decode("MSR", NULL, e);
			}
			else ifregexEngine("22-21,11", e) decode("MSR", NULL, e);
		}
	}
	else ifregexEngine("6-4,001", e) {
		ifregexEngine("22-21,01", e) decode("BX", NULL, e);
		else ifregexEngine("22-21,11", e) decode("CLZ", NULL, e);
	}
	else ifregexEngine("6-4,010", e) {
		ifregexEngine("22-21,01", e) decode("BXJ", NULL, e);
	}
	else ifregexEngine("6-4,011", e) {
		ifregexEngine("22-21,01", e) decode("BLX", NULL, e);
	}
	else ifregexEngine("6-4,101", e) euseaa32(saturating_addition_and_subtraction, e);
	else ifregexEngine("6-4,110", e) {
		ifregexEngine("22-21,11", e) decode("ERET", NULL, e);
	}
	else ifregexEngine("6-4,111", e) {
		ifregexEngine("22-21,01", e) decode("BKPT", NULL, e);
		else ifregexEngine("22-21,10", e) decode("HVC", NULL, e);
		else ifregexEngine("22-21,11", e) decode("SMC", NULL, e);
	}
}

void egenaa32(load_store_word_and_unsigned_byte, e) {
	if (!disassembler_instruction_only) printf("Load/store word and unsigned byte > ");
	ifregexEngine("25,0",e) {
		ifregexEngine("24-20,xx0x0 not 0x010",e) decode("STR", NULL, e);
		else ifregexEngine("24-20,0x010",e) decode("STRT", NULL, e);
		else ifregexEngine("24-20,xx0x1 not 0x011",e) {
			ifregexEngine("19-16,not 1111",e) decode("LDR", NULL, e);
			else ifregexEngine("19-16,1111",e) decode("LDR", NULL, e);
		}
		else ifregexEngine("24-20,0x011",e) decode("LDRT", NULL, e);
		else ifregexEngine("24-20,xx1x0	not 0x110",e) decode("STRB", NULL, e);
		else ifregexEngine("24-20,0x110",e) decode("STRBT", NULL, e);
		else ifregexEngine("24-20,xx1x1 not 0x111",e) {
			ifregexEngine("19-16,not 1111",e) decode("LDRB", NULL, e);
			else ifregexEngine("19-16,1111",e) decode("LDRB", NULL, e);
		}
		else ifregexEngine("24-20,0x111",e) decode("LDRBT", NULL, e);
	}
	else ifregexEngine("25,1",e) {
		ifregexEngine("4,1",e) euseaa32(media_instructions, e);
		else ifregexEngine("24-20,xx0x0 not 0x010,4,0",e) decode("STR", NULL, e);
		else ifregexEngine("24-20,0x010,4,0",e) decode("STRT", NULL, e);
		else ifregexEngine("24-20,xx0x1 not 0x011,4,0",e) decode("LDR", NULL, e);
		else ifregexEngine("24-20,0x011,4,0",e) decode("LDRT", NULL, e);
		else ifregexEngine("24-20,xx1x0	not 0x110,4,0",e) decode("STRB", NULL, e);
		else ifregexEngine("24-20,0x110,4,0",e) decode("STRBT", NULL, e);
		else ifregexEngine("24-20,xx1x1 not 0x111,4,0",e) decode("LDRB", NULL, e);
		else ifregexEngine("24-20,0x111,4,0",e) decode("LDRBT", NULL, e);
	}
}

void egenaa32(media_instructions, e) {
	if (!disassembler_instruction_only) printf("Media instructions > ");
	ifregexEngine("24-20,000xx",e) {}
	else ifregexEngine("24-20,000xx",e) euseaa32(signed_parallel_addition_and_subtraction_instructions, e);
	else ifregexEngine("24-20,001xx",e) euseaa32(unsigned_parallel_addition_and_subtraction_instructions, e);
	else ifregexEngine("24-20,01xxx",e) euseaa32(packing__unpacking__saturation__and_reversal_instructions, e);
	else ifregexEngine("24-20,10xxx",e) euseaa32(signed_multiply__signed_and_unsigned_divide_instructions, e);
	else ifregexEngine("24-20,11000,7-5,000",e) {
		ifregexEngine("3-0,1111",e) decode("USAD8", NULL, e);
		else ifregexEngine("3-0,not 1111",e) decode("USADA8", NULL, e);
	}
	else ifregexEngine("24-20,1101x,7-5,x10",e) decode("SBFX", NULL, e);
	else ifregexEngine("24-20,1110x,7-5,x00",e) {
		ifregexEngine("3-0,1111",e) decode("BFC", NULL, e);
		else ifregexEngine("3-0,not 1111",e) decode("BFI", NULL, e);
	}
	else ifregexEngine("24-20,1111x,7-5,x10",e) decode("UBFX", NULL, e);
	else ifregexEngine("24-20,11111,7-5,111",e) {
		ifregexEngine("31-28,1110",e) decode("UDF", NULL, e);
		else ifregexEngine("31-28,not 1110",e) decode("-a", NULL, e);
	}
}

void egenaa32(signed_parallel_addition_and_subtraction_instructions, e) {
	if (!disassembler_instruction_only) printf("Signed parallel addition and subtraction instructions > ");
	ifregexEngine("7-6,000", e) {
		ifregexEngine("21-20,01", e) decode("SADD16", NULL, e);
		else ifregexEngine("21-20,10", e) decode("QADD16", NULL, e);
		else ifregexEngine("21-20,11", e) decode("SHADD16", NULL, e);
	}
	else ifregexEngine("7-6,001", e) {
		ifregexEngine("21-20,01", e) decode("SASX", NULL, e);
		else ifregexEngine("21-20,10", e) decode("QASX", NULL, e);
		else ifregexEngine("21-20,11", e) decode("SHASX", NULL, e);
	}
	else ifregexEngine("7-6,010", e) {
		ifregexEngine("21-20,01", e) decode("SSAX", NULL, e);
		else ifregexEngine("21-20,10", e) decode("QSAX", NULL, e);
		else ifregexEngine("21-20,11", e) decode("SHSAX", NULL, e);
	}
	else ifregexEngine("7-6,011", e) {
		ifregexEngine("21-20,01", e) decode("SSUB16", NULL, e);
		else ifregexEngine("21-20,10", e) decode("QSUB16", NULL, e);
		else ifregexEngine("21-20,11", e) decode("SHSUB16", NULL, e);
	}
	else ifregexEngine("7-6,100", e) {
		ifregexEngine("21-20,01", e) decode("SADD8", NULL, e);
		else ifregexEngine("21-20,10", e) decode("QADD8", NULL, e);
		else ifregexEngine("21-20,11", e) decode("SHADD8", NULL, e);
	}
	else ifregexEngine("7-6,111", e) {
		ifregexEngine("21-20,01", e) decode("SSUB8", NULL, e);
		else ifregexEngine("21-20,10", e) decode("QSUB8", NULL, e);
		else ifregexEngine("21-20,11", e) decode("SHSUB8", NULL, e);
	}
	
}

void egenaa32(unsigned_parallel_addition_and_subtraction_instructions, e) {
	if (!disassembler_instruction_only) printf("Unsigned parallel addition and subtraction instructions > ");
	ifregexEngine("7-6,000", e) {
		ifregexEngine("21-20,01", e) decode("UADD16", NULL, e);
		else ifregexEngine("21-20,10", e) decode("UQADD16", NULL, e);
		else ifregexEngine("21-20,11", e) decode("UHADD16", NULL, e);
	}
	else ifregexEngine("7-6,001", e) {
		ifregexEngine("21-20,01", e) decode("UASX", NULL, e);
		else ifregexEngine("21-20,10", e) decode("UQASX", NULL, e);
		else ifregexEngine("21-20,11", e) decode("UHASX", NULL, e);
	}
	else ifregexEngine("7-6,010", e) {
		ifregexEngine("21-20,01", e) decode("USAX", NULL, e);
		else ifregexEngine("21-20,10", e) decode("UQSAX", NULL, e);
		else ifregexEngine("21-20,11", e) decode("UHSAX", NULL, e);
	}
	else ifregexEngine("7-6,011", e) {
		ifregexEngine("21-20,01", e) decode("USUB16", NULL, e);
		else ifregexEngine("21-20,10", e) decode("UQSUB16", NULL, e);
		else ifregexEngine("21-20,11", e) decode("UHSUB16", NULL, e);
	}
	else ifregexEngine("7-6,100", e) {
		ifregexEngine("21-20,01", e) decode("UADD8", NULL, e);
		else ifregexEngine("21-20,10", e) decode("UQADD8", NULL, e);
		else ifregexEngine("21-20,11", e) decode("UHADD8", NULL, e);
	}
	else ifregexEngine("7-6,111", e) {
		ifregexEngine("21-20,01", e) decode("USUB8", NULL, e);
		else ifregexEngine("21-20,10", e) decode("UQSUB8", NULL, e);
		else ifregexEngine("21-20,11", e) decode("UHSUB8", NULL, e);
	}
}

void egenaa32(packing__unpacking__saturation__and_reversal_instructions, e) {
	if (!disassembler_instruction_only) printf("Packing, unpacking, saturation, and reversal instructions > ");
	ifregexEngine("7-5,011",e) {
		ifregexEngine("19-16, not 1111",e) {
			ifregexEngine("22-20,000",e) decode("SXTAB16", NULL, e);
			else ifregexEngine("22-20,010",e) decode("SXTAB", NULL, e);
			else ifregexEngine("22-20,011",e) decode("SXTAH", NULL, e);
			else ifregexEngine("22-20,100",e) decode("UXTAB16", NULL, e);
			else ifregexEngine("22-20,110",e) decode("UXTAB", NULL, e);
			else ifregexEngine("22-20,111",e) decode("UXTAH", NULL, e);
		}
		else ifregexEngine("19-16, 1111",e) {
			ifregexEngine("22-20,000",e) decode("SXTB16", NULL, e);
			else ifregexEngine("22-20,010",e) decode("SXTB", NULL, e);
			else ifregexEngine("22-20,011",e) decode("SXTH", NULL, e);
			else ifregexEngine("22-20,100",e) decode("UXTB16", NULL, e);
			else ifregexEngine("22-20,110",e) decode("UXTB", NULL, e);
			else ifregexEngine("22-20,111",e) decode("UXTH", NULL, e);
		}
	}
	else ifregexEngine("22-20,000",e) {
		ifregexEngine("7-5,xx0",e) decode("PKH", NULL, e);
		else ifregexEngine("7-5,101",e) decode("SEL", NULL, e);
	}
	else ifregexEngine("22-20,01x,7-5,xx0",e) decode("SSAT", NULL, e);
	else ifregexEngine("22-20,010,7-5,001",e) decode("SSAT16", NULL, e);
	else ifregexEngine("22-20,011",e) {
		ifregexEngine("7-5,001",e) decode("REV", NULL, e);
		else ifregexEngine("7-5,101",e) decode("REV16", NULL, e);
	}
	else ifregexEngine("22-20,11x,7-5,xx0",e) decode("USAT", NULL, e);
	else ifregexEngine("22-20,110,7-5,001",e) decode("USAT16", NULL, e);
	else ifregexEngine("22-20,111",e) {
		ifregexEngine("7-5,001",e) decode("RBIT", NULL, e);
		else ifregexEngine("7-5,101",e) decode("REVSH", NULL, e);
	}
}

void egenaa32(signed_multiply__signed_and_unsigned_divide_instructions, e) {
	if (!disassembler_instruction_only) printf("Signed multiply, signed and unsigned divide instructions > ");
	ifregexEngine("15-12, not 1111",e) {
		ifregexEngine("22-20,000",e) {
			ifregexEngine("7-5,00x",e) decode("SMLAD", NULL, e);
			else ifregexEngine("7-5,01x",e) decode("SMLSD", NULL, e);
		}
		else ifregexEngine("22-20,101,7-5,00x",e) decode("SMMLA", NULL, e);
	}
	else ifregexEngine("15-12,1111",e) {
		ifregexEngine("22-20,000",e) {
			ifregexEngine("7-5,00x",e) decode("SMUAD", NULL, e);
			else ifregexEngine("7-5,01x",e) decode("SMUSD", NULL, e);
		}
		else ifregexEngine("22-20,101,7-5,00x",e) decode("SMMUL", NULL, e);
	}
	else ifregexEngine("22-20,001,7-5,000",e) decode("SDIV", NULL, e);
	else ifregexEngine("22-20,011,7-5,000",e) decode("UDIV", NULL, e);
	ifregexEngine("22-20,100",e) {
		ifregexEngine("7-5,00x",e) decode("SMLALD", NULL, e);
		else ifregexEngine("7-5,01x",e) decode("SMLSLD", NULL, e);
	}
	else ifregexEngine("22-20,101,7-5,11x",e) decode("SMMLS", NULL, e);
}

void egenaa32(branch__branch_with_link__and_block_data_transfer, e) {
	if (!disassembler_instruction_only) printf("Branch, branch with link, and block data transfer instructions > ");
	ifregexEngine("25-20,0000x0",e) decode("STMDA (STMED)", NULL, e);
	else ifregexEngine("25-20,0000x1",e) decode("LDMDA/LDMFA", NULL, e);
	else ifregexEngine("25-20,0010x0",e) decode("STM (STMIA, STMEA)", NULL, e);
	else ifregexEngine("25-20,001001",e) decode("LDM/LDMIA/LDMFD (ARM)", NULL, e);
	else ifregexEngine("25-20,001011",e) {
		ifregexEngine("19-16,not 1101",e) decode("LDM/LDMIA/LDMFD (ARM)", NULL, e);
		else ifregexEngine("19-16,1101",e) decode("POP (ARM)", NULL, e);
	}
	else ifregexEngine("25-20,010000",e) decode("STMDB (STMFD)", NULL, e);
	else ifregexEngine("25-20,010010",e) {
		ifregexEngine("19-16,not 1101",e) decode("STMDB (STMFD)", NULL, e);
		else ifregexEngine("19-16,1101",e) decode("PUSH (ARM)", NULL, e);
	}
	else ifregexEngine("25-20,0100x1",e) decode("LDMDB/LDMEA", NULL, e);
	else ifregexEngine("25-20,0110x0",e) decode("STMIB (STMFA)", NULL, e);
	else ifregexEngine("25-20,0110x1",e) decode("LDMIB/LDMED", NULL, e);
	else ifregexEngine("25-20,0xx1x0",e) decode("STM", NULL, e);
	else ifregexEngine("25-20,0xx1x1",e) {
		ifregexEngine("15,0",e) decode("LDM", NULL, e);
		else ifregexEngine("15,1",e) decode("LDM", NULL, e);
	}
	else ifregexEngine("25-20,10xxxx",e) decode("B", NULL, e);
	else ifregexEngine("25-20,11xxxx",e) decode("BL, BLX", NULL, e);
}

void egenaa32(coprocessor_instructions_and_supervisor_call, e) {
	if (!disassembler_instruction_only) printf("Coprocessor instructions and supervisor call > ");
	ifregexEngine("25-20,00000x",e) decode("UNDEFINED", NULL, e);
	else ifregexEngine("25-20,11xxxx",e) decode("SVC", NULL, e);
	else ifregexEngine("11-8,not 101x",e) {
		ifregexEngine("25-20,0xxxx0 not 000x00",e) decode("STC, STC2", NULL, e);
		else ifregexEngine("25-20,0xxxx1 not 000x01",e) {
			ifregexEngine("19-16,not 1111",e) decode("LDC, LDC2", NULL, e);
			else ifregexEngine("19-16,1111",e) decode("LDC, LDC2", NULL, e);
		}
		else ifregexEngine("25-20,000100",e) decode("MCRR, MCRR2", NULL, e);
		else ifregexEngine("25-20,000101",e) decode("MRRC, MRRC2", NULL, e);
		else ifregexEngine("25-20,10xxxx,4,0",e) decode("CDP, CDP2", NULL, e);
		else ifregexEngine("25-20,10xxx0,4,1",e) decode("MCR, MCR2", NULL, e);
		else ifregexEngine("25-20,10xxx1,4,1",e) decode("MRC, MRC2", NULL, e);
	}
	else ifregexEngine("11-8,101x",e) {
		ifregexEngine("25-20,0xxxx0 not 000x00",e) printf("see Extention register load/store instructions on page 272");
		else ifregexEngine("25-20,00010x",e) printf("see 64-bit transfers between ARM core and extention registers on page 277");
		else ifregexEngine("25-20,10xxxx",e) {
			ifregexEngine("4,0",e) printf("see Floating-point data-processing instructions on page 270");
			else ifregexEngine("4,1",e) printf("see 8, 16, and 32-bit transfers between ARM core and extention registers on page 276");
		}
	}
}

void egenaa32(unconditional_instructions, e) {
	if (!disassembler_instruction_only) printf("Unconditional instructions > ");
	ifregexEngine("27-20,0xxxxxxx",e) euseaa32(memory_hints__advanced_simd_instructions__and_miscellaneous_instructions, e);
	else ifregexEngine("27-20,100xx1x0",e) decode("SRS (ARM)", NULL, e);
	else ifregexEngine("27-20,100xx0x1",e) decode("RFE", NULL, e);
	else ifregexEngine("27-20,101xxxxx",e) decode("BL,BLX", NULL, e);
	else ifregexEngine("27-20,110xxxx0 not 11000x00",e) decode("STC, STC2", NULL, e);
	else ifregexEngine("27-20,110xxxx1 not 11000x01",e) {
		ifregexEngine("19-16,not 1111",e) decode("LDC, LDC2", NULL, e);
		else ifregexEngine("19-16,1111",e) decode("LDC, LDC2", NULL, e);
	}
	else ifregexEngine("25-20,11000100",e) decode("MCRR, MCRR2", NULL, e);
	else ifregexEngine("25-20,11000101",e) decode("MRRC, MRRC2", NULL, e);
	else ifregexEngine("25-20,1110xxxx,4,0",e) decode("CDP, CDP2", NULL, e);
	else ifregexEngine("25-20,1110xxx0,4,1",e) decode("MCR, MCR2", NULL, e);
	else ifregexEngine("25-20,1110xxx1,4,1",e) decode("MRC, MRC2", NULL, e);
}

void egenaa32(memory_hints__advanced_simd_instructions__and_miscellaneous_instructions, e) {
	if (!disassembler_instruction_only) printf("Memory hints, Advanced SIMD instructions, and miscellaneous instructions > ");
	ifregexEngine("26-20,0010000",e) {
		ifregexEngine("19-16,xxx0,7-4,xx0x",e) decode("CPS", NULL, e);
		else ifregexEngine("19-16,xxx1,7-4,0000",e) decode("SETEND", NULL, e);
	}
	else ifregexEngine("26-20,0010010,7-4,0111",e) decode("UNPREDICTABLE", NULL, e);
	else ifregexEngine("26-20,01xxxxx",e) printf("see Advanced SIMD data-processing instructions on page 259");
	else ifregexEngine("26-20,100xxx0",e) printf("see Advanced SIMD element or structure load/store instructions on page 273");
	else ifregexEngine("26-20,100x001,",e) decode("NOP", NULL, e);
	else ifregexEngine("26-20,100x101,",e) decode("PLI", NULL, e);
	else ifregexEngine("26-20,100xx11,",e) decode("UNPREDICTABLE", NULL, e);
	else ifregexEngine("26-20,101x001,",e) {
		ifregexEngine("19-16,not 1111",e) decode("PLD, PLDW", NULL, e);
		else ifregexEngine("19-16,1111",e) decode("UNPREDICTABLE", NULL, e);
	}
	else ifregexEngine("26-20,101x101,",e) {
		ifregexEngine("19-16,not 1111",e) decode("PLD, PLDW", NULL, e);
		else ifregexEngine("19-16,1111",e) decode("PLD", NULL, e);
	}
	else ifregexEngine("26-20,1010011",e) decode("UNPREDICTABLE", NULL, e);
	else ifregexEngine("26-20,1010111",e) {
		ifregexEngine("19-16,0000",e) decode("UNPREDICTABLE", NULL, e);
		else ifregexEngine("19-16,0001",e) decode("CLREX", NULL, e);
		else ifregexEngine("19-16,001x",e) decode("UNPREDICTABLE", NULL, e);
		else ifregexEngine("19-16,0100",e) decode("DSB", NULL, e);
		else ifregexEngine("19-16,0101",e) decode("DMB", NULL, e);
		else ifregexEngine("19-16,0110",e) decode("ISB", NULL, e);
		else ifregexEngine("19-16,0111",e) decode("UNPREDICTABLE", NULL, e);
		else ifregexEngine("19-16,1xxx",e) decode("UNPREDICTABLE", NULL, e);
	}
	else ifregexEngine("26-20,1011x11",e) decode("UNPREDICTABLE", NULL, e);
	else ifregexEngine("26-20,110x001,19-16,xxx0",e) decode("NOP", NULL, e);
	else ifregexEngine("26-20,110x101,19-16,xxx0",e) decode("PLI", NULL, e);
	else ifregexEngine("26-20,111x001,19-16,xxx0",e) decode("PLD, PLDW", NULL, e);
	else ifregexEngine("26-20,111x101,19-16,xxx0",e) decode("PLD, PLDW", NULL, e);
	else ifregexEngine("26-20,11xxx11,19-16,xxx0",e) decode("UNPREDICTABLE", NULL, e);
	else ifregexEngine("26-20,1111111,19-16,1111",e) decode("Permanently UNDEFINED", NULL, e);
}


void read_encoding_arm_regexEngine(unsigned char * bit) {
	char * e = readbin(bit, 32);
	regexEngine_Debug = false;
	regexEngine_max_bit_length = 32;
	regexEngine_bit_start = 31;
	euseaa32(base, e);
	free(e);
}
