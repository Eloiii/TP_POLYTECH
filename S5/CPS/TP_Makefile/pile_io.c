#include "pile_io.h"
#include <stdio.h>

void afficher_pile(pile p)
{
  pile temp;

  temp = pile_vide();
  /* parcours la pile en la depilant entierement */
  while (!est_pile_vide(p))
    {
      printf("%d\n",sommet(p));
      temp = empiler(sommet(p),temp);
      p = depiler(p);
    }

  /* on la remet en etat en la rempilant dans l'ordre initial */
  while (!est_pile_vide(temp))
    {
      p = empiler(sommet(temp),p);
      temp = depiler(temp);
    }
}
