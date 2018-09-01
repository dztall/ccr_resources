# [xshell] Project

To compile,
```
make
./xshell
```

## Files
```
shell.c, shell.h - contains built-in functions, execution functions, and how the shell functions.
parser/lex.l, parser/lex.l - parses input into command tables.
lists/chain and ll - linked list and command table container definitions.
```

## Known issues
```
[xshell] sometimes prints the current directory incorrectly (misplaced, wrong line). Nonetheless, any commands typed should function as normal.
[xshell] sometimes doesn't print the current directory after commands complete, especially with IO redirection. Nonetheless, any commands typed should function as normal.
When piping commands, [xshell] sometimes states that valid input is invalid. Nonetheless, it will still try to run.
[xshell] may crash or fall into an infinite loop on IO redirection.
```

## Features
```
setenv variable word
printenv
unsetenv variable
cd (directory name)
alias
alias name
alias name word
unalias name
bye
```

Commands in the form of
```
cmd [arg]* [|cmd [arg]*]* [< fn1] [>[>] fn2] [2>fn3 || 2>&1] [&]

piping
input
output
error
background
```

Aliases
```
words set as aliases are replaced.
(If an aliases is infinite, the original term is not replaced at all)
```

Environment variable expansion 
```
${variable}
(any words that match an alias in a variable are not replaced, variables are static terms)
```

Wildcard matching
```
Variables with * and ? are replaced with alphabetically sorted filenames in the working directory that match the pattern.
* matches any string, including null string
? matches any single character
```

Tilde expansion
```
~ on its own expands to home directory of the current user
~name expands to name's home directory
(only when ~ is not in quotes)
```

File name completion
```
Not implemented
```

