#include "instrumentation.h"

// INSTRUMENTATION et affichage tous les FREQ appels

boolean INSTRUMENTATION = false;
int INSTRUMENTATION_FREQUENCY = 30000; // 30000;


int call = 0;

int mod(int n, int p){
  int r = n%p;
  if (n<0) r +=p;
  return r;
}

// == affichage des appels

boolean newline = false;

void show_call_fib(int depth, int n){
  if (INSTRUMENTATION){
    int i;
    if (depth==1) printf("\n");
    printf("\n");
    switch(depth){
      case 0: break;
      case 1: printf("* "); break;
      default: for(i=0 ; i<=depth ; i++) printf(" ");
    }
    printf("fib(%d)",n);
    newline = false;
  } else {
    call = mod(call+1,INSTRUMENTATION_FREQUENCY);
    if (call==1) printf(".");
  }
}

// == affichage du résulat

void show_double(int depth, double d){
  int i;
  if (INSTRUMENTATION){
    if (newline){
      printf("\n");
      for(i=0 ; i<depth ; i++) printf(" ");
      printf("\e[1;34m = %f \e[m",d);
    } else {
      printf("\e[2;34m = %f \e[m",d);
    }
    newline = true;
  }
}
