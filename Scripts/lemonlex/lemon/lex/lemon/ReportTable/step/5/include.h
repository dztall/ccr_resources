// line 7832
// inside void ReportTable(
#ifdef LEMONEX
  /* Append any addition code the user desires */
  tplt_print(out,lemp,lemp->lexercode,&lineno);
  tplt_xfer(lemp->name,in,out,&lineno);
  for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state){
    if(curr_state->code != 0){
      fprintf(out, "static void lx_state_action_%d(lxLexer *lxpLexer){", curr_state->state_id);
      emit_lexer_actioncode(out, curr_state->code, lemp, &lineno);
      fprintf(out, "}\n");lineno++;
    }
  }

  tplt_xfer(lemp->name,in,out,&lineno);
  lx_generate_output(lemp, out, &lineno);
  tplt_xfer(lemp->name,in,out,&lineno);
#endif
