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
#include "../../Shell/builtins/printfmacro.h"
#include "../../Shell/builtins/env.h"
#define EVAL_TYPE int
#include "evaldefs.h"
#include "evalkern.c"
#include "evalwrap.c"
#include <assert.h>
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
  char * expression;
  expression = "f=4";
  ps(expression);
  errorFlag = evaluateExpression(expression);
  pi(nVariables)
  for (i = 0; i < nVariables; i++) printf("\t\t%s = %i;\n", variable[i].name, *variable[i].valueptr);
  puts("declaring int test = 8");
  int test = 8;
  puts("binding \"s\" to &test");
  Expression_Assign("s", &test);
  puts("declaring int test2 = 80");
  int test2 = 80;
  puts("binding \"sam\" to &test2");
  Expression_Assign("sam", &test2);
  expression = "s += sam + f";
  ps(expression);
  errorFlag = evaluateExpression(expression);
  for (i = 0; i < nVariables; i++) printf("\t\t%s = %i;\n", variable[i].name, *variable[i].valueptr);
  /* check for error */
  if (errorFlag) fprintf(stderr,"File %s: %s at line %d, column %d\n",
                            "expression",
                            errorRecord.message,
                            errorRecord.line,
                            errorRecord.column);
  puts("printing value of test");
  pi(test);
  puts("printing value of test2");
  pi(test2);
  Expression_Assign_free();
  variable_cleanup();
  puts("testing test string");
  /* Allocate storage for input string */
  char * expressionString = "\n\
  /* simple assignment expressions */\n\
  a =  7;\n\
  b = 23;\n\
  \n\
  /* complex assignment operators */\n\
  d = 10, d += b;\n\
  e = 11, e *= a;\n\
  f = 12, f -= b;\n\
  g = 13, g /= a;\n\
  \n\
  /* add to memory, with parenthesized assignment */\n\
  h += (1/(c=1.05)); // int does not work here due to rounding, so change .05 to 1.05 to round to 1 otherwise we get divide by zero\n\
  \n\
  LongVariableNamesAreOK = (a+b)/(a-b);\n\
  \n\
  x = h/LongVariableNamesAreOK, y = 1-x;\n\
  \n\
  // Comparison operators\n\
  xLTy = x<y;\n\
  xLEy = x<=y;\n\
  xGTy = x>y;\n\
  xGEy = x>=y;\n\
  xNEy = x!=y;\n\
  xeqy = x==y;\n\
  \n\
  // Conditional expressions are supported\n\
  test = !(x < y  && u != v) ? y :\n\
         x >= z ? z : 1 ;\n\
  \n\
  // Standard math functions\n\
  u=sin(x), v = cos(y);\n\
  theta = atan2(u,v);\n\
  \n\
  //checkInversion\n\
  ok = (phi = atan2(sin(theta),cos(theta))) == theta;\n\
  \n\
  // Exponentiation\n\
  w = y**x;\n\
  q = -c**-2;\n\
  z = 23.7*10**-3;\n\
  \n\
  \n\
  ";
  /* evaluate expressions */
  ps(expressionString);
  errorFlag = evaluateExpression(expressionString);     // Call parser function
  /* print values of variables */
  for (i = 0; i < nVariables; i++) printf("%s = %d;\n",
                                           variable[i].name,
                                           variable[i].value);
  /* check for error */
  if (errorFlag) fprintf(stderr,"File %s: %s at line %d, column %d\n",
                            "expressionString",
                            errorRecord.message,
                            errorRecord.line,
                            errorRecord.column);
  /* done */
  return 0;
}
/*  End of EVALDEMO.C */
