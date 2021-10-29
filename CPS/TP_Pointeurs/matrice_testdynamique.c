#include "matrice_dynamique.h"
#include "utils_matrice.h"
#include "utils_tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init(argv[1]);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
