LEX = flex
YACC = bison
CC = clang

calc: lex.yy.c calc.tab.c calc.tab.h
	$(CC) -o calc calc.tab.c lex.yy.c

lex.yy.c: calc.l calc.tab.h
	$(LEX) calc.l

calc.tab.c calc.tab.h: calc.y
	$(YACC) -d calc.y

.PHONY: clean
clean :
	rm -f *.o
	rm -f *.c
	rm -f *.h
	rm calc
