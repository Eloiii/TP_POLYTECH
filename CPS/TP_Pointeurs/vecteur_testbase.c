#include "vecteur.h"
#include "utils_vecteur.h"
#include "utils_tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    vecteur v1, v2;

    init(argv[1]);
    v1 = lit_vecteur("vecteur1.txt");
    affiche_vecteur(v1);
    liberer_vecteur(v1);
    v2 = lit_vecteur("vecteur2.txt");
    affiche_vecteur(v2);
    liberer_vecteur(v2);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
