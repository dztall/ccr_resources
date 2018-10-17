// line 5067
// inside static void parseonetoken(struct pstate *psp)
// inside   switch( psp->state ){
// inside     case WAITING_FOR_DECL_OR_RULE:
#ifdef LEMONEX
        if((psp->is_defininglx != 0) && (psp->curr_state == 0)) {
          ErrorMsg(psp->filename,psp->tokenlineno,
"There is no prior lexer rule upon which to attach the code \
fragment which begins on this line.");
          psp->errorcnt++;
        } else if((psp->is_defininglx != 0) && (psp->curr_state != 0)) {
          assert(psp->curr_state->is_leaf == 1);
          psp->curr_state->code = &x[1];
          if(psp->curr_state->star_state != 0){
            assert(psp->curr_state->star_state->is_leaf == 1);
            psp->curr_state->star_state->code = &x[1];
          }
        } else
#endif
