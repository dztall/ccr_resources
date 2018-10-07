%include {
#include <assert.h>
#include <stdlib.h>
#include <string.h>
}

%token_prefix TK_
%start_symbol rModule
rModule ::= EOF.
EOF ::= !".". { printf("Recieved EOF:\n"); }
ENTER_MLCOMMENT ::= "/\*". [MLCOMMENT] { printf("Recieved START: %s\n", $$.buf); }

%lexer_mode MLCOMMENT.
LEAVE_MLCOMMENT ::= "\*/". [<] { printf("Recieved END: %s\n", $$.buf); }
WS ::= ".*". { printf("Recieved MIDDLE: %s\n", $$.buf); }

%code {
int main(int argc, char* argv[]) {
//  ParseTrace(stderr, "LEMON: ");
  void *yyp = 0;
  void *lxp = 0;
  if(lx_alloc_parser(&yyp, &lxp, "stdin", "dbgpfx") != 0){
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
  if(ParseReadString("/*ac*/b", "<string>", "DBG_PREFIX:") != 0) {
    printf("Error\n");
  } else printf("Success\n");
  return 0;
}
}
