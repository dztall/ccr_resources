#include "varg.h"
#include "cpu_language.h"
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define CPU_TYPE unsigned int
#define CPU_TYPE_ADD 1
#define CPU_POWER_ON true
#define CPU_POWER_OFF false
#define null_int(x) x = 0
#define null_custom(x, y) x = y

struct virtual_cpu_register_bank {
    int r1;
    int r2;
    int r3;
    int32_t pc;
    char * name;
    CPU_TYPE type;
};

struct virtual_cpu_sub_core {
    struct virtual_cpu_register_bank virtual_register;
    int op;
    int status;
    char * name;
};

struct virtual_cpu_core {
    struct virtual_cpu_sub_core previous;
    struct virtual_cpu_sub_core current;
    int status;
    int power;
    char * cpu_power_state[2];
    char * name;
    bool init;
};

struct virtual_cpu {
    int core_count;
    struct virtual_cpu_core *core;
    struct Queue *q;
    char ** table_instructions;
    char ** table_types;
    char ** table_registers;
    char ** table_encoding;
    struct instruction * instruction_bank;
    char * name;
} cpu_default;

void setup_decoding_information(struct instruction ** instruction_bank) {
    instruction_add(instruction_bank, "instruction_add");
    instruction_add_operands(instruction_bank, "instruction_add", "register_r1, register_r2"); // if this step is omitted all registers in the operations shall become IMPLICIT
    instruction_add_operations(instruction_bank, "instruction_add", "register_r3 = register_r1 + register_r2");
    instruction_finalize(instruction_bank);
    
    instruction_add(instruction_bank, "instruction_add3");
    instruction_add_operands(instruction_bank, "instruction_add3", "register_r3, register_r1, register_r2"); // if this step is omitted all registers in the operations shall become IMPLICIT
    instruction_add_operations(instruction_bank, "instruction_add3", "register_r3 = (register_r1 * register_r2) + register_r2");
    instruction_finalize(instruction_bank);

    instruction_add(instruction_bank, "instruction_mov");
    instruction_add_operands(instruction_bank, "instruction_mov", "register_r1, register_r2"); // if this step is omitted all registers in the operations shall become IMPLICIT
    instruction_add_operations(instruction_bank, "instruction_mov", "register_r2 = register_r1");
    instruction_finalize(instruction_bank);
}


void cpu_register_info_minimal(struct virtual_cpu_register_bank *virtual_register);
void virtual_cpu_check(struct virtual_cpu *cpu);
void cpu_register_info(struct virtual_cpu *cpu, struct virtual_cpu_core *core, struct virtual_cpu_sub_core *sub_core, struct virtual_cpu_register_bank *virtual_register);
void cpu_sub_core_info(struct virtual_cpu *cpu, struct virtual_cpu_core *core, struct virtual_cpu_sub_core *sub_core);
void cpu_core_info(struct virtual_cpu *cpu, struct virtual_cpu_core *core);
void cpu_info(struct virtual_cpu *cpu);
void cpu_core_start(struct virtual_cpu_core *core);
void cpu_start(struct virtual_cpu *cpu);
void cpu_core_shutdown(struct virtual_cpu_core *core);
void cpu_shutdown(struct virtual_cpu *cpu);
struct QNode* newNode(char * string);
struct Queue *createQueue();
void store_asm(struct Queue *q, char * string);
struct QNode * load_asm(struct Queue *q);
int cpu_queue_add(char * string);
void virtual_cpu_register_check(struct virtual_cpu_register_bank *reg, char * name);
void virtual_cpu_sub_core_check(struct virtual_cpu_sub_core * core, char * name);
void virtual_cpu_core_check(struct virtual_cpu_core *core, char * name);
void cpu_add(int register_input1, int register_input2, int * register_out);
void cpu_action_init(void);
void cpu_execute(struct virtual_cpu *cpu);
void cpu_deinit(struct virtual_cpu *cpu);
void cpu_core_init(struct virtual_cpu *cpu, int max_cores);


void cpu_register_info_minimal(struct virtual_cpu_register_bank *virtual_register) {
    printf("VIRTUAL CPU: INFO : register bank name: %s\n", virtual_register->name);
    printf("VIRTUAL CPU: INFO : size of %s: %zu\n", virtual_register->name, sizeof(*virtual_register));
    printf("VIRTUAL CPU: INFO : %s : r1:   %d\n", virtual_register->name, virtual_register->r1);
    printf("VIRTUAL CPU: INFO : %s : r2:   %d\n", virtual_register->name, virtual_register->r2);
    printf("VIRTUAL CPU: INFO : %s : r3:   %d\n", virtual_register->name, virtual_register->r3);
    printf("VIRTUAL CPU: INFO : %s : pc:   %d\n", virtual_register->name, virtual_register->pc);
    printf("VIRTUAL CPU: INFO : %s : name: %s\n", virtual_register->name, virtual_register->name);
}

void cpu_register_info(struct virtual_cpu *cpu, struct virtual_cpu_core *core, struct virtual_cpu_sub_core *sub_core, struct virtual_cpu_register_bank *virtual_register) {
    printf("VIRTUAL CPU: INFO : %s : %s : %s : register bank name: %s\n", cpu->name, core->name, sub_core->name, virtual_register->name);
    printf("VIRTUAL CPU: INFO : %s : %s : %s : size of %s: %zu\n", cpu->name, core->name, sub_core->name, virtual_register->name, sizeof(*virtual_register));
    printf("VIRTUAL CPU: INFO : %s : %s : %s : %s : r1: %d\n", cpu->name, core->name, sub_core->name, virtual_register->name, virtual_register->r1);
    printf("VIRTUAL CPU: INFO : %s : %s : %s : %s : r2: %d\n", cpu->name, core->name, sub_core->name, virtual_register->name, virtual_register->r2);
    printf("VIRTUAL CPU: INFO : %s : %s : %s : %s : r3: %d\n", cpu->name, core->name, sub_core->name, virtual_register->name, virtual_register->r3);
    printf("VIRTUAL CPU: INFO : %s : %s : %s : %s : pc: %d\n", cpu->name, core->name, sub_core->name, virtual_register->name, virtual_register->pc);
}

void cpu_sub_core_info(struct virtual_cpu *cpu, struct virtual_cpu_core *core, struct virtual_cpu_sub_core *sub_core) {
    printf("VIRTUAL CPU: INFO : %s : %s : sub core name: %s\n", cpu->name, core->name, sub_core->name);
    printf("VIRTUAL CPU: INFO : %s : %s : size of %s: %zu\n", cpu->name, core->name, sub_core->name, sizeof(*sub_core));
    cpu_register_info(cpu, core, sub_core, &sub_core->virtual_register);
}

void cpu_core_info(struct virtual_cpu *cpu, struct virtual_cpu_core *core) {
    printf("VIRTUAL CPU: INFO : %s : core name:  %s\n", cpu->name, core->name);
    printf("VIRTUAL CPU: INFO : %s : size of %s: %zu\n", cpu->name, core->name, 
           sizeof(*core)-
           sizeof(core->cpu_power_state)+
           (
               sizeof(core->cpu_power_state)*env__size(core->cpu_power_state)
           )
    );
    printf("VIRTUAL CPU: INFO : %s : %s : cpu power status: %s\n", cpu->name, core->name, core->cpu_power_state[core->power]);
    printf("VIRTUAL CPU: INFO : %s : %s : status:           %d\n", cpu->name, core->name, core->status);
    cpu_sub_core_info(cpu, core, &core->previous);
    cpu_sub_core_info(cpu, core, &core->current);
}

void cpu_info(struct virtual_cpu *cpu) {
    virtual_cpu_check(cpu);
    printf("VIRTUAL CPU: INFO : cpu name:         %s\n", cpu->name);
    printf("VIRTUAL CPU: INFO : cpu cores:        %d\n", cpu->core_count);
    printf
    (
        "VIRTUAL CPU: INFO : size of %s: %zu\n", cpu->name,
        (
            sizeof(*cpu)-
            (
                sizeof(cpu->q)+
                sizeof(cpu->core)+
                sizeof(cpu->table_instructions)+
                sizeof(cpu->table_types)+
                sizeof(cpu->table_registers)+
                sizeof(cpu->table_encoding)+
                sizeof(cpu->instruction_bank)
            )+
            (
                (
                    sizeof(cpu->core[0])-
                    sizeof(cpu->core[0].cpu_power_state)+
                    (
                        sizeof(cpu->core[0].cpu_power_state)*env__size(cpu->core[0].cpu_power_state)
                    )
                ) * cpu->core_count
            )
        ) +
        (
            sizeof(cpu->table_instructions) * env__size(cpu->table_instructions)+
            sizeof(cpu->table_types) *env__size(cpu->table_types)+
            sizeof(cpu->table_registers) * env__size(cpu->table_registers)+
            sizeof(cpu->table_encoding) * env__size(cpu->table_encoding)+
            sizeof(*cpu->instruction_bank) * env__size(&cpu->instruction_bank)
        )
    );
    printf("VIRTUAL CPU: INFO : size of instruction table: %zu\n", sizeof(cpu->table_instructions)  * env__size(cpu->table_instructions));
    printf("VIRTUAL CPU: INFO : size of types table:       %zu\n", sizeof(cpu->table_types)         * env__size(cpu->table_types));
    printf("VIRTUAL CPU: INFO : size of registers table:   %zu\n", sizeof(cpu->table_registers)     * env__size(cpu->table_registers));
    printf("VIRTUAL CPU: INFO : size of encoding table:    %zu\n", sizeof(cpu->table_encoding)      * env__size(cpu->table_encoding));
    printf("VIRTUAL CPU: INFO : size of instruction bank:  %zu\n", sizeof(*cpu->instruction_bank)   * env__size(&cpu->instruction_bank));
    for (int i = 0; i < 1; i++) cpu_core_info(cpu, &cpu->core[i]);
}

void cpu_core_start(struct virtual_cpu_core *core) {
    printf("VIRTUAL CPU: starting virtual cpu core:      %s\n", core->name);
    core->power = CPU_POWER_ON;
}

void cpu_start(struct virtual_cpu *cpu) {
    puts("VIRTUAL CPU: performing startup check");
    virtual_cpu_check(cpu);
    puts("VIRTUAL CPU: startup check complete");
    printf("VIRTUAL CPU: starting virtual cpu:      %s\n", cpu->name);
    Expression_Assign("register_r1", &cpu->core[0].current.virtual_register.r1);
    Expression_Assign("register_r2", &cpu->core[0].current.virtual_register.r2);
    Expression_Assign("register_r3", &cpu->core[0].current.virtual_register.r3);
    init_table(&cpu->table_instructions, &cpu->table_types, &cpu->table_registers, &cpu->table_encoding);
    setup_decoding_information(&cpu->instruction_bank);
    cpu_core_start(&cpu->core[0]);
}

void cpu_core_shutdown(struct virtual_cpu_core *core) {
    printf("VIRTUAL CPU: shutting down virtual cpu core: %s\n", core->name);
    core->power = CPU_POWER_OFF;
}

void cpu_shutdown(struct virtual_cpu *cpu) {
    puts("VIRTUAL CPU: performing shutdown check");
    virtual_cpu_check(cpu);
    puts("VIRTUAL CPU: shutdown check complete");
    printf("VIRTUAL CPU: shutting down virtual cpu:      %s\n", cpu->name);
    denit_table(&cpu->table_instructions, &cpu->table_types, &cpu->table_registers, &cpu->table_encoding);
    instruction_delete_bank(&cpu->instruction_bank);
    opcode_structure_clear_all();
    internal_parser_index = 0;
    Expression_Assign_free();
    cpu_core_shutdown(&cpu->core[0]);
    cpu_deinit(cpu);
}

// A C program to demonstrate linked list based implementation of queue 
// A linked list (LL) node to store a queue entry
struct QNode
{
    char * assembly;
    struct QNode *next;
};
 
// The queue, front stores the front node of LL and rear stores ths
// last node of LL
struct Queue
{
    struct QNode *front, *rear;
};
 
// A utility function to create a new linked list node.
struct QNode* newNode(char * string)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->assembly = string;
    temp->next = NULL;
    return temp; 
}
 
// A utility function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void store_asm(struct Queue *q, char * string)
{
    // Create a new LL node
    struct QNode *temp = newNode(string);
 
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       return;
    }
 
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
 
struct QNode * load_asm(struct Queue *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
       return NULL;
 
    // Store previous front and move front one node ahead
    struct QNode *temp = q->front;
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}

void virtual_cpu_register_check(struct virtual_cpu_register_bank *reg, char * name) {
    null_int(reg->r1);
    null_int(reg->r2);
    null_int(reg->r3);
    null_int(reg->pc);
    null_custom(reg->name, name);
    null_int(reg->type);
}

void virtual_cpu_sub_core_check(struct virtual_cpu_sub_core * core, char * name) {
    virtual_cpu_register_check(&core->virtual_register, "register");
    null_int(core->op);
    null_int(core->status);
    null_custom(core->name, name);
}

// a cpu part shall be considered uninitialized if has a value of zero [ 0 ]
void virtual_cpu_core_check(struct virtual_cpu_core *core, char * name) {
    if (core->init == true) return;
    virtual_cpu_sub_core_check(&core->previous, "PREVIOUS");
    virtual_cpu_sub_core_check(&core->current, "CURRENT");
    null_int(core->status);
    null_int(core->power);
    null_custom(core->cpu_power_state[0], "OFF");
    null_custom(core->cpu_power_state[1], "ON");
    null_custom(core->name, name);
    core->init = true;
}

void cpu_core_init(struct virtual_cpu *cpu, int max_cores) {
    if (cpu->core) return;
    cpu->core = malloc(max_cores*sizeof(struct virtual_cpu_core));
    for (int i = 0; i < max_cores; i++) {
        char * name = malloc(100);
        snprintf(name, 100, "Core %d", i);
        virtual_cpu_core_check(&cpu->core[i], name);
    }
    cpu->core_count = max_cores;
}

void cpu_deinit(struct virtual_cpu *cpu) {
    if (!cpu->core) return;
    for (int i = 0; i < cpu->core_count; i++) {
        free(cpu->core[i].name);
    }
    free(cpu->core);
    free(cpu->q);
    cpu->core_count = 0;
}

void virtual_cpu_check(struct virtual_cpu *cpu) {
    cpu_action_init();
    cpu_core_init(cpu, 32);
    null_custom(cpu->name, "cpu_default");
}

struct virtual_cpu_action {
    bool init;
    void (*add)(int, int, int*);
} cpu_action;

// shall add the contents of one register to another register
void cpu_add(int register_input1, int register_input2, int * register_out) {
    *register_out = register_input1 + register_input2;
}

void cpu_action_init(void) {
    if (cpu_action.init) return;
    null_custom(cpu_action.add, cpu_add);
}

int cpu_queue_add(char * string) {
    if (!cpu_default.q) cpu_default.q = createQueue();
    store_asm(cpu_default.q, string);
    return 0;
}

// cpu shall backup current to previous in order to have a restore point, then take changes from que and commit them to current
void cpu_execute(struct virtual_cpu *cpu) {
    puts("attempting to execute instruction list");
    // obtain the first added instruction
    struct QNode * node = malloc(1); // this gets freed anyway
    int instructions = 0;
    while (node != NULL) {
        // drain the list until empty
        free(node);
        node = load_asm(cpu->q);
        if (node == NULL) break;
        parse(cpu->table_encoding, node->assembly);
        cpu_decode(cpu->table_instructions, cpu->table_types, cpu->table_registers, cpu->instruction_bank, cpu->core[0].current.virtual_register.pc);
        cpu->core[0].current.virtual_register.pc++;
        instructions++;
    }
    if (instructions == 0) puts("i have no instruction to execute");
    else puts("i have no instructions left to execute");
}

int main()
{
    cpu_info(&cpu_default);
    cpu_start(&cpu_default);
    cpu_queue_add("instruction_mov 19, register_r1");
    cpu_queue_add("instruction_mov 1, register_r2");
    cpu_queue_add("instruction_add register_r1, register_r2");
    cpu_queue_add("instruction_add3 register_r3, register_r3, register_r3");
    cpu_execute(&cpu_default);
    cpu_queue_add("instruction_mov 1, register_r2");
    cpu_execute(&cpu_default);
    cpu_execute(&cpu_default);
    cpu_info(&cpu_default);
    cpu_shutdown(&cpu_default);
    return 0;
}
