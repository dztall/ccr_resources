#pragma once

#include <stdlib.h> // atexit itself

int atexitindex = 0;

int atexitmax = 32;


void (*atexithandler[atexitmax])();

int atexitf(void(*handle)()) {
	if (atexitindex == atexitmax) return -1;
	atexithandler[atexitindex++] = handle;
	return 0;
}

void atexitreal(void) {
	do {
		atexitindex--;
		atexithandler[atexitindex]();
	}
	while(atexitindex);
}

int atexitinit = atexit(atexitreal);
#define atexit atexitf
