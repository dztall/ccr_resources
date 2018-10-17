//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

// for gcc builtin to be timed in detail, we need to set up seperate timers for each step, but what should we identify as a "step"?

/*

clock__add(timefunc_start);
clock__add(timefunc_end);

#define timefunc(func) { \
	clock__set(timefunc_start); \
	func; \
	clock__set(timefunc_end); \
	printf("cpu time: %.2f seconds\n", clock__calculate(timefunc_start, timefunc_end)); \
}



to time a initiation such as

int a = clock();

we could change this to

int a;
timefunc(a = clock())

tho additional time may be spent during the assignment of the variable

*/

#include <ccr.h>

// we enum to allow for preprocessing of #x as definition string of the define itself instead of its value
enum {
	// prepend _ to allow for preprocessing (if any) to still work on these defines
	
	_CPP_NO_ERROR=CPP_NO_ERROR,
	_CPP_OUT_OF_MEMORY=CPP_OUT_OF_MEMORY,
	_CPP_INVALID_ARGUMENTS=CPP_INVALID_ARGUMENTS,
	_CPP_INTERNAL_ERROR=CPP_INTERNAL_ERROR,
	_CPP_PARSING_ERROR=CPP_PARSING_ERROR,
	_CPP_LINKING_ERROR=CPP_LINKING_ERROR,
	_CPP_RUNNING_ERROR=CPP_RUNNING_ERROR
}

#define __return(function) printf("%s returned %d\n", #function, function);

#define retv(ret, x) if(ret == x) return #x+1; // trim the leading _

#define retc(x) retv(x, _CPP_INTERNAL_ERROR) retv(x, _CPP_INVALID_ARGUMENTS) retv(x, _CPP_LINKING_ERROR) retv(x, _CPP_NO_ERROR) retv(x, _CPP_OUT_OF_MEMORY) retv(x, _CPP_PARSING_ERROR) retv(x, _CPP_RUNNING_ERROR)

const char * return_cpp_error_code(int ret) {
	retc(ret)
	return "(null)";
}

CPPenum cpp_y;
const char * cpp_z;

#define cpp_check1(x) printf("%s returned %s\n", #x, return_cpp_error_code(x));

// same code above but with proper error checking

// cpp_check shall recieve a start clock and a end clock to eliminate time taken for debug calls when timing x itself, currently defines as invalid operand
#define cpp_check(x, clock_start, clock_end) { \
	/*clock_start = clock();*/ \
	cpp_y = x; \
	/*clock_end = clock();*/ \
	cpp_z = return_cpp_error_code(cpp_y); \
	if (strcmp(cpp_z, cpp_y==_CPP_NO_ERROR?"CPP_NO_ERROR":"NULL") != 0) { \
		printf("%s returned %s\n", #x, cpp_z); \
		return -1; \
	} \
}


void attachSourceFile(CPPuint programID, const char *fileName);
const char *getFileExtension(const char *fileName);

CPPuint programID = 0;

char ** gcc_files = env__new();
char ** gcc_defines = env__new();
char ** gcc_includes = env__new();

void attachSourceFile(CPPuint programID, const char *fileName) {
	CURRENT_FUNCTION
	CPPuint objectID = cppCreateObject();

	/* Set user header search paths. */
	for (int i = 0; i < count_array(gcc_includes); i++) {
		printf("including %s\n", gcc_defines[i]);
		cpp_check(cppObjectAddUserHeaderSearchPath(objectID, gcc_includes[i]));
	}
	
	/* Macro definitions... */
	for (int i = 0; i < count_array(gcc_defines); i++) {
		printf("defining %s\n", gcc_defines[i]);
		cpp_check(cppObjectAddPrologue(objectID, gcc_defines[i]));
	}

	cpp_check(cppObjectSourceFile(objectID, fileName));
	cpp_check(cppCompileObject(objectID));
	cpp_check(cppAttachObject(programID, objectID));
	cpp_check(cppDeleteObject(objectID));
}

int builtin__gcc(const int argc, const char * argv[]) {
	CURRENT_FUNCTION
	ift clock__init();
	itta(argv);
	if (argc < 2) {
		printf("%s: error: argument expected\n", argv[0]);
		return -1;
	}
	gcc_files = env__new();
	gcc_defines = env__new();
	gcc_includes = env__new();
	for (int i = 1; i< argc; i++) {
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i],"--help")) {
			return gcc_usage();
		}
		else if (!strcmp(argv[i], "-I") || !strcmp(argv[i],"--include")) {
			i++;
			printf("Include: %s\n", argv[i]);
			env__add(gcc_includes, argv[i]);
			itta(gcc_includes);
		}
		else if (!strcmp(argv[i], "-D") || !strcmp(argv[i],"--define")) {
			i++;
			printf("Define: %s\n", argv[i]);
			str_new(defined);
			str_insert_string(defined, "#define ");
			str_insert_string(defined, argv[i]);
			env__add(gcc_defines, defined.string);
			str_free(defined);
			itta(gcc_defines);
		}
		else if ((argv[i])[0]== '-') {
			fprintf(stderr, "Unsupported option %s\n", argv[i]);
		}
		else {
			printf("File: %s\n", argv[i]);
			env__add(gcc_files, argv[i]);
		}
	}
	pz(sizeof(gcc_includes));
	pz(sizeof(&gcc_includes));
	pz(sizeof(*gcc_includes));
	itta(gcc_files);
	itta(gcc_defines);
	itta(gcc_includes);
	clock__add(whereis_start);
	clock__add(whereis_end);
	char ** filesreal = env__new();
	ift clock__set(whereis_start);
	for (int i = 0; i < count_array(gcc_files); i++) {
		char * tmp = builtin__whereis(count_array(gcc_files), gcc_files+i, NULL, false, *gcc_includes==NULL?NULL:argtopathlist(count_array(gcc_includes), gcc_includes), whereis_mode_return_first);
		if (tmp) env__add(filesreal, tmp);
	}
	ift clock__set(whereis_end);
	env__free(gcc_files);
	// time whereis first
	clock__add(create_start);
	clock__add(create_end);
	ift clock__set(create_start);
	programID = cppCreateProgram();
	ift clock__set(create_end);
	clock__add(build_start);
	clock__add(build_end);
	ift clock__set(build_start);
	//attachSourceFile(programID, "wrappers.h"); // add our wrapper file first
	for (int i = 0; i < count_array(filesreal); i++) attachSourceFile(programID, filesreal[i]);
	ift clock__set(build_end);
	env__free(gcc_defines);
	env__free(gcc_includes);
	env__free(filesreal);
	DEBUG printf("Compiling and linking...\n");
	clock__add(link_start);
	clock__add(link_end);
	ift clock__set(link_start);
	cpp_check(cppLinkProgram(programID), clock__get(link_start), clock__get(link_end));
	ift clock__set(link_end);
	DEBUG printf("Running...\n");
	clock__add(run_start);
	clock__add(run_end);
	ift clock__set(run_start);
	cpp_check(cppRunProgram(programID), clock__get(run_start), clock__get(run_end));
	ift clock__set(run_end);
	DEBUG printf("Finished running.\n");
	clock__add(delete_start);
	clock__add(delete_end);
	if (programID) {
		ift clock__set(delete_start);
		cppDeleteProgram(programID);
		ift clock__set(delete_end);
	}
	ift clock__total(clock__shorten(whereis), clock__shorten(create), clock__shorten(build), clock__shorten(link), clock__shorten(run), clock__shorten(delete));
	return 0;
}
