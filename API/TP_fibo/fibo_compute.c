

#include "fibo_compute.h"
#include <stdio.h>
#include <math.h>

long long fibo_rec(long long n) {
	if(n <= 1)
		return n;
	return fibo_rec(n - 1) + fibo_rec(n - 2);
}

long long fibo_iter(int n){
    long f0=1, f1=1, f=1;
    for (int i=2;i<n;++i){
        f=f0+f1;
        f0=f1;
        f1=f;
    }
    return f1;
}

long calc_fibo_rec2(long f0, long f1, long n) {
	if(n == 2)
		return f0 + f1;
	return calc_fibo_rec2(f1, f1+f0, n-1);
}

long long fibo_rec2(long long n) {
	long f0 = 0, f1 = 1;
	return calc_fibo_rec2(f0, f1, n);
}

float puissance(float x, int n) {
	float res = 1;
	for (int i = 0; i < n; ++i)
	{
		res*=x;
	}
	return res;
}

long double exponentiation_rapide(float x, int n) {
	if(n == 1)
		return x;
	if(n % 2 == 0)
		return exponentiation_rapide(x*x, n/2);
	return x * exponentiation_rapide(x*x, (n-1)/2);
}

long long fibo_golden(long n) {
	long double cst = sqrt(5);
    long double phi = exponentiation_rapide((1+cst)/2,n);
    long double triangle = exponentiation_rapide((1-cst)/2,n);
    return (1/cst)*(phi-triangle);
}

Matrice mul_mat(Matrice a, Matrice b) {
	Matrice res;
	res.a = a.a * b.a + a.b * b.c;
	res.b = a.a * b.b + a.b * b.d;
	res.c = a.c * b.a + a.d * b.c;
	res.d = a.b * b.c + a.d * b.d;
	return res;
}

Matrice exponentiation_rapide_mat(Matrice m, int n) {
	if(n == 1)
		return m;
	if(n % 2 == 0)
		return exponentiation_rapide_mat(mul_mat(m, m), n/2);
	return mul_mat(m, exponentiation_rapide_mat(mul_mat(m,m), (n-1)/2));
}

long long fibo_mat(int n) {
	Matrice m = {0, 1, 1, 1};
	Matrice mN = exponentiation_rapide_mat(m, n);
	return mN.b;
}