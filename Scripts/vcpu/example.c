#include <gc.h>
#include "cpu_language.h"

void setup_decoding_information(struct instruction ** instruction_bank) {
    instruction_add(instruction_bank, "instruction_add");
    instruction_add_operands(instruction_bank, "instruction_add", "a, b"); // if this step is omitted all registers in the operations shall become IMPLICIT
    instruction_add_operations(instruction_bank, "instruction_add", "register_r3 = a + b");
    instruction_finalize(instruction_bank);
    
    instruction_add(instruction_bank, "instruction_add3");
    instruction_add_operands(instruction_bank, "instruction_add3", "a, b, c"); // if this step is omitted all registers in the operations shall become IMPLICIT
    instruction_add_operations(instruction_bank, "instruction_add3", "a = (b * c) + c; a += (c*c)*a");
    instruction_finalize(instruction_bank);

    instruction_add(instruction_bank, "instruction_mov");
    instruction_add_operands(instruction_bank, "instruction_mov", "register_r1, register_r2"); // if this step is omitted all registers in the operations shall become IMPLICIT
    instruction_add_operations(instruction_bank, "instruction_mov", "register_r2 = register_r1");
    instruction_finalize(instruction_bank);
}

int main()
{
    char ** table_instructions;
    char ** table_types;
    char ** table_registers;
    char ** table_encoding;
    init_table(&table_instructions, &table_types, &table_registers, &table_encoding);
    instruction_new_bank(test);
    setup_decoding_information(&test);
    parse(table_encoding, "instruction_mov 19, register_r1");
    /*
    puts("writing from opcode_structure to testcpuwrite");
    opcode_structure_write("testcpuwrite", "a+");
    opcode_structure_clear_all();
    puts("reading from testcpuwrite into opcode_structure");
    opcode_structure_read("testcpuwrite");
    opcode_structure_print_all();
    */
    cpu_decode(table_encoding, table_types, table_registers, test, 0);
    opcode_structure_clear_all();
    instruction_delete_bank(&test);
    denit_table(&table_instructions, &table_types, &table_registers, &table_encoding);
    return 0;
}
