#include "matrice_lineaire.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    matrice m = { 0, 0, NULL };
    m.l = l;
    m.c = c;
    m.donnees = (double *) malloc(sizeof(double) * l * c);
    if(m.donnees == NULL)
        m.c = -1;
    return m;
}

void liberer_matrice(matrice m) {
    free(m.donnees);
}

int est_matrice_invalide(matrice m) {
    int resultat = 0;
    if(m.c == -1)
        resultat = 1;
    return resultat;
}

double *acces_matrice(matrice m, int i, int j) {
    double *resultat = NULL;
    resultat = &m.donnees[i * m.c + j];
    return resultat;
}

int nb_lignes_matrice(matrice m) {
    int resultat = 0;
    resultat = m.l;
    return resultat;
}

int nb_colonnes_matrice(matrice m) {
    int resultat = 0;
    resultat = m.c;
    return resultat;
}
