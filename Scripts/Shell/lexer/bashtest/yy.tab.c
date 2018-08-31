/* compiling yacc file

Usage: /usr/bin/bison [OPTION]... FILE
Generate a deterministic LR or generalized LR (GLR) parser employing
LALR(1), IELR(1), or canonical LR(1) parser tables.  IELR(1) and
canonical LR(1) support is experimental.

Mandatory arguments to long options are mandatory for short options too.
The same is true for optional arguments.

Operation modes:
  -h, --help                 display this help and exit
  -V, --version              output version information and exit
      --print-localedir      output directory containing locale-dependent data
      --print-datadir        output directory containing skeletons and XSLT
  -y, --yacc                 emulate POSIX Yacc
  -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY
  -f, --feature[=FEATURE]    activate miscellaneous features

Parser:
  -L, --language=LANGUAGE          specify the output programming language
  -S, --skeleton=FILE              specify the skeleton to use
  -t, --debug                      instrument the parser for tracing
                                   same as '-Dparse.trace'
      --locations                  enable location support
  -D, --define=NAME[=VALUE]        similar to '%define NAME "VALUE"'
  -F, --force-define=NAME[=VALUE]  override '%define NAME "VALUE"'
  -p, --name-prefix=PREFIX         prepend PREFIX to the external symbols
                                   deprecated by '-Dapi.prefix=PREFIX'
  -l, --no-lines                   don't generate '#line' directives
  -k, --token-table                include a table of token names

Output:
      --defines[=FILE]       also produce a header file
  -d                         likewise but cannot specify FILE (for POSIX Yacc)
  -r, --report=THINGS        also produce details on the automaton
      --report-file=FILE     write report to FILE
  -v, --verbose              same as '--report=state'
  -b, --file-prefix=PREFIX   specify a PREFIX for output files
  -o, --output=FILE          leave output to FILE
  -g, --graph[=FILE]         also output a graph of the automaton
  -x, --xml[=FILE]           also output an XML report of the automaton
                             (the XML schema is experimental)

Warning categories include:
  'midrule-values'    unset or unused midrule values
  'yacc'              incompatibilities with POSIX Yacc
  'conflicts-sr'      S/R conflicts (enabled by default)
  'conflicts-rr'      R/R conflicts (enabled by default)
  'deprecated'        obsolete constructs
  'empty-rule'        empty rules without %empty
  'precedence'        useless precedence and associativity
  'other'             all other warnings (enabled by default)
  'all'               all the warnings except 'yacc'
  'no-CATEGORY'       turn off warnings in CATEGORY
  'none'              turn off all the warnings
  'error[=CATEGORY]'  treat warnings as errors

THINGS is a list of comma separated words that can include:
  'state'        describe the states
  'itemset'      complete the core item sets with their closure
  'lookahead'    explicitly associate lookahead tokens to items
  'solved'       describe shift/reduce conflicts solving
  'all'          include all the above information
  'none'         disable the report

FEATURE is a list of comma separated words that can include:
  'caret'        show errors with carets
  'all'          all of the above
  'none'         disable all of the above
  
Report bugs to <bug-bison@gnu.org>.
GNU Bison home page: <http://www.gnu.org/software/bison/>.
General help using GNU software: <http://www.gnu.org/gethelp/>.
Report translation bugs to <http://translationproject.org/team/>.
For complete documentation, run: info bison.

yacc.y: warning: 1 shift/reduce conflict [-Wconflicts-sr]

total 452K
-rw-r--r-- 1 2001 2000    0 May 16 15:57 bashansi.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 bashintl.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 bashtypes.h
drwxr-xr-x 2 2001 2000 4.0K May 16 15:57 builtins
-rw-r--r-- 1 2001 2000    0 May 16 15:57 builtins.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 chartypes.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 config.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 filecntl.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 flags.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 mailcheck.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 memalloc.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 parser.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 shell.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 shmbutil.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 stdc.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 test.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 trap.h
-rw-r--r-- 1 2001 2000    0 May 16 15:57 typemax.h
-rw-r--r-- 1 2001 2000 258K May 16 15:57 y.tab.c
-rw-rw-rw- 1 2001 2000 178K May 16 15:57 yacc.y

yacc.y:129:8: error: unknown type name 'sh_builtin_func_t'
 extern sh_builtin_func_t *last_shell_builtin, *this_shell_builtin;
        ^~~~~~~~~~~~~~~~~
In file included from /usr/include/features.h:367,
                 from /usr/include/stdio.h:27,
                 from yacc.y:37:
yacc.y:175:31: error: unknown type name 'REDIRECT'
 static void push_heredoc __P((REDIRECT *));
                               ^~~~~~~~
yacc.y:232:24: error: 'PPROMPT' undeclared here (not in a function)
 char *primary_prompt = PPROMPT;
                        ^~~~~~~
yacc.y:233:26: error: 'SPROMPT' undeclared here (not in a function)
 char *secondary_prompt = SPROMPT;
                          ^~~~~~~
yacc.y:277:8: error: unknown type name 'REDIRECT'
 static REDIRECT *redir_stack[HEREDOC_MAX];
        ^~~~~~~~
yacc.y:277:30: error: 'HEREDOC_MAX' undeclared here (not in a function)
 static REDIRECT *redir_stack[HEREDOC_MAX];
                              ^~~~~~~~~~~
yacc.y:327:8: error: unknown type name 'WORD_DESC'
 static WORD_DESC *word_desc_to_read;
        ^~~~~~~~~
yacc.y:329:8: error: unknown type name 'REDIRECTEE'
 static REDIRECTEE source;
        ^~~~~~~~~~
yacc.y:330:8: error: unknown type name 'REDIRECTEE'
 static REDIRECTEE redir;
        ^~~~~~~~~~
yacc.y:334:3: error: unknown type name 'WORD_DESC'
   WORD_DESC *word;  /* the word that we read. */
   ^~~~~~~~~
yacc.y:336:3: error: unknown type name 'WORD_LIST'
   WORD_LIST *word_list;
   ^~~~~~~~~
yacc.y:337:3: error: unknown type name 'COMMAND'
   COMMAND *command;
   ^~~~~~~
yacc.y:338:3: error: unknown type name 'REDIRECT'
   REDIRECT *redirect;
   ^~~~~~~~
yacc.y:339:3: error: unknown type name 'ELEMENT'
   ELEMENT element;
   ^~~~~~~
yacc.y:340:3: error: unknown type name 'PATTERN_LIST'
   PATTERN_LIST *pattern;
   ^~~~~~~~~~~~
yacc.y: In function 'yyparse':
yacc.y:390:6: error: 'global_command' undeclared (first use in this function); did you mean 'global_extglob'?
      global_command = $1;
      ^~~~~~~~~~~~~~
      global_extglob
yacc.y:390:6: note: each undeclared identifier is reported only once for each function it appears in
yacc.y:393:25: error: 'PST_CMDSUBST' undeclared (first use in this function)
      if (parser_state & PST_CMDSUBST)
                         ^~~~~~~~~~~~
yacc.y:394:24: error: 'PST_EOFTOKEN' undeclared (first use in this function)
        parser_state |= PST_EOFTOKEN;
                        ^~~~~~~~~~~~
yacc.y:401:24: error: 'COMMAND' undeclared (first use in this function)
      global_command = (COMMAND *)NULL;
                        ^~~~~~~
yacc.y:401:33: error: expected expression before ')' token
      global_command = (COMMAND *)NULL;
                                 ^
yacc.y:409:33: error: expected expression before ')' token
      global_command = (COMMAND *)NULL;
                                 ^
yacc.y:412:10: error: 'interactive' undeclared (first use in this function)
      if (interactive && parse_and_execute_level == 0)
          ^~~~~~~~~~~
yacc.y:425:33: error: expected expression before ')' token
      global_command = (COMMAND *)NULL;
                                 ^
yacc.y:432:27: warning: implicit declaration of function 'make_word_list' [-Wimplicit-function-declaration]
    { $$ = make_word_list ($1, (WORD_LIST *)NULL); }
                           ^~~~~~~~~~~~~~
yacc.y:432:61: error: 'WORD_LIST' undeclared (first use in this function)
    { $$ = make_word_list ($1, (WORD_LIST *)NULL); }
                                                             ^        
yacc.y:432:72: error: expected expression before ')' token
    { $$ = make_word_list ($1, (WORD_LIST *)NULL); }
                                                                        ^
yacc.y:434:25: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_word_list ($2, $1); }
                         ^
yacc.y:439:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:440:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:441:25: warning: implicit declaration of function 'make_redirection'; did you mean 'sa_sigaction'? [-Wimplicit-function-declaration]
      $$ = make_redirection (source, r_output_direction, redir, 0);
                         ^~~~~~~~~~~~~~~~
                         sa_sigaction
yacc.y:441:51: error: 'r_output_direction' undeclared (first use in this function)
      $$ = make_redirection (source, r_output_direction, redir, 0);
                                                   ^~~~~~~~~~~~~~~~  
yacc.y:445:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:446:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:447:51: error: 'r_input_direction' undeclared (first use in this function)
      $$ = make_redirection (source, r_input_direction, redir, 0);
                                                   ^~~~~~~~~~~~~~~  
yacc.y:451:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:452:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:457:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:458:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:463:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:464:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:465:78: error: 'REDIR_VARASSIGN' undeclared (first use in this function)
      $$ = make_redirection (source, r_output_direction, redir, REDIR_VARASSIGN);
                                                                              ^~~            
yacc.y:469:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:470:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:475:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:476:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:477:51: error: 'r_appending_to' undeclared (first use in this function); did you mean 'sigpending'?
      $$ = make_redirection (source, r_appending_to, redir, 0);
                                                   ^~~~~~~~~~~~  
                                                   sigpending
yacc.y:481:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:482:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:487:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:488:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:493:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:494:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:495:51: error: 'r_output_force' undeclared (first use in this function)
      $$ = make_redirection (source, r_output_force, redir, 0);
                                                   ^~~~~~~~~~~~  
yacc.y:499:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:500:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:505:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:506:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:511:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:512:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:513:51: error: 'r_input_output' undeclared (first use in this function)
      $$ = make_redirection (source, r_input_output, redir, 0);
                                                   ^~~~~~~~~~~~  
yacc.y:517:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:518:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:523:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:524:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:529:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:530:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:531:51: error: 'r_reading_until' undeclared (first use in this function)
      $$ = make_redirection (source, r_reading_until, redir, 0);
                                                   ^~~~~~~~~~~~~  
yacc.y:532:6: warning: implicit declaration of function 'push_heredoc' [-Wimplicit-function-declaration]
      push_heredoc ($$);
      ^~~~~~~~~~~~
yacc.y:536:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:537:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:543:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:544:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:550:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:551:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:552:51: error: 'r_deblank_reading_until' undeclared (first use in this function)
      $$ = make_redirection (source, r_deblank_reading_until, redir, 0);
                                                   ^~~~~~~~~~~~~~~~~~~~~  
yacc.y:557:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:558:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:564:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:565:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:571:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:572:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:573:51: error: 'r_reading_string' undeclared (first use in this function); did you mean 'rewind_input_string'?
      $$ = make_redirection (source, r_reading_string, redir, 0);
                                                   ^~~~~~~~~~~~~~  
                                                   rewind_input_string
yacc.y:577:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:578:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:583:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:584:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:589:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:590:11: error: request for member 'dest' in something not a structure or union
      redir.dest = $2;
           ^
yacc.y:591:51: error: 'r_duplicating_input' undeclared (first use in this function)
      $$ = make_redirection (source, r_duplicating_input, redir, 0);
                                                   ^~~~~~~~~~~~~~~~~  
yacc.y:595:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:596:11: error: request for member 'dest' in something not a structure or union
      redir.dest = $3;
           ^
yacc.y:601:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:602:11: error: request for member 'dest' in something not a structure or union
      redir.dest = $3;
           ^
yacc.y:607:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:608:11: error: request for member 'dest' in something not a structure or union
      redir.dest = $2;
           ^
yacc.y:609:51: error: 'r_duplicating_output' undeclared (first use in this function)
      $$ = make_redirection (source, r_duplicating_output, redir, 0);
                                                   ^~~~~~~~~~~~~~~~~~  
yacc.y:613:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:614:11: error: request for member 'dest' in something not a structure or union
      redir.dest = $3;
           ^
yacc.y:619:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:620:11: error: request for member 'dest' in something not a structure or union
      redir.dest = $3;
           ^
yacc.y:625:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:626:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:627:51: error: 'r_duplicating_input_word' undeclared (first use in this function)
      $$ = make_redirection (source, r_duplicating_input_word, redir, 0);
                                                   ^~~~~~~~~~~~~~~~~~~~~~  
yacc.y:631:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:632:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:637:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:638:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:643:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:644:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:645:51: error: 'r_duplicating_output_word' undeclared (first use in this function)
      $$ = make_redirection (source, r_duplicating_output_word, redir, 0);
                                                   ^~~~~~~~~~~~~~~~~~~~~~~  
yacc.y:649:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:650:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:655:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:656:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $3;
           ^
yacc.y:661:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:662:11: error: request for member 'dest' in something not a structure or union
      redir.dest = 0;
           ^
yacc.y:663:51: error: 'r_close_this' undeclared (first use in this function)
      $$ = make_redirection (source, r_close_this, redir, 0);
                                                   ^~~~~~~~~~  
yacc.y:667:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:668:11: error: request for member 'dest' in something not a structure or union
      redir.dest = 0;
           ^
yacc.y:673:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:674:11: error: request for member 'dest' in something not a structure or union
      redir.dest = 0;
           ^
yacc.y:679:12: error: request for member 'dest' in something not a structure or union
      source.dest = 0;
            ^
yacc.y:680:11: error: request for member 'dest' in something not a structure or union
      redir.dest = 0;
           ^
yacc.y:685:12: error: request for member 'dest' in something not a structure or union
      source.dest = $1;
            ^
yacc.y:686:11: error: request for member 'dest' in something not a structure or union
      redir.dest = 0;
           ^
yacc.y:691:12: error: request for member 'filename' in something not a structure or union
      source.filename = $1;
            ^
yacc.y:692:11: error: request for member 'dest' in something not a structure or union
      redir.dest = 0;
           ^
yacc.y:697:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:698:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:699:51: error: 'r_err_and_out' undeclared (first use in this function)
      $$ = make_redirection (source, r_err_and_out, redir, 0);
                                                   ^~~~~~~~~~~  
yacc.y:703:12: error: request for member 'dest' in something not a structure or union
      source.dest = 1;
            ^
yacc.y:704:11: error: request for member 'filename' in something not a structure or union
      redir.filename = $2;
           ^
yacc.y:705:51: error: 'r_append_err_and_out' undeclared (first use in this function)
      $$ = make_redirection (source, r_append_err_and_out, redir, 0);
                                                   ^~~~~~~~~~~~~~~~~~  
yacc.y:710:22: error: request for member 'word' in something not a structure or union
    { $$.word = $1; $$.redirect = 0; }
                      ^
yacc.y:710:62: error: request for member 'redirect' in something not a structure or union
    { $$.word = $1; $$.redirect = 0; }
                                                              ^
yacc.y:712:22: error: request for member 'word' in something not a structure or union
    { $$.word = $1; $$.redirect = 0; }
                      ^
yacc.y:712:62: error: request for member 'redirect' in something not a structure or union
    { $$.word = $1; $$.redirect = 0; }
                                                              ^
yacc.y:714:22: error: request for member 'redirect' in something not a structure or union
    { $$.redirect = $1; $$.word = 0; }
                      ^
yacc.y:714:70: error: request for member 'word' in something not a structure or union
    { $$.redirect = $1; $$.word = 0; }
                                                                      ^
yacc.y:723:15: error: unknown type name 'REDIRECT'
      register REDIRECT *t;
               ^~~~~~~~
yacc.y:725:38: error: request for member 'next' in something not a structure or union
      for (t = $1; t->next; t = t->next)
                                      ^~
yacc.y:725:51: error: request for member 'next' in something not a structure or union
      for (t = $1; t->next; t = t->next)
                                                   ^ 
yacc.y:727:7: error: request for member 'next' in something not a structure or union
      t->next = $2;
       ^~
yacc.y:733:25: warning: implicit declaration of function 'make_simple_command' [-Wimplicit-function-declaration]
    { $$ = make_simple_command ($1, (COMMAND *)NULL); }
                         ^~~~~~~~~~~~~~~~~~~
yacc.y:733:76: error: expected expression before ')' token
    { $$ = make_simple_command ($1, (COMMAND *)NULL); }
                                                                            ^
yacc.y:735:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_simple_command ($2, $1); }
                       ^
yacc.y:739:25: warning: implicit declaration of function 'clean_simple_command' [-Wimplicit-function-declaration]
    { $$ = clean_simple_command ($1); }
                         ^~~~~~~~~~~~~~      
yacc.y:739:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = clean_simple_command ($1); }
                       ^
yacc.y:744:15: error: 'tc' undeclared (first use in this function)
      COMMAND *tc;
               ^~
yacc.y:749:19: error: unknown type name 'REDIRECT'
          register REDIRECT *t;
                   ^~~~~~~~
yacc.y:750:35: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                   ^~
yacc.y:750:48: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                                ^~
yacc.y:752:11: error: request for member 'next' in something not a structure or union
          t->next = $2;
           ^~
yacc.y:769:25: warning: implicit declaration of function 'make_while_command' [-Wimplicit-function-declaration]
    { $$ = make_while_command ($2, $4); }
                         ^~~~~~~~~~~~~~~~  
yacc.y:769:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_while_command ($2, $4); }
                       ^
yacc.y:771:25: warning: implicit declaration of function 'make_until_command' [-Wimplicit-function-declaration]
    { $$ = make_until_command ($2, $4); }
                         ^~~~~~~~~~~~~~~~  
yacc.y:771:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_until_command ($2, $4); }
                       ^
yacc.y:790:24: warning: implicit declaration of function 'make_for_command' [-Wimplicit-function-declaration]
      $$ = make_for_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                        ^~~~~~~~~~~~~~~~
yacc.y:790:60: warning: implicit declaration of function 'add_string_to_list'; did you mean 'yy_string_unget'? [-Wimplicit-function-declaration]
      $$ = make_for_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                                                            ^~~~~~~~~~~~~~~~~~
                                                            yy_string_unget
yacc.y:790:102: error: expected expression before ')' token
      $$ = make_for_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                                                                                                      ^
yacc.y:795:102: error: expected expression before ')' token
      $$ = make_for_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                                                                                                      ^
yacc.y:800:102: error: expected expression before ')' token
      $$ = make_for_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $6, word_lineno[word_top]);
                                                                                                      ^
yacc.y:805:102: error: expected expression before ')' token
      $$ = make_for_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $6, word_lineno[word_top]);
                                                                                                      ^
yacc.y:810:60: warning: implicit declaration of function 'REVERSE_LIST' [-Wimplicit-function-declaration]
      $$ = make_for_command ($2, REVERSE_LIST ($5, WORD_LIST *), $9, word_lineno[word_top]);
                                                            ^~~~~~~~~~~~
yacc.y:810:108: error: expected expression before ')' token
      $$ = make_for_command ($2, REVERSE_LIST ($5, WORD_LIST *), $9, word_lineno[word_top]);
                                                                                                            ^
yacc.y:815:108: error: expected expression before ')' token
      $$ = make_for_command ($2, REVERSE_LIST ($5, WORD_LIST *), $9, word_lineno[word_top]);
                                                                                                            ^
yacc.y:820:72: error: expected expression before ')' token
      $$ = make_for_command ($2, (WORD_LIST *)NULL, $8, word_lineno[word_top]);
                                                                        ^
yacc.y:825:72: error: expected expression before ')' token
      $$ = make_for_command ($2, (WORD_LIST *)NULL, $8, word_lineno[word_top]);
                                                                        ^
yacc.y:832:25: warning: implicit declaration of function 'make_arith_for_command' [-Wimplicit-function-declaration]
       $$ = make_arith_for_command ($2, $6, arith_for_lineno);
                         ^~~~~~~~~~~~~~~~~~~~~~
yacc.y:832:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       $$ = make_arith_for_command ($2, $6, arith_for_lineno);
                       ^
yacc.y:837:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       $$ = make_arith_for_command ($2, $6, arith_for_lineno);
                       ^
yacc.y:842:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       $$ = make_arith_for_command ($2, $4, arith_for_lineno);
                       ^
yacc.y:847:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       $$ = make_arith_for_command ($2, $4, arith_for_lineno);
                       ^
yacc.y:854:24: warning: implicit declaration of function 'make_select_command' [-Wimplicit-function-declaration]
      $$ = make_select_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                        ^~~~~~~~~~~~~~~~~~~
yacc.y:854:105: error: expected expression before ')' token
      $$ = make_select_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                                                                                                         ^
yacc.y:859:105: error: expected expression before ')' token
      $$ = make_select_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $5, word_lineno[word_top]);
                                                                                                         ^
yacc.y:864:105: error: expected expression before ')' token
      $$ = make_select_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $6, word_lineno[word_top]);
                                                                                                         ^
yacc.y:869:105: error: expected expression before ')' token
      $$ = make_select_command ($2, add_string_to_list ("\"$@\"", (WORD_LIST *)NULL), $6, word_lineno[word_top]);
                                                                                                         ^
yacc.y:874:111: error: expected expression before ')' token
      $$ = make_select_command ($2, REVERSE_LIST ($5, WORD_LIST *), $9, word_lineno[word_top]);
                                                                                                               ^
yacc.y:879:111: error: expected expression before ')' token
      $$ = make_select_command ($2, REVERSE_LIST ($5, WORD_LIST *), $9, word_lineno[word_top]);
                                                                                                               ^
yacc.y:886:24: warning: implicit declaration of function 'make_case_command' [-Wimplicit-function-declaration]
      $$ = make_case_command ($2, (PATTERN_LIST *)NULL, word_lineno[word_top]);
                        ^~~~~~~~~~~~~~~~~
yacc.y:886:62: error: 'PATTERN_LIST' undeclared (first use in this function)
      $$ = make_case_command ($2, (PATTERN_LIST *)NULL, word_lineno[word_top]);
                                                              ^~~~~~~~~~~~
yacc.y:886:76: error: expected expression before ')' token
      $$ = make_case_command ($2, (PATTERN_LIST *)NULL, word_lineno[word_top]);
                                                                            ^
yacc.y:891:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = make_case_command ($2, $5, word_lineno[word_top]);
                      ^
yacc.y:896:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = make_case_command ($2, $5, word_lineno[word_top]);
                      ^
yacc.y:902:25: warning: implicit declaration of function 'make_function_def' [-Wimplicit-function-declaration]
    { $$ = make_function_def ($1, $5, function_dstart, function_bstart); }
                         ^~~~~~~~~~~~~~~~~
yacc.y:902:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_function_def ($1, $5, function_dstart, function_bstart); }
                       ^
yacc.y:905:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_function_def ($2, $6, function_dstart, function_bstart); }
                       ^
yacc.y:908:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_function_def ($2, $4, function_dstart, function_bstart); }
                       ^
yacc.y:933:19: error: unknown type name 'REDIRECT'
          register REDIRECT *t;
                   ^~~~~~~~
yacc.y:934:35: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                   ^~
yacc.y:934:48: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                                ^~
yacc.y:936:11: error: request for member 'next' in something not a structure or union
          t->next = $2;
           ^~
yacc.y:946:24: warning: implicit declaration of function 'make_subshell_command' [-Wimplicit-function-declaration]
      $$ = make_subshell_command ($2);
                        ^~~~~~~~~~~~~~       
yacc.y:946:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = make_subshell_command ($2);
                      ^
yacc.y:947:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_WANT_SUBSHELL;
                     ^~
yacc.y:947:32: error: 'CMD_WANT_SUBSHELL' undeclared (first use in this function)
      $$->flags |= CMD_WANT_SUBSHELL;
                                ^~~~~            
yacc.y:953:24: warning: implicit declaration of function 'make_coproc_command' [-Wimplicit-function-declaration]
      $$ = make_coproc_command ("COPROC", $2);
                        ^~~~~~~~~~~~~~~~~~~
yacc.y:953:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = make_coproc_command ("COPROC", $2);
                      ^
yacc.y:954:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_WANT_SUBSHELL|CMD_COPROC_SUBSHELL;
                     ^~
yacc.y:954:50: error: 'CMD_COPROC_SUBSHELL' undeclared (first use in this function)
      $$->flags |= CMD_WANT_SUBSHELL|CMD_COPROC_SUBSHELL;
                                                  ^~~~~~~            
yacc.y:963:19: error: unknown type name 'REDIRECT'
          register REDIRECT *t;
                   ^~~~~~~~
yacc.y:964:35: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                   ^~
yacc.y:964:48: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                                ^~
yacc.y:966:11: error: request for member 'next' in something not a structure or union
          t->next = $3;
           ^~
yacc.y:970:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = make_coproc_command ("COPROC", $2);
                      ^
yacc.y:971:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_WANT_SUBSHELL|CMD_COPROC_SUBSHELL;
                     ^~
yacc.y:975:61: error: request for member 'word' in something not a structure or union
      $$ = make_coproc_command ($2->word, $3);
                                                             ^ 
yacc.y:976:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_WANT_SUBSHELL|CMD_COPROC_SUBSHELL;
                     ^~
yacc.y:985:19: error: unknown type name 'REDIRECT'
          register REDIRECT *t;
                   ^~~~~~~~
yacc.y:986:35: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                   ^~
yacc.y:986:48: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                                ^~
yacc.y:988:11: error: request for member 'next' in something not a structure or union
          t->next = $4;
           ^~
yacc.y:992:61: error: request for member 'word' in something not a structure or union
      $$ = make_coproc_command ($2->word, $3);
                                                             ^ 
yacc.y:993:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_WANT_SUBSHELL|CMD_COPROC_SUBSHELL;
                     ^~
yacc.y:997:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = make_coproc_command ("COPROC", clean_simple_command ($2));
                      ^
yacc.y:998:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_WANT_SUBSHELL|CMD_COPROC_SUBSHELL;
                     ^~
yacc.y:1003:25: warning: implicit declaration of function 'make_if_command' [-Wimplicit-function-declaration]
    { $$ = make_if_command ($2, $4, (COMMAND *)NULL); }
                         ^~~~~~~~~~~~~~~
yacc.y:1003:94: error: expected expression before ')' token
    { $$ = make_if_command ($2, $4, (COMMAND *)NULL); }
                                                                                              ^
yacc.y:1005:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_if_command ($2, $4, $6); }
                       ^
yacc.y:1007:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_if_command ($2, $4, $5); }
                       ^
yacc.y:1012:25: warning: implicit declaration of function 'make_group_command' [-Wimplicit-function-declaration]
    { $$ = make_group_command ($2); }
                         ^~~~~~~~~~~~      
yacc.y:1012:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_group_command ($2); }
                       ^
yacc.y:1016:25: warning: implicit declaration of function 'make_arith_command' [-Wimplicit-function-declaration]
    { $$ = make_arith_command ($1); }
                         ^~~~~~~~~~~~      
yacc.y:1016:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_arith_command ($1); }
                       ^
yacc.y:1024:93: error: expected expression before ')' token
    { $$ = make_if_command ($2, $4, (COMMAND *)NULL); }
                                                                                             ^
yacc.y:1026:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_if_command ($2, $4, $6); }
                       ^
yacc.y:1028:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_if_command ($2, $4, $5); }
                       ^
yacc.y:1033:25: error: request for member 'next' in something not a structure or union
    { $2->next = $1; $$ = $2; }
                         ^~
yacc.y:1037:25: warning: implicit declaration of function 'make_pattern_list' [-Wimplicit-function-declaration]
    { $$ = make_pattern_list ($2, $4); }
                         ^~~~~~~~~~~~~~~  
yacc.y:1037:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_pattern_list ($2, $4); }
                       ^
yacc.y:1039:77: error: expected expression before ')' token
    { $$ = make_pattern_list ($2, (COMMAND *)NULL); }
                                                                             ^
yacc.y:1041:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_pattern_list ($3, $5); }
                       ^
yacc.y:1043:77: error: expected expression before ')' token
    { $$ = make_pattern_list ($3, (COMMAND *)NULL); }
                                                                             ^
yacc.y:1049:26: error: request for member 'next' in something not a structure or union
    { $2->next = $1; $$ = $2; }
                          ^~
yacc.y:1051:26: error: request for member 'flags' in something not a structure or union
    { $1->flags |= CASEPAT_FALLTHROUGH; $$ = $1; }
                          ^~
yacc.y:1051:37: error: 'CASEPAT_FALLTHROUGH' undeclared (first use in this function)
    { $1->flags |= CASEPAT_FALLTHROUGH; $$ = $1; }
                                     ^~~~~~~~~~~~~      
yacc.y:1053:26: error: request for member 'flags' in something not a structure or union
    { $2->flags |= CASEPAT_FALLTHROUGH; $2->next = $1; $$ = $2; }
                          ^~
yacc.y:1053:77: error: request for member 'next' in something not a structure or union
    { $2->flags |= CASEPAT_FALLTHROUGH; $2->next = $1; $$ = $2; }
                                                                             ^ 
yacc.y:1055:26: error: request for member 'flags' in something not a structure or union
    { $1->flags |= CASEPAT_TESTNEXT; $$ = $1; }
                          ^~
yacc.y:1055:37: error: 'CASEPAT_TESTNEXT' undeclared (first use in this function)
    { $1->flags |= CASEPAT_TESTNEXT; $$ = $1; }
                                     ^~~~~~~~~~      
yacc.y:1057:26: error: request for member 'flags' in something not a structure or union
    { $2->flags |= CASEPAT_TESTNEXT; $2->next = $1; $$ = $2; }
                          ^~
yacc.y:1057:74: error: request for member 'next' in something not a structure or union
    { $2->flags |= CASEPAT_TESTNEXT; $2->next = $1; $$ = $2; }
                                                                          ^ 
yacc.y:1061:72: error: expected expression before ')' token
    { $$ = make_word_list ($1, (WORD_LIST *)NULL); }
                                                                        ^
yacc.y:1063:25: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = make_word_list ($3, $1); }
                         ^
yacc.y:1075:8: warning: implicit declaration of function 'gather_here_documents' [-Wimplicit-function-declaration]
        gather_here_documents ();
        ^~~~~~~~~~~~~~~~~~~~~
yacc.y:1089:29: error: request for member 'type' in something not a structure or union
      if ($1->type == cm_connection)
                             ^~
yacc.y:1089:39: error: 'cm_connection' undeclared (first use in this function)
      if ($1->type == cm_connection)
                                       ^            
yacc.y:1090:26: warning: implicit declaration of function 'connect_async_list' [-Wimplicit-function-declaration]
        $$ = connect_async_list ($1, (COMMAND *)NULL, '&');
                          ^~~~~~~~~~~~~~~~~~
yacc.y:1090:77: error: expected expression before ')' token
        $$ = connect_async_list ($1, (COMMAND *)NULL, '&');
                                                                             ^
yacc.y:1092:26: warning: implicit declaration of function 'command_connect' [-Wimplicit-function-declaration]
        $$ = command_connect ($1, (COMMAND *)NULL, '&');
                          ^~~~~~~~~~~~~~~
yacc.y:1099:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, AND_AND); }
                       ^
yacc.y:1101:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, OR_OR); }
                       ^
yacc.y:1104:29: error: request for member 'type' in something not a structure or union
      if ($1->type == cm_connection)
                             ^~
yacc.y:1105:24: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        $$ = connect_async_list ($1, $4, '&');
                        ^
yacc.y:1107:24: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        $$ = command_connect ($1, $4, '&');
                        ^
yacc.y:1110:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, ';'); }
                       ^
yacc.y:1112:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, ';'); }
                       ^
yacc.y:1154:29: error: request for member 'type' in something not a structure or union
      if ($1->type == cm_connection)
                             ^~
yacc.y:1155:77: error: expected expression before ')' token
        $$ = connect_async_list ($1, (COMMAND *)NULL, '&');
                                                                             ^
yacc.y:1184:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, AND_AND); }
                       ^
yacc.y:1186:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, OR_OR); }
                       ^
yacc.y:1189:29: error: request for member 'type' in something not a structure or union
      if ($1->type == cm_connection)
                             ^~
yacc.y:1190:24: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        $$ = connect_async_list ($1, $3, '&');
                        ^
yacc.y:1192:24: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        $$ = command_connect ($1, $3, '&');
                        ^
yacc.y:1195:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $3, ';'); }
                       ^
yacc.y:1206:26: error: request for member 'flags' in something not a structure or union
        $2->flags ^= CMD_INVERT_RETURN; /* toggle */
                          ^~
yacc.y:1206:37: error: 'CMD_INVERT_RETURN' undeclared (first use in this function)
        $2->flags ^= CMD_INVERT_RETURN; /* toggle */
                                     ^~~~~~~~~~~~~~~  
yacc.y:1212:26: error: request for member 'flags' in something not a structure or union
        $2->flags |= $1;
                          ^ 
yacc.y:1217:6: error: unknown type name 'ELEMENT'
      ELEMENT x;
      ^~~~~~~
yacc.y:1224:7: error: request for member 'word' in something not a structure or union
      x.word = 0;
       ^
yacc.y:1225:7: error: request for member 'redirect' in something not a structure or union
      x.redirect = 0;
       ^
yacc.y:1226:58: error: expected expression before ')' token
      $$ = make_simple_command (x, (COMMAND *)NULL);
                                                          ^
yacc.y:1227:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= $1;
                     ^ 
yacc.y:1236:6: error: unknown type name 'ELEMENT'
      ELEMENT x;
      ^~~~~~~
yacc.y:1244:7: error: request for member 'word' in something not a structure or union
      x.word = 0;
       ^
yacc.y:1245:7: error: request for member 'redirect' in something not a structure or union
      x.redirect = 0;
       ^
yacc.y:1246:58: error: expected expression before ')' token
      $$ = make_simple_command (x, (COMMAND *)NULL);
                                                          ^
yacc.y:1247:21: error: request for member 'flags' in something not a structure or union
      $$->flags |= CMD_INVERT_RETURN;
                     ^~
yacc.y:1257:23: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
    { $$ = command_connect ($1, $4, '|'); }
                       ^
yacc.y:1262:6: error: unknown type name 'REDIRECTEE'; did you mean 'REDIR_WORD'?
      REDIRECTEE rd, sd;
      ^~~~~~~~~~
      REDIR_WORD
yacc.y:1263:6: error: unknown type name 'REDIRECT'; did you mean 'SELECT'?
      REDIRECT *r;
      ^~~~~~~~
      SELECT
yacc.y:1265:30: error: request for member 'type' in something not a structure or union
      tc = $1->type == cm_simple ? (COMMAND *)$1->value.Simple : $1;
                              ^~
yacc.y:1265:40: error: 'cm_simple' undeclared (first use in this function)
      tc = $1->type == cm_simple ? (COMMAND *)$1->value.Simple : $1;
                                        ^~~~~~~~~
yacc.y:1265:62: error: expected expression before ')' token
      tc = $1->type == cm_simple ? (COMMAND *)$1->value.Simple : $1;
                                                              ^
yacc.y:1266:8: error: request for member 'dest' in something not a structure or union
      sd.dest = 2;
        ^
yacc.y:1267:8: error: request for member 'dest' in something not a structure or union
      rd.dest = 1;
        ^
yacc.y:1271:19: error: unknown type name 'REDIRECT'
          register REDIRECT *t;
                   ^~~~~~~~
yacc.y:1272:35: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                   ^~
yacc.y:1272:48: error: request for member 'next' in something not a structure or union
          for (t = tc->redirects; t->next; t = t->next)
                                                ^~
yacc.y:1274:11: error: request for member 'next' in something not a structure or union
          t->next = r;
           ^~
yacc.y:1279:22: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
      $$ = command_connect ($1, $4, '|');
                      ^
yacc.y:1286:24: error: 'CMD_TIME_PIPELINE' undeclared (first use in this function)
    { $$ = CMD_TIME_PIPELINE; }
                        ^~~~~~~          
yacc.y:1288:42: error: 'CMD_TIME_POSIX' undeclared (first use in this function)
    { $$ = CMD_TIME_PIPELINE|CMD_TIME_POSIX; }
                                          ^~~~          
yacc.y: At top level:
yacc.y:1340:1: error: unknown type name 'BASH_INPUT'
 BASH_INPUT bash_input;
 ^~~~~~~~~~
yacc.y: In function 'initialize_bash_input':
yacc.y:1347:13: error: request for member 'type' in something not a structure or union
   bash_input.type = st_none;
             ^
yacc.y:1347:21: error: 'st_none' undeclared (first use in this function)
   bash_input.type = st_none;
                     ^~~~~~~
yacc.y:1348:3: warning: implicit declaration of function 'FREE'; did you mean 'YYFREE'? [-Wimplicit-function-declaration]
   FREE (bash_input.name);
   ^~~~
   YYFREE
yacc.y:1348:19: error: request for member 'name' in something not a structure or union
   FREE (bash_input.name);
                   ^
yacc.y:1349:13: error: request for member 'name' in something not a structure or union
   bash_input.name = (char *)NULL;
             ^
yacc.y:1350:13: error: request for member 'location' in something not a structure or union
   bash_input.location.file = (FILE *)NULL;
             ^
yacc.y:1351:13: error: request for member 'location' in something not a structure or union
   bash_input.location.string = (char *)NULL;
             ^
yacc.y:1352:13: error: request for member 'getter' in something not a structure or union
   bash_input.getter = (sh_cget_func_t *)NULL;
             ^
yacc.y:1352:24: error: 'sh_cget_func_t' undeclared (first use in this function)
   bash_input.getter = (sh_cget_func_t *)NULL;
                        ^~~~~~~~~~~~~~
yacc.y:1352:40: error: expected expression before ')' token
   bash_input.getter = (sh_cget_func_t *)NULL;
                                        ^
yacc.y:1353:13: error: request for member 'ungetter' in something not a structure or union
   bash_input.ungetter = (sh_cunget_func_t *)NULL;
             ^
yacc.y:1353:26: error: 'sh_cunget_func_t' undeclared (first use in this function)
   bash_input.ungetter = (sh_cunget_func_t *)NULL;
                          ^~~~~~~~~~~~~~~~
yacc.y:1353:44: error: expected expression before ')' token
   bash_input.ungetter = (sh_cunget_func_t *)NULL;
                                            ^
yacc.y: In function 'init_yy_io':
yacc.y:1360:6: error: unknown type name 'sh_cget_func_t'
      sh_cget_func_t *get;
      ^~~~~~~~~~~~~~
yacc.y:1361:6: error: unknown type name 'sh_cunget_func_t'
      sh_cunget_func_t *unget;
      ^~~~~~~~~~~~~~~~
yacc.y:1364:6: error: unknown type name 'INPUT_STREAM'
      INPUT_STREAM location;
      ^~~~~~~~~~~~
yacc.y:1362:23: error: parameter 'type' has incomplete type
      enum stream_type type;
                       ^~~~
yacc.y:1366:13: error: request for member 'type' in something not a structure or union
   bash_input.type = type;
             ^
yacc.y:1367:19: error: request for member 'name' in something not a structure or union
   FREE (bash_input.name);
                   ^
yacc.y:1368:13: error: request for member 'name' in something not a structure or union
   bash_input.name = name ? savestring (name) : (char *)NULL;
             ^
yacc.y:1368:28: warning: implicit declaration of function 'savestring' [-Wimplicit-function-declaration]
   bash_input.name = name ? savestring (name) : (char *)NULL;
                            ^~~~~~~~~~
yacc.y:1368:46: warning: pointer/integer type mismatch in conditional expression
   bash_input.name = name ? savestring (name) : (char *)NULL;
                                              ^
yacc.y:1374:13: error: request for member 'location' in something not a structure or union
   bash_input.location = location;
             ^
yacc.y:1376:13: error: request for member 'getter' in something not a structure or union
   bash_input.getter = get;
             ^
yacc.y:1377:13: error: request for member 'ungetter' in something not a structure or union
   bash_input.ungetter = unget;
             ^
yacc.y: In function 'yy_input_name':
yacc.y:1383:21: error: request for member 'name' in something not a structure or union
   return (bash_input.name ? bash_input.name : "stdin");
                     ^
yacc.y:1383:39: error: request for member 'name' in something not a structure or union
   return (bash_input.name ? bash_input.name : "stdin");
                                       ^
yacc.y: In function 'yy_getc':
yacc.y:1390:23: error: request for member 'getter' in something not a structure or union
   return (*(bash_input.getter)) ();
                       ^
yacc.y: In function 'yy_ungetc':
yacc.y:1399:23: error: request for member 'ungetter' in something not a structure or union
   return (*(bash_input.ungetter)) (c);
                       ^
yacc.y: In function 'with_input_from_stdin':
yacc.y:1523:3: warning: implicit declaration of function 'with_input_from_stream'; did you mean 'with_input_from_stdin'? [-Wimplicit-function-declaration]
   with_input_from_stream (stdin, "stdin");
   ^~~~~~~~~~~~~~~~~~~~~~
   with_input_from_stdin
yacc.y: In function 'yy_string_get':
yacc.y:1539:22: error: request for member 'location' in something not a structure or union
   string = bash_input.location.string;
                      ^
yacc.y:1545:17: error: request for member 'location' in something not a structure or union
       bash_input.location.string = string;
                 ^
yacc.y: In function 'yy_string_unget':
yacc.y:1556:17: error: request for member 'location' in something not a structure or union
   *(--bash_input.location.string) = c;
                 ^
yacc.y: In function 'with_input_from_string':
yacc.y:1565:3: error: unknown type name 'INPUT_STREAM'
   INPUT_STREAM location;
   ^~~~~~~~~~~~
yacc.y:1567:11: error: request for member 'string' in something not a structure or union
   location.string = string;
           ^
yacc.y:1568:47: error: 'st_string' undeclared (first use in this function); did you mean 'string'?
   init_yy_io (yy_string_get, yy_string_unget, st_string, name, location);
                                               ^~~~~~~~~
                                               string
yacc.y: In function 'rewind_input_string':
yacc.y:1584:17: error: request for member 'location' in something not a structure or union
   if (bash_input.location.string[-1] == '\n')
                 ^
yacc.y:1595:13: error: request for member 'location' in something not a structure or union
   bash_input.location.string -= xchars;
             ^
yacc.y: In function 'yy_stream_get':
yacc.y:1616:17: error: request for member 'location' in something not a structure or union
   if (bash_input.location.file)
                 ^
yacc.y:1625:16: warning: implicit declaration of function 'getc_with_restart' [-Wimplicit-function-declaration]
       result = getc_with_restart (bash_input.location.file);
                ^~~~~~~~~~~~~~~~~
yacc.y:1625:45: error: request for member 'location' in something not a structure or union
       result = getc_with_restart (bash_input.location.file);
                                             ^
yacc.y: In function 'yy_stream_unget':
yacc.y:1639:11: warning: implicit declaration of function 'ungetc_with_restart' [-Wimplicit-function-declaration]
   return (ungetc_with_restart (c, bash_input.location.file));
           ^~~~~~~~~~~~~~~~~~~
yacc.y:1639:45: error: request for member 'location' in something not a structure or union
   return (ungetc_with_restart (c, bash_input.location.file));
                                             ^
yacc.y: At top level:
yacc.y:1643:1: warning: conflicting types for 'with_input_from_stream'
 with_input_from_stream (stream, name)
 ^~~~~~~~~~~~~~~~~~~~~~
yacc.y:1523:3: note: previous implicit declaration of 'with_input_from_stream' was here
   with_input_from_stream (stdin, "stdin");
   ^~~~~~~~~~~~~~~~~~~~~~
yacc.y: In function 'with_input_from_stream':
yacc.y:1647:3: error: unknown type name 'INPUT_STREAM'
   INPUT_STREAM location;
   ^~~~~~~~~~~~
yacc.y:1649:11: error: request for member 'file' in something not a structure or union
   location.file = stream;
           ^
yacc.y:1650:47: error: 'st_stream' undeclared (first use in this function); did you mean 'stream'?
   init_yy_io (yy_stream_get, yy_stream_unget, st_stream, name, location);
                                               ^~~~~~~~~
                                               stream
yacc.y: At top level:
yacc.y:1655:3: error: unknown type name 'BASH_INPUT'
   BASH_INPUT bash_input;
   ^~~~~~~~~~
yacc.y: In function 'push_stream':
yacc.y:1679:41: warning: implicit declaration of function 'xmalloc'; did you mean 'malloc'? [-Wimplicit-function-declaration]
   STREAM_SAVER *saver = (STREAM_SAVER *)xmalloc (sizeof (STREAM_SAVER));
                                         ^~~~~~~
                                         malloc
yacc.y:1679:25: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   STREAM_SAVER *saver = (STREAM_SAVER *)xmalloc (sizeof (STREAM_SAVER));
                         ^
yacc.y:1681:3: warning: implicit declaration of function 'xbcopy' [-Wimplicit-function-declaration]
   xbcopy ((char *)&bash_input, (char *)&(saver->bash_input), sizeof (BASH_INPUT));
   ^~~~~~
yacc.y:1681:70: error: 'BASH_INPUT' undeclared (first use in this function)
   xbcopy ((char *)&bash_input, (char *)&(saver->bash_input), sizeof (BASH_INPUT));
                                                                      ^~~~~~~~~~
yacc.y:1692:13: error: request for member 'name' in something not a structure or union
   bash_input.name = (char *)NULL;
             ^
yacc.y: In function 'pop_stream':
yacc.y:1712:36: error: request for member 'getter' in something not a structure or union
       init_yy_io (saver->bash_input.getter,
                                    ^
yacc.y:1713:22: error: request for member 'ungetter' in something not a structure or union
     saver->bash_input.ungetter,
                      ^
yacc.y:1714:22: error: request for member 'type' in something not a structure or union
     saver->bash_input.type,
                      ^
yacc.y:1715:22: error: request for member 'name' in something not a structure or union
     saver->bash_input.name,
                      ^
yacc.y:1716:22: error: request for member 'location' in something not a structure or union
     saver->bash_input.location);
                      ^
yacc.y:1742:30: error: request for member 'name' in something not a structure or union
       FREE (saver->bash_input.name);
                              ^
yacc.y: In function 'stream_on_stack':
yacc.y:1750:23: error: parameter 'type' has incomplete type
      enum stream_type type;
                       ^~~~
yacc.y:1755:22: error: request for member 'type' in something not a structure or union
     if (s->bash_input.type == type)
                      ^
yacc.y: In function 'save_token_state':
yacc.y:1766:9: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   ret = (int *)xmalloc (4 * sizeof (int));
         ^
yacc.y: In function 'read_a_line':
yacc.y:1301:4: error: 'interactive' undeclared (first use in this function)
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
    ^~~~~~~~~~~
yacc.y:1986:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT ())
       ^~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:1986:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT ())
       ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:1986:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT ())
       ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:1986:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT ())
       ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:1986:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT ())
       ^~~~~~~~~~~~~
yacc.y:1994:7: error: 'QUIT' undeclared (first use in this function)
       QUIT;
       ^~~~
yacc.y:2010:33: error: request for member 'type' in something not a structure or union
    if (interactive && bash_input.type == st_stream)
                                 ^
yacc.y:2018:7: warning: implicit declaration of function 'RESIZE_MALLOCED_BUFFER' [-Wimplicit-function-declaration]
       RESIZE_MALLOCED_BUFFER (line_buffer, indx, 2, buffer_size, 128);
       ^~~~~~~~~~~~~~~~~~~~~~
yacc.y: In function 'read_secondary_line':
yacc.y:1301:4: error: 'interactive' undeclared (first use in this function)
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
    ^~~~~~~~~~~
yacc.y:2071:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT())
       ^~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:2071:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT())
       ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:2071:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT())
       ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:2071:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT())
       ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:2071:7: note: in expansion of macro 'SHOULD_PROMPT'
   if (SHOULD_PROMPT())
       ^~~~~~~~~~~~~
yacc.y: At top level:
yacc.y:2098:1: error: unknown type name 'STRING_INT_ALIST'
 STRING_INT_ALIST word_token_alist[] = {
 ^~~~~~~~~~~~~~~~
yacc.y:2099:3: warning: braces around scalar initializer
   { "if", IF },
   ^
yacc.y:2099:3: note: (near initialization for 'word_token_alist[0]')
yacc.y:2099:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "if", IF },
     ^~~~
yacc.y:2099:5: note: (near initialization for 'word_token_alist[0]')
yacc.y:2099:5: error: initializer element is not computable at load time
yacc.y:2099:5: note: (near initialization for 'word_token_alist[0]')
y.tab.c:459:12: warning: excess elements in scalar initializer
 #define IF 258
            ^~~
yacc.y:2099:11: note: in expansion of macro 'IF'
   { "if", IF },
           ^~
y.tab.c:459:12: note: (near initialization for 'word_token_alist[0]')
 #define IF 258
            ^~~
yacc.y:2099:11: note: in expansion of macro 'IF'
   { "if", IF },
           ^~
yacc.y:2100:3: warning: braces around scalar initializer
   { "then", THEN },
   ^
yacc.y:2100:3: note: (near initialization for 'word_token_alist[1]')
yacc.y:2100:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "then", THEN },
     ^~~~~~
yacc.y:2100:5: note: (near initialization for 'word_token_alist[1]')
yacc.y:2100:5: error: initializer element is not computable at load time
yacc.y:2100:5: note: (near initialization for 'word_token_alist[1]')
y.tab.c:460:14: warning: excess elements in scalar initializer
 #define THEN 259
              ^~~
yacc.y:2100:13: note: in expansion of macro 'THEN'
   { "then", THEN },
             ^~~~
y.tab.c:460:14: note: (near initialization for 'word_token_alist[1]')
 #define THEN 259
              ^~~
yacc.y:2100:13: note: in expansion of macro 'THEN'
   { "then", THEN },
             ^~~~
yacc.y:2101:3: warning: braces around scalar initializer
   { "else", ELSE },
   ^
yacc.y:2101:3: note: (near initialization for 'word_token_alist[2]')
yacc.y:2101:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "else", ELSE },
     ^~~~~~
yacc.y:2101:5: note: (near initialization for 'word_token_alist[2]')
yacc.y:2101:5: error: initializer element is not computable at load time
yacc.y:2101:5: note: (near initialization for 'word_token_alist[2]')
y.tab.c:461:14: warning: excess elements in scalar initializer
 #define ELSE 260
              ^~~
yacc.y:2101:13: note: in expansion of macro 'ELSE'
   { "else", ELSE },
             ^~~~
y.tab.c:461:14: note: (near initialization for 'word_token_alist[2]')
 #define ELSE 260
              ^~~
yacc.y:2101:13: note: in expansion of macro 'ELSE'
   { "else", ELSE },
             ^~~~
yacc.y:2102:3: warning: braces around scalar initializer
   { "elif", ELIF },
   ^
yacc.y:2102:3: note: (near initialization for 'word_token_alist[3]')
yacc.y:2102:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "elif", ELIF },
     ^~~~~~
yacc.y:2102:5: note: (near initialization for 'word_token_alist[3]')
yacc.y:2102:5: error: initializer element is not computable at load time
yacc.y:2102:5: note: (near initialization for 'word_token_alist[3]')
y.tab.c:462:14: warning: excess elements in scalar initializer
 #define ELIF 261
              ^~~
yacc.y:2102:13: note: in expansion of macro 'ELIF'
   { "elif", ELIF },
             ^~~~
y.tab.c:462:14: note: (near initialization for 'word_token_alist[3]')
 #define ELIF 261
              ^~~
yacc.y:2102:13: note: in expansion of macro 'ELIF'
   { "elif", ELIF },
             ^~~~
yacc.y:2103:3: warning: braces around scalar initializer
   { "fi", FI },
   ^
yacc.y:2103:3: note: (near initialization for 'word_token_alist[4]')
yacc.y:2103:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "fi", FI },
     ^~~~
yacc.y:2103:5: note: (near initialization for 'word_token_alist[4]')
yacc.y:2103:5: error: initializer element is not computable at load time
yacc.y:2103:5: note: (near initialization for 'word_token_alist[4]')
y.tab.c:463:12: warning: excess elements in scalar initializer
 #define FI 262
            ^~~
yacc.y:2103:11: note: in expansion of macro 'FI'
   { "fi", FI },
           ^~
y.tab.c:463:12: note: (near initialization for 'word_token_alist[4]')
 #define FI 262
            ^~~
yacc.y:2103:11: note: in expansion of macro 'FI'
   { "fi", FI },
           ^~
yacc.y:2104:3: warning: braces around scalar initializer
   { "case", CASE },
   ^
yacc.y:2104:3: note: (near initialization for 'word_token_alist[5]')
yacc.y:2104:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "case", CASE },
     ^~~~~~
yacc.y:2104:5: note: (near initialization for 'word_token_alist[5]')
yacc.y:2104:5: error: initializer element is not computable at load time
yacc.y:2104:5: note: (near initialization for 'word_token_alist[5]')
y.tab.c:464:14: warning: excess elements in scalar initializer
 #define CASE 263
              ^~~
yacc.y:2104:13: note: in expansion of macro 'CASE'
   { "case", CASE },
             ^~~~
y.tab.c:464:14: note: (near initialization for 'word_token_alist[5]')
 #define CASE 263
              ^~~
yacc.y:2104:13: note: in expansion of macro 'CASE'
   { "case", CASE },
             ^~~~
yacc.y:2105:3: warning: braces around scalar initializer
   { "esac", ESAC },
   ^
yacc.y:2105:3: note: (near initialization for 'word_token_alist[6]')
yacc.y:2105:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "esac", ESAC },
     ^~~~~~
yacc.y:2105:5: note: (near initialization for 'word_token_alist[6]')
yacc.y:2105:5: error: initializer element is not computable at load time
yacc.y:2105:5: note: (near initialization for 'word_token_alist[6]')
y.tab.c:465:14: warning: excess elements in scalar initializer
 #define ESAC 264
              ^~~
yacc.y:2105:13: note: in expansion of macro 'ESAC'
   { "esac", ESAC },
             ^~~~
y.tab.c:465:14: note: (near initialization for 'word_token_alist[6]')
 #define ESAC 264
              ^~~
yacc.y:2105:13: note: in expansion of macro 'ESAC'
   { "esac", ESAC },
             ^~~~
yacc.y:2106:3: warning: braces around scalar initializer
   { "for", FOR },
   ^
yacc.y:2106:3: note: (near initialization for 'word_token_alist[7]')
yacc.y:2106:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "for", FOR },
     ^~~~~
yacc.y:2106:5: note: (near initialization for 'word_token_alist[7]')
yacc.y:2106:5: error: initializer element is not computable at load time
yacc.y:2106:5: note: (near initialization for 'word_token_alist[7]')
y.tab.c:466:13: warning: excess elements in scalar initializer
 #define FOR 265
             ^~~
yacc.y:2106:12: note: in expansion of macro 'FOR'
   { "for", FOR },
            ^~~
y.tab.c:466:13: note: (near initialization for 'word_token_alist[7]')
 #define FOR 265
             ^~~
yacc.y:2106:12: note: in expansion of macro 'FOR'
   { "for", FOR },
            ^~~
yacc.y:2110:3: warning: braces around scalar initializer
   { "while", WHILE },
   ^
yacc.y:2110:3: note: (near initialization for 'word_token_alist[8]')
yacc.y:2110:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "while", WHILE },
     ^~~~~~~
yacc.y:2110:5: note: (near initialization for 'word_token_alist[8]')
yacc.y:2110:5: error: initializer element is not computable at load time
yacc.y:2110:5: note: (near initialization for 'word_token_alist[8]')
y.tab.c:468:15: warning: excess elements in scalar initializer
 #define WHILE 267
               ^~~
yacc.y:2110:14: note: in expansion of macro 'WHILE'
   { "while", WHILE },
              ^~~~~
y.tab.c:468:15: note: (near initialization for 'word_token_alist[8]')
 #define WHILE 267
               ^~~
yacc.y:2110:14: note: in expansion of macro 'WHILE'
   { "while", WHILE },
              ^~~~~
yacc.y:2111:3: warning: braces around scalar initializer
   { "until", UNTIL },
   ^
yacc.y:2111:3: note: (near initialization for 'word_token_alist[9]')
yacc.y:2111:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "until", UNTIL },
     ^~~~~~~
yacc.y:2111:5: note: (near initialization for 'word_token_alist[9]')
yacc.y:2111:5: error: initializer element is not computable at load time
yacc.y:2111:5: note: (near initialization for 'word_token_alist[9]')
y.tab.c:469:15: warning: excess elements in scalar initializer
 #define UNTIL 268
               ^~~
yacc.y:2111:14: note: in expansion of macro 'UNTIL'
   { "until", UNTIL },
              ^~~~~
y.tab.c:469:15: note: (near initialization for 'word_token_alist[9]')
 #define UNTIL 268
               ^~~
yacc.y:2111:14: note: in expansion of macro 'UNTIL'
   { "until", UNTIL },
              ^~~~~
yacc.y:2112:3: warning: braces around scalar initializer
   { "do", DO },
   ^
yacc.y:2112:3: note: (near initialization for 'word_token_alist[10]')
yacc.y:2112:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "do", DO },
     ^~~~
yacc.y:2112:5: note: (near initialization for 'word_token_alist[10]')
yacc.y:2112:5: error: initializer element is not computable at load time
yacc.y:2112:5: note: (near initialization for 'word_token_alist[10]')
y.tab.c:470:12: warning: excess elements in scalar initializer
 #define DO 269
            ^~~
yacc.y:2112:11: note: in expansion of macro 'DO'
   { "do", DO },
           ^~
y.tab.c:470:12: note: (near initialization for 'word_token_alist[10]')
 #define DO 269
            ^~~
yacc.y:2112:11: note: in expansion of macro 'DO'
   { "do", DO },
           ^~
yacc.y:2113:3: warning: braces around scalar initializer
   { "done", DONE },
   ^
yacc.y:2113:3: note: (near initialization for 'word_token_alist[11]')
yacc.y:2113:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "done", DONE },
     ^~~~~~
yacc.y:2113:5: note: (near initialization for 'word_token_alist[11]')
yacc.y:2113:5: error: initializer element is not computable at load time
yacc.y:2113:5: note: (near initialization for 'word_token_alist[11]')
y.tab.c:471:14: warning: excess elements in scalar initializer
 #define DONE 270
              ^~~
yacc.y:2113:13: note: in expansion of macro 'DONE'
   { "done", DONE },
             ^~~~
y.tab.c:471:14: note: (near initialization for 'word_token_alist[11]')
 #define DONE 270
              ^~~
yacc.y:2113:13: note: in expansion of macro 'DONE'
   { "done", DONE },
             ^~~~
yacc.y:2114:3: warning: braces around scalar initializer
   { "in", IN },
   ^
yacc.y:2114:3: note: (near initialization for 'word_token_alist[12]')
yacc.y:2114:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "in", IN },
     ^~~~
yacc.y:2114:5: note: (near initialization for 'word_token_alist[12]')
yacc.y:2114:5: error: initializer element is not computable at load time
yacc.y:2114:5: note: (near initialization for 'word_token_alist[12]')
y.tab.c:477:12: warning: excess elements in scalar initializer
 #define IN 276
            ^~~
yacc.y:2114:11: note: in expansion of macro 'IN'
   { "in", IN },
           ^~
y.tab.c:477:12: note: (near initialization for 'word_token_alist[12]')
 #define IN 276
            ^~~
yacc.y:2114:11: note: in expansion of macro 'IN'
   { "in", IN },
           ^~
yacc.y:2115:3: warning: braces around scalar initializer
   { "function", FUNCTION },
   ^
yacc.y:2115:3: note: (near initialization for 'word_token_alist[13]')
yacc.y:2115:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "function", FUNCTION },
     ^~~~~~~~~~
yacc.y:2115:5: note: (near initialization for 'word_token_alist[13]')
yacc.y:2115:5: error: initializer element is not computable at load time
yacc.y:2115:5: note: (near initialization for 'word_token_alist[13]')
y.tab.c:472:18: warning: excess elements in scalar initializer
 #define FUNCTION 271
                  ^~~
yacc.y:2115:17: note: in expansion of macro 'FUNCTION'
   { "function", FUNCTION },
                 ^~~~~~~~
y.tab.c:472:18: note: (near initialization for 'word_token_alist[13]')
 #define FUNCTION 271
                  ^~~
yacc.y:2115:17: note: in expansion of macro 'FUNCTION'
   { "function", FUNCTION },
                 ^~~~~~~~
yacc.y:2119:3: warning: braces around scalar initializer
   { "{", '{' },
   ^
yacc.y:2119:3: note: (near initialization for 'word_token_alist[14]')
yacc.y:2119:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "{", '{' },
     ^~~
yacc.y:2119:5: note: (near initialization for 'word_token_alist[14]')
yacc.y:2119:5: error: initializer element is not computable at load time
yacc.y:2119:5: note: (near initialization for 'word_token_alist[14]')
yacc.y:2119:10: warning: excess elements in scalar initializer
   { "{", '{' },
          ^~~
yacc.y:2119:10: note: (near initialization for 'word_token_alist[14]')
yacc.y:2120:3: warning: braces around scalar initializer
   { "}", '}' },
   ^
yacc.y:2120:3: note: (near initialization for 'word_token_alist[15]')
yacc.y:2120:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "}", '}' },
     ^~~
yacc.y:2120:5: note: (near initialization for 'word_token_alist[15]')
yacc.y:2120:5: error: initializer element is not computable at load time
yacc.y:2120:5: note: (near initialization for 'word_token_alist[15]')
yacc.y:2120:10: warning: excess elements in scalar initializer
   { "}", '}' },
          ^~~
yacc.y:2120:10: note: (near initialization for 'word_token_alist[15]')
yacc.y:2121:3: warning: braces around scalar initializer
   { "!", BANG },
   ^
yacc.y:2121:3: note: (near initialization for 'word_token_alist[16]')
yacc.y:2121:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "!", BANG },
     ^~~
yacc.y:2121:5: note: (near initialization for 'word_token_alist[16]')
yacc.y:2121:5: error: initializer element is not computable at load time
yacc.y:2121:5: note: (near initialization for 'word_token_alist[16]')
y.tab.c:478:14: warning: excess elements in scalar initializer
 #define BANG 277
              ^~~
yacc.y:2121:10: note: in expansion of macro 'BANG'
   { "!", BANG },
          ^~~~
y.tab.c:478:14: note: (near initialization for 'word_token_alist[16]')
 #define BANG 277
              ^~~
yacc.y:2121:10: note: in expansion of macro 'BANG'
   { "!", BANG },
          ^~~~
yacc.y:2129:3: warning: braces around scalar initializer
   { (char *)NULL, 0}
   ^
yacc.y:2129:3: note: (near initialization for 'word_token_alist[17]')
yacc.y:2129:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { (char *)NULL, 0}
     ^
yacc.y:2129:5: note: (near initialization for 'word_token_alist[17]')
yacc.y:2129:19: warning: excess elements in scalar initializer
   { (char *)NULL, 0}
                   ^
yacc.y:2129:19: note: (near initialization for 'word_token_alist[17]')
yacc.y:2133:1: error: unknown type name 'STRING_INT_ALIST'
 STRING_INT_ALIST other_token_alist[] = {
 ^~~~~~~~~~~~~~~~
yacc.y:2135:3: warning: braces around scalar initializer
   { "--", TIMEIGN },
   ^
yacc.y:2135:3: note: (near initialization for 'other_token_alist[0]')
yacc.y:2135:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "--", TIMEIGN },
     ^~~~
yacc.y:2135:5: note: (near initialization for 'other_token_alist[0]')
yacc.y:2135:5: error: initializer element is not computable at load time
yacc.y:2135:5: note: (near initialization for 'other_token_alist[0]')
y.tab.c:481:17: warning: excess elements in scalar initializer
 #define TIMEIGN 280
                 ^~~
yacc.y:2135:11: note: in expansion of macro 'TIMEIGN'
   { "--", TIMEIGN },
           ^~~~~~~
y.tab.c:481:17: note: (near initialization for 'other_token_alist[0]')
 #define TIMEIGN 280
                 ^~~
yacc.y:2135:11: note: in expansion of macro 'TIMEIGN'
   { "--", TIMEIGN },
           ^~~~~~~
yacc.y:2136:3: warning: braces around scalar initializer
   { "-p", TIMEOPT },
   ^
yacc.y:2136:3: note: (near initialization for 'other_token_alist[1]')
yacc.y:2136:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "-p", TIMEOPT },
     ^~~~
yacc.y:2136:5: note: (near initialization for 'other_token_alist[1]')
yacc.y:2136:5: error: initializer element is not computable at load time
yacc.y:2136:5: note: (near initialization for 'other_token_alist[1]')
y.tab.c:480:17: warning: excess elements in scalar initializer
 #define TIMEOPT 279
                 ^~~
yacc.y:2136:11: note: in expansion of macro 'TIMEOPT'
   { "-p", TIMEOPT },
           ^~~~~~~
y.tab.c:480:17: note: (near initialization for 'other_token_alist[1]')
 #define TIMEOPT 279
                 ^~~
yacc.y:2136:11: note: in expansion of macro 'TIMEOPT'
   { "-p", TIMEOPT },
           ^~~~~~~
yacc.y:2137:3: warning: braces around scalar initializer
   { "&&", AND_AND },
   ^
yacc.y:2137:3: note: (near initialization for 'other_token_alist[2]')
yacc.y:2137:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "&&", AND_AND },
     ^~~~
yacc.y:2137:5: note: (near initialization for 'other_token_alist[2]')
yacc.y:2137:5: error: initializer element is not computable at load time
yacc.y:2137:5: note: (near initialization for 'other_token_alist[2]')
y.tab.c:489:17: warning: excess elements in scalar initializer
 #define AND_AND 288
                 ^~~
yacc.y:2137:11: note: in expansion of macro 'AND_AND'
   { "&&", AND_AND },
           ^~~~~~~
y.tab.c:489:17: note: (near initialization for 'other_token_alist[2]')
 #define AND_AND 288
                 ^~~
yacc.y:2137:11: note: in expansion of macro 'AND_AND'
   { "&&", AND_AND },
           ^~~~~~~
yacc.y:2138:3: warning: braces around scalar initializer
   { "||", OR_OR },
   ^
yacc.y:2138:3: note: (near initialization for 'other_token_alist[3]')
yacc.y:2138:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "||", OR_OR },
     ^~~~
yacc.y:2138:5: note: (near initialization for 'other_token_alist[3]')
yacc.y:2138:5: error: initializer element is not computable at load time
yacc.y:2138:5: note: (near initialization for 'other_token_alist[3]')
y.tab.c:490:15: warning: excess elements in scalar initializer
 #define OR_OR 289
               ^~~
yacc.y:2138:11: note: in expansion of macro 'OR_OR'
   { "||", OR_OR },
           ^~~~~
y.tab.c:490:15: note: (near initialization for 'other_token_alist[3]')
 #define OR_OR 289
               ^~~
yacc.y:2138:11: note: in expansion of macro 'OR_OR'
   { "||", OR_OR },
           ^~~~~
yacc.y:2139:3: warning: braces around scalar initializer
   { ">>", GREATER_GREATER },
   ^
yacc.y:2139:3: note: (near initialization for 'other_token_alist[4]')
yacc.y:2139:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ">>", GREATER_GREATER },
     ^~~~
yacc.y:2139:5: note: (near initialization for 'other_token_alist[4]')
yacc.y:2139:5: error: initializer element is not computable at load time
yacc.y:2139:5: note: (near initialization for 'other_token_alist[4]')
y.tab.c:491:25: warning: excess elements in scalar initializer
 #define GREATER_GREATER 290
                         ^~~
yacc.y:2139:11: note: in expansion of macro 'GREATER_GREATER'
   { ">>", GREATER_GREATER },
           ^~~~~~~~~~~~~~~
y.tab.c:491:25: note: (near initialization for 'other_token_alist[4]')
 #define GREATER_GREATER 290
                         ^~~
yacc.y:2139:11: note: in expansion of macro 'GREATER_GREATER'
   { ">>", GREATER_GREATER },
           ^~~~~~~~~~~~~~~
yacc.y:2140:3: warning: braces around scalar initializer
   { "<<", LESS_LESS },
   ^
yacc.y:2140:3: note: (near initialization for 'other_token_alist[5]')
yacc.y:2140:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "<<", LESS_LESS },
     ^~~~
yacc.y:2140:5: note: (near initialization for 'other_token_alist[5]')
yacc.y:2140:5: error: initializer element is not computable at load time
yacc.y:2140:5: note: (near initialization for 'other_token_alist[5]')
y.tab.c:492:19: warning: excess elements in scalar initializer
 #define LESS_LESS 291
                   ^~~
yacc.y:2140:11: note: in expansion of macro 'LESS_LESS'
   { "<<", LESS_LESS },
           ^~~~~~~~~
y.tab.c:492:19: note: (near initialization for 'other_token_alist[5]')
 #define LESS_LESS 291
                   ^~~
yacc.y:2140:11: note: in expansion of macro 'LESS_LESS'
   { "<<", LESS_LESS },
           ^~~~~~~~~
yacc.y:2141:3: warning: braces around scalar initializer
   { "<&", LESS_AND },
   ^
yacc.y:2141:3: note: (near initialization for 'other_token_alist[6]')
yacc.y:2141:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "<&", LESS_AND },
     ^~~~
yacc.y:2141:5: note: (near initialization for 'other_token_alist[6]')
yacc.y:2141:5: error: initializer element is not computable at load time
yacc.y:2141:5: note: (near initialization for 'other_token_alist[6]')
y.tab.c:493:18: warning: excess elements in scalar initializer
 #define LESS_AND 292
                  ^~~
yacc.y:2141:11: note: in expansion of macro 'LESS_AND'
   { "<&", LESS_AND },
           ^~~~~~~~
y.tab.c:493:18: note: (near initialization for 'other_token_alist[6]')
 #define LESS_AND 292
                  ^~~
yacc.y:2141:11: note: in expansion of macro 'LESS_AND'
   { "<&", LESS_AND },
           ^~~~~~~~
yacc.y:2142:3: warning: braces around scalar initializer
   { ">&", GREATER_AND },
   ^
yacc.y:2142:3: note: (near initialization for 'other_token_alist[7]')
yacc.y:2142:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ">&", GREATER_AND },
     ^~~~
yacc.y:2142:5: note: (near initialization for 'other_token_alist[7]')
yacc.y:2142:5: error: initializer element is not computable at load time
yacc.y:2142:5: note: (near initialization for 'other_token_alist[7]')
y.tab.c:495:21: warning: excess elements in scalar initializer
 #define GREATER_AND 294
                     ^~~
yacc.y:2142:11: note: in expansion of macro 'GREATER_AND'
   { ">&", GREATER_AND },
           ^~~~~~~~~~~
y.tab.c:495:21: note: (near initialization for 'other_token_alist[7]')
 #define GREATER_AND 294
                     ^~~
yacc.y:2142:11: note: in expansion of macro 'GREATER_AND'
   { ">&", GREATER_AND },
           ^~~~~~~~~~~
yacc.y:2143:3: warning: braces around scalar initializer
   { ";;", SEMI_SEMI },
   ^
yacc.y:2143:3: note: (near initialization for 'other_token_alist[8]')
yacc.y:2143:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ";;", SEMI_SEMI },
     ^~~~
yacc.y:2143:5: note: (near initialization for 'other_token_alist[8]')
yacc.y:2143:5: error: initializer element is not computable at load time
yacc.y:2143:5: note: (near initialization for 'other_token_alist[8]')
y.tab.c:496:19: warning: excess elements in scalar initializer
 #define SEMI_SEMI 295
                   ^~~
yacc.y:2143:11: note: in expansion of macro 'SEMI_SEMI'
   { ";;", SEMI_SEMI },
           ^~~~~~~~~
y.tab.c:496:19: note: (near initialization for 'other_token_alist[8]')
 #define SEMI_SEMI 295
                   ^~~
yacc.y:2143:11: note: in expansion of macro 'SEMI_SEMI'
   { ";;", SEMI_SEMI },
           ^~~~~~~~~
yacc.y:2144:3: warning: braces around scalar initializer
   { ";&", SEMI_AND },
   ^
yacc.y:2144:3: note: (near initialization for 'other_token_alist[9]')
yacc.y:2144:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ";&", SEMI_AND },
     ^~~~
yacc.y:2144:5: note: (near initialization for 'other_token_alist[9]')
yacc.y:2144:5: error: initializer element is not computable at load time
yacc.y:2144:5: note: (near initialization for 'other_token_alist[9]')
y.tab.c:497:18: warning: excess elements in scalar initializer
 #define SEMI_AND 296
                  ^~~
yacc.y:2144:11: note: in expansion of macro 'SEMI_AND'
   { ";&", SEMI_AND },
           ^~~~~~~~
y.tab.c:497:18: note: (near initialization for 'other_token_alist[9]')
 #define SEMI_AND 296
                  ^~~
yacc.y:2144:11: note: in expansion of macro 'SEMI_AND'
   { ";&", SEMI_AND },
           ^~~~~~~~
yacc.y:2145:3: warning: braces around scalar initializer
   { ";;&", SEMI_SEMI_AND },
   ^
yacc.y:2145:3: note: (near initialization for 'other_token_alist[10]')
yacc.y:2145:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ";;&", SEMI_SEMI_AND },
     ^~~~~
yacc.y:2145:5: note: (near initialization for 'other_token_alist[10]')
yacc.y:2145:5: error: initializer element is not computable at load time
yacc.y:2145:5: note: (near initialization for 'other_token_alist[10]')
y.tab.c:498:23: warning: excess elements in scalar initializer
 #define SEMI_SEMI_AND 297
                       ^~~
yacc.y:2145:12: note: in expansion of macro 'SEMI_SEMI_AND'
   { ";;&", SEMI_SEMI_AND },
            ^~~~~~~~~~~~~
y.tab.c:498:23: note: (near initialization for 'other_token_alist[10]')
 #define SEMI_SEMI_AND 297
                       ^~~
yacc.y:2145:12: note: in expansion of macro 'SEMI_SEMI_AND'
   { ";;&", SEMI_SEMI_AND },
            ^~~~~~~~~~~~~
yacc.y:2146:3: warning: braces around scalar initializer
   { "<<-", LESS_LESS_MINUS },
   ^
yacc.y:2146:3: note: (near initialization for 'other_token_alist[11]')
yacc.y:2146:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "<<-", LESS_LESS_MINUS },
     ^~~~~
yacc.y:2146:5: note: (near initialization for 'other_token_alist[11]')
yacc.y:2146:5: error: initializer element is not computable at load time
yacc.y:2146:5: note: (near initialization for 'other_token_alist[11]')
y.tab.c:499:25: warning: excess elements in scalar initializer
 #define LESS_LESS_MINUS 298
                         ^~~
yacc.y:2146:12: note: in expansion of macro 'LESS_LESS_MINUS'
   { "<<-", LESS_LESS_MINUS },
            ^~~~~~~~~~~~~~~
y.tab.c:499:25: note: (near initialization for 'other_token_alist[11]')
 #define LESS_LESS_MINUS 298
                         ^~~
yacc.y:2146:12: note: in expansion of macro 'LESS_LESS_MINUS'
   { "<<-", LESS_LESS_MINUS },
            ^~~~~~~~~~~~~~~
yacc.y:2147:3: warning: braces around scalar initializer
   { "<<<", LESS_LESS_LESS },
   ^
yacc.y:2147:3: note: (near initialization for 'other_token_alist[12]')
yacc.y:2147:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "<<<", LESS_LESS_LESS },
     ^~~~~
yacc.y:2147:5: note: (near initialization for 'other_token_alist[12]')
yacc.y:2147:5: error: initializer element is not computable at load time
yacc.y:2147:5: note: (near initialization for 'other_token_alist[12]')
y.tab.c:494:24: warning: excess elements in scalar initializer
 #define LESS_LESS_LESS 293
                        ^~~
yacc.y:2147:12: note: in expansion of macro 'LESS_LESS_LESS'
   { "<<<", LESS_LESS_LESS },
            ^~~~~~~~~~~~~~
y.tab.c:494:24: note: (near initialization for 'other_token_alist[12]')
 #define LESS_LESS_LESS 293
                        ^~~
yacc.y:2147:12: note: in expansion of macro 'LESS_LESS_LESS'
   { "<<<", LESS_LESS_LESS },
            ^~~~~~~~~~~~~~
yacc.y:2148:3: warning: braces around scalar initializer
   { "&>", AND_GREATER },
   ^
yacc.y:2148:3: note: (near initialization for 'other_token_alist[13]')
yacc.y:2148:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "&>", AND_GREATER },
     ^~~~
yacc.y:2148:5: note: (near initialization for 'other_token_alist[13]')
yacc.y:2148:5: error: initializer element is not computable at load time
yacc.y:2148:5: note: (near initialization for 'other_token_alist[13]')
y.tab.c:500:21: warning: excess elements in scalar initializer
 #define AND_GREATER 299
                     ^~~
yacc.y:2148:11: note: in expansion of macro 'AND_GREATER'
   { "&>", AND_GREATER },
           ^~~~~~~~~~~
y.tab.c:500:21: note: (near initialization for 'other_token_alist[13]')
 #define AND_GREATER 299
                     ^~~
yacc.y:2148:11: note: in expansion of macro 'AND_GREATER'
   { "&>", AND_GREATER },
           ^~~~~~~~~~~
yacc.y:2149:3: warning: braces around scalar initializer
   { "&>>", AND_GREATER_GREATER },
   ^
yacc.y:2149:3: note: (near initialization for 'other_token_alist[14]')
yacc.y:2149:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "&>>", AND_GREATER_GREATER },
     ^~~~~
yacc.y:2149:5: note: (near initialization for 'other_token_alist[14]')
yacc.y:2149:5: error: initializer element is not computable at load time
yacc.y:2149:5: note: (near initialization for 'other_token_alist[14]')
y.tab.c:501:29: warning: excess elements in scalar initializer
 #define AND_GREATER_GREATER 300
                             ^~~
yacc.y:2149:12: note: in expansion of macro 'AND_GREATER_GREATER'
   { "&>>", AND_GREATER_GREATER },
            ^~~~~~~~~~~~~~~~~~~
y.tab.c:501:29: note: (near initialization for 'other_token_alist[14]')
 #define AND_GREATER_GREATER 300
                             ^~~
yacc.y:2149:12: note: in expansion of macro 'AND_GREATER_GREATER'
   { "&>>", AND_GREATER_GREATER },
            ^~~~~~~~~~~~~~~~~~~
yacc.y:2150:3: warning: braces around scalar initializer
   { "<>", LESS_GREATER },
   ^
yacc.y:2150:3: note: (near initialization for 'other_token_alist[15]')
yacc.y:2150:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "<>", LESS_GREATER },
     ^~~~
yacc.y:2150:5: note: (near initialization for 'other_token_alist[15]')
yacc.y:2150:5: error: initializer element is not computable at load time
yacc.y:2150:5: note: (near initialization for 'other_token_alist[15]')
y.tab.c:502:22: warning: excess elements in scalar initializer
 #define LESS_GREATER 301
                      ^~~
yacc.y:2150:11: note: in expansion of macro 'LESS_GREATER'
   { "<>", LESS_GREATER },
           ^~~~~~~~~~~~
y.tab.c:502:22: note: (near initialization for 'other_token_alist[15]')
 #define LESS_GREATER 301
                      ^~~
yacc.y:2150:11: note: in expansion of macro 'LESS_GREATER'
   { "<>", LESS_GREATER },
           ^~~~~~~~~~~~
yacc.y:2151:3: warning: braces around scalar initializer
   { ">|", GREATER_BAR },
   ^
yacc.y:2151:3: note: (near initialization for 'other_token_alist[16]')
yacc.y:2151:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ">|", GREATER_BAR },
     ^~~~
yacc.y:2151:5: note: (near initialization for 'other_token_alist[16]')
yacc.y:2151:5: error: initializer element is not computable at load time
yacc.y:2151:5: note: (near initialization for 'other_token_alist[16]')
y.tab.c:503:21: warning: excess elements in scalar initializer
 #define GREATER_BAR 302
                     ^~~
yacc.y:2151:11: note: in expansion of macro 'GREATER_BAR'
   { ">|", GREATER_BAR },
           ^~~~~~~~~~~
y.tab.c:503:21: note: (near initialization for 'other_token_alist[16]')
 #define GREATER_BAR 302
                     ^~~
yacc.y:2151:11: note: in expansion of macro 'GREATER_BAR'
   { ">|", GREATER_BAR },
           ^~~~~~~~~~~
yacc.y:2152:3: warning: braces around scalar initializer
   { "|&", BAR_AND },
   ^
yacc.y:2152:3: note: (near initialization for 'other_token_alist[17]')
yacc.y:2152:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "|&", BAR_AND },
     ^~~~
yacc.y:2152:5: note: (near initialization for 'other_token_alist[17]')
yacc.y:2152:5: error: initializer element is not computable at load time
yacc.y:2152:5: note: (near initialization for 'other_token_alist[17]')
y.tab.c:504:17: warning: excess elements in scalar initializer
 #define BAR_AND 303
                 ^~~
yacc.y:2152:11: note: in expansion of macro 'BAR_AND'
   { "|&", BAR_AND },
           ^~~~~~~
y.tab.c:504:17: note: (near initialization for 'other_token_alist[17]')
 #define BAR_AND 303
                 ^~~
yacc.y:2152:11: note: in expansion of macro 'BAR_AND'
   { "|&", BAR_AND },
           ^~~~~~~
yacc.y:2153:3: warning: braces around scalar initializer
   { "EOF", yacc_EOF },
   ^
yacc.y:2153:3: note: (near initialization for 'other_token_alist[18]')
yacc.y:2153:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "EOF", yacc_EOF },
     ^~~~~
yacc.y:2153:5: note: (near initialization for 'other_token_alist[18]')
yacc.y:2153:5: error: initializer element is not computable at load time
yacc.y:2153:5: note: (near initialization for 'other_token_alist[18]')
y.tab.c:505:18: warning: excess elements in scalar initializer
 #define yacc_EOF 304
                  ^~~
yacc.y:2153:12: note: in expansion of macro 'yacc_EOF'
   { "EOF", yacc_EOF },
            ^~~~~~~~
y.tab.c:505:18: note: (near initialization for 'other_token_alist[18]')
 #define yacc_EOF 304
                  ^~~
yacc.y:2153:12: note: in expansion of macro 'yacc_EOF'
   { "EOF", yacc_EOF },
            ^~~~~~~~
yacc.y:2155:3: warning: braces around scalar initializer
   { ">", '>' },
   ^
yacc.y:2155:3: note: (near initialization for 'other_token_alist[19]')
yacc.y:2155:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ">", '>' },
     ^~~
yacc.y:2155:5: note: (near initialization for 'other_token_alist[19]')
yacc.y:2155:5: error: initializer element is not computable at load time
yacc.y:2155:5: note: (near initialization for 'other_token_alist[19]')
yacc.y:2155:10: warning: excess elements in scalar initializer
   { ">", '>' },
          ^~~
yacc.y:2155:10: note: (near initialization for 'other_token_alist[19]')
yacc.y:2156:3: warning: braces around scalar initializer
   { "<", '<' },
   ^
yacc.y:2156:3: note: (near initialization for 'other_token_alist[20]')
yacc.y:2156:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "<", '<' },
     ^~~
yacc.y:2156:5: note: (near initialization for 'other_token_alist[20]')
yacc.y:2156:5: error: initializer element is not computable at load time
yacc.y:2156:5: note: (near initialization for 'other_token_alist[20]')
yacc.y:2156:10: warning: excess elements in scalar initializer
   { "<", '<' },
          ^~~
yacc.y:2156:10: note: (near initialization for 'other_token_alist[20]')
yacc.y:2157:3: warning: braces around scalar initializer
   { "-", '-' },
   ^
yacc.y:2157:3: note: (near initialization for 'other_token_alist[21]')
yacc.y:2157:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "-", '-' },
     ^~~
yacc.y:2157:5: note: (near initialization for 'other_token_alist[21]')
yacc.y:2157:5: error: initializer element is not computable at load time
yacc.y:2157:5: note: (near initialization for 'other_token_alist[21]')
yacc.y:2157:10: warning: excess elements in scalar initializer
   { "-", '-' },
          ^~~
yacc.y:2157:10: note: (near initialization for 'other_token_alist[21]')
yacc.y:2158:3: warning: braces around scalar initializer
   { "{", '{' },
   ^
yacc.y:2158:3: note: (near initialization for 'other_token_alist[22]')
yacc.y:2158:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "{", '{' },
     ^~~
yacc.y:2158:5: note: (near initialization for 'other_token_alist[22]')
yacc.y:2158:5: error: initializer element is not computable at load time
yacc.y:2158:5: note: (near initialization for 'other_token_alist[22]')
yacc.y:2158:10: warning: excess elements in scalar initializer
   { "{", '{' },
          ^~~
yacc.y:2158:10: note: (near initialization for 'other_token_alist[22]')
yacc.y:2159:3: warning: braces around scalar initializer
   { "}", '}' },
   ^
yacc.y:2159:3: note: (near initialization for 'other_token_alist[23]')
yacc.y:2159:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "}", '}' },
     ^~~
yacc.y:2159:5: note: (near initialization for 'other_token_alist[23]')
yacc.y:2159:5: error: initializer element is not computable at load time
yacc.y:2159:5: note: (near initialization for 'other_token_alist[23]')
yacc.y:2159:10: warning: excess elements in scalar initializer
   { "}", '}' },
          ^~~
yacc.y:2159:10: note: (near initialization for 'other_token_alist[23]')
yacc.y:2160:3: warning: braces around scalar initializer
   { ";", ';' },
   ^
yacc.y:2160:3: note: (near initialization for 'other_token_alist[24]')
yacc.y:2160:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ";", ';' },
     ^~~
yacc.y:2160:5: note: (near initialization for 'other_token_alist[24]')
yacc.y:2160:5: error: initializer element is not computable at load time
yacc.y:2160:5: note: (near initialization for 'other_token_alist[24]')
yacc.y:2160:10: warning: excess elements in scalar initializer
   { ";", ';' },
          ^~~
yacc.y:2160:10: note: (near initialization for 'other_token_alist[24]')
yacc.y:2161:3: warning: braces around scalar initializer
   { "(", '(' },
   ^
yacc.y:2161:3: note: (near initialization for 'other_token_alist[25]')
yacc.y:2161:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "(", '(' },
     ^~~
yacc.y:2161:5: note: (near initialization for 'other_token_alist[25]')
yacc.y:2161:5: error: initializer element is not computable at load time
yacc.y:2161:5: note: (near initialization for 'other_token_alist[25]')
yacc.y:2161:10: warning: excess elements in scalar initializer
   { "(", '(' },
          ^~~
yacc.y:2161:10: note: (near initialization for 'other_token_alist[25]')
yacc.y:2162:3: warning: braces around scalar initializer
   { ")", ')' },
   ^
yacc.y:2162:3: note: (near initialization for 'other_token_alist[26]')
yacc.y:2162:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { ")", ')' },
     ^~~
yacc.y:2162:5: note: (near initialization for 'other_token_alist[26]')
yacc.y:2162:5: error: initializer element is not computable at load time
yacc.y:2162:5: note: (near initialization for 'other_token_alist[26]')
yacc.y:2162:10: warning: excess elements in scalar initializer
   { ")", ')' },
          ^~~
yacc.y:2162:10: note: (near initialization for 'other_token_alist[26]')
yacc.y:2163:3: warning: braces around scalar initializer
   { "|", '|' },
   ^
yacc.y:2163:3: note: (near initialization for 'other_token_alist[27]')
yacc.y:2163:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "|", '|' },
     ^~~
yacc.y:2163:5: note: (near initialization for 'other_token_alist[27]')
yacc.y:2163:5: error: initializer element is not computable at load time
yacc.y:2163:5: note: (near initialization for 'other_token_alist[27]')
yacc.y:2163:10: warning: excess elements in scalar initializer
   { "|", '|' },
          ^~~
yacc.y:2163:10: note: (near initialization for 'other_token_alist[27]')
yacc.y:2164:3: warning: braces around scalar initializer
   { "&", '&' },
   ^
yacc.y:2164:3: note: (near initialization for 'other_token_alist[28]')
yacc.y:2164:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "&", '&' },
     ^~~
yacc.y:2164:5: note: (near initialization for 'other_token_alist[28]')
yacc.y:2164:5: error: initializer element is not computable at load time
yacc.y:2164:5: note: (near initialization for 'other_token_alist[28]')
yacc.y:2164:10: warning: excess elements in scalar initializer
   { "&", '&' },
          ^~~
yacc.y:2164:10: note: (near initialization for 'other_token_alist[28]')
yacc.y:2165:3: warning: braces around scalar initializer
   { "newline", '\n' },
   ^
yacc.y:2165:3: note: (near initialization for 'other_token_alist[29]')
yacc.y:2165:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { "newline", '\n' },
     ^~~~~~~~~
yacc.y:2165:5: note: (near initialization for 'other_token_alist[29]')
yacc.y:2165:5: error: initializer element is not computable at load time
yacc.y:2165:5: note: (near initialization for 'other_token_alist[29]')
yacc.y:2165:16: warning: excess elements in scalar initializer
   { "newline", '\n' },
                ^~~~
yacc.y:2165:16: note: (near initialization for 'other_token_alist[29]')
yacc.y:2166:3: warning: braces around scalar initializer
   { (char *)NULL, 0}
   ^
yacc.y:2166:3: note: (near initialization for 'other_token_alist[30]')
yacc.y:2166:5: warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
   { (char *)NULL, 0}
     ^
yacc.y:2166:5: note: (near initialization for 'other_token_alist[30]')
yacc.y:2166:19: warning: excess elements in scalar initializer
   { (char *)NULL, 0}
                   ^
yacc.y:2166:19: note: (near initialization for 'other_token_alist[30]')
yacc.y:2182:8: error: variable 'dstack' has initializer but incomplete type
 struct dstack dstack = {  (char *)NULL, 0, 0 };
        ^~~~~~
yacc.y:2182:27: warning: excess elements in struct initializer
 struct dstack dstack = {  (char *)NULL, 0, 0 };
                           ^
yacc.y:2182:27: note: (near initialization for 'dstack')
yacc.y:2182:41: warning: excess elements in struct initializer
 struct dstack dstack = {  (char *)NULL, 0, 0 };
                                         ^
yacc.y:2182:41: note: (near initialization for 'dstack')
yacc.y:2182:44: warning: excess elements in struct initializer
 struct dstack dstack = {  (char *)NULL, 0, 0 };
                                            ^
yacc.y:2182:44: note: (near initialization for 'dstack')
yacc.y:2187:15: error: variable 'temp_dstack' has initializer but incomplete type
 static struct dstack temp_dstack = { (char *)NULL, 0, 0 };
               ^~~~~~
yacc.y:2187:38: warning: excess elements in struct initializer
 static struct dstack temp_dstack = { (char *)NULL, 0, 0 };
                                      ^
yacc.y:2187:38: note: (near initialization for 'temp_dstack')
yacc.y:2187:52: warning: excess elements in struct initializer
 static struct dstack temp_dstack = { (char *)NULL, 0, 0 };
                                                    ^
yacc.y:2187:52: note: (near initialization for 'temp_dstack')
yacc.y:2187:55: warning: excess elements in struct initializer
 static struct dstack temp_dstack = { (char *)NULL, 0, 0 };
                                                       ^
yacc.y:2187:55: note: (near initialization for 'temp_dstack')
yacc.y: In function 'shell_getc':
yacc.y:2225:3: error: 'QUIT' undeclared (first use in this function)
   QUIT;
   ^~~~
yacc.y:2228:7: error: 'sigwinch_received' undeclared (first use in this function)
   if (sigwinch_received)
       ^~~~~~~~~~~~~~~~~
yacc.y:2231:7: warning: implicit declaration of function 'get_new_window_size' [-Wimplicit-function-declaration]
       get_new_window_size (0, (int *)0, (int *)0);
       ^~~~~~~~~~~~~~~~~~~
yacc.y:2274:11: error: 'interactive_shell' undeclared (first use in this function)
       if (interactive_shell == 0 || SHOULD_PROMPT())
           ^~~~~~~~~~~~~~~~~
yacc.y:1301:4: error: 'interactive' undeclared (first use in this function)
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
    ^~~~~~~~~~~
yacc.y:2274:37: note: in expansion of macro 'SHOULD_PROMPT'
       if (interactive_shell == 0 || SHOULD_PROMPT())
                                     ^~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:2274:37: note: in expansion of macro 'SHOULD_PROMPT'
       if (interactive_shell == 0 || SHOULD_PROMPT())
                                     ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:2274:37: note: in expansion of macro 'SHOULD_PROMPT'
       if (interactive_shell == 0 || SHOULD_PROMPT())
                                     ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:2274:37: note: in expansion of macro 'SHOULD_PROMPT'
       if (interactive_shell == 0 || SHOULD_PROMPT())
                                     ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:2274:37: note: in expansion of macro 'SHOULD_PROMPT'
       if (interactive_shell == 0 || SHOULD_PROMPT())
                                     ^~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:2290:11: note: in expansion of macro 'SHOULD_PROMPT'
       if (SHOULD_PROMPT())
           ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:2290:11: note: in expansion of macro 'SHOULD_PROMPT'
       if (SHOULD_PROMPT())
           ^~~~~~~~~~~~~
yacc.y:2294:21: error: request for member 'type' in something not a structure or union
       if (bash_input.type == st_stream)
                     ^
yacc.y:2316:33: error: 'SIZE_MAX' undeclared (first use in this function)
    if (shell_input_line_size > (SIZE_MAX - 256))
                                 ^~~~~~~~
yacc.y:2316:33: note: 'SIZE_MAX' is defined in header '<stdint.h>'; did you forget to '#include <stdint.h>'?
yacc.y:1292:1:
+#include <stdint.h>
 %%
yacc.y:2316:33:
    if (shell_input_line_size > (SIZE_MAX - 256))
                                 ^~~~~~~~
yacc.y:2316:30: warning: comparison between pointer and integer
    if (shell_input_line_size > (SIZE_MAX - 256))
                              ^
yacc.y:2320:10: warning: assignment to 'size_t' {aka 'long unsigned int'} from 'int *' makes integer from pointer without a cast [-Wint-conversion]
        n = SIZE_MAX - i; /* how much more can we put into the buffer? */
          ^
yacc.y:2324:7: warning: implicit declaration of function 'internal_warning' [-Wimplicit-function-declaration]
       internal_warning(_("shell_getc: shell_input_line_size (%zu) exceeds SIZE_MAX (%lu): line truncated"), shell_input_line_size, (unsigned long)SIZE_MAX);
       ^~~~~~~~~~~~~~~~
yacc.y:2324:24: warning: implicit declaration of function '_' [-Wimplicit-function-declaration]
       internal_warning(_("shell_getc: shell_input_line_size (%zu) exceeds SIZE_MAX (%lu): line truncated"), shell_input_line_size, (unsigned long)SIZE_MAX);
                        ^
yacc.y:2328:34: warning: comparison between pointer and integer
        if (shell_input_line_size < SIZE_MAX)
                                  ^
yacc.y:2330:27: warning: assignment to 'size_t' {aka 'long unsigned int'} from 'int *' makes integer from pointer without a cast [-Wint-conversion]
     shell_input_line_size = SIZE_MAX;
                           ^
yacc.y:2331:24: warning: implicit declaration of function 'xrealloc'; did you mean 'malloc'? [-Wimplicit-function-declaration]
     shell_input_line = xrealloc (shell_input_line, shell_input_line_size);
                        ^~~~~~~~
                        malloc
yacc.y:2331:22: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     shell_input_line = xrealloc (shell_input_line, shell_input_line_size);
                      ^
yacc.y:2339:22: error: request for member 'type' in something not a structure or union
        if (bash_input.type == st_stream)
                      ^
yacc.y:2434:8: error: 'echo_input_at_read' undeclared (first use in this function)
    if (echo_input_at_read && (shell_input_line[0] ||
        ^~~~~~~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:2443:8: note: in expansion of macro 'SHOULD_PROMPT'
    if (SHOULD_PROMPT ())
        ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:2443:8: note: in expansion of macro 'SHOULD_PROMPT'
    if (SHOULD_PROMPT ())
        ^~~~~~~~~~~~~
yacc.y:2452:30: warning: comparison between pointer and integer
    if (shell_input_line_size < SIZE_MAX-3 && (shell_input_line_len+3 > shell_input_line_size))
                              ^
yacc.y:2453:25: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
      shell_input_line = (char *)xrealloc (shell_input_line,
                         ^
yacc.y:2460:18: error: request for member 'type' in something not a structure or union
    if (bash_input.type == st_string && expanding_alias() == 0 && last_was_backslash && c == EOF && remove_quoted_newline)
                  ^
yacc.y:2460:27: error: 'st_string' undeclared (first use in this function); did you mean 'si_stime'?
    if (bash_input.type == st_string && expanding_alias() == 0 && last_was_backslash && c == EOF && remove_quoted_newline)
                           ^~~~~~~~~
                           si_stime
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:2499:6: note: in expansion of macro 'SHOULD_PROMPT'
  if (SHOULD_PROMPT ())
      ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:2499:6: note: in expansion of macro 'SHOULD_PROMPT'
  if (SHOULD_PROMPT ())
      ^~~~~~~~~~~~~
yacc.y: In function 'execute_variable_command':
yacc.y:2608:3: error: unknown type name 'sh_parser_state_t'
   sh_parser_state_t ps;
   ^~~~~~~~~~~~~~~~~
yacc.y:2610:3: warning: implicit declaration of function 'save_parser_state'; did you mean 'save_token_state'? [-Wimplicit-function-declaration]
   save_parser_state (&ps);
   ^~~~~~~~~~~~~~~~~
   save_token_state
yacc.y:2611:18: warning: implicit declaration of function 'get_string_value'; did you mean 'yy_string_unget'? [-Wimplicit-function-declaration]
   last_lastarg = get_string_value ("_");
                  ^~~~~~~~~~~~~~~~
                  yy_string_unget
yacc.y:2611:16: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   last_lastarg = get_string_value ("_");
                ^
yacc.y:2613:18: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     last_lastarg = savestring (last_lastarg);
                  ^
yacc.y:2615:3: warning: implicit declaration of function 'parse_and_execute' [-Wimplicit-function-declaration]
   parse_and_execute (savestring (command), vname, SEVAL_NONINT|SEVAL_NOHIST);
   ^~~~~~~~~~~~~~~~~
yacc.y:2615:51: error: 'SEVAL_NONINT' undeclared (first use in this function)
   parse_and_execute (savestring (command), vname, SEVAL_NONINT|SEVAL_NOHIST);
                                                   ^~~~~~~~~~~~
yacc.y:2615:64: error: 'SEVAL_NOHIST' undeclared (first use in this function); did you mean 'SA_NOMASK'?
   parse_and_execute (savestring (command), vname, SEVAL_NONINT|SEVAL_NOHIST);
                                                                ^~~~~~~~~~~~
                                                                SA_NOMASK
yacc.y:2615:63: error: invalid operands to binary | (have 'int *' and 'int *')
   parse_and_execute (savestring (command), vname, SEVAL_NONINT|SEVAL_NOHIST);
                                                   ~~~~~~~~~~~~^
yacc.y:2617:3: warning: implicit declaration of function 'restore_parser_state'; did you mean 'restore_token_state'? [-Wimplicit-function-declaration]
   restore_parser_state (&ps);
   ^~~~~~~~~~~~~~~~~~~~
   restore_token_state
yacc.y:2618:3: warning: implicit declaration of function 'bind_variable' [-Wimplicit-function-declaration]
   bind_variable ("_", last_lastarg, 0);
   ^~~~~~~~~~~~~
yacc.y: In function 'yylex':
yacc.y:2654:7: error: 'interactive' undeclared (first use in this function)
   if (interactive && (current_token == 0 || current_token == '\n'))
       ^~~~~~~~~~~
yacc.y:2660:60: warning: implicit declaration of function 'time_to_check_mail' [-Wimplicit-function-declaration]
       if (prompt_is_ps1 && parse_and_execute_level == 0 && time_to_check_mail ())
                                                            ^~~~~~~~~~~~~~~~~~
yacc.y:2662:4: warning: implicit declaration of function 'check_mail' [-Wimplicit-function-declaration]
    check_mail ();
    ^~~~~~~~~~
yacc.y:2663:4: warning: implicit declaration of function 'reset_mail_timer' [-Wimplicit-function-declaration]
    reset_mail_timer ();
    ^~~~~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:2668:33: note: in expansion of macro 'SHOULD_PROMPT'
       if (token_to_read == 0 && SHOULD_PROMPT ())
                                 ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:2668:33: note: in expansion of macro 'SHOULD_PROMPT'
       if (token_to_read == 0 && SHOULD_PROMPT ())
                                 ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:2668:33: note: in expansion of macro 'SHOULD_PROMPT'
       if (token_to_read == 0 && SHOULD_PROMPT ())
                                 ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:2668:33: note: in expansion of macro 'SHOULD_PROMPT'
       if (token_to_read == 0 && SHOULD_PROMPT ())
                                 ^~~~~~~~~~~~~
yacc.y:2677:23: error: 'PST_EOFTOKEN' undeclared (first use in this function)
   if ((parser_state & PST_EOFTOKEN) && current_token == shell_eof_token)
                       ^~~~~~~~~~~~
yacc.y:2677:21: error: invalid operands to binary & (have 'int' and 'int *')
   if ((parser_state & PST_EOFTOKEN) && current_token == shell_eof_token)
                     ^
yacc.y:2680:21: error: request for member 'type' in something not a structure or union
       if (bash_input.type == st_string)
                     ^
yacc.y:2680:30: error: 'st_string' undeclared (first use in this function); did you mean 'si_stime'?
       if (bash_input.type == st_string)
                              ^~~~~~~~~
                              si_stime
yacc.y:2683:19: error: wrong type argument to bit-complement
   parser_state &= ~PST_EOFTOKEN;
                   ^
yacc.y:2683:16: error: invalid operands to binary & (have 'int' and 'int *')
   parser_state &= ~PST_EOFTOKEN;
                ^~ ~
yacc.y: At top level:
yacc.y:2693:1: warning: conflicting types for 'push_heredoc'
 push_heredoc (r)
 ^~~~~~~~~~~~
yacc.y:2693:1: error: static declaration of 'push_heredoc' follows non-static declaration
yacc.y:532:6: note: previous implicit declaration of 'push_heredoc' was here
      push_heredoc ($$);
      ^~~~~~~~~~~~
yacc.y: In function 'push_heredoc':
yacc.y:2694:6: error: unknown type name 'REDIRECT'; did you mean 'RESET'?
      REDIRECT *r;
      ^~~~~~~~
      RESET
yacc.y:2696:21: warning: comparison between pointer and integer
   if (need_here_doc >= HEREDOC_MAX)
                     ^~
yacc.y:2698:33: error: 'EX_BADUSAGE' undeclared (first use in this function)
       last_command_exit_value = EX_BADUSAGE;
                                 ^~~~~~~~~~~
yacc.y:2698:31: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
       last_command_exit_value = EX_BADUSAGE;
                               ^
yacc.y:2700:28: warning: passing argument 1 of 'report_syntax_error' makes pointer from integer without a cast [-Wint-conversion]
       report_syntax_error (_("maximum here-document count exceeded"));
                            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/features.h:367,
                 from /usr/include/stdio.h:27,
                 from yacc.y:37:
yacc.y:209:38: note: expected 'char *' but argument is of type 'int'
 static void report_syntax_error __P((char *));
                                      ^~~~~~
yacc.y:2701:7: warning: implicit declaration of function 'reset_parser' [-Wimplicit-function-declaration]
       reset_parser ();
       ^~~~~~~~~~~~
yacc.y:2702:7: warning: implicit declaration of function 'exit_shell' [-Wimplicit-function-declaration]
       exit_shell (last_command_exit_value);
       ^~~~~~~~~~
yacc.y:2704:32: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
   redir_stack[need_here_doc++] = r;
                                ^
yacc.y: At top level:
yacc.y:2708:1: warning: conflicting types for 'gather_here_documents'
 gather_here_documents ()
 ^~~~~~~~~~~~~~~~~~~~~
yacc.y:1075:8: note: previous implicit declaration of 'gather_here_documents' was here
        gather_here_documents ();
        ^~~~~~~~~~~~~~~~~~~~~
yacc.y: In function 'gather_here_documents':
yacc.y:2716:23: error: 'PST_HEREDOC' undeclared (first use in this function)
       parser_state |= PST_HEREDOC;
                       ^~~~~~~~~~~
yacc.y:2716:20: error: invalid operands to binary | (have 'int' and 'int *')
       parser_state |= PST_HEREDOC;
                    ^~ ~~~~~~~~~~~
yacc.y:2717:7: warning: implicit declaration of function 'make_here_document'; did you mean 'gather_here_documents'? [-Wimplicit-function-declaration]
       make_here_document (redir_stack[r++], line_number);
       ^~~~~~~~~~~~~~~~~~
       gather_here_documents
yacc.y:2718:23: error: wrong type argument to bit-complement
       parser_state &= ~PST_HEREDOC;
                       ^
yacc.y:2718:20: error: invalid operands to binary & (have 'int' and 'int *')
       parser_state &= ~PST_HEREDOC;
                    ^~ ~
yacc.y: In function 'special_case_tokens':
yacc.y:2947:20: error: 'PST_CASEPAT' undeclared (first use in this function)
    parser_state |= PST_CASEPAT;
                    ^~~~~~~~~~~
yacc.y:2947:17: error: invalid operands to binary | (have 'int' and 'int *')
    parser_state |= PST_CASEPAT;
                 ^~ ~~~~~~~~~~~
yacc.y:2971:11: warning: implicit declaration of function 'STREQ' [-Wimplicit-function-declaration]
       if (STREQ (tokstr, "esac"))
           ^~~~~
yacc.y:2973:20: error: wrong type argument to bit-complement
    parser_state &= ~PST_CASEPAT;
                    ^
yacc.y:2973:17: error: invalid operands to binary & (have 'int' and 'int *')
    parser_state &= ~PST_CASEPAT;
                 ^~ ~
yacc.y:2979:22: error: 'PST_ALLOWOPNBRC' undeclared (first use in this function)
   if (parser_state & PST_ALLOWOPNBRC)
                      ^~~~~~~~~~~~~~~
yacc.y:2979:20: error: invalid operands to binary & (have 'int' and 'int *')
   if (parser_state & PST_ALLOWOPNBRC)
                    ^
yacc.y:2981:23: error: wrong type argument to bit-complement
       parser_state &= ~PST_ALLOWOPNBRC;
                       ^
yacc.y:2981:20: error: invalid operands to binary & (have 'int' and 'int *')
       parser_state &= ~PST_ALLOWOPNBRC;
                    ^~ ~
yacc.y: At top level:
yacc.y:3026:1: warning: conflicting types for 'reset_parser'
 reset_parser ()
 ^~~~~~~~~~~~
yacc.y:2701:7: note: previous implicit declaration of 'reset_parser' was here
       reset_parser ();
       ^~~~~~~~~~~~
yacc.y: In function 'reset_parser':
yacc.y:3028:9: error: invalid use of undefined type 'struct dstack'
   dstack.delimiter_depth = 0; /* No delimiters found so far. */
         ^
yacc.y:3054:24: error: 'WORD_DESC' undeclared (first use in this function)
   word_desc_to_read = (WORD_DESC *)NULL;
                        ^~~~~~~~~
yacc.y:3054:35: error: expected expression before ')' token
   word_desc_to_read = (WORD_DESC *)NULL;
                                   ^
yacc.y:3054:34: error: invalid operands to binary * (have 'int *' and 'int *')
   word_desc_to_read = (WORD_DESC *)NULL;
                        ~~~~~~~~~ ^
yacc.y:3054:23: error: called object is not a function or function pointer
   word_desc_to_read = (WORD_DESC *)NULL;
                       ^
yacc.y: In function 'read_token':
yacc.y:3085:25: error: 'WORD_DESC' undeclared (first use in this function)
    word_desc_to_read = (WORD_DESC *)NULL;
                         ^~~~~~~~~
yacc.y:3085:36: error: expected expression before ')' token
    word_desc_to_read = (WORD_DESC *)NULL;
                                    ^
yacc.y:3085:35: error: invalid operands to binary * (have 'int *' and 'int *')
    word_desc_to_read = (WORD_DESC *)NULL;
                         ~~~~~~~~~ ^
yacc.y:3085:24: error: called object is not a function or function pointer
    word_desc_to_read = (WORD_DESC *)NULL;
                        ^
yacc.y:3115:49: warning: implicit declaration of function 'shellblank'; did you mean 'shell_getc'? [-Wimplicit-function-declaration]
   while ((character = shell_getc (1)) != EOF && shellblank (character))
                                                 ^~~~~~~~~~
                                                 shell_getc
yacc.y:3124:35: error: 'interactive' undeclared (first use in this function)
   if MBTEST(character == '#' && (!interactive || interactive_comments))
                                   ^~~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3124:50: error: 'interactive_comments' undeclared (first use in this function)
   if MBTEST(character == '#' && (!interactive || interactive_comments))
                                                  ^~~~~~~~~~~~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3143:24: error: 'PST_ASSIGNOK' undeclared (first use in this function); did you mean 'SI_SIGIO'?
       parser_state &= ~PST_ASSIGNOK;
                        ^~~~~~~~~~~~
                        SI_SIGIO
yacc.y:3143:23: error: wrong type argument to bit-complement
       parser_state &= ~PST_ASSIGNOK;
                       ^
yacc.y:3143:20: error: invalid operands to binary & (have 'int' and 'int *')
       parser_state &= ~PST_ASSIGNOK;
                    ^~ ~
yacc.y:3148:22: error: 'PST_REGEXP' undeclared (first use in this function)
   if (parser_state & PST_REGEXP)
                      ^~~~~~~~~~
yacc.y:3148:20: error: invalid operands to binary & (have 'int' and 'int *')
   if (parser_state & PST_REGEXP)
                    ^
yacc.y:3152:13: warning: implicit declaration of function 'shellmeta'; did you mean 'shell_getc'? [-Wimplicit-function-declaration]
   if MBTEST(shellmeta (character) && ((parser_state & PST_DBLPAREN) == 0))
             ^~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3152:55: error: 'PST_DBLPAREN' undeclared (first use in this function)
   if MBTEST(shellmeta (character) && ((parser_state & PST_DBLPAREN) == 0))
                                                       ^~~~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3152:53: error: invalid operands to binary & (have 'int' and 'int *')
   if MBTEST(shellmeta (character) && ((parser_state & PST_DBLPAREN) == 0))
                                                     ^
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3161:23: error: wrong type argument to bit-complement
       parser_state &= ~PST_ASSIGNOK;
                       ^
yacc.y:3161:20: error: invalid operands to binary & (have 'int' and 'int *')
       parser_state &= ~PST_ASSIGNOK;
                    ^~ ~
yacc.y:3168:27: error: 'PST_CMDSUBST' undeclared (first use in this function)
       if ((parser_state & PST_CMDSUBST) && character == shell_eof_token)
                           ^~~~~~~~~~~~
yacc.y:3168:25: error: invalid operands to binary & (have 'int' and 'int *')
       if ((parser_state & PST_CMDSUBST) && character == shell_eof_token)
                         ^
yacc.y:3195:24: error: 'PST_CASEPAT' undeclared (first use in this function)
        parser_state |= PST_CASEPAT;
                        ^~~~~~~~~~~
yacc.y:3195:21: error: invalid operands to binary | (have 'int' and 'int *')
        parser_state |= PST_CASEPAT;
                     ^~ ~~~~~~~~~~~
yacc.y:3248:17: error: invalid operands to binary | (have 'int' and 'int *')
    parser_state |= PST_CASEPAT;
                 ^~ ~~~~~~~~~~~
yacc.y:3262:20: error: 'PST_ALLOWOPNBRC' undeclared (first use in this function)
    parser_state |= PST_ALLOWOPNBRC;
                    ^~~~~~~~~~~~~~~
yacc.y:3262:17: error: invalid operands to binary | (have 'int' and 'int *')
    parser_state |= PST_ALLOWOPNBRC;
                 ^~ ~~~~~~~~~~~~~~~
yacc.y:3272:51: error: invalid operands to binary & (have 'int' and 'int *')
       if MBTEST(character == '(' && (parser_state & PST_CASEPAT) == 0) /* ) */
                                                   ^
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3273:18: error: 'PST_SUBSHELL' undeclared (first use in this function)
  parser_state |= PST_SUBSHELL;
                  ^~~~~~~~~~~~
yacc.y:3273:15: error: invalid operands to binary | (have 'int' and 'int *')
  parser_state |= PST_SUBSHELL;
               ^~ ~~~~~~~~~~~~
yacc.y:3275:36: error: invalid operands to binary & (have 'int' and 'int *')
       else if MBTEST((parser_state & PST_CASEPAT) && character == ')')
                                    ^
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3276:18: error: wrong type argument to bit-complement
  parser_state &= ~PST_CASEPAT;
                  ^
yacc.y:3276:15: error: invalid operands to binary & (have 'int' and 'int *')
  parser_state &= ~PST_CASEPAT;
               ^~ ~
yacc.y:3278:36: error: invalid operands to binary & (have 'int' and 'int *')
       else if MBTEST((parser_state & PST_SUBSHELL) && character == ')')
                                    ^
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3279:18: error: wrong type argument to bit-complement
  parser_state &= ~PST_SUBSHELL;
                  ^
yacc.y:3279:15: error: invalid operands to binary & (have 'int' and 'int *')
  parser_state &= ~PST_SUBSHELL;
               ^~ ~
yacc.y: In function 'parse_matched_pair':
yacc.y:3367:43: error: 'DOLBRACE_PARAM' undeclared (first use in this function)
   dolbrace_state = (flags & P_DOLBRACE) ? DOLBRACE_PARAM : 0;
                                           ^~~~~~~~~~~~~~
yacc.y:3367:18: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
   dolbrace_state = (flags & P_DOLBRACE) ? DOLBRACE_PARAM : 0;
                  ^
yacc.y:3379:9: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   ret = (char *)xmalloc (retsize = 64);
         ^
yacc.y:3390:4: warning: implicit declaration of function 'parser_error'; did you mean 'perror'? [-Wimplicit-function-declaration]
    parser_error (start_lineno, _("unexpected EOF while looking for matching `%c'"), close);
    ^~~~~~~~~~~~
    perror
yacc.y:1301:4: error: 'interactive' undeclared (first use in this function)
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
    ^~~~~~~~~~~
yacc.y:3396:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:3396:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:3396:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:3396:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:3396:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:3430:20: error: 'CTLESC' undeclared (first use in this function)
    if MBTEST(ch == CTLESC)
                    ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3430:17: warning: comparison between pointer and integer
    if MBTEST(ch == CTLESC)
                 ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3431:20: warning: assignment to 'char' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      ret[retind++] = CTLESC;
                    ^
yacc.y:3439:38: error: 'PST_REPARSE' undeclared (first use in this function)
       else if MBTEST((parser_state & PST_REPARSE) && open == '\'' && (ch == CTLESC || ch == CTLNUL))
                                      ^~~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3439:36: error: invalid operands to binary & (have 'int' and 'int *')
       else if MBTEST((parser_state & PST_REPARSE) && open == '\'' && (ch == CTLESC || ch == CTLNUL))
                                    ^
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3439:74: warning: comparison between pointer and integer
       else if MBTEST((parser_state & PST_REPARSE) && open == '\'' && (ch == CTLESC || ch == CTLNUL))
                                                                          ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3439:93: error: 'CTLNUL' undeclared (first use in this function)
       else if MBTEST((parser_state & PST_REPARSE) && open == '\'' && (ch == CTLESC || ch == CTLNUL))
                                                                                             ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3439:90: warning: comparison between pointer and integer
       else if MBTEST((parser_state & PST_REPARSE) && open == '\'' && (ch == CTLESC || ch == CTLNUL))
                                                                                          ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3445:25: warning: comparison between pointer and integer
       else if MBTEST(ch == CTLESC || ch == CTLNUL) /* special shell escapes */
                         ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3445:41: warning: comparison between pointer and integer
       else if MBTEST(ch == CTLESC || ch == CTLNUL) /* special shell escapes */
                                         ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3448:18: warning: assignment to 'char' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
    ret[retind++] = CTLESC;
                  ^
yacc.y:3488:29: warning: comparison between pointer and integer
    if MBTEST(dolbrace_state == DOLBRACE_PARAM && ch == '%' && retind > 1)
                             ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3489:23: error: 'DOLBRACE_QUOTE' undeclared (first use in this function); did you mean 'P_BACKQUOTE'?
      dolbrace_state = DOLBRACE_QUOTE;
                       ^~~~~~~~~~~~~~
                       P_BACKQUOTE
yacc.y:3489:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_QUOTE;
                     ^
yacc.y:3491:34: warning: comparison between pointer and integer
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && ch == '#' && retind > 1)
                                  ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3492:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_QUOTE;
                     ^
yacc.y:3494:34: warning: comparison between pointer and integer
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && ch == '/' && retind > 1)
                                  ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3495:23: error: 'DOLBRACE_QUOTE2' undeclared (first use in this function); did you mean 'P_BACKQUOTE'?
      dolbrace_state = DOLBRACE_QUOTE2; /* XXX */
                       ^~~~~~~~~~~~~~~
                       P_BACKQUOTE
yacc.y:3495:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_QUOTE2; /* XXX */
                     ^
yacc.y:3497:34: warning: comparison between pointer and integer
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && ch == '^' && retind > 1)
                                  ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3498:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_QUOTE;
                     ^
yacc.y:3500:34: warning: comparison between pointer and integer
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && ch == ',' && retind > 1)
                                  ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3501:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_QUOTE;
                     ^
yacc.y:3502:34: warning: comparison between pointer and integer
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && strchr ("#%^,~:-=?+/", ch) != 0)
                                  ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3502:55: warning: implicit declaration of function 'strchr' [-Wimplicit-function-declaration]
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && strchr ("#%^,~:-=?+/", ch) != 0)
                                                       ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3502:55: warning: incompatible implicit declaration of built-in function 'strchr'
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && strchr ("#%^,~:-=?+/", ch) != 0)
                                                       ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3502:55: note: include '<string.h>' or provide a declaration of 'strchr'
yacc.y:1292:1:
+#include <string.h>
 %%
yacc.y:3502:55:
    else if MBTEST(dolbrace_state == DOLBRACE_PARAM && strchr ("#%^,~:-=?+/", ch) != 0)
                                                       ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3503:23: error: 'DOLBRACE_OP' undeclared (first use in this function); did you mean 'P_DOLBRACE'?
      dolbrace_state = DOLBRACE_OP;
                       ^~~~~~~~~~~
                       P_DOLBRACE
yacc.y:3503:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_OP;
                     ^
yacc.y:3504:34: warning: comparison between pointer and integer
    else if MBTEST(dolbrace_state == DOLBRACE_OP && strchr ("#%^,~:-=?+/", ch) == 0)
                                  ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3505:23: error: 'DOLBRACE_WORD' undeclared (first use in this function)
      dolbrace_state = DOLBRACE_WORD;
                       ^~~~~~~~~~~~~
yacc.y:3505:21: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      dolbrace_state = DOLBRACE_WORD;
                     ^
yacc.y:3513:36: error: 'shell_compatibility_level' undeclared (first use in this function); did you mean 'shell_input_line_len'?
       if MBTEST(posixly_correct && shell_compatibility_level > 41 && dolbrace_state != DOLBRACE_QUOTE && dolbrace_state != DOLBRACE_QUOTE2 && (flags & P_DQUOTE) && (flags & P_DOLBRACE) && ch == '\'')
                                    ^~~~~~~~~~~~~~~~~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3513:62: warning: comparison between pointer and integer
       if MBTEST(posixly_correct && shell_compatibility_level > 41 && dolbrace_state != DOLBRACE_QUOTE && dolbrace_state != DOLBRACE_QUOTE2 && (flags & P_DQUOTE) && (flags & P_DOLBRACE) && ch == '\'')
                                                              ^
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3513:85: warning: comparison between pointer and integer
       if MBTEST(posixly_correct && shell_compatibility_level > 41 && dolbrace_state != DOLBRACE_QUOTE && dolbrace_state != DOLBRACE_QUOTE2 && (flags & P_DQUOTE) && (flags & P_DOLBRACE) && ch == '\'')
                                                                                     ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3513:121: warning: comparison between pointer and integer
       if MBTEST(posixly_correct && shell_compatibility_level > 41 && dolbrace_state != DOLBRACE_QUOTE && dolbrace_state != DOLBRACE_QUOTE2 && (flags & P_DQUOTE) && (flags & P_DOLBRACE) && ch == '\'')
                                                                                                                         ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3520:14: warning: implicit declaration of function 'shellquote'; did you mean 'shell_getc'? [-Wimplicit-function-declaration]
    if MBTEST(shellquote (ch))
              ^~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:2197:13: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
             ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2197:38: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
                                      ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2198:4: error: invalid use of undefined type 'struct dstack'
  ds.delimiters = (char *)xrealloc \
    ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2199:7: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
       ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2199:23: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                       ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2199:47: error: invalid operands to binary * (have 'int *' and 'long unsigned int')
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                    ~                          ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2198:18: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  ds.delimiters = (char *)xrealloc \
                  ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2200:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
         ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2200:23: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
                       ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2200:20: error: array subscript is not an integer
       ds.delimiters[ds.delimiter_depth] = character; \
                    ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2201:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiter_depth++; \
         ^
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2201:25: error: lvalue required as increment operand
       ds.delimiter_depth++; \
                         ^~
yacc.y:3523:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, ch);
        ^~~~~~~~~~~~~~
yacc.y:2205:29: error: invalid use of undefined type 'struct dstack'
 #define pop_delimiter(ds) ds.delimiter_depth--
                             ^
yacc.y:3528:8: note: in expansion of macro 'pop_delimiter'
        pop_delimiter (dstack);
        ^~~~~~~~~~~~~
yacc.y:2205:45: error: lvalue required as decrement operand
 #define pop_delimiter(ds) ds.delimiter_depth--
                                             ^~
yacc.y:3528:8: note: in expansion of macro 'pop_delimiter'
        pop_delimiter (dstack);
        ^~~~~~~~~~~~~
yacc.y:3534:14: warning: implicit declaration of function 'ansiexpand'; did you mean 'si_band'? [-Wimplicit-function-declaration]
     ttrans = ansiexpand (nestret, 0, nestlen - 1, &ttranslen);
              ^~~~~~~~~~
              si_band
yacc.y:3534:12: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ttrans = ansiexpand (nestret, 0, nestlen - 1, &ttranslen);
            ^
yacc.y:3535:5: warning: implicit declaration of function 'xfree'; did you mean 'free'? [-Wimplicit-function-declaration]
     xfree (nestret);
     ^~~~~
     free
yacc.y:3542:36: warning: comparison between pointer and integer
     if ((shell_compatibility_level > 42) && (rflags & P_DQUOTE) && (dolbrace_state == DOLBRACE_QUOTE2) && (flags & P_DOLBRACE))
                                    ^
yacc.y:3542:84: warning: comparison between pointer and integer
     if ((shell_compatibility_level > 42) && (rflags & P_DQUOTE) && (dolbrace_state == DOLBRACE_QUOTE2) && (flags & P_DOLBRACE))
                                                                                    ^~
yacc.y:3544:19: warning: implicit declaration of function 'sh_single_quote' [-Wimplicit-function-declaration]
         nestret = sh_single_quote (ttrans);
                   ^~~~~~~~~~~~~~~
yacc.y:3544:17: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
         nestret = sh_single_quote (ttrans);
                 ^
yacc.y:3546:19: warning: implicit declaration of function 'strlen' [-Wimplicit-function-declaration]
         nestlen = strlen (nestret);
                   ^~~~~~
yacc.y:3546:19: warning: incompatible implicit declaration of built-in function 'strlen'
yacc.y:3546:19: note: include '<string.h>' or provide a declaration of 'strlen'
yacc.y:3550:17: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
         nestret = sh_single_quote (ttrans);
                 ^
yacc.y:3552:19: warning: incompatible implicit declaration of built-in function 'strlen'
         nestlen = strlen (nestret);
                   ^~~~~~
yacc.y:3552:19: note: include '<string.h>' or provide a declaration of 'strlen'
yacc.y:3564:14: warning: implicit declaration of function 'localeexpand' [-Wimplicit-function-declaration]
     ttrans = localeexpand (nestret, 0, nestlen - 1, start_lineno, &ttranslen);
              ^~~~~~~~~~~~
yacc.y:3564:12: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ttrans = localeexpand (nestret, 0, nestlen - 1, start_lineno, &ttranslen);
            ^
yacc.y:3567:15: warning: implicit declaration of function 'sh_mkdoublequoted' [-Wimplicit-function-declaration]
     nestret = sh_mkdoublequoted (ttrans, ttranslen, 0);
               ^~~~~~~~~~~~~~~~~
yacc.y:3567:13: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     nestret = sh_mkdoublequoted (ttrans, ttranslen, 0);
             ^
yacc.y:3348:2: warning: implicit declaration of function 'strcpy' [-Wimplicit-function-declaration]
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3573:8: note: in expansion of macro 'APPEND_NESTRET'
        APPEND_NESTRET ();
        ^~~~~~~~~~~~~~
yacc.y:3348:2: warning: incompatible implicit declaration of built-in function 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3573:8: note: in expansion of macro 'APPEND_NESTRET'
        APPEND_NESTRET ();
        ^~~~~~~~~~~~~~
yacc.y:3348:2: note: include '<string.h>' or provide a declaration of 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3573:8: note: in expansion of macro 'APPEND_NESTRET'
        APPEND_NESTRET ();
        ^~~~~~~~~~~~~~
yacc.y:3348:2: warning: incompatible implicit declaration of built-in function 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3587:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y:3348:2: note: include '<string.h>' or provide a declaration of 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3587:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y:3348:2: warning: incompatible implicit declaration of built-in function 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3605:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y:3348:2: note: include '<string.h>' or provide a declaration of 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:3605:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y: In function 'parse_comsub':
yacc.y:3723:33: error: 'interactive' undeclared (first use in this function)
   if ((tflags & LEX_CKCASE) && (interactive == 0 || interactive_comments))
                                 ^~~~~~~~~~~
yacc.y:3723:53: error: 'interactive_comments' undeclared (first use in this function)
   if ((tflags & LEX_CKCASE) && (interactive == 0 || interactive_comments))
                                                     ^~~~~~~~~~~~~~~~~~~~
yacc.y:3729:9: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   ret = (char *)xmalloc (retsize = 64);
         ^
yacc.y:3772:12: warning: implicit declaration of function 'STREQN'; did you mean 'THEN'? [-Wimplicit-function-declaration]
        if (STREQN (ret + tind, heredelim, hdlen))
            ^~~~~~
            THEN
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:3786:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:3786:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:3786:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:3786:25: note: in expansion of macro 'SHOULD_PROMPT'
       if (ch == '\n' && SHOULD_PROMPT ())
                         ^~~~~~~~~~~~~
yacc.y:3859:20: error: 'CTLESC' undeclared (first use in this function)
    if MBTEST(ch == CTLESC)
                    ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3859:17: warning: comparison between pointer and integer
    if MBTEST(ch == CTLESC)
                 ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3860:20: warning: assignment to 'char' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
      ret[retind++] = CTLESC;
                    ^
yacc.y:3867:17: warning: implicit declaration of function 'shellbreak'; did you mean 'shell_getc'? [-Wimplicit-function-declaration]
       if MBTEST(shellbreak (ch))
                 ^~~~~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:3921:15: warning: implicit declaration of function 'substring' [-Wimplicit-function-declaration]
     nestret = substring (ret, lex_firstind, retind);
               ^~~~~~~~~
yacc.y:3921:13: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     nestret = substring (ret, lex_firstind, retind);
             ^
yacc.y:3922:17: warning: implicit declaration of function 'string_quote_removal' [-Wimplicit-function-declaration]
     heredelim = string_quote_removal (nestret, 0);
                 ^~~~~~~~~~~~~~~~~~~~
yacc.y:3922:15: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     heredelim = string_quote_removal (nestret, 0);
               ^
yacc.y:3923:13: warning: implicit declaration of function 'STRLEN'; did you mean 'THEN'? [-Wimplicit-function-declaration]
     hdlen = STRLEN(heredelim);
             ^~~~~~
             THEN
yacc.y:3977:14: warning: implicit declaration of function 'islower' [-Wimplicit-function-declaration]
    if MBTEST(islower ((unsigned char)ch))
              ^~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:4025:7: warning: implicit declaration of function 'isblank' [-Wimplicit-function-declaration]
      (isblank((unsigned char)ch) || ch == '\n') &&
       ^~~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:4098:20: warning: comparison between pointer and integer
       if MBTEST(ch == CTLESC || ch == CTLNUL) /* special shell escapes */
                    ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:4098:39: error: 'CTLNUL' undeclared (first use in this function)
       if MBTEST(ch == CTLESC || ch == CTLNUL) /* special shell escapes */
                                       ^~~~~~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:4098:36: warning: comparison between pointer and integer
       if MBTEST(ch == CTLESC || ch == CTLNUL) /* special shell escapes */
                                    ^~
yacc.y:111:23: note: in definition of macro 'MBTEST'
 #  define MBTEST(x) ((x))
                       ^
yacc.y:4101:18: warning: assignment to 'char' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
    ret[retind++] = CTLESC;
                  ^
yacc.y:2197:13: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
             ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2197:38: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
                                      ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2198:4: error: invalid use of undefined type 'struct dstack'
  ds.delimiters = (char *)xrealloc \
    ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2199:7: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
       ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2199:23: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                       ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2199:47: error: invalid operands to binary * (have 'int *' and 'long unsigned int')
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                    ~                          ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2198:18: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  ds.delimiters = (char *)xrealloc \
                  ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2200:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
         ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2200:23: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
                       ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2200:20: error: array subscript is not an integer
       ds.delimiters[ds.delimiter_depth] = character; \
                    ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2201:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiter_depth++; \
         ^
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2201:25: error: lvalue required as increment operand
       ds.delimiter_depth++; \
                         ^~
yacc.y:4134:11: note: in expansion of macro 'push_delimiter'
           push_delimiter (dstack, ch);
           ^~~~~~~~~~~~~~
yacc.y:2205:29: error: invalid use of undefined type 'struct dstack'
 #define pop_delimiter(ds) ds.delimiter_depth--
                             ^
yacc.y:4139:4: note: in expansion of macro 'pop_delimiter'
    pop_delimiter (dstack);
    ^~~~~~~~~~~~~
yacc.y:2205:45: error: lvalue required as decrement operand
 #define pop_delimiter(ds) ds.delimiter_depth--
                                             ^~
yacc.y:4139:4: note: in expansion of macro 'pop_delimiter'
    pop_delimiter (dstack);
    ^~~~~~~~~~~~~
yacc.y:4145:15: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        ttrans = ansiexpand (nestret, 0, nestlen - 1, &ttranslen);
               ^
yacc.y:4150:13: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     nestret = sh_single_quote (ttrans);
             ^
yacc.y:4152:15: warning: incompatible implicit declaration of built-in function 'strlen'
     nestlen = strlen (nestret);
               ^~~~~~
yacc.y:4152:15: note: include '<string.h>' or provide a declaration of 'strlen'
yacc.y:4164:15: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        ttrans = localeexpand (nestret, 0, nestlen - 1, start_lineno, &ttranslen);
               ^
yacc.y:4167:16: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
        nestret = sh_mkdoublequoted (ttrans, ttranslen, 0);
                ^
yacc.y:3348:2: warning: incompatible implicit declaration of built-in function 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:4173:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y:3348:2: note: include '<string.h>' or provide a declaration of 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:4173:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y:3348:2: warning: incompatible implicit declaration of built-in function 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:4189:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y:3348:2: note: include '<string.h>' or provide a declaration of 'strcpy'
  strcpy (ret + retind, nestret); \
  ^~~~~~
yacc.y:4189:4: note: in expansion of macro 'APPEND_NESTRET'
    APPEND_NESTRET ();
    ^~~~~~~~~~~~~~
yacc.y: In function 'xparse_dolparen':
yacc.y:4215:3: error: unknown type name 'sh_parser_state_t'
   sh_parser_state_t ps;
   ^~~~~~~~~~~~~~~~~
yacc.y:4216:3: error: unknown type name 'sh_input_line_state_t'; did you mean 'set_line_mbstate'?
   sh_input_line_state_t ls;
   ^~~~~~~~~~~~~~~~~~~~~
   set_line_mbstate
yacc.y:4225:12: error: 'SEVAL_NONINT' undeclared (first use in this function)
   sflags = SEVAL_NONINT|SEVAL_NOHIST|SEVAL_NOFREE;
            ^~~~~~~~~~~~
yacc.y:4225:25: error: 'SEVAL_NOHIST' undeclared (first use in this function); did you mean 'SA_NOMASK'?
   sflags = SEVAL_NONINT|SEVAL_NOHIST|SEVAL_NOFREE;
                         ^~~~~~~~~~~~
                         SA_NOMASK
yacc.y:4225:24: error: invalid operands to binary | (have 'int *' and 'int *')
   sflags = SEVAL_NONINT|SEVAL_NOHIST|SEVAL_NOFREE;
            ~~~~~~~~~~~~^
yacc.y:4225:38: error: 'SEVAL_NOFREE' undeclared (first use in this function)
   sflags = SEVAL_NONINT|SEVAL_NOHIST|SEVAL_NOFREE;
                                      ^~~~~~~~~~~~
yacc.y:4225:37: error: invalid operands to binary | (have 'int *' and 'int *')
   sflags = SEVAL_NONINT|SEVAL_NOHIST|SEVAL_NOFREE;
            ~~~~~~~~~~~~             ^
yacc.y:4225:10: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
   sflags = SEVAL_NONINT|SEVAL_NOHIST|SEVAL_NOFREE;
          ^
yacc.y:4226:15: error: 'SX_NOLONGJMP' undeclared (first use in this function)
   if (flags & SX_NOLONGJMP)
               ^~~~~~~~~~~~
yacc.y:4226:13: error: invalid operands to binary & (have 'int' and 'int *')
   if (flags & SX_NOLONGJMP)
             ^
yacc.y:4227:15: error: 'SEVAL_NOLONGJMP' undeclared (first use in this function)
     sflags |= SEVAL_NOLONGJMP;
               ^~~~~~~~~~~~~~~
yacc.y:4227:12: error: invalid operands to binary | (have 'int' and 'int *')
     sflags |= SEVAL_NOLONGJMP;
            ^~ ~~~~~~~~~~~~~~~
yacc.y:4229:3: warning: implicit declaration of function 'save_input_line_state'; did you mean 'save_token_state'? [-Wimplicit-function-declaration]
   save_input_line_state (&ls);
   ^~~~~~~~~~~~~~~~~~~~~
   save_token_state
yacc.y:4233:19: error: 'PST_CMDSUBST' undeclared (first use in this function)
   parser_state |= PST_CMDSUBST|PST_EOFTOKEN; /* allow instant ')' */ /*(*/
                   ^~~~~~~~~~~~
yacc.y:4233:32: error: 'PST_EOFTOKEN' undeclared (first use in this function)
   parser_state |= PST_CMDSUBST|PST_EOFTOKEN; /* allow instant ')' */ /*(*/
                                ^~~~~~~~~~~~
yacc.y:4233:31: error: invalid operands to binary | (have 'int *' and 'int *')
   parser_state |= PST_CMDSUBST|PST_EOFTOKEN; /* allow instant ')' */ /*(*/
                   ~~~~~~~~~~~~^
yacc.y:4233:16: error: invalid operands to binary | (have 'int' and 'int *')
   parser_state |= PST_CMDSUBST|PST_EOFTOKEN; /* allow instant ')' */ /*(*/
                ^~ ~~~~~~~~~~~~
yacc.y:4236:8: warning: implicit declaration of function 'parse_string'; did you mean 'push_stream'? [-Wimplicit-function-declaration]
   nc = parse_string (string, "command substitution", sflags, &ep);
        ^~~~~~~~~~~~
        push_stream
yacc.y:4242:3: warning: implicit declaration of function 'restore_input_line_state'; did you mean 'restore_token_state'? [-Wimplicit-function-declaration]
   restore_input_line_state (&ls);
   ^~~~~~~~~~~~~~~~~~~~~~~~
   restore_token_state
yacc.y:4249:5: warning: implicit declaration of function 'jump_to_top_level' [-Wimplicit-function-declaration]
     jump_to_top_level (-nc); /* XXX */
     ^~~~~~~~~~~~~~~~~
yacc.y:4274:15: error: 'SX_NOALLOC' undeclared (first use in this function); did you mean 'YYMALLOC'?
   if (flags & SX_NOALLOC)
               ^~~~~~~~~~
               YYMALLOC
yacc.y:4274:13: error: invalid operands to binary & (have 'int' and 'int *')
   if (flags & SX_NOALLOC)
             ^
yacc.y:4279:11: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       ret = xmalloc (1);
           ^
yacc.y:4283:9: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ret = substring (ostring, 0, nc - 1);
         ^
yacc.y: In function 'read_token_word':
yacc.y:4686:3: error: unknown type name 'WORD_DESC'
   WORD_DESC *the_word;
   ^~~~~~~~~
yacc.y:4713:3: error: unknown type name 'intmax_t'
   intmax_t lvalue;
   ^~~~~~~~
yacc.y:4716:13: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
     token = (char *)xrealloc (token, token_buffer_size = TOKEN_DEFAULT_INITIAL_SIZE);
             ^
yacc.y:4719:21: warning: implicit declaration of function 'DIGIT'; did you mean 'SIGIO'? [-Wimplicit-function-declaration]
   all_digit_token = DIGIT (character);
                     ^~~~~
                     SIGIO
yacc.y:2192:6: error: invalid use of undefined type 'struct dstack'
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
      ^
yacc.y:4733:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:2192:27: error: invalid use of undefined type 'struct dstack'
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
                           ^
yacc.y:4733:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:2192:41: error: invalid use of undefined type 'struct dstack'
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
                                         ^
yacc.y:4733:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:2192:38: error: array subscript is not an integer
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
                                      ^
yacc.y:4733:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:4733:10: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
       cd = current_delimiter (dstack);
          ^
yacc.y:4754:38: error: 'sh_syntaxtab' undeclared (first use in this function); did you mean 'si_status'?
     (cd == '"' && peek_char >= 0 && (sh_syntaxtab[peek_char] & CBSDQUOTE)))
                                      ^~~~~~~~~~~~
                                      si_status
yacc.y:4754:64: error: 'CBSDQUOTE' undeclared (first use in this function); did you mean 'P_DQUOTE'?
     (cd == '"' && peek_char >= 0 && (sh_syntaxtab[peek_char] & CBSDQUOTE)))
                                                                ^~~~~~~~~
                                                                P_DQUOTE
yacc.y:4754:62: error: invalid operands to binary & (have 'int' and 'int *')
     (cd == '"' && peek_char >= 0 && (sh_syntaxtab[peek_char] & CBSDQUOTE)))
                                      ~~~~~~~~~~~~~~~~~~~~~~~ ^
yacc.y:2197:13: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
             ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2197:38: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
                                      ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2198:4: error: invalid use of undefined type 'struct dstack'
  ds.delimiters = (char *)xrealloc \
    ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2199:7: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
       ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2199:23: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                       ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2199:47: error: invalid operands to binary * (have 'int *' and 'long unsigned int')
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                    ~                          ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2198:18: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  ds.delimiters = (char *)xrealloc \
                  ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2200:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
         ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2200:23: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
                       ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2200:20: error: array subscript is not an integer
       ds.delimiters[ds.delimiter_depth] = character; \
                    ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2201:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiter_depth++; \
         ^
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2201:25: error: lvalue required as increment operand
       ds.delimiter_depth++; \
                         ^~
yacc.y:4765:4: note: in expansion of macro 'push_delimiter'
    push_delimiter (dstack, character);
    ^~~~~~~~~~~~~~
yacc.y:2205:29: error: invalid use of undefined type 'struct dstack'
 #define pop_delimiter(ds) ds.delimiter_depth--
                             ^
yacc.y:4767:4: note: in expansion of macro 'pop_delimiter'
    pop_delimiter (dstack);
    ^~~~~~~~~~~~~
yacc.y:2205:45: error: lvalue required as decrement operand
 #define pop_delimiter(ds) ds.delimiter_depth--
                                             ^~
yacc.y:4767:4: note: in expansion of macro 'pop_delimiter'
    pop_delimiter (dstack);
    ^~~~~~~~~~~~~
yacc.y:4773:4: warning: incompatible implicit declaration of built-in function 'strcpy'
    strcpy (token + token_index, ttok);
    ^~~~~~
yacc.y:4773:4: note: include '<string.h>' or provide a declaration of 'strcpy'
yacc.y:4777:43: warning: incompatible implicit declaration of built-in function 'strchr'
    dollar_present |= (character == '"' && strchr (ttok, '$') != 0);
                                           ^~~~~~
yacc.y:4777:43: note: include '<string.h>' or provide a declaration of 'strchr'
yacc.y:4837:11: warning: implicit declaration of function 'shellexp'; did you mean 'shell_getc'? [-Wimplicit-function-declaration]
       if (shellexp (character))
           ^~~~~~~~
           shell_getc
yacc.y:2197:13: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
             ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2197:38: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
                                      ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2198:4: error: invalid use of undefined type 'struct dstack'
  ds.delimiters = (char *)xrealloc \
    ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2199:7: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
       ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2199:23: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                       ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2199:47: error: invalid operands to binary * (have 'int *' and 'long unsigned int')
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                    ~                          ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2198:18: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  ds.delimiters = (char *)xrealloc \
                  ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2200:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
         ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2200:23: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
                       ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2200:20: error: array subscript is not an integer
       ds.delimiters[ds.delimiter_depth] = character; \
                    ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2201:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiter_depth++; \
         ^
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2201:25: error: lvalue required as increment operand
       ds.delimiter_depth++; \
                         ^~
yacc.y:4853:5: note: in expansion of macro 'push_delimiter'
     push_delimiter (dstack, peek_char);
     ^~~~~~~~~~~~~~
yacc.y:2205:29: error: invalid use of undefined type 'struct dstack'
 #define pop_delimiter(ds) ds.delimiter_depth--
                             ^
yacc.y:4855:5: note: in expansion of macro 'pop_delimiter'
     pop_delimiter (dstack);
     ^~~~~~~~~~~~~
yacc.y:2205:45: error: lvalue required as decrement operand
 #define pop_delimiter(ds) ds.delimiter_depth--
                                             ^~
yacc.y:4855:5: note: in expansion of macro 'pop_delimiter'
     pop_delimiter (dstack);
     ^~~~~~~~~~~~~
yacc.y:4866:8: warning: incompatible implicit declaration of built-in function 'strcpy'
        strcpy (token + token_index, ttok);
        ^~~~~~
yacc.y:4866:8: note: include '<string.h>' or provide a declaration of 'strcpy'
yacc.y:2197:13: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
             ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2197:38: error: invalid use of undefined type 'struct dstack'
       if (ds.delimiter_depth + 2 > ds.delimiter_space) \
                                      ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2198:4: error: invalid use of undefined type 'struct dstack'
  ds.delimiters = (char *)xrealloc \
    ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2199:7: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
       ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2199:23: error: invalid use of undefined type 'struct dstack'
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                       ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2199:47: error: invalid operands to binary * (have 'int *' and 'long unsigned int')
    (ds.delimiters, (ds.delimiter_space += 10) * sizeof (char)); \
                    ~                          ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2198:18: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  ds.delimiters = (char *)xrealloc \
                  ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2200:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
         ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2200:23: error: invalid use of undefined type 'struct dstack'
       ds.delimiters[ds.delimiter_depth] = character; \
                       ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2200:20: error: array subscript is not an integer
       ds.delimiters[ds.delimiter_depth] = character; \
                    ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2201:9: error: invalid use of undefined type 'struct dstack'
       ds.delimiter_depth++; \
         ^
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2201:25: error: lvalue required as increment operand
       ds.delimiter_depth++; \
                         ^~
yacc.y:4879:8: note: in expansion of macro 'push_delimiter'
        push_delimiter (dstack, peek_char);
        ^~~~~~~~~~~~~~
yacc.y:2205:29: error: invalid use of undefined type 'struct dstack'
 #define pop_delimiter(ds) ds.delimiter_depth--
                             ^
yacc.y:4883:8: note: in expansion of macro 'pop_delimiter'
        pop_delimiter (dstack);
        ^~~~~~~~~~~~~
yacc.y:2205:45: error: lvalue required as decrement operand
 #define pop_delimiter(ds) ds.delimiter_depth--
                                             ^~
yacc.y:4883:8: note: in expansion of macro 'pop_delimiter'
        pop_delimiter (dstack);
        ^~~~~~~~~~~~~
yacc.y:4888:12: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ttrans = ansiexpand (ttok, 0, ttoklen - 1, &ttranslen);
            ^
yacc.y:4894:10: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ttok = sh_single_quote (ttrans);
          ^
yacc.y:4896:17: warning: incompatible implicit declaration of built-in function 'strlen'
     ttranslen = strlen (ttok);
                 ^~~~~~
yacc.y:4896:17: note: include '<string.h>' or provide a declaration of 'strlen'
yacc.y:4902:12: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ttrans = localeexpand (ttok, 0, ttoklen - 1, first_line, &ttranslen);
            ^
yacc.y:4906:10: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
     ttok = sh_mkdoublequoted (ttrans, ttranslen, 0);
          ^
yacc.y:4915:8: warning: incompatible implicit declaration of built-in function 'strcpy'
        strcpy (token + token_index, ttrans);
        ^~~~~~
yacc.y:4915:8: note: include '<string.h>' or provide a declaration of 'strcpy'
yacc.y:5003:24: error: 'CTLESC' undeclared (first use in this function)
       if (character == CTLESC || character == CTLNUL)
                        ^~~~~~
yacc.y:5003:21: warning: comparison between pointer and integer
       if (character == CTLESC || character == CTLNUL)
                     ^~
yacc.y:5003:47: error: 'CTLNUL' undeclared (first use in this function)
       if (character == CTLESC || character == CTLNUL)
                                               ^~~~~~
yacc.y:5003:44: warning: comparison between pointer and integer
       if (character == CTLESC || character == CTLNUL)
                                            ^~
yacc.y:5007:25: warning: assignment to 'char' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
    token[token_index++] = CTLESC;
                         ^
yacc.y:1301:4: error: 'interactive' undeclared (first use in this function)
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
    ^~~~~~~~~~~
yacc.y:5020:32: note: in expansion of macro 'SHOULD_PROMPT'
       if (character == '\n' && SHOULD_PROMPT ())
                                ^~~~~~~~~~~~~
yacc.y:1301:30: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                              ^
yacc.y:5020:32: note: in expansion of macro 'SHOULD_PROMPT'
       if (character == '\n' && SHOULD_PROMPT ())
                                ^~~~~~~~~~~~~
yacc.y:1301:39: error: 'st_stdin' undeclared (first use in this function); did you mean 'stdin'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                       ^~~~~~~~
yacc.y:5020:32: note: in expansion of macro 'SHOULD_PROMPT'
       if (character == '\n' && SHOULD_PROMPT ())
                                ^~~~~~~~~~~~~
yacc.y:1301:61: error: request for member 'type' in something not a structure or union
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                             ^
yacc.y:5020:32: note: in expansion of macro 'SHOULD_PROMPT'
       if (character == '\n' && SHOULD_PROMPT ())
                                ^~~~~~~~~~~~~
yacc.y:1301:70: error: 'st_stream' undeclared (first use in this function); did you mean 'pop_stream'?
   (interactive && (bash_input.type == st_stdin || bash_input.type == st_stream))
                                                                      ^~~~~~~~~
yacc.y:5020:32: note: in expansion of macro 'SHOULD_PROMPT'
       if (character == '\n' && SHOULD_PROMPT ())
                                ^~~~~~~~~~~~~
yacc.y:2192:6: error: invalid use of undefined type 'struct dstack'
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
      ^
yacc.y:5026:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:2192:27: error: invalid use of undefined type 'struct dstack'
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
                           ^
yacc.y:5026:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:2192:41: error: invalid use of undefined type 'struct dstack'
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
                                         ^
yacc.y:5026:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:2192:38: error: array subscript is not an integer
   (ds.delimiter_depth ? ds.delimiters[ds.delimiter_depth - 1] : 0)
                                      ^
yacc.y:5026:12: note: in expansion of macro 'current_delimiter'
       cd = current_delimiter (dstack);
            ^~~~~~~~~~~~~~~~~
yacc.y:5026:10: warning: assignment to 'int' from 'int *' makes integer from pointer without a cast [-Wint-conversion]
       cd = current_delimiter (dstack);
          ^
yacc.y:5043:6: warning: implicit declaration of function 'legal_number' [-Wimplicit-function-declaration]
  if (legal_number (token, &lvalue) && (int)lvalue == lvalue)
      ^~~~~~~~~~~~
yacc.y:2761:33: error: request for member 'word' in something not a structure or union
  for (i = 0; word_token_alist[i].word != (char *)NULL; i++) \
                                 ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2761:39: warning: comparison of distinct pointer types lacks a cast
  for (i = 0; word_token_alist[i].word != (char *)NULL; i++) \
                                       ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2762:39: error: request for member 'word' in something not a structure or union
    if (STREQ (tok, word_token_alist[i].word)) \
                                       ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2764:28: error: 'PST_CASEPAT' undeclared (first use in this function)
        if ((parser_state & PST_CASEPAT) && (word_token_alist[i].token != ESAC)) \
                            ^~~~~~~~~~~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2764:26: error: invalid operands to binary & (have 'int' and 'int *')
        if ((parser_state & PST_CASEPAT) && (word_token_alist[i].token != ESAC)) \
                          ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2764:64: error: request for member 'token' in something not a structure or union
        if ((parser_state & PST_CASEPAT) && (word_token_alist[i].token != ESAC)) \
                                                                ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2764:71: warning: comparison between pointer and integer
        if ((parser_state & PST_CASEPAT) && (word_token_alist[i].token != ESAC)) \
                                                                       ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2766:31: error: request for member 'token' in something not a structure or union
        if (word_token_alist[i].token == TIME && time_command_acceptable () == 0) \
                               ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2766:38: warning: comparison between pointer and integer
        if (word_token_alist[i].token == TIME && time_command_acceptable () == 0) \
                                      ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2768:26: error: invalid operands to binary & (have 'int' and 'int *')
        if ((parser_state & PST_CASEPAT) && last_read_token == '|' && word_token_alist[i].token == ESAC) \
                          ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2768:89: error: request for member 'token' in something not a structure or union
        if ((parser_state & PST_CASEPAT) && last_read_token == '|' && word_token_alist[i].token == ESAC) \
                                                                                         ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2768:96: warning: comparison between pointer and integer
        if ((parser_state & PST_CASEPAT) && last_read_token == '|' && word_token_alist[i].token == ESAC) \
                                                                                                ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2770:31: error: request for member 'token' in something not a structure or union
        if (word_token_alist[i].token == ESAC) \
                               ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2770:38: warning: comparison between pointer and integer
        if (word_token_alist[i].token == ESAC) \
                                      ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2771:33: error: 'PST_CASESTMT' undeclared (first use in this function)
   parser_state &= ~(PST_CASEPAT|PST_CASESTMT); \
                                 ^~~~~~~~~~~~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2771:32: error: invalid operands to binary | (have 'int *' and 'int *')
   parser_state &= ~(PST_CASEPAT|PST_CASESTMT); \
                     ~~~~~~~~~~~^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2771:19: error: wrong type argument to bit-complement
   parser_state &= ~(PST_CASEPAT|PST_CASESTMT); \
                   ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2771:16: error: invalid operands to binary & (have 'int' and 'int *')
   parser_state &= ~(PST_CASEPAT|PST_CASESTMT); \
                ^~ ~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2772:36: error: request for member 'token' in something not a structure or union
        else if (word_token_alist[i].token == CASE) \
                                    ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2772:43: warning: comparison between pointer and integer
        else if (word_token_alist[i].token == CASE) \
                                           ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2773:16: error: invalid operands to binary | (have 'int' and 'int *')
   parser_state |= PST_CASESTMT; \
                ^~ ~~~~~~~~~~~~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2774:36: error: request for member 'token' in something not a structure or union
        else if (word_token_alist[i].token == COND_END) \
                                    ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2774:43: warning: comparison between pointer and integer
        else if (word_token_alist[i].token == COND_END) \
                                           ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2775:21: error: 'PST_CONDCMD' undeclared (first use in this function); did you mean 'COND_CMD'?
   parser_state &= ~(PST_CONDCMD|PST_CONDEXPR); \
                     ^~~~~~~~~~~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2775:33: error: 'PST_CONDEXPR' undeclared (first use in this function); did you mean 'SA_NODEFER'?
   parser_state &= ~(PST_CONDCMD|PST_CONDEXPR); \
                                 ^~~~~~~~~~~~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2775:32: error: invalid operands to binary | (have 'int *' and 'int *')
   parser_state &= ~(PST_CONDCMD|PST_CONDEXPR); \
                     ~~~~~~~~~~~^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2775:19: error: wrong type argument to bit-complement
   parser_state &= ~(PST_CONDCMD|PST_CONDEXPR); \
                   ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2775:16: error: invalid operands to binary & (have 'int' and 'int *')
   parser_state &= ~(PST_CONDCMD|PST_CONDEXPR); \
                ^~ ~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2776:36: error: request for member 'token' in something not a structure or union
        else if (word_token_alist[i].token == COND_START) \
                                    ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2776:43: warning: comparison between pointer and integer
        else if (word_token_alist[i].token == COND_START) \
                                           ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2777:16: error: invalid operands to binary | (have 'int' and 'int *')
   parser_state |= PST_CONDCMD; \
                ^~ ~~~~~~~~~~~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2778:36: error: request for member 'token' in something not a structure or union
        else if (word_token_alist[i].token == '{') \
                                    ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2778:43: warning: comparison between pointer and integer
        else if (word_token_alist[i].token == '{') \
                                           ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2780:36: error: request for member 'token' in something not a structure or union
        else if (word_token_alist[i].token == '}' && open_brace_count) \
                                    ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2780:43: warning: comparison between pointer and integer
        else if (word_token_alist[i].token == '}' && open_brace_count) \
                                           ^~
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2782:35: error: request for member 'token' in something not a structure or union
        return (word_token_alist[i].token); \
                                   ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:2782:15: warning: returning 'int *' from a function with return type 'int' makes integer from pointer without a cast [-Wint-conversion]
        return (word_token_alist[i].token); \
               ^
yacc.y:5077:5: note: in expansion of macro 'CHECK_FOR_RESERVED_WORD'
     CHECK_FOR_RESERVED_WORD (token);
     ^~~~~~~~~~~~~~~~~~~~~~~
yacc.y:5079:14: warning: implicit declaration of function 'alloc_word_desc' [-Wimplicit-function-declaration]
   the_word = alloc_word_desc ();
              ^~~~~~~~~~~~~~~
yacc.y:5079:12: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   the_word = alloc_word_desc ();
            ^
yacc.y:5080:11: error: request for member 'word' in something not a structure or union
   the_word->word = (char *)xmalloc (1 + token_index);
           ^~
yacc.y:5080:20: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   the_word->word = (char *)xmalloc (1 + token_index);
                    ^
yacc.y:5081:11: error: request for member 'flags' in something not a structure or union
   the_word->flags = 0;
           ^~
yacc.y:5082:3: warning: incompatible implicit declaration of built-in function 'strcpy'
   strcpy (the_word->word, token);
   ^~~~~~
yacc.y:5082:3: note: include '<string.h>' or provide a declaration of 'strcpy'
yacc.y:5082:19: error: request for member 'word' in something not a structure or union
   strcpy (the_word->word, token);
                   ^~
yacc.y:5082:11: warning: passing argument 1 of 'strcpy' from incompatible pointer type [-Wincompatible-pointer-types]
   strcpy (the_word->word, token);
           ^~~~~~~~~~~~~~
yacc.y:5082:11: note: expected 'char *' but argument is of type 'int *'
yacc.y:5084:13: error: request for member 'flags' in something not a structure or union
     the_word->flags |= W_HASDOLLAR;
             ^~
yacc.y:5084:24: error: 'W_HASDOLLAR' undeclared (first use in this function)
     the_word->flags |= W_HASDOLLAR;
                        ^~~~~~~~~~~
yacc.y:5086:13: error: request for member 'flags' in something not a structure or union
     the_word->flags |= W_QUOTED;  /*(*/
             ^~
yacc.y:5086:24: error: 'W_QUOTED' undeclared (first use in this function); did you mean 'P_DQUOTE'?
     the_word->flags |= W_QUOTED;  /*(*/
                        ^~~~~~~~
                        P_DQUOTE
yacc.y:5088:13: error: request for member 'flags' in something not a structure or union
     the_word->flags |= W_COMPASSIGN;
             ^~
yacc.y:5088:24: error: 'W_COMPASSIGN' undeclared (first use in this function)
     the_word->flags |= W_COMPASSIGN;
                        ^~~~~~~~~~~~
yacc.y:5092:7: warning: implicit declaration of function 'assignment'; did you mean 'ssignal'? [-Wimplicit-function-declaration]
   if (assignment (token, (parser_state & PST_COMPASSIGN) != 0))
       ^~~~~~~~~~
       ssignal
yacc.y:5092:42: error: 'PST_COMPASSIGN' undeclared (first use in this function)
   if (assignment (token, (parser_state & PST_COMPASSIGN) != 0))
                                          ^~~~~~~~~~~~~~
yacc.y:5092:40: error: invalid operands to binary & (have 'int' and 'int *')
   if (assignment (token, (parser_state & PST_COMPASSIGN) != 0))
                                        ^
yacc.y:5094:15: error: request for member 'flags' in something not a structure or union
       the_word->flags |= W_ASSIGNMENT;
               ^~
yacc.y:5094:26: error: 'W_ASSIGNMENT' undeclared (first use in this function); did you mean 'ASSIGNMENT_WORD'?
       the_word->flags |= W_ASSIGNMENT;
                          ^~~~~~~~~~~~
                          ASSIGNMENT_WORD
yacc.y:2746:19: error: 'PST_REDIRLIST' undeclared (first use in this function)
    ((parser_state&PST_REDIRLIST) && parsing_redirection(token) == 0) || \
                   ^~~~~~~~~~~~~
yacc.y:2751:4: note: in expansion of macro 'command_token_position'
   (command_token_position(token) && ((parser_state & PST_CASEPAT) == 0))
    ^~~~~~~~~~~~~~~~~~~~~~
yacc.y:5096:11: note: in expansion of macro 'assignment_acceptable'
       if (assignment_acceptable (last_read_token) || (parser_state & PST_COMPASSIGN) != 0)
           ^~~~~~~~~~~~~~~~~~~~~
yacc.y:2746:18: error: invalid operands to binary & (have 'int' and 'int *')
    ((parser_state&PST_REDIRLIST) && parsing_redirection(token) == 0) || \
                  ^
yacc.y:2751:4: note: in expansion of macro 'command_token_position'
   (command_token_position(token) && ((parser_state & PST_CASEPAT) == 0))
    ^~~~~~~~~~~~~~~~~~~~~~
yacc.y:5096:11: note: in expansion of macro 'assignment_acceptable'
       if (assignment_acceptable (last_read_token) || (parser_state & PST_COMPASSIGN) != 0)
           ^~~~~~~~~~~~~~~~~~~~~
yacc.y:2751:52: error: invalid operands to binary & (have 'int' and 'int *')
   (command_token_position(token) && ((parser_state & PST_CASEPAT) == 0))
                                                    ^
yacc.y:5096:11: note: in expansion of macro 'assignment_acceptable'
       if (assignment_acceptable (last_read_token) || (parser_state & PST_COMPASSIGN) != 0)
           ^~~~~~~~~~~~~~~~~~~~~
yacc.y:5096:68: error: invalid operands to binary & (have 'int' and 'int *')
       if (assignment_acceptable (last_read_token) || (parser_state & PST_COMPASSIGN) != 0)
                                                                    ^
yacc.y:5098:12: error: request for member 'flags' in something not a structure or union
    the_word->flags |= W_NOSPLIT;
            ^~
yacc.y:5098:23: error: 'W_NOSPLIT' undeclared (first use in this function)
    the_word->flags |= W_NOSPLIT;
                       ^~~~~~~~~
yacc.y:5099:21: error: invalid operands to binary & (have 'int' and 'int *')
    if (parser_state & PST_COMPASSIGN)
                     ^
yacc.y:5100:14: error: request for member 'flags' in something not a structure or union
      the_word->flags |= W_NOGLOB; /* XXX - W_NOBRACE? */
              ^~
yacc.y:5100:25: error: 'W_NOGLOB' undeclared (first use in this function)
      the_word->flags |= W_NOGLOB; /* XXX - W_NOBRACE? */
                         ^~~~~~~~
yacc.y:2746:18: error: invalid operands to binary & (have 'int' and 'int *')
    ((parser_state&PST_REDIRLIST) && parsing_redirection(token) == 0) || \
                  ^
yacc.y:5104:7: note: in expansion of macro 'command_token_position'
   if (command_token_position (last_read_token))
       ^~~~~~~~~~~~~~~~~~~~~~
yacc.y:5107:11: warning: implicit declaration of function 'builtin_address_internal' [-Wimplicit-function-declaration]
       b = builtin_address_internal (token, 0);
           ^~~~~~~~~~~~~~~~~~~~~~~~
yacc.y:5107:9: warning: assignment to 'struct builtin *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       b = builtin_address_internal (token, 0);
         ^
yacc.y:5108:18: error: dereferencing pointer to incomplete type 'struct builtin'
       if (b && (b->flags & ASSIGNMENT_BUILTIN))
                  ^~
yacc.y:5108:18: error: request for member 'flags' in something not a structure or union
yacc.y:5108:28: error: 'ASSIGNMENT_BUILTIN' undeclared (first use in this function); did you mean 'ASSIGNMENT_WORD'?
       if (b && (b->flags & ASSIGNMENT_BUILTIN))
                            ^~~~~~~~~~~~~~~~~~
                            ASSIGNMENT_WORD
yacc.y:5108:26: error: invalid operands to binary & (have 'int *' and 'int *')
       if (b && (b->flags & ASSIGNMENT_BUILTIN))
                 ~        ^
yacc.y:5109:18: error: 'PST_ASSIGNOK' undeclared (first use in this function); did you mean 'SI_SIGIO'?
  parser_state |= PST_ASSIGNOK;
                  ^~~~~~~~~~~~
                  SI_SIGIO
yacc.y:5109:15: error: invalid operands to binary | (have 'int' and 'int *')
  parser_state |= PST_ASSIGNOK;
               ^~ ~~~~~~~~~~~~
yacc.y:5111:15: error: invalid operands to binary | (have 'int' and 'int *')
  parser_state |= PST_ASSIGNOK;
               ^~ ~~~~~~~~~~~~
yacc.y:5124:11: warning: implicit declaration of function 'legal_identifier' [-Wimplicit-function-declaration]
       if (legal_identifier (token+1))
           ^~~~~~~~~~~~~~~~
yacc.y:5127:20: error: request for member 'word' in something not a structure or union
    strcpy (the_word->word, token+1);
                    ^~
yacc.y:5127:12: warning: passing argument 1 of 'strcpy' from incompatible pointer type [-Wincompatible-pointer-types]
    strcpy (the_word->word, token+1);
            ^~~~~~~~~~~~~~
yacc.y:5127:12: note: expected 'char *' but argument is of type 'int *'
yacc.y:5133:22: error: request for member 'flags' in something not a structure or union
   result = ((the_word->flags & (W_ASSIGNMENT|W_NOSPLIT)) == (W_ASSIGNMENT|W_NOSPLIT))
                      ^~
yacc.y:5133:45: error: invalid operands to binary | (have 'int *' and 'int *')
   result = ((the_word->flags & (W_ASSIGNMENT|W_NOSPLIT)) == (W_ASSIGNMENT|W_NOSPLIT))
                                 ~~~~~~~~~~~~^
yacc.y:5133:30: error: invalid operands to binary & (have 'int *' and 'int *')
   result = ((the_word->flags & (W_ASSIGNMENT|W_NOSPLIT)) == (W_ASSIGNMENT|W_NOSPLIT))
              ~~~~~~~~        ^
yacc.y:5133:74: error: invalid operands to binary | (have 'int *' and 'int *')
   result = ((the_word->flags & (W_ASSIGNMENT|W_NOSPLIT)) == (W_ASSIGNMENT|W_NOSPLIT))
                                                              ~~~~~~~~~~~~^
yacc.y:5139:23: error: 'PST_ALLOWOPNBRC' undeclared (first use in this function); did you mean 'P_ALLOWESC'?
       parser_state |= PST_ALLOWOPNBRC;
                       ^~~~~~~~~~~~~~~
                       P_ALLOWESC
yacc.y:5139:20: error: invalid operands to binary | (have 'int' and 'int *')
       parser_state |= PST_ALLOWOPNBRC;
                    ^~ ~~~~~~~~~~~~~~~
yacc.y: In function 'find_reserved_word':
yacc.y:5211:34: error: request for member 'word' in something not a structure or union
   for (i = 0; word_token_alist[i].word; i++)
                                  ^
yacc.y:5212:43: error: request for member 'word' in something not a structure or union
     if (STREQ (tokstr, word_token_alist[i].word))
                                           ^
yacc.y: In function 'parser_in_command_position':
yacc.y:2746:19: error: 'PST_REDIRLIST' undeclared (first use in this function)
    ((parser_state&PST_REDIRLIST) && parsing_redirection(token) == 0) || \
                   ^~~~~~~~~~~~~
yacc.y:5222:11: note: in expansion of macro 'command_token_position'
   return (command_token_position (last_read_token));
           ^~~~~~~~~~~~~~~~~~~~~~
yacc.y:2746:18: error: invalid operands to binary & (have 'int' and 'int *')
    ((parser_state&PST_REDIRLIST) && parsing_redirection(token) == 0) || \
                  ^
yacc.y:5222:11: note: in expansion of macro 'command_token_position'
   return (command_token_position (last_read_token));
           ^~~~~~~~~~~~~~~~~~~~~~
yacc.y: In function 'prompt_again':
yacc.y:5362:7: error: 'interactive' undeclared (first use in this function)
   if (interactive == 0 || expanding_alias ()) /* XXX */
       ^~~~~~~~~~~
yacc.y:5365:14: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   ps1_prompt = get_string_value ("PS1");
              ^
yacc.y:5366:14: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   ps2_prompt = get_string_value ("PS2");
              ^
yacc.y:5368:14: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   ps0_prompt = get_string_value ("PS0");
              ^
yacc.y:5374:6: warning: implicit declaration of function 'decode_prompt_string'; did you mean 'rewind_input_string'? [-Wimplicit-function-declaration]
    ? decode_prompt_string (*prompt_string_pointer)
      ^~~~~~~~~~~~~~~~~~~~
      rewind_input_string
yacc.y:5375:4: warning: pointer/integer type mismatch in conditional expression
    : (char *)NULL;
    ^
yacc.y:5379:21: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
       temp_prompt = (char *)xmalloc (1);
                     ^
yacc.y: At top level:
yacc.y:5454:1: error: conflicting types for 'decode_prompt_string'
 decode_prompt_string (string)
 ^~~~~~~~~~~~~~~~~~~~
yacc.y:5374:6: note: previous implicit declaration of 'decode_prompt_string' was here
    ? decode_prompt_string (*prompt_string_pointer)
      ^~~~~~~~~~~~~~~~~~~~
yacc.y: In function 'decode_prompt_string':
yacc.y:5457:3: error: unknown type name 'WORD_LIST'
   WORD_LIST *list;
   ^~~~~~~~~
yacc.y:5459:17: error: storage size of 'save_dstack' isn't known
   struct dstack save_dstack;
                 ^~~~~~~~~~~
yacc.y:5817:10: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   result = savestring (string);
          ^
yacc.y:5824:10: error: 'dstack' has an incomplete type 'struct dstack'
   dstack = temp_dstack;
          ^
yacc.y:5825:9: error: invalid use of undefined type 'struct dstack'
   dstack.delimiter_depth = 0;
         ^
yacc.y:5833:14: warning: implicit declaration of function 'expand_prompt_string'; did you mean 'decode_prompt_string'? [-Wimplicit-function-declaration]
       list = expand_prompt_string (result, Q_DOUBLE_QUOTES, 0);
              ^~~~~~~~~~~~~~~~~~~~
              decode_prompt_string
yacc.y:5833:44: error: 'Q_DOUBLE_QUOTES' undeclared (first use in this function)
       list = expand_prompt_string (result, Q_DOUBLE_QUOTES, 0);
                                            ^~~~~~~~~~~~~~~
yacc.y:5833:12: warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       list = expand_prompt_string (result, Q_DOUBLE_QUOTES, 0);
            ^
yacc.y:5835:16: warning: implicit declaration of function 'string_list'; did you mean 'yy_string_get'? [-Wimplicit-function-declaration]
       result = string_list (list);
                ^~~~~~~~~~~
                yy_string_get
yacc.y:5835:14: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       result = string_list (list);
              ^
yacc.y:5836:7: warning: implicit declaration of function 'dispose_words' [-Wimplicit-function-declaration]
       dispose_words (list);
       ^~~~~~~~~~~~~
yacc.y:5842:11: warning: implicit declaration of function 'dequote_string' [-Wimplicit-function-declaration]
       t = dequote_string (result);
           ^~~~~~~~~~~~~~
yacc.y:5842:9: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       t = dequote_string (result);
         ^
yacc.y:5847:10: error: 'dstack' has an incomplete type 'struct dstack'
   dstack = save_dstack;
          ^
yacc.y: In function 'error_token_from_token':
yacc.y:5875:11: warning: implicit declaration of function 'find_token_in_alist' [-Wimplicit-function-declaration]
   if (t = find_token_in_alist (tok, word_token_alist, 0))
           ^~~~~~~~~~~~~~~~~~~
yacc.y:5875:9: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   if (t = find_token_in_alist (tok, word_token_alist, 0))
         ^
yacc.y:5878:9: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   if (t = find_token_in_alist (tok, other_token_alist, 0))
         ^
yacc.y:5888:29: error: request for member 'word' in something not a structure or union
  t = savestring (yylval.word->word);
                             ^~
yacc.y:5888:4: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
  t = savestring (yylval.word->word);
    ^
yacc.y:5891:11: warning: implicit declaration of function 'itos' [-Wimplicit-function-declaration]
       t = itos (yylval.number);
           ^~~~
yacc.y:5891:9: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
       t = itos (yylval.number);
         ^
yacc.y:5895:11: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
         t = string_list (yylval.word_list);
           ^
yacc.y:5899:6: warning: implicit declaration of function 'string_list_internal' [-Wimplicit-function-declaration]
  t = string_list_internal (yylval.word_list, " ; ");
      ^~~~~~~~~~~~~~~~~~~~
yacc.y:5899:4: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
  t = string_list_internal (yylval.word_list, " ; ");
    ^
yacc.y: In function 'error_token_from_text':
yacc.y:5923:16: warning: implicit declaration of function 'whitespace' [-Wimplicit-function-declaration]
   while (i && (whitespace (t[i]) || t[i] == '\n'))
                ^~~~~~~~~~
yacc.y:5929:16: warning: implicit declaration of function 'member' [-Wimplicit-function-declaration]
   while (i && (member (t[i], " \n\t;|&") == 0))
                ^~~~~~
yacc.y:5939:6: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
  msg = substring (t, i, token_end);
      ^
yacc.y:5942:10: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
    msg = (char *)xmalloc (2);
          ^
yacc.y: In function 'print_offending_line':
yacc.y:5957:7: warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
   msg = savestring (shell_input_line);
       ^
yacc.y:5958:15: warning: incompatible implicit declaration of built-in function 'sexecution expired
