#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <err.h>
#ifndef shell__builtins
#include "printfmacro.h"
#include <stdbool.h>
#include "usage.h"
#endif

void fusage(void){
	usage_print("usage: find [path] [option]")
	usage_print_command("-name [file]")
	usage_print_command_info("searches [path] recursively for [file]")
	usage_print_command("-o [file]")
	usage_print_command_info("redirects all output into [file]")
	usage_print_command("-type [type]")
	usage_print_command_info("only finds files of type [type]")
	usage_print_command_info("d  - directory")
	usage_print_command_info("f  - folder")
}

enum {
	WALK_OK = 0,
	WALK_BADPATTERN,
	WALK_NAMETOOLONG,
	WALK_BADIO,
};

#define WS_NONE		0
#define WS_RECURSIVE	(1 << 0)
#define WS_DEFAULT	WS_RECURSIVE
#define WS_FOLLOWLINK	(1 << 1)	/* follow symlinks */
#define WS_DOTFILES	(1 << 2)	/* per unix convention, .file is hidden */
#define WS_MATCHDIRS	(1 << 3)	/* if pattern is used on dir names too */
#define WS_RM	(1 << 4)	/* removal mode */
#define WS_LS	(1 << 5)	/* ls mode */
int is_root = 0, is_slash = 0;
int res = WALK_OK;
int spec;
 
int process(char * long_name, struct dirent *dent, bool print, int spec) {
	if (print == true) {
		if (!(spec & WS_RM)) puts(long_name);
		else if ((spec & WS_RM)) {
			printf("REMOVING FILE: %s\n", long_name);
			unlink(long_name);
			return 0;
		}
	}
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
		if ((spec & WS_RECURSIVE)) return -1;
			
 
		if (!(spec & WS_MATCHDIRS)) return 0;
	}
	return 0;
}
int walk_recur(char *dname, regex_t *reg, int spec)
{
	//ps(dname)
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
	//puts(fn);
 
	if (!(dir = opendir(dname))) {
		warn("can't open %s", dname);
		return WALK_BADIO;
	}
 
	errno = 0;
	while ((dent = readdir(dir))) {
		strcpy(fntmp, dname);
		if (!is_root) strcat(fntmp, "/");
		strcat(fntmp, dent->d_name);
		if (!(spec & WS_RM)) if (dent->d_type == DT_DIR && !(!strcmp(dent->d_name, ".") || !strcmp(dent->d_name, ".."))) strcat(fntmp, "/");
		bool print = false;
		if (*reg) {
			if (!regexec(reg, fn, 0, 0, 0)) print = true;
		}
		else {
			if (spec & WS_RM) {
				if (dent->d_type != DT_DIR) print = true;
				else print = false;
			}
			else print = true;
		}
		int ret = process(fntmp, dent, print, spec);
		if (!ret) continue;
		else walk_recur(fntmp, reg, spec);
	}
	if (spec & WS_RM) {
		printf("REMOVING DIRECTORY: %s\n", fn);
		rmdir(fn);
	}
 
	if (dir) closedir(dir);
	return res ? res : errno ? WALK_BADIO : WALK_OK;
}
 
int walk_dir(char *dname, char *pattern, int spec)
{
	regex_t r;
	int res = 0;
	if (pattern) {
		ps(pattern);
		if (regcomp(&r, pattern, REG_EXTENDED | REG_NOSUB))
		return WALK_BADPATTERN;
	}
	res = walk_recur(dname, &r, spec);
	if (pattern) regfree(&r);
 
	return res;
}

#include "usage.h"

int rmusage(void) {
	usage_print("usage: rm -r PATH");
	return -1;
}

int find(int argc, char * argv[])
{
	spec = WS_DEFAULT|WS_MATCHDIRS|WS_DOTFILES;
	if (strcmp(argv[0], "rm") == 0) spec |= WS_RM;
	char * path;
    char * reg;
    if (!(spec & WS_RM)) {
	    if (argc == 1) {
	        path = ".";
	        reg = NULL;
	    }
	    else if (argc == 2) {
	        path = argv[1];
	        reg = NULL;
	    }
	    else if (argc == 3) {
	        path = argv[1];
	        reg = argv[2];
	    }
	}
	else {
		if (argc == 1) {
	        return rmusage();
	    }
	    else if (argc == 2) {
	        path = argv[1];
	        reg = NULL;
	    }
		else return rmusage();
	}
	int r = walk_dir(path, reg, spec);
	switch(r) {
		case WALK_OK:		break;
		case WALK_BADIO:	err(1, "IO error");
		case WALK_BADPATTERN:	err(1, "Bad pattern");
		case WALK_NAMETOOLONG:	err(1, "Filename too long");
		default:
			err(1, "Unknown error?");
	}
	return 0;
}
