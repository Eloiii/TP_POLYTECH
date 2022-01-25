#include "vecteur.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = { 0, NULL };
    v.taille = taille;
    v.donnees = malloc(sizeof(double) * taille);
    if(v.donnees == NULL)
        v.taille = -1;
    return v;
}

void liberer_vecteur(vecteur v) {
    free(v.donnees);
}

int est_vecteur_invalide(vecteur v) {
    int resultat = 0;
    if(v.taille == -1)
        resultat = 1;
    return resultat;
}

double *acces_vecteur(vecteur v, int i) {
    double *resultat = NULL;
    resultat = &v.donnees[i];
    return resultat;
}

int taille_vecteur(vecteur v) {
    int resultat = 0;
    resultat = v.taille;
    return resultat;
}
