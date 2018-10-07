#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <err.h>
#include <stdbool.h>
#include "../ccr_resources_REAL/Scripts/Shell/builtins/regex_str.h"

void defwrite(char * file, char * mode, char * contents) {
    FILE * t = fopen(file, mode);
    fwrite(contents, strlen(contents), 1, t);
    fclose(t);
}

#define ps(x)      printf("%s = %s\n", #x, x);
#define pi(x)      printf("%s = %d\n", #x, x);
#define try printf("trying %s\n", ph); printf("%s '%s'\n", access(ph, F_OK)==0?"found":"could not find", ph);
#define WS_NONE		0
#define WS_RECURSIVE	(1 << 0)
#define WS_DEFAULT	WS_RECURSIVE
#define WS_FOLLOWLINK	(1 << 1)	/* follow symlinks */
#define WS_DOTFILES	(1 << 2)	/* per unix convention, .file is hidden */
#define WS_MATCHDIRS	(1 << 3)	/* if pattern is used on dir names too */
#define WS_CLEAN	(1 << 4)	/* removal mode */
#define WS_LS	(1 << 5)	/* ls mode */
#define is(x) strcmp(str_found, x) == 0
#define isc(str, i, x) str[i] == x
#define erase(string, size) memset(string,0,size)
#define DIRMAX 4096

enum {
	WALK_OK = 0,
	WALK_BADPATTERN,
	WALK_NAMETOOLONG,
	WALK_BADIO,
};

int is_root = 0, is_slash = 0;
int res = WALK_OK;
int spec;

char *strstr_backward(char *str, const char *str_find)
{
	char *str_found_backward = NULL;
	char *str_found = NULL;
	size_t position = 0;

	while ((str_found = (char *)strstr(str + position, str_find)) != NULL)
	{
		str_found_backward = str_found;
		position = (str_found - str) + 1;
	}

	return str_found_backward;
}

char dircurrent[DIRMAX];
char dirlast[DIRMAX];
char dirfile[DIRMAX];
char dirdefines[DIRMAX];
char contents[DIRMAX*2];
char definition[DIRMAX*2];
char * defstring = "#define ";

int defformat(const char * str) {
	memset(definition, 0, DIRMAX*2);
	char underscore = '_';
	if (str == NULL) return -1;
	int i_defstring = 0;
	int i_definition = 0;
	int i_string = 0;
	for (; i_defstring < strlen(defstring); i_defstring++) {
		memcpy(definition+i_definition, defstring+i_defstring, 1);
		i_definition++;
	}
	int len = strlen(str)+i_definition;
	for (; i_definition < len; i_definition++) {
		if (
			isc(str, i_string, '/') ||
			isc(str, i_string, '.')
		) memcpy(definition+i_definition, &underscore, 1);
		else memcpy(definition+i_definition, str+i_string, 1);
		i_string++;
	}
	*(definition+i_definition) = '\n';
	return 0;
}
int count = 0;
void def(char * dir, char * long_name, bool is_directory) {
	char * ext = "";
	if (is_directory == true) ext=".h";
	int dir_updated = 0;
	if (dirlast == NULL) {
		if (dircurrent) {
			erase(dirlast, DIRMAX);
			strncpy(dirlast, dircurrent, DIRMAX);
			dirname(dirlast);
			dir_updated = 1;
		}
	}
	erase(dircurrent, DIRMAX);
	strncpy(dircurrent, long_name, DIRMAX);
	dirname(dircurrent);
	if (dirlast) {
		if (strcmp(dircurrent, dirlast) != 0) {
			erase(dirlast, DIRMAX);
			strncpy(dirlast, long_name, DIRMAX);
			dirname(dirlast);
			dir_updated = 1;
		}
	}
	if (dir_updated) {
		erase(dirfile, DIRMAX);
		snprintf(dirfile, DIRMAX, "%s.h", dircurrent);
		snprintf(dirdefines, DIRMAX, "%s/%sdefines.h", dir, dir);
		if ((spec & WS_CLEAN)) {
			printf("rm \"%s\"\n", dirfile);
			unlink(dirfile);
			unlink(dirdefines);
		}
		else {
			defformat(dirfile);
			printf("echo -e \"%s\" >> %s\n", definition, dirdefines);
			defwrite(dirdefines, "a+", definition);
		}
	}
	if (!(spec & WS_CLEAN)) {
		if (is_directory == false) { // dont generate includes for directories
			erase(contents, DIRMAX*2);
			char * d = basename(dirname(strdup(long_name)));
			snprintf(contents, DIRMAX*2, "#include \"%s/%s%s\"\n", d, basename(long_name), ext);
			printf("echo -e \"#include \\\"%s/%s%s\\\"\\n\" >> %s\n", d, basename(long_name), ext, dirfile);
			defwrite(dirfile, "a+", contents);
		}
	}
}

int process(char * dir, char * long_name, struct dirent *dent, bool print, char * extention, int spec) {
	if (!(spec & WS_DOTFILES) && dent->d_name[0] == '.')
		return 0;
	if (!strcmp(dent->d_name, ".") || !strcmp(dent->d_name, "..")) {
		return 0;
	}
	
	
	struct stat st;
 
	if (lstat(long_name, &st) == -1) {
		warn("Can't stat %s", long_name);
		res = WALK_BADIO;
		return 0;
	}
 
	/* don't follow symlink unless told so */
	if (S_ISLNK(st.st_mode) && !(spec & WS_FOLLOWLINK))
		return 0;
 
	/* will be false for symlinked dirs */
	if (S_ISDIR(st.st_mode)) {
		/* recursively follow dirs */
		if ((spec & WS_RECURSIVE)) {
			def(dir, long_name, true);
			return -1;
		}
 
		if (!(spec & WS_MATCHDIRS)) return 0;
	}
	if (S_ISREG(st.st_mode)) {
		char *str_found = NULL;
		if ((str_found = strstr_backward(long_name, ".")) != NULL)
		{
			char *hardcoded_platform_specific_path_separator = ":";
			char * pathtmp = NULL;
			pathtmp = strdup(extention);
			char ph[DIRMAX];
			for (char *tok = strtok(pathtmp, hardcoded_platform_specific_path_separator); tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
				if (is(tok)) {
					def(dir, long_name, false);
				}
				else print = false;
			}
			free(pathtmp);
			memset(str_found, 0, strlen(str_found));
		}
	}
	return 0;
}

int walk_recur(char * dn, char *dname, char * extention, int spec)
{
	count++;
	if (count == 1) {
		snprintf(dirdefines, DIRMAX, "%s/%sdefines.h", dn, dn);
		printf("touch %s\n", dirdefines);
		fclose(fopen(dirdefines,"w"));
	}
	// case 1, if path is root itself, correct d_name
	if (dname[0] == '/' && dname[1] == '\0') is_root = 1;
	// case 2, if path ends in / but is not root itself, remove it
	if (!is_root) if (dname[strlen(dname)-1] == '/') {
		dname[strlen(dname)-1] = 0;
		is_slash = 1;
	}
	struct dirent *dent;
	DIR *dir;
	char fn[FILENAME_MAX];
	char fntmp[FILENAME_MAX];
	int len = strlen(dname);
	if (len >= FILENAME_MAX - 1)
		return WALK_NAMETOOLONG;
 
	strcpy(fn, dname);
 
	if (!(dir = opendir(dname))) {
		warn("can't open %s", dname);
		return WALK_BADIO;
	}
 
	errno = 0;
	while ((dent = readdir(dir))) {
		strcpy(fntmp, dname);
		if (!is_root) strcat(fntmp, "/");
		strcat(fntmp, dent->d_name);
		bool print = false;
		int ret = process(dn, fntmp, dent, print, extention, spec);
		if (!ret) continue;
		else walk_recur(dn, fntmp, extention, spec);
	}
	if (dir) closedir(dir);
	return res ? res : errno ? WALK_BADIO : WALK_OK;
}
 
int walk_dir(char *dname, char * extention, int spec)
{
	return walk_recur(dname, dname, extention, spec);
}

void defclean(char * filename) {
	count = -1;
	if (filename == NULL) filename=".";
	if (strcmp(filename, "") == 0) filename = ".";
	spec = WS_DEFAULT|WS_CLEAN;
	int r = walk_dir(filename, ".c:.h", spec);
	switch(r) {
		case WALK_OK:		break;
		case WALK_BADIO:	break;//err(1, "IO error");
		case WALK_BADPATTERN:	err(1, "Bad pattern");
		case WALK_NAMETOOLONG:	err(1, "Filename too long");
		default:
			err(1, "Unknown error?");
	}
	return 0;
}

void defgenlist(char * filename) {
	count=0;
	if (filename == NULL) filename=".";
	if (strcmp(filename, "") == 0) filename = ".";
	spec = WS_DEFAULT;
	int r = walk_dir(filename, ".c:.h", spec);
	switch(r) {
		case WALK_OK:		break;
		case WALK_BADIO:	break;//err(1, "IO error");
		case WALK_BADPATTERN:	err(1, "Bad pattern");
		case WALK_NAMETOOLONG:	err(1, "Filename too long");
		default:
			err(1, "Unknown error?");
	}
	return 0;
}

int main(void) {
	defclean("lex");
	defgenlist("lex");
}
