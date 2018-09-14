//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123
#include "../builtins/env.h"

char ** EVALWRAP_INTERNAL_VARIABLE_LIST;
void Expression_Assign_free(void) {
    puts("freeing EVALWRAP_INTERNAL_VARIABLE_LIST");
    env__free(EVALWRAP_INTERNAL_VARIABLE_LIST);
}

void Expression_Assign(char * name, void * variable) {
    if (!EVALWRAP_INTERNAL_VARIABLE_LIST) {
        EVALWRAP_INTERNAL_VARIABLE_LIST = env__new();
        atexit(Expression_Assign_free);
    }
    int len = strlen(name)+strlen("=")+sizeof(char*)+1;
    char * str = malloc(len);
    memset(str, 0, len);
    sprintf(str,"%s=%p",name, variable);
    EVALWRAP_INTERNAL_VARIABLE_LIST = env__add(EVALWRAP_INTERNAL_VARIABLE_LIST, name);
    memset(str, 0, len);
    free(str);
    env__list(EVALWRAP_INTERNAL_VARIABLE_LIST);
};


char ** vars;

int main(int argc, char *argv[])
{
    int i;
    Expression_Assign("a", &i);
    Expression_Assign("b", &i);
    Expression_Assign("c", &i);
	return 0;
}
