#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include "varg.h"
#include <ctype.h>
#include "cpu_definitions.h"
#include "../Shell/builtins/printfmacro.h"
#include "../Shell/builtins/env.h"
#define EVAL_TYPE int
#include "eval11/evaldefs.h"
#include "eval11/evalkern.c"
#include "eval11/evalwrap.c"

// add_instruction              // add
// add_instruction_operands     // r1, r2, r3 
// add_instruction_operations   // r3 = r1 + r2
// add_instruction_opcode       //

// note instructions CAN contain IMPLICIT registers, such as x86's SAHF and LAHF, aswell as CLC and STC, in which case any registers that are included in the operations but are not specified in the operands shall be IMPLICIT and shall NOT be required

// add_instruction              // add
// add_instruction_operands     // r1, r2  ; implicit r3 register
// add_instruction_operations   // r3 = r1 + r2  ; implicit r3 register
// add_instruction_opcode       //

struct instruction {
    char *  instruction;
    char ** instruction_operands;
    int     instruction_operand_count;
    char *  instruction_operations;
    char ** instruction_implicit_operands;
    int     instruction_implicit_count;
    int     internal_bank_count;
};

// steps in dynamically creating a new instruction

// step 1. create an instruction bank
#define instruction_new_bank(x) struct instruction * x = NULL;

void instruction_delete_bank(struct instruction ** instruction_bank) {
    if (*instruction_bank != NULL) {
        for (int bank = 0; bank < (*instruction_bank)[0].internal_bank_count; bank++) {
            if ((*instruction_bank)[bank].instruction) {
                (*instruction_bank)[bank].instruction = NULL;
            }
            if((*instruction_bank)[bank].instruction_operands) env__free((*instruction_bank)[bank].instruction_operands);
            if ((*instruction_bank)[bank].instruction_operations) {
                (*instruction_bank)[bank].instruction_operations = NULL;
            }
            if((*instruction_bank)[bank].instruction_implicit_operands) env__free((*instruction_bank)[bank].instruction_implicit_operands);
        }
        (*instruction_bank)[0].internal_bank_count = 0;
        free(*instruction_bank);
    }
}

// step 2. register an instruction to the instruction bank, this shall be searched for when assembling and queueing instructions aswell as disassembling
void instruction_add(struct instruction ** instruction_bank, char * instr) {
    if (*instruction_bank == NULL) {
        *instruction_bank = malloc(50*sizeof(struct instruction)); // create 50 structure pointers
        for (int i = 0; i < 50; i++) {
        	(*instruction_bank)[i].instruction = NULL;
        	(*instruction_bank)[i].instruction_operands = NULL;
        	(*instruction_bank)[i].instruction_operand_count = 0;
        	(*instruction_bank)[i].instruction_operations = NULL;
        	(*instruction_bank)[i].instruction_implicit_operands = NULL;
        	(*instruction_bank)[i].instruction_implicit_count = 0;
        	(*instruction_bank)[i].internal_bank_count = 0;
        }
    }
    (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction = instr;
    (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operand_count = 0;
    (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_implicit_count = 0;
}

// step 3. register operands to the instruction specified
void instruction_add_operands(struct instruction ** instruction_bank, char * instr, char * operands) {
    if (!(*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands) (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands = env__new();
    char * assembly1 = strdup(operands);
    for (char * tok1 = strtok(assembly1, ", "); tok1; tok1 = strtok(NULL, ", ")) {
    	(*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands = env__add((*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands, tok1);
        (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operand_count++;
    }
    free(assembly1);
}

// step 4. register operations to the instruction specified
void instruction_add_operations(struct instruction ** instruction_bank, char * instr, char * operations) {
    (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operations = operations;
    
    // figure out IMPLICIT operands
    
    // step 1. gather needed information
    // we use our shell's env functions to handle allocation for us
    (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_implicit_operands = env__new();
    char ** tokens2 = env__new();
    char * assembly2 = strdup((*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operations);
    for (char * tok2 = strtok(assembly2, " "); tok2; tok2 = strtok(NULL, " ")) {
        tokens2 = env__add(tokens2, tok2);
    }
    free(assembly2);
    // step 2. determine what parts are IMPLICIT
    for (int i = 0; i < env__size(tokens2); i++) {
        int m = 0;
        for (int ii = 0; ii < env__size((*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands); ii++) {
            if (strcmp((*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands[ii], tokens2[i]) < 0) {
                m++;
            }
        }
        if (m == env__size((*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_operands)) {
            (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_implicit_operands = env__add((*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_implicit_operands, tokens2[i]);
            (*instruction_bank)[(*instruction_bank)[0].internal_bank_count].instruction_implicit_count++;
        }
    }
    env__free(tokens2);
}


void instruction_finalize(struct instruction ** instruction_bank) {
    (*instruction_bank)[0].internal_bank_count++;
}

void instruction_info(struct instruction * instruction_bank, int instruction_bank_index) {
    puts("----instruction bank information start----");
    ps(instruction_bank[instruction_bank_index].instruction);
    pi(instruction_bank[instruction_bank_index].instruction_operand_count);
    if (instruction_bank[instruction_bank_index].instruction_operand_count) {
        puts("instruction_bank[instruction_bank_index].instruction_operands:");
        env__list(instruction_bank[instruction_bank_index].instruction_operands);
    }
    ps(instruction_bank[instruction_bank_index].instruction_operations);
    pi(instruction_bank[instruction_bank_index].instruction_implicit_count);
    if (instruction_bank[instruction_bank_index].instruction_implicit_count) {
        puts("instruction_bank[instruction_bank_index].instruction_implicit_operands:");
        env__list(instruction_bank[instruction_bank_index].instruction_implicit_operands);
    }
    puts("-----instruction bank information end-----");
}

int get_bank_index(struct instruction * instruction_bank, char * ins) {
    for (int bank = 0; bank < instruction_bank[0].internal_bank_count; bank++) {
        if (strcmp(instruction_bank[bank].instruction, ins) == 0) return bank;
    }
    return -1;
}

// step 5. build an opcode from the specified instruction

unsigned char * bin2str_(uint8_t bin) {
    return readbin_(&bin, 8);
}

uint8_t str2bin_(unsigned char * str) {
    return string_to_bin(8, str);
}

/*      SYNTAX
 * 
 * syntax shall be a custom syntax, merge of AT&T, INTEL, and my own, intended to be easy to write and read/understand, at the compromize of code density
 * every item shall be prefixed with a meaningfull type identifier suffixed with an optional type
 * 
 * example:
 * 
 * instruction_add decimal_long_5 register_r1   ; add 5 long into register r1
 * instruction_mov decimal_hex_0xff register_r1 ; move decimal value of the hex value 0xff into register r1 
 *                                              ; alternative: (move 255 decimal into register r1)
 */

int str_isdigit(char * str) {
    while (str && *str) {
        if (!isdigit((unsigned)*str)) return 0;
        str++;
    }
    return 1;
}

#define parsedo(x,str) \
    if (!operr) {\
        if (opc > x-1) {\
            int isnum = 0;\
            char * type = malloc(50);\
            char * tmp2 = strdup(tokens1[x-1]);\
            char * tmp = strtok(tmp2, "_");\
            if(str_isdigit(tmp)) {\
                isnum = 1;\
                sprintf(type, "type_%s", "number");\
            } else {\
                sprintf(type, "type_%s", tmp);\
            }\
            char * i_ty##x = env__get(table_encoding, type);\
            if (i_ty##x) opcode_structure[internal_parser_index].ty##x = *i_ty##x;\
            else {\
                printf("error: invalid token: %s, skipping parsing this line: %s\n", tmp,str);\
                opcode_structure[internal_parser_index].ty##x = 0x0;\
                opcode_structure_clear(internal_parser_index);\
                operr=1;\
            }\
            free(type);\
            if (isnum) {\
                opcode_structure[internal_parser_index].op##x = atoi(tmp);\
            } else {\
                char * i_op##x;\
                i_op##x = env__get(table_encoding, tokens1[x-1]);\
                if (i_op##x) opcode_structure[internal_parser_index].op##x = *i_op##x;\
                else opcode_structure[internal_parser_index].op##x = 0x0;\
            }\
            free(tmp2);\
        } else {\
            opcode_structure[internal_parser_index].op##x = 0x0;\
        }\
    }

void parse(char ** table_encoding, char * str) {
    if (!table_encoding) {
        puts("error: encoding table is not defined, please define one");
        return;
    }
    if (!opcode_structure) {
        opcode_structure = malloc(50*sizeof(struct opcode)); // create 50 structure pointers
        memset(opcode_structure, 0, 50);
    }
    // step 1. gather needed information
    // we use our shell's env functions cus fuck manually reallocating
    char ** tokens1 = env__new();
    char * assembly1 = strdup(str);
    char * inst = strdup(strtok(assembly1, " "));
    for (char * tok1 = strtok(NULL, ", "); tok1; tok1 = strtok(NULL, ", ")) {
        tokens1 = env__add(tokens1, tok1);
    }
    free(assembly1);
    char * i_ins = env__get(table_encoding, inst);
    if (i_ins) opcode_structure[internal_parser_index].ins = *i_ins;
    else opcode_structure[internal_parser_index].ins = 0x0;
    int opc = env__size(tokens1);
    if (opc == 0) abort();
    else {
        int operr=0;
        parsedo(1, str);
        parsedo(2, str);
        parsedo(3, str);
    }
    free(inst);
    env__free(tokens1);
    internal_parser_index++;
}

char * bitfind(uint8_t bit, char ** table) {
    for (int i = 0; i < env__size(table); i++) {
        char * tmp2 = strdup(table[i]);
        strtok(tmp2, "=");
        if (bit == *env__get(table, tmp2)) return tmp2;
        free(tmp2);
    }
    return NULL;
}

// You must free the result if result is non-NULL.
char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

#define cpu_disassemble_info(x, str) \
                if (instruction_bank[bank].instruction_operand_count > x-1) {\
                    t = bitfind(opcode_structure[index].ty##x, table_types);\
                    if (t) {\
                        if (strcmp(t, type_register) == 0) {\
                            val = bitfind(opcode_structure[index].op##x, table_registers);\
                            if (val) {\
                                if (str) {\
                                    char * str2 = str_replace(str, instruction_bank[bank].instruction_operands[x-1], val);\
                                    free(str);\
                                    str = str2;\
                                }\
                                printf("%s, ", val);\
                                free(val);\
                            }\
                        } else if (strcmp(t, type_number) == 0) {\
                            char * v = malloc(100);\
                            sprintf(v, "%d", opcode_structure[index].op##x);\
                            if (str) {\
                                char * str2 = str_replace(str, instruction_bank[bank].instruction_operands[x-1], v);\
                                free(str);\
                                str = str2;\
                            }\
                            printf("%s, ", v);\
                            free(v);\
                        }\
                        free(t);\
                    } else {\
                        puts("error: expected operand");\
                        return 0;\
                    }\
                }

int cpu_disassemble(char ** table_instructions, char ** table_types, char ** table_registers, struct instruction * instruction_bank, int index, char ** str) {
    // attempt to decode a structure
    if (!table_instructions) {
        puts("error: instructions table is not defined, please define one");
        return 0;
    }
    if (!table_types) {
        puts("error: types table is not defined, please define one");
        return 0;
    }
    if (!table_registers) {
        puts("error: registers table is not defined, please define one");
        return 0;
    }
    if (!instruction_bank) {
        puts("warning: instruction bank is not defined, decoding ability will be limited");
    }
    
    
    char * i;
    char * t;
    char * val;
    
    i = bitfind(opcode_structure[index].ins, table_instructions);
    if (i) {
        if (instruction_bank) {
            // first obtain an index to the structure
            int bank = get_bank_index(instruction_bank, i);
            if (bank != -1) {
                printf("%s ", i);
                free(i);
                // next print the instruction bank information for the aquired index
                instruction_info(instruction_bank, bank);
                if (str) {
                    *str = malloc(strlen(instruction_bank[bank].instruction_operations)+512);
                    strcpy(*str, instruction_bank[bank].instruction_operations);
                    cpu_disassemble_info(1, *str)
                    cpu_disassemble_info(2, *str)
                    cpu_disassemble_info(3, *str)
                } else {
                    cpu_disassemble_info(1, str)
                    cpu_disassemble_info(2, str)
                    cpu_disassemble_info(3, str)
                }
                printf("\b\b \n");
            } else {
                puts("warning: desired instruction was not found in instruction bank, decoding ability will be limited");
                printf("%s ", i);
                free(i);
            }
        } else {
            printf("%s ", i);
            free(i);
        }
    } else {
        puts("error: expected instruction");
        return 0;
    }

    return 1;
}

int cpu_decode(char ** table_instructions, char ** table_types, char ** table_registers, struct instruction * instruction_bank, int index) {
    // attempt to decode a structure
    if (!table_instructions) {
        puts("error: instructions table is not defined, please define one");
        return 0;
    }
    if (!table_types) {
        puts("error: types table is not defined, please define one");
        return 0;
    }
    if (!table_registers) {
        puts("error: registers table is not defined, please define one");
        return 0;
    }
    if (!instruction_bank) {
        puts("warning: instruction bank is not defined, decoding ability will be limited");
    }
    char * s;
    if (cpu_disassemble(table_instructions, table_types, table_registers, instruction_bank, index, &s)) {
        char * i;
        char * t;
        char * val;
        
        i = bitfind(opcode_structure[index].ins, table_instructions);
        if (i) {
            if (instruction_bank) {
                // i can be decoded
                // first obtain an index to the structure
                int bank = get_bank_index(instruction_bank, i);
                free(i);
                if (bank != -1) {
                    // attempt to decode the operation
                    if (s) {
                        ps(s)
                        
                        int err = evaluateExpression(s);
                        free(s);
                        for (int i = 0; i < nVariables; i++) printf("%s = %i;\n", variable[i].name, *variable[i].valueptr);
                        if (err) {
                            fprintf(stderr,"File %s: %s at line %d, column %d\n", "stdin", errorRecord.message, errorRecord.line, errorRecord.column);
                        }
                        
                    }
                }
            }
        }
    } else {
        puts("error: invalid instruction");
        return 0;
    }
    return 1;
}
