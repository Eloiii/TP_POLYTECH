#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/* calcul de la division euclidienne "binaire" */



main(int argc, char * argv[])
{
    unsigned int a,b,n,q,r;
	
    if (argc != 3) exit(0);
    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%d", &b);
    
	q=0; 
	n=0;
	while (b<=a)
	{
		b=b*2;
		n++;
	}
	r=a;
	while (n>0)
	{
		b=b/2;
		n=n-1;
        q=2*q;
		if (r>=b)
		{
			q=q+1;
			r=r-b;
		}
	}
	printf("Resultat quotient: %d reste : %d\n",  q,r);
}
