// line 7336
// inside void ReportTable(
#ifdef LEMONEX
  out = file_open(lemp,ofileext,"wb");
#else
  out = file_open(lemp,".c","wb");
#endif
