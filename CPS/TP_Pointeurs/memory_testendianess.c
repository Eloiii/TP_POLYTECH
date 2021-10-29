#include "memory_operations.h"
#include "utils_tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    char tableau[sizeof(int)];
    int *entier = (int *) tableau;
    int i;

    init(argv[1]);
    for (i = 0; i < sizeof(int); i++)
        tableau[i] = 0;
    if (is_little_endian())
        tableau[0] = 1;
    else
        tableau[sizeof(int) - 1] = 1;
    affiche_test("Un : %d\nTruc bizarre : %x\n", *entier, reverse_endianess(0x01234567));

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
