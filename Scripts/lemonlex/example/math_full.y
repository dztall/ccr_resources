%lexer_debuglevel HIGH.
// %nonassoc makes it do in order found
%token_prefix TOKEN_MATH_

%nonassoc DIVIDE TIMES MINUS PLUS     INTEGER.

// %token makes it do in unpredictable order as if it attempts to apply precedence to it
// %token DIVIDE TIMES MINUS PLUS     INTEGER.

// %left PLUS MINUS.
// %left DIVIDE TIMES.

%syntax_error {
  puts("Syntax error!");
}

%include {
char * HD = NULL;
char * PL = "+";
char * V1 = "\"PL\"";
}

%start_symbol rModule
// %token_type {struct lxLexer}
rModule ::= .
// WORD ::= "[\d]+". { printf("Recieved WORD %s\n", $$.buf); }
// NUMBER ::= "\d". { printf("Recieved NUMBER %s\n", $$.buf); }
PLU ::= $"PA". { printf("Recieved PLUS %s\n", $$.buf); } // $"PL" == "\"PL\""
PLU ::= $"PL". { printf("Recieved PLUS %s\n", $$.buf); } // $"PL" == "\"PL\""
PLU ::= $"PB". { printf("Recieved PLUS %s\n", $$.buf); } // $"PL" == "\"PL\""
// V1 ::= $"V1".
// V2 ::= $"V2".
V1 ::= $V1. { puts("V1");}
V2 ::= $V2. { puts("V2");}
// V2 ::= $V2.
// MUL ::= "*". { printf("Recieved TIMES %s\n", $$.buf); }
// EOL ::= $"D". { printf("Recieved EOL %s\n", $$.buf); }
HEREDOC ::= "<1.*[\n ]". [HD] { HD = $$.buf+2; printf("S: \"%s\"\n", HD); }
WS ::= ".*". { printf("OTHER: %s\n", $$.buf); }

%lexer_mode HD.
ENTER_HEREDOC ::= "<1.*[\n ]". [HD] { HD = $$.buf+2; printf("S: \"%s\"\n", HD); }
LEAVE_HEREDOC ::= "<2". [<] { printf("E: %s\n", $$.buf); }
V2 ::= $V2. { puts("V2");}
WS ::= ".*". { printf("HD_%s: %s\n", "CONTENTS", $$.buf); }
// 
// %lexer_mode D.
// LEAVE_MLCOMMENT ::= "5". [<] { printf("COMMENT_%s: %s\n", "END", $$.buf); }
// WS ::= ".*". { printf("HD_%s: %s\n", "CONTENTS", $$.buf); }

// %lexer_mode PARSE.
// %token_type {int}
// P ::= "A".
// program ::= expr(A).   { printf("Result=%d\n", A); }
// expr(A) ::= expr(B) MINUS  expr(C).   { A = B - C; }
// expr(A) ::= expr(B) PLUS  expr(C).   { A = B + C; }
// expr(A) ::= expr(B) TIMES  expr(C).   { A = B * C; }
// expr(A) ::= expr(B) DIVIDE expr(C).  {
// 
//          if(C != 0){
//            A = B / C;
//           }else{
//            puts("divide by zero");
//            }
// }  /* end of DIVIDE */
// 
// expr(A) ::= INTEGER(B). { A = B; }

%code {
	int main()
	{
// 	void* pParser = ParseAlloc (malloc);
// 
// 	/* First input:
// 		15 / 5
// 									*/
// 	Parse (pParser, INTEGER, 15);
// 	Parse (pParser, TIMES, 0);
// 	Parse (pParser, INTEGER, 5);
// 	Parse (pParser, 0, 0);
// 
// 	/*  Second input:
// 			50 + 125
// 								*/
// 
// 
// 	Parse (pParser, INTEGER, 50);
// 	Parse (pParser, PLUS, 0);
// 	Parse (pParser, INTEGER, 125);
// 	Parse (pParser, 0, 0);
// 
// 
// 	/*  Third input:
// 			50 * 125 + 125
// 								*/
// 
// 
// 	Parse (pParser, INTEGER, 2);//	2	(2)			2	(2)		5	(5)
// 	Parse (pParser, TIMES, 0);//	x				x			+
// 	Parse (pParser, INTEGER, 5);//	5	(10)		5	(7)		15	(20)
// 	Parse (pParser, PLUS, 0);//		+				+			x
// 	Parse (pParser, INTEGER, 15);//	15	(10+15)		15	(7x15)	2	(20x2)
// 	Parse (pParser, 0, 0);//		=	25			=	105		=	40
// 
// 
// 	ParseFree(pParser, free );
	char * s = "PL5+5*5 <<H\n k \nH\n<<K\nK PL j";
	s = "\"PA\" \"PL\" \"PB\" ";
	printf("parsing %s\n", s);
	if(ParseReadString(s, "<string>", "DEBUG: ") != 0) {
		printf("Error\n");
	} else printf("Success\n");

	}
}
