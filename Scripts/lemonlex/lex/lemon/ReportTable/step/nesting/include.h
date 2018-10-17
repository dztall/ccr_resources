// line 7445
// inside void ReportTable(
#ifdef LEMONEX
  fprintf(out,"#ifdef LEMONEX\n"); lineno++;
  fprintf(out,"#define %sLX_INTEGRATEDMODE %d\n", name, lemp->lxintegration); lineno++;
  fprintf(out,"#define %sLX_NESTINGDEPTH %d\n", name, lemp->lxnestingdepth); lineno++;
  fprintf(out,"#endif\n"); lineno++;
#endif
