<h1>Lemonex</h1>

Originally ported from what is believed to be https://sqlite.org/src/vinfo?name=5b295897153e9b26 version of the sqlite repository tree, Lemonex is an extension to the lemon parser, developed to include a builtin lexer.

SQLite's documentation for Lemon can be found here:
* https://www.hwaci.com/sw/lemon/lemon.html (current)
* https://sqlite.org/src/raw/doc/lemon.html?name=ac63db056bce24b7368e29319cd1a7eb5f1798cc85922d96a80b6c3a4ff9f51b (https://sqlite.org/src/vinfo?name=5b295897153e9b26)

Updated by me, mgood7123, in an attempt to port the most current version of lemon to this version of lemonlex (as far as my understanding of the integrated lexer and lemon itself goes).

i did try to port lemonlex to the current lemon (https://github.com/mgood7123/lemonlex/tree/master/lemon) but that failed:
```
GNU gdb (Ubuntu 8.1-0ubuntu3) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
pwndbg: loaded 168 commands. Type pwndbg [filter] for a list.
pwndbg: created $rebase, $ida gdb functions (can be used with print/break)
Reading symbols from p/parse...done.
pwndbg> r
Starting program: /home/mobile_c/git/lemonlex/lemon/p/parse 
Failed to connect to IDA Pro (ConnectionResetError: [Errno 104] Connection reset by peer)
For more info invoke `set exception-verbose on`
To disable IDA Pro integration invoke `set ida-enabled off`
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
*****CREATE_TOKEN:(1,1)
L0:1
S1(1,2):0x68(h)
S2(1,3):0x69(i)
Recieved EOF
*****FINALIZE_TOKEN(0,0):(null)
lemon debug: Input EOF
lemon debug: Shift 1
lemon debug: Stack: EOF
lemon debug: Return
*****CREATE_TOKEN:(1,3)
S1(1,3):0x69(i)
S2(1,4):0x2F(/)
Recieved EOF
*****FINALIZE_TOKEN(1,3):(null)
lemon debug: Input EOF
parse: p/p.c:1352: yy_find_reduce_action: Assertion `stateno<=YY_REDUCE_COUNT' failed.

Program received signal SIGABRT, Aborted.
__GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:51
51      ../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
LEGEND: STACK | HEAP | CODE | DATA | RWX | RODATA
────────────────────────────────────────[ REGISTERS ]────────────────────────────────────────
 RAX  0x0
 RBX  0x0
 RCX  0x7ffff781be97 (raise+199) ◂— mov    rcx, qword ptr [rsp + 0x108]
 RDX  0x0
 RDI  0x2
 RSI  0x7fffffffd820 ◂— 0x0
 R8   0x0
 R9   0x7fffffffd820 ◂— 0x0
 R10  0x8
 R11  0x246
 R12  0x555555557db7 ◂— jo     0x555555557de8 /* 'p/p.c' */
 R13  0x555555557ee3 ◂— jae    0x555555557f59
 R14  0x548
 R15  0x0
 RBP  0x7ffff79947d8 ◂— and    eax, 0x25732573
 RSP  0x7fffffffd820 ◂— 0x0
 RIP  0x7ffff781be97 (raise+199) ◂— mov    rcx, qword ptr [rsp + 0x108]
─────────────────────────────────────────[ DISASM ]──────────────────────────────────────────
 ► 0x7ffff781be97 <raise+199>    mov    rcx, qword ptr [rsp + 0x108] <0x7ffff781be97>
   0x7ffff781be9f <raise+207>    xor    rcx, qword ptr fs:[0x28]
   0x7ffff781bea8 <raise+216>    mov    eax, r8d
   0x7ffff781beab <raise+219>    jne    raise+252 <0x7ffff781becc>
    ↓
   0x7ffff781becc <raise+252>    call   __stack_chk_fail <0x7ffff7911c80>
 
   0x7ffff781bed1                nop    word ptr cs:[rax + rax]
   0x7ffff781bedb                nop    dword ptr [rax + rax]
   0x7ffff781bee0 <killpg>       test   edi, edi
   0x7ffff781bee2 <killpg+2>     js     killpg+16 <0x7ffff781bef0>
 
   0x7ffff781bee4 <killpg+4>     neg    edi
   0x7ffff781bee6 <killpg+6>     jmp    kill <0x7ffff781c180>
──────────────────────────────────────────[ STACK ]──────────────────────────────────────────
00:0000│ rsi r9 rsp  0x7fffffffd820 ◂— 0x0
01:0008│             0x7fffffffd828 —▸ 0x55555575e8a0 ◂— 0x0
02:0010│             0x7fffffffd830 ◂— 0x0
03:0018│             0x7fffffffd838 —▸ 0x7ffff78655e0 (vasprintf+240) ◂— test   rax, rax
04:0020│             0x7fffffffd840 ◂— 0xfbad8000
05:0028│             0x7fffffffd848 —▸ 0x55555575e8a0 ◂— 0x0
... ↓
────────────────────────────────────────[ BACKTRACE ]────────────────────────────────────────
 ► f 0     7ffff781be97 raise+199
   f 1     7ffff781d801 abort+321
   f 2     7ffff780d39a __assert_fail_base+330
   f 3     7ffff780d412
   f 4     5555555558d2 yy_find_reduce_action+53
   f 5     555555555d47 yy_reduce+359
   f 6     555555556036 Parse+316
   f 7     55555555668d ParseRead+760
   f 8     555555557b19 main+163
   f 9     7ffff77feb97 __libc_start_main+231
Program received signal SIGABRT
pwndbg> bt
#0  __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:51
#1  0x00007ffff781d801 in __GI_abort () at abort.c:79
#2  0x00007ffff780d39a in __assert_fail_base (fmt=0x7ffff79947d8 "%s%s%s:%u: %s%s"..., assertion=assertion@entry=0x555555557ee3 "stateno<=YY_RED"..., file=file@entry=0x555555557db7 "p/p.c", line=line@entry=1352, function=function@entry=0x5555555582e0 <__PRETTY_FUNCTION__.3106> "yy_find_reduce_"...) at assert.c:92
#3  0x00007ffff780d412 in __GI___assert_fail (assertion=0x555555557ee3 "stateno<=YY_RED"..., file=0x555555557db7 "p/p.c", line=1352, function=0x5555555582e0 <__PRETTY_FUNCTION__.3106> "yy_find_reduce_"...) at assert.c:101
#4  0x00005555555558d2 in yy_find_reduce_action (stateno=64, iLookAhead=102 'f') at p/p.c:1352
#5  0x0000555555555d47 in yy_reduce (yypParser=0x55555575d260, yyruleno=-3) at p/p.c:2748
#6  0x0000555555556036 in Parse (yyp=0x55555575d260, yymajor=3, yyminor=...) at p/p.c:2889
#7  0x000055555555668d in ParseRead (yyp=0x55555575d260, buf=0x555555558284 "hi/*", buf_end=0x555555558288 "", is_final=1) at p/p.c:3077
#8  0x0000555555557b19 in main (argc=1, argv=0x7fffffffdd98) at ./p.y:41
#9  0x00007ffff77feb97 in __libc_start_main (main=0x555555557a76 <main>, argc=1, argv=0x7fffffffdd98, init=<optimised out>, fini=<optimised out>, rtld_fini=<optimised out>, stack_end=0x7fffffffdd88) at ../csu/libc-start.c:310
#10 0x00005555555549aa in _start ()
pwndbg> 
```

included is lemon_original.c and lempar_original.c, the files wich i believe this is based upon, directly from https://sqlite.org/src/vinfo?name=5b295897153e9b26

among the updates are:

* updated testall.sh (https://github.com/mgood7123/lemonlex/tree/master/testall.sh) so it now correctly preforms the tests, where is before linux was not correctly detected, and contains tests for my changes to the lexer
* additions to lemon
	* alot
* bug fixes in lemon
	* -d option now working correctly and can correctly handle more path cases
	* slightly more meaningfull debug output
	* -m now generates a header file, and excludes the generated defines from the generated parser as they are generated in the header file instead
	* nesting now works correctly, handling of $$.buf is not recursive safe yet but can be worked around by reparsing $$.buf that contains the nest token, and defining the nest token in the main symbol
* lemon now handles 
	* %token directive
	* $variables, $arrays[], and $functions(), in which these are specified after ::= directive, and thus $ is added to the "Expected ..." message where appropriate, ALL variables/arrays/functions must result in type [char *], eg char ** a; char * aa();char * aaa;  $a[0] $aa(), $aaa, NOTE: supports $"" since technically a string literal is a char * but it quotes them instead, resulting in ::= $"P" == ::= "\"P\"", it is undecided whether i should keep this behavour or not
* new definitions in lexer
	* LX_NESTMAX and LX_NESTLEVEL definitions
	* LX_REPARSE, alias for ParseReadString, accepts only a string as the first argument for easier readability, eg LX_REPARSE("hi"); vs ParseReadString("hi, "<string>", "DEBUG:");
* a re-structured template (https://github.com/mgood7123/lemonlex/tree/master/lempar.c)
	* function prototypes that are needed for internal functions can now be added, these are inserted BEFORE any %include code is generated
	* control defines are inserted and generated BEFORE function prototypes instead of after %include code, as these are needed by internal functions
	* after-include %include code is inserted BEFORE control defines instead of after %include code
	* assert.h and stdlib inserted due to the template requiring assert(), malloc() and free()
	* nesting definitions are included BEFORE function prototypes
* lex folder (https://github.com/mgood7123/lemonlex/tree/master/lex)
	* this is the guts of the builtin lexer that i have seperated from lemon.c (https://github.com/mgood7123/lemonlex/tree/master/lemon.c) to make it easier to work with and easier to add or remove stuff instead of scrolling though thousands of lines to find code related to the lexer, all of the lexer code is now all in this folder
	* (i attempted to do the same to lempar (lempar_include.c) but unfortunatly that gets probogated to the generated parser and thus the files would need to be copied to where-ever the user outputs the generated parser to in order for it to compile which would be too much work)
* binary folder (https://github.com/mgood7123/lemonlex/tree/master/binary)
	* this is where binary executables get stored
* example folder (https://github.com/mgood7123/lemonlex/tree/master/example)
	* this contains example programs that demonstrates some of lemonex's features, including the ability to recursively parse aswell as nested parsing
* defgen (https://github.com/mgood7123/lemonlex/tree/master/binary/defgen)
	* this is a handmade definitions generator for lemon to aid with making conditional include files and statements
	* defgen works by traversing ./lex and generating a list of inclue files recursively then generates a list of #defines covering all generated files, ultimately producing a ./lex.h file that includes ./lex/lexdefines.h
	* It also produces a shell compatible log (to stdout) in order to reproduce the generated definition files, it is not recommended to use this log as it is dependant on the structure of the lex folder remaining more or less the same and will not update if any new folders or files are added
	* files generated by defgen reside in ./lex/path/to/folder_name.h
	* folders can have multiple sub directories and files
	* a custom include file MUST NOT be the name of any folders in its current directory
	* it is recomended to always run defgen after making changes such as a new folder or file, in order to generate conditional defines for new/removed folders or files
	* it IS NOT recommended to rename any folders unless you know what you are doing, look in lemon.c for information about the current definitions ( grep ifdef\ lex_lemon lemon.c)
	* as of writing, the contents of lex are as follows (generated by tree)
	
```
$ tree lex
lex
├── lemon
│   ├── emit_destructor_code
│   │   ├── if
│   │   │   └── include.h
│   │   └── if.h
│   ├── enum
│   │   ├── e_state
│   │   │   └── include.h
│   │   └── e_state.h
│   ├── file_makename
│   │   └── include.h
│   ├── file_makename.h
│   ├── handle_d_option
│   │   └── include.h
│   ├── handle_d_option.h
│   ├── has_destructor
│   │   ├── if
│   │   │   └── include.h
│   │   └── if.h
│   ├── ifdef
│   │   └── __WIN32__
│   │       ├── else
│   │       │   └── include.h
│   │       └── else.h
│   ├── include.h
│   ├── main
│   │   ├── part_1
│   │   │   └── include.h
│   │   ├── part_1.h
│   │   ├── part_2
│   │   │   └── include.h
│   │   ├── part_2.h
│   │   └── struct
│   │       └── s_options
│   │           ├── options
│   │           │   └── include.h
│   │           └── options.h
│   ├── middle
│   │   └── include.h
│   ├── middle.h
│   ├── Parse
│   │   ├── for
│   │   │   ├── if
│   │   │   │   └── include.h
│   │   │   └── if.h
│   │   └── include.h
│   ├── Parse.h
│   ├── parseonetoken
│   │   ├── switch
│   │   │   ├── INITIALIZE
│   │   │   │   └── include.h
│   │   │   ├── INITIALIZE.h
│   │   │   ├── lemon_additions
│   │   │   │   └── include.h
│   │   │   ├── lemon_additions.h
│   │   │   ├── lexer_additions
│   │   │   │   └── include.h
│   │   │   ├── lexer_additions.h
│   │   │   ├── WAITING_FOR_CLASS_TOKEN.h
│   │   │   ├── WAITING_FOR_DECL_KEYWORD
│   │   │   │   ├── lemon.h
│   │   │   │   └── lexer.h
│   │   │   ├── WAITING_FOR_DECL_KEYWORD.h
│   │   │   ├── WAITING_FOR_DECL_OR_RULE
│   │   │   │   ├── else
│   │   │   │   │   └── if
│   │   │   │   │       ├── ISLOWER
│   │   │   │   │       │   └── include.h
│   │   │   │   │       ├── ISLOWER.h
│   │   │   │   │       └── x
│   │   │   │   │           └── equal_to
│   │   │   │   │               ├── rounded_bracket
│   │   │   │   │               │   └── include.h
│   │   │   │   │               ├── rounded_bracket.h
│   │   │   │   │               ├── square_bracket
│   │   │   │   │               │   └── include.h
│   │   │   │   │               └── square_bracket.h
│   │   │   │   └── include.h
│   │   │   └── WAITING_FOR_DECL_OR_RULE.h
│   │   └── switch.h
│   ├── print_stack_union
│   │   └── include.h
│   ├── print_stack_union.h
│   ├── ReportTable
│   │   ├── else
│   │   │   └── include.h
│   │   ├── else.h
│   │   ├── if
│   │   │   └── include.h
│   │   ├── if.h
│   │   ├── include.h
│   │   └── step
│   │       ├── 1
│   │       │   └── include.h
│   │       ├── 1.h
│   │       ├── 2
│   │       │   └── include.h
│   │       ├── 2.h
│   │       ├── 3
│   │       │   └── include.h
│   │       ├── 3.h
│   │       ├── 4
│   │       │   └── include.h
│   │       ├── 4.h
│   │       ├── 5
│   │       │   └── include.h
│   │       ├── 5.h
│   │       ├── functions
│   │       │   └── include.h
│   │       └── functions.h
│   ├── ReportTable.h
│   ├── struct
│   │   ├── lemon
│   │   │   └── include.h
│   │   ├── lemon.h
│   │   ├── pstate
│   │   │   └── include.h
│   │   ├── pstate.h
│   │   ├── symbol
│   │   │   └── include.h
│   │   └── symbol.h
│   ├── Symbol_New
│   │   ├── if
│   │   │   └── include.h
│   │   └── if.h
│   ├── top
│   │   └── include.h
│   └── top.h
├── lemon.h
├── lempar
│   └── section
│       ├── 1
│       │   └── include.h
│       ├── 13
│       │   └── include.h
│       ├── 13.h
│       ├── 1.h
│       ├── 2
│       │   └── include.h
│       ├── 2.h
│       ├── 3
│       │   └── include.h
│       ├── 3.h
│       ├── 5
│       │   └── include.h
│       ├── 5.h
│       ├── 7
│       │   └── include.h
│       ├── 7.h
│       ├── 8
│       │   └── include.h
│       └── 8.h
└── lexdefines.h

63 directories, 90 files
```

This is the git repository. If you prefer fossil, use this: https://chiselapp.com/user/renjipanicker/repository/lemonex/home

The following is a minimal example:

```
%include {
#include <assert.h>
#include <stdlib.h>
#include <string.h>
}

%start_symbol rModule
rModule ::= URL EOL.
EOL ::= "\n".
URL ::= "(http|ftp)://([^/\n]+)(/[^\n]*)?".

%code {
int main(int argc, char* argv[]) {
  int rc = ParseReadString("http://www.google.co.in/mail/index.html\n", "<string>", "DBG_PREFIX:"); \
  if(rc != 0){
    printf("Error\n");
    return 1;
  }
  printf("Success\n");
  return 0;
}
}
```

<h2>Symbol definition</h2>
Lemonex automatically matches the symbol on the LHS to any symbol of the same name defined in the grammar. It generates warning on symbols that do not have a regex defined.
Any regex that does not have a symbol in the grammar is ignored. This is useful for comments, whitespace, etc.

<h2>Integration</h2>
The lexer can be invoked in 2 ways:

* Standalone: In this mode, the lexer is created and invoked as an independent object, just like the parser.
* Integrated: In this mode, the lexer is automatically created when the parser is created.

The integration mode is defined using %lexer_integration (values are ON or OFF).

<h2>Wrapper functions</h2>
Lemon provides 2 wrapper functions, for reading strings and files respectively. These functions wrap the lexer and parser conveniently. These functions are:

* ParseReadString()
* ParseReadFile()

where Parse is replaced by the prefix specified by %name

<h2>Lexer modes</h2>
It can work in multiple lexer modes. The modes are defined by the %lexer_mode command, as follows:

```
%start_symbol rModule
rModule ::= URL EOL.
EOL ::= "\n".
URL ::= "(http|ftp)://([^/\n]+)(/[^\n]*)?".
ENTER_MLCOMMENT ::= "/\*". [MLCOMMENT]

%lexer_mode MLCOMMENT.
ENTER_MLCOMMENT ::= "/\*". [MLCOMMENT]
LEAVE_MLCOMMENT ::= "\*/". [<]
WS ::= ".*".
```

The lexer starts in the first mode which has been defined. If no mode was explicitly defined, a default mode named INITMODE is created.

In the example above, ENTER_MLCOMMENT is a pseudo-symbol (not defined in the grammar), which causes the lexer to switch to MLCOMMENT mode when it reads a /* on the input stream.

In MLCOMMENT mode, if it sees another /* it recursively enters the same mode. If it sees a */, it returns to the previous mode, specified by <

This makes handling of nested multiline comments easy.
The nesting depth is defined using %lexer_nestingdepth, with a default value of 32.

<h2>Regular expressions</h2>
Lemonex works with a subset of the regular expression syntax. It can handle *, + and ? operators, as well as [] for defining classes, and () for grouping.

Further, Lemonex supports limited capture functionality. for example:

```
STRING ::= !"'" ".*" !"'".
```

This defines a string defined within single quotes. The single quotes are defined separately, prefixed with an exclamation indicating that it should be added to the captured text.

Lemonex has a limitation, in that the capture definition cannot overlap. For example:

```
STRING1 ::= !"'" "ABC" !"'".
STRING2 ::=  "'" "DEF"  "'".
```

This will give an error. Since Lemonex has a lookahead of 1 and cannot backtrack, it cannot go back and re-capture the quote when it realises that the input will not match STRING1.

<h2>Regular expression classes</h2>
It can handle a few classes such as:

* \l (letters)
* \d (digits)
* \s (spaces, tabs)

<h2>Regular expression loop exit</h2>
Lemonex has two mechanisms for breaking out of * loops.

For regular expressions that end with a dot-star, such as:

```
EOL ::= "?".
STRING ::=  "ABC.*".
WS ::= " ".
```

It will read the input ABC, and then keep reading characters until it finds either a ? or a space. That is, until it finds any character that starts another symbol in the current mode.

Whereas for regular expressions that end with a not-star, such as:

```
EOL ::= "?".
STRING ::=  "ABC[^;]*".
WS ::= " ".
```

It will keep reading the input, including any ? or spaces, until it finds a ;

<h2>Default token</h2>
It defines a default token structure called lxToken (defined in lempar.c), which contains the following members:

* filename: the current file name (blank if reading from a string)
* row/col: the row/column - Lemonex can handle newlines and keep row/column counts.
* buf: and the captured token text - by default, Lemonex uses malloc/free to automatically maintain the current capture buffer.

This structure is used by default, but can be overridden by the %token_type directive provided by the lemon parser.

<h2>Default token constructor</h2>
Lemonex has a %token_constructor block, defined as a counterpart to the %token_destructor block.

The function for this block is defined in the lempar.c file, and is used only if the default token is not overridden by %token_type.

This block is called whenever

* a token needs to be initialised
* a character needs to be captured
* and a token needs to be finalised before sending to the parser.

<h2>Action code</h2>
Lemonex supports match actions, code that executes when any symbol is matched. This is similar to the reduce action defined in the grammar. This allows the capture to be modified before it gets sent to the parser. For example:

```
WORD ::= "[\r\n\t ]+". {$$.buf[0] = ' ';$$.buf[1] = 0;}
```

This code converts any whitespace character including newlines, to a single space before getting sent to the parser.

<h2>Lexer code</h2>
Lemon allows one to define a code block using %lexer_code. This is similar to the %code block, expect that it gets generated between the parser and lexer in the output file.

This allows one to define function and other constructs that can be accessed from the lexer, and which can in turn access constructs defined as a part of the parser.

<h2>Unicode handling</h2>
Lemonex can handle UTF8 natively. For example:

```
rModule ::= HINDI_WORD JAPANESE_WORD EOL.
EOL  ::= "[\.\!\?]".
HINDI_WORD ::= "आप".
JAPANESE_WORD ::= "なか".
WS ::= " ".
```

Lemonex has full support for Unicode letter, digit and space character classes.

<h2>Miscellaneous</h2>

* Totally unrelated to lexing, lemonex allows to specify the output directory(-d) and extention(-e). This eases the usage in project files where a .cpp file is required, within a specific output directory.

<h2>Technical information</h2>
Lemonex has a lookahead of 1, with fail state.

It starts with an empty DFA, and works in 3 stages: preprocess, process, and postprocess.
* In the preprocess stage, it converts the input regex string to an intermediate AST (See grammar here [ASTGrammar])
* In the process stage, it traverses the AST recursively, adding states and transitions to the DFA.
* In the postprocess stage, it traverses the DFA and adds fail states to each state.

The lexer extension feature is enabled in the code by #defining LEMONEX to 1

Lemonex has 3 debug levels - 0, 1 and 2, indicating increasing levels of debug info that gets generated. This is defined in the LEMONEX_DBG preprocessor variable in lemon.c.

In LEMONEX mode, the error token is always enabled, and used on lexer error.

Lemonex has been developed against the most recent commit on sqlite3 trunk as of 22nd June 2015.

<h2>Contact</h2>
Any feedback, comments, suggestions will be gratefully accepted and worked on. Drop me a note at renjipanicker@gmail.com
