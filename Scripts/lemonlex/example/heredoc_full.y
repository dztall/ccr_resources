%lexer_debuglevel HIGH.
%token_prefix TOKEN_

%syntax_error {
  puts("Syntax error!");
}

%include {
char * CAT = NULL;
char * aaa = "AAA";
}

%start_symbol rModule
// %token_type {struct lxLexer}
rModule ::= .
DD ::= $EOF. {printf("recieved EOF\n");}
DD ::= "AAA". [D] { printf("5CAT_%s: %s\n", "START", $$.buf); }
// DD ::= . [D] { printf("5CAT_%s: %s\n", "START", $$.buf); }
// HEREDOC ::= "<<.*[\n ]". [CAT] {											//			<--------------------- NESTING ENTER
// 	CAT = $$.buf;
// 	if (CAT[strlen(CAT)-1] == ' ' || CAT[strlen(CAT)-1] == '\n') {
// 		CAT[strlen(CAT)-1] = 0;
// 	}
// 	printf("S: \"%s\"\n", CAT);
// }

WS ::= ".*". { printf("OTHER: %s\n", $$.buf); }

// %lexer_mode CAT.
// LEAVE_HEREDOC ::= $CAT. [<] { printf("E: %s\n", $$.buf); }					//			<--------------------- NESTING EXIT
// WS ::= ".*". { printf("CAT_%s: %s\n", "CONTENTS", $$.buf); } // the full contents can be obtained by specifying the $CAT2 in the main mode where this HEREDOC starts, and then parsing the heredoc contents using ParseReadString($$.buf);

%lexer_mode D.
LEAVE_MLCOMMENT ::= $aaa. [<] { printf("5CAT_%s: %s\n", "END", $$.buf); }	//			<--------------------- NESTING EXIT
WS ::= ".*". { printf("5CAT_%s: %s\n", "CONTENTS", $$.buf); }
%code {
	int main()
	{
	char * s = "<<CAT HEREDOC <<CAT\n AAA <<EOF\nANOTHER\nHERE\nDOC\n>5 05 >5 END OF FILE\n<<EOF AAA RIP";
// 	s = "<<CAT HEREDOC <<CAT\n AAA FILE AAA // the full contents can be obtained by specifying the $CAT2 in the main mode where this HEREDOC starts, and then parsing the heredoc contents using ParseReadString($$.buf";
	printf("parsing %s\n", s);
	if(ParseReadString(s, "<string>", "DEBUG: ") != 0) {
		printf("Error\n");
	} else printf("Success\n");

	}
}
