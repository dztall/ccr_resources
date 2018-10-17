// line 7417
// inside void ReportTable(
// inside   if( lemp->arg && lemp->arg[0] ){
#ifdef LEMONEX
    fprintf(out,"#ifdef LEMONEX\n"); lineno++;
    fprintf(out,"#define %sARG_VNAME ,%s\n",
                 name,&lemp->arg[i]);  lineno++;
    fprintf(out,"#endif\n"); lineno++;
#endif
