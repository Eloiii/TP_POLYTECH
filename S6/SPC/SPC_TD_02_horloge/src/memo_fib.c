#include "memo_fib.h"

// SUITE DE FIBONACCI

// == Calcul récursif avec mémoization

// === un tableau pour mémoriser les calculs déjà faits
#define SIZE 1024
double FIB[SIZE];
boolean INITIALIZED = false;

void initialize_FIB(){
  int i;
  for(i=0 ; i<SIZE ; i++) FIB[i]=-1;
  INITIALIZED = true;
}

// === memo_fib utilise et alimente le tableau FIB
double memo_fib(int depth, int n){
  double result;                             show_call_fib(depth,n);
  // initialisation au premier appel
  if (!INITIALIZED) initialize_FIB();

  if (n==0 || n==1){
    result = (double)n ;
  } else {
    // >> ... À COMPLÉTER ... <<
  }                                          show_double(depth,result);
  return result;
}


// === affichage du tableau
void show_FIB(){
  int i;
  for(i=2; i<SIZE ; i++){
    if (FIB[i]<0) break;
    printf("\nFIB[%4d] = %f",i,FIB[i]);
  }
}
