#include "pile.h"
#include "pile_io.h"
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_BUFFER 128

void aide()
{
  fprintf(stderr,"Aide :\n");
  fprintf(stderr,"Saisir l'une des commandes suivantes\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"e nombre   :   empiler un nombre\n");
  fprintf(stderr,"d          :   depiler le sommet\n");
  fprintf(stderr,"s          :   afficher la valeur du sommet\n");
  fprintf(stderr,"a          :   afficher le contenu de la pile\n");
  fprintf(stderr,"h          :   afficher cette aide\n");
  fprintf(stderr,"q          :   quitter ce programme\n");
}

int main()
{
  char buffer[TAILLE_BUFFER];
  char commande;
  int donnee;
  pile p;

  p = pile_vide();
  aide();
  while (1)
    {
      commande = getchar();
      switch (commande)
        {
        case 'e':
          scanf ("%d",&donnee);
          p = empiler(donnee,p);
          printf("%d a ete empile\n",donnee);
          break;
        case 's':
          printf("Le sommet de la pile contient : %d\n",sommet(p));
          break;
        case 'd':
          p = depiler(p);
          printf("Le sommet de la pile a ete depile\n");
          break;
        case 'a':
          printf("La pile :\n");
          afficher_pile(p);
          break;
        case 'h':
          aide();
          break;
        case 'q':
          detruire_pile(p);
          exit(0);
        default:
          fprintf(stderr,"Commande inconnue !\n");
        }
      /* vide ce qu'il reste de la ligne dans le buffer d'entree */
      fgets(buffer,TAILLE_BUFFER,stdin);
    }
  detruire_pile(p);
  return 0;
}
