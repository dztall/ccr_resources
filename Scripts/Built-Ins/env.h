//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

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

char *
env__get(char ** env, const char *envtarget)
{
    const char * STTR = envtarget;
    int i = 1;
    char *s = *env;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                    char * NAME = pch;
                    if (strcmp(NAME,STTR) == 0 )
                        {
                            char * pch = strtok (NULL, "=");
                            char * VALUE = pch;
                            return VALUE;
                        }
                    if (strcmp(NAME,STTR) != 0 )
                        {
                        }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	fprintf(stderr, "  \"%s\" COULD NOT BE FOUND\n", STTR);
	free(s);
	return "(null)";
}

void
env__print(char ** env, const char *envtarget)
{
    const char * STTR = envtarget;
    int i = 1;
    char *s = *env;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                    char * NAME = pch;
                    if (strcmp(NAME,STTR) == 0 )
                        {
                            char * pch = strtok (NULL, "=");
                            char * VALUE = pch;
                            puts(s);
                            return;
                        }
                    if (strcmp(NAME,STTR) != 0 )
                        {
                        }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	fprintf(stderr, "  \"%s\" COULD NOT BE FOUND\n", STTR);
	free(s);
	return;
}

char *
env__return(char ** env, const char *envtarget)
{
    const char * STTR = envtarget;
    int i = 1;
    char *s = *env;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                    char * NAME = pch;
                    if (strcmp(NAME,STTR) == 0 )
                        {
                            char * pch = strtok (NULL, "=");
                            char * VALUE = pch;
                            return s;
                        }
                    if (strcmp(NAME,STTR) != 0 )
                        {
                        }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	fprintf(stderr, "  \"%s\" COULD NOT BE FOUND\n", STTR);
	free(s);
	return "(null)";
}

int
env__getposition(char ** env, const char *envtarget)
{
    const char * STTR = envtarget;
    int i = 1;
    char *s = *env;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                    char * NAME = pch;
                    if (strcmp(NAME,STTR) == 0 )
                        {
                            return i;
                        }
                    if (strcmp(NAME,STTR) != 0 )
                        {
                        }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	fprintf(stderr, "  \"%s\" COULD NOT BE FOUND\n", STTR);
	free(s);
	return -1;
}

char ** env__new() {
	char ** envempty = malloc(1);
	envempty[0] = NULL;
	return envempty;
}

void env__free(char ** env) {
	free(*env);
}

void env__clear(char ** env) {
	env__free(env);
	env = env_new();
}

void env__list(char ** env) {
	char **ep;
	for (ep = env; *ep; ep++) printf("%s\n", *ep);
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

char ** env__copy(char **env)
{
	char **ret;
	size_t i = env__size(env);
	ret = malloc((i+2)*sizeof(char*));
	for (i = 0; env[i]; i++)
		ret[i] = strdup(env[i]);
	ret[i] = NULL;
	return ret;
}

char ** env__remove(char ** env, const char * string) {
	// we rebuild the entire environment
	char ** envtmp = env__copy(env);
	char ** envempty = env__new();
    int i = 1;
    char *s = *envtmp;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                    if (strcmp(pch,string) != 0 ) {
                    	envempty = env__add(envempty, s);
                    }
                    else printf("\nremoving %s\n\n", string);
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	free(s);
	env = env__copy(envempty);
	free(envempty);
	free(envtmp);
	return env;
}

char ** env__replace(char ** env, const char * string, const char * string2) {
	// we rebuild the entire environment
	char ** envtmp = env__copy(env);
	char ** envempty = env__new();
    int i = 1;
    char *s = *envtmp;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                	//printf(" does %s == %s\n", pch, string);
                    if (strcmp(pch,string) != 0 ) {
                    	envempty = env__add(envempty, s);
                    }
                    else {
                    	printf("replacing %s with %s=%s\n\n", s, pch, string2);
                    	char * tmp = malloc(strlen(pch)+strlen("=")+strlen(string2));
                    	tmp = strcatb(tmp, pch);
                    	tmp = strcatb(tmp, "=");
                    	tmp = strcatb(tmp, string2);
                    	envempty = env__add(envempty, tmp);
                    	free(tmp);
                    }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	free(s);
	env = env__copy(envempty);
	free(envempty);
	free(envtmp);
	return env;
}


char ** env__append(char ** env, const char * name, const char * string) {
	// we rebuild the entire environment
	char ** envtmp = env__copy(env);
	char ** envempty = env__new();
    int i = 1;
    char *s = *envtmp;

    for (; s; i++) {
        if (s)
        {
            char * pch;
            char * y = (char *)malloc(strlen(s) + 1);
            strcpy(y,s);
            //fprintf(stderr, "trying \"%s\"\n", y);
            pch = strtok (y,"=");
            while (pch != NULL)
                {
                	printf("does %s == %s (%s)\n", pch, name s, string);
                    if (strcmp(pch,name) != 0 ) {
                    	envempty = env__add(envempty, s);
                    }
                    else {
                    	printf("appending %s to %s\n\n", string, s);
                    	char * tmp = malloc(strlen(s)+strlen(string));
                    	tmp = strcatb(tmp, s);
                    	tmp = strcatb(tmp, string);
                    	envempty = env__add(envempty, tmp);
                    	free(tmp);
                    }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
	free(s);
	env = env__copy(envempty);
	free(envempty);
	free(envtmp);
	return env;
}


#endif
