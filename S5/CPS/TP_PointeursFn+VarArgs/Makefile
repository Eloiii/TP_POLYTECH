CC=gcc
CFLAGS=-Wall -Werror

essai_fap : essai_fap.o essai_fap.o fap.o
	$(CC) -o $@ $^

essai_fap.o : essai_fap.c fap.h
	$(CC) $(CFLAGS) -c $<

fap.o : fap.c fap.h
	$(CC) $(CFLAGS) -c $<