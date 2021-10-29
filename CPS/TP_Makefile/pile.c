#include "pile.h"
#include <stdlib.h>

pile pile_vide()
{
  return (pile) NULL;
}

void detruire_pile(pile p)
{
  pile prochain;

  while (p)
    {
      prochain = p->prochain;
      free(p);
      p = prochain;
    }
}

pile empiler(int donnee, pile p)
{
  pile element;

  element = (pile) malloc(sizeof(struct noeud));
  element->donnee = donnee;
  element->prochain = p;
  return element;
}

int sommet(pile p)
{
  if (p)
      return p->donnee;
  else
      return 0;
}

pile depiler(pile p)
{
  pile prochain;

  if (p)
    {
      prochain = p->prochain;
      free(p);
      return prochain;
    }
  else
      return (pile) NULL;
}

int est_pile_vide(pile p)
{
  return p==(pile) NULL;
}
