#include "utils_matrice.h"
#include "utils_tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    matrice m1, m2;

    init(argv[1]);
    m1 = lit_matrice("matrice1.txt");
    affiche_matrice(m1);
    liberer_matrice(m1);
    m2 = lit_matrice("matrice2.txt");
    affiche_matrice(m2);
    liberer_matrice(m2);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
