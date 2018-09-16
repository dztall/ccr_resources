#include "encoding.h"
#include "encoding_arm.h"

bool disassembler_include_binary = false;

void process_opcodes(void *bufferb, unsigned char * opcode, unsigned long index, unsigned long width)
{
	printf("%p ", bufferb);
	unsigned char * buffer = bufferb;
	unsigned long i, ii;
	int c = 0;
	// mov AL : 10110 000
	for (int i = 0; i < index; i++) { ifc printf_b("%02x ", opcode[i]); else printf("%02x ", opcode[i]); }
	//puts("");
	if(disassembler_include_binary) {
		for (i = !swap?0:index-1; !swap?i < index:i != -1; !swap?i++:i--) {
			if (index >= 5) {
				c++;
				if (c >= 5) {
					puts("");
					c=0;
				}
			}
			printBin(buffer[i]);
			printf(" ");
		}
	}
	read_encoding_arm_regexEngine(opcode);
	puts("");
}
