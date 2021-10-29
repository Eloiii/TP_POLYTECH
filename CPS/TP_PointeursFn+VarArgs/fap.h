#ifndef __FAP_H__
#define __FAP_H__

struct maillon {
int element;
int priorite;
struct maillon *prochain;
};

typedef struct {
  struct maillon *tete;
  int (*fonction_comapraison)(int, int);
} fap;

/*
   creer_fap_vide
   description : construit une fap vide.
   parametres : aucun
   valeur de retour : une fap vide
   effets de bord : aucun
*/
fap creer_fap_vide();

/*
   inserer
   description : insere un element etant donne sa priorite.
   parametres : une fap, un element et sa priorite
   valeur de retour : la fap une fois l'element insere
   effets de bord : alloue de la memoire
*/
fap inserer(fap f, int element, int priorite);

/*
   extraire
   description : extrait un element prioritaire de la fap.
   parametres : une fap et les adresses d'un element et d'une priorite
   valeur de retour : element et sa priorite aux adresses passees en parametre
   effets de bord : libere de la memoire
*/
fap extraire(fap f, int *element, int *priorite);

/*
   est_fap_vide
   description : retourne vrai si la fap est vide.
   parametres : une fap
   valeur de retour : un booleen
   effets de bord : aucun
*/
int est_fap_vide(fap f);

/*
   detruire_fap
   description : detruit une fap en liberant toute sa memoire
   parametres : une fap
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void detruire_fap(fap f);

#endif
