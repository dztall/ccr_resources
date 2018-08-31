#include "Garbage_Collector/gc.h"
#include "Shell/builtins/bom.h"

int main(int argc, char * argv[])
{
	if (argc <2) {
		printf("usage: %s File\n", argv[0]);
		return -1;
	}
	struct BOM t = builtin__BOM_get(filetostring(argv[1]));
	builtin__BOM_print(t);
	builtin__BOM_free(t);
	Garbage_Collector_Shutdown();
	return 0;
}
