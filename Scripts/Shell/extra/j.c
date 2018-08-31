/* UNPRINTABLE CHARACTER 239 *//* UNPRINTABLE CHARACTER 187 *//* UNPRINTABLE CHARACTER 191 */#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define bytecmpq strcmp
#define GQ2 "no"
#define json 3

int mode;
int read__(char *file, char **p, size_t **q) {
    int fd;
    size_t len = 0;
    char *o;
    if (!(fd = open(file, O_RDONLY)))
    {
        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "open() failure\n");
        return (1);
    }
    len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, 0);
    if (!(o = malloc(len))) {
        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "failure to malloc()\n");
    }
    if ((read(fd, o, len)) == -1) {
        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "failure to read()\n");
    }
    int cl = close(fd);
    if (cl < 0) {
        if (bytecmpq(GQ2, "no") == 0) fprintf(stderr, "cannot close \"%s\", returned %i\n", file, cl);
        return -1;
    }
    *p = malloc(len);
    *p = o;
    *q = len;
    return len;
}

char * __cathexj(char * file)
{
	unsigned char * buffer;
	unsigned long * len;
	size_t * lens;
	if (file == NULL) file = "./coliru.c";
	read__(file, &buffer, &lens);
	len = (unsigned long *)lens;
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
		else if ( buffer[i] < 32 || buffer[i] >= 127 )
			fprintf(printf_stdoutjjjjjjj, "/* UNPRINTABLE CHARACTER %d */", buffer[i]);
		else
			fprintf(printf_stdoutjjjjjjj, "%c", buffer[i]);
	}
	fclose(printf_stdoutjjjjjjj);
	char * buf;
	size_t * size;
	read__("./json", &buf, &size);
	#ifdef __CCR__
	buf[size] = NULL;
	#endif
	
	return buf;
}

char * builtin__json(char * file) {
	mode = json;
	return __cathexj(file);
}


int split (const char *strconst, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;
    char * str = strdup(strconst);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }
    *arr = NULL;

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }
    *t = '\0';

    return count;
}

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
	char * s4 = builtin__json(file);
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


int main(int argc, char ** argv)
{
	if (argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		printf("%s <mode> <file> \"<command>\" <optional output file>\n", argv[0]);
		return 0;
	}
	if (argc < 3) if (argv[2] == NULL) {
		puts("must specify a file");
		return -1;
	}
	if (argc < 4) if (argv[3] == NULL) {
		puts("must specify a command (\" \" is allowed)");
		return -1;
	}
	builtin__coliru(argv[1], argv[2], argv[3], argv[4]);
	return 0;
}
