// line 83
#if LEMONEX
#ifdef ParseLX_NESTINGDEPTH
struct lxNestingFrame {
  int prev_state;
  int count;
};
#endif

/* The state of the lexer is completely contained in an instance of
** the following structure */
struct lxLexer {
  int lxstate;
  int lxrow;
  int lxcol;
  const char* filename;
  ParseTOKENTYPE token;
#ifdef ParseLX_NESTINGDEPTH
  struct lxNestingFrame nestingstack[ParseLX_NESTINGDEPTH];
  int nestinglevel;
#endif
};
typedef struct lxLexer lxLexer;

#ifdef ParseLX_NESTINGDEPTH
static int lx_enternesting(
  lxLexer *lxpLexer,           /* The lexer */
  int prev_state
)
{
  if(lxpLexer->nestinglevel >= ParseLX_NESTINGDEPTH){
    printf("out of nesting space\n");
    return 1;
  }
  lxpLexer->nestingstack[lxpLexer->nestinglevel].count = 0;
  lxpLexer->nestingstack[lxpLexer->nestinglevel].prev_state = prev_state;
  ++lxpLexer->nestinglevel;
#if LEMONEX_DBGLVL>=2
  printf("NEST:enter-level:%d(count:%d, prev_state:%d\n",
        lxpLexer->nestinglevel,
        lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count,
        lxpLexer->nestingstack[lxpLexer->nestinglevel-1].prev_state);
#endif
  return 0;
}

static void lx_renewnesting(
  lxLexer *lxpLexer           /* The lexer */
)
{
  ++lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count;
#if LEMONEX_DBGLVL>=2
  printf("NEST:renew-count:%d\n", lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count);
#endif
}

static int lx_leavenesting(
  lxLexer *lxpLexer           /* The lexer */
)
{
#if LEMONEX_DBGLVL>=2
  printf("NEST:leave:%d\n", lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count);
#endif
  if(lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count == 0){
    lxpLexer->lxstate = lxpLexer->nestingstack[lxpLexer->nestinglevel-1].prev_state;
    --lxpLexer->nestinglevel;
#if LEMONEX_DBGLVL>=2
    printf("NEST:leave-level:%d, goto:%d\n", lxpLexer->nestinglevel, lxpLexer->lxstate);
#endif
    return 1;
  }
  --lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count;
#if LEMONEX_DBGLVL>=2
  printf("NEST:leave-count:%d\n", lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count);
#endif
  return 0;
}

#define LX_ENTER_NESTING(prev_state) if(lx_enternesting(lxpLexer, prev_state) == 1) {return -1;}
#define LX_RENEW_NESTING lx_renewnesting(lxpLexer)
#define LX_LEAVE_NESTING() lx_leavenesting(lxpLexer)
#else
#define LX_ENTER_NESTING(prev_state)
#define LX_RENEW_NESTING
#define LX_LEAVE_NESTING()
#endif

#if ParseTOKENTYPE_DEF
#if LEMONEX_DBGLVL>=2
#define LX_FREETOK {printf("FREETOK:%s\n", (yypminor->yy0).buf);free((yypminor->yy0).buf);}
#else
#define LX_FREETOK {free((yypminor->yy0).buf);}
#endif
#endif

#define LX_TOK_RESET 1
#define LX_TOK_CAPTURE 2
#define LX_TOK_FINALIZE 3

/*
** The following is executed to create/update current token value
*/
static void lx_tokenctor(
  lxLexer *lxpLexer,           /* The lexer */
  int op,
  int major,
  char* ch,
  int len
){
#if ParseTOKENTYPE_DEF
  switch(op){
    case LX_TOK_RESET:
#if LEMONEX_DBGLVL>=1
    printf("*****CREATE_TOKEN:(%d,%d)\n", lxpLexer->lxrow, lxpLexer->lxcol);
#endif
      break;
    case LX_TOK_CAPTURE:
      break;
    case LX_TOK_FINALIZE:
#if LEMONEX_DBGLVL>=1
      printf("*****FINALIZE_TOKEN(%d,%d):%s\n", lxpLexer->token.row, lxpLexer->token.col, lxpLexer->token.buf);
#endif
      break;
  }

  if(op == LX_TOK_RESET){
    lxpLexer->token.buf = 0;
    return;
  }

  assert((op == LX_TOK_CAPTURE)||(op == LX_TOK_FINALIZE));
  if(lxpLexer->token.buf == 0){
    lxpLexer->token.buf = (char*)malloc(LX_CAPBUF_CHUNKSIZE);
    lxpLexer->token.buf[0] = 0;
    lxpLexer->token.buflen = LX_CAPBUF_CHUNKSIZE;
    lxpLexer->token.caplen = 0;
    lxpLexer->token.row = lxpLexer->lxrow;
    lxpLexer->token.col = lxpLexer->lxcol;
    lxpLexer->token.filename = lxpLexer->filename;
  }

  if(op == LX_TOK_FINALIZE){
    return;
  }

  while((lxpLexer->token.caplen + len) >= lxpLexer->token.buflen){
#if LEMONEX_DBGLVL>=1
    printf("*****RESIZE_TOKEN\n");
#endif
    lxpLexer->token.buf = (char*)realloc(lxpLexer->token.buf, lxpLexer->token.buflen + LX_CAPBUF_CHUNKSIZE);
    lxpLexer->token.buflen += LX_CAPBUF_CHUNKSIZE;
  }
  for(int i = 0; i < len; ++i, ++lxpLexer->token.caplen){
    assert(ch[i] != 0);
    lxpLexer->token.buf[lxpLexer->token.caplen] = ch[i];
  }
  lxpLexer->token.buf[lxpLexer->token.caplen] = 0;
#if LEMONEX_DBGLVL>=1
  printf("*****CAT_TOKEN:%s\n", lxpLexer->token.buf);
#endif
#else
#define LX_OP op
#define LX_IDX major
#define LX_CAP ch
#define LX_CAPLEN len
#define LX_ROW (lxpLexer->lxrow)
#define LX_COL (lxpLexer->lxcol)
#define LX_FILENAME (lxpLexer->filename)
%%
#undef LX_OP
#undef LX_IDX
#undef LX_CAP
#undef LX_CAPLEN
#undef LX_ROW
#undef LX_COL
#undef LX_FILENAME
#endif
}

#define MASKBITS   0x3F
#define MASK1BYTES 0x80
#define MASK2BYTES 0xC0
#define MASK3BYTES 0xE0
#define MASK4BYTES 0xF0
#define MASK5BYTES 0xF8
#define MASK6BYTES 0xFC

/*
** The following is executed to advance the current position in the input stream
*/
static int lx_advance(
  lxLexer *lxpLexer,           /* The lexer */
  char** curr_pos,
  char** pp,
  char* buf_end,
  int* plen,
  int* pch
){
  char* p = *pp;
  (*curr_pos) = (*pp);
  if(p == buf_end){
    *pch = 0;
    return 0;
  }

  ++lxpLexer->lxcol;
  if((*p == '\r') && (*(p+1) == '\n')) {
    ++p;
    ++(*curr_pos);
    assert(*p == '\n');
  }
  if(*p == '\n') {
    ++lxpLexer->lxrow;
    lxpLexer->lxcol = 0;
  }

  *plen = 0;
  if((*p & MASK6BYTES) == MASK6BYTES) {
    // 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
    *pch = (int)(buf_end - p);
    if(*pch < 6){
      return 1;
    }
    *pch = ((*p & 0x01) << 30) | ( (*(p+1) & MASKBITS) << 24) | ( (*(p+2) & MASKBITS) << 18) | ( (*(p+3) & MASKBITS) << 12) | ( (*(p+4) & MASKBITS) << 6) | (*(p+5) & MASKBITS);
    *plen = 6;
    p += 6;
  } else if((*p & MASK5BYTES) == MASK5BYTES) {
    // 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
    *pch = (int)(buf_end - p);
    if(*pch < 5){
      return 1;
    }
    *pch = ((*p & 0x03) << 24) | ( (*(p+1) & MASKBITS) << 18) | ( (*(p+2) & MASKBITS) << 12) | ( (*(p+3) & MASKBITS) << 6) | (*(p+4) & MASKBITS);
    *plen = 5;
    p += 5;
  } else if((*p & MASK4BYTES) == MASK4BYTES) {
    // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    *pch = (int)(buf_end - p);
    if(*pch < 4){
      return 1;
    }
    *pch = ((*p & 0x07) << 18) | ( (*(p+1) & MASKBITS) << 12) | ( (*(p+2) & MASKBITS) << 6) | (*(p+3) & MASKBITS);
    *plen = 4;
    p += 4;
  } else if((*p & MASK3BYTES) == MASK3BYTES) {
    // 1110xxxx 10xxxxxx 10xxxxxx
    *pch = (int)(buf_end - p);
    if(*pch < 3){
      return 1;
    }
    *pch = ((*p & 0x0F) << 12) | ( (*(p+1) & MASKBITS) << 6) | (*(p+2) & MASKBITS);
    *plen = 3;
    p += 3;
  } else if((*p & MASK2BYTES) == MASK2BYTES) {
    // 110xxxxx 10xxxxxx
    *pch = (int)(buf_end - p);
    if(*pch < 2){
      return 1;
    }
    *pch = ((*p & 0x1F) << 6) | (*(p+1) & MASKBITS);
    *plen = 2;
    p += 2;
  } else {
    // 0xxxxxxx
    *pch = (int)(buf_end - p);
    if(*pch < 1){
      return 1;
    }
    *pch = (*p & 0xff);
    *plen = 1;
    p += 1;
  }
  *pp = p;
  return 0;
}

%%

/* returns 1 if ch is in cls */
static int lx_isclass(int ch, int* clsl){
  int i = 0;
  while(clsl[i] != 0) {
    if((ch >= clsl[i]) && (ch <= clsl[i+1])) {
      return 1;
    }
    i += 2;
  }
  return 0;
}

#define LX_ISLETTER(ch) (lx_isclass(ch, lxcls_l))
#define LX_ISDIGIT(ch) (lx_isclass(ch, lxcls_d))
#define LX_ISWORD(ch) (((LX_ISLETTER(ch) == 1)||(LX_ISDIGIT(ch) == 1))?:1:0)
#define LX_ISSPACE(ch) (lx_isclass(ch, lxcls_s))
#define LX_ISENDL(ch) (lx_isclass(ch, lxcls_e))

#define LX_ADVANCE(ls) {if(lx_advance(lxpLexer, &curr_pos, &p, buf_end, &curr_len, &ch) != 0){lxpLexer->lxstate=ls;return ch;}}
#define LX_RESET lx_tokenctor(lxpLexer, LX_TOK_RESET, 0, 0, 0)
#define LX_SEND(major_token) lx_tokenctor(lxpLexer, LX_TOK_FINALIZE, major_token, 0, 0);Parse(yyp, major_token, lxpLexer->token ParseARG_VNAME)
#define LX_CAPTURE(curr_pos, curr_len) lx_tokenctor(lxpLexer, LX_TOK_CAPTURE, 0, curr_pos, curr_len)
#define LX_SENDERR(err_token) LX_CAPTURE(curr_pos, curr_len);LX_SEND(err_token)

/*
** This function allocates a new lexer.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a lexer.  This pointer is used in subsequent calls
** to ParseRead and ParseFree.
*/
void *ParseLexerAlloc(void *(*mallocProc)(size_t)){
  lxLexer *lxpLexer;
  lxpLexer = (lxLexer*)(*mallocProc)( (size_t)sizeof(lxLexer) );
  if( lxpLexer ){
    lxpLexer->lxstate = 1;
    lxpLexer->lxrow = 1;
    lxpLexer->lxcol = 1;
    lxpLexer->filename = 0;
#ifdef ParseLX_NESTINGDEPTH
    lxpLexer->nestingstack[0].count = 0;
    lxpLexer->nestinglevel = 0;
#endif
    LX_RESET;
  }
  return lxpLexer;
}

/*
** Deallocate and destroy a lexer.
**
** Inputs:
** <ul>
** <li>  A pointer to the lexer.  This should be a pointer
**       obtained from ParseLexerAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseLexerFree(
  void *p,                    /* The lexer to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  lxLexer *lxpLexer = (lxLexer*)p;
  if( lxpLexer==0 ) return;
  (*freeProc)((void*)lxpLexer);
}
#endif /* LEMONEX */
