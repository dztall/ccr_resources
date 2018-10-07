// %lexer_debuglevel HIGH.
// %lexer_integration ON.
%include {
#include <string.h>
}

%syntax_error {
  puts("Syntax error!");
}

%parse_accept {
  puts("parsing complete!");
}

%token_prefix TK_

%token STR U3.

%token STR3.

%start_symbol rModule
rModule ::= EOF.
EOF ::= !".". { printf("Recieved EOF\n"); }
ENTER_MLCOMMENT ::= "/\*". [MLCOMMENT] { printf("COMMENT_%s: %s\n", "START", $$.buf); }
ENTER_MLCOMMENT2 ::= "a". [MLCOMMENT2] { printf("HD_%s: %s\n", "START", $$.buf); }

%lexer_mode MLCOMMENT.
LEAVE_MLCOMMENT ::= "\*/". [<] { printf("COMMENT_%s: %s\n", "END", $$.buf); }
WS ::= ".*". {
	printf("COMMENT_%s: %s\n", "CONTENTS", $$.buf);
	puts("parsing...");
	  if(LX_REPARSE($$.buf) != 0) {
    printf("Error\n");
  } else printf("Success\n");
}

%lexer_mode MLCOMMENT2.
LEAVE_MLCOMMENT2 ::= "c". [<] { printf("HD_%s: %s\n", "END", $$.buf); }
WS ::= ".*". { printf("HD_%s: %s\n", "CONTENTS", $$.buf); }

%code {
int main(int argc, char* argv[]) {
  if(ParseReadString("/*abadcgc*/", "<string>", "DEBUG: ") != 0) {
    printf("Error\n");
  } else printf("Success\n");
  return 0;
}
}
