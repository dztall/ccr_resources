/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* to be able to use certain functions in %include directives we first need to define them */
/* The include code might contain pch header, so include stdio.h here */
#include <stdio.h>
#include <assert.h> // this uses assert
#include <stdlib.h> // uses callbacks to free and malloc, have them already available
#include <string.h>
#define LEMONEX 1
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YY_MAX_SHIFT       Maximum value for shift actions
**    YY_MIN_SHIFTREDUCE Minimum value for shift-reduce actions
**    YY_MAX_SHIFTREDUCE Maximum value for shift-reduce actions
**    YY_MIN_REDUCE      Maximum value for reduce actions
**    YY_ERROR_ACTION    The yy_action[] code for syntax error
**    YY_ACCEPT_ACTION   The yy_action[] code for accept
**    YY_NO_ACTION       The yy_action[] code for no-op
*/

#if LEMONEX
#define LX_CAPBUF_CHUNKSIZE 128
struct lxToken{
  char* buf;
  int buflen;
  int caplen;
  int row;
  int col;
  const char* filename;
};
#endif /* LEMONEX */
#define YYCODETYPE unsigned char
#define YYNOCODE 4
#define YYACTIONTYPE unsigned char
#if INTERFACE
#ifdef LEMONEX
#define ParseTOKENTYPE struct lxToken
#define ParseTOKENTYPE_DEF 1
#else /* LEMONEX */
#define ParseTOKENTYPE void*
#endif /* LEMONEX */
#endif
typedef union {
	int yyinit;
	ParseTOKENTYPE yy0;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#if INTERFACE
#define ParseARG_SDECL
#define ParseARG_PDECL
#define ParseARG_FETCH
#define ParseARG_STORE
#ifdef LEMONEX
#define ParseARG_VNAME
#endif
#define ParseARG_SDECL
#endif
#ifdef LEMONEX
#define ParseLX_INTEGRATEDMODE 1
#define ParseLX_NESTINGDEPTH 32
#endif
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
#define LX_NESTLEVEL (lxpLexer->nestinglevel-(lxpLexer->nestinglevel==0?0:lxpLexer->nestinglevel)) + lxpLexer->nestingstack[(lxpLexer->nestinglevel==0?1:lxpLexer->nestinglevel)-1].count
#define LX_NESTMAX ParseLX_NESTINGDEPTH
#else
#define LX_NESTLEVEL 0
#define LX_NESTMAX 0
#endif

/* declare function definitions here, this will be blank if there are no definitions */
int ParseReadString(
  char *buf
  ,const char *filename
  ,const char* dbgpfx
  ParseARG_PDECL               /* Optional %extra_argument parameter */
);
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#line 2 "example/heredoc.y"

	char * CAT[LX_NESTMAX] = {0};
// 	char * AAA = "AAA";
#line 144 "./example/heredoc/heredoc.c"
#define LEMONEX_DBGLVL 3
#include "heredoc.h"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
#ifdef LEMONEX
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
	if (lxpLexer->nestinglevel == 0) {
		printf("NEST:cannot leave empty nest\n");
		printf("NEST:leave-level:%d\n", lxpLexer->nestinglevel);
		return -1;
	}
	if (lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count != 0) {
		lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count--;
		return 0;
	}
#if LEMONEX_DBGLVL>=2
  printf("NEST:leave-level:%d\n", lxpLexer->nestinglevel);
  printf("NEST:leave:%d\n", lxpLexer->nestingstack[lxpLexer->nestinglevel].count);
  printf("NEST:leave-1:%d\n", lxpLexer->nestingstack[lxpLexer->nestinglevel-1].count);
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

int bcmpcq__2(void const *vp, size_t n, void const *vp2, size_t n2)
{
    int string_match = 0;
    unsigned char const *p = vp;
    unsigned char const *p2 = vp2;
    int matches=0;
    int contains_matches=0;
    for (size_t i=0; i<n; i++) {
        if (p[i] == p2[i]) {
            matches++;
        } else {
            if (matches) contains_matches = 1;
            break;
        }
    }
    if (matches == 0) {
        return -1;
	} else if (matches == n) {
		return 0;
    } else {
        int ret = 0;
        if (contains_matches) ret = 1;
        return ret;
    }
}


/*
** The following is executed to lookahead the current position in the input stream without introducing the need for backtracking
*/

static int lx_lookahead(
  lxLexer *lxpLexer,           /* The lexer */
  char** curr_pos,
  char** pp,
  char* buf_end,
  int* plen,
  int* pch,
  char * lookahead_token
){
  int lookahead_lxcol = lxpLexer->lxcol;
  int lookahead_lxrow = lxpLexer->lxrow;
#if LEMONEX_DBGLVL>=1
  printf("checking for match (%s) against %s\n", lookahead_token, *curr_pos);
#endif
  if (bcmpcq__2(lookahead_token, strlen(lookahead_token), *curr_pos, strlen(*curr_pos)) == 0) {
#if LEMONEX_DBGLVL>=1
	  puts("LOOKAHEAD: found match");
#endif
	  return -1;
  }
  char* p = *pp;
  if(p == buf_end){
    *pch = 0;
	puts("EOF");
    return 0;
  }
  

  ++lookahead_lxcol;
  if((*p == '\r') && (*(p+1) == '\n')) {
    ++p;
    assert(*p == '\n');
  }
  if(*p == '\n') {
    ++lookahead_lxrow;
    lookahead_lxcol = 0;
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
  return 1;
}

static int lxcls_l[] = {
  0x61    ,0x7A    ,  0xB5    ,0xB5    ,  0xDF    ,0xF6    ,  0xF8    ,0xFF    ,
  0x101   ,0x101   ,  0x103   ,0x103   ,  0x105   ,0x105   ,  0x107   ,0x107   ,
  0x109   ,0x109   ,  0x10B   ,0x10B   ,  0x10D   ,0x10D   ,  0x10F   ,0x10F   ,
  0x111   ,0x111   ,  0x113   ,0x113   ,  0x115   ,0x115   ,  0x117   ,0x117   ,
  0x119   ,0x119   ,  0x11B   ,0x11B   ,  0x11D   ,0x11D   ,  0x11F   ,0x11F   ,
  0x121   ,0x121   ,  0x123   ,0x123   ,  0x125   ,0x125   ,  0x127   ,0x127   ,
  0x129   ,0x129   ,  0x12B   ,0x12B   ,  0x12D   ,0x12D   ,  0x12F   ,0x12F   ,
  0x131   ,0x131   ,  0x133   ,0x133   ,  0x135   ,0x135   ,  0x137   ,0x138   ,
  0x13A   ,0x13A   ,  0x13C   ,0x13C   ,  0x13E   ,0x13E   ,  0x140   ,0x140   ,
  0x142   ,0x142   ,  0x144   ,0x144   ,  0x146   ,0x146   ,  0x148   ,0x149   ,
  0x14B   ,0x14B   ,  0x14D   ,0x14D   ,  0x14F   ,0x14F   ,  0x151   ,0x151   ,
  0x153   ,0x153   ,  0x155   ,0x155   ,  0x157   ,0x157   ,  0x159   ,0x159   ,
  0x15B   ,0x15B   ,  0x15D   ,0x15D   ,  0x15F   ,0x15F   ,  0x161   ,0x161   ,
  0x163   ,0x163   ,  0x165   ,0x165   ,  0x167   ,0x167   ,  0x169   ,0x169   ,
  0x16B   ,0x16B   ,  0x16D   ,0x16D   ,  0x16F   ,0x16F   ,  0x171   ,0x171   ,
  0x173   ,0x173   ,  0x175   ,0x175   ,  0x177   ,0x177   ,  0x17A   ,0x17A   ,
  0x17C   ,0x17C   ,  0x17E   ,0x180   ,  0x183   ,0x183   ,  0x185   ,0x185   ,
  0x188   ,0x188   ,  0x18C   ,0x18D   ,  0x192   ,0x192   ,  0x195   ,0x195   ,
  0x199   ,0x19B   ,  0x19E   ,0x19E   ,  0x1A1   ,0x1A1   ,  0x1A3   ,0x1A3   ,
  0x1A5   ,0x1A5   ,  0x1A8   ,0x1A8   ,  0x1AA   ,0x1AB   ,  0x1AD   ,0x1AD   ,
  0x1B0   ,0x1B0   ,  0x1B4   ,0x1B4   ,  0x1B6   ,0x1B6   ,  0x1B9   ,0x1BA   ,
  0x1BD   ,0x1BF   ,  0x1C6   ,0x1C6   ,  0x1C9   ,0x1C9   ,  0x1CC   ,0x1CC   ,
  0x1CE   ,0x1CE   ,  0x1D0   ,0x1D0   ,  0x1D2   ,0x1D2   ,  0x1D4   ,0x1D4   ,
  0x1D6   ,0x1D6   ,  0x1D8   ,0x1D8   ,  0x1DA   ,0x1DA   ,  0x1DC   ,0x1DD   ,
  0x1DF   ,0x1DF   ,  0x1E1   ,0x1E1   ,  0x1E3   ,0x1E3   ,  0x1E5   ,0x1E5   ,
  0x1E7   ,0x1E7   ,  0x1E9   ,0x1E9   ,  0x1EB   ,0x1EB   ,  0x1ED   ,0x1ED   ,
  0x1EF   ,0x1F0   ,  0x1F3   ,0x1F3   ,  0x1F5   ,0x1F5   ,  0x1F9   ,0x1F9   ,
  0x1FB   ,0x1FB   ,  0x1FD   ,0x1FD   ,  0x1FF   ,0x1FF   ,  0x201   ,0x201   ,
  0x203   ,0x203   ,  0x205   ,0x205   ,  0x207   ,0x207   ,  0x209   ,0x209   ,
  0x20B   ,0x20B   ,  0x20D   ,0x20D   ,  0x20F   ,0x20F   ,  0x211   ,0x211   ,
  0x213   ,0x213   ,  0x215   ,0x215   ,  0x217   ,0x217   ,  0x219   ,0x219   ,
  0x21B   ,0x21B   ,  0x21D   ,0x21D   ,  0x21F   ,0x21F   ,  0x221   ,0x221   ,
  0x223   ,0x223   ,  0x225   ,0x225   ,  0x227   ,0x227   ,  0x229   ,0x229   ,
  0x22B   ,0x22B   ,  0x22D   ,0x22D   ,  0x22F   ,0x22F   ,  0x231   ,0x231   ,
  0x233   ,0x239   ,  0x23C   ,0x23C   ,  0x23F   ,0x240   ,  0x242   ,0x242   ,
  0x247   ,0x247   ,  0x249   ,0x249   ,  0x24B   ,0x24B   ,  0x24D   ,0x24D   ,
  0x24F   ,0x293   ,  0x295   ,0x2AF   ,  0x371   ,0x371   ,  0x373   ,0x373   ,
  0x377   ,0x377   ,  0x37B   ,0x37D   ,  0x390   ,0x390   ,  0x3AC   ,0x3CE   ,
  0x3D0   ,0x3D1   ,  0x3D5   ,0x3D7   ,  0x3D9   ,0x3D9   ,  0x3DB   ,0x3DB   ,
  0x3DD   ,0x3DD   ,  0x3DF   ,0x3DF   ,  0x3E1   ,0x3E1   ,  0x3E3   ,0x3E3   ,
  0x3E5   ,0x3E5   ,  0x3E7   ,0x3E7   ,  0x3E9   ,0x3E9   ,  0x3EB   ,0x3EB   ,
  0x3ED   ,0x3ED   ,  0x3EF   ,0x3F3   ,  0x3F5   ,0x3F5   ,  0x3F8   ,0x3F8   ,
  0x3FB   ,0x3FC   ,  0x430   ,0x45F   ,  0x461   ,0x461   ,  0x463   ,0x463   ,
  0x465   ,0x465   ,  0x467   ,0x467   ,  0x469   ,0x469   ,  0x46B   ,0x46B   ,
  0x46D   ,0x46D   ,  0x46F   ,0x46F   ,  0x471   ,0x471   ,  0x473   ,0x473   ,
  0x475   ,0x475   ,  0x477   ,0x477   ,  0x479   ,0x479   ,  0x47B   ,0x47B   ,
  0x47D   ,0x47D   ,  0x47F   ,0x47F   ,  0x481   ,0x481   ,  0x48B   ,0x48B   ,
  0x48D   ,0x48D   ,  0x48F   ,0x48F   ,  0x491   ,0x491   ,  0x493   ,0x493   ,
  0x495   ,0x495   ,  0x497   ,0x497   ,  0x499   ,0x499   ,  0x49B   ,0x49B   ,
  0x49D   ,0x49D   ,  0x49F   ,0x49F   ,  0x4A1   ,0x4A1   ,  0x4A3   ,0x4A3   ,
  0x4A5   ,0x4A5   ,  0x4A7   ,0x4A7   ,  0x4A9   ,0x4A9   ,  0x4AB   ,0x4AB   ,
  0x4AD   ,0x4AD   ,  0x4AF   ,0x4AF   ,  0x4B1   ,0x4B1   ,  0x4B3   ,0x4B3   ,
  0x4B5   ,0x4B5   ,  0x4B7   ,0x4B7   ,  0x4B9   ,0x4B9   ,  0x4BB   ,0x4BB   ,
  0x4BD   ,0x4BD   ,  0x4BF   ,0x4BF   ,  0x4C2   ,0x4C2   ,  0x4C4   ,0x4C4   ,
  0x4C6   ,0x4C6   ,  0x4C8   ,0x4C8   ,  0x4CA   ,0x4CA   ,  0x4CC   ,0x4CC   ,
  0x4CE   ,0x4CF   ,  0x4D1   ,0x4D1   ,  0x4D3   ,0x4D3   ,  0x4D5   ,0x4D5   ,
  0x4D7   ,0x4D7   ,  0x4D9   ,0x4D9   ,  0x4DB   ,0x4DB   ,  0x4DD   ,0x4DD   ,
  0x4DF   ,0x4DF   ,  0x4E1   ,0x4E1   ,  0x4E3   ,0x4E3   ,  0x4E5   ,0x4E5   ,
  0x4E7   ,0x4E7   ,  0x4E9   ,0x4E9   ,  0x4EB   ,0x4EB   ,  0x4ED   ,0x4ED   ,
  0x4EF   ,0x4EF   ,  0x4F1   ,0x4F1   ,  0x4F3   ,0x4F3   ,  0x4F5   ,0x4F5   ,
  0x4F7   ,0x4F7   ,  0x4F9   ,0x4F9   ,  0x4FB   ,0x4FB   ,  0x4FD   ,0x4FD   ,
  0x4FF   ,0x4FF   ,  0x501   ,0x501   ,  0x503   ,0x503   ,  0x505   ,0x505   ,
  0x507   ,0x507   ,  0x509   ,0x509   ,  0x50B   ,0x50B   ,  0x50D   ,0x50D   ,
  0x50F   ,0x50F   ,  0x511   ,0x511   ,  0x513   ,0x513   ,  0x515   ,0x515   ,
  0x517   ,0x517   ,  0x519   ,0x519   ,  0x51B   ,0x51B   ,  0x51D   ,0x51D   ,
  0x51F   ,0x51F   ,  0x521   ,0x521   ,  0x523   ,0x523   ,  0x525   ,0x525   ,
  0x527   ,0x527   ,  0x529   ,0x529   ,  0x52B   ,0x52B   ,  0x52D   ,0x52D   ,
  0x52F   ,0x52F   ,  0x561   ,0x587   ,  0x13F8  ,0x13FD  ,  0x1D00  ,0x1D2B  ,
  0x1D6B  ,0x1D77  ,  0x1D79  ,0x1D9A  ,  0x1E01  ,0x1E01  ,  0x1E03  ,0x1E03  ,
  0x1E05  ,0x1E05  ,  0x1E07  ,0x1E07  ,  0x1E09  ,0x1E09  ,  0x1E0B  ,0x1E0B  ,
  0x1E0D  ,0x1E0D  ,  0x1E0F  ,0x1E0F  ,  0x1E11  ,0x1E11  ,  0x1E13  ,0x1E13  ,
  0x1E15  ,0x1E15  ,  0x1E17  ,0x1E17  ,  0x1E19  ,0x1E19  ,  0x1E1B  ,0x1E1B  ,
  0x1E1D  ,0x1E1D  ,  0x1E1F  ,0x1E1F  ,  0x1E21  ,0x1E21  ,  0x1E23  ,0x1E23  ,
  0x1E25  ,0x1E25  ,  0x1E27  ,0x1E27  ,  0x1E29  ,0x1E29  ,  0x1E2B  ,0x1E2B  ,
  0x1E2D  ,0x1E2D  ,  0x1E2F  ,0x1E2F  ,  0x1E31  ,0x1E31  ,  0x1E33  ,0x1E33  ,
  0x1E35  ,0x1E35  ,  0x1E37  ,0x1E37  ,  0x1E39  ,0x1E39  ,  0x1E3B  ,0x1E3B  ,
  0x1E3D  ,0x1E3D  ,  0x1E3F  ,0x1E3F  ,  0x1E41  ,0x1E41  ,  0x1E43  ,0x1E43  ,
  0x1E45  ,0x1E45  ,  0x1E47  ,0x1E47  ,  0x1E49  ,0x1E49  ,  0x1E4B  ,0x1E4B  ,
  0x1E4D  ,0x1E4D  ,  0x1E4F  ,0x1E4F  ,  0x1E51  ,0x1E51  ,  0x1E53  ,0x1E53  ,
  0x1E55  ,0x1E55  ,  0x1E57  ,0x1E57  ,  0x1E59  ,0x1E59  ,  0x1E5B  ,0x1E5B  ,
  0x1E5D  ,0x1E5D  ,  0x1E5F  ,0x1E5F  ,  0x1E61  ,0x1E61  ,  0x1E63  ,0x1E63  ,
  0x1E65  ,0x1E65  ,  0x1E67  ,0x1E67  ,  0x1E69  ,0x1E69  ,  0x1E6B  ,0x1E6B  ,
  0x1E6D  ,0x1E6D  ,  0x1E6F  ,0x1E6F  ,  0x1E71  ,0x1E71  ,  0x1E73  ,0x1E73  ,
  0x1E75  ,0x1E75  ,  0x1E77  ,0x1E77  ,  0x1E79  ,0x1E79  ,  0x1E7B  ,0x1E7B  ,
  0x1E7D  ,0x1E7D  ,  0x1E7F  ,0x1E7F  ,  0x1E81  ,0x1E81  ,  0x1E83  ,0x1E83  ,
  0x1E85  ,0x1E85  ,  0x1E87  ,0x1E87  ,  0x1E89  ,0x1E89  ,  0x1E8B  ,0x1E8B  ,
  0x1E8D  ,0x1E8D  ,  0x1E8F  ,0x1E8F  ,  0x1E91  ,0x1E91  ,  0x1E93  ,0x1E93  ,
  0x1E95  ,0x1E9D  ,  0x1E9F  ,0x1E9F  ,  0x1EA1  ,0x1EA1  ,  0x1EA3  ,0x1EA3  ,
  0x1EA5  ,0x1EA5  ,  0x1EA7  ,0x1EA7  ,  0x1EA9  ,0x1EA9  ,  0x1EAB  ,0x1EAB  ,
  0x1EAD  ,0x1EAD  ,  0x1EAF  ,0x1EAF  ,  0x1EB1  ,0x1EB1  ,  0x1EB3  ,0x1EB3  ,
  0x1EB5  ,0x1EB5  ,  0x1EB7  ,0x1EB7  ,  0x1EB9  ,0x1EB9  ,  0x1EBB  ,0x1EBB  ,
  0x1EBD  ,0x1EBD  ,  0x1EBF  ,0x1EBF  ,  0x1EC1  ,0x1EC1  ,  0x1EC3  ,0x1EC3  ,
  0x1EC5  ,0x1EC5  ,  0x1EC7  ,0x1EC7  ,  0x1EC9  ,0x1EC9  ,  0x1ECB  ,0x1ECB  ,
  0x1ECD  ,0x1ECD  ,  0x1ECF  ,0x1ECF  ,  0x1ED1  ,0x1ED1  ,  0x1ED3  ,0x1ED3  ,
  0x1ED5  ,0x1ED5  ,  0x1ED7  ,0x1ED7  ,  0x1ED9  ,0x1ED9  ,  0x1EDB  ,0x1EDB  ,
  0x1EDD  ,0x1EDD  ,  0x1EDF  ,0x1EDF  ,  0x1EE1  ,0x1EE1  ,  0x1EE3  ,0x1EE3  ,
  0x1EE5  ,0x1EE5  ,  0x1EE7  ,0x1EE7  ,  0x1EE9  ,0x1EE9  ,  0x1EEB  ,0x1EEB  ,
  0x1EED  ,0x1EED  ,  0x1EEF  ,0x1EEF  ,  0x1EF1  ,0x1EF1  ,  0x1EF3  ,0x1EF3  ,
  0x1EF5  ,0x1EF5  ,  0x1EF7  ,0x1EF7  ,  0x1EF9  ,0x1EF9  ,  0x1EFB  ,0x1EFB  ,
  0x1EFD  ,0x1EFD  ,  0x1EFF  ,0x1F07  ,  0x1F10  ,0x1F15  ,  0x1F20  ,0x1F27  ,
  0x1F30  ,0x1F37  ,  0x1F40  ,0x1F45  ,  0x1F50  ,0x1F57  ,  0x1F60  ,0x1F67  ,
  0x1F70  ,0x1F87  ,  0x1F90  ,0x1F97  ,  0x1FA0  ,0x1FA7  ,  0x1FB0  ,0x1FB7  ,
  0x1FBE  ,0x1FBE  ,  0x1FC2  ,0x1FC7  ,  0x1FD0  ,0x1FD7  ,  0x1FE0  ,0x1FE7  ,
  0x1FF2  ,0x1FF7  ,  0x210A  ,0x210A  ,  0x210E  ,0x210F  ,  0x2113  ,0x2113  ,
  0x212F  ,0x212F  ,  0x2134  ,0x2134  ,  0x2139  ,0x2139  ,  0x213C  ,0x213D  ,
  0x2146  ,0x2149  ,  0x214E  ,0x214E  ,  0x2184  ,0x2184  ,  0x2C30  ,0x2C5E  ,
  0x2C61  ,0x2C61  ,  0x2C65  ,0x2C66  ,  0x2C68  ,0x2C68  ,  0x2C6A  ,0x2C6A  ,
  0x2C6C  ,0x2C6C  ,  0x2C71  ,0x2C71  ,  0x2C73  ,0x2C74  ,  0x2C76  ,0x2C7B  ,
  0x2C81  ,0x2C81  ,  0x2C83  ,0x2C83  ,  0x2C85  ,0x2C85  ,  0x2C87  ,0x2C87  ,
  0x2C89  ,0x2C89  ,  0x2C8B  ,0x2C8B  ,  0x2C8D  ,0x2C8D  ,  0x2C8F  ,0x2C8F  ,
  0x2C91  ,0x2C91  ,  0x2C93  ,0x2C93  ,  0x2C95  ,0x2C95  ,  0x2C97  ,0x2C97  ,
  0x2C99  ,0x2C99  ,  0x2C9B  ,0x2C9B  ,  0x2C9D  ,0x2C9D  ,  0x2C9F  ,0x2C9F  ,
  0x2CA1  ,0x2CA1  ,  0x2CA3  ,0x2CA3  ,  0x2CA5  ,0x2CA5  ,  0x2CA7  ,0x2CA7  ,
  0x2CA9  ,0x2CA9  ,  0x2CAB  ,0x2CAB  ,  0x2CAD  ,0x2CAD  ,  0x2CAF  ,0x2CAF  ,
  0x2CB1  ,0x2CB1  ,  0x2CB3  ,0x2CB3  ,  0x2CB5  ,0x2CB5  ,  0x2CB7  ,0x2CB7  ,
  0x2CB9  ,0x2CB9  ,  0x2CBB  ,0x2CBB  ,  0x2CBD  ,0x2CBD  ,  0x2CBF  ,0x2CBF  ,
  0x2CC1  ,0x2CC1  ,  0x2CC3  ,0x2CC3  ,  0x2CC5  ,0x2CC5  ,  0x2CC7  ,0x2CC7  ,
  0x2CC9  ,0x2CC9  ,  0x2CCB  ,0x2CCB  ,  0x2CCD  ,0x2CCD  ,  0x2CCF  ,0x2CCF  ,
  0x2CD1  ,0x2CD1  ,  0x2CD3  ,0x2CD3  ,  0x2CD5  ,0x2CD5  ,  0x2CD7  ,0x2CD7  ,
  0x2CD9  ,0x2CD9  ,  0x2CDB  ,0x2CDB  ,  0x2CDD  ,0x2CDD  ,  0x2CDF  ,0x2CDF  ,
  0x2CE1  ,0x2CE1  ,  0x2CE3  ,0x2CE4  ,  0x2CEC  ,0x2CEC  ,  0x2CEE  ,0x2CEE  ,
  0x2CF3  ,0x2CF3  ,  0x2D00  ,0x2D2D  ,  0xA641  ,0xA641  ,  0xA643  ,0xA643  ,
  0xA645  ,0xA645  ,  0xA647  ,0xA647  ,  0xA649  ,0xA649  ,  0xA64B  ,0xA64B  ,
  0xA64D  ,0xA64D  ,  0xA64F  ,0xA64F  ,  0xA651  ,0xA651  ,  0xA653  ,0xA653  ,
  0xA655  ,0xA655  ,  0xA657  ,0xA657  ,  0xA659  ,0xA659  ,  0xA65B  ,0xA65B  ,
  0xA65D  ,0xA65D  ,  0xA65F  ,0xA65F  ,  0xA661  ,0xA661  ,  0xA663  ,0xA663  ,
  0xA665  ,0xA665  ,  0xA667  ,0xA667  ,  0xA669  ,0xA669  ,  0xA66B  ,0xA66B  ,
  0xA66D  ,0xA66D  ,  0xA681  ,0xA681  ,  0xA683  ,0xA683  ,  0xA685  ,0xA685  ,
  0xA687  ,0xA687  ,  0xA689  ,0xA689  ,  0xA68B  ,0xA68B  ,  0xA68D  ,0xA68D  ,
  0xA68F  ,0xA68F  ,  0xA691  ,0xA691  ,  0xA693  ,0xA693  ,  0xA695  ,0xA695  ,
  0xA697  ,0xA697  ,  0xA699  ,0xA699  ,  0xA69B  ,0xA69B  ,  0xA723  ,0xA723  ,
  0xA725  ,0xA725  ,  0xA727  ,0xA727  ,  0xA729  ,0xA729  ,  0xA72B  ,0xA72B  ,
  0xA72D  ,0xA72D  ,  0xA72F  ,0xA731  ,  0xA733  ,0xA733  ,  0xA735  ,0xA735  ,
  0xA737  ,0xA737  ,  0xA739  ,0xA739  ,  0xA73B  ,0xA73B  ,  0xA73D  ,0xA73D  ,
  0xA73F  ,0xA73F  ,  0xA741  ,0xA741  ,  0xA743  ,0xA743  ,  0xA745  ,0xA745  ,
  0xA747  ,0xA747  ,  0xA749  ,0xA749  ,  0xA74B  ,0xA74B  ,  0xA74D  ,0xA74D  ,
  0xA74F  ,0xA74F  ,  0xA751  ,0xA751  ,  0xA753  ,0xA753  ,  0xA755  ,0xA755  ,
  0xA757  ,0xA757  ,  0xA759  ,0xA759  ,  0xA75B  ,0xA75B  ,  0xA75D  ,0xA75D  ,
  0xA75F  ,0xA75F  ,  0xA761  ,0xA761  ,  0xA763  ,0xA763  ,  0xA765  ,0xA765  ,
  0xA767  ,0xA767  ,  0xA769  ,0xA769  ,  0xA76B  ,0xA76B  ,  0xA76D  ,0xA76D  ,
  0xA76F  ,0xA76F  ,  0xA771  ,0xA778  ,  0xA77A  ,0xA77A  ,  0xA77C  ,0xA77C  ,
  0xA77F  ,0xA77F  ,  0xA781  ,0xA781  ,  0xA783  ,0xA783  ,  0xA785  ,0xA785  ,
  0xA787  ,0xA787  ,  0xA78C  ,0xA78C  ,  0xA78E  ,0xA78E  ,  0xA791  ,0xA791  ,
  0xA793  ,0xA795  ,  0xA797  ,0xA797  ,  0xA799  ,0xA799  ,  0xA79B  ,0xA79B  ,
  0xA79D  ,0xA79D  ,  0xA79F  ,0xA79F  ,  0xA7A1  ,0xA7A1  ,  0xA7A3  ,0xA7A3  ,
  0xA7A5  ,0xA7A5  ,  0xA7A7  ,0xA7A7  ,  0xA7A9  ,0xA7A9  ,  0xA7B5  ,0xA7B5  ,
  0xA7B7  ,0xA7B7  ,  0xA7FA  ,0xA7FA  ,  0xAB30  ,0xAB5A  ,  0xAB60  ,0xABBF  ,
  0xFB00  ,0xFB17  ,  0xFF41  ,0xFF5A  ,  0x10428 ,0x1044F ,  0x10CC0 ,0x10CF2 ,
  0x118C0 ,0x118DF ,  0x1D41A ,0x1D433 ,  0x1D44E ,0x1D467 ,  0x1D482 ,0x1D49B ,
  0x1D4B6 ,0x1D4CF ,  0x1D4EA ,0x1D503 ,  0x1D51E ,0x1D537 ,  0x1D552 ,0x1D56B ,
  0x1D586 ,0x1D59F ,  0x1D5BA ,0x1D5D3 ,  0x1D5EE ,0x1D607 ,  0x1D622 ,0x1D63B ,
  0x1D656 ,0x1D66F ,  0x1D68A ,0x1D6A5 ,  0x1D6C2 ,0x1D6DA ,  0x1D6DC ,0x1D6E1 ,
  0x1D6FC ,0x1D714 ,  0x1D716 ,0x1D71B ,  0x1D736 ,0x1D74E ,  0x1D750 ,0x1D755 ,
  0x1D770 ,0x1D788 ,  0x1D78A ,0x1D78F ,  0x1D7AA ,0x1D7C2 ,  0x1D7C4 ,0x1D7C9 ,
  0x1D7CB ,0x1D7CB ,  0x2B0   ,0x2C1   ,  0x2C6   ,0x2D1   ,  0x2E0   ,0x2E4   ,
  0x2EC   ,0x2EC   ,  0x2EE   ,0x2EE   ,  0x374   ,0x374   ,  0x37A   ,0x37A   ,
  0x559   ,0x559   ,  0x640   ,0x640   ,  0x6E5   ,0x6E6   ,  0x7F4   ,0x7F5   ,
  0x7FA   ,0x7FA   ,  0x81A   ,0x81A   ,  0x824   ,0x824   ,  0x828   ,0x828   ,
  0x971   ,0x971   ,  0xE46   ,0xE46   ,  0xEC6   ,0xEC6   ,  0x10FC  ,0x10FC  ,
  0x17D7  ,0x17D7  ,  0x1843  ,0x1843  ,  0x1AA7  ,0x1AA7  ,  0x1C78  ,0x1C7D  ,
  0x1D2C  ,0x1D6A  ,  0x1D78  ,0x1D78  ,  0x1D9B  ,0x1DBF  ,  0x2071  ,0x2071  ,
  0x207F  ,0x207F  ,  0x2090  ,0x209C  ,  0x2C7C  ,0x2C7D  ,  0x2D6F  ,0x2D6F  ,
  0x2E2F  ,0x2E2F  ,  0x3005  ,0x3005  ,  0x3031  ,0x3035  ,  0x303B  ,0x303B  ,
  0x309D  ,0x309E  ,  0x30FC  ,0x30FE  ,  0xA015  ,0xA015  ,  0xA4F8  ,0xA4FD  ,
  0xA60C  ,0xA60C  ,  0xA67F  ,0xA67F  ,  0xA69C  ,0xA69D  ,  0xA717  ,0xA71F  ,
  0xA770  ,0xA770  ,  0xA788  ,0xA788  ,  0xA7F8  ,0xA7F9  ,  0xA9CF  ,0xA9CF  ,
  0xA9E6  ,0xA9E6  ,  0xAA70  ,0xAA70  ,  0xAADD  ,0xAADD  ,  0xAAF3  ,0xAAF4  ,
  0xAB5C  ,0xAB5F  ,  0xFF70  ,0xFF70  ,  0xFF9E  ,0xFF9F  ,  0x16B40 ,0x16B43 ,
  0x16F93 ,0x16F9F ,  0xAA    ,0xAA    ,  0xBA    ,0xBA    ,  0x1BB   ,0x1BB   ,
  0x1C0   ,0x1C3   ,  0x294   ,0x294   ,  0x5D0   ,0x5F2   ,  0x620   ,0x63F   ,
  0x641   ,0x64A   ,  0x66E   ,0x66F   ,  0x671   ,0x6D3   ,  0x6D5   ,0x6D5   ,
  0x6EE   ,0x6EF   ,  0x6FA   ,0x6FC   ,  0x6FF   ,0x6FF   ,  0x710   ,0x710   ,
  0x712   ,0x72F   ,  0x74D   ,0x7A5   ,  0x7B1   ,0x7B1   ,  0x7CA   ,0x7EA   ,
  0x800   ,0x815   ,  0x840   ,0x858   ,  0x8A0   ,0x8B4   ,  0x900   ,0x963   ,
  0x970   ,0x97F   ,  0x980   ,0x9E5   ,  0x9F0   ,0x9FF   ,  0xA00   ,0xA65   ,
  0xA70   ,0xA7F   ,  0xA80   ,0xAE5   ,  0xAF0   ,0xAFF   ,  0xB00   ,0xB65   ,
  0xB70   ,0xB7F   ,  0xB80   ,0xBE5   ,  0xBF0   ,0xBFF   ,  0xC00   ,0xC65   ,
  0xC70   ,0xC7F   ,  0xC80   ,0xCE5   ,  0xCF0   ,0xCFF   ,  0xD00   ,0xD65   ,
  0xD70   ,0xD7F   ,  0xD85   ,0xDC6   ,  0xE01   ,0xE30   ,  0xE32   ,0xE33   ,
  0xE40   ,0xE45   ,  0xE81   ,0xEB0   ,  0xEB2   ,0xEB3   ,  0xEBD   ,0xEC4   ,
  0xEDC   ,0xF00   ,  0xF40   ,0xF6C   ,  0xF88   ,0xF8C   ,  0x1000  ,0x102A  ,
  0x103F  ,0x103F  ,  0x1050  ,0x1055  ,  0x105A  ,0x105D  ,  0x1061  ,0x1061  ,
  0x1065  ,0x1066  ,  0x106E  ,0x1070  ,  0x1075  ,0x1081  ,  0x108E  ,0x108E  ,
  0x10D0  ,0x10FA  ,  0x10FD  ,0x135A  ,  0x1380  ,0x138F  ,  0x1401  ,0x166C  ,
  0x166F  ,0x167F  ,  0x1681  ,0x169A  ,  0x16A0  ,0x16EA  ,  0x16F1  ,0x1711  ,
  0x1720  ,0x1731  ,  0x1740  ,0x1751  ,  0x1760  ,0x1770  ,  0x1780  ,0x17B3  ,
  0x17DC  ,0x17DC  ,  0x1820  ,0x1842  ,  0x1844  ,0x18A8  ,  0x18AA  ,0x191E  ,
  0x1950  ,0x19C9  ,  0x1A00  ,0x1A16  ,  0x1A20  ,0x1A54  ,  0x1B05  ,0x1B33  ,
  0x1B45  ,0x1B4B  ,  0x1B83  ,0x1BA0  ,  0x1BAE  ,0x1BAF  ,  0x1BBA  ,0x1BE5  ,
  0x1C00  ,0x1C23  ,  0x1C4D  ,0x1C4F  ,  0x1C5A  ,0x1C77  ,  0x1CE9  ,0x1CEC  ,
  0x1CEE  ,0x1CF1  ,  0x1CF5  ,0x1CF6  ,  0x2135  ,0x2138  ,  0x2D30  ,0x2D67  ,
  0x2D80  ,0x2DDE  ,  0x3006  ,0x3006  ,  0x303C  ,0x303C  ,  0x3041  ,0x3096  ,
  0x309F  ,0x309F  ,  0x30A1  ,0x30FA  ,  0x30FF  ,0x318E  ,  0x31A0  ,0x31BA  ,
  0x31F0  ,0x31FF  ,  0x3400  ,0x4DB5  ,  0x4E00  ,0xA014  ,  0xA016  ,0xA48C  ,
  0xA4D0  ,0xA4F7  ,  0xA500  ,0xA60B  ,  0xA610  ,0xA61F  ,  0xA62A  ,0xA62B  ,
  0xA66E  ,0xA66E  ,  0xA6A0  ,0xA6E5  ,  0xA78F  ,0xA78F  ,  0xA7F7  ,0xA7F7  ,
  0xA7FB  ,0xA801  ,  0xA803  ,0xA805  ,  0xA807  ,0xA80A  ,  0xA80C  ,0xA822  ,
  0xA840  ,0xA873  ,  0xA882  ,0xA8B3  ,  0xA8F2  ,0xA8F7  ,  0xA8FB  ,0xA8FB  ,
  0xA8FD  ,0xA8FD  ,  0xA90A  ,0xA925  ,  0xA930  ,0xA946  ,  0xA960  ,0xA97C  ,
  0xA984  ,0xA9B2  ,  0xA9E0  ,0xA9E4  ,  0xA9E7  ,0xA9EF  ,  0xA9FA  ,0xAA28  ,
  0xAA40  ,0xAA42  ,  0xAA44  ,0xAA4B  ,  0xAA60  ,0xAA6F  ,  0xAA71  ,0xAA76  ,
  0xAA7A  ,0xAA7A  ,  0xAA7E  ,0xAAAF  ,  0xAAB1  ,0xAAB1  ,  0xAAB5  ,0xAAB6  ,
  0xAAB9  ,0xAABD  ,  0xAAC0  ,0xAAC0  ,  0xAAC2  ,0xAADC  ,  0xAAE0  ,0xAAEA  ,
  0xAAF2  ,0xAAF2  ,  0xAB01  ,0xAB2E  ,  0xABC0  ,0xABE2  ,  0xAC00  ,0xD7FB  ,
  0xF900  ,0xFAD9  ,  0xFB1D  ,0xFB1D  ,  0xFB1F  ,0xFB28  ,  0xFB2A  ,0xFBB1  ,
  0xFBD3  ,0xFD3D  ,  0xFD50  ,0xFDFB  ,  0xFE70  ,0xFEFC  ,  0xFF66  ,0xFF6F  ,
  0xFF71  ,0xFF9D  ,  0xFFA0  ,0xFFDC  ,  0x10000 ,0x100FA ,  0x10280 ,0x102D0 ,
  0x10300 ,0x1031F ,  0x10330 ,0x10340 ,  0x10342 ,0x10349 ,  0x10350 ,0x10375 ,
  0x10380 ,0x1039D ,  0x103A0 ,0x103CF ,  0x10450 ,0x1049D ,  0x10500 ,0x10563 ,
  0x10600 ,0x10855 ,  0x10860 ,0x10876 ,  0x10880 ,0x1089E ,  0x108E0 ,0x108F5 ,
  0x10900 ,0x10915 ,  0x10920 ,0x10939 ,  0x10980 ,0x109B7 ,  0x109BE ,0x109BF ,
  0x10A00 ,0x10A00 ,  0x10A10 ,0x10A33 ,  0x10A60 ,0x10A7C ,  0x10A80 ,0x10A9C ,
  0x10AC0 ,0x10AC7 ,  0x10AC9 ,0x10AE4 ,  0x10B00 ,0x10B35 ,  0x10B40 ,0x10B55 ,
  0x10B60 ,0x10B72 ,  0x10B80 ,0x10B91 ,  0x10C00 ,0x10C48 ,  0x11003 ,0x11037 ,
  0x11083 ,0x110AF ,  0x110D0 ,0x110E8 ,  0x11103 ,0x11126 ,  0x11150 ,0x11172 ,
  0x11176 ,0x11176 ,  0x11183 ,0x111B2 ,  0x111C1 ,0x111C4 ,  0x111DA ,0x111DA ,
  0x111DC ,0x111DC ,  0x11200 ,0x1122B ,  0x11280 ,0x112A8 ,  0x112B0 ,0x112DE ,
  0x11305 ,0x11339 ,  0x1133D ,0x1133D ,  0x11350 ,0x11350 ,  0x1135D ,0x11361 ,
  0x11480 ,0x114AF ,  0x114C4 ,0x114C5 ,  0x114C7 ,0x114C7 ,  0x11580 ,0x115AE ,
  0x115D8 ,0x115DB ,  0x11600 ,0x1162F ,  0x11644 ,0x11644 ,  0x11680 ,0x116AA ,
  0x11700 ,0x11719 ,  0x118FF ,0x12399 ,  0x12480 ,0x16A5E ,  0x16AD0 ,0x16AED ,
  0x16B00 ,0x16B2F ,  0x16B63 ,0x16F50 ,  0x1B000 ,0x1BC99 ,  0x1E800 ,0x1E8C4 ,
  0x1EE00 ,0x1EEBB ,  0x20000 ,0x2FA1D ,  0x1C5   ,0x1C5   ,  0x1C8   ,0x1C8   ,
  0x1CB   ,0x1CB   ,  0x1F2   ,0x1F2   ,  0x1F88  ,0x1F8F  ,  0x1F98  ,0x1F9F  ,
  0x1FA8  ,0x1FAF  ,  0x1FBC  ,0x1FBC  ,  0x1FCC  ,0x1FCC  ,  0x1FFC  ,0x1FFC  ,
  0x41    ,0x5A    ,  0xC0    ,0xD6    ,  0xD8    ,0xDE    ,  0x100   ,0x100   ,
  0x102   ,0x102   ,  0x104   ,0x104   ,  0x106   ,0x106   ,  0x108   ,0x108   ,
  0x10A   ,0x10A   ,  0x10C   ,0x10C   ,  0x10E   ,0x10E   ,  0x110   ,0x110   ,
  0x112   ,0x112   ,  0x114   ,0x114   ,  0x116   ,0x116   ,  0x118   ,0x118   ,
  0x11A   ,0x11A   ,  0x11C   ,0x11C   ,  0x11E   ,0x11E   ,  0x120   ,0x120   ,
  0x122   ,0x122   ,  0x124   ,0x124   ,  0x126   ,0x126   ,  0x128   ,0x128   ,
  0x12A   ,0x12A   ,  0x12C   ,0x12C   ,  0x12E   ,0x12E   ,  0x130   ,0x130   ,
  0x132   ,0x132   ,  0x134   ,0x134   ,  0x136   ,0x136   ,  0x139   ,0x139   ,
  0x13B   ,0x13B   ,  0x13D   ,0x13D   ,  0x13F   ,0x13F   ,  0x141   ,0x141   ,
  0x143   ,0x143   ,  0x145   ,0x145   ,  0x147   ,0x147   ,  0x14A   ,0x14A   ,
  0x14C   ,0x14C   ,  0x14E   ,0x14E   ,  0x150   ,0x150   ,  0x152   ,0x152   ,
  0x154   ,0x154   ,  0x156   ,0x156   ,  0x158   ,0x158   ,  0x15A   ,0x15A   ,
  0x15C   ,0x15C   ,  0x15E   ,0x15E   ,  0x160   ,0x160   ,  0x162   ,0x162   ,
  0x164   ,0x164   ,  0x166   ,0x166   ,  0x168   ,0x168   ,  0x16A   ,0x16A   ,
  0x16C   ,0x16C   ,  0x16E   ,0x16E   ,  0x170   ,0x170   ,  0x172   ,0x172   ,
  0x174   ,0x174   ,  0x176   ,0x176   ,  0x178   ,0x179   ,  0x17B   ,0x17B   ,
  0x17D   ,0x17D   ,  0x181   ,0x182   ,  0x184   ,0x184   ,  0x186   ,0x187   ,
  0x189   ,0x18B   ,  0x18E   ,0x191   ,  0x193   ,0x194   ,  0x196   ,0x198   ,
  0x19C   ,0x19D   ,  0x19F   ,0x1A0   ,  0x1A2   ,0x1A2   ,  0x1A4   ,0x1A4   ,
  0x1A6   ,0x1A7   ,  0x1A9   ,0x1A9   ,  0x1AC   ,0x1AC   ,  0x1AE   ,0x1AF   ,
  0x1B1   ,0x1B3   ,  0x1B5   ,0x1B5   ,  0x1B7   ,0x1B8   ,  0x1BC   ,0x1BC   ,
  0x1C4   ,0x1C4   ,  0x1C7   ,0x1C7   ,  0x1CA   ,0x1CA   ,  0x1CD   ,0x1CD   ,
  0x1CF   ,0x1CF   ,  0x1D1   ,0x1D1   ,  0x1D3   ,0x1D3   ,  0x1D5   ,0x1D5   ,
  0x1D7   ,0x1D7   ,  0x1D9   ,0x1D9   ,  0x1DB   ,0x1DB   ,  0x1DE   ,0x1DE   ,
  0x1E0   ,0x1E0   ,  0x1E2   ,0x1E2   ,  0x1E4   ,0x1E4   ,  0x1E6   ,0x1E6   ,
  0x1E8   ,0x1E8   ,  0x1EA   ,0x1EA   ,  0x1EC   ,0x1EC   ,  0x1EE   ,0x1EE   ,
  0x1F1   ,0x1F1   ,  0x1F4   ,0x1F4   ,  0x1F6   ,0x1F8   ,  0x1FA   ,0x1FA   ,
  0x1FC   ,0x1FC   ,  0x1FE   ,0x1FE   ,  0x200   ,0x200   ,  0x202   ,0x202   ,
  0x204   ,0x204   ,  0x206   ,0x206   ,  0x208   ,0x208   ,  0x20A   ,0x20A   ,
  0x20C   ,0x20C   ,  0x20E   ,0x20E   ,  0x210   ,0x210   ,  0x212   ,0x212   ,
  0x214   ,0x214   ,  0x216   ,0x216   ,  0x218   ,0x218   ,  0x21A   ,0x21A   ,
  0x21C   ,0x21C   ,  0x21E   ,0x21E   ,  0x220   ,0x220   ,  0x222   ,0x222   ,
  0x224   ,0x224   ,  0x226   ,0x226   ,  0x228   ,0x228   ,  0x22A   ,0x22A   ,
  0x22C   ,0x22C   ,  0x22E   ,0x22E   ,  0x230   ,0x230   ,  0x232   ,0x232   ,
  0x23A   ,0x23B   ,  0x23D   ,0x23E   ,  0x241   ,0x241   ,  0x243   ,0x246   ,
  0x248   ,0x248   ,  0x24A   ,0x24A   ,  0x24C   ,0x24C   ,  0x24E   ,0x24E   ,
  0x370   ,0x370   ,  0x372   ,0x372   ,  0x376   ,0x376   ,  0x37F   ,0x37F   ,
  0x386   ,0x386   ,  0x388   ,0x38F   ,  0x391   ,0x3AB   ,  0x3CF   ,0x3CF   ,
  0x3D2   ,0x3D4   ,  0x3D8   ,0x3D8   ,  0x3DA   ,0x3DA   ,  0x3DC   ,0x3DC   ,
  0x3DE   ,0x3DE   ,  0x3E0   ,0x3E0   ,  0x3E2   ,0x3E2   ,  0x3E4   ,0x3E4   ,
  0x3E6   ,0x3E6   ,  0x3E8   ,0x3E8   ,  0x3EA   ,0x3EA   ,  0x3EC   ,0x3EC   ,
  0x3EE   ,0x3EE   ,  0x3F4   ,0x3F4   ,  0x3F7   ,0x3F7   ,  0x3F9   ,0x3FA   ,
  0x3FD   ,0x42F   ,  0x460   ,0x460   ,  0x462   ,0x462   ,  0x464   ,0x464   ,
  0x466   ,0x466   ,  0x468   ,0x468   ,  0x46A   ,0x46A   ,  0x46C   ,0x46C   ,
  0x46E   ,0x46E   ,  0x470   ,0x470   ,  0x472   ,0x472   ,  0x474   ,0x474   ,
  0x476   ,0x476   ,  0x478   ,0x478   ,  0x47A   ,0x47A   ,  0x47C   ,0x47C   ,
  0x47E   ,0x47E   ,  0x480   ,0x480   ,  0x48A   ,0x48A   ,  0x48C   ,0x48C   ,
  0x48E   ,0x48E   ,  0x490   ,0x490   ,  0x492   ,0x492   ,  0x494   ,0x494   ,
  0x496   ,0x496   ,  0x498   ,0x498   ,  0x49A   ,0x49A   ,  0x49C   ,0x49C   ,
  0x49E   ,0x49E   ,  0x4A0   ,0x4A0   ,  0x4A2   ,0x4A2   ,  0x4A4   ,0x4A4   ,
  0x4A6   ,0x4A6   ,  0x4A8   ,0x4A8   ,  0x4AA   ,0x4AA   ,  0x4AC   ,0x4AC   ,
  0x4AE   ,0x4AE   ,  0x4B0   ,0x4B0   ,  0x4B2   ,0x4B2   ,  0x4B4   ,0x4B4   ,
  0x4B6   ,0x4B6   ,  0x4B8   ,0x4B8   ,  0x4BA   ,0x4BA   ,  0x4BC   ,0x4BC   ,
  0x4BE   ,0x4BE   ,  0x4C0   ,0x4C1   ,  0x4C3   ,0x4C3   ,  0x4C5   ,0x4C5   ,
  0x4C7   ,0x4C7   ,  0x4C9   ,0x4C9   ,  0x4CB   ,0x4CB   ,  0x4CD   ,0x4CD   ,
  0x4D0   ,0x4D0   ,  0x4D2   ,0x4D2   ,  0x4D4   ,0x4D4   ,  0x4D6   ,0x4D6   ,
  0x4D8   ,0x4D8   ,  0x4DA   ,0x4DA   ,  0x4DC   ,0x4DC   ,  0x4DE   ,0x4DE   ,
  0x4E0   ,0x4E0   ,  0x4E2   ,0x4E2   ,  0x4E4   ,0x4E4   ,  0x4E6   ,0x4E6   ,
  0x4E8   ,0x4E8   ,  0x4EA   ,0x4EA   ,  0x4EC   ,0x4EC   ,  0x4EE   ,0x4EE   ,
  0x4F0   ,0x4F0   ,  0x4F2   ,0x4F2   ,  0x4F4   ,0x4F4   ,  0x4F6   ,0x4F6   ,
  0x4F8   ,0x4F8   ,  0x4FA   ,0x4FA   ,  0x4FC   ,0x4FC   ,  0x4FE   ,0x4FE   ,
  0x500   ,0x500   ,  0x502   ,0x502   ,  0x504   ,0x504   ,  0x506   ,0x506   ,
  0x508   ,0x508   ,  0x50A   ,0x50A   ,  0x50C   ,0x50C   ,  0x50E   ,0x50E   ,
  0x510   ,0x510   ,  0x512   ,0x512   ,  0x514   ,0x514   ,  0x516   ,0x516   ,
  0x518   ,0x518   ,  0x51A   ,0x51A   ,  0x51C   ,0x51C   ,  0x51E   ,0x51E   ,
  0x520   ,0x520   ,  0x522   ,0x522   ,  0x524   ,0x524   ,  0x526   ,0x526   ,
  0x528   ,0x528   ,  0x52A   ,0x52A   ,  0x52C   ,0x52C   ,  0x52E   ,0x52E   ,
  0x531   ,0x556   ,  0x10A0  ,0x10CD  ,  0x13A0  ,0x13F5  ,  0x1E00  ,0x1E00  ,
  0x1E02  ,0x1E02  ,  0x1E04  ,0x1E04  ,  0x1E06  ,0x1E06  ,  0x1E08  ,0x1E08  ,
  0x1E0A  ,0x1E0A  ,  0x1E0C  ,0x1E0C  ,  0x1E0E  ,0x1E0E  ,  0x1E10  ,0x1E10  ,
  0x1E12  ,0x1E12  ,  0x1E14  ,0x1E14  ,  0x1E16  ,0x1E16  ,  0x1E18  ,0x1E18  ,
  0x1E1A  ,0x1E1A  ,  0x1E1C  ,0x1E1C  ,  0x1E1E  ,0x1E1E  ,  0x1E20  ,0x1E20  ,
  0x1E22  ,0x1E22  ,  0x1E24  ,0x1E24  ,  0x1E26  ,0x1E26  ,  0x1E28  ,0x1E28  ,
  0x1E2A  ,0x1E2A  ,  0x1E2C  ,0x1E2C  ,  0x1E2E  ,0x1E2E  ,  0x1E30  ,0x1E30  ,
  0x1E32  ,0x1E32  ,  0x1E34  ,0x1E34  ,  0x1E36  ,0x1E36  ,  0x1E38  ,0x1E38  ,
  0x1E3A  ,0x1E3A  ,  0x1E3C  ,0x1E3C  ,  0x1E3E  ,0x1E3E  ,  0x1E40  ,0x1E40  ,
  0x1E42  ,0x1E42  ,  0x1E44  ,0x1E44  ,  0x1E46  ,0x1E46  ,  0x1E48  ,0x1E48  ,
  0x1E4A  ,0x1E4A  ,  0x1E4C  ,0x1E4C  ,  0x1E4E  ,0x1E4E  ,  0x1E50  ,0x1E50  ,
  0x1E52  ,0x1E52  ,  0x1E54  ,0x1E54  ,  0x1E56  ,0x1E56  ,  0x1E58  ,0x1E58  ,
  0x1E5A  ,0x1E5A  ,  0x1E5C  ,0x1E5C  ,  0x1E5E  ,0x1E5E  ,  0x1E60  ,0x1E60  ,
  0x1E62  ,0x1E62  ,  0x1E64  ,0x1E64  ,  0x1E66  ,0x1E66  ,  0x1E68  ,0x1E68  ,
  0x1E6A  ,0x1E6A  ,  0x1E6C  ,0x1E6C  ,  0x1E6E  ,0x1E6E  ,  0x1E70  ,0x1E70  ,
  0x1E72  ,0x1E72  ,  0x1E74  ,0x1E74  ,  0x1E76  ,0x1E76  ,  0x1E78  ,0x1E78  ,
  0x1E7A  ,0x1E7A  ,  0x1E7C  ,0x1E7C  ,  0x1E7E  ,0x1E7E  ,  0x1E80  ,0x1E80  ,
  0x1E82  ,0x1E82  ,  0x1E84  ,0x1E84  ,  0x1E86  ,0x1E86  ,  0x1E88  ,0x1E88  ,
  0x1E8A  ,0x1E8A  ,  0x1E8C  ,0x1E8C  ,  0x1E8E  ,0x1E8E  ,  0x1E90  ,0x1E90  ,
  0x1E92  ,0x1E92  ,  0x1E94  ,0x1E94  ,  0x1E9E  ,0x1E9E  ,  0x1EA0  ,0x1EA0  ,
  0x1EA2  ,0x1EA2  ,  0x1EA4  ,0x1EA4  ,  0x1EA6  ,0x1EA6  ,  0x1EA8  ,0x1EA8  ,
  0x1EAA  ,0x1EAA  ,  0x1EAC  ,0x1EAC  ,  0x1EAE  ,0x1EAE  ,  0x1EB0  ,0x1EB0  ,
  0x1EB2  ,0x1EB2  ,  0x1EB4  ,0x1EB4  ,  0x1EB6  ,0x1EB6  ,  0x1EB8  ,0x1EB8  ,
  0x1EBA  ,0x1EBA  ,  0x1EBC  ,0x1EBC  ,  0x1EBE  ,0x1EBE  ,  0x1EC0  ,0x1EC0  ,
  0x1EC2  ,0x1EC2  ,  0x1EC4  ,0x1EC4  ,  0x1EC6  ,0x1EC6  ,  0x1EC8  ,0x1EC8  ,
  0x1ECA  ,0x1ECA  ,  0x1ECC  ,0x1ECC  ,  0x1ECE  ,0x1ECE  ,  0x1ED0  ,0x1ED0  ,
  0x1ED2  ,0x1ED2  ,  0x1ED4  ,0x1ED4  ,  0x1ED6  ,0x1ED6  ,  0x1ED8  ,0x1ED8  ,
  0x1EDA  ,0x1EDA  ,  0x1EDC  ,0x1EDC  ,  0x1EDE  ,0x1EDE  ,  0x1EE0  ,0x1EE0  ,
  0x1EE2  ,0x1EE2  ,  0x1EE4  ,0x1EE4  ,  0x1EE6  ,0x1EE6  ,  0x1EE8  ,0x1EE8  ,
  0x1EEA  ,0x1EEA  ,  0x1EEC  ,0x1EEC  ,  0x1EEE  ,0x1EEE  ,  0x1EF0  ,0x1EF0  ,
  0x1EF2  ,0x1EF2  ,  0x1EF4  ,0x1EF4  ,  0x1EF6  ,0x1EF6  ,  0x1EF8  ,0x1EF8  ,
  0x1EFA  ,0x1EFA  ,  0x1EFC  ,0x1EFC  ,  0x1EFE  ,0x1EFE  ,  0x1F08  ,0x1F0F  ,
  0x1F18  ,0x1F1D  ,  0x1F28  ,0x1F2F  ,  0x1F38  ,0x1F3F  ,  0x1F48  ,0x1F4D  ,
  0x1F59  ,0x1F5F  ,  0x1F68  ,0x1F6F  ,  0x1FB8  ,0x1FBB  ,  0x1FC8  ,0x1FCB  ,
  0x1FD8  ,0x1FDB  ,  0x1FE8  ,0x1FEC  ,  0x1FF8  ,0x1FFB  ,  0x2102  ,0x2102  ,
  0x2107  ,0x2107  ,  0x210B  ,0x210D  ,  0x2110  ,0x2112  ,  0x2115  ,0x2115  ,
  0x2119  ,0x211D  ,  0x2124  ,0x2124  ,  0x2126  ,0x2126  ,  0x2128  ,0x2128  ,
  0x212A  ,0x212D  ,  0x2130  ,0x2133  ,  0x213E  ,0x213F  ,  0x2145  ,0x2145  ,
  0x2183  ,0x2183  ,  0x2C00  ,0x2C2E  ,  0x2C60  ,0x2C60  ,  0x2C62  ,0x2C64  ,
  0x2C67  ,0x2C67  ,  0x2C69  ,0x2C69  ,  0x2C6B  ,0x2C6B  ,  0x2C6D  ,0x2C70  ,
  0x2C72  ,0x2C72  ,  0x2C75  ,0x2C75  ,  0x2C7E  ,0x2C80  ,  0x2C82  ,0x2C82  ,
  0x2C84  ,0x2C84  ,  0x2C86  ,0x2C86  ,  0x2C88  ,0x2C88  ,  0x2C8A  ,0x2C8A  ,
  0x2C8C  ,0x2C8C  ,  0x2C8E  ,0x2C8E  ,  0x2C90  ,0x2C90  ,  0x2C92  ,0x2C92  ,
  0x2C94  ,0x2C94  ,  0x2C96  ,0x2C96  ,  0x2C98  ,0x2C98  ,  0x2C9A  ,0x2C9A  ,
  0x2C9C  ,0x2C9C  ,  0x2C9E  ,0x2C9E  ,  0x2CA0  ,0x2CA0  ,  0x2CA2  ,0x2CA2  ,
  0x2CA4  ,0x2CA4  ,  0x2CA6  ,0x2CA6  ,  0x2CA8  ,0x2CA8  ,  0x2CAA  ,0x2CAA  ,
  0x2CAC  ,0x2CAC  ,  0x2CAE  ,0x2CAE  ,  0x2CB0  ,0x2CB0  ,  0x2CB2  ,0x2CB2  ,
  0x2CB4  ,0x2CB4  ,  0x2CB6  ,0x2CB6  ,  0x2CB8  ,0x2CB8  ,  0x2CBA  ,0x2CBA  ,
  0x2CBC  ,0x2CBC  ,  0x2CBE  ,0x2CBE  ,  0x2CC0  ,0x2CC0  ,  0x2CC2  ,0x2CC2  ,
  0x2CC4  ,0x2CC4  ,  0x2CC6  ,0x2CC6  ,  0x2CC8  ,0x2CC8  ,  0x2CCA  ,0x2CCA  ,
  0x2CCC  ,0x2CCC  ,  0x2CCE  ,0x2CCE  ,  0x2CD0  ,0x2CD0  ,  0x2CD2  ,0x2CD2  ,
  0x2CD4  ,0x2CD4  ,  0x2CD6  ,0x2CD6  ,  0x2CD8  ,0x2CD8  ,  0x2CDA  ,0x2CDA  ,
  0x2CDC  ,0x2CDC  ,  0x2CDE  ,0x2CDE  ,  0x2CE0  ,0x2CE0  ,  0x2CE2  ,0x2CE2  ,
  0x2CEB  ,0x2CEB  ,  0x2CED  ,0x2CED  ,  0x2CF2  ,0x2CF2  ,  0xA640  ,0xA640  ,
  0xA642  ,0xA642  ,  0xA644  ,0xA644  ,  0xA646  ,0xA646  ,  0xA648  ,0xA648  ,
  0xA64A  ,0xA64A  ,  0xA64C  ,0xA64C  ,  0xA64E  ,0xA64E  ,  0xA650  ,0xA650  ,
  0xA652  ,0xA652  ,  0xA654  ,0xA654  ,  0xA656  ,0xA656  ,  0xA658  ,0xA658  ,
  0xA65A  ,0xA65A  ,  0xA65C  ,0xA65C  ,  0xA65E  ,0xA65E  ,  0xA660  ,0xA660  ,
  0xA662  ,0xA662  ,  0xA664  ,0xA664  ,  0xA666  ,0xA666  ,  0xA668  ,0xA668  ,
  0xA66A  ,0xA66A  ,  0xA66C  ,0xA66C  ,  0xA680  ,0xA680  ,  0xA682  ,0xA682  ,
  0xA684  ,0xA684  ,  0xA686  ,0xA686  ,  0xA688  ,0xA688  ,  0xA68A  ,0xA68A  ,
  0xA68C  ,0xA68C  ,  0xA68E  ,0xA68E  ,  0xA690  ,0xA690  ,  0xA692  ,0xA692  ,
  0xA694  ,0xA694  ,  0xA696  ,0xA696  ,  0xA698  ,0xA698  ,  0xA69A  ,0xA69A  ,
  0xA722  ,0xA722  ,  0xA724  ,0xA724  ,  0xA726  ,0xA726  ,  0xA728  ,0xA728  ,
  0xA72A  ,0xA72A  ,  0xA72C  ,0xA72C  ,  0xA72E  ,0xA72E  ,  0xA732  ,0xA732  ,
  0xA734  ,0xA734  ,  0xA736  ,0xA736  ,  0xA738  ,0xA738  ,  0xA73A  ,0xA73A  ,
  0xA73C  ,0xA73C  ,  0xA73E  ,0xA73E  ,  0xA740  ,0xA740  ,  0xA742  ,0xA742  ,
  0xA744  ,0xA744  ,  0xA746  ,0xA746  ,  0xA748  ,0xA748  ,  0xA74A  ,0xA74A  ,
  0xA74C  ,0xA74C  ,  0xA74E  ,0xA74E  ,  0xA750  ,0xA750  ,  0xA752  ,0xA752  ,
  0xA754  ,0xA754  ,  0xA756  ,0xA756  ,  0xA758  ,0xA758  ,  0xA75A  ,0xA75A  ,
  0xA75C  ,0xA75C  ,  0xA75E  ,0xA75E  ,  0xA760  ,0xA760  ,  0xA762  ,0xA762  ,
  0xA764  ,0xA764  ,  0xA766  ,0xA766  ,  0xA768  ,0xA768  ,  0xA76A  ,0xA76A  ,
  0xA76C  ,0xA76C  ,  0xA76E  ,0xA76E  ,  0xA779  ,0xA779  ,  0xA77B  ,0xA77B  ,
  0xA77D  ,0xA77E  ,  0xA780  ,0xA780  ,  0xA782  ,0xA782  ,  0xA784  ,0xA784  ,
  0xA786  ,0xA786  ,  0xA78B  ,0xA78B  ,  0xA78D  ,0xA78D  ,  0xA790  ,0xA790  ,
  0xA792  ,0xA792  ,  0xA796  ,0xA796  ,  0xA798  ,0xA798  ,  0xA79A  ,0xA79A  ,
  0xA79C  ,0xA79C  ,  0xA79E  ,0xA79E  ,  0xA7A0  ,0xA7A0  ,  0xA7A2  ,0xA7A2  ,
  0xA7A4  ,0xA7A4  ,  0xA7A6  ,0xA7A6  ,  0xA7A8  ,0xA7A8  ,  0xA7AA  ,0xA7B4  ,
  0xA7B6  ,0xA7B6  ,  0xFF21  ,0xFF3A  ,  0x10400 ,0x10427 ,  0x10C80 ,0x10CB2 ,
  0x118A0 ,0x118BF ,  0x1D400 ,0x1D419 ,  0x1D434 ,0x1D44D ,  0x1D468 ,0x1D481 ,
  0x1D49C ,0x1D4B5 ,  0x1D4D0 ,0x1D4E9 ,  0x1D504 ,0x1D51C ,  0x1D538 ,0x1D550 ,
  0x1D56C ,0x1D585 ,  0x1D5A0 ,0x1D5B9 ,  0x1D5D4 ,0x1D5ED ,  0x1D608 ,0x1D621 ,
  0x1D63C ,0x1D655 ,  0x1D670 ,0x1D689 ,  0x1D6A8 ,0x1D6C0 ,  0x1D6E2 ,0x1D6FA ,
  0x1D71C ,0x1D734 ,  0x1D756 ,0x1D76E ,  0x1D790 ,0x1D7A8 ,  0x1D7CA ,0x1D7CA ,
  0,0
};
static int lxcls_d[] = {
  0x30    ,0x39    ,  0x660   ,0x669   ,  0x6F0   ,0x6F9   ,
  0x7C0   ,0x7C9   ,  0x966   ,0x96F   ,  0x9E6   ,0x9EF   ,  0xA66   ,0xA6F   ,
  0xAE6   ,0xAEF   ,  0xB66   ,0xB6F   ,  0xBE6   ,0xBEF   ,  0xC66   ,0xC6F   ,
  0xCE6   ,0xCEF   ,  0xD66   ,0xD6F   ,  0xDE6   ,0xDEF   ,  0xE50   ,0xE59   ,
  0xED0   ,0xED9   ,  0xF20   ,0xF29   ,  0x1040  ,0x1049  ,  0x1090  ,0x1099  ,
  0x17E0  ,0x17E9  ,  0x1810  ,0x1819  ,  0x1946  ,0x194F  ,  0x19D0  ,0x19D9  ,
  0x1A80  ,0x1A99  ,  0x1B50  ,0x1B59  ,  0x1BB0  ,0x1BB9  ,  0x1C40  ,0x1C49  ,
  0x1C50  ,0x1C59  ,  0xA620  ,0xA629  ,  0xA8D0  ,0xA8D9  ,  0xA900  ,0xA909  ,
  0xA9D0  ,0xA9D9  ,  0xA9F0  ,0xA9F9  ,  0xAA50  ,0xAA59  ,  0xABF0  ,0xABF9  ,
  0xFF10  ,0xFF19  ,  0x104A0 ,0x104A9 ,  0x11066 ,0x1106F ,  0x110F0 ,0x110F9 ,
  0x11136 ,0x1113F ,  0x111D0 ,0x111D9 ,  0x112F0 ,0x112F9 ,  0x114D0 ,0x114D9 ,
  0x11650 ,0x11659 ,  0x116C0 ,0x116C9 ,  0x11730 ,0x11739 ,  0x118E0 ,0x118E9 ,
  0x16A60 ,0x16A69 ,  0x16B50 ,0x16B59 ,  0x1D7CE ,0x1D7FF ,  0x16EE  ,0x16F0  ,
  0x2160  ,0x2182  ,  0x2185  ,0x2188  ,  0x3007  ,0x3007  ,  0x3021  ,0x3029  ,
  0x3038  ,0x303A  ,  0xA6E6  ,0xA6EF  ,  0x10140 ,0x10174 ,  0x10341 ,0x10341 ,
  0x1034A ,0x1034A ,  0x103D1 ,0x103D5 ,  0x12400 ,0x1246E ,  0xB2    ,0xB3    ,
  0xB9    ,0xB9    ,  0xBC    ,0xBE    ,  0x9F4   ,0x9F9   ,  0xB72   ,0xB77   ,
  0xBF0   ,0xBF2   ,  0xC78   ,0xC7E   ,  0xD70   ,0xD75   ,  0xF2A   ,0xF33   ,
  0x1369  ,0x137C  ,  0x17F0  ,0x17F9  ,  0x19DA  ,0x19DA  ,  0x2070  ,0x2070  ,
  0x2074  ,0x2079  ,  0x2080  ,0x2089  ,  0x2150  ,0x215F  ,  0x2189  ,0x2189  ,
  0x2460  ,0x249B  ,  0x24EA  ,0x24FF  ,  0x2776  ,0x2793  ,  0x2CFD  ,0x2CFD  ,
  0x3192  ,0x3195  ,  0x3220  ,0x3229  ,  0x3248  ,0x324F  ,  0x3251  ,0x325F  ,
  0x3280  ,0x3289  ,  0x32B1  ,0x32BF  ,  0xA830  ,0xA835  ,  0x10107 ,0x10133 ,
  0x10175 ,0x10178 ,  0x1018A ,0x1018B ,  0x102E1 ,0x102FB ,  0x10320 ,0x10323 ,
  0x10858 ,0x1085F ,  0x10879 ,0x1087F ,  0x108A7 ,0x108AF ,  0x108FB ,0x108FF ,
  0x10916 ,0x1091B ,  0x109BC ,0x109BD ,  0x109C0 ,0x109FF ,  0x10A40 ,0x10A47 ,
  0x10A7D ,0x10A7E ,  0x10A9D ,0x10A9F ,  0x10AEB ,0x10AEF ,  0x10B58 ,0x10B5F ,
  0x10B78 ,0x10B7F ,  0x10BA9 ,0x10BAF ,  0x10CFA ,0x10E7E ,  0x11052 ,0x11065 ,
  0x111E1 ,0x111F4 ,  0x1173A ,0x1173B ,  0x118EA ,0x118F2 ,  0x16B5B ,0x16B61 ,
  0x1D360 ,0x1D371 ,  0x1E8C7 ,0x1E8CF ,  0x1F100 ,0x1F10C ,  0,0
};
static int lxcls_s[] = {
  0x9     ,0x9     ,  0x20    ,0x20    ,  0xA0    ,0xA0    ,  0x1680  ,0x1680  ,
  0x2000  ,0x200A  ,  0x202F  ,0x202F  ,  0x205F  ,0x205F  ,  0x3000  ,0x3000  ,
  0,0
};
static int lxcls_e[] = {
  0x21    ,0x21    ,  0x3F    ,0x3F    ,  0x2E    ,0x2E    ,
  0x964   ,0x965   ,  0,0
};
#endif
#define YYNSTATE						 1
#define YYNRULE							1
#define YY_MAX_SHIFT				 0
#define YY_MIN_SHIFTREDUCE	 1
#define YY_MAX_SHIFTREDUCE	 1
#define YY_MIN_REDUCE				2
#define YY_MAX_REDUCE				2
#define YY_ERROR_ACTION			3
#define YY_ACCEPT_ACTION		 4
#define YY_NO_ACTION				 5

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

int lx_lookahead_(lxLexer *lxpLexer,           /* The lexer */
  char** curr_pos,
  char** pp,
  char* buf_end,
  int* plen,
  int* pch,
  char * lookahead_token) {
	char * curpos = *curr_pos;
	return lx_lookahead(lxpLexer, curr_pos, pp, buf_end, plen, pch, lookahead_token);
}

int lx_lookahead_advance(lxLexer *lxpLexer,           /* The lexer */
  char** curr_pos,
  char** pp,
  char* buf_end,
  int* plen,
  int* pch,
  char * lookahead_token) {
	  for (int i = 0; i < strlen(lookahead_token); i++) {
		  if(lx_advance(lxpLexer, curr_pos, pp, buf_end, plen, pch) != 0){return -1;};
	  }
	  return 0;
}


#define LX_LOOKAHEAD(tok) lx_lookahead_(lxpLexer, &curr_pos, &p, buf_end, &curr_len, &ch, tok)
#define LX_LOOKAHEAD_ADVANCE(tok, ls) if (lx_lookahead_advance(lxpLexer, &curr_pos, &p, buf_end, &curr_len, &ch, tok) == -1) { lxpLexer->lxstate=ls;return ch; }
#define LX_RESET lx_tokenctor(lxpLexer, LX_TOK_RESET, 0, 0, 0)
#define LX_SEND(major_token) lx_tokenctor(lxpLexer, LX_TOK_FINALIZE, major_token, 0, 0);Parse(yyp, major_token, lxpLexer->token ParseARG_VNAME)
#define LX_CAPTURE(curr_pos, curr_len) lx_tokenctor(lxpLexer, LX_TOK_CAPTURE, 0, curr_pos, curr_len)
#define LX_SENDERR(err_token) LX_CAPTURE(curr_pos, curr_len);LX_SEND(err_token)
#define LX_REPARSE(s) ParseReadString(s, "<REPARSED>", "DEBUG_REPARSED: ")

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

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N <= YY_MAX_SHIFT             Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   N between YY_MIN_SHIFTREDUCE       Shift to an arbitrary state then
**     and YY_MAX_SHIFTREDUCE           reduce by rule N-YY_MIN_SHIFTREDUCE.
**
**   N between YY_MIN_REDUCE            Reduce by rule N-YY_MIN_REDUCE
**     and YY_MAX_REDUCE

**   N == YY_ERROR_ACTION               A syntax error has occurred.
**
**   N == YY_ACCEPT_ACTION              The parser accepts its input.
**
**   N == YY_NO_ACTION                  No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (2)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */     2,    4,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,    2,
};
#define YY_SHIFT_USE_DFLT (-1)
#define YY_SHIFT_COUNT (0)
#define YY_SHIFT_MIN	 (0)
#define YY_SHIFT_MAX	 (0)
static const signed char yy_shift_ofst[] = {
 /*     0 */     0,
};
#define YY_REDUCE_USE_DFLT (-2)
#define YY_REDUCE_COUNT (0)
#define YY_REDUCE_MIN	 (-1)
#define YY_REDUCE_MAX	 (0)
static const signed char yy_reduce_ofst[] = {
 /*     0 */    -1,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */     3,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
**
** After the "shift" half of a SHIFTREDUCE action, the stateno field
** actually contains the reduce action for the second half of the
** SHIFTREDUCE.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number, or reduce action in SHIFTREDUCE */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
#if LEMONEX
#if ParseLX_INTEGRATEDMODE
  struct lxLexer* lxpLexer;
#endif
#endif /* LEMONEX */
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
	"$",           	"error",       	"rModule",     
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "rModule ::=",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
#if LEMONEX
#if ParseLX_INTEGRATEDMODE
    pParser->lxpLexer = (struct lxLexer*)ParseLexerAlloc(mallocProc);
#endif
#endif /* LEMONEX */
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
#if LEMONEX
#if ParseLX_INTEGRATEDMODE
    ParseLexerFree(pParser->lxpLexer, freeProc);
#endif
#endif /* LEMONEX */
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;

  if( stateno>=YY_MIN_REDUCE ) return stateno; 
  assert( stateno <= YY_SHIFT_COUNT );
  i = yy_shift_ofst[stateno];
  if( i==YY_SHIFT_USE_DFLT ) return yy_default[stateno];
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Print tracing information for a SHIFT action
*/
#ifndef NDEBUG
static void yyTraceShift(yyParser *yypParser, int yyNewState){
  if( yyTraceFILE ){
    int i;
    if( yyNewState<YYNSTATE ){
      fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
      fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
      for(i=1; i<=yypParser->yyidx; i++)
        fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
      fprintf(yyTraceFILE,"\n");
    }else{
      fprintf(yyTraceFILE,"%sShift *\n",yyTracePrompt);
    }
  }
}
#else
# define yyTraceShift(X,Y)
#endif

/*
** Perform a shift action.  Return the number of errors.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
  yyTraceShift(yypParser, yyNewState);
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
	{ 2, 0 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    yysize = yyRuleInfo[yyruleno].nrhs;
    fprintf(yyTraceFILE, "%sReduce [%s] -> state %d.\n", yyTracePrompt,
      yyRuleName[yyruleno], yymsp[-yysize].stateno);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
			default:
			/* (0) rModule ::= */ yytestcase(yyruleno==0);
				break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact <= YY_MAX_SHIFTREDUCE ){
    if( yyact>YY_MAX_SHIFT ) yyact += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
    /* If the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
      yyTraceShift(yypParser, yyact);
    }else{
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YY_ACCEPT_ACTION );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact <= YY_MAX_SHIFTREDUCE ){
      if( yyact > YY_MAX_SHIFT ) yyact += YY_MIN_REDUCE - YY_MIN_SHIFTREDUCE;
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact <= YY_MAX_REDUCE ){
      yy_reduce(yypParser,yyact-YY_MIN_REDUCE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YY_MIN_REDUCE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sReturn\n",yyTracePrompt);
  }
#endif
  return;
}

#if LEMONEX
/* The lexer code */

/* The regex actions */
static void lx_state_action_1(lxLexer *lxpLexer){ printf("OTHER: \"%s\"\n", (lxpLexer->token).buf); }
static void lx_state_action_7(lxLexer *lxpLexer){											//			<--------------------- NESTING ENTER
	CAT[LX_NESTLEVEL] = (lxpLexer->token).buf;
	int len = strlen(CAT[LX_NESTLEVEL]);
	if (CAT[LX_NESTLEVEL][len-1] == ' ' || CAT[LX_NESTLEVEL][len-1] == '\n') {
		CAT[LX_NESTLEVEL][len-1] = 0;
	}
	printf("S: \"%s\"\n", CAT[LX_NESTLEVEL]);
	CAT[LX_NESTLEVEL] += 2;
}
static void lx_state_action_8(lxLexer *lxpLexer){ printf("OTHER: \"%s\"\n", (lxpLexer->token).buf); }
static void lx_state_action_11(lxLexer *lxpLexer){
	printf("CAT[LX_NESTLEVEL-1]_%s: %s\n", "CONTENTS", (lxpLexer->token).buf);
// 	puts("parsing...");
// 	if(LX_REPARSE((lxpLexer->token).buf) != 0) {
// 		printf("Error\n");
// 	} else printf("Success\n");
}
static void lx_state_action_17(lxLexer *lxpLexer){											//			<--------------------- NESTING ENTER
	CAT[LX_NESTLEVEL+1] = (lxpLexer->token).buf;
	int len = strlen(CAT[LX_NESTLEVEL+1]);
	if (CAT[LX_NESTLEVEL+1][len-1] == ' ' || CAT[LX_NESTLEVEL+1][len-1] == '\n') {
		CAT[LX_NESTLEVEL+1][len-1] = 0;
	}
	printf("S: \"%s\"\n", CAT[LX_NESTLEVEL+1]);
	CAT[LX_NESTLEVEL+1] += 2;
}
static void lx_state_action_34(lxLexer *lxpLexer){ printf("E: %s\n", (lxpLexer->token).buf); }
static void lx_state_action_35(lxLexer *lxpLexer){
	printf("CAT[LX_NESTLEVEL-1]_%s: %s\n", "CONTENTS", (lxpLexer->token).buf);
// 	puts("parsing...");
// 	if(LX_REPARSE((lxpLexer->token).buf) != 0) {
// 		printf("Error\n");
// 	} else printf("Success\n");
}
#define LX_ACTION(s) lx_state_action_##s(lxpLexer)

/* The main lexer */
int ParseRead(
  void *yyp,
#if !ParseLX_INTEGRATEDMODE
  void *yyl,
#endif
  char *buf,
  char* buf_end,
  int is_final      /* 1 if this is final buffer in input stream */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  yyParser *yypParser = (yyParser*)(yyp);
#if ParseLX_INTEGRATEDMODE
  lxLexer *lxpLexer = yypParser->lxpLexer;
#else
  lxLexer *lxpLexer = (lxLexer*)(yyl);
#endif
  char* curr_pos;
  int curr_len;
  char* p = buf;
  int ch = 0;

  LX_ADVANCE(lxpLexer->lxstate);
L0:
  printf("L0:%d\n", lxpLexer->lxstate);
  switch(lxpLexer->lxstate) {
    case 1:goto S1;
    case 2:goto S2;
    case 3:goto S3;
    case 4:goto S4;
    case 5:goto S5;
    case 6:goto S6;
    case 7:goto S7;
    case 8:goto S8;
    case 9:goto S9;
    case 10:goto S10;
    case 11:goto S11;
    case 12:goto S12;
    case 13:goto S13;
    case 14:goto S14;
    case 15:goto S15;
    case 16:goto S16;
    case 17:goto S17;
    case 18:goto S18;
    case 19:goto S19;
    case 20:goto S20;
    case 21:goto S21;
    case 22:goto S22;
    case 23:goto S23;
    case 24:goto S24;
    case 25:goto S25;
    case 26:goto S26;
    case 27:goto S27;
    case 28:goto S28;
    case 29:goto S29;
    case 30:goto S30;
    case 31:goto S31;
    case 32:goto S32;
    case 33:goto S33;
    case 34:goto S34;
    case 35:goto S35;
    case 36:goto S36;
    case 37:goto S37;
  }
S1:
  printf("current state: 1: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  REGULAR_TX  
*/    /*1[60(<)-0( )]->2:tx_type:0, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(2);goto S2; /*1*/}

/*
REGULAR_TX  INIT_TX     
*/    /*1[60(<)-0( )]->2:tx_type:2, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){  LX_ACTION(1);/*NO_SEND*/LX_RESET;LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(2);goto S2; /*1*/}

/*
REGULAR_TX  LOOP_TX     
*/    /*1[0( )-0( )]->8:tx_type:4, is_cap:0*/  /*loop --> 8*/

/*
REGULAR_TX  REGULAR_TX  
*/    /*1[0( )-5( )]->10:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(10);goto S10; /*1*/}
  if(is_final == 0) {lxpLexer->lxstate=1;return 0;}
  LX_SEND(0);return 0;
  
S2:
  printf("current state: 2: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*2[60(<)-0( )]->3:tx_type:0, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(3);goto S3; /*1*/}
  if(ch == 0){lxpLexer->lxstate=2;return 0;}
  goto S8; /* by goto_state */
S3:
  printf("current state: 3: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  LOOP_TX     
*/    /*3[0( )-0( )]->4:tx_type:4, is_cap:0*/  /*loop --> 4*/

/*
REGULAR_TX  REGULAR_TX  
*/    /*3[0( )-5( )]->6:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(6);goto S6; /*1*/}
  lxpLexer->lxstate=3;return 0;
  
S4:
  printf("current state: 4: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  REGULAR_TX  
*/    /*4[10( )-0( )]->7:tx_type:0, is_cap:1*/ if(ch == 10 /* decimal is required for full unicode support, printable character is '\n' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(7);goto S7; /*1*/}

/*
REGULAR_TX  REGULAR_TX  
*/    /*4[32( )-0( )]->7:tx_type:0, is_cap:1*/ if(ch == 32 /* decimal is required for full unicode support, printable character is ' ' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(7);goto S7; /*1*/}

/*
REGULAR_TX  REGULAR_TX  
*/    /*4[0( )-5( )]->5:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(5);goto S5; /*1*/}
  lxpLexer->lxstate=4;return 0;
  
S5:
  printf("current state: 5: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S4; /* by goto_state */
S6:
  printf("current state: 6: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S5; /* by goto_state */
S7:
  printf("current state: 7: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  if((ch == 0) && (is_final == 0)) {lxpLexer->lxstate=7;return 0;}
  LX_ACTION(7);/*NO_SEND*/LX_RESET;
  if(ch == 0) {LX_SEND(0);return 0;}
  LX_ENTER_NESTING(1);
  goto S11; /* by retn_state */
S8:
  printf("current state: 8: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  INIT_TX     
*/    /*8[60(<)-0( )]->2:tx_type:2, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){  LX_ACTION(8);/*NO_SEND*/LX_RESET;LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(2);goto S2; /*1*/}

/*
REGULAR_TX  REGULAR_TX  
*/    /*8[0( )-5( )]->9:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(9);goto S9; /*1*/}
  if(is_final == 0) {lxpLexer->lxstate=8;return 0;}
  LX_SEND(0);return 0;
  
S9:
  printf("current state: 9: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S8; /* by goto_state */
S10:
  printf("current state: 10: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S9; /* by goto_state */
S11:
  printf("current state: 11: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  REGULAR_TX  
*/    /*11[60(<)-0( )]->12:tx_type:0, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(12);goto S12; /*1*/}

/*
REGULAR_TX  REGULAR_TX  
*/    /*11[67(C)-0( )]->18:tx_type:0, is_cap:1*/ if(ch == CAT[LX_NESTLEVEL][0]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 11, goto 18*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(18);goto S18; /*1*/}}

/*
REGULAR_TX  INIT_TX     
*/    /*11[60(<)-0( )]->12:tx_type:2, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){  LX_ACTION(11);/*NO_SEND*/LX_RESET;LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(12);goto S12; /*1*/}

/*
REGULAR_TX  INIT_TX     
*/    /*11[67(C)-0( )]->18:tx_type:2, is_cap:1*/ if(ch == CAT[LX_NESTLEVEL][0]){  LX_ACTION(11);/*NO_SEND*/if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 11, goto 18*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(18);goto S18; /*1*/}}

/*
REGULAR_TX  LOOP_TX     
*/    /*11[0( )-0( )]->35:tx_type:4, is_cap:0*/  /*loop --> 35*/

/*
REGULAR_TX  REGULAR_TX  
*/    /*11[0( )-5( )]->37:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(37);goto S37; /*1*/}
  if(is_final == 0) {lxpLexer->lxstate=11;return 0;}
  LX_SEND(0);return 0;
  
S12:
  printf("current state: 12: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*12[60(<)-0( )]->13:tx_type:0, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(13);goto S13; /*1*/}
  if(ch == 0){lxpLexer->lxstate=12;return 0;}
  goto S35; /* by goto_state */
S13:
  printf("current state: 13: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  LOOP_TX     
*/    /*13[0( )-0( )]->14:tx_type:4, is_cap:0*/  /*loop --> 14*/

/*
REGULAR_TX  REGULAR_TX  
*/    /*13[0( )-5( )]->16:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(16);goto S16; /*1*/}
  lxpLexer->lxstate=13;return 0;
  
S14:
  printf("current state: 14: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  REGULAR_TX  
*/    /*14[10( )-0( )]->17:tx_type:0, is_cap:1*/ if(ch == 10 /* decimal is required for full unicode support, printable character is '\n' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(17);goto S17; /*1*/}

/*
REGULAR_TX  REGULAR_TX  
*/    /*14[32( )-0( )]->17:tx_type:0, is_cap:1*/ if(ch == 32 /* decimal is required for full unicode support, printable character is ' ' */ ){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(17);goto S17; /*1*/}

/*
REGULAR_TX  REGULAR_TX  
*/    /*14[0( )-5( )]->15:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(15);goto S15; /*1*/}
  lxpLexer->lxstate=14;return 0;
  
S15:
  printf("current state: 15: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S14; /* by goto_state */
S16:
  printf("current state: 16: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S15; /* by goto_state */
S17:
  printf("current state: 17: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  if((ch == 0) && (is_final == 0)) {lxpLexer->lxstate=17;return 0;}
  LX_ACTION(17);/*NO_SEND*/LX_RESET;
  if(ch == 0) {LX_SEND(0);return 0;}
  LX_RENEW_NESTING;
  goto S11; /* by retn_state */
S18:
  printf("current state: 18: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*18[65(A)-0( )]->19:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][1]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 18, goto 19*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(19);goto S19; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=18;return 0;}
  goto S35; /* by goto_state */
S19:
  printf("current state: 19: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*19[84(T)-0( )]->20:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][2]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 19, goto 20*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(20);goto S20; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=19;return 0;}
  goto S35; /* by goto_state */
S20:
  printf("current state: 20: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*20[91([)-0( )]->21:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][3]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 20, goto 21*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(21);goto S21; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=20;return 0;}
  goto S35; /* by goto_state */
S21:
  printf("current state: 21: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*21[76(L)-0( )]->22:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][4]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 21, goto 22*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(22);goto S22; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=21;return 0;}
  goto S35; /* by goto_state */
S22:
  printf("current state: 22: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*22[88(X)-0( )]->23:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][5]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 22, goto 23*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(23);goto S23; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=22;return 0;}
  goto S35; /* by goto_state */
S23:
  printf("current state: 23: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*23[95(_)-0( )]->24:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][6]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 23, goto 24*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(24);goto S24; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=23;return 0;}
  goto S35; /* by goto_state */
S24:
  printf("current state: 24: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*24[78(N)-0( )]->25:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][7]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 24, goto 25*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(25);goto S25; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=24;return 0;}
  goto S35; /* by goto_state */
S25:
  printf("current state: 25: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*25[69(E)-0( )]->26:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][8]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 25, goto 26*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(26);goto S26; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=25;return 0;}
  goto S35; /* by goto_state */
S26:
  printf("current state: 26: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*26[83(S)-0( )]->27:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][9]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 26, goto 27*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(27);goto S27; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=26;return 0;}
  goto S35; /* by goto_state */
S27:
  printf("current state: 27: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*27[84(T)-0( )]->28:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][10]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 27, goto 28*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(28);goto S28; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=27;return 0;}
  goto S35; /* by goto_state */
S28:
  printf("current state: 28: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*28[76(L)-0( )]->29:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][11]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 28, goto 29*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(29);goto S29; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=28;return 0;}
  goto S35; /* by goto_state */
S29:
  printf("current state: 29: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*29[69(E)-0( )]->30:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][12]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 29, goto 30*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(30);goto S30; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=29;return 0;}
  goto S35; /* by goto_state */
S30:
  printf("current state: 30: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*30[86(V)-0( )]->31:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][13]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 30, goto 31*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(31);goto S31; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=30;return 0;}
  goto S35; /* by goto_state */
S31:
  printf("current state: 31: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*31[69(E)-0( )]->32:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][14]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 31, goto 32*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(32);goto S32; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=31;return 0;}
  goto S35; /* by goto_state */
S32:
  printf("current state: 32: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*32[76(L)-0( )]->33:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][15]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 32, goto 33*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(33);goto S33; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=32;return 0;}
  goto S35; /* by goto_state */
S33:
  printf("current state: 33: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
none        REGULAR_TX  
*/    /*33[93(])-0( )]->34:tx_type:0, is_cap:1*/// if(ch == CAT[LX_NESTLEVEL][16]){if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 33, goto 34*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(34);goto S34; /*1*/}}
  if(ch == 0){lxpLexer->lxstate=33;return 0;}
  goto S35; /* by goto_state */
S34:
  printf("current state: 34: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  if((ch == 0) && (is_final == 0)) {lxpLexer->lxstate=34;return 0;}
  LX_ACTION(34);/*NO_SEND*/LX_RESET;
  if(ch == 0) {LX_SEND(0);return 0;}
  if(LX_LEAVE_NESTING() == 1){goto L0;}
  goto S11; /* by next_state */
S35:
  printf("current state: 35: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');

/*
REGULAR_TX  INIT_TX     
*/    /*35[60(<)-0( )]->12:tx_type:2, is_cap:1*/ if(ch == 60 /* decimal is required for full unicode support, printable character is '<' */ ){  LX_ACTION(35);/*NO_SEND*/LX_RESET;LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(12);goto S12; /*1*/}

/*
REGULAR_TX  INIT_TX     
*/    /*35[67(C)-0( )]->18:tx_type:2, is_cap:1*/ if(ch == CAT[LX_NESTLEVEL][0]){  LX_ACTION(35);/*NO_SEND*/if (LX_LOOKAHEAD(CAT[LX_NESTLEVEL]) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(CAT[LX_NESTLEVEL])); LX_LOOKAHEAD_ADVANCE(CAT[LX_NESTLEVEL], 34); goto S34 /*nest enter goto 34, nest exit goto -1, action goto 34, find mode 35, goto 18*/;}else { LX_CAPTURE(curr_pos, 1);LX_ADVANCE(18);goto S18; /*1*/}}

/*
REGULAR_TX  REGULAR_TX  
*/    /*35[0( )-5( )]->36:tx_type:0, is_cap:1*/  if(ch != 0){LX_CAPTURE(curr_pos, curr_len);LX_ADVANCE(36);goto S36; /*1*/}
  if(is_final == 0) {lxpLexer->lxstate=35;return 0;}
  LX_SEND(0);return 0;
  
S36:
  printf("current state: 36: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S35; /* by goto_state */
S37:
  printf("current state: 37: (row %d, column %d): char hex:0x%X (%c)\n", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');
  goto S36; /* by goto_state */

  return 0;
}

#ifndef NDEBUG
#define LX_DEBUG(t)
#else
#define LX_DEBUG(t) ,t
#endif

/* Helper function to allocate lexer and parser */
int lx_alloc_parser(
  void** pyyp
  ,void** plxp
  ,const char *filename
  ,const char* dbgpfx
){
  *pyyp = ParseAlloc(malloc);
  if(*pyyp == 0) {
    printf("unable to allocate parser\n");
    return 1;
  }

#if ParseLX_INTEGRATEDMODE
  ((struct yyParser*)(*pyyp))->lxpLexer->filename = filename;
#else
  *plxp = ParseLexerAlloc(malloc);
  if(*plxp == 0) {
    printf("unable to allocate lexer\n");
    ParseFree(*pyyp, free);
    return 1;
  }
  ((struct lxLexer*)(*plxp))->filename = filename;
#endif

#if LEMONEX_DBGLVL>=1
  if(dbgpfx != 0) {
    ParseTrace(stdout, (char*)dbgpfx);
  }
#endif
  return 0;
}

/* Helper function to free lexer and parser */
int lx_free_parser(
  void** pyyp
  ,void** plxp
){
#if !ParseLX_INTEGRATEDMODE
  if(*plxp != 0){
    ParseLexerFree(*plxp, free);
    *plxp = 0;
  }
#endif
  if(*pyyp != 0){
    ParseFree(*pyyp, free);
    *pyyp = 0;
  }
  return 0;
}

/* Helper function to read and parse an in-memory string */
int ParseReadString(
  char *buf
  ,const char *filename
  ,const char* dbgpfx
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  void *yyp = 0;
  void *lxp = 0;
  if(lx_alloc_parser(&yyp, &lxp, filename, dbgpfx) != 0){
    return 1;
  }

  char *buf_end = buf;
  while(*buf_end != 0) ++buf_end;
#if ParseLX_INTEGRATEDMODE
  int rc = ParseRead(yyp, buf, buf_end, 1 ParseARG_VNAME);
#else
  int rc = ParseRead(yyp, lxp, buf, buf_end, 1 ParseARG_VNAME);
#endif
  if(rc < 0){
    printf("error in string:%d\n", rc);
    lx_free_parser(&yyp, &lxp);
    return 1;
  }
  lx_free_parser(&yyp, &lxp);
  return 0;
}

/* Helper function to read and parse a file */
int ParseReadFile(
  const char *filename
  ,const char* dbgpfx
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  void *yyp = 0;
  void *lxp = 0;
  if(lx_alloc_parser(&yyp, &lxp, filename, dbgpfx) != 0){
    return 1;
  }

#ifdef _WIN32
  FILE* fp = 0;
  errno_t err = fopen_s(&fp, filename, "rb");
  if (err != 0) {
#else
  FILE* fp = fopen(filename, "rb");
  if (fp == 0) {
#endif
    printf("ParseReadFile:unable to open file:%s\n", filename);
    lx_free_parser(&yyp, &lxp);
    return 1;
  }

  char buf[1024];
  char* pbuf = buf;
  while(!feof(fp)) {
    size_t cnt = fread(pbuf, 1, (size_t)(1024 - (pbuf - buf) - 1), fp);
    char* buf_end = buf+(pbuf-buf)+cnt;
    *buf_end = 0;
    int is_final = 0;
    if((buf_end - buf) < 1023) {is_final = 1;}
#if ParseLX_INTEGRATEDMODE
    int rc = ParseRead(yyp, buf, buf_end, is_final ParseARG_VNAME);
#else
    int rc = ParseRead(yyp, lxp, buf, buf_end, is_final ParseARG_VNAME);
#endif
    if(rc < 0){
      printf("error in file:%d\n", rc);
      fclose(fp);
      lx_free_parser(&yyp, &lxp);
      return 1;
    }
    if(rc > 0){
      char* ebuf = buf_end - rc;
      for(int i = 0; i < rc; ++i) {
        buf[i] = ebuf[i];
      }
    }
    pbuf = buf+rc;
  }

  fclose(fp);
  lx_free_parser(&yyp, &lxp);
  return 0;
}
#endif /* LEMONEX */
#line 41 "example/heredoc.y"

	int main()
	{
// 		LX_REPARSE("<<CAT[LX_NESTLEVEL] HEREDOC<<EOF <<CAT[LX_NESTLEVEL] <<EOF K <<CAT[LX_NESTLEVEL]");
		LX_REPARSE("<<CAT <<EOF EOF CAT");
	}
#line 3614 "./example/heredoc/heredoc.c"
