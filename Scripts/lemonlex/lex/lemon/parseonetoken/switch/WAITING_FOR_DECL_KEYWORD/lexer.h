// line 5352
// inside static void parseonetoken(struct pstate *psp)
// inside   switch( psp->state ){
// inside     case WAITING_FOR_DECL_KEYWORD:
#ifdef LEMONEX
        }else if( strcmp(x,"lexer_integration")==0 ){
          psp->state = WAITING_FOR_INTEGRATIONMODE_1;
        }else if( strcmp(x,"lexer_nestingdepth")==0 ){
          psp->state = WAITING_FOR_NESTINGDEPTH_1;
        }else if( strcmp(x,"lexer_encoding")==0 ){
          psp->state = WAITING_FOR_ENCODING_ID_1;
        }else if( strcmp(x,"lexer_code")==0 ){
          psp->declargslot = &(psp->gp->lexercode);
        }else if( strcmp(x,"lexer_mode")==0 ){
          psp->state = WAITING_FOR_MODE_ID_1;
        }else if( strcmp(x,"lexer_debuglevel")==0 ){
          psp->state = WAITING_FOR_DEBUG_LEVEL_1;
        }else if( strcmp(x,"token_constructor")==0 ){
          psp->declargslot = &psp->gp->tokenctor;
#endif
