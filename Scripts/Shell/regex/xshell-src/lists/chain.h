#ifndef CHAIN
#define CHAIN
#include "ll.h"

typedef struct chain {
	int count;
	int background; // 0 - not in background, 1 - in bg
	int parsed; // 0 - not, 1 - yes
	int piped; // 0 - not, 1 - yes
	int firstpiped; // 0 - not, 1 - yes

	char* fileIn;
	char* fileOut;
	int fileOutMode; // 0 - write, 1 - append
	char* fileErrorOut;
	int fileErrorStdout; // 0 - false, 1 - true

	struct ll* start;
	struct ll* end;
} chain;

chain* chainCreate(int x);
void chainReset(chain* command);
void chainPush(chain* command, ll* list);
ll* chainPop(chain* command);
void chainPrint(chain* command);

#endif

