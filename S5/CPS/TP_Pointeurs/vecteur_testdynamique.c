#include "vecteur_dynamique.h"
#include "utils_vecteur.h"
#include "utils_tests.h"
#include <stdio.h>

void teste_vecteur(vecteur v) {
    int i;
    int limite, extra = 100;

    limite = taille_vecteur(v);
    for (i = -extra; i < limite + extra; i++)
        if (acces_vecteur(v, i) != NULL)
            *acces_vecteur(v, i) = i % 10;
    for (i = -extra; i < limite + extra; i++)
        if (acces_vecteur(v, i) != NULL)
            affiche_test("%g", *acces_vecteur(v, i));
    affiche_test("\n");
}

int main(int argc, char *argv[]) {
    vecteur v1, v2;

    init(argv[1]);
    v1 = lit_vecteur("vecteur1.txt");
    teste_vecteur(v1);
    liberer_vecteur(v1);
    v2 = lit_vecteur("vecteur2.txt");
    teste_vecteur(v2);
    liberer_vecteur(v2);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
