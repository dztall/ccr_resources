// line 7350
// inside void ReportTable(
#ifdef LEMONEX
  /* The include code might contain pch header, so include stdio.h here */
  fprintf(out, "#define LEMONEX_DBGLVL %d\n", lemp->lxdebuglevel); lineno++;
#endif
