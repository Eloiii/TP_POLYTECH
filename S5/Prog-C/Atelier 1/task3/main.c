/*
 * Vous pouvez ignorer les deux lignes suivantes.
 */
#include <stdint.h>
#include <stdio.h>

#include "math.c"

/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {

  float f = toRadians(180);
  printf("rads=%f\n",f);
  f = toDegrees(f);
  printf("degs=%f\n",f);

  int i = abs(2);
  printf("abs(2)=%d\n",i);
  i = abs(-1);
  printf("abs(-1)=%d\n",i);

  float j = absf(4.6f);
  printf("absf(4.6)=%f\n",j);
  j = absf(-39.1f);
  printf("absf(-39.1)=%f\n",j);
  
  int m = min(2,3);
  printf("min(2,3)=%d\n",m);
  m = max(2,3);
  printf("max(2,3)=%d\n",m);
  m = min(3,2);
  printf("min(3,2)=%d\n",m);
  m = max(3,2);
  printf("max(3,2)=%d\n",m);

  i = comp(3,3);
  printf("comp(3,3)=%d\n",i);
  i = comp(2,3);
  printf("comp(2,3)=%d\n",i);
  i = comp(3,2);
  printf("comp(3,2)=%d\n",i);

  f = minf(2.0f,3.4f);
  printf("minf(2.0f,3.4f)=%f\n",f);
  f = maxf(3.2f,3.4f);
  printf("maxf(3.2f,3.4f)=%f\n",f);
  f = minf(3.0f,2.0f);
  printf("minf(3.2f,3.4f)=%f\n",f);
  f = maxf(3.0f,2.0f);
  printf("maxf(3.0f,2.0f)=%f\n",f);

  i = compf(3.2f,3.2f);
  printf("compf(3.2f,3.2f)=%d\n",i);
  i = compf(2.35f,3.12f);
  printf("compf(2.35f,3.12f)=%d\n",i);
  i = compf(3.12f,2.35f);
  printf("compf(3.12f,2.35f)=%d\n",i);

  i = factorial(7);
  printf(" factrial(5)=%d\n",i);

  i = power(3,7);
  printf(" power(2,3)=%d\n",i);

  return 0; 
}
