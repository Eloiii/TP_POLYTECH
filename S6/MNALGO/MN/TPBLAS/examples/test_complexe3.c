#include <stdio.h>
#include <stdlib.h>
#include "mnblas.h"
#include "complexe2.h"


#define    NB_FOIS        419430412

#include "flop.h"

int main (int argc, char **argv)
{
 complexe_float_t c1= {1.0, 2.0} ;
 complexe_float_t c2= {3.0, 6.0} ;
 complexe_float_t c3 ;

 complexe_double_t cd1 ;
 complexe_double_t cd2 ;
 complexe_double_t cd3 ;

 unsigned long long int start, end  ;
 int i ;

 init_flop_nano () ;
 
 c3 = add_complexe_float (c1, c2) ;

 printf ("c3.r %f c3.i %f\n", c3.real, c3.imaginary) ;

 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;

 cd3 = add_complexe_double (cd1, cd2) ;

 printf ("cd3.r %f cd3.i %f\n", cd3.real, cd3.imaginary) ;

 start = _rdtsc () ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd3 = add_complexe_double (cd1, cd2) ;
     cd1.real = cd1.real + 1.0 ;
   }

 end = _rdtsc () ;

 printf ("apres boucle cd3.real %f cd3.imaginary %f %Ld cycles \n", cd3.real, cd3.imaginary, end-start) ;

 calcul_flop_nano ("calcul complexe nano ", NB_FOIS*4, end-start) ;
 exit (0) ;
 
}


