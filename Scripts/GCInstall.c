#include "Garbage_Collector/gc.h"
#include <stdio.h>
#include "Shell/builtins/printfmacro.h"
#include "Shell/builtins/regex_str.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "realpath/realpath.h"

int main()
{
	str_new(path);
	char * pathh = getenv("CPATH")+1;
	int len = strlen(pathh)-strlen("~/CCR/Headers");
	str_insert_string(path, path.index, pathh);
	str_insert_string(path, path.index, "/gc.h");
	if (access(path.string, F_OK) == 0) {
		printf("Garbage Collector Is Already Installed\n");
	}
	else {
		puts("Garbage Collector Is Not Installed");
		printf("Installing Garbage Collector to %s\n", path.string);
		puts("Generating Include string");
		char * gcpath = resolve("./Garbage_Collector/gc.h", dirname(path.string));
		str_new(contents);
		str_insert_string(contents, contents.index, "#include \"");
		str_insert_string(contents, contents.index, gcpath);
		str_insert_string(contents, contents.index, "\"");
		puts("Include string generated");
		puts("Writing file");
		str_output(contents, path.string);
		puts("File written succesfully");
		puts("Garbage Collector has been succesfully installed\nGarbage Collector can be accessed by '#include <gc.h>'");
		str_free(contents);
		free(gcpath);
	}
	str_free(path);
	return 0;
}
