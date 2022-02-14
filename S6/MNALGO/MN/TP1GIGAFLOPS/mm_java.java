import java.util.Random;

public class mm_java
{
    static int N = 2048 ;
    
    static double [][] A = new double [N][N];
    static double [][] B = new double [N][N];
    static double [][] C = new double [N][N];

    public static void main (String[] args)
    {
	Random r = new Random () ;

	for (int i = 0; i < N; i++)
	    {
		for (int j = 0 ; j < N ; j++)
		    {
			A[i][j] = r.nextDouble () ;
			B[i][j] = r.nextDouble () ;
			C[i][j] = 0 ;
		    }
	    }

	long start = System.nanoTime () ;

	for (int i = 0; i < N; i++)
	    {
		for (int j = 0 ; j < N ; j++)	
		    {
			for (int k = 0 ; k < N; k++)
			    {
				C[i][j] += A[i][k] * B [k][j] ;
			    }
		    }
	    }

	long stop = System.nanoTime () ;


	double tdiff = (stop - start) * 1e-9 ;

	System.out.println (tdiff) ;
    }
}
