#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "../task4/string.c"

int main(int nargs, char** args) {

  // initlalize the random generator
  srand(clock());
  
  printf("Bye.\n");
}
