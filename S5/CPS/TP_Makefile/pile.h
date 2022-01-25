#ifndef PILE_H
#define PILE_H

typedef struct noeud {
	int donnee;
	struct noeud* prochain;
}noeud;

typedef noeud *pile;

pile pile_vide();
void detruire_pile(pile p);
pile empiler(int donnee, pile p);
int sommet(pile p);
pile depiler(pile p);
int est_pile_vide(pile p);

#endif