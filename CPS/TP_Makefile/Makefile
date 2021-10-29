CC=gcc
CFLAGS=-Wall -Werror

essai_pile : essai_pile.o pile.o pile_io.o
	$(CC) -o $@ $^

essai_pile.o : essai_pile.c pile.h pile_io.h
	$(CC) $(CFLAGS) -c $<

pile.o : pile.c pile.h
	$(CC) $(CFLAGS) -c $<

pile_io.o : pile_io.c pile.h pile_io.h
	$(CC) $(CFLAGS) -c $<