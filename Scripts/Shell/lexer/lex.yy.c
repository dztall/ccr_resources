/* compiling lex file

Usage: lex [OPTIONS] [FILE]...
Generates programs that perform pattern-matching on text.

Table Compression:
  -Ca, --align      trade off larger tables for better memory alignment
  -Ce, --ecs        construct equivalence classes
  -Cf               do not compress tables; use -f representation
  -CF               do not compress tables; use -F representation
  -Cm, --meta-ecs   construct meta-equivalence classes
  -Cr, --read       use read() instead of stdio for scanner input
  -f, --full        generate fast, large scanner. Same as -Cfr
  -F, --fast        use alternate table representation. Same as -CFr
  -Cem              default compression (same as --ecs --meta-ecs)

Debugging:
  -d, --debug             enable debug mode in scanner
  -b, --backup            write backing-up information to lex.backup
  -p, --perf-report       write performance report to stderr
  -s, --nodefault         suppress default rule to ECHO unmatched text
  -T, --trace             lex should run in trace mode
  -w, --nowarn            do not generate warnings
  -v, --verbose           write summary of scanner statistics to stdout
      --hex               use hexadecimal numbers instead of octal in debug outputs

Files:
  -o, --outfile=FILE      specify output filename
  -S, --skel=FILE         specify skeleton file
  -t, --stdout            write scanner on stdout instead of lex.yy.c
      --yyclass=NAME      name of C++ class
      --header-file=FILE   create a C header file in addition to the scanner
      --tables-file[=FILE] write tables to FILE

Scanner behavior:
  -7, --7bit              generate 7-bit scanner
  -8, --8bit              generate 8-bit scanner
  -B, --batch             generate batch scanner (opposite of -I)
  -i, --case-insensitive  ignore case in patterns
  -l, --lex-compat        maximal compatibility with original lex
  -X, --posix-compat      maximal compatibility with POSIX lex
  -I, --interactive       generate interactive scanner (opposite of -B)
      --yylineno          track line count in yylineno

Generated code:
  -+,  --c++               generate C++ scanner class
  -Dmacro[=defn]           #define macro defn  (default defn is '1')
  -L,  --noline            suppress #line directives in scanner
  -P,  --prefix=STRING     use STRING as prefix instead of "yy"
  -R,  --reentrant         generate a reentrant C scanner
       --bison-bridge      scanner for bison pure parser.
       --bison-locations   include yylloc support.
       --stdinit           initialize yyin/yyout to stdin/stdout
       --noansi-definitions old-style function definitions
       --noansi-prototypes  empty parameter list in prototypes
       --nounistd          do not include <unistd.h>
       --noFUNCTION        do not generate a particular FUNCTION

Miscellaneous:
  -c                      do-nothing POSIX option
  -n                      do-nothing POSIX option
  -?
  -h, --help              produce this help message
  -V, --version           report lex version

%option %option %option %option %option %option %%
1	<<EOF>>
1	[a-zA-Z]*"\(\)"
2	"\{"
3	"\}"
4	"\$\{"*"\[\]"*"\}"
5	"\$"*[a-zA-Z]*" "
6	"\$"*[a-zA-Z]*"\012"
7	"\$\("*"\)"
8	[a-zA-Z]+
9	"&&"
10	";"
11	"\012"
12	.
13	End Marker
%option yylineno entails a performance penalty ONLY on rules that can match newline characters


********** beginning dump of nfa with start state 93
state #    1	257:     0,    0
state #    2	257:     0,    0
state #    3	 -1:     4,    0
state #    4	257:     3,    5
state #    5	257:     7,    0
state #    6	257:     3,    5
state #    7	257:     8,    0
state #    8	 40:     9,    0
state #    9	 41:    10,    0
state #   10	257:     0,    0  [1]
state #   11	257:     1,    6
state #   12	257:    13,    0
state #   13	123:    14,    0
state #   14	257:     0,    0  [2]
state #   15	257:    11,   12
state #   16	257:    17,    0
state #   17	125:    18,    0
state #   18	257:     0,    0  [3]
state #   19	257:    15,   16
state #   20	257:    21,    0
state #   21	 36:    22,    0
state #   22	123:    23,    0
state #   23	257:    20,   24
state #   24	257:    31,    0
state #   25	257:    20,   24
state #   26	257:    27,    0
state #   27	 91:    28,    0
state #   28	 93:    29,    0
state #   29	257:    26,   30
state #   30	257:    32,    0
state #   31	257:    26,   30
state #   32	257:    33,    0
state #   33	125:    34,    0
state #   34	257:     0,    0  [4]
state #   35	257:    19,   25
state #   36	257:    37,    0
state #   37	 36:    38,    0
state #   38	257:    36,   39
state #   39	257:    44,    0
state #   40	257:    36,   39
state #   41	 -2:    42,    0
state #   42	257:    41,   43
state #   43	257:    45,    0
state #   44	257:    41,   43
state #   45	257:    46,    0
state #   46	 32:    47,    0
state #   47	257:     0,    0  [5]
state #   48	257:    35,   40
state #   49	257:    50,    0
state #   50	 36:    51,    0
state #   51	257:    49,   52
state #   52	257:    57,    0
state #   53	257:    49,   52
state #   54	 -3:    55,    0
state #   55	257:    54,   56
state #   56	257:    58,    0
state #   57	257:    54,   56
state #   58	257:    59,    0
state #   59	 10:    60,    0
state #   60	257:     0,    0  [6]
state #   61	257:    48,   53
state #   62	257:    63,    0
state #   63	 36:    64,    0
state #   64	 40:    65,    0
state #   65	257:    62,   66
state #   66	257:    68,    0
state #   67	257:    62,   66
state #   68	257:    69,    0
state #   69	 41:    70,    0
state #   70	257:     0,    0  [7]
state #   71	257:    61,   67
state #   72	 -4:    73,    0
state #   73	257:    72,    0  [8]
state #   74	257:    71,   72
state #   75	257:    76,    0
state #   76	 38:    77,    0
state #   77	 38:    78,    0
state #   78	257:     0,    0  [9]
state #   79	257:    74,   75
state #   80	257:    81,    0
state #   81	 59:    82,    0
state #   82	257:     0,    0  [10]
state #   83	257:    79,   80
state #   84	257:    85,    0
state #   85	 10:    86,    0
state #   86	257:     0,    0  [11]
state #   87	257:    83,   84
state #   88	 -5:    89,    0
state #   89	257:     0,    0  [12]
state #   90	257:    87,   88
state #   91	 -7:    92,    0
state #   92	257:     0,    0  [13]
state #   93	257:    90,   91
********** end of dump


DFA Dump:

state # 1:
	1	4
	2	5
	3	6
	4	7
	5	8
	6	9
	7	10
	8	11
	9	12
	10	13
	11	4
	12	14
	13	15
state # 2:
	1	4
	2	5
	3	6
	4	7
	5	8
	6	9
	7	10
	8	11
	9	12
	10	13
	11	4
	12	14
	13	15
state # 3:
state # 4:
state # 5:
state # 6:
state # 7:
	2	16
	3	17
	4	18
	6	19
	9	20
	12	21
state # 8:
	5	22
state # 9:
	7	23
state # 10:
state # 11:
state # 12:
	2	16
	3	17
	6	24
	9	25
state # 13:
	11	26
state # 14:
state # 15:
state # 16:
state # 17:
state # 18:
	2	16
	3	17
	4	18
	9	20
state # 19:
	4	27
	7	28
state # 20:
	2	16
	3	17
	9	20
state # 21:
	4	29
	10	30
	13	31
state # 22:
state # 23:
state # 24:
	7	23
state # 25:
	2	16
	3	17
	6	24
	9	25
state # 26:
	10	30
	13	31
state # 27:
	6	19
state # 28:
state # 29:
	12	21
state # 30:
	11	26
state # 31:
lex.l:36: warning, rule cannot be matched
state # 3 accepts: [14]
state # 4 accepts: [12]
state # 5 accepts: [6]
state # 6 accepts: [5]
state # 7 accepts: [12]
state # 8 accepts: [12]
state # 9 accepts: [12]
state # 10 accepts: [7]
state # 11 accepts: [10]
state # 12 accepts: [8]
state # 13 accepts: [12]
state # 14 accepts: [2]
state # 15 accepts: [3]
state # 16 accepts: [6]
state # 17 accepts: [5]
state # 22 accepts: [9]
state # 23 accepts: [1]
state # 25 accepts: [8]
state # 28 accepts: [7]
state # 31 accepts: [4]


Equivalence Classes:

\000 = -1  ' ' = 3     @ = 1     ` = 1  \200 = 1  \240 = 1  \300 = 1  \340 = 1  
\001 = 1     ! = 1     A = 9     a = 9  \201 = 1  \241 = 1  \301 = 1  \341 = 1  
\002 = 1     " = 1     B = 9     b = 9  \202 = 1  \242 = 1  \302 = 1  \342 = 1  
\003 = 1     # = 1     C = 9     c = 9  \203 = 1  \243 = 1  \303 = 1  \343 = 1  
\004 = 1     $ = 4     D = 9     d = 9  \204 = 1  \244 = 1  \304 = 1  \344 = 1  
\005 = 1     % = 1     E = 9     e = 9  \205 = 1  \245 = 1  \305 = 1  \345 = 1  
\006 = 1     & = 5     F = 9     f = 9  \206 = 1  \246 = 1  \306 = 1  \346 = 1  
  \a = 1     ' = 1     G = 9     g = 9  \207 = 1  \247 = 1  \307 = 1  \347 = 1  
  \b = 1     ( = 6     H = 9     h = 9  \210 = 1  \250 = 1  \310 = 1  \350 = 1  
  \t = 1     ) = 7     I = 9     i = 9  \211 = 1  \251 = 1  \311 = 1  \351 = 1  
  \n = 2     * = 1     J = 9     j = 9  \212 = 1  \252 = 1  \312 = 1  \352 = 1  
  \v = 1     + = 1     K = 9     k = 9  \213 = 1  \253 = 1  \313 = 1  \353 = 1  
  \f = 1     , = 1     L = 9     l = 9  \214 = 1  \254 = 1  \314 = 1  \354 = 1  
  \r = 1     - = 1     M = 9     m = 9  \215 = 1  \255 = 1  \315 = 1  \355 = 1  
\016 = 1     . = 1     N = 9     n = 9  \216 = 1  \256 = 1  \316 = 1  \356 = 1  
\017 = 1     / = 1     O = 9     o = 9  \217 = 1  \257 = 1  \317 = 1  \357 = 1  
\020 = 1     0 = 1     P = 9     p = 9  \220 = 1  \260 = 1  \320 = 1  \360 = 1  
\021 = 1     1 = 1     Q = 9     q = 9  \221 = 1  \261 = 1  \321 = 1  \361 = 1  
\022 = 1     2 = 1     R = 9     r = 9  \222 = 1  \262 = 1  \322 = 1  \362 = 1  
\023 = 1     3 = 1     S = 9     s = 9  \223 = 1  \263 = 1  \323 = 1  \363 = 1  
\024 = 1     4 = 1     T = 9     t = 9  \224 = 1  \264 = 1  \324 = 1  \364 = 1  
\025 = 1     5 = 1     U = 9     u = 9  \225 = 1  \265 = 1  \325 = 1  \365 = 1  
\026 = 1     6 = 1     V = 9     v = 9  \226 = 1  \266 = 1  \326 = 1  \366 = 1  
\027 = 1     7 = 1     W = 9     w = 9  \227 = 1  \267 = 1  \327 = 1  \367 = 1  
\030 = 1     8 = 1     X = 9     x = 9  \230 = 1  \270 = 1  \330 = 1  \370 = 1  
\031 = 1     9 = 1     Y = 9     y = 9  \231 = 1  \271 = 1  \331 = 1  \371 = 1  
\032 = 1     : = 1     Z = 9     z = 9  \232 = 1  \272 = 1  \332 = 1  \372 = 1  
\033 = 1     ; = 8     [ = 10    { = 12 \233 = 1  \273 = 1  \333 = 1  \373 = 1  
\034 = 1     < = 1     \ = 1     | = 1  \234 = 1  \274 = 1  \334 = 1  \374 = 1  
\035 = 1     = = 1     ] = 11    } = 13 \235 = 1  \275 = 1  \335 = 1  \375 = 1  
\036 = 1     > = 1     ^ = 1     ~ = 1  \236 = 1  \276 = 1  \336 = 1  \376 = 1  
\037 = 1     ? = 1     _ = 1  \177 = 1  \237 = 1  \277 = 1  \337 = 1  \377 = 1  


Meta-Equivalence Classes:
1 = 1
2 = 1
3 = 1
4 = 1
5 = 1
6 = 1
7 = 1
8 = 1
9 = 1
10 = 1
11 = 1
12 = 1
13 = 1
lex version 2.6.0 usage statistics:
  scanner options: -dpsvBT8 -Cem
  94/2000 NFA states
  31/1000 DFA states (144 words)
  13 rules
  Compressed tables always back-up
  1/40 start conditions
  68 epsilon states, 30 double epsilon states
  7/100 character classes needed 209/500 words of storage, 0 reused
  61 state/nextstate pairs created
  59/2 unique/duplicate transitions
  32/1000 base-def entries created
  67/2000 (peak 53) nxt-chk entries created
  1/2500 (peak 13) template nxt-chk entries created
  13 empty table entries
  8 protos created
  1 templates created, 0 uses
  13/256 equivalence classes created
  1/256 meta-equivalence classes created
  0 (0 saved) hash collisions, 31 DFAs equal
  0 sets of reallocations needed
  467 total table entries needed

total 64
-rw-rw-rw- 1 2001 2000  2144 May 16 08:43 lex.l
-rw-r--r-- 1 2001 2000 54433 May 16 08:43 lex.yy.c

     1	a && b;
     2	a=8;
--(end of buffer or a NUL)
--accepting rule at line 30 ("a ")
--accepting rule at line 34 ("&&")
--accepting rule at line 30 (" ")
--accepting rule at line 33 ("b")
--accepting rule at line 35 (";")
--accepting rule at line 31 ("
")
--accepting rule at line 33 ("a")
--accepting rule at line 37 ("=")
--accepting rule at line 37 ("8")
--accepting rule at line 35 (";")
--(end of buffer or a NUL)
--accepting rule at line 31 ("
")
--(end of buffer or a NUL)
--EOF (start condition 0)
--(end of buffer or a NUL)
--EOF (start condition 0)
token line = 1, variable: "a ", token = 9 (a )
token line = 1, AND: "&&", token = 3 (&&)
token line = 1, variable: " ", token = 9 ( )
token line = 1, identifier: "b", token = 1 (b)
token line = 1, command: ";", token = 0 (;)
token line = 2, variable: "
", token = 9 (
)
token line = 2, identifier: "a", token = 1 (a)
token line = 2, command: ";", token = 0 (;)
token line = 3, variable: "
", token = 9 (
)
token line = 3, token = -1 ()
lex file compiled */

#line 3 "lex.yy.c"

#define  YY_INT_ALIGNED short int

/* A lexical scanner generated by flex */

/* %not-for-header */

/* %if-c-only */
/* %if-not-reentrant */

/* %endif */
/* %endif */
/* %ok-for-header */

#define FLEX_SCANNER
#define YY_FLEX_MAJOR_VERSION 2
#define YY_FLEX_MINOR_VERSION 6
#define YY_FLEX_SUBMINOR_VERSION 0
#if YY_FLEX_SUBMINOR_VERSION > 0
#define FLEX_BETA
#endif

/* %if-c++-only */
/* %endif */

/* %if-c-only */
    
/* %endif */

/* %if-c-only */

/* %endif */

/* First, we deal with  platform-specific or compiler-specific issues. */

/* begin standard C headers. */
/* %if-c-only */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
/* %endif */

/* %if-tables-serialization */
/* %endif */
/* end standard C headers. */

/* %if-c-or-c++ */
/* flex integer type definitions */

#ifndef FLEXINT_H
#define FLEXINT_H

/* C99 systems have <inttypes.h>. Non-C99 systems may or may not. */

#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

/* C99 says to define __STDC_LIMIT_MACROS before including stdint.h,
 * if you want the limit (max/min) macros for int types. 
 */
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif

#include <inttypes.h>
typedef int8_t flex_int8_t;
typedef uint8_t flex_uint8_t;
typedef int16_t flex_int16_t;
typedef uint16_t flex_uint16_t;
typedef int32_t flex_int32_t;
typedef uint32_t flex_uint32_t;
#else
typedef signed char flex_int8_t;
typedef short int flex_int16_t;
typedef int flex_int32_t;
typedef unsigned char flex_uint8_t; 
typedef unsigned short int flex_uint16_t;
typedef unsigned int flex_uint32_t;

/* Limits of integral types. */
#ifndef INT8_MIN
#define INT8_MIN               (-128)
#endif
#ifndef INT16_MIN
#define INT16_MIN              (-32767-1)
#endif
#ifndef INT32_MIN
#define INT32_MIN              (-2147483647-1)
#endif
#ifndef INT8_MAX
#define INT8_MAX               (127)
#endif
#ifndef INT16_MAX
#define INT16_MAX              (32767)
#endif
#ifndef INT32_MAX
#define INT32_MAX              (2147483647)
#endif
#ifndef UINT8_MAX
#define UINT8_MAX              (255U)
#endif
#ifndef UINT16_MAX
#define UINT16_MAX             (65535U)
#endif
#ifndef UINT32_MAX
#define UINT32_MAX             (4294967295U)
#endif

#endif /* ! C99 */

#endif /* ! FLEXINT_H */

/* %endif */

/* %if-c++-only */
/* %endif */

#ifdef __cplusplus

/* The "const" storage-class-modifier is valid. */
#define YY_USE_CONST

#else	/* ! __cplusplus */

/* C99 requires __STDC__ to be defined as 1. */
#if defined (__STDC__)

#define YY_USE_CONST

#endif	/* defined (__STDC__) */
#endif	/* ! __cplusplus */

#ifdef YY_USE_CONST
#define yyconst const
#else
#define yyconst
#endif

/* %not-for-header */

/* Returned upon end-of-file. */
#define YY_NULL 0
/* %ok-for-header */

/* %not-for-header */

/* Promotes a possibly negative, possibly signed char to an unsigned
 * integer for use as an array index.  If the signed char is negative,
 * we want to instead treat it as an 8-bit unsigned char, hence the
 * double cast.
 */
#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)
/* %ok-for-header */

/* %if-reentrant */
/* %endif */

/* %if-not-reentrant */

/* %endif */

/* Enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN.
 */
#define BEGIN (yy_start) = 1 + 2 *

/* Translate the current start state into a value that can be later handed
 * to BEGIN to return to the state.  The YYSTATE alias is for lex
 * compatibility.
 */
#define YY_START (((yy_start) - 1) / 2)
#define YYSTATE YY_START

/* Action number for EOF rule of a given start state. */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* Special action meaning "start processing a new file". */
#define YY_NEW_FILE yyrestart(yyin  )

#define YY_END_OF_BUFFER_CHAR 0

/* Size of default input buffer. */
#ifndef YY_BUF_SIZE
#ifdef __ia64__
/* On IA-64, the buffer size is 16k, not 8k.
 * Moreover, YY_BUF_SIZE is 2*YY_READ_BUF_SIZE in the general case.
 * Ditto for the __ia64__ case accordingly.
 */
#define YY_BUF_SIZE 32768
#else
#define YY_BUF_SIZE 16384
#endif /* __ia64__ */
#endif

/* The state buf must be large enough to hold one state per character in the main buffer.
 */
#define YY_STATE_BUF_SIZE   ((YY_BUF_SIZE + 2) * sizeof(yy_state_type))

#ifndef YY_TYPEDEF_YY_BUFFER_STATE
#define YY_TYPEDEF_YY_BUFFER_STATE
typedef struct yy_buffer_state *YY_BUFFER_STATE;
#endif

#ifndef YY_TYPEDEF_YY_SIZE_T
#define YY_TYPEDEF_YY_SIZE_T
typedef size_t yy_size_t;
#endif

/* %if-not-reentrant */
extern yy_size_t yyleng;
/* %endif */

/* %if-c-only */
/* %if-not-reentrant */
extern FILE *yyin, *yyout;
/* %endif */
/* %endif */

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

    /* Note: We specifically omit the test for yy_rule_can_match_eol because it requires
     *       access to the local variable yy_act. Since yyless() is a macro, it would break
     *       existing scanners that call yyless() from OUTSIDE yylex. 
     *       One obvious solution it to make yy_act a global. I tried that, and saw
     *       a 5% performance hit in a non-yylineno scanner, because yy_act is
     *       normally declared as a register variable-- so it is not worth it.
     */
    #define  YY_LESS_LINENO(n) \
            do { \
                int yyl;\
                for ( yyl = n; yyl < yyleng; ++yyl )\
                    if ( yytext[yyl] == '\n' )\
                        --yylineno;\
            }while(0)
    #define YY_LINENO_REWIND_TO(dst) \
            do {\
                const char *p;\
                for ( p = yy_cp-1; p >= (dst); --p)\
                    if ( *p == '\n' )\
                        --yylineno;\
            }while(0)
    
/* Return all but the first "n" matched characters back to the input stream. */
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
        int yyless_macro_arg = (n); \
        YY_LESS_LINENO(yyless_macro_arg);\
		*yy_cp = (yy_hold_char); \
		YY_RESTORE_YY_MORE_OFFSET \
		(yy_c_buf_p) = yy_cp = yy_bp + yyless_macro_arg - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, (yytext_ptr)  )

#ifndef YY_STRUCT_YY_BUFFER_STATE
#define YY_STRUCT_YY_BUFFER_STATE
struct yy_buffer_state
	{
/* %if-c-only */
	FILE *yy_input_file;
/* %endif */

/* %if-c++-only */
/* %endif */

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	yy_size_t yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	int yy_n_chars;

	/* Whether we "own" the buffer - i.e., we know we created it,
	 * and can realloc() it to grow it, and should free() it to
	 * delete it.
	 */
	int yy_is_our_buffer;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether we're considered to be at the beginning of a line.
	 * If so, '^' rules will be active on the next match, otherwise
	 * not.
	 */
	int yy_at_bol;

    int yy_bs_lineno; /**< The line count. */
    int yy_bs_column; /**< The column count. */
    
	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	int yy_buffer_status;

#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1
	/* When an EOF's been seen but there's still some text to process
	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we
	 * shouldn't try reading from the input source any more.  We might
	 * still have a bunch of tokens to match, though, because of
	 * possible backing-up.
	 *
	 * When we actually see the EOF, we change the status to "new"
	 * (via yyrestart()), so that the user can continue scanning by
	 * just pointing yyin at a new input file.
	 */
#define YY_BUFFER_EOF_PENDING 2

	};
#endif /* !YY_STRUCT_YY_BUFFER_STATE */

/* %if-c-only Standard (non-C++) definition */
/* %not-for-header */

/* %if-not-reentrant */

/* Stack of input buffers. */
static size_t yy_buffer_stack_top = 0; /**< index of top of stack. */
static size_t yy_buffer_stack_max = 0; /**< capacity of stack. */
static YY_BUFFER_STATE * yy_buffer_stack = 0; /**< Stack as an array. */
/* %endif */
/* %ok-for-header */

/* %endif */

/* We provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state".
 *
 * Returns the top of the stack, or NULL.
 */
#define YY_CURRENT_BUFFER ( (yy_buffer_stack) \
                          ? (yy_buffer_stack)[(yy_buffer_stack_top)] \
                          : NULL)

/* Same as previous macro, but useful when we know that the buffer stack is not
 * NULL or when we need an lvalue. For internal use only.
 */
#define YY_CURRENT_BUFFER_LVALUE (yy_buffer_stack)[(yy_buffer_stack_top)]

/* %if-c-only Standard (non-C++) definition */

/* %if-not-reentrant */
/* %not-for-header */

/* yy_hold_char holds the character lost when yytext is formed. */
static char yy_hold_char;
static int yy_n_chars;		/* number of characters read into yy_ch_buf */
yy_size_t yyleng;

/* Points to current character in buffer. */
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 0;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* Flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;
/* %ok-for-header */

/* %endif */

void yyrestart (FILE *input_file  );
void yy_switch_to_buffer (YY_BUFFER_STATE new_buffer  );
YY_BUFFER_STATE yy_create_buffer (FILE *file,int size  );
void yy_delete_buffer (YY_BUFFER_STATE b  );
void yy_flush_buffer (YY_BUFFER_STATE b  );
void yypush_buffer_state (YY_BUFFER_STATE new_buffer  );
void yypop_buffer_state (void );

static void yyensure_buffer_stack (void );
static void yy_load_buffer_state (void );
static void yy_init_buffer (YY_BUFFER_STATE b,FILE *file  );

#define YY_FLUSH_BUFFER yy_flush_buffer(YY_CURRENT_BUFFER )

YY_BUFFER_STATE yy_scan_buffer (char *base,yy_size_t size  );
YY_BUFFER_STATE yy_scan_string (yyconst char *yy_str  );
YY_BUFFER_STATE yy_scan_bytes (yyconst char *bytes,yy_size_t len  );

/* %endif */

void *yyalloc (yy_size_t  );
void *yyrealloc (void *,yy_size_t  );
void yyfree (void *  );

#define yy_new_buffer yy_create_buffer

#define yy_set_interactive(is_interactive) \
	{ \
	if ( ! YY_CURRENT_BUFFER ){ \
        yyensure_buffer_stack (); \
		YY_CURRENT_BUFFER_LVALUE =    \
            yy_create_buffer(yyin,YY_BUF_SIZE ); \
	} \
	YY_CURRENT_BUFFER_LVALUE->yy_is_interactive = is_interactive; \
	}

#define yy_set_bol(at_bol) \
	{ \
	if ( ! YY_CURRENT_BUFFER ){\
        yyensure_buffer_stack (); \
		YY_CURRENT_BUFFER_LVALUE =    \
            yy_create_buffer(yyin,YY_BUF_SIZE ); \
	} \
	YY_CURRENT_BUFFER_LVALUE->yy_at_bol = at_bol; \
	}

#define YY_AT_BOL() (YY_CURRENT_BUFFER_LVALUE->yy_at_bol)

/* %% [1.0] yytext/yyin/yyout/yy_state_type/yylineno etc. def's & init go here */
/* Begin user sect3 */

#define yywrap() (/*CONSTCOND*/1)
#define YY_SKIP_YYWRAP

#define FLEX_DEBUG

typedef unsigned char YY_CHAR;

FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;

typedef int yy_state_type;

extern int yylineno;

int yylineno = 1;

extern char *yytext;
#ifdef yytext_ptr
#undef yytext_ptr
#endif
#define yytext_ptr yytext

/* %% [1.5] DFA */

/* %if-c-only Standard (non-C++) definition */

static yy_state_type yy_get_previous_state (void );
static yy_state_type yy_try_NUL_trans (yy_state_type current_state  );
static int yy_get_next_buffer (void );
#if defined(__GNUC__) && __GNUC__ >= 3
__attribute__((__noreturn__))
#endif
static void yy_fatal_error (yyconst char msg[]  );

/* %endif */

/* Done after the current pattern has been matched and before the
 * corresponding action - sets up yytext.
 */
#define YY_DO_BEFORE_ACTION \
	(yytext_ptr) = yy_bp; \
/* %% [2.0] code to fiddle yytext and yyleng for yymore() goes here \ */\
	yyleng = (size_t) (yy_cp - yy_bp); \
	(yy_hold_char) = *yy_cp; \
	*yy_cp = '\0'; \
/* %% [3.0] code to copy yytext_ptr to yytext[] goes here, if %array \ */\
	(yy_c_buf_p) = yy_cp;

/* %% [4.0] data tables for the DFA and the user's section 1 definitions go here */
#define YY_NUM_RULES 13
#define YY_END_OF_BUFFER 14
/* This struct is not used in this scanner,
   but its presence is necessary. */
struct yy_trans_info
	{
	flex_int32_t yy_verify;
	flex_int32_t yy_nxt;
	};
static yyconst flex_int16_t yy_accept[33] =
    {   0,
        0,    0,   14,   12,    6,    5,   12,   12,   12,    7,
       10,    8,   12,    2,    3,    6,    5,    0,    0,    0,
        0,    9,    1,    0,    8,    0,    0,    7,    0,    0,
        4,    0
    } ;

static yyconst YY_CHAR yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    3,    1,    1,    1,    4,    1,    5,    1,    6,
        7,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    8,    1,
        1,    1,    1,    1,    9,    9,    9,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
       10,    1,   11,    1,    1,    1,    9,    9,    9,    9,

        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        9,    9,   12,    1,   13,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static yyconst YY_CHAR yy_meta[14] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1
    } ;

static yyconst flex_uint16_t yy_base[33] =
    {   0,
        0,    0,   34,   54,   54,   54,   12,   26,   23,   54,
       54,   23,   17,   54,   54,   54,   54,   27,   36,   23,
       40,   54,   54,   16,    0,   18,   14,   54,    7,    6,
       54,   54
    } ;

static yyconst flex_int16_t yy_def[33] =
    {   0,
       32,    1,   32,   32,   32,   32,   32,   32,   32,   32,
       32,   32,   32,   32,   32,   32,   32,    7,   32,   18,
       32,   32,   32,   32,   12,   21,   32,   32,   32,   32,
       32,    0
    } ;

static yyconst flex_uint16_t yy_nxt[68] =
    {   0,
        4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
        4,   14,   15,   16,   17,   18,   26,   19,   21,   19,
       20,   32,   23,   21,   16,   17,   32,   26,   24,   23,
       22,   25,   32,   32,   32,   32,   32,   32,   32,   27,
       32,   32,   28,   29,   32,   32,   32,   32,   32,   30,
       32,   32,   31,    3,   32,   32,   32,   32,   32,   32,
       32,   32,   32,   32,   32,   32,   32
    } ;

static yyconst flex_int16_t yy_chk[68] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    7,    7,    7,   30,    7,   29,   27,
        7,   26,   24,    7,   12,   12,   20,   13,   12,    9,
        8,   12,   18,    3,    0,    0,    0,    0,   18,   19,
        0,    0,   19,   21,    0,    0,    0,    0,    0,   21,
        0,    0,   21,   32,   32,   32,   32,   32,   32,   32,
       32,   32,   32,   32,   32,   32,   32
    } ;

/* Table of booleans, true if rule could match eol. */
static yyconst flex_int32_t yy_rule_can_match_eol[14] =
    {   0,
0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,     };

static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;

extern int yy_flex_debug;
int yy_flex_debug = 1;

static yyconst flex_int16_t yy_rule_linenum[13] =
    {   0,
       26,   27,   28,   29,   30,   31,   32,   33,   34,   35,
       36,   37
    } ;

/* The intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed.
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
#define YY_RESTORE_YY_MORE_OFFSET
char *yytext;
#line 1 "lex.l"
#line 3 "lex.l"
size_t line = 1;
#define shcommand 0
#define shident 1
#define shnewline 2
#define shand 3
#define shfunction 4
#define shcommand2 5
#define shblockstart 6
#define shblockend 7
#define sharray 8
#define shvar 9
#define shcommandsubstitution 10

#define YY_NO_UNISTD_H 1
#line 620 "lex.yy.c"

#define INITIAL 0

#ifndef YY_NO_UNISTD_H
/* Special case for "unistd.h", since it is non-ANSI. We include it way
 * down here because we want the user's section 1 to have been scanned first.
 * The user has a chance to override it with an option.
 */
/* %if-c-only */
#include <unistd.h>
/* %endif */
/* %if-c++-only */
/* %endif */
#endif

#ifndef YY_EXTRA_TYPE
#define YY_EXTRA_TYPE void *
#endif

/* %if-c-only Reentrant structure and macros (non-C++). */
/* %if-reentrant */
/* %if-c-only */

static int yy_init_globals (void );

/* %endif */
/* %if-reentrant */
/* %endif */
/* %endif End reentrant structures and macros. */

/* Accessor methods to globals.
   These are made visible to non-reentrant scanners for convenience. */

int yylex_destroy (void );

int yyget_debug (void );

void yyset_debug (int debug_flag  );

YY_EXTRA_TYPE yyget_extra (void );

void yyset_extra (YY_EXTRA_TYPE user_defined  );

FILE *yyget_in (void );

void yyset_in  (FILE * _in_str  );

FILE *yyget_out (void );

void yyset_out  (FILE * _out_str  );

yy_size_t yyget_leng (void );

char *yyget_text (void );

int yyget_lineno (void );

void yyset_lineno (int _line_number  );

/* %if-bison-bridge */
/* %endif */

/* Macros after this point can all be overridden by user definitions in
 * section 1.
 */

#ifndef YY_SKIP_YYWRAP
#ifdef __cplusplus
extern "C" int yywrap (void );
#else
extern int yywrap (void );
#endif
#endif

/* %not-for-header */

#ifndef YY_NO_UNPUT
    
#endif
/* %ok-for-header */

/* %endif */

#ifndef yytext_ptr
static void yy_flex_strncpy (char *,yyconst char *,int );
#endif

#ifdef YY_NEED_STRLEN
static int yy_flex_strlen (yyconst char * );
#endif

#ifndef YY_NO_INPUT
/* %if-c-only Standard (non-C++) definition */
/* %not-for-header */

#ifdef __cplusplus
static int yyinput (void );
#else
static int input (void );
#endif
/* %ok-for-header */

/* %endif */
#endif

/* %if-c-only */

/* %endif */

/* Amount of stuff to slurp up with each read. */
#ifndef YY_READ_BUF_SIZE
#ifdef __ia64__
/* On IA-64, the buffer size is 16k, not 8k */
#define YY_READ_BUF_SIZE 16384
#else
#define YY_READ_BUF_SIZE 8192
#endif /* __ia64__ */
#endif

/* Copy whatever the last rule matched to the standard output. */
#ifndef ECHO
/* %if-c-only Standard (non-C++) definition */
/* This used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite().
 */
#define ECHO do { if (fwrite( yytext, yyleng, 1, yyout )) {} } while (0)
/* %endif */
/* %if-c++-only C++ definition */
/* %endif */
#endif

/* Gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
/* %% [5.0] fread()/read() definition of YY_INPUT goes here unless we're doing C++ \ */\
	if ( YY_CURRENT_BUFFER_LVALUE->yy_is_interactive ) \
		{ \
		int c = '*'; \
		size_t n; \
		for ( n = 0; n < max_size && \
			     (c = getc( yyin )) != EOF && c != '\n'; ++n ) \
			buf[n] = (char) c; \
		if ( c == '\n' ) \
			buf[n++] = (char) c; \
		if ( c == EOF && ferror( yyin ) ) \
			YY_FATAL_ERROR( "input in flex scanner failed" ); \
		result = n; \
		} \
	else \
		{ \
		errno=0; \
		while ( (result = fread(buf, 1, max_size, yyin))==0 && ferror(yyin)) \
			{ \
			if( errno != EINTR) \
				{ \
				YY_FATAL_ERROR( "input in flex scanner failed" ); \
				break; \
				} \
			errno=0; \
			clearerr(yyin); \
			} \
		}\
\
/* %if-c++-only C++ definition \ */\
/* %endif */

#endif

/* No semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#ifndef yyterminate
#define yyterminate() return YY_NULL
#endif

/* Number of entries by which start-condition stack grows. */
#ifndef YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#endif

/* Report a fatal error. */
#ifndef YY_FATAL_ERROR
/* %if-c-only */
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
/* %endif */
/* %if-c++-only */
/* %endif */
#endif

/* %if-tables-serialization structures and prototypes */
/* %not-for-header */

/* %ok-for-header */

/* %not-for-header */

/* %tables-yydmap generated elements */
/* %endif */
/* end tables serialization structures and prototypes */

/* %ok-for-header */

/* Default declaration of generated scanner - a define so the user can
 * easily add parameters.
 */
#ifndef YY_DECL
#define YY_DECL_IS_OURS 1
/* %if-c-only Standard (non-C++) definition */

extern int yylex (void);

#define YY_DECL int yylex (void)
/* %endif */
/* %if-c++-only C++ definition */
/* %endif */
#endif /* !YY_DECL */

/* Code executed at the beginning of each rule, after yytext and yyleng
 * have been set up.
 */
#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

/* Code executed at the end of each rule. */
#ifndef YY_BREAK
#define YY_BREAK /*LINTED*/break;
#endif

/* %% [6.0] YY_RULE_SETUP definition goes here */
#define YY_RULE_SETUP \
	YY_USER_ACTION

/* %not-for-header */

/** The main scanner function which does all the work.
 */
YY_DECL
{
	yy_state_type yy_current_state;
	char *yy_cp, *yy_bp;
	int yy_act;
    
	if ( !(yy_init) )
		{
		(yy_init) = 1;

#ifdef YY_USER_INIT
		YY_USER_INIT;
#endif

		if ( ! (yy_start) )
			(yy_start) = 1;	/* first start state */

		if ( ! yyin )
/* %if-c-only */
			yyin = stdin;
/* %endif */
/* %if-c++-only */
/* %endif */

		if ( ! yyout )
/* %if-c-only */
			yyout = stdout;
/* %endif */
/* %if-c++-only */
/* %endif */

		if ( ! YY_CURRENT_BUFFER ) {
			yyensure_buffer_stack ();
			YY_CURRENT_BUFFER_LVALUE =
				yy_create_buffer(yyin,YY_BUF_SIZE );
		}

		yy_load_buffer_state( );
		}

	{
/* %% [7.0] user's declarations go here */
#line 24 "lex.l"

#line 905 "lex.yy.c"

	while ( /*CONSTCOND*/1 )		/* loops until end-of-file is reached */
		{
/* %% [8.0] yymore()-related code goes here */
		yy_cp = (yy_c_buf_p);

		/* Support of yytext. */
		*yy_cp = (yy_hold_char);

		/* yy_bp points to the position in yy_ch_buf of the start of
		 * the current run.
		 */
		yy_bp = yy_cp;

/* %% [9.0] code to set up and find next match goes here */
		yy_current_state = (yy_start);
yy_match:
		do
			{
			YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)] ;
			if ( yy_accept[yy_current_state] )
				{
				(yy_last_accepting_state) = yy_current_state;
				(yy_last_accepting_cpos) = yy_cp;
				}
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 33 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			++yy_cp;
			}
		while ( yy_current_state != 32 );
		yy_cp = (yy_last_accepting_cpos);
		yy_current_state = (yy_last_accepting_state);

yy_find_action:
/* %% [10.0] code to find the action number goes here */
		yy_act = yy_accept[yy_current_state];

		YY_DO_BEFORE_ACTION;

/* %% [11.0] code for yylineno update goes here */

		if ( yy_act != YY_END_OF_BUFFER && yy_rule_can_match_eol[yy_act] )
			{
			yy_size_t yyl;
			for ( yyl = 0; yyl < yyleng; ++yyl )
				if ( yytext[yyl] == '\n' )
					   
    yylineno++;
;
			}

do_action:	/* This label is used only to access EOF actions. */

/* %% [12.0] debug code goes here */
		if ( yy_flex_debug )
			{
			if ( yy_act == 0 )
				fprintf( stderr, "--scanner backing up\n" );
			else if ( yy_act < 13 )
				fprintf( stderr, "--accepting rule at line %ld (\"%s\")\n",
				         (long)yy_rule_linenum[yy_act], yytext );
			else if ( yy_act == 13 )
				fprintf( stderr, "--accepting default rule (\"%s\")\n",
				         yytext );
			else if ( yy_act == 14 )
				fprintf( stderr, "--(end of buffer or a NUL)\n" );
			else
				fprintf( stderr, "--EOF (start condition %d)\n", YY_START );
			}

		switch ( yy_act )
	{ /* beginning of action switch */
/* %% [13.0] actions go here */
			case 0: /* must back up */
			/* undo the effects of YY_DO_BEFORE_ACTION */
			*yy_cp = (yy_hold_char);
			yy_cp = (yy_last_accepting_cpos);
			yy_current_state = (yy_last_accepting_state);
			goto yy_find_action;

case YY_STATE_EOF(INITIAL):
#line 25 "lex.l"
{ return EOF; /* valid */ }
	YY_BREAK
case 1:
YY_RULE_SETUP
#line 26 "lex.l"
{ return shfunction; /* valid */}
	YY_BREAK
case 2:
YY_RULE_SETUP
#line 27 "lex.l"
{ return shblockstart; /* valid */}
	YY_BREAK
case 3:
YY_RULE_SETUP
#line 28 "lex.l"
{ return shblockend; /* valid */}
	YY_BREAK
case 4:
YY_RULE_SETUP
#line 29 "lex.l"
{ return sharray; }
	YY_BREAK
case 5:
YY_RULE_SETUP
#line 30 "lex.l"
{ return shvar; }
	YY_BREAK
case 6:
/* rule 6 can match eol */
YY_RULE_SETUP
#line 31 "lex.l"
{ line++; return shvar; }
	YY_BREAK
case 7:
YY_RULE_SETUP
#line 32 "lex.l"
{ return shcommandsubstitution; }
	YY_BREAK
case 8:
YY_RULE_SETUP
#line 33 "lex.l"
{ return shident; /* valid */}
	YY_BREAK
case 9:
YY_RULE_SETUP
#line 34 "lex.l"
{ return shand; /* valid */}
	YY_BREAK
case 10:
YY_RULE_SETUP
#line 35 "lex.l"
{ return shcommand; /* valid */}
	YY_BREAK
case 11:
/* rule 11 can match eol */
YY_RULE_SETUP
#line 36 "lex.l"
{ line++; return shcommand2; /* valid */}
	YY_BREAK
case 12:
YY_RULE_SETUP
#line 37 "lex.l"
{ /* skip everything else */ }
	YY_BREAK
case 13:
YY_RULE_SETUP
#line 38 "lex.l"
YY_FATAL_ERROR( "flex scanner jammed" );
	YY_BREAK
#line 1062 "lex.yy.c"

	case YY_END_OF_BUFFER:
		{
		/* Amount of text matched not including the EOB char. */
		int yy_amount_of_matched_text = (int) (yy_cp - (yytext_ptr)) - 1;

		/* Undo the effects of YY_DO_BEFORE_ACTION. */
		*yy_cp = (yy_hold_char);
		YY_RESTORE_YY_MORE_OFFSET

		if ( YY_CURRENT_BUFFER_LVALUE->yy_buffer_status == YY_BUFFER_NEW )
			{
			/* We're scanning a new file or input source.  It's
			 * possible that this happened because the user
			 * just pointed yyin at a new source and called
			 * yylex().  If so, then we have to assure
			 * consistency between YY_CURRENT_BUFFER and our
			 * globals.  Here is the right place to do so, because
			 * this is the first action (other than possibly a
			 * back-up) that will match for the new input source.
			 */
			(yy_n_chars) = YY_CURRENT_BUFFER_LVALUE->yy_n_chars;
/* %if-c-only */
			YY_CURRENT_BUFFER_LVALUE->yy_input_file = yyin;
/* %endif */
/* %if-c++-only */
/* %endif */
			YY_CURRENT_BUFFER_LVALUE->yy_buffer_status = YY_BUFFER_NORMAL;
			}

		/* Note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the
		 * end-of-buffer state).  Contrast this with the test
		 * in input().
		 */
		if ( (yy_c_buf_p) <= &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)] )
			{ /* This was really a NUL. */
			yy_state_type yy_next_state;

			(yy_c_buf_p) = (yytext_ptr) + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state(  );

			/* Okay, we're now positioned to make the NUL
			 * transition.  We couldn't have
			 * yy_get_previous_state() go ahead and do it
			 * for us because it doesn't know how to deal
			 * with the possibility of jamming (and we don't
			 * want to build jamming into it because then it
			 * will run more slowly).
			 */

			yy_next_state = yy_try_NUL_trans( yy_current_state );

			yy_bp = (yytext_ptr) + YY_MORE_ADJ;

			if ( yy_next_state )
				{
				/* Consume the NUL. */
				yy_cp = ++(yy_c_buf_p);
				yy_current_state = yy_next_state;
				goto yy_match;
				}

			else
				{
/* %% [14.0] code to do back-up for compressed tables and set up yy_cp goes here */
				yy_cp = (yy_last_accepting_cpos);
				yy_current_state = (yy_last_accepting_state);
				goto yy_find_action;
				}
			}

		else switch ( yy_get_next_buffer(  ) )
			{
			case EOB_ACT_END_OF_FILE:
				{
				(yy_did_buffer_switch_on_eof) = 0;

				if ( yywrap( ) )
					{
					/* Note: because we've taken care in
					 * yy_get_next_buffer() to have set up
					 * yytext, we can now set up
					 * yy_c_buf_p so that if some total
					 * hoser (like flex itself) wants to
					 * call the scanner after we return the
					 * YY_NULL, it'll still work - another
					 * YY_NULL will get returned.
					 */
					(yy_c_buf_p) = (yytext_ptr) + YY_MORE_ADJ;

					yy_act = YY_STATE_EOF(YY_START);
					goto do_action;
					}

				else
					{
					if ( ! (yy_did_buffer_switch_on_eof) )
						YY_NEW_FILE;
					}
				break;
				}

			case EOB_ACT_CONTINUE_SCAN:
				(yy_c_buf_p) =
					(yytext_ptr) + yy_amount_of_matched_text;

				yy_current_state = yy_get_previous_state(  );

				yy_cp = (yy_c_buf_p);
				yy_bp = (yytext_ptr) + YY_MORE_ADJ;
				goto yy_match;

			case EOB_ACT_LAST_MATCH:
				(yy_c_buf_p) =
				&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)];

				yy_current_state = yy_get_previous_state(  );

				yy_cp = (yy_c_buf_p);
				yy_bp = (yytext_ptr) + YY_MORE_ADJ;
				goto yy_find_action;
			}
		break;
		}

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} /* end of action switch */
		} /* end of scanning one token */
	} /* end of user's declarations */
} /* end of yylex */
/* %ok-for-header */

/* %if-c++-only */
/* %not-for-header */

/* %ok-for-header */

/* %endif */

/* yy_get_next_buffer - try to read in a new buffer
 *
 * Returns a code representing an action:
 *	EOB_ACT_LAST_MATCH -
 *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *	EOB_ACT_END_OF_FILE - end of file
 */
/* %if-c-only */
static int yy_get_next_buffer (void)
/* %endif */
/* %if-c++-only */
/* %endif */
{
    	char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
	char *source = (yytext_ptr);
	yy_size_t number_to_move, i;
	int ret_val;

	if ( (yy_c_buf_p) > &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars) + 1] )
		YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

	if ( YY_CURRENT_BUFFER_LVALUE->yy_fill_buffer == 0 )
		{ /* Don't try to fill the buffer, so this is an EOF. */
		if ( (yy_c_buf_p) - (yytext_ptr) - YY_MORE_ADJ == 1 )
			{
			/* We matched a single character, the EOB, so
			 * treat this as a final EOF.
			 */
			return EOB_ACT_END_OF_FILE;
			}

		else
			{
			/* We matched some text prior to the EOB, first
			 * process it.
			 */
			return EOB_ACT_LAST_MATCH;
			}
		}

	/* Try to read more data. */

	/* First move last chars to start of buffer. */
	number_to_move = (yy_size_t) ((yy_c_buf_p) - (yytext_ptr)) - 1;

	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);

	if ( YY_CURRENT_BUFFER_LVALUE->yy_buffer_status == YY_BUFFER_EOF_PENDING )
		/* don't do the read, it's not guaranteed to return an EOF,
		 * just force an EOF
		 */
		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars) = 0;

	else
		{
			yy_size_t num_to_read =
			YY_CURRENT_BUFFER_LVALUE->yy_buf_size - number_to_move - 1;

		while ( num_to_read <= 0 )
			{ /* Not enough room in the buffer - grow it. */

			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = YY_CURRENT_BUFFER_LVALUE;

			int yy_c_buf_p_offset =
				(int) ((yy_c_buf_p) - b->yy_ch_buf);

			if ( b->yy_is_our_buffer )
				{
				yy_size_t new_size = b->yy_buf_size * 2;

				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;

				b->yy_ch_buf = (char *)
					/* Include room in for 2 EOB chars. */
					yyrealloc((void *) b->yy_ch_buf,b->yy_buf_size + 2  );
				}
			else
				/* Can't grow it, we don't own it. */
				b->yy_ch_buf = 0;

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			(yy_c_buf_p) = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = YY_CURRENT_BUFFER_LVALUE->yy_buf_size -
						number_to_move - 1;

			}

		if ( num_to_read > YY_READ_BUF_SIZE )
			num_to_read = YY_READ_BUF_SIZE;

		/* Read in more data. */
		YY_INPUT( (&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[number_to_move]),
			(yy_n_chars), num_to_read );

		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars);
		}

	if ( (yy_n_chars) == 0 )
		{
		if ( number_to_move == YY_MORE_ADJ )
			{
			ret_val = EOB_ACT_END_OF_FILE;
			yyrestart(yyin  );
			}

		else
			{
			ret_val = EOB_ACT_LAST_MATCH;
			YY_CURRENT_BUFFER_LVALUE->yy_buffer_status =
				YY_BUFFER_EOF_PENDING;
			}
		}

	else
		ret_val = EOB_ACT_CONTINUE_SCAN;

	if ((int) ((yy_n_chars) + number_to_move) > YY_CURRENT_BUFFER_LVALUE->yy_buf_size) {
		/* Extend the array by 50%, plus the number we really need. */
		int new_size = (yy_n_chars) + number_to_move + ((yy_n_chars) >> 1);
		YY_CURRENT_BUFFER_LVALUE->yy_ch_buf = (char *) yyrealloc((void *) YY_CURRENT_BUFFER_LVALUE->yy_ch_buf,new_size  );
		if ( ! YY_CURRENT_BUFFER_LVALUE->yy_ch_buf )
			YY_FATAL_ERROR( "out of dynamic memory in yy_get_next_buffer()" );
	}

	(yy_n_chars) += number_to_move;
	YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)] = YY_END_OF_BUFFER_CHAR;
	YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars) + 1] = YY_END_OF_BUFFER_CHAR;

	(yytext_ptr) = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[0];

	return ret_val;
}

/* yy_get_previous_state - get the state just before the EOB char was reached */

/* %if-c-only */
/* %not-for-header */

    static yy_state_type yy_get_previous_state (void)
/* %endif */
/* %if-c++-only */
/* %endif */
{
	yy_state_type yy_current_state;
	char *yy_cp;
    
/* %% [15.0] code to get the start state into yy_current_state goes here */
	yy_current_state = (yy_start);

	for ( yy_cp = (yytext_ptr) + YY_MORE_ADJ; yy_cp < (yy_c_buf_p); ++yy_cp )
		{
/* %% [16.0] code to find the next state goes here */
		YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
		if ( yy_accept[yy_current_state] )
			{
			(yy_last_accepting_state) = yy_current_state;
			(yy_last_accepting_cpos) = yy_cp;
			}
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
			{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 33 )
				yy_c = yy_meta[(unsigned int) yy_c];
			}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
		}

	return yy_current_state;
}

/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *	next_state = yy_try_NUL_trans( current_state );
 */
/* %if-c-only */
    static yy_state_type yy_try_NUL_trans  (yy_state_type yy_current_state )
/* %endif */
/* %if-c++-only */
/* %endif */
{
	int yy_is_jam;
    /* %% [17.0] code to find the next state, and perhaps do backing up, goes here */
	char *yy_cp = (yy_c_buf_p);

	YY_CHAR yy_c = 1;
	if ( yy_accept[yy_current_state] )
		{
		(yy_last_accepting_state) = yy_current_state;
		(yy_last_accepting_cpos) = yy_cp;
		}
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 33 )
			yy_c = yy_meta[(unsigned int) yy_c];
		}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	yy_is_jam = (yy_current_state == 32);

		return yy_is_jam ? 0 : yy_current_state;
}

#ifndef YY_NO_UNPUT
/* %if-c-only */

/* %endif */
#endif

/* %if-c-only */
#ifndef YY_NO_INPUT
#ifdef __cplusplus
    static int yyinput (void)
#else
    static int input  (void)
#endif

/* %endif */
/* %if-c++-only */
/* %endif */
{
	int c;
    
	*(yy_c_buf_p) = (yy_hold_char);

	if ( *(yy_c_buf_p) == YY_END_OF_BUFFER_CHAR )
		{
		/* yy_c_buf_p now points to the character we want to return.
		 * If this occurs *before* the EOB characters, then it's a
		 * valid NUL; if not, then we've hit the end of the buffer.
		 */
		if ( (yy_c_buf_p) < &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)] )
			/* This was really a NUL. */
			*(yy_c_buf_p) = '\0';

		else
			{ /* need more input */
			yy_size_t offset = (yy_c_buf_p) - (yytext_ptr);
			++(yy_c_buf_p);

			switch ( yy_get_next_buffer(  ) )
				{
				case EOB_ACT_LAST_MATCH:
					/* This happens because yy_g_n_b()
					 * sees that we've accumulated a
					 * token and flags that we need to
					 * try matching the token before
					 * proceeding.  But for input(),
					 * there's no matching to consider.
					 * So convert the EOB_ACT_LAST_MATCH
					 * to EOB_ACT_END_OF_FILE.
					 */

					/* Reset buffer status. */
					yyrestart(yyin );

					/*FALLTHROUGH*/

				case EOB_ACT_END_OF_FILE:
					{
					if ( yywrap( ) )
						return EOF;

					if ( ! (yy_did_buffer_switch_on_eof) )
						YY_NEW_FILE;
#ifdef __cplusplus
					return yyinput();
#else
					return input();
#endif
					}

				case EOB_ACT_CONTINUE_SCAN:
					(yy_c_buf_p) = (yytext_ptr) + offset;
					break;
				}
			}
		}

	c = *(unsigned char *) (yy_c_buf_p);	/* cast for 8-bit char's */
	*(yy_c_buf_p) = '\0';	/* preserve yytext */
	(yy_hold_char) = *++(yy_c_buf_p);

/* %% [19.0] update BOL and yylineno */
	if ( c == '\n' )
		   
    yylineno++;
;

	return c;
}
/* %if-c-only */
#endif	/* ifndef YY_NO_INPUT */
/* %endif */

/** Immediately switch to a different input stream.
 * @param input_file A readable stream.
 * 
 * @note This function does not reset the start condition to @c INITIAL .
 */
/* %if-c-only */
    void yyrestart  (FILE * input_file )
/* %endif */
/* %if-c++-only */
/* %endif */
{
    
	if ( ! YY_CURRENT_BUFFER ){
        yyensure_buffer_stack ();
		YY_CURRENT_BUFFER_LVALUE =
            yy_create_buffer(yyin,YY_BUF_SIZE );
	}

	yy_init_buffer(YY_CURRENT_BUFFER,input_file );
	yy_load_buffer_state( );
}

/* %if-c++-only */
/* %endif */

/** Switch to a different input buffer.
 * @param new_buffer The new input buffer.
 * 
 */
/* %if-c-only */
    void yy_switch_to_buffer  (YY_BUFFER_STATE  new_buffer )
/* %endif */
/* %if-c++-only */
/* %endif */
{
    
	/* TODO. We should be able to replace this entire function body
	 * with
	 *		yypop_buffer_state();
	 *		yypush_buffer_state(new_buffer);
     */
	yyensure_buffer_stack ();
	if ( YY_CURRENT_BUFFER == new_buffer )
		return;

	if ( YY_CURRENT_BUFFER )
		{
		/* Flush out information for old buffer. */
		*(yy_c_buf_p) = (yy_hold_char);
		YY_CURRENT_BUFFER_LVALUE->yy_buf_pos = (yy_c_buf_p);
		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars);
		}

	YY_CURRENT_BUFFER_LVALUE = new_buffer;
	yy_load_buffer_state( );

	/* We don't actually know whether we did this switch during
	 * EOF (yywrap()) processing, but the only time this flag
	 * is looked at is after yywrap() is called, so it's safe
	 * to go ahead and always set it.
	 */
	(yy_did_buffer_switch_on_eof) = 1;
}

/* %if-c-only */
static void yy_load_buffer_state  (void)
/* %endif */
/* %if-c++-only */
/* %endif */
{
    	(yy_n_chars) = YY_CURRENT_BUFFER_LVALUE->yy_n_chars;
	(yytext_ptr) = (yy_c_buf_p) = YY_CURRENT_BUFFER_LVALUE->yy_buf_pos;
/* %if-c-only */
	yyin = YY_CURRENT_BUFFER_LVALUE->yy_input_file;
/* %endif */
/* %if-c++-only */
/* %endif */
	(yy_hold_char) = *(yy_c_buf_p);
}

/** Allocate and initialize an input buffer state.
 * @param file A readable stream.
 * @param size The character buffer size in bytes. When in doubt, use @c YY_BUF_SIZE.
 * 
 * @return the allocated buffer state.
 */
/* %if-c-only */
    YY_BUFFER_STATE yy_create_buffer  (FILE * file, int  size )
/* %endif */
/* %if-c++-only */
/* %endif */
{
	YY_BUFFER_STATE b;
    
	b = (YY_BUFFER_STATE) yyalloc(sizeof( struct yy_buffer_state )  );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_buf_size = (yy_size_t)size;

	/* yy_ch_buf has to be 2 characters longer than the size given because
	 * we need to put in 2 end-of-buffer characters.
	 */
	b->yy_ch_buf = (char *) yyalloc(b->yy_buf_size + 2  );
	if ( ! b->yy_ch_buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_is_our_buffer = 1;

	yy_init_buffer(b,file );

	return b;
}

/* %if-c++-only */
/* %endif */

/** Destroy the buffer.
 * @param b a buffer created with yy_create_buffer()
 * 
 */
/* %if-c-only */
    void yy_delete_buffer (YY_BUFFER_STATE  b )
/* %endif */
/* %if-c++-only */
/* %endif */
{
    
	if ( ! b )
		return;

	if ( b == YY_CURRENT_BUFFER ) /* Not sure if we should pop here. */
		YY_CURRENT_BUFFER_LVALUE = (YY_BUFFER_STATE) 0;

	if ( b->yy_is_our_buffer )
		yyfree((void *) b->yy_ch_buf  );

	yyfree((void *) b  );
}

/* Initializes or reinitializes a buffer.
 * This function is sometimes called more than once on the same buffer,
 * such as during a yyrestart() or at EOF.
 */
/* %if-c-only */
    static void yy_init_buffer  (YY_BUFFER_STATE  b, FILE * file )
/* %endif */
/* %if-c++-only */
/* %endif */

{
	int oerrno = errno;
    
	yy_flush_buffer(b );

/* %if-c-only */
	b->yy_input_file = file;
/* %endif */
/* %if-c++-only */
/* %endif */
	b->yy_fill_buffer = 1;

    /* If b is the current buffer, then yy_init_buffer was _probably_
     * called from yyrestart() or through yy_get_next_buffer.
     * In that case, we don't want to reset the lineno or column.
     */
    if (b != YY_CURRENT_BUFFER){
        b->yy_bs_lineno = 1;
        b->yy_bs_column = 0;
    }

/* %if-c-only */

        b->yy_is_interactive = 0;
    
/* %endif */
/* %if-c++-only */
/* %endif */
	errno = oerrno;
}

/** Discard all buffered characters. On the next scan, YY_INPUT will be called.
 * @param b the buffer state to be flushed, usually @c YY_CURRENT_BUFFER.
 * 
 */
/* %if-c-only */
    void yy_flush_buffer (YY_BUFFER_STATE  b )
/* %endif */
/* %if-c++-only */
/* %endif */
{
    	if ( ! b )
		return;

	b->yy_n_chars = 0;

	/* We always need two end-of-buffer characters.  The first causes
	 * a transition to the end-of-buffer state.  The second causes
	 * a jam in that state.
	 */
	b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;
	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;

	b->yy_buf_pos = &b->yy_ch_buf[0];

	b->yy_at_bol = 1;
	b->yy_buffer_status = YY_BUFFER_NEW;

	if ( b == YY_CURRENT_BUFFER )
		yy_load_buffer_state( );
}

/* %if-c-or-c++ */
/** Pushes the new state onto the stack. The new state becomes
 *  the current state. This function will allocate the stack
 *  if necessary.
 *  @param new_buffer The new state.
 *  
 */
/* %if-c-only */
void yypush_buffer_state (YY_BUFFER_STATE new_buffer )
/* %endif */
/* %if-c++-only */
/* %endif */
{
    	if (new_buffer == NULL)
		return;

	yyensure_buffer_stack();

	/* This block is copied from yy_switch_to_buffer. */
	if ( YY_CURRENT_BUFFER )
		{
		/* Flush out information for old buffer. */
		*(yy_c_buf_p) = (yy_hold_char);
		YY_CURRENT_BUFFER_LVALUE->yy_buf_pos = (yy_c_buf_p);
		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars);
		}

	/* Only push if top exists. Otherwise, replace top. */
	if (YY_CURRENT_BUFFER)
		(yy_buffer_stack_top)++;
	YY_CURRENT_BUFFER_LVALUE = new_buffer;

	/* copied from yy_switch_to_buffer. */
	yy_load_buffer_state( );
	(yy_did_buffer_switch_on_eof) = 1;
}
/* %endif */

/* %if-c-or-c++ */
/** Removes and deletes the top of the stack, if present.
 *  The next element becomes the new top.
 *  
 */
/* %if-c-only */
void yypop_buffer_state (void)
/* %endif */
/* %if-c++-only */
/* %endif */
{
    	if (!YY_CURRENT_BUFFER)
		return;

	yy_delete_buffer(YY_CURRENT_BUFFER );
	YY_CURRENT_BUFFER_LVALUE = NULL;
	if ((yy_buffer_stack_top) > 0)
		--(yy_buffer_stack_top);

	if (YY_CURRENT_BUFFER) {
		yy_load_buffer_state( );
		(yy_did_buffer_switch_on_eof) = 1;
	}
}
/* %endif */

/* %if-c-or-c++ */
/* Allocates the stack if it does not exist.
 *  Guarantees space for at least one push.
 */
/* %if-c-only */
static void yyensure_buffer_stack (void)
/* %endif */
/* %if-c++-only */
/* %endif */
{
	yy_size_t num_to_alloc;
    
	if (!(yy_buffer_stack)) {

		/* First allocation is just for 2 elements, since we don't know if this
		 * scanner will even need a stack. We use 2 instead of 1 to avoid an
		 * immediate realloc on the next call.
         */
		num_to_alloc = 1; /* After all that talk, this was set to 1 anyways... */
		(yy_buffer_stack) = (struct yy_buffer_state**)yyalloc
								(num_to_alloc * sizeof(struct yy_buffer_state*)
								);
		if ( ! (yy_buffer_stack) )
			YY_FATAL_ERROR( "out of dynamic memory in yyensure_buffer_stack()" );
								  
		memset((yy_buffer_stack), 0, num_to_alloc * sizeof(struct yy_buffer_state*));
				
		(yy_buffer_stack_max) = num_to_alloc;
		(yy_buffer_stack_top) = 0;
		return;
	}

	if ((yy_buffer_stack_top) >= ((yy_buffer_stack_max)) - 1){

		/* Increase the buffer to prepare for a possible push. */
		yy_size_t grow_size = 8 /* arbitrary grow size */;

		num_to_alloc = (yy_buffer_stack_max) + grow_size;
		(yy_buffer_stack) = (struct yy_buffer_state**)yyrealloc
								((yy_buffer_stack),
								num_to_alloc * sizeof(struct yy_buffer_state*)
								);
		if ( ! (yy_buffer_stack) )
			YY_FATAL_ERROR( "out of dynamic memory in yyensure_buffer_stack()" );

		/* zero only the new slots.*/
		memset((yy_buffer_stack) + (yy_buffer_stack_max), 0, grow_size * sizeof(struct yy_buffer_state*));
		(yy_buffer_stack_max) = num_to_alloc;
	}
}
/* %endif */

/* %if-c-only */
/** Setup the input buffer state to scan directly from a user-specified character buffer.
 * @param base the character buffer
 * @param size the size in bytes of the character buffer
 * 
 * @return the newly allocated buffer state object. 
 */
YY_BUFFER_STATE yy_scan_buffer  (char * base, yy_size_t  size )
{
	YY_BUFFER_STATE b;
    
	if ( size < 2 ||
	     base[size-2] != YY_END_OF_BUFFER_CHAR ||
	     base[size-1] != YY_END_OF_BUFFER_CHAR )
		/* They forgot to leave room for the EOB's. */
		return 0;

	b = (YY_BUFFER_STATE) yyalloc(sizeof( struct yy_buffer_state )  );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_buffer()" );

	b->yy_buf_size = size - 2;	/* "- 2" to take care of EOB's */
	b->yy_buf_pos = b->yy_ch_buf = base;
	b->yy_is_our_buffer = 0;
	b->yy_input_file = 0;
	b->yy_n_chars = b->yy_buf_size;
	b->yy_is_interactive = 0;
	b->yy_at_bol = 1;
	b->yy_fill_buffer = 0;
	b->yy_buffer_status = YY_BUFFER_NEW;

	yy_switch_to_buffer(b  );

	return b;
}
/* %endif */

/* %if-c-only */
/** Setup the input buffer state to scan a string. The next call to yylex() will
 * scan from a @e copy of @a str.
 * @param yystr a NUL-terminated string to scan
 * 
 * @return the newly allocated buffer state object.
 * @note If you want to scan bytes that may contain NUL values, then use
 *       yy_scan_bytes() instead.
 */
YY_BUFFER_STATE yy_scan_string (yyconst char * yystr )
{
    
	return yy_scan_bytes(yystr,strlen(yystr) );
}
/* %endif */

/* %if-c-only */
/** Setup the input buffer state to scan the given bytes. The next call to yylex() will
 * scan from a @e copy of @a bytes.
 * @param yybytes the byte buffer to scan
 * @param _yybytes_len the number of bytes in the buffer pointed to by @a bytes.
 * 
 * @return the newly allocated buffer state object.
 */
YY_BUFFER_STATE yy_scan_bytes  (yyconst char * yybytes, yy_size_t  _yybytes_len )
{
	YY_BUFFER_STATE b;
	char *buf;
	yy_size_t n;
	yy_size_t i;
    
	/* Get memory for full buffer, including space for trailing EOB's. */
	n = _yybytes_len + 2;
	buf = (char *) yyalloc(n  );
	if ( ! buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_bytes()" );

	for ( i = 0; i < _yybytes_len; ++i )
		buf[i] = yybytes[i];

	buf[_yybytes_len] = buf[_yybytes_len+1] = YY_END_OF_BUFFER_CHAR;

	b = yy_scan_buffer(buf,n );
	if ( ! b )
		YY_FATAL_ERROR( "bad buffer in yy_scan_bytes()" );

	/* It's okay to grow etc. this buffer, and we should throw it
	 * away when we're done.
	 */
	b->yy_is_our_buffer = 1;

	return b;
}
/* %endif */

#ifndef YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#endif

/* %if-c-only */
static void yy_fatal_error (yyconst char* msg )
{
			(void) fprintf( stderr, "%s\n", msg );
	exit( YY_EXIT_FAILURE );
}
/* %endif */
/* %if-c++-only */
/* %endif */

/* Redefine yyless() so it works in section 3 code. */

#undef yyless
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
        int yyless_macro_arg = (n); \
        YY_LESS_LINENO(yyless_macro_arg);\
		yytext[yyleng] = (yy_hold_char); \
		(yy_c_buf_p) = yytext + yyless_macro_arg; \
		(yy_hold_char) = *(yy_c_buf_p); \
		*(yy_c_buf_p) = '\0'; \
		yyleng = yyless_macro_arg; \
		} \
	while ( 0 )

/* Accessor  methods (get/set functions) to struct members. */

/* %if-c-only */
/* %if-reentrant */
/* %endif */

/** Get the current line number.
 * 
 */
int yyget_lineno  (void)
{
        
    return yylineno;
}

/** Get the input stream.
 * 
 */
FILE *yyget_in  (void)
{
        return yyin;
}

/** Get the output stream.
 * 
 */
FILE *yyget_out  (void)
{
        return yyout;
}

/** Get the length of the current token.
 * 
 */
yy_size_t yyget_leng  (void)
{
        return yyleng;
}

/** Get the current token.
 * 
 */

char *yyget_text  (void)
{
        return yytext;
}

/* %if-reentrant */
/* %endif */

/** Set the current line number.
 * @param _line_number line number
 * 
 */
void yyset_lineno (int  _line_number )
{
    
    yylineno = _line_number;
}

/** Set the input stream. This does not discard the current
 * input buffer.
 * @param _in_str A readable stream.
 * 
 * @see yy_switch_to_buffer
 */
void yyset_in (FILE *  _in_str )
{
        yyin = _in_str ;
}

void yyset_out (FILE *  _out_str )
{
        yyout = _out_str ;
}

int yyget_debug  (void)
{
        return yy_flex_debug;
}

void yyset_debug (int  _bdebug )
{
        yy_flex_debug = _bdebug ;
}

/* %endif */

/* %if-reentrant */
/* %if-bison-bridge */
/* %endif */
/* %endif if-c-only */

/* %if-c-only */
static int yy_init_globals (void)
{
        /* Initialization is the same as for the non-reentrant scanner.
     * This function is called from yylex_destroy(), so don't allocate here.
     */

    /* We do not touch yylineno unless the option is enabled. */
    yylineno =  1;
    
    (yy_buffer_stack) = 0;
    (yy_buffer_stack_top) = 0;
    (yy_buffer_stack_max) = 0;
    (yy_c_buf_p) = (char *) 0;
    (yy_init) = 0;
    (yy_start) = 0;

/* Defined in main.c */
#ifdef YY_STDINIT
    yyin = stdin;
    yyout = stdout;
#else
    yyin = (FILE *) 0;
    yyout = (FILE *) 0;
#endif

    /* For future reference: Set errno on error, since we are called by
     * yylex_init()
     */
    return 0;
}
/* %endif */

/* %if-c-only SNIP! this currently causes conflicts with the c++ scanner */
/* yylex_destroy is for both reentrant and non-reentrant scanners. */
int yylex_destroy  (void)
{
    
    /* Pop the buffer stack, destroying each element. */
	while(YY_CURRENT_BUFFER){
		yy_delete_buffer(YY_CURRENT_BUFFER  );
		YY_CURRENT_BUFFER_LVALUE = NULL;
		yypop_buffer_state();
	}

	/* Destroy the stack itself. */
	yyfree((yy_buffer_stack) );
	(yy_buffer_stack) = NULL;

    /* Reset the globals. This is important in a non-reentrant scanner so the next time
     * yylex() is called, initialization will occur. */
    yy_init_globals( );

/* %if-reentrant */
/* %endif */
    return 0;
}
/* %endif */

/*
 * Internal utility routines.
 */

#ifndef yytext_ptr
static void yy_flex_strncpy (char* s1, yyconst char * s2, int n )
{
		
	int i;
	for ( i = 0; i < n; ++i )
		s1[i] = s2[i];
}
#endif

#ifdef YY_NEED_STRLEN
static int yy_flex_strlen (yyconst char * s )
{
	int n;
	for ( n = 0; s[n]; ++n )
		;

	return n;
}
#endif

void *yyalloc (yy_size_t  size )
{
			return (void *) malloc( size );
}

void *yyrealloc  (void * ptr, yy_size_t  size )
{
		
	/* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */
	return (void *) realloc( (char *) ptr, size );
}

void yyfree (void * ptr )
{
			free( (char *) ptr );	/* see yyrealloc() for (char *) cast */
}

/* %if-tables-serialization definitions */
/* %define-yytables   The name for this specific scanner's tables. */
#define YYTABLES_NAME "yytables"
/* %endif */

/* %ok-for-header */

#line 38 "lex.l"



void parsefile(const char * file, int lines)
{
	yyin = fopen(file, "r");
	#ifdef __CCR__
	// for files created on C Mobile the first 3 bytes of the file are unknown and cannot be represented in printable ascii, we skip those
	fseek(yyin, 3, SEEK_SET );
	#endif
	int token, vtok;
	token = yylex();
	int keepgoing = 1;
    while (keepgoing) {
		printf("token line = %d", line);
		if (line > lines) { keepgoing = 0; break;}
		switch(token) {
			case shvar: printf(", variable: \"%s\"", yytext); break;
			case sharray: printf(", array: \"%s\"", yytext); break;
			case shcommandsubstitution: printf(", shcommandsubstitution: \"%s\"", yytext); break;
			case shident: printf(", identifier: \"%s\"", yytext); break;
			case shand: printf(", AND: \"%s\"", yytext);  break;
			case shcommand: printf(", command: \"%s\"", yytext); break;
			case shcommand2: printf(", command: \"<new-line>\""); break;
			case shfunction: printf(", function: \"%s\"\n", yytext); break;
			case EOF: keepgoing = 0; break;
		}
    	printf(", token = %d (%s)\n", token, yytext);
    	token = yylex();
    }
	fclose(yyin);
}

int main()
{
	parsefile("../regex/test.sh", 6);
	return 1;
}
