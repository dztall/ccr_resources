//#include "../Garbage_Collector/gc.h"
#include <unistd.h>
#include "disassembler.h"

int a() {
	int a = 6;
	return a;
}

int fooa(void) {
	return a()+7;
}

void loop(void) {
	return 1;
}

int rec = 0; // set to 1 to test recursion and stability
int m = 0;
int i = 100;

/*


0x2ca23d 00 60 f9 61 00000000 01100000 11111001 01100001 RSB{1} <0> <7> <0>{, <shift> (type=00,imm5=00011)}
0x2ca27d 02 60 f9 61 00000010 01100000 11111001 01100001 RSB
0x2ca25d 01 60 f9 61 00000001 01100000 11111001 01100001 ERET


*/
#include "cpu.h"
// cpu type could be used to automatically choose the disassembly type based on the host
int main(void)
{
	timefunc(
		getCPUType();
		printCPUType(cpu);
	);
    static char (*func)();
    func = (char *()) fooa;
	pi(a());
	pi(fooa());
	regexEngine_Debug = false;
	disassembler_colour = true;
	disassembler_debug = false;
	disassembler_decode_cond = false;
	disassembler_instruction_only = true;
	disassembler_include_binary = false;
	timefunc(
		disassemble_ARM_IOS(loop, 32, 32);
	);
	pi(regexEngine_Total_Calls)
	if (rec == 1) {
	if(m < i) {
		m++;
		main();
	}
	if (m < i+1) printf("%d < %d\n", m, i+1);
	m--;
	}
	return 0;
}
