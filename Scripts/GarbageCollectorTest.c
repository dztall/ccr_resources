//#define Garbage_Collector_Full_Scan
#include "Garbage_Collector/gc.h"
//Garbage_Collector_Debug = Garbage_Collector_Debug_Free | Garbage_Collector_Debug_List | Garbage_Collector_Debug_Realloc;
Garbage_Collector_Debug = Garbage_Collector_Debug_Normal;

int main()
{
	printf("\ntest 1: multiple shutdowns and start ups\n");
	Garbage_Collector_Shutdown();
	Garbage_Collector_Start();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Start();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Start();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Start();
	Garbage_Collector_Start();
	Garbage_Collector_Start();
	Garbage_Collector_Start();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Shutdown();
	Garbage_Collector_Start();
	printf("\ntest 2: malloc an area of 250, 500 times, and then clean up\n");
	Garbage_Collector_Debug = Garbage_Collector_Debug_List;
	for (int i = 0; i < 500; i++) {
		malloc(250);
	}
	puts("calling clean up");
	Garbage_Collector_Debug = Garbage_Collector_Debug_Free;
	Garbage_Collector_Cleanup();
	Garbage_Collector_Debug = Garbage_Collector_Debug_Normal;
	printf("\ntest 3: clean up on segfault, dumping pointer list before cleaning up\n");
	char * a = malloc(1);
	a = realloc(a,2);
	Garbage_Collector_Debug = Garbage_Collector_Debug_List;
	for (int i = 0; i < 12; i++) {
		malloc(250);
	}
	Garbage_Collector_Debug = Garbage_Collector_Debug_Normal;
	Garbage_Collector_Dump_Mem(a);
	return 0;
}
