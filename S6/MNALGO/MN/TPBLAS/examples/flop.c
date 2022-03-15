#include <stdio.h>
#include <x86intrin.h>

#include "flop.h"


static const float duree_cycle = (float) 1 / (float) 2.6 ;
// 2.6 Ghz sur la machine corte
// duree du cycle processeur en nano seconde (10e9)

static unsigned long long residu_nano ;
static float residu_micro ;

float tdiff_micro (struct timeval *start,
	     struct timeval *end)
 {
   return (end->tv_sec - start->tv_sec) +
     1e-6*(end->tv_usec - start->tv_usec) ;
 }


void init_flop_micro ()
{
  struct timeval start, end ;

  TOP(start) ;

  TOP(end) ;

  residu_micro = tdiff_micro (&start, &end) ;
  printf ("residu_micro = %e\n", residu_micro) ; 
} 

void init_flop_nano ()
{
  unsigned long long start, end ;

  start = _rdtsc () ;

  end = _rdtsc () ;

  residu_nano = end - start ;
  printf ("residu_nano = %Ld cycles \n", residu_nano) ;
}


void calcul_flop_micro (char *message, unsigned int nb_operations_flottantes, float duree)
{
  printf ("%s %d operations duree %.7f seconde  Performance %5.3f GFLOP/s\n", message, nb_operations_flottantes, duree, ((float) nb_operations_flottantes / duree)/1000000000) ;
  return ;
}

void calcul_flop_nano (char *message, int nb_operations_flottantes, unsigned long long int cycles)
{
  printf ("%s %d operations %Ld cycles Performance %5.3f GFLOP/s\n", message, nb_operations_flottantes, cycles, ((float) nb_operations_flottantes) 
/ (((float) cycles) * duree_cycle)) ;
  return ;
}
