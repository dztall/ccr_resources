/*
 EVALWRAP.C  Version 1.1

 evaluateExpression: A Simple Expression Evaluator
 Copyright (c) 1996 - 1999 Parsifal Software, All
 Rights Reserved.

 The EVALWRAP.C module provides support functions for the parser function
 evalKernel(), defined by EVALKERN.SYN. It includes definitions of the
 functions called by evalKernel() as well as the definition of the
 evaluateExpression function, implemented as a wrapper function for
 evalKernel().

 This module consists of six parts:
   1. Error diagnostic procedures, including the definition of
      checkZero.
   2. Character stack procedures, including the definition of
      pushChar.
   3. Symbol table procedures, including the definition of
      locateVariable, which provides access to named variables. In this
      implementation, there are no predefined variables. If a variable
      is not found, it is added to the table and initialized to zero.
      The lookup uses a binary search.
   4. Argument stack procedures, including the definition of
      pushArg.
   5. Function call interface which provides access to
      the standard C library math functions.
      The interface consists of
      . a functionTable, each entry of which contains the name of a
        function and a wrapper function which calls the named
        function.
      . an implementation of callFunction which does a binary search of
        functionTable and then calls the appropriate wrapper function.
      Macros are used to simplify generation of the wrapper functions
      and the functionTable entries.
   6. Definition of the evaluateExpression wrapper function.

 For further information about this module, contact
   Parsifal Software
   http://www.parsifalsoft.com
   info@parsifalsoft.com
   1-800-879-2755, 1-508-358-2564
   P.O. Box 219
   Wayland, MA 01778
*/

#include <math.h>
#include <string.h>

#include "evaldefs.h"
#include "evalkern.h"


/*********************************************************************

 Part 1. Error Diagnostics

*********************************************************************/

ErrorRecord errorRecord;           /* define an error record */

void diagnoseError(char *msg) {
  if (evalKernel_pcb.exit_flag == AG_RUNNING_CODE)   /* parser still running */
    evalKernel_pcb.exit_flag = AG_SEMANTIC_ERROR_CODE;      /* stop parse */
  errorRecord.message = msg;
  errorRecord.line    = evalKernel_pcb.line;
  errorRecord.column  = evalKernel_pcb.column;
}

EVAL_TYPE checkZero(EVAL_TYPE value) {
  if (value) return value;
  diagnoseError("Divide by Zero");
  return 1;
}


/*******************************************************************

Part 2. Accumulate variable names and function names

*******************************************************************/

static char  charStack[CHAR_STACK_LENGTH+1];
static char *charStackTop = charStack;
static void resetCharStack(void) {
	charStackTop = charStack;
}

void pushChar(int c) {              /* append char to name string */
  if (charStackTop < charStack+CHAR_STACK_LENGTH) {
    *charStackTop = (char) c;
    charStackTop++;
    return;
  }
  /* buffer overflow, kill parse and issue diagnostic */
  diagnoseError("Character Stack Overflow");
}

static char *popString(int nChars) {                /* get string */
  *charStackTop = 0;
  return charStackTop -= nChars;
}


/**********************************************************************

Part 3. Symbol Table

**********************************************************************/

struct VariableDescriptor variable[N_VARIABLES];    /* Symbol table array */

int nVariables = 0;                       /* no. of entries in table */

/* Callback function to locate named variable */
char ** EVALWRAP_INTERNAL_VARIABLE_LIST;
int EVALWRAP_INTERNAL_VARIABLE_LIST_freed = 0;

void Expression_Assign_free(void) {
    if (!EVALWRAP_INTERNAL_VARIABLE_LIST_freed) {
        if (EVALWRAP_INTERNAL_VARIABLE_LIST) {
            EVALWRAP_INTERNAL_VARIABLE_LIST_freed = 1;
            puts("freeing EVALWRAP_INTERNAL_VARIABLE_LIST");
            env__free(EVALWRAP_INTERNAL_VARIABLE_LIST);
        }
    }
}

void Expression_Assign(char * name, void * variable) {
    if (!EVALWRAP_INTERNAL_VARIABLE_LIST) {
        EVALWRAP_INTERNAL_VARIABLE_LIST = env__new();
        EVALWRAP_INTERNAL_VARIABLE_LIST_freed = 0;
        atexit(Expression_Assign_free);
    }
    int len = 1+strlen(name)+strlen("=")+strlen("0x")+(sizeof(variable)*2); // (0x00 to 0xFF) == 1 byte
    char * str = malloc(len);
    memset(str, 0, len);
    snprintf(str,len, "%s=%p",name, variable);
    EVALWRAP_INTERNAL_VARIABLE_LIST = env__add(EVALWRAP_INTERNAL_VARIABLE_LIST, str);
    memset(str, 0, len);
    free(str);
};

int locateVariable_first_call = 0;

void (variable_cleanup)(void) {
    for (int i = 0; i < nVariables; i++) {
    	free(variable[i].name);
    	variable[i].valueptr = NULL;
    	variable[i].value = 0;
    }
}





EVAL_TYPE *locateVariable(int nameLength) {   /* identify variable name */
    if (!locateVariable_first_call) {
        locateVariable_first_call = 1;
        atexit(variable_cleanup);
    }
  char *name = popString(nameLength);
  int first = 0;
  int last = nVariables - 1;
  for (int i = 0; i < nVariables; i++) if (strcmp(name,variable[i].name) == 0) {
      printf("%s found\n", name);
      return variable[i].valueptr;
  }
  // name not found in assigned variable list, check external variables list
  puts("checking external list");
  if (!EVALWRAP_INTERNAL_VARIABLE_LIST) {
      EVALWRAP_INTERNAL_VARIABLE_LIST = env__new();
      EVALWRAP_INTERNAL_VARIABLE_LIST_freed = 0;
      atexit(Expression_Assign_free);
  }
  nVariables++;
  first = nVariables-1;
  char * n = env__get(EVALWRAP_INTERNAL_VARIABLE_LIST, name);
  if (n) {
    printf("%s found\n", name);
    // n exists, use it
    variable[first].name = strdup(name);
    void *b;
    sscanf(n,"%p",&b);
    variable[first].valueptr = (EVAL_TYPE*)b;
  } else {
    printf("%s not found, adding\n", name);
    /* name not found, check for room in table */
    if (nVariables >= N_VARIABLES) {
        /* table is full, kill parse and issue diagnostic */
        static EVAL_TYPE junk = 0;
        diagnoseError("Symbol Table Full");
        return &junk;
    }
    
    variable[first].name = strdup(name);
    variable[first].valueptr = &variable[first].value;
    variable[first].value = 0;
  }
  return variable[first].valueptr;
}


/*******************************************************************

Part 4. Accumulate list of function arguments

*******************************************************************/

static EVAL_TYPE  argStack[ARG_STACK_LENGTH];      /* argument buffer */
static EVAL_TYPE *argStackTop = argStack;

static void resetArgStack(void) {
  argStackTop = argStack;
}

void pushArg(EVAL_TYPE x) {                     /* store arg in list */
  if (argStackTop < argStack + ARG_STACK_LENGTH) {
    *argStackTop++ = x;
    return;
  }
  /* too many args, kill parse and issue diagnostic */
  diagnoseError("Argument Stack Full");
}

static EVAL_TYPE *popArgs(int nArgs) {                 /* fetch args */
  return argStackTop -= nArgs;
}


/**********************************************************************

 Part 5. Function Call Interface

 Define functionTable, each entry of which contains the ascii name of
 a function and a pointer to a wrapper function. The wrapper function
 checks the argument count and calls the real function.

 Then, define callFunction. Given the ascii name of a function,
 callFunction does a binary search of functionTable and on a successful
 search calls the corresponding wrapper function.

**********************************************************************/

/* define some macros to build the wrapper functions */

/*
 First, a macro to make a wrapper function for a function with one
 argument.
*/

#define WRAPPER_FUNCTION_1_ARG(FUN) \
EVAL_TYPE FUN##Wrapper(int argc, EVAL_TYPE *argv) {\
  if (argc == 1) return FUN(argv[0]);\
  diagnoseError("Wrong Number of Arguments");\
  return 0;\
}

/*
 Now, a macro to make a wrapper function for a function with two
 arguments.
*/

#define WRAPPER_FUNCTION_2_ARGS(FUN) \
EVAL_TYPE FUN##Wrapper(int argc, EVAL_TYPE *argv) {\
  if (argc==2) return FUN(argv[0], argv[1]);\
  diagnoseError("Wrong Number of Arguments");\
  return 0;\
}


/*
 Now define wrapper functions for the standard C library
 math functions.
*/

WRAPPER_FUNCTION_1_ARG(acos)
WRAPPER_FUNCTION_1_ARG(asin)
WRAPPER_FUNCTION_1_ARG(atan)
WRAPPER_FUNCTION_2_ARGS(atan2)
WRAPPER_FUNCTION_1_ARG(cos)
WRAPPER_FUNCTION_1_ARG(cosh)
WRAPPER_FUNCTION_1_ARG(exp)
WRAPPER_FUNCTION_1_ARG(fabs)
WRAPPER_FUNCTION_2_ARGS(fmod)
WRAPPER_FUNCTION_1_ARG(log)
WRAPPER_FUNCTION_1_ARG(log10)
WRAPPER_FUNCTION_1_ARG(sin)
WRAPPER_FUNCTION_1_ARG(sinh)
WRAPPER_FUNCTION_1_ARG(sqrt)
WRAPPER_FUNCTION_1_ARG(tan)
WRAPPER_FUNCTION_1_ARG(tanh)


/* A macro to make correct functionTable entries */
#define TABLE_ENTRY(FUN) {#FUN, FUN##Wrapper}

/* remember to fix this when you add more functions to the table */
#define N_FUNCTIONS 16

/* define the function table -- must be in sorted order! */
struct {
  char *name;
  EVAL_TYPE (*function)(int, EVAL_TYPE[]);
} functionTable[N_FUNCTIONS] = {
  TABLE_ENTRY(acos),
  TABLE_ENTRY(asin),
  TABLE_ENTRY(atan),
  TABLE_ENTRY(atan2),
  TABLE_ENTRY(cos),
  TABLE_ENTRY(cosh),
  TABLE_ENTRY(exp),
  TABLE_ENTRY(fabs),
  TABLE_ENTRY(fmod),
  TABLE_ENTRY(log),
  TABLE_ENTRY(log10),
  TABLE_ENTRY(sin),
  TABLE_ENTRY(sinh),
  TABLE_ENTRY(sqrt),
  TABLE_ENTRY(tan),
  TABLE_ENTRY(tanh),
};


/* Finally, define the callback function to perform a function call */

EVAL_TYPE callFunction(int nameLength, int argCount) {
  char *name = popString(nameLength);
  EVAL_TYPE *argValues = popArgs(argCount);
  int first = 0;
  int last = N_FUNCTIONS-1;
  while (first <= last) {                     /* binary search */
    int middle = (first+last)/2;
    int flag = strcmp(name,functionTable[middle].name);
    if (flag == 0) return functionTable[middle].function(argCount, argValues);
    if (flag < 0) last = middle-1;
    else first = middle+1;
  }
  diagnoseError("Unknown Function");
  return 0;
}

/*******************************************************************

Part 6. Wrapper function definition

*******************************************************************/

int evaluateExpression(char *expressionString) {
  if (!expressionString) return -1;
  resetCharStack();
  resetArgStack();
  evalKernel_pcb.pointer = (unsigned char *) expressionString;
  evalKernel();
  return evalKernel_pcb.exit_flag != AG_SUCCESS_CODE;
}

/* End of evalwrap.c */
