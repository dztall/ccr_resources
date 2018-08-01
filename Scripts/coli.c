/*

http://coliru.stacked-crooked.com/a/Invalid query parameters: invalid %-encoding ({&quot;cmd&quot;:&quot;cat .&#x2F;main.cpp&quot;,&quot;src&quot;:&quot;&#x2F;*\n\nhttp:&#x2F;&#x2F;coliru.stacked-crooked.com&#x2F;a&#x2F;Invalid query parameters: invalid %-encoding ({)


http://coliru.stacked-crooked.com/a/Invalid query parameters: invalid %-encoding ({&quot;cmd&quot;:&quot;cat .&#x2F;main.cpp&quot;,&quot;src&quot;:&quot;&#x2F;*\n\nhttp:&#x2F;&#x2F;coliru.stacked-crooked.com&#x2F;a&#x2F;Invalid query parameters: invalid %-encoding ( 0;\\n    char *o;\\n    if (!(fd )


http://coliru.stacked-crooked.com/a/Invalid query parameters: invalid %-encoding ( 0;\n    char *o;\n    if (!(fd = open(file, O_RDONLY)))\n    {\n        fprintf(stderr, \&quot;open() failure\\n\&quot;);\n        return (1);\n    }\n    len = lseek(fd, 0, SEEK_END);\n    lseek(fd, 0, 0);\n    if (!(o = malloc(len))) {\n        fprintf(stderr, \&quot;failure to malloc()\\n\&quot;);\n    }\n    if ((read(fd, o, len)) == -1) {\n        fprintf(stderr, \&quot;failure to read()\\n\&quot;);\n    }\n    int cl = close(fd);\n    if (cl &lt; 0) {\n        fprintf(stderr, \&quot;cannot close \\\&quot;%s\\\&quot;, returned %i\\n\&quot;, file, cl);\n        return -1;\n    }\n    *p = o;\n    *q = len;\n    return len;\n}\n\n#define json 3\n\nint mode;\n\nchar * __cathexj(const char **args)\n{\n\tunsigned char * buffer;\n\tunsigned long * len;\n\tconst char * file;\n\tif (args[1] == NULL) file = __FILE__;\n\telse file = args[1];\n\tread__(file, (char *))

*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int read__(char *file, char **p, size_t *q) {
    int fd;
    size_t len = 0;
    char *o;
    if (!(fd = open(file, O_RDONLY)))
    {
        fprintf(stderr, "open() failure\n");
        return (1);
    }
    len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, 0);
    if (!(o = malloc(len))) {
        fprintf(stderr, "failure to malloc()\n");
    }
    if ((read(fd, o, len)) == -1) {
        fprintf(stderr, "failure to read()\n");
    }
    int cl = close(fd);
    if (cl < 0) {
        fprintf(stderr, "cannot close \"%s\", returned %i\n", file, cl);
        return -1;
    }
    *p = o;
    *q = len;
    return len;
}

#define json 3

int mode;

char * __cathexj(const char **args)
{
	unsigned char * buffer;
	unsigned long * len;
	const char * file;
	if (args[1] == NULL) file = __FILE__;
	else file = args[1];
	read__(file, (char *)&buffer, (size_t *)&len);
/*

The following characters are reserved in JSON and must be properly escaped to be used in strings:

Backspace is replaced with \b
Form feed is replaced with \f
Newline is replaced with \n
Carriage return is replaced with \r
Tab is replaced with \t
Double quote is replaced with \"
Backslash is replaced with \\
	
*/
	
	// small sacrifice, should be done in memory

	unsigned long i;
	remove("./json");
	FILE * printf_stdoutjjjjjjj = fopen("./json", "a+");
	for (i = 0; i < len; i++)
	{
		if ( buffer[i] == '\\' && buffer[i+1] == '\n' && i+2 == len ) fprintf(printf_stdoutjjjjjjj, "\\\n");
		else if ( buffer[i] == '\\' && buffer[i+1] == '\n' ) fprintf(printf_stdoutjjjjjjj, "\\\\\\n");
		else if ( buffer[i-1] == '\\' && buffer[i] == '\n' ) {}
		else if ( buffer[i] == '\n' && i+1 == len ) fprintf(printf_stdoutjjjjjjj, "\\n");
		else if ( buffer[i] == '\n' ) fprintf(printf_stdoutjjjjjjj, "\\n");
		else if ( buffer[i] == '\t' ) fprintf(printf_stdoutjjjjjjj, "\\t");
		else if ( buffer[i] == '\r' ) fprintf(printf_stdoutjjjjjjj, "\\r");
		else if ( buffer[i] == '\f' ) fprintf(printf_stdoutjjjjjjj, "\\f");
		else if ( buffer[i] == '\b' ) fprintf(printf_stdoutjjjjjjj, "\\b");
		else if ( buffer[i] == '"' ) fprintf(printf_stdoutjjjjjjj, "\\\"");
		else if ( buffer[i] == '\'' ) fprintf(printf_stdoutjjjjjjj, "\\'");
		else if ( buffer[i] == '\\' ) fprintf(printf_stdoutjjjjjjj, "\\\\");
		else if ( buffer[i] < 32 || buffer[i] >= 127 ) {}
			//fprintf(printf_stdoutjjjjjjj, "\
/* UNPRINTABLE CHARACTER %d */\
", buffer[i]);
		else
			fprintf(printf_stdoutjjjjjjj, "%c", buffer[i]);
	}
	fclose(printf_stdoutjjjjjjj);
	char * buf;
	size_t * size;
	read__("./json", &buf, &size);
	buf[size] = NULL;
	
	return strdup(buf);
}

char * builtin__json(const char **args) {
	mode = json;
	return __cathexj(args);
}


char ** env__new();
char ** env__add(char ** env, const char * string);

void builtin__coliru(char * mode, char * file, char * cmd, char * out)
{
	if(access(file, F_OK) == -1) {
		printf(file);
		puts(" must be accessable");
		return;
	}
	if ((strcmp(mode, "compile") != 0 && strcmp(mode, "share") == 0) || (strcmp(mode, "compile") == 0 && strcmp(mode, "share") != 0));
	else {
		puts("must specify either \"compile\" or \"share\"");
		return;
	}
	if (file == NULL) {
		puts("must specify a file");
		return;
	}
	if (cmd == NULL) {
		puts("must specify a command (\" \" is allowed)");
		return;
	}
	char ** args = env__add(env__add(env__new(), "default"), file);
	char * s4 = builtin__json(args);
	free(args);
	char * s1 = "curl 'http://coliru.stacked-crooked.com/";
	char * s2 = "' --data-binary '{\"cmd\":\"";
	char * s3 = "\
\",\"src\":\"";
	char * s5;
	if (out == NULL) {
		s5 = "\"}'";
		out = "";
	}
	else {
		s5 = "\"}' -o ";
	}
	char * line = malloc(
	strlen(s1)+
	strlen(mode)+
	strlen(s2)+
	strlen(cmd)+
	strlen(s3)+
	strlen(s4)+
	strlen(s5)+
	strlen(out)
	);
	sprintf(line, "%s%s%s%s%s%s%s%s", s1, mode, s2, cmd, s3, s4, s5, out);
	//puts(line);
	if (strcmp(mode, "share") == 0) printf("http://coliru.stacked-crooked.com/a/");
	system(line);
	puts("");
}

int main(void)
{
	builtin__coliru("share", "./coli.c", "cat ./main.cpp", NULL);
	return 0;
}

#ifndef __SHELL_ENV
#define __SHELL_ENV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef libstring
char *
strcatb(char *dest,
       const char *src)
{
    char *cptr = dest;

    while (*cptr) {
        cptr++;
    }
    while (*src) {
        *cptr++ = *src++;
    }
    *cptr = *src;

    return dest;
}
#endif

extern char **environ;
char **environ_default;

static int env__size(char **env) { 
	int i;
	for(i = 0; env[i] != 0; i++);
	return i;
}

char ** env__new() {
	char ** envempty = malloc(1);
	envempty[0] = NULL;
	return envempty;
}

char ** env__add(char ** env, const char * string) {
	char ** array_tmp;
	size_t i = env__size(env);
	array_tmp = realloc(env, ((i+2)*sizeof(char*)));
    if (array_tmp == NULL) {
        fprintf(stderr, "failed to resize env");
        return env;
    } else {
        env = array_tmp;
    }
    env[i] = strdup(string);
    env[i+1] = NULL;
    return env;
}
