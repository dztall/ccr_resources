// line 7445
// inside void ReportTable(
#ifdef LEMONEX
  fprintf(out,"#ifdef LEMONEX\n"); lineno++;
  tplt_xfer(lemp->name,in,out,&lineno);

  /* Generate code which executes when token needs to be created */
  if(lemp->tokenctor) {
    emit_constructor_code(out, lemp->tokenctor, lemp, &lineno);
  }

  tplt_xfer(lemp->name,in,out,&lineno);

  /* Generate char class list */
  Lexer_generate_class_list(lemp, out, &lineno);
  fprintf(out,"#endif\n"); lineno++;
#endif
