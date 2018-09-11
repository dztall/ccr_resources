//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#pragma once

#ifndef __SHELL_ENV
#include "env.h"
#endif
#ifndef SPLIT
#include "split.h"
#endif

#ifndef SHELL
	#define SHELLtmp
	#ifndef shell__builtins
		#ifndef shell__builtinstmp
			#define shell__builtinstmp
			struct shell {
				char * name;
			} shell = { "Shell" };
			#define DEBUG if(1)
			#include "printfmacro.h"
		#endif
	#endif
#endif


#define file__path 1
#define file__relative 2
#define file__directory 3
#define whereis_mode_print_all 1
#define whereis_mode_return_first 2
#define whereis_mode_return_all_as_path 3
#define whereis_mode_return_all_as_string 4

#define try DEBUG printf("trying %s\n", ph); if (access(ph, F_OK) == 0) { if (shell.builtin) printf("found '%s' at '%s'\n", file, ph); return ph; }

// mosh appears to handle lookup in this order: cwd, scripts, path

char * builtin__whereis(const int argc, const char * argv[], const char * extention, int skip_arg0, char * optional_path, int mode) {
	if (extention == NULL) extention = "";
	int mode, arg_number;
	if(*argv[skip_arg0] == '.' && *argv[skip_arg0]+1 == '/') mode = file__relative;
	else if (*argv[skip_arg0] == '/') mode = file__directory;
	else {
		char ** tt;
		int c = split(argv[skip_arg0], '/', &tt);
    	if (c == 1 && *argv[skip_arg0] != '.') mode = file__path;
    	freesplit(c, &tt);
	}
	
	char * file = argv[skip_arg0];
	
	if (optional_path == NULL && (mode == file__relative || mode == file__directory)) {
		if (access(argv[skip_arg0], F_OK) == 0) {
			if (shell.builtin) printf("found '%s' at '%s'\n", argv[skip_arg0], argv[skip_arg0]);
			return strdup(argv[skip_arg0]);
		}
	}
	else {
		char * path = env__get(environ_default?environ_default:environ, "PATH");
		char ph[4096];
	  	if (!path) path = "/bin:/usr/bin:/usr/local/bin";
		sprintf(path, "%s/CCR/Scripts:%s:%s/CCR/Scripts", env__get(environ_default?environ_default:environ, "CPP_DATA_DIR"), path, env__get(environ_default?environ_default:environ, "CPP_RESOURCE_DIR"));
		if (path == NULL) {
			puts("environment variable PATH is unset; cannot proceed");
			return NULL;
		}
		char *hardcoded_platform_specific_path_separator = ":";
		char * pathtmp = NULL;
		// includes are searched first
		if (optional_path != NULL) {
			pathtmp = strdup(optional_path);
			for (char *tok = strtok(pathtmp, hardcoded_platform_specific_path_separator); tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
				sprintf(ph, "%s/%s%s", tok, file, extention);
				try
				sprintf(ph, "%s/%s.proj%s", tok, file, extention);
				try
				// update puts .proj in named folders, we search both for compatibility with older versions
				sprintf(ph, "%s/%s/%s.proj%s", tok, file, file, extention);
				try
			}
			free(pathtmp);
		}
		pathtmp = strdup(path);
		for (char *tok = strtok(pathtmp, hardcoded_platform_specific_path_separator); tok; tok = strtok(NULL, hardcoded_platform_specific_path_separator)) {
			sprintf(ph, "/var/%s/%s%s", tok+4, file, extention);
			try
			sprintf(ph, "/var/%s/%s.proj%s", tok+4, file, extention);
			try
			// update puts .proj in named folders, we search both for compatibility with older versions
			sprintf(ph, "/var/%s/%s/%s.proj%s", tok+4, file, file, extention);
			try
		}
		free(pathtmp);
		sprintf(ph, "./%s%s", file, extention);
		try
		sprintf(ph, "./%s.proj%s", file, extention);
		try
	}
	printf("%s: %s not found\n", skip_arg0?file:shell.name, file);
	return NULL;
}
