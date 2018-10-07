%lexer_debuglevel HIGH.
// %lexer_integration ON.
%include {
#include <string.h>
}


%token_prefix TK_

%token STR U3.

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
	  if(ParseReadString($$.buf, "<string>", "DEBUG: ") != 0) {
    printf("Error\n");
  } else printf("Success\n");
}

%lexer_mode MLCOMMENT2.
LEAVE_MLCOMMENT2 ::= "c". [<] { printf("HD_%s: %s\n", "END", $$.buf); }
WS ::= ".*". { printf("HD_%s: %s\n", "CONTENTS", $$.buf);}

%code {
int main(int argc, char* argv[]) {
//   ParseTrace(stderr, "LEMON: ");
  void *yyp = 0;
  void *lxp = 0;
  if(lx_alloc_parser(&yyp, &lxp, "stdin", "lemon debug: ") != 0){
    return 1;
  }
  char * buf = "hi/*";
  int rc = ParseRead(yyp, buf, strchr(buf, 0), 1 ParseARG_VNAME);
  if(rc < 0){
    printf("error in string:%d\n", rc);
    lx_free_parser(&yyp, &lxp);
    return 1;
  }
  buf = "*/";
  rc = ParseRead(yyp, buf, strchr(buf, 0), 1 ParseARG_VNAME);
  if(rc < 0){
    printf("error in string:%d\n", rc);
    lx_free_parser(&yyp, &lxp);
    return 1;
  }
  lx_free_parser(&yyp, &lxp);
  if(ParseReadString("/*abc*/b", "<string>", "DEBUG: ") != 0) {
    printf("Error\n");
  } else printf("Success\n");
  return 0;
}
}
