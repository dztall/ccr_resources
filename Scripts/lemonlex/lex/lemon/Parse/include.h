// line 5990
// inside void Parse(struct lemon *gp)
#ifdef LEMONEX
  if( gp->errorcnt ) exit(gp->errorcnt);
  LxState_postprocess(&ps);
  gp->headmode = ps.first_mode;
  gp->headstate = ps.first_state;
#endif
