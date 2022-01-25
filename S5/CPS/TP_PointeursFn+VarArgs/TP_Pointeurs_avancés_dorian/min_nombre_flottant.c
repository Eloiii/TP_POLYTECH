#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int max(int nombre, ...){
    int i;
    va_list ap;

    va_start(ap,nombre);
    for (i=0;i<nombre;i++){
      printf("%d\n", va_arg(ap,double));
    }
    va_end(ap);
}

void main()
{
    max(2, 21, 77);
}