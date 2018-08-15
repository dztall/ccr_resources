//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <assert.h>
#include "Built-Ins/env.h"
#include "Built-Ins/colors.h"
#include "Built-Ins/printfmacro.h"

char * chartostring(char c) {
	char cc[2];
	cc[0] = c;
	cc[1] = '\0';
	return strdup(cc);
}

#define DEBUG if (shell.debug)
#define DEBUG2 if (shell.debug_calls)

#ifndef DEBUG_SLEEP
#define DEBUG_SLEEP /* printf("sleeping for 2 seconds\n") ; sleep(2) ; */
#endif


#ifndef PASSED
#define PASSED DEBUG2 DEBUG_SLEEP fprintf(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#endif

#ifndef PASSED_COLORS
#define PASSED_COLORS
#define PASSED_B DEBUG2 DEBUG_SLEEP fprintf_b(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#define PASSED_R DEBUG2 DEBUG_SLEEP fprintf_r(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#define PASSED_M DEBUGw DEBUG_SLEEP fprintf_m(stderr, "passed %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#endif

#ifndef CURRENT_FUNCTION
#define CURRENT_FUNCTION DEBUG2 printf("->called %s() at line %d from %s\n", __func__, __LINE__, __FILE__);
#endif


#define dothis(what, times) {\
	for(int i = 0;i<times;i++) { what }; \
}


#define SHELL

struct shell {
	char * name;
	char * version;
	int exit;
	int debug;
	int debug_calls;
	int exe;
	int exebackground;
	int internal;
	int builtin;
} shell = { "Shell", "1.1" };

#define MAX 512

char PS1[4096];
char cwd[4096];
char charcurrent, charkeycurrent, charlast;
char input[MAX];
char com[MAX];

#include <libgen.h>

void prompt()
{
   if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
          strcpy(PS1, shell.name);
          strcat(PS1, ":");
          strcat(PS1, basename(cwd));
          strcat(PS1, "$ ");

          printf("%s", PS1);
        }
   else
       perror("getcwd() error");

}

#include "Built-Ins/split.h"



#include "Built-Ins/Built-Ins.h"

#define true 1
#define false 0

// find builtin capability

#ifdef shell__builtins
int have_builtins = true;
#else
int have_builtins = false;
#endif

#define ifb(x) if(strcmp(builtin, x) == 0)
#define elifb(x) else ifb(x)

int builtin(const char * builtin, const int argc, const char * argv[]) {
	if(have_builtins == true) {
		ifb("hex") iftimeret(builtin__hex(argc, argv))
		elifb("cat") iftimeret(builtin__cat(argc, argv))
		elifb("json") iftimeret(puts(builtin__json(argc, argv)))
		elifb("xxd") iftimeret(builtin__xxd(argc, argv))
		elifb("CPUInfo") iftimeret(builtin__CPU_Info(argc, argv))
		elifb("ls") iftimeret(builtin__ls(argc, argv))
		elifb("gcc") iftimeret(builtin__gcc(argc, argv))
		elifb("whereis") iftimeret(builtin__whereis(argc, argv, ".c", true, NULL, whereis_mode_return_first))
		elifb("list") iftimeretc(printf("list of available builtins:\nhex\ncat\njson\nxxd\nCPUInfo\nls\ngcc\nwhereis\nlist\ntime\nexit\nq\n"), 0)
		elifb("time") timefuncretc(, 0)
		elifb("exit") {
			DEBUG printf("exit recognized\n");
        	shell.exit = 1;
    		0;
    	}
		elifb("q") {
			DEBUG printf("exit recognized\n");
        	shell.exit = 1;
    		return 0;
    	}
		else if (shell.builtin == true) iftime(printf("builtin not found, type builtin.list for a list of available built-ins"))
		return -1;
	} else if (shell.builtin == true) iftime(printf("warning, no builtins installed\n"))
	return -2;
}

#define ib(x) if(strcmp(builtin, #x) == 0) return 0;
#define eb(x) else ib(x)

int ifbuiltin(const char * builtin) {
	if(have_builtins == true) {
		ib(hex)
		eb(xxd)
		eb(json)
		eb(CPUInfo)
		eb(ls)
		eb(gcc)
		eb(whereis)
		eb(list)
		eb(time)
		eb(exit)
		eb(q)
	}
	return -1;
}

#include <pthread.h>
pthread_t threads[5];
pthread_attr_t attr;
int rc;
long t;
void *status;

struct command {
	char * vector_line[MAX];
	int vector_line_idx;
	char * vector_word[MAX];
	int vector_word_idx;
	char * vector_wordAND[MAX];
	int vector_wordAND_idx;
	struct word {
		int has_time;
		int vector_has_sub_word;
		int vector_how_many;
		char * vector_sub_word[MAX];
	} vector_sub[MAX];
	struct wordAND vector_subAND[MAX];
} commands;

const char * fix_string(const char * fmt) {
	if (fmt == NULL) return NULL;
	char * tmp = NULL;
	tmp = (char *)malloc(strlen(fmt)*2);
	DEBUG printf("recieved string to fix = %s\n", fmt);
    for (int i = 0;fmt[i]!=0;i++) {
    	DEBUG printf("parsing fmt[%d] = %c\n", i, fmt[i]);
		if (fmt[i] == '\\') {
			sprintf(tmp, "%s%s", tmp, "\\\\");
			mq(qt, tmp);
		    DEBUG printf("CORRECTION tmp = %s\n", qt);
		    free(qt);
		}
		else {
			sprintf(tmp, "%s%c", tmp, fmt[i]);
			mq(qt, tmp);
		    DEBUG printf("tmp = %s\\n", qt);
		    free(qt);
		}
	}
	fmt = strdup(tmp);
	free(tmp);
	mq(qt, fmt);
	DEBUG printf("fixed string = %s\n", qt);
	free(qt);
	return fmt;
}

const char * returnstr(const char * str, const char * replacement) {
	const char * result = strstr(str, replacement);
	if(result == NULL) return "NULL";
	return result;
}

// replace("1;2 ;h h; ;", " ; ", "; ", " ;");
const char * replace(const char * str) {
	if (str == NULL) return NULL;
	char tmp[MAX];
	DEBUG printf("recieved string to fix = %s\n", str);
    for (int i = 0; str[i] != 0 ; i++) {
    	DEBUG printf("parsing fmt[%d] = %c\n", i, str[i]);
		if (str[i] == ';') {
			if (i == 0) sprintf(tmp, "%c", str[i]); // ";"
			else if (i == 0 && str[i+1] != ' ') sprintf(tmp, "%c ", str[i]); // ";a"
			else if (str[i-1] == ' ' && str[i+1] == ' ') sprintf(tmp, "%s%c", tmp, str[i]); // " ; " do nothing
			else if (str[i-1] != ' ' && str[i+1] == '\0') sprintf(tmp, "%s %c",  tmp, str[i]); // "a;"
			else if (str[i-1] == ' ' && str[i+1] == '\0') sprintf(tmp, "%s%c",   tmp, str[i]); // "a ;"
			else if (str[i+1] == ';') sprintf(tmp, "%s %c",  tmp, str[i]); // ";;"
			else if (str[i-1] != ' ' && str[i+1] == ' ') sprintf(tmp, "%s %c",  tmp, str[i]); // "a; "
			else if (str[i-1] == ' ' && str[i+1] != ' ') sprintf(tmp, "%s%c ",  tmp, str[i]); // " ;a"
			else if (str[i-1] != ' ' && str[i+1] != ' ') sprintf(tmp, "%s %c ", tmp, str[i]); // "a;a"
			else {
			    sprintf(tmp, "%s%c", tmp, str[i]);
			    mq(qt,tmp);
		        DEBUG printf("tmp = %s\n", qt);
		        free(qt);
		    }
		    mq(qt,tmp);
		    DEBUG printf("CORRECTION tmp = %s\n", qt);
		    free(qt)
		}
		else {
			sprintf(tmp, "%s%c", tmp, str[i]);
			mq(qt,tmp);
		    DEBUG printf("tmp = %s\n", qt);
		    free(qt);
		}
	}
	str = strdup(tmp);
	mq(qt,str);
	DEBUG printf("fixed string = %s\n", qt);
	free(qt);
	return str;
}

/// const char * replaces(const char * str, const char * replace, const char * with, const char * avoid1, const char * avoid2) {

const char * replaces(const char * str) {
	if (str == NULL) return NULL;
	char tmp[MAX];
    for (int i = 0; str[i] != 0 ; i++) {
		if (str[i] == ';') {
			if (i == 0) sprintf(tmp, "%c", str[i]); // ";"
			else if (i == 0 && str[i+1] != ' ') sprintf(tmp, "%c ", str[i]); // ";a"
			else if (str[i-1] == ' ' && str[i+1] == ' ') sprintf(tmp, "%s%c", tmp, str[i]); // " ; " do nothing
			else if (str[i-1] != ' ' && str[i+1] == '\0') sprintf(tmp, "%s %c",  tmp, str[i]); // "a;"
			else if (str[i-1] == ' ' && str[i+1] == '\0') sprintf(tmp, "%s%c",   tmp, str[i]); // "a ;"
			else if (str[i+1] == ';') sprintf(tmp, "%s %c",  tmp, str[i]); // ";;"
			else if (str[i-1] != ' ' && str[i+1] == ' ') sprintf(tmp, "%s %c",  tmp, str[i]); // "a; "
			else if (str[i-1] == ' ' && str[i+1] != ' ') sprintf(tmp, "%s%c ",  tmp, str[i]); // " ;a"
			else if (str[i-1] != ' ' && str[i+1] != ' ') sprintf(tmp, "%s %c ", tmp, str[i]); // "a;a"
			else {
			    sprintf(tmp, "%s%c", tmp, str[i]);
		    }
		}
		else {
			sprintf(tmp, "%s%c", tmp, str[i]);
		}
	}
	str = strdup(tmp);
	return str;
}

const char * replacespace(const char * str) {
	if (str == NULL) return NULL;
	char tmp[MAX];
	for (int o = 0; o<=2; o++) {
	memset(tmp, 0, MAX);
    for (int i = 0; str[i] != 0 ; i++) {
		if (str[i] == ';' && str[i+1] == ' ') sprintf(tmp, "%s%c",  tmp, str[i]); // ";;"
		else if (str[i] == ' ') {
			if (str[i-1] == ';') {} // "; "
			else if (str[i+1] == ';' || str[i+1] == ' ') {} // " ;" || "  "
			else sprintf(tmp, "%s%c", tmp, str[i]);
		}
		else {
			sprintf(tmp, "%s%c", tmp, str[i]);
		}
	}
	str = strdup(tmp);
	}
	return str;
}



void build(char * lang, int number_of_commands, char ** command_list) {
	DEBUG printf("lang = %s\n", lang);
    DEBUG for (int i = 0; i < number_of_commands; i++) {
        printf("command_list[%d] = %s\n", i, command_list[i]);
    }
    
}

void parseb(int c, char ** arr) {
    ++arr;
    --c;
    build(arr[0], c, arr);
}

int detect_keyword(int argc, char ** argv, int i) {
	if (i == 0 || i == argc-1)
            return 1;
	else {
		if (strcmp(argv[i-1],";") == 0)
             if (strcmp(argv[i+1],";") == 0 )
                 return 1;
	}
	return 0;
}









void * execute(void * tmp) {
	mach_port_t machTID = pthread_mach_thread_np(pthread_self());
	DEBUG printf("machTid is %d\n", machTID);
	struct command *cmd = tmp;
	DEBUG ps(cmd->vector_line[cmd->vector_line_idx])
	DEBUG pi(cmd->vector_line_idx)
	DEBUG pi(cmd->vector_word_idx)
	DEBUG ps(cmd->vector_word[0])
	DEBUG pi(ifbuiltin(cmd->vector_word[0]))
	has_time = commands.vector_sub[0].has_time;
	DEBUG pi(has_time)
	if (!ifbuiltin(cmd->vector_word[0])) return (void *) builtin(cmd->vector_word[0], cmd->vector_word_idx, cmd->vector_word);
	
	// parse sub.words
	for (int idx = 0; idx < cmd->vector_word_idx; idx++) {
		// begin
		if (cmd->vector_sub[idx].vector_has_sub_word == true) {
			shell.internal = true;
			DEBUG printf("sub word detected in word %d\nnumber of sub words contained in word = %d\n", idx, cmd->vector_sub[idx].vector_how_many);
        	DEBUG for (int i = 0; i<cmd->vector_sub[idx].vector_how_many; i++) {
        		mq(qt,cmd->vector_sub[idx].vector_sub_word[i]);
        		printf("cmd->vector_sub[%d].word[%d] = %s\n", idx, i, qt);
        		free(qt);
        	}
			// parse shell settings
			if (strcmp(cmd->vector_sub[idx].vector_sub_word[0], "shell") == 0) {
				DEBUG printf("parsing shell core setting\n");
				if (strcmp(cmd->vector_sub[idx].vector_sub_word[1], "debug") == 0) {
					shell.debug = atoi(cmd->vector_word[1]);
                	printf("shell debug turned %s\n", shell.debug?"on":"off");
             	}
             	if (strcmp(cmd->vector_sub[idx].vector_sub_word[1], "exe") == 0) {
					shell.exe = atoi(cmd->vector_word[idx+1]);
                	printf("shell execution turned %s\n", shell.exe?"on":"off");
             	}
            }
            // pass builtins
            else if (strcmp(cmd->vector_sub[idx].vector_sub_word[0], "builtin") == 0) {
            	shell.builtin = true;
            	DEBUG printf("parsing builtin\n");
            	builtin(cmd->vector_sub[idx].vector_sub_word[1], cmd->vector_word_idx, cmd->vector_word);
            	// unlike shell settings, we cannot parse multiple builtins on one line
            	shell.internal = false;
            	break;
            }
            else {
            	// no settings or builtins where detected, re-enable execution
            	shell.internal = false;
            	shell.builtin = false;
            }
        }
        // end
    }
    
    if (shell.exe == true && shell.internal == false && shell.builtin == false) {
		mq(qt,cmd->vector_line[cmd->vector_line_idx]);
    	DEBUG printf("executing [%d]: %s\ni am pid %d\n", cmd->vector_line_idx, qt, getpid());
    	free(qt);
    	char * exe;
    	exe = builtin__whereis(cmd->vector_word_idx, cmd->vector_word, ".c", false, NULL, whereis_mode_return_first);
    	int ret;
    	if(exe) {
    		ret = 0;
    		iftime(execvp(exe, cmd->vector_word));
    	}
    	else {
    		iftime()
    		ret = -1;
    	}
    	return (void *) ret;
    }
    else if (shell.builtin == true) shell.builtin = false;
    else if (shell.internal == true) {
    	DEBUG printf("ERROR: execution is disabled when parsing shell core settings\n");
    	shell.internal = false;
    }
    else {
    	printf("ERROR: execution is disabled\n");
    	return (void *) -2;
    }
    return (void *) 0;
}








void execute_thread(struct command ** commands) {
	mach_port_t machTID = pthread_mach_thread_np(pthread_self());
	DEBUG printf("machTid is %d\n", machTID);
	/* Initialize and set thread detached attribute */
	pthread_attr_init(&attr);
    pthread_create(&threads[1], &attr, &execute, commands);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_destroy(&attr);
	for (t = 1; t < 2; t++) {
		rc = pthread_join(threads[t], &status);
		if (rc) {
			DEBUG printf("ERROR; return code from pthread_join() is %d\n", rc);
			exit(-1);
		}
		DEBUG printf("Main: completed join with thread %ld having a status of %d\n", t, (int)status);
	}
	DEBUG printf("thread completed.\n");
}




















void parse_special_commands(int cc, char * command_list[]) {
	for (int i = 0; i<cc; i++) commands.vector_line[i] = command_list[i];
	for (commands.vector_line_idx = 0; commands.vector_line_idx < cc; commands.vector_line_idx++) {
        commands.vector_sub[0].has_time = false;
		mq(qt,commands.vector_line[commands.vector_line_idx]);
        DEBUG printf("commands.vector_line[%d] = %s\n", commands.vector_line_idx, qt);
        free(qt);
        // split current line into words
        char **t, **tt;
        int c;
        string_to_argv(commands.vector_line[commands.vector_line_idx], &c, &t);
        //int c = split(commands.vector_line[commands.vector_line_idx], ' ', &t);
        for (int i = 0; i<c; i++) {
        	int a = split(replacespace(replaces(t[i])), '&', &tt);
        	if (a > 1) for (int ii = 0; ii<a; ii++) {
        		mq(qt,t[ii]);
        		DEBUG printf("tt[%d] = %s\n", ii, qt);
        		free(qt);
        		commands.vector_wordAND[i] = strdup(t[ii]);
        		i++;
        	}
        	if (i>=c) {
        		break;
        	}
        	mq(qt,t[i]);
        	DEBUG printf("t[%d] = %s\n", i, qt);
        	free(qt);
        	commands.vector_word[i] = strdup(t[i]);
        	freesplit(a, &tt);
        }
        PASSED
        DEBUG pi(c)
        if (c > 1 && strcmp(commands.vector_word[0], "time") == 0) {
        	int size = sizeof(commands.vector_word)/sizeof(commands.vector_word[0]);
        	for (int i = 0; i<size; i++) {
        		if (i+2 <= size) commands.vector_word[i] = commands.vector_word[i+1];
        		else commands.vector_word[i] = NULL;
        	}
        	c--;
        	if (strcmp(commands.vector_word[0], "time") == 0) puts("still has time");
        	commands.vector_sub[0].has_time = true;
        }
        //freesplit(c, &t);
        free(t);
        commands.vector_word[c] = NULL;
        // each vector index corresponds to the word index
        for (commands.vector_word_idx = 0; commands.vector_word_idx < c; commands.vector_word_idx++) {
        	mq(qt,commands.vector_word[commands.vector_word_idx]);
        	DEBUG printf("commands.vector_word[%d] = %s\n", commands.vector_word_idx, qt);
        	free(qt);
        	// if word contains a sub word, we split it
        	// save to temporary variable first
        	char ** tt;
        	int cc = split(commands.vector_word[commands.vector_word_idx], '.', &tt);
        	for (int i = 0; i<cc; i++) {
        		mq(qt,tt[i]);
            	DEBUG printf("tt[%d] = %s\n", i, qt);
            	free(qt);
            	commands.vector_sub[commands.vector_word_idx].vector_sub_word[i] = strdup(tt[i]);
            }
            freesplit(cc, &tt);
        	// if cc is 1 then the words does not contain a sub word
        	if (cc > 1) {
        		// word contains a sub word, mark and split
        		DEBUG printf("marking cmd->vector_sub[%d].vector_has_sub_word = true\n", commands.vector_word_idx);
        		commands.vector_sub[commands.vector_word_idx].vector_has_sub_word = true;
        		commands.vector_sub[commands.vector_word_idx].vector_how_many = cc;
        		DEBUG printf("sub word detected\n");
        	    DEBUG printf("cc = %d\n", cc);
        	    DEBUG for (int i = 0; i<cc; i++) {
        	    	mq(qt,commands.vector_sub[commands.vector_word_idx].vector_sub_word[i]);
        	    	printf("commands.vector_sub[%d].word[%d] = %s\n", commands.vector_word_idx, i, qt);
        	    	free(qt);
        	    }
        	}
        	else {
        		// else we unmark it to prevent cross marking
        		DEBUG printf("marking cmd->vector_sub[%d].vector_has_sub_word = false\n", commands.vector_word_idx);
        		commands.vector_sub[commands.vector_word_idx].vector_has_sub_word = false;
        		commands.vector_sub[commands.vector_word_idx].vector_how_many = 0;
        	}
        }
        execute_thread(&commands);
        if (shell.exit == 1) {
		    return;
	    }
        DEBUG printf("\n");
    }
}

















int parse(const char * args)
{
	mq(qt,args);
	DEBUG printf("parsing: %s\n", qt);
	free(qt);
    char **ar = NULL;
    // fix string then split into lines
	int cc = split(replacespace(replaces(args)), ';', &ar);
    parse_special_commands(cc, ar);
    freesplit(cc, &ar);
    if (shell.exit == 1) {
    	printf("exiting\n");
    	return 1;
	}
	return 0;
    //parseb(c, arr);
}

void test_parser(int num) {
	CURRENT_FUNCTION
    for (int i = 0; i < num; i++) {
	    parse("test line ; sub.word.test.1; sub.word.test.2 ; bash ; version 1.2.4 ;");
	    parse("shell.exe 0 shell.exe 1 shell.exe 0 shell.exe 1");
	    parse("return42 ; cat return42.c ; exit42 ; cat exit42.c ; true;false");
	}
}

void test_builtin(int num) {
	CURRENT_FUNCTION
    for (int i = 0; i < num; i++) {
    	PASSED
	    parse("builtin.cat");
    	PASSED
		parse("builtin.hex ");
    	PASSED
		parse("builtin.xxd");
    	PASSED
		parse("builtin.json");
    	PASSED
		parse("builtin.CPUInfo");
    	PASSED
		parse("builtin.gcc help");
    	PASSED
		parse("builtin.help");
    	PASSED
	}
}

void test_variables(int num) {
	CURRENT_FUNCTION
    for (int i = 0; i < num; i++) {
    	PASSED
	    parse("$1;     $2     ;$1;$4");
    	PASSED
	}
}

void test_background_execution(int num) {
	CURRENT_FUNCTION
    if (shell.exebackground) {
    	for (int i = 0; i < num; i++) {
	    	PASSED
	    	parse("");
	    	PASSED
		    parse("t;a&y;a& b w&7;a.a&w.a&");
	    	PASSED
		}
	}
}

void test_time(int num) {
	CURRENT_FUNCTION
    for (int i = 0; i < num; i++) {
	    parse("time test line ; sub.word.test.1; time sub.word.test.2 ; bash ; time bash; time version 1.2.4 ;");
	    parse("shell.exe 0 shell.exe 1 shell.exe 0 shell.exe 1");
	    parse("time return42 ; time cat return42.c ; exit42 ; cat exit42.c ; true;false");
	}
}

void test_all(int num) {
	for (int i = 0; i < num; i++) {
    	PASSED
		test_parser(1);
    	PASSED
		test_variables(1);
    	PASSED
		test_builtin(1);
    	PASSED
		test_background_execution(1);
    	PASSED
	}
}
