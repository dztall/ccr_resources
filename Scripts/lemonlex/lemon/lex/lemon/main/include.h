// line 3310
// inside main
#ifdef LEMONEX
  strncpy(ofileext, ".c", OFILE_LEN);
  if (handle_d_option) strcpy(ofiledir,"./");
#endif

// line 3338
// inside main
#ifdef LEMONEX
  lem.lxintegration = 1;
  lem.lxnestingdepth = 32;
  lem.lxdebuglevel = 0;
  lem.lxencoding = 0;
  lem.headmode = 0;
  lem.headstate = 0;
  lem.tokenctor = 0;
  lem.lxclasslist = s_lxclasslist;
#endif
