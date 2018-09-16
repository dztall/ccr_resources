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

int bcmpcq__2(void const *vp, size_t n, void const *vp2, size_t n2)
{
    int string_match = 0;
    unsigned char const *p = vp;
    unsigned char const *p2 = vp2;
    int matches=0;
    int contains_matches=0;
    for (size_t i=0; i<n; i++) {
        if (p[i] == p2[i]) {
            matches++;
        } else {
            if (matches) contains_matches = 1;
            break;
        }
    }
    if (matches == 0) {
        return -1;
    } else {
        int ret = 0;
        if (contains_matches) ret = 1;
        return ret;
    }
}

extern char **environ;
char **environ_default;

static int env__size(char **env) { 
    if (!env) return 0;
	int i;
	for(i = 0; env[i] != 0; i++);
	return i;
}

char *
env__get(char ** env, const char *envtarget)
{
    if (!env) return NULL;
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
                    if (bcmpcq__2(s, strlen(STTR), STTR, strlen(STTR)) == 0)
                        {
                            free(y);
                            return strchr(s, '=')+1;
                        }
                    if (bcmpcq__2(s, strlen(STTR), STTR, strlen(STTR)) != 0)
                        {
                        }
                    break;
                }
            free(y);
        }
        s = *(env+i);
    }
// 	fprintf(stderr, "  \"%s\" COULD NOT BE FOUND\n", STTR);
	free(s);
	return NULL;
}

void
env__print(char ** env, const char *envtarget)
{
    if (!env) return;
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
                            free(y);
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
	free(s);
	return;
}

char *
env__return(char ** env, const char *envtarget)
{
    if (!env) return NULL;
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
                            free(y);
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
	return (char*)"(null)";
}

int
env__getposition(char ** env, const char *envtarget)
{
    if (!env) return -1;
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
                            free(y);
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
	char ** envempty = malloc(1*sizeof(*envempty));
	envempty[0] = NULL;
	return envempty;
}

void env__free(char ** env) {
    if (!env) return;
    for (char ** ep = env; *ep; ep++) {
        memset(*ep, 0, strlen(*ep));
        free(*ep);
        *ep = NULL;
    }
    *env = NULL;
	free(env);
    env = NULL;
}

void env__clear(char ** env) {
	env__free(env);
	env = env__new();
}

void env__list(char ** env) {
    if (!env) return;
	char **ep;
	for (ep = env; *ep; ep++) printf("%s\n", *ep);
}

char ** env__add(char ** env, const char * string) {
    //if (!env) env = env__new();
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
    if (!env) return env__new();
	char **ret = env__new();
	for (int i = 0; i < env__size(env); i++) ret = env__add(ret, env[i]);
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
    env__free(env);
	env = env__copy(envempty);
	env__free(envempty);
	env__free(envtmp);
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
    env__free(env);
	env = env__copy(envempty);
	env__free(envempty);
	env__free(envtmp);
	return env;
}


char ** env__append(char ** env, const char * name, const char * string) {
    if (!env) return env__new();
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
//                 	printf("does %s == %s (%s)\n", pch, name, string);
                    if (strcmp(pch,name) != 0 ) {
                    	envempty = env__add(envempty, s);
                    }
                    else {
//                     	printf("appending %s to %s\n\n", string, s);
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
    env__free(env);
	env = env__copy(envempty);
	env__free(envempty);
	env__free(envtmp);
	return env;
}

char ** env__append_env(char ** env1, char ** env2) {
 	if (!env1 && !env2) return env__new();
    if (!env2) return env1;
	// we rebuild the entire environment
 	char ** envtmp = env__copy(env1);
	for (int i = 0; i < env__size(env1); i++) envtmp = env__add(envtmp, env1[i]);
	for (int i = 0; i < env__size(env2); i++) envtmp = env__add(envtmp, env2[i]);
	env__free(env1);
	env1 = env__copy(envtmp);
	env__free(envtmp);
	return env1;
}

#endif
