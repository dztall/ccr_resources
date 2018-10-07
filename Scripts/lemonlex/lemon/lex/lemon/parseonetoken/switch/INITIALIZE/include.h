// line 5036
// inside static void parseonetoken(struct pstate *psp)
// inside   switch( psp->state ){
// inside     case INITIALIZE:
#ifdef LEMONEX
      psp->is_defininglx = 0;
      psp->next_lxstate_id = 0;
      psp->last_state = 0;
      psp->first_state = 0;
      psp->curr_state = 0;
      psp->last_mode = 0;
      psp->first_mode = 0;
      psp->lastlxsym = 0;
      psp->nstarcount = 0;
      psp->is_capturing = 1;
#endif
