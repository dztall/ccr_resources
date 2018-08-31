#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../ccr_resources/Shell/builtins/builtins.h"

int depth;

char * argv_to_string(char * argv0, int argc, char ** argv) {
	char * cmd = malloc(4096);
	if (argv0) snprintf(cmd, 4096, "%s", argv0);
	for (int i = argv0?1:0; i< argc; i++) snprintf(cmd, 4096, "%s %s", cmd, argv[i]);
	return cmd;
}
			

FILE * fif_file;

#define print_usage(x) fprintf(file, "%s\n", x);
#define print_usage_command(x) fprintf(file, "\t%s\n", x);
#define print_usage_command_info(x) fprintf(file, "\t\t\t\t%s\n", x);

void fusage(void){
	print_usage("usage: find [path] [option]")
	print_usage_command("-name [file]")
	print_usage_command_info("searches [path] recursively for [file]")
	print_usage_command("-o [file]")
	print_usage_command_info("redirects all output into [file]")
}

int is_out = 0;

void findinfiles(const char *name, const char * regex)
{
	if (!is_out) fif_file = stdout;
	char *is_name = NULL, *is_type = NULL;
	int argc, is_root = 0, is_slash = 0;
	char ** argv;
	string_to_argv(name, &argc, &argv);
	//builtin__argv(argc, argv);
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
			if (is_out) {
				fclose(fif_file);
				fif_file = stdout;
				is_out = 0;
			}
			fusage();
			return;
		}
		else if (!strcmp(argv[i], "-o")) {
			i++;
			if (!is_out) {
				is_out = 1;
				fif_file = fopen(argv[i], "a+");
				if (!fif_file) {
					puts("failed to set out");
					fif_file = stdout;
					is_out = 0;
				}
			}
		}
		else if ((argv[i])[0]== '-') {
			if (is_out) {
				fclose(fif_file);
				fif_file = stdout;
				is_out = 0;
			}
			fprintf(file, "invalid command: '%s'\n", argv[i]);
			fusage();
			return;
		}	
	}
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(argv[0]))) {
    	char path1[1024+1024], path2[1024+1024];
	    snprintf(path2, sizeof(path2), "%s \"%s\" -n", regex, argv[0]);
        snprintf(path1, sizeof(path1), "%s -q", path2);
        int ret;
        if (is_name) {
			if (strcmp(is_name, entry->d_name) == 0) ret = grep(path1);
		}
		else ret = grep(path1);
    	if (!ret) {
    		printf_b("%s:\n", argv[0]);
	        if (is_name) {
				if (strcmp(is_name, entry->d_name) == 0) grep(path2);
			}
			else grep(path2);
			puts("");
    	}
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
			depth++;
            snprintf(path, sizeof(path), "%s%s%s%s", argv[0], is_root?"":(is_slash?"/":"/"), entry->d_name, is_root?"/":(is_slash?"/":""));
            mq(qp,path);
			char * cmd = argv_to_string(qp, argc, argv);
            free(qp);
            findinfiles(cmd, regex);
			free(cmd);
			depth--;
        } else {
            char pathF[1024+1024], pathG[1024+1024], pathA[1024];
            snprintf(pathA, sizeof(pathA), "%s%s%s", argv[0], is_root?"":(is_slash?"/":"/"), entry->d_name);
            snprintf(pathF, sizeof(pathF), "%s \"%s\" -n", regex, pathA);
	        snprintf(pathG, sizeof(pathG), "%s -q", pathF);
	        int ret;
	        if (is_name) {
				if (strcmp(is_name, entry->d_name) == 0) ret = grep(pathG);
			}
			else ret = grep(pathG);
	    	if (!ret) {
	    		printf_b("%s:\n", pathA);
		        if (is_name) {
					if (strcmp(is_name, entry->d_name) == 0) grep(pathF);
				}
				else grep(pathF);
				puts("");
	    	}
        }
    }
    closedir(dir);
    if (is_out && !depth) {
		fclose(fif_file);
		fif_file = stdout;
		is_out = 0;
	}
			
}
