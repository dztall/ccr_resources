// line 7428
// inside void ReportTable(
// inside   }else{
#ifdef LEMONEX
    fprintf(out,"#ifdef LEMONEX\n"); lineno++;
    fprintf(out,"#define %sARG_VNAME\n",name); lineno++;
    fprintf(out,"#endif\n"); lineno++;
#endif
