// line 6596
// inside void emit_destructor_code(
// inside  if( sp->type==TERMINAL ){
#ifdef LEMONEX
  if(lemp->tokentype == 0){
   fprintf(out,"#ifdef LEMONEX\n"); (*lineno)++;
   fprintf(out,"      LX_FREETOK;\n"); (*lineno)++;
   fprintf(out,"#endif /*LEMONEX*/\n"); (*lineno)++;
   return;
  }
#endif
