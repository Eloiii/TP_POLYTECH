#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../task3/math.c"
#include "array.c"

void test_sum() {
  int length = 4;
  int *array = malloc(length) ;
  array[0] = 0x01;
  array[1] = 0x02;
  array[2] = 0x03;
  array[3] = 0x04;
  printf("sum = %d\n", array_sum(array, 0, length));
  free(array);
}


void test_sumf() {
  int length = 6;
  float *array = malloc(length) ;
  array[0] = 2.2f;
  array[1] = 0.4f;
  array[2] = 5.0f;
  array[3] = 3.8f;
  array[4] = 6.2f;
  array[5] = 4.7f;
  printf("sumf = %f\n", array_sumf(array, 0, length));
  free(array);
}


void test_average() {
  int length = 4;
  int *array = malloc(length) ;
  array[0] = 0x01;
  array[1] = 0x02;
  array[2] = 0x03;
  array[3] = 0x04;
  printf("average = %d\n", array_average(array, 0, length));
  free(array);
}


void test_averagef() {
  int length = 6;
  float *array = malloc(length) ;
  array[0] = 2.2f;
  array[1] = 0.4f;
  array[2] = 5.0f;
  array[3] = 3.8f;
  array[4] = 6.2f;
  array[5] = 4.7f;
  printf("averagef = %f\n", array_averagef(array, 0, length));
  free(array);
}


void test_copy() {
  int length = 4;
  int *array1 = malloc(length);
  int *array2 = malloc(length);
  array2[0] = 0x01;
  array2[1] = 0x02;
  array2[2] = 0x03;
  array2[3] = 0x04;
  array_copy(array1, 0, array2, 0, length);
  printf("copy = ");
  for (int i = 0; i < length; ++i){
    printf("%d ", array1[i]);
  }
  printf("\n"); 
  free(array1);
  free(array2);
}


void test_copyf() {
  int length = 8;
  float *array1 = malloc(length);
  array1[0] = 9.9f;
  array1[1] = 10.10f;
  float *array2 = malloc(length);
  array2[0] = 2.2f;
  array2[1] = 0.4f;
  array2[2] = 5.0f;
  array2[3] = 3.8f;
  array2[4] = 6.2f;
  array2[5] = 4.7f;
  array_copyf(array1, 2, array2, 0, length);
  printf("copyf = ");
  for (int i = 0; i < length; ++i){
    printf("%f ", array1[i]);
  }
  printf("\n"); 
  free(array1);
  free(array2);
}

void test_sort() {
  int length = 4;
  int *array = malloc(length) ;
  array[0] = 0x01;
  array[1] = 0x04;
  array[2] = 0x03;
  array[3] = 0x02;
  array_sort(array, length);
  printf("sort = ");
  for (int i = 0; i < length; ++i){
    printf("%d ", array[i]);
  }
  printf("\n"); 
  free(array);
}


void test_sortf() {
  int length = 6;
  float *array = malloc(length) ;
  array[0] = 2.2f;
  array[1] = 0.4f;
  array[2] = 5.0f;
  array[3] = 3.8f;
  array[4] = 6.2f;
  array[5] = 4.7f;
  array_sortf(array, length);
  printf("sortf = ");
  for (int i = 0; i < length; ++i){
    printf("%f ", array[i]);
  }
  printf("\n");
  free(array);
}




/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {

  test_sum();
  test_sumf();
  test_average();
  test_averagef();
  test_copy();
  test_copyf();
  test_sort();
  test_sortf();
  return 0; 
}
