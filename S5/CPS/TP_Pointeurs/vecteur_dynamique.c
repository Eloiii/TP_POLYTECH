#include "vecteur_dynamique.h"
#include <stdlib.h>
#include <stdio.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = malloc(sizeof(vecteur));
    v->taille = taille;
    v->donnees = malloc(sizeof(double) * taille);
    if(v->donnees == NULL)
        v->taille = -1;
    return v;
}

void liberer_vecteur(vecteur v) {
    free(v->donnees);
    free(v);
}

int est_vecteur_invalide(vecteur v) {
    int resultat = 0;
    if(v->taille == -1)
        resultat = 1;
    return resultat;
}

double *acces_vecteur(vecteur v, int i) {
    double *resultat = NULL;
    if(i >= 0 && i <= v->taille) {
        resultat = &v->donnees[i];
    } else if(i >=0 && i > v->taille) {
        v->donnees = (double *) realloc(v->donnees, sizeof(double) * (v->taille + (i - v->taille) + 1));
        v->taille = (v->taille + (i - v->taille) + 1);
        if(v->donnees)
            resultat = &v->donnees[i];
    }
    return resultat;
}

int taille_vecteur(vecteur v) {
    int resultat = 0;
    resultat = v->taille;
    return resultat;
}
