//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Garbage_Collector/gc.h"
Garbage_Collector_Options = Garbage_Collector_Options_No_Recycle;
//Garbage_Collector_Debug = Garbage_Collector_Debug_Free | Garbage_Collector_Debug_Realloc | Garbage_Collector_Debug_List;

#include "git/git.h"

int main(int argc, char * argv[])
{
	argc--;
	argv++;
	char * a = builtin__argvtostring(argc, argv);
	git(a);
	free(a);
	Garbage_Collector_Shutdown();
	return 0;
}
