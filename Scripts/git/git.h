//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include <stdio.h>
#include <unistd.h>
#include <string.h>
Garbage_Collector_Options |= Garbage_Collector_Options_Quiet;

#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ x
#else
# define UNUSED(x) x
#endif

//#include "../../shells/Built-Ins/argv.h"

#include "../Shell/builtins/builtins.h"

shell.debug_calls = true;

int git(char * str);

#include "git_macros.h"
/*

we provide two methods of including the libgit header

1. use the built-in header

#define git_libgit_version_2_standard

2. use the newest libgit headers

#define git_libgit_version_2_new

*/

// for compatibility we use the standard git header provided by the hosts libgit2 installation

#define git_libgit_version_2_standard

int using_defined = false;
char * defined_username = "mgood7123";
char * defined_password = "";

#include "common.h"

#include "callbacks/cred.h"


#include "git_init.h"
#include "git_add.h"
#include "git_auto.h"
#include "git_config.h"
#include "git_clone.h"
#include "git_curl.h"
#include "git_commit.h"
#include "git_general.h"
#include "git_log.h"
#include "git_merge.h"
#include "git_push.h"
#include "git_remote.h"
#include "git_stat.h"
#include "git_tests.h"

int gitprefix(show_usage)(void) {
	usage_print("usage: git [command] [action]")
	usage_print_command("git init repo")
	usage_print_command_info("initializes an empty git repository")
	return -1;
}

int gitprefix(clean_init)(void) {
	int inits_remaining = git_libgit2_init();
	int shutdowns_remaining = git_libgit2_shutdown();
	inits_remaining--;
	if (!inits_remaining && !shutdowns_remaining) {
		puts("nothing to clean");
		return 0;
	}
	if (inits_remaining < 0) {
		pi(inits_remaining)
		while(inits_remaining < 1) {
			inits_remaining = git_libgit2_init();
			pi(inits_remaining)
		}
		pi(inits_remaining)
	}
	if (shutdowns_remaining > 0) {
		pi(shutdowns_remaining)
		while(shutdowns_remaining > 0) {
			shutdowns_remaining = git_libgit2_shutdown();
			pi(shutdowns_remaining)
		}
	}
	return 0;
}

int gitprefix(clean)(int argc, char * argv[]) {
	if (argc < 2) giterrornomessage("%s requires an additional command", argv[0]);
	if(strcmp(argv[1], "init") == 0) return gitprefix(clean_init)();
	else giterrornomessage("%s is not a valid sub command of %s", argv[1], argv[0]);
}
int gitprefix(dotgit)(int argc, char * argv[]) {
	if (access(".git",F_OK) == -1) {
		puts("no .git to move");
		return -1;
	}
	puts("attempting to move ./.git to ./dotgit");
	system("mv .git dotgit");
	return 0;
}

int git(char * str) {
	int argc;
	char ** argv;
	string_to_argv(str, &argc, &argv);
	//builtin__argv(argc, argv);
	if (argc == 0) {
		free(argv);
		return gitprefix(show_usage)();
	}
	
	     gitdo(init)
	else gitdo(add)
	else gitdo(auto)
	else gitdo(clean)
	else gitdo(clone)
	else gitdo(config)
	else gitdo(commit)
	else gitdo(curl)
	else gitdo(dotgit)
	else gitdo(general)
	else gitdo(log)
	else gitdo(merge)
	else gitdo(push)
	else gitdo(remote)
	else gitdo(stat)
	else gitdo(status)
	else gitdo(test)
	else giterrornomessage("%s is not a valid command", argv[0]);
	return 0;
}
