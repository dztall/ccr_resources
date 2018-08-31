#include "Garbage_Collector/gc.h"
#include <stdio.h>
#include "Shell/builtins/printfmacro.h"
#include "Shell/builtins/regex_str.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
	str_new(path);
	char * pathh = getenv("CPATH")+1;
	int len = strlen(pathh)-strlen("~/CCR/Headers");
	str_insert_string(path, path.index, pathh);
	str_insert_string(path, path.index, "/gc.h");
	if (access(path.string, F_OK) == 0) {
		printf("Uninstalling Garbage Collector from %s\n", path.string);
		unlink(path.string);
		puts("Garbage Collector has been succesfully uninstalled\nGarbage collector can no longer be accessed by '#include <gc.h>'");
	}
	else {
		puts("Garbage Collector is already unistalled");
	}
	str_free(path);
	return 0;
}
