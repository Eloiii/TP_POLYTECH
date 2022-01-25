#ifndef FIBO_COMPUTE_H
#define FIBO_COMPUTE_H

typedef struct matrice
{
	long long a, b, c, d;
} Matrice;

long long fibo_rec(long long n);
long long fibo_iter(int n);
long long fibo_rec2(long long n);
float puissance(float x, int n);
long double exponentiation_rapide(float x, int n);
long long fibo_golden(long n);
long long fibo_mat(int n);

#endif
