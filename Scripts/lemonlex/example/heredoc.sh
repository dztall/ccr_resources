rm -rf example/heredoc
binary/lemon -d./example/heredoc example/heredoc.y -m -s &&
gcc example/heredoc/heredoc.c -o example/heredoc/m &&
example/heredoc/m &&
ls example/heredoc &&
cat example/heredoc/heredoc.h &&
exit 0



# 			/*
# 			REGULAR_TX  REGULAR_TX  
# 			*/    /*1[65(A)-0( )]->2:tx_type:0, is_cap:1*/  if(ch == 65 /* decimal is required for full unicode support, printable character is 'A' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(2);goto S2; /*1*/}
# 			/*
# 			none        REGULAR_TX  
# 			*/    /*2[65(A)-0( )]->3:tx_type:0, is_cap:1*/  if(ch == 65 /* decimal is required for full unicode support, printable character is 'A' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(3);goto S3; /*1*/}
# 			/*
# 			none        REGULAR_TX  
# 			*/    /*3[65(A)-0( )]->4:tx_type:0, is_cap:1*/  if(ch == 65 /* decimal is required for full unicode support, printable character is 'A' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(4);goto S4; /*1*/}
# 			printf("current state: 4: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
# 			if((ch == 0) && (is_final == 0)) {lxpLexer->lxstate=4;return 0;}
# 			LX_ACTION(4);/*NO_SEND*/LX_RESET;
# 			if(ch == 0) {LX_SEND(0);return 0;}
# 			LX_ENTER_NESTING(1);
# 			goto S11; /* by retn_state */
