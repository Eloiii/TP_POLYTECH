#include "fib.h"

// CALCUL DE LA SUITE DE FIBONACCI

// === version 1. Le calcul naif.

double fib(int depth, int n){
  double result;
                      show_call_fib(depth,n);

  if (n==0 || n==1)
    result = (double) n;
  else
    result = fib(depth+1, n-1) + fib(depth+1,n-2);

                      show_double(depth,result);
  return result;
}

// === version 2. avec mémoization, voir memo_fib.c
