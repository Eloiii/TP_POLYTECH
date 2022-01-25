#include "utils_tests.h"
#include <stdlib.h>

FILE *output;

void init(char *name) {
    static int first = 1;

    if (first) {
        if (name != NULL) {
            output = fopen(name, "w");
            if (output == NULL) {
                fprintf(stderr, "Erreur interne, impossible de créer le fichier de sortie");
                exit(3);
            }
        } else {
            output = stdout;
        }
        first = 0;
    }
}

void shutdown() {
    fclose(output);
}
