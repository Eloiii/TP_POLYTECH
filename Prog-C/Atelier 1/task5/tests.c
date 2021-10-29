#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../task3/math.c"
#include "array.c"

void ensure(int cond) {
  if (cond==0) {
    printf("A test failed.\n");
    exit(-1);
  }
}

void Test01() {
  int* values = malloc(3*sizeof(int));
  values[0] = 4;
  values[1] = 5;
  values[2] = 6;
  int sum = array_sum(values,0,3);
  ensure(sum == 15);
}

void Test02() {
  float* values = malloc(3*sizeof(float));
  values[0] = 4.3F;
  values[1] = 5.2F;
  values[2] = 6.0F;
  float sum = array_sumf(values,0,3);
  ensure(sum == 15.5F);
}

void Test03() {
  int* values = malloc(3*sizeof(int));
  values[0] = 4;
  values[1] = 5;
  values[2] = 6;
  int avg = array_average(values,0,3);
  ensure(avg == 15/3);
}

void Test04() {
  int length = 3;
  float* values = malloc(length*sizeof(float));
  values[0] = 4.3F;
  values[1] = 5.2F;
  values[2] = 6.0F;
  float avg = array_averagef(values,0,length);
  ensure(avg == 15.5f/3.0f);
}

void Test05() {
  int* values = malloc(7*sizeof(int));
  for (int i=0;i<7;i++)
    values[i] = i;
  int avg = array_average(values,4,3);
  ensure(avg == 15/3);
}

void Test06() {
  float* values = malloc(7*sizeof(float));
  values[0] = 0;
  values[1] = 1;
  values[2] = 2;
  values[3] = 3;
  values[4] = 4.3f;
  values[5] = 5.2f;
  values[6] = 6.0f;
  float avg = array_averagef(values,4,3);
  ensure(avg == 15.5f/3.0f);
}

void Test07() {
  int length = 3;
  int* values = malloc(length*sizeof(int));
  values[0] = 4;
  values[1] = 5;
  values[2] = 6;
  int* copy = malloc(6*sizeof(int));
  memset(copy,0,6);
  array_copy(copy,0,values,0,length);
  for (int i=0;i<3;i++)
    ensure(copy[i]==values[i]);
  for (int i=3;i<6;i++)
    ensure(copy[i]==0);
}

void Test08() {
  int len = 7;
  int* values = malloc(len*sizeof(int));
  values[0] = 3;
  values[1] = 1;
  values[2] = 6;
  values[3] = 5;
  values[4] = 7;
  values[5] = 4;
  values[6] = 8;  
  // int[] values = new int[] { 3,1,6,5,7,4,8 };
  array_sort(values,len);
  for (int i=0;i<len-1;i++)
    ensure(values[i] <= values[i+1]);
}

void Test09() {
  int len = 7;
  float* values = malloc(len*sizeof(float));
  values[0] = 3.1f;
  values[1] = 1.2f;
  values[2] = 6.4f;
  values[3] = 5.3f;
  values[4] = 7.5f;
  values[5] = 4.6f;
  values[6] = 8.7f;  
  array_sortf(values,len);
  for (int i=0;i<len-1;i++)
    ensure(values[i] <= values[i+1]);
}


/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {

  Test01();
  Test02();
  Test03();
  Test04();
  Test05();
  Test06();
  Test07();
  Test08();
  Test09();
  printf("All tests passed.\n");
  return 0; 
}
