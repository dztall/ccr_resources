#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#ifdef __CPP__

typedef char *va_list;

inline char *__va_aligned__2(char *p, int align)
{
	int alignLocal = 8;
	long long ll=(long long)p;
	while(ll%alignLocal!=0)
		ll++;
	return (char *)ll;
}

#define va_start(ap, param) (ap) = ((char *)&param) + sizeof(param)
#define va_end(ap) (ap)
#define va_arg(ap, type) ((ap) = __va_aligned__2((ap), sizeof(type)*2), (ap) += sizeof(type)*2, *(type *)((ap) - (sizeof(type)*2)))
#define va_copy(dest, src)  (dest) = (src);

#else
#include <stdarg.h>
#endif
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

// variable core cpu
struct virtual_cpu {
    int core_count;
    struct virtual_cpu_core *core;
    struct Queue *q;
    char * name;
} cpu_default;


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
struct QNode* newNode(CPU_TYPE type, struct virtual_cpu_register_bank reg);
struct Queue *createQueue();
void store_bank(struct Queue *q, CPU_TYPE type, struct virtual_cpu_register_bank reg);
struct QNode * load_bank(struct Queue *q);
int cpu_queue_add(CPU_TYPE what, ...);
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
    printf("VIRTUAL CPU: INFO : %s : size of %s: %zu\n", cpu->name, core->name, sizeof(*core));
    printf("VIRTUAL CPU: INFO : %s : %s : cpu power status: %s\n", cpu->name, core->name, core->cpu_power_state[core->power]);
    printf("VIRTUAL CPU: INFO : %s : %s : status:           %d\n", cpu->name, core->name, core->status);
    cpu_sub_core_info(cpu, core, &core->previous);
    cpu_sub_core_info(cpu, core, &core->current);
}

void cpu_info(struct virtual_cpu *cpu) {
    virtual_cpu_check(cpu);
    printf("VIRTUAL CPU: INFO : cpu name:         %s\n", cpu->name);
    printf("VIRTUAL CPU: INFO : cpu cores:        %d\n", cpu->core_count);
    printf("VIRTUAL CPU: INFO : size of %s: %zu\n", cpu->name, sizeof(*cpu) * cpu->core_count);
    for (int i = 0; i < 1; i++) cpu_core_info(cpu, &cpu->core[i]);
}

void cpu_core_start(struct virtual_cpu_core *core) {
    printf("VIRTUAL CPU: starting virtual cpu core:      %s\n", core->name);
    core->power = CPU_POWER_ON;
}

void cpu_start(struct virtual_cpu *cpu) {
    virtual_cpu_check(cpu);
    printf("VIRTUAL CPU: starting virtual cpu:      %s\n", cpu->name);
    cpu_core_start(&cpu->core[0]);
}

void cpu_core_shutdown(struct virtual_cpu_core *core) {
    printf("VIRTUAL CPU: shutting down virtual cpu core: %s\n", core->name);
    core->power = CPU_POWER_OFF;
}

void cpu_shutdown(struct virtual_cpu *cpu) {
    virtual_cpu_check(cpu);
    printf("VIRTUAL CPU: shutting down virtual cpu:      %s\n", cpu->name);
    cpu_core_shutdown(&cpu->core[0]);
    cpu_deinit(cpu);
}

// A C program to demonstrate linked list based implementation of queue 
// A linked list (LL) node to store a queue entry
struct QNode
{
    struct virtual_cpu_register_bank reg;
    struct QNode *next;
};
 
// The queue, front stores the front node of LL and rear stores ths
// last node of LL
struct Queue
{
    struct QNode *front, *rear;
};
 
// A utility function to create a new linked list node.
struct QNode* newNode(CPU_TYPE type, struct virtual_cpu_register_bank reg)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->reg = reg;
    temp->reg.type = type;
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
 
void store_bank(struct Queue *q, CPU_TYPE type, struct virtual_cpu_register_bank reg)
{
    // Create a new LL node
    struct QNode *temp = newNode(type, reg);
 
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
 
struct QNode * load_bank(struct Queue *q)
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

int cpu_queue_add(CPU_TYPE what, ...) {
    if (!cpu_default.q) cpu_default.q = createQueue();
    struct virtual_cpu_register_bank regs;
    virtual_cpu_register_check(&regs, "register bank queue");
    // storage format shall be a register queue, arguments are to be interperated by specified type and saved appropriately
    if (what == CPU_TYPE_ADD) {
        puts("queing ADD instruction");
        // adds r1 and r2 and stores the result in r3
        va_list ap2;
        va_start(ap2, what);
        regs.r1 = va_arg(ap2, int);
        regs.r2 = va_arg(ap2, int);
        store_bank(cpu_default.q, what, regs);
        va_end(ap2);
    }
    //cpu_register_info_minimal(&regs);
    return 0;
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

// cpu shall backup current to previous in order to have a restore point, then take changes from que and commit them to current
void cpu_execute(struct virtual_cpu *cpu) {
    puts("attempting to execute instruction list");
    // obtain the first added instruction
    struct QNode * node = malloc(1); // this gets freed anyway
    struct virtual_cpu_register_bank regs = {0};
    struct virtual_cpu_register_bank regstmp = {0};
    virtual_cpu_register_check(&regstmp, "placeholder");
    virtual_cpu_register_check(&regs, "global");
    int instructions;
    while (node != NULL) {
        // drain the list until empty
        free(node);
        node = load_bank(cpu->q);
        if (node == NULL) break;
        regstmp = node->reg;
        instructions++;
        if (regstmp.type == CPU_TYPE_ADD) {
            cpu_register_info_minimal(&regstmp);
            cpu_add(regstmp.r1, regstmp.r2, &regstmp.r3);
            cpu_add(regstmp.r3, regs.r3, &regs.r3);
            cpu_register_info_minimal(&regs);
        }
    }
    if (instructions == 0) puts("i have no instruction to execute");
    else puts("i have no instructions left to execute");
}

int main()
{
    cpu_start(&cpu_default);
    cpu_info(&cpu_default);
    cpu_queue_add(CPU_TYPE_ADD, 1, 2);
    cpu_queue_add(CPU_TYPE_ADD, 10, 20);
    cpu_execute(&cpu_default);
    cpu_execute(&cpu_default);
    cpu_execute(&cpu_default);
    cpu_shutdown(&cpu_default);
    return 0;
}
