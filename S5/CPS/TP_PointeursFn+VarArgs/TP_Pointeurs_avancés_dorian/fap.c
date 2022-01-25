#include "fap.h"
#include <unistd.h>
#include <stdlib.h>

fap creer_fap_vide(int (*comparer)(maillon, maillon))
{
  fap resultat;

  resultat.tete = NULL;
  resultat.comparer = comparer;
  return resultat;
}

// fap inserer(fap f, int element, int priorite)
// {
//     maillon *nouveau, *courant, *precedent;

//   nouveau = (  maillon *) malloc(sizeof(  maillon));
//   nouveau->element = element;
//   nouveau->priorite = priorite;
//   if ((f.tete == NULL) || (priorite < f.tete->priorite))
//     {
//       nouveau->prochain = f.tete;
//       f.tete = nouveau;
//     }
//   else
//     {
//       precedent = f.tete;
//       courant = precedent->prochain;
//       while ((courant != NULL) && (priorite >= courant->priorite))
//         {
//           precedent = courant;
//           courant = courant->prochain;
//         }
//       precedent->prochain = nouveau;
//       nouveau->prochain = courant;
//     }
//   return f;
// }

fap inserer(fap f, int element, int priorite)
{
    maillon *nouveau, *courant, *precedent;

  nouveau = (  maillon *) malloc(sizeof(  maillon));
  nouveau->element = element;
  nouveau->priorite = priorite;
  if ((f.tete == NULL) || f.comparer(*nouveau, *f.tete)/* (priorite < f.tete->priorite) */)
    {
      nouveau->prochain = f.tete;
      f.tete = nouveau;
    }
  else
    {
      precedent = f.tete;
      courant = precedent->prochain;
      while ((courant != NULL) && !(f.comparer(*nouveau, *f.tete))/* (priorite >= courant->priorite) */)
        {
          precedent = courant;
          courant = courant->prochain;
        }
      precedent->prochain = nouveau;
      nouveau->prochain = courant;
    }
  return f;
}
  
fap extraire(fap f, int *element, int *priorite)
{
    maillon *courant;

  if (f.tete != NULL)
    {
      courant = f.tete;
      *element = courant->element;
      *priorite = courant->priorite;
      f.tete = courant->prochain;
      free(courant);
    }
  return f;
}

int est_fap_vide(fap f)
{
  return f.tete == NULL;
}

void
detruire_fap(fap f)
{
  int element, priorite;

  while (!est_fap_vide(f))
      f = extraire(f,&element,&priorite);
}
