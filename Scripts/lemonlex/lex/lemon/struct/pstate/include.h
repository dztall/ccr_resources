// line 3909
// inside struct pstate {
#ifdef LEMONEX
  int is_defininglx;          /* 1 if currently defining a lexer token */
  int next_lxstate_id;        /* next available lexer state number */
  struct LxMode *first_mode;  /* Pointer to first mode in the lexer */
  struct LxMode *last_mode;   /* Pointer to last mode in the lexer */
  struct LxState *first_state;/* Pointer to first state in parser */
  struct LxState *last_state; /* Pointer to last state in last mode */
  struct LxState *curr_state; /* Pointer to last state in current regex */
  struct symbol *lastlxsym;   /* Pointer to current lexer symbol being defined */
  int nstarcount;             /* count of regex parts that are not root-level star regexes */
  int is_capturing;           /* 1 if current regex is capturing */
#endif
