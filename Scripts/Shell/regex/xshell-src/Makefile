CC = gcc
LEX = flex
YACC = bison

all: lex-config yacc-config build

lex-config:
	 $(LEX) parser/lex.l

yacc-config:
	 $(YACC) -dyv parser/yacc.y

build:
	$(CC) lex.yy.c y.tab.c lists/ll.c lists/chain.c shell.c -g -o xshell

