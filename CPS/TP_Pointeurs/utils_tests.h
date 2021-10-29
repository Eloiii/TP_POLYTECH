#ifndef __UTILS_TESTS__
#define __UTILS_TESTS__
#include <stdio.h>

extern FILE *output;

#define affiche_test(...) fprintf(output, __VA_ARGS__)

void init(char *filename);
void shutdown();

#endif
