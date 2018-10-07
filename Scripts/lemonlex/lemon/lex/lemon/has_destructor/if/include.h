// line 6645
// inside int has_destructor(struct symbol *sp, struct lemon *lemp)
// inside   if( sp->type==TERMINAL ){
#ifdef LEMONEX
    ret = (lemp->tokendest!=0)||(lemp->tokentype == 0);
#else
    ret = lemp->tokendest!=0;
#endif
