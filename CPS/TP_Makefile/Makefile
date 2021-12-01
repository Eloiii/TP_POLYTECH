CC=gcc
CFLAGS=-Wall -Werror

essai_pile : essai_pile.o pile.o pile_io.o
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<


essai_pile.o: pile.h pile_io.h
pile_io.o : pile.h