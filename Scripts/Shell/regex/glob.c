#include <glob.h>
#include <unistd.h>
#include "stdio.h"
#include "../Built-Ins/Built-Ins.h"
#include <errno.h>

#define globflags GLOB_DOOFFS | GLOB_BRACE | GLOB_MARK | GLOB_QUOTE
int main(int argc, char *argv[])
{
	glob_t globbuf;
	pi(GLOB_NOMATCH);
	pi(glob("/*",  globflags , NULL, &globbuf));
	//pi(glob("*", globflags | GLOB_APPEND, NULL, &globbuf));
	builtin__argv(globbuf.gl_pathc, globbuf.gl_pathv);
	builtin__whereis(env__add(env__add(env__new(), "nuuu"), "glob"), "c");
	
//globbuf.gl_pathv[0] = "ls";
//globbuf.gl_pathv[1] = "-l";
//execvp("ls", &globbuf.gl_pathv[0]);
	return 0;
}
