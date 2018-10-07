/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
%%
/* The include code might contain pch header, so include stdio.h here */
#include <stdio.h>
#include <assert.h> // this uses assert
#include <stdlib.h> // uses callbacks to free and malloc, have them already available
#define LEMONEX 1

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
%%
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

%%

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
%%

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
%%
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
%%
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
%%
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
%%
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
%%
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
%%
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
%%
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
%%
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
%%
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
%%
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
%%

/* The regex actions */
%%
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

%%

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
