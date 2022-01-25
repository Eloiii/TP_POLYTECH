#include <stdio.h>

int a;
int b;
int* pointeur;

int main()
{
    pointeur= &a;
    a=10;
    b=*pointeur;
    *pointeur = 15;
    
    
    printf("Valeur de a: %d\n",a);
    printf("Valeur de b: %d\n",b);
    printf("Valeur de l'adresse de a: %d\n",(int)&a);
    printf("Valeur du pointeur sur a: %d\n",(int)pointeur);
    printf("Valeur de l'adresse du pointeur p: %d\n",(int)&pointeur);
    
    *pointeur=7;
    printf("Nouvelle valeur de a: %d\n",a);

}

