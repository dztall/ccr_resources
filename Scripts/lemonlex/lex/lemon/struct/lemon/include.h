// line 2131
// inside struct lemon {
#ifdef LEMONEX
  int lxintegration;          /* TRUE if lexer is integrated into parser */
  int lxnestingdepth;         /* nesting depth of lexer */
  int lxdebuglevel;           /* error level of lexer */
  const char *lxencoding;     /* lexer encoding */
  char *lexercode;            /* Lexer code appended to the generated file */
  char *tokenctor;            /* Code to execute to create token data */
  struct LxMode *headmode;    /* List of all lexer modes */
  struct LxState *headstate;  /* List of all lexer states */
  const int *lxclasslist;    /* lexer class list */
#endif
