#include "vecteur.h"
#include "utils_vecteur.h"
#include "utils_tests.h"
#include "memory_operations.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    vecteur v1, v2;

    init(argv[1]);
    v1 = lit_vecteur("vecteur1.txt");
    v2 = allouer_vecteur(taille_vecteur(v1));
    my_memcpy(acces_vecteur(v2, 0), acces_vecteur(v1, 0), taille_vecteur(v1) * sizeof(double));
    affiche_vecteur(v1);
    affiche_vecteur(v2);
    liberer_vecteur(v1);
    liberer_vecteur(v2);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
