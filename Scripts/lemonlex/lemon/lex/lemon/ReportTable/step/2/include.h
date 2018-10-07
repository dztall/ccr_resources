// line 7362
// inside void ReportTable(
#ifdef LEMONEX
  const char *prefix;
  if( lemp->tokenprefix ) prefix = lemp->tokenprefix;
  else                    prefix = "";
  for(i=1; i<lemp->nterminal; i++){
    fprintf(out,"#define %s%-30s %2d\n",prefix,lemp->symbols[i]->name,i);
    lineno++;
  }
#else
  if( mhflag ){
    const char *prefix;
    fprintf(out,"#if INTERFACE\n"); lineno++;
    if( lemp->tokenprefix ) prefix = lemp->tokenprefix;
    else                    prefix = "";
    for(i=1; i<lemp->nterminal; i++){
      fprintf(out,"#define %s%-30s %2d\n",prefix,lemp->symbols[i]->name,i);
      lineno++;
    }
    fprintf(out,"#endif\n"); lineno++;
  }
#endif
