//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123
#include <../../Garbage_Collector/gc.h>
Garbage_Collector_Options = Garbage_Collector_Options_No_Recycle;
#include "../builtins/env.h"

char ** vars;

int main(int argc, char *argv[])
{
	vars = env__new();
	vars = env__add(vars, "foo=foo bar");
	printf("index of foo is %d\n", env__getposition(vars, "foo"));
	printf("value of foo is %s\n", env__get(vars, "foo"));
	env__print(vars, "foo");
	vars = env__append(vars, "foo", " baz");
	env__print(vars, "foo");
	free(vars);
	return 0;
}
