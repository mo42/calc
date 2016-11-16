CC = clang
CFLAGS = -g -Wall -O0 -c

calc : calc.o tokenize.o
	$(CC) calc.o tokenize.o -o calc

tokenize.o : tokenize.c
	$(CC) $(CFLAGS) tokenize.c

calc.o : calc.c
	$(CC) $(CFLAGS) calc.c

.PHONY: clean mrproper
clean :
	rm -f *.o

mrproper : clean
	rm -r calc
