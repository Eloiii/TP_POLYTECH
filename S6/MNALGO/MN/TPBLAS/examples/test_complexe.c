#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define    NB_FOIS        419430412

int main (int argc, char **argv)
{
 complexe_float_t c1= {1.0, 2.0} ;
 complexe_float_t c2= {3.0, 6.0} ;
 complexe_float_t c3 ;

 complexe_double_t cd1 ;
 complexe_double_t cd2 ;
 complexe_double_t cd3 ;

 struct timeval start, end ;
 
 int i ;

 init_flop_micro () ;
 
 c3 = add_complexe_float (c1, c2) ;

 printf ("addition float : c3.r %f c3.i %f\n", c3.real, c3.imaginary) ;

 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;

 cd3 = add_complexe_double (cd1, cd2) ;

 printf ("addition double : cd3.r %f cd3.i %f\n", cd3.real, cd3.imaginary) ;

 c3 = mult_complexe_float(c1, c2);

 printf("mult float : c3.r %f c3.i %f\n", c3.real, c3.imaginary);

 TOP(start) ;
 
 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd3 = add_complexe_double (cd1, cd2) ;
     cd1.real = cd1.real + 1 ;
   }

 TOP(end) ;

 printf ("apres boucle cd3.real %f cd3.imaginary %f duree %f \n", cd3.real, cd3.imaginary, tdiff_micro (&start, &end)) ;

 calcul_flop_micro ("calcul complexe ", NB_FOIS*4, tdiff_micro(&start, &end)) ;
 exit (0) ;
}
