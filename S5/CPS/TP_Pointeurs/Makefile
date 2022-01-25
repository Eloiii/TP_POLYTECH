CC=clang
CFLAGS=-Wall -Werror -g -include my_memory.h

PROGRAMS=vecteur_testbase matrice_testbase matrice_lineaire_testbase \
         vecteur_testdynamique \
         memory_testcpy memory_testmove \
         memory_testendianess \
         matrice_testdynamique

TESTS=$(addsuffix .result, $(PROGRAMS))

OTHER_PROGRAMS=generer_vecteur generer_matrice

EXERCICES=matrice_lineaire.c matrice.c \
          vecteur.c vecteur_dynamique.c \
          memory_operations.c \
		  matrice_dynamique.c matrice_testdynamique.c

TDP_FILES=teste_programme Makefile vecteur*.txt matrice*.txt \
          *test*.c *utils*.c *utils*.h vecteur*.h matrice*.h my_memory.h \
          my_memory.c memory_operations.h

OTHER_FILES=filtre generer*.c *.gif *.html Makefile *.fig

.PHONY: all programs tests results fichiers correction clean distclean indent

all:
	@echo "Indiquez une cible (ex. 'make test' ou 'make vecteur_testbase par exemple')"

programs: $(PROGRAMS) $(OTHER_PROGRAMS)

test: $(PROGRAMS)
	@echo;echo "*** TESTS ***";echo;\
	chmod u+x ./teste_programme
	for file in $^;\
		do echo ;\
		./teste_programme $$file 2>/dev/null || break;\
	done

results: $(TESTS)

%.result: %
	./$< > $@

fichiers: $(EXERCICES) $(TDP_FILES) $(TESTS)
	if [ ! -d Fichiers ];then mkdir Fichiers;fi
	-rm Fichiers/*
	for file in $(TDP_FILES) $(TESTS);do cp -p $$file Fichiers;done
	for file in $(EXERCICES);\
	    do cat $$file | ./filtre SUJET >Fichiers/$$file;done
	cd Fichiers && zip ../TP_Memoire.zip *

correction: $(EXERCICES)
	if [ ! -d Correction ];then mkdir Correction;fi
	for file in $(EXERCICES);\
	    do cat $$file | ./filtre SOLUTION >Correction/$$file;done

indent:
	for file in *.[ch];\
	do indent -kr -brf -l100 -lc100 -nut $$file;\
	done

clean:
	rm -f *.o $(PROGRAMS) $(OTHER_PROGRAMS) *.output

distclean: clean
	rm -rf *.result Fichiers Correction *.tgz *.bak

%: %.o
	$(CC) -o $@ $^

%.o: %.c my_memory.h
	$(CC) $(CFLAGS) -c $<

utils_vecteur.o: utils_vecteur.c vecteur.h utils_vecteur.h
	$(CC) $(CFLAGS) -c -include vecteur.h utils_vecteur.c

utils_vecteur_dynamique.o: utils_vecteur.c vecteur_dynamique.h utils_vecteur.h
	$(CC) $(CFLAGS) -c -o $@ -include vecteur_dynamique.h utils_vecteur.c

utils_matrice.o: utils_matrice.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -include matrice.h utils_matrice.c

utils_matrice_lineaire.o: utils_matrice.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h utils_matrice.c

utils_matrice_dynamique.o: utils_matrice.c matrice_dynamique.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_dynamique.h utils_matrice.c

matrice_testbase.o: matrice_testbase.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice.h matrice_testbase.c

matrice_lineaire_testbase.o: matrice_testbase.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h matrice_testbase.c

my_memory.o: my_memory.c
	$(CC) -Wall -Werror -c $<

# dependences
vecteur_testbase: vecteur.o utils_vecteur.o my_memory.o utils_tests.o
vecteur_testdynamique: vecteur_dynamique.o utils_vecteur_dynamique.o my_memory.o utils_tests.o

vecteur_testbase.o: vecteur.h utils_vecteur.h
vecteur_testdynamique.o: vecteur_dynamique.h utils_vecteur.h

vecteur.o: vecteur.h
vecteur_dynamique.o: vecteur_dynamique.h

matrice_testbase: matrice.o utils_matrice.o my_memory.o utils_tests.o
matrice_testdynamique: matrice_dynamique.o utils_matrice_dynamique.o my_memory.o utils_tests.o vecteur_dynamique.o

matrice.o: matrice.h

matrice_lineaire_testbase: matrice_lineaire.o utils_matrice_lineaire.o my_memory.o utils_tests.o

matrice_lineaire.o: matrice_lineaire.h

memory_testcpy: memory_testcpy.o memory_operations.o vecteur.o utils_vecteur.o my_memory.o utils_tests.o
memory_testmove: memory_testmove.o memory_operations.o vecteur.o utils_vecteur.o my_memory.o utils_tests.o
memory_testendianess: memory_testendianess.o memory_operations.o my_memory.o utils_tests.o

memory_testcpy.o: vecteur.h memory_operations.h utils_vecteur.h
memory_testmove.o: vecteur.h memory_operations.h utils_vecteur.h
memory_testendianess.o: memory_operations.h

memory_operations.o: memory_operations.h

utils_tests.o: utils_tests.h
