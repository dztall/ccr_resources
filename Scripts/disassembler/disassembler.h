//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123
#define MCASSEMBLER
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "../../shells/Built-Ins/Built-Ins.h"

#include "../Shell/builtins/colors.h"
#include "../Shell/builtins/clock.h"
#include "regexEngine.h"



bool disassembler_debug = false;
bool disassembler_colour = false;
#define ifd if (disassembler_debug)
#define ifc if (disassembler_colour)


#define __ds p()
#define __de p()
#define d(a, b, y, x) { __ds for (int y = a ; y < b; y++) { ifc printf_b("%02x ", (x)[y]); else printf("%02x ", (x)[y]); } __de }
#define ds(a, b, y, x) { __ds for (int y = !swap?a:b-1; !swap?y < b:y != ((a)-1); !swap?y++:y--) { ifc printf_b("%02x ", (x)[y]); else printf("%02x ", (x)[y]); } __de }

#define preview(x) { printf("preview swapped:     "); ds(0, 4, def_prev ,x) ds(4, 8, def_prev ,x) puts(""); printf("preview not swapped: "); d(0, 4, def_prev ,x) d(4, 8, def_prev ,x) puts(""); }

#define current(x) { printf("current: "); ds(0, 4, def_curr ,x) puts(""); }

#define next(x) { printf("next:    "); ds(4, 8, def_next ,x) puts(""); }

int swap_(void) {
	unsigned int x = 1;
	return (int) (((char *)&x)[0]);
}

int swap = 0;

int getBit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}

void printBin(unsigned char num){
	for (int i = 7; i != -1; i--) {
		ifc printf_r("%d", getBit(num, i));
		else printf("%d", getBit(num, i));
	}
}

#include "opcodes.h"
void __dump(unsigned char *buffer, unsigned long index, unsigned long width)
{
	unsigned char * opcode = malloc(index);
	unsigned long i = 0, ii = 0;
	for (i = !swap?0:index-1; !swap?i < index:i != -1; !swap?i++:i--) {
		memcpy(&opcode[ii], &buffer[i], 1);
	    ii++;
	}
	process_opcodes(buffer, opcode, index, width); // needs to retain the address
	free(opcode);
}


// ARM 32 Dissassembler


void disassemble_ARM_IOS(void * function, int length, int lines) {
	pp(function);
	swap = swap_();
	printf("Endian: %s\nbit length: %d\nlines to read = %d (1 line == %d bits read)\n", swap?"Big":"Little", length, lines, length);
	length = length/8;
	int width = length*2;
	
	for(unsigned long i = 0;i < lines;i++) {
		ifd puts("");
		ifd pp((unsigned char*)function+( i*length ))
		ifd preview((unsigned char*) function+( i*length ))
		ifd current((unsigned char*) function+( i*length ))
		ifd next((unsigned char*) function+( i*length ))
		__dump((unsigned char*)function+( i*length ), length, width);
	}
}
