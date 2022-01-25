#include <stdlib.h> 
#include <stdio.h>
#include "fibo_compute.h"

int main(int argc, const char* argv[]) {
	long long res_rec;
	long long res_iter;
	long long res_rec2;
	long long res_golden;
	// float res_pui;
	long long res_fibo_mat;
	int n;
	// float x;

	n = atof(argv[1]);
	// n = atoi(argv[2]);
	res_rec = n > 45 ? 0 : fibo_rec(n);
	res_iter = fibo_iter(n);
	res_rec2 = fibo_rec2(n);
	// res_pui = puissance(x, n);
	// res_pui = exponentiation_rapide(x, n);
	res_golden = fibo_golden(n);
	res_fibo_mat = fibo_mat(n);

	printf("res_rec = %lld\n res_iter = %lld\n res_rec2 = %lld\n res_golden = %lld\n res_fibo_mat = %lld\n", res_rec, res_iter, res_rec2, res_golden, res_fibo_mat);
	return 0;
}
