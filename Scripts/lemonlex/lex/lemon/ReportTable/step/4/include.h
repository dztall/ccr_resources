// line 7706
// inside void ReportTable(
#ifdef LEMONEX
  if(( lemp->tokendest != 0) || (lemp->tokentype == 0))
#else
  if( lemp->tokendest )
#endif
 { // nessesary to avoid a bug in kate
