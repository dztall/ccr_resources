/*
 EVALDEMO.C  Version 1.1

 Program to demonstrate evaluateExpression
 Copyright (c) 1996 - 1999 Parsifal Software. All Rights
 Reserved.

 Usage: evaldemo <filename>\n where the file holds
 expressions to be evaluated, with optional comments.

 An example main program which simply reads a file into a string
 in memory and calls evaluateExpression to evaluate the
 expressions in the string and store the results in a simple
 symbol table. It then prints out the contents of the symbol
 table to stdout in a form which allows it to be read as input
 again, should that be desired for initialization purposes.
 Finally, if there was an error, it prints a diagnostic message
 on stderr.

 For further information about this program, contact
   Parsifal Software
   http://www.parsifalsoft.com
   info@parsifalsoft.com
   1-800-879-2755, Voice/Fax 1-508-358-2564
   P.O. Box 219
   Wayland, MA 01778
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../../../Shell/builtins/printfmacro.h"
#include "../../../Shell/builtins/env.h"
#define EVAL_TYPE int
#include "evaldefs.h"
#include "evalkern.c"
#include "evalwrap.c"

/* Main Program */
#define printBinLen(num, len) { \
}

int main(int argc, char *argv[]) {
  int i;
  FILE *input;
  long fileLength;
  size_t stringLength;
  int errorFlag;
  /* evaluate expressions */
  int sum = 0;
  Expression_Assign("sum", &sum);
  errorFlag = evaluateExpression("f=4");
  errorFlag = evaluateExpression("a=1");
  errorFlag = evaluateExpression("b=2");
  errorFlag = evaluateExpression("c=3");
  errorFlag = evaluateExpression("e=5");
  for (i = 0; i < nVariables; i++) printf("\t\t%s = %i;\n", variable[i].name, *variable[i].valueptr);
  evaluateExpression("sum += a+b+c+e+f");
  evaluateExpression("sum += a+b+c+e+f");
  evaluateExpression("sum += a+b+c+e+f");
  evaluateExpression("sum += a+b+c+e+f");
  for (i = 0; i < nVariables; i++) printf("\t\t%s = %i;\n", variable[i].name, *variable[i].valueptr);
  pi(sum);
  env__list(EVALWRAP_INTERNAL_VARIABLE_LIST);
  return 0;
}
/*  End of EVALDEMO.C */
