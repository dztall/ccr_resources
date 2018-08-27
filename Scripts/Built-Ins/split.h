#pragma once

#ifndef SPLIT
#define SPLIT
int split (const char *strconst, char c, char ***arr) {
	*arr =  env__new();
	char * pathtmp = strdup(strconst);
	int i=0;
	for (char *tok = strtok(pathtmp, chartostring(c)); tok; tok = strtok(NULL, chartostring(c))) {
		*arr = env__add(*arr, tok);
		i++;
	}
	free(pathtmp);
	return i;
}

void freesplit(int c, char *** a) {
	env__free(*a);
}
#endif
