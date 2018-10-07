// line 5097
// inside static void parseonetoken(struct pstate *psp)
// inside   switch( psp->state ){
// inside     case WAITING_FOR_DECL_OR_RULE:
#ifdef LEMONEX
        if(psp->is_defininglx != 0){
          psp->state = IN_NEXTMODE;
        } else
#endif
