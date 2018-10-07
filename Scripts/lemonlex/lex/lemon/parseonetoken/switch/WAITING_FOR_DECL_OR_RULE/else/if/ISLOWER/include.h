// line 5057
// inside static void parseonetoken(struct pstate *psp)
// inside   switch( psp->state ){
// inside     case WAITING_FOR_DECL_OR_RULE:
#ifdef LEMONEX
        psp->is_defininglx = 0;
      }else if( isupper(x[0]) ){
        psp->lastlxsym = Symbol_find(x); /* this might be 0 if symbol not found */
        psp->nstarcount = 0;
        psp->is_capturing = (psp->lastlxsym==0)?0:1;
        psp->state = WAITING_FOR_ARROW_LEX;
        psp->is_defininglx = 1;
#endif
