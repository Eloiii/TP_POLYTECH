#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>

matrice allouer_matrice(int l, int c) {
    matrice m = { 0, 0, NULL };
    m.l = l;
    m.c = c;
    m.donnees = (double **) malloc(l * sizeof(double *));
    if(m.donnees == NULL)
        m.c = -1;
    for (int i = 0; i < l; ++i)
        m.donnees[i] = malloc(c * sizeof(double));
    return m;
}

void liberer_matrice(matrice m) {
    for (int i = 0; i < m.l; ++i)
        free(m.donnees[i]);
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
    resultat = &m.donnees[i][j];
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
