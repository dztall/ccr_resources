%lexer_debuglevel HIGH.
%include {
	char * CAT[LX_NESTMAX] = {0};
// 	char * AAA = "AAA";
}

rModule ::= .
// DD ::= $AAA. [D] { printf("AAA_%s: %s\n", "START", $$.buf); }
HEREDOC ::= "<<.*[\n ]". [CAT] {											//			<--------------------- NESTING ENTER
	CAT[LX_NESTLEVEL] = $$.buf;
	int len = strlen(CAT[LX_NESTLEVEL]);
	if (CAT[LX_NESTLEVEL][len-1] == ' ' || CAT[LX_NESTLEVEL][len-1] == '\n') {
		CAT[LX_NESTLEVEL][len-1] = 0;
	}
	printf("S: \"%s\"\n", CAT[LX_NESTLEVEL]);
	CAT[LX_NESTLEVEL] += 2;
}
WS ::= ".*". { printf("OTHER: \"%s\"\n", $$.buf); }

%lexer_mode CAT.
HEREDOC ::= "<<.*[\n ]". [CAT] {											//			<--------------------- NESTING ENTER
	CAT[LX_NESTLEVEL+1] = $$.buf;
	int len = strlen(CAT[LX_NESTLEVEL+1]);
	if (CAT[LX_NESTLEVEL+1][len-1] == ' ' || CAT[LX_NESTLEVEL+1][len-1] == '\n') {
		CAT[LX_NESTLEVEL+1][len-1] = 0;
	}
	printf("S: \"%s\"\n", CAT[LX_NESTLEVEL+1]);
	CAT[LX_NESTLEVEL+1] += 2;
}
LEAVE_HEREDOC ::= $CAT[LX_NESTLEVEL]. [<] { printf("E: %s\n", $$.buf); }					//			<--------------------- NESTING EXIT
WS ::= ".*". {
	printf("CAT[LX_NESTLEVEL-1]_%s: %s\n", "CONTENTS", $$.buf);
// 	puts("parsing...");
// 	if(LX_REPARSE($$.buf) != 0) {
// 		printf("Error\n");
// 	} else printf("Success\n");
}
// %lexer_mode D.
// LEAVE_MLCOMMENT ::= $AAA. [<] { printf("AAA_%s: %s\n", "END", $$.buf); }	//			<--------------------- NESTING EXIT
// WS ::= ".*". { printf("AAA_%s: %s\n", "CONTENTS", $$.buf); }
%code {
	int main()
	{
// 		LX_REPARSE("<<CAT[LX_NESTLEVEL] HEREDOC<<EOF <<CAT[LX_NESTLEVEL] <<EOF K <<CAT[LX_NESTLEVEL]");
		LX_REPARSE("<<CAT <<EOF EOF CAT");
	}
}
