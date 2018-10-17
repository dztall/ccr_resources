// line 6935
// inside void print_stack_union(
#ifdef LEMONEX
  fprintf(out,"#ifdef LEMONEX\n");lineno++;
  fprintf(out,"#define %sTOKENTYPE %s\n",name,
    lemp->tokentype?lemp->tokentype:"struct lxToken");  lineno++;
  fprintf(out,"#define %sTOKENTYPE_DEF %d\n",name,
    lemp->tokentype?0:1);  lineno++;
  fprintf(out,"#else /* LEMONEX */\n");lineno++;
  fprintf(out,"#define %sTOKENTYPE %s\n",name,
    lemp->tokentype?lemp->tokentype:"void*");  lineno++;
  fprintf(out,"#endif /* LEMONEX */\n");lineno++;
#else
  fprintf(out,"#define %sTOKENTYPE %s\n",name,
    lemp->tokentype?lemp->tokentype:"void*");  lineno++;
#endif
