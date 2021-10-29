#include "utils_vecteur.h"
#include "utils_tests.h"
#include <stdio.h>
#include <stdlib.h>

vecteur construit_vecteur(int n, double *donnees) {
    vecteur v;
    int i;

    v = allouer_vecteur(n);
    if (est_vecteur_invalide(v)) {
        fprintf(stderr, "Erreur d'allocation du vecteur\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
        *acces_vecteur(v, i) = donnees[i];
    return v;
}

void affiche_vecteur(vecteur v) {
    int i;

    affiche_test("[ ");
    for (i = 0; i < taille_vecteur(v); i++)
        affiche_test("%g ", *acces_vecteur(v, i));
    affiche_test("]\n");
}

vecteur lit_vecteur(char *fichier) {
    vecteur v;
    int i, n;
    FILE *f;

    f = fopen(fichier, "r");
    if (f == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier de vecteur %s\n", fichier);
        exit(1);
    }
    fscanf(f, " %d", &n);
    v = allouer_vecteur(n);
    if (est_vecteur_invalide(v)) {
        fprintf(stderr, "Erreur d'allocation du vecteur\n");
        exit(2);
    }
    for (i = 0; i < n; i++)
        fscanf(f, " %lg", acces_vecteur(v, i));
    fclose(f);
    return v;
}
