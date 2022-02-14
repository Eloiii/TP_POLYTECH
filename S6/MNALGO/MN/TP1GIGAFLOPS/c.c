#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define N   2048

double A [N][N] ;
double B [N][N] ;
double C [N][N] ;

float tdiff (struct timeval *start,
	     struct timeval *end)
 {
   return (end->tv_sec - start->tv_sec) +
     1e-6*(end->tv_usec - start->tv_usec) ;
 }

int main (int argc, char*argv[])
{
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	{
	  A [i][j] = (double) rand () / (double) RAND_MAX ;
      	  B [i][j] = (double) rand () / (double) RAND_MAX ;
	  C [i][j] = 0 ;
        }
     }

struct timeval start, end ;

 gettimeofday (&start, NULL) ;

 for (int i = 0 ; i < N ; i++)
   {
     for (int j = 0 ; j < N; j++)
       {
	 for (int k = 0 ; k < N; k++)
	   {
	     C [i][j] += A[i][k] * B [k][j] ;
	   }
       }
   }

 gettimeofday (&end, NULL) ;
 printf ("%0.6f\n", tdiff (&start, &end) ) ;
 return 0 ;
}
