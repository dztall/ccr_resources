#ifndef EVALDEFS_H
#define EVALDEFS_H

/*****************************************************************

 EVALDEFS.H

 Interface declarations for EVALKERN.SYN
 Copyright (c) 1996 - 1999 Parsifal Software. All Rights Reserved.

 For further information about this program, contact
   Parsifal Software
   http://www.parsifalsoft.com
   info@parsifalsoft.com
   1-800-879-2755, Voice/Fax 1-508-358-2564
   P.O. Box 219
   Wayland, MA 01778

*****************************************************************/


/*****************************************************************

Override AnaGram defaults

*****************************************************************/

/* override default definition of SYNTAX_ERROR */

#define SYNTAX_ERROR diagnoseError(evalKernel_pcb.error_message)


/*****************************************************************

Define compile time constants

*****************************************************************/

/* define array sizes */
#define CHAR_STACK_LENGTH 1000          /* Length of char stack */
#define ARG_STACK_LENGTH   200          /* Length of arg stack  */
#define N_VARIABLES        100          /* Size of symbol table */


/*****************************************************************

Define data types

*****************************************************************/

/* Define an error record */
typedef struct {
  char *message;                 /* identifies error */
  int line;                      /* location of error */
  int column;
} ErrorRecord;

/* Define a symbol table entry */
struct VariableDescriptor {
  char   *name;
  EVAL_TYPE * valueptr; // shall be a pointer to a external variable otherwise shall point to value
  EVAL_TYPE value;      // this is what valueptr points to when not binded
};

/**********************************************************************

Function prototypes

**********************************************************************/

void    pushChar(int character);
void    pushArg(EVAL_TYPE value);
EVAL_TYPE  checkZero(EVAL_TYPE value);
EVAL_TYPE *locateVariable(int nameLength);
EVAL_TYPE  callFunction(int nameLength, int argCount);
void    diagnoseError(char *message);
int     evaluateExpression(char *expressionString);

/**********************************************************************

Global data

**********************************************************************/

/* Support for error diagnostics */
extern ErrorRecord errorRecord;

/* Symbol table */
extern struct VariableDescriptor variable[];
extern int nVariables;

#endif
