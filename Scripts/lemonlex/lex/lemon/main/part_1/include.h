// line 3310
// inside main
#ifdef LEMONEX
  strncpy(ofileext, ".c", OFILE_LEN);
  if (handle_d_option) strcpy(ofiledir,"./");
#endif

  atexit(x_e_free);
