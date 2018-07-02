#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ps(x) { printf("%s = %s\n", #x, x); }
#define pi(x) { printf("%s = %d\n", #x, x); }

int depth;

char * quote(char * str) {
	char * quoted = malloc(4096);
	memset(quoted, 0, 4096);
	snprintf(quoted, 4096, "\"%s\"", str);
	return quoted;
}

char * argv_to_string(char * argv0, int argc, char ** argv) {
	char * cmd = malloc(4096);
	if (argv0) snprintf(cmd, 4096, "%s", argv0);
	for (int i = argv0?1:0; i< argc; i++) snprintf(cmd, 4096, "%s %s", cmd, argv[i]);
	return cmd;
}
			


typedef enum {
    STR2AV_OK       = 0,
    STR2AV_UNBALANCED_QUOTE
} str_to_argv_err_t;

str_to_argv_err_t string_to_argv(char const * str, int * argc_p, char *** argv_p);
void builtin__argv(int argc, char ** argv);

#define print_usage(x) printf("%s\n", x);
#define print_usage_command(x) printf("\t%s\n", x);
#define print_usage_command_info(x) printf("\t\t\t\t%s\n", x);

void usage(void){
	print_usage("usage: find [path] [option]")
	print_usage_command("-name [file]")
	print_usage_command_info("searches [path] recursively for [file]")
}

void find(const char *name)
{
	char *is_name = NULL, *is_type = NULL;
	int argc, is_root = 0, is_slash = 0;
	char ** argv;
	string_to_argv(name, &argc, &argv);
	// case 1, if path is root itself, correct d_name
	if ((argv[0])[0] == '/' && strlen(argv[0]) == 1) is_root = 1;
	// case 2, if path ends in / but is not root itself, remove it
	if (!is_root) if ((argv[0])[strlen(argv[0])-1] == '/') {
		(argv[0])[strlen(argv[0])-1] = 0;
		is_slash = 1;
	}
	// process args
	for (int i = 0; i< argc; i++) {
		if (!strcmp(argv[i], "-name")) {
			i++;
			is_name = argv[i];
		}
		else if (!strcmp(argv[i], "-type")) {
			i++;
			is_type = argv[i];
		}
		else if (!strcmp(argv[i], "-h") || !strcmp(argv[i],"--help")) {
			usage();
			return;
		}
		else if ((argv[i])[0]== '-') {
			printf("invalid command: '%s'\n", argv[i]);
			usage();
			return;
		}	
	}
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(argv[0]))) {
    	printf("%s/ (unreadable)\n", argv[0]);
        return;
    }
    
    char pathD[1024];
    snprintf(pathD, sizeof(pathD), "%s%s", argv[0], is_root?"":(is_slash?"/":"/"));
    
    if (is_name) {
		if (strcmp(is_name, argv[0]) == 0) printf("%s\n", pathD);
	}
	else printf("%s\n", pathD);
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
			depth++;
            snprintf(path, sizeof(path), "%s%s%s%s", argv[0], is_root?"":(is_slash?"/":"/"), entry->d_name, is_root?"/":(is_slash?"/":""));
            char * qp = quote(path);
			char * cmd = argv_to_string(qp, argc, argv);
            free(qp);
            find(cmd);
			free(cmd);
			depth--;
        } else {
            char pathF[1024];
            snprintf(pathF, sizeof(pathF), "%s%s%s", argv[0], is_root?"":(is_slash?"/":"/"), entry->d_name);
			if (is_name) {
				if (strcmp(is_name, entry->d_name) == 0) printf("%s\n", pathF);
			}
			else printf("%s\n", pathF);
        }
    }
    closedir(dir);
}

int main(int argc, char * argv[]) {
	char * cmd = malloc(4096);
	memset(cmd, 0, 4096);
	if (argc == 1) snprintf(cmd, 4096, "./");
	else for (int i = 1; i< argc; i++) snprintf(cmd, 4096, "%s %s", cmd, argv[i]);
    find(cmd);
    free(cmd);
    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifndef NUL
#define NUL '\0'
#endif

static char const nomem[] = "no memory for %d byte allocation\n";

static str_to_argv_err_t
copy_raw_string(char ** dest_p, char ** src_p);

static str_to_argv_err_t
copy_cooked_string(char ** dest_p, char ** src_p);

static inline void *
Xmalloc(size_t sz)
{
    void * res = malloc(sz);
    if (res == NULL) {
        fprintf(stderr, nomem, sz);
        exit(EXIT_FAILURE);
    }
    return res;
}

static inline void *
Xrealloc(void * ptr, size_t sz)
{
    void * res = realloc(ptr, sz);
    if (res == NULL) {
        fprintf(stderr, nomem, sz);
        exit(EXIT_FAILURE);
    }
    return res;
}

str_to_argv_err_t
string_to_argv(char const * str, int * argc_p, char *** argv_p)
{
    int     argc = 0;
    int     act  = 10;
    char ** res  = Xmalloc(sizeof(char *) * 10);
    char ** argv = res;
    char *  scan;
    char *  dest;
    str_to_argv_err_t err;

    while (isspace((unsigned char)*str))  str++;
    str = scan = strdup(str);

    for (;;) {
        while (isspace((unsigned char)*scan))  scan++;
        if (*scan == NUL)
            break;

        if (++argc >= act) {
            act += act / 2;
            res  = Xrealloc(res, act * sizeof(char *));
            argv = res + (argc - 1);
        }

        *(argv++) = dest = scan;

        for (;;) {
            char ch = *(scan++);
            switch (ch) {
            case NUL:
                goto done;

            case '\\':
                if ( (*(dest++) = *(scan++)) == NUL)
                    goto done;
                break;

            case '\'':
                err = copy_raw_string(&dest, &scan);
                if (err != STR2AV_OK)
                    goto error_leave;
                break;

            case '"':
                err = copy_cooked_string(&dest, &scan);
                if (err != STR2AV_OK)
                    goto error_leave;
                break;

            case ' ':
            case '\t':
            case '\n':
            case '\f':
            case '\r':
            case '\v':
            case '\b':
                goto token_done;

            default:
                *(dest++) = ch;
            }
        }

    token_done:
        *dest = NUL;
    }

done:

    *argv_p = res;
    *argc_p = argc;
    *argv   = NULL;
    if (argc == 0)
        free((void *)str);

    return STR2AV_OK;

error_leave:

    free(res);
    free((void *)str);
    return err;
}

static str_to_argv_err_t
copy_raw_string(char ** dest_p, char ** src_p)
{
    for (;;) {
        char ch = *((*src_p)++);

        switch (ch) {
        case NUL: return STR2AV_UNBALANCED_QUOTE;
        case '\'':
            *(*dest_p) = NUL;
            return STR2AV_OK;

        case '\\':
            ch = *((*src_p)++);
            switch (ch) {
            case NUL:
                return STR2AV_UNBALANCED_QUOTE;

            default:
                /*
                 * unknown/invalid escape.  Copy escape character.
                 */
                *((*dest_p)++) = '\\';
                break;

            case '\\':
            case '\'':
                break;
            }
            /* FALLTHROUGH */

        default:
            *((*dest_p)++) = ch;
            break;
        }
    }
}

static char
escape_convt(char ** src_p)
{
    char ch = *((*src_p)++);

    /*
     *  Escape character is always eaten.  The next character is sometimes
     *  treated specially.
     */
    switch (ch) {
    case 'a': ch = '\a'; break;
    case 'b': ch = '\b'; break;
    case 't': ch = '\t'; break;
    case 'n': ch = '\n'; break;
    case 'v': ch = '\v'; break;
    case 'f': ch = '\f'; break;
    case 'r': ch = '\r'; break;
    }

    return ch;
}


static str_to_argv_err_t
copy_cooked_string(char ** dest_p, char ** src_p)
{
    for (;;) {
        char ch = *((*src_p)++);
        switch (ch) {
        case NUL: return STR2AV_UNBALANCED_QUOTE;
        case '"':
            *(*dest_p) = NUL;
            return STR2AV_OK;

        case '\\':
            ch = escape_convt(src_p);
            if (ch == NUL)
                return STR2AV_UNBALANCED_QUOTE;
            /* FALLTHROUGH */

        default:
            *((*dest_p)++) = ch;
            break;
        }
    }
}

void builtin__argv(int argc, char ** argv) {
	printf("argc = %d\n", argc);
	for (int i = 0; i<argc; i++) printf("argv[%d] = %s\n", i, argv[i]);
}
