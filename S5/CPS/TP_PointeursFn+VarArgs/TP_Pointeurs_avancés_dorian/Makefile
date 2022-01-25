all: essai_fap

essai_fap: essai_fap.o fap.o
	gcc -o essai_fap fap.o essai_fap.o

fap.o: fap.c fap.h
	gcc -o fap.o -c fap.c -Wall -O

essai_fap.o: essai_fap.c 
	gcc -o essai_fap.o -c essai_fap.c -Wall -O

clean:
	rm -f *.o core
