#include <stdio.h>
#define TAILLE 5

//retourne la somme des elements du tableau tab
int somme(int tab[])
{
    int somme = 0;
    for (int i = 0; i < TAILLE; ++i)
    {
        somme += tab[i];
    }
    return somme;
}

int main()
{
    int t[TAILLE] = {10, 9, 77, 40, 1};
    int res;

    res= somme(t);
    printf("Resultat:%d\n",res);
}

