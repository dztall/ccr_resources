//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Garbage_Collector/gc.h"
#include "Shell/builtins/find.h"

int main(int argc, char * argv[]) {
	int ret = find(argc, argv);
	Garbage_Collector_Shutdown();
	return ret;
}
