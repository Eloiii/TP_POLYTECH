#include <stdlib.h>

#include <stdio.h>

#include <assert.h>

#include <math.h>

#define NMAX 50000 /* peut etre modifie si necessaire */

int f = 0;
/*
generation_aleatoire
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : les valeurs t[0..n-1] ont ete initialisees avec n valeurs aleatoires
           prises dans [0,2147483647] selon une loi uniforme.
Pre-condition : le generateur aleatoire doit avoir ete initialise avec "srand"
*/

void generation_aleatoire(int t[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    t[i] = rand();
  };
}

/*
generation_aleatoire_non_uniforme
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : les valeurs t[0..n-1] ont ete initialisees avec n valeurs aleatoires
           prises dans [0,2147483647].
Pre-condition : le generateur aleatoire doit avoir ete initialise avec "srand"
*/
void generation_aleatoire_non_uniforme(int t[], int n) {
  int i;
  int x = 0;

  for (i = 0; i < n; i++) {
    t[i] = x;
    x = x + ((rand() % 10) - 2);
  }
}

/*
tri_insertion
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : le tableau t est trie en ordre croissant
*/
void tri_insertion(int t[], int n) {
  int i, j;
  int Clef;

  for (i = 1; i < n; i++) {

    Clef = t[i];

    j = i - 1;

    /* Decalage des valeurs du tableau */
    while ((j >= 0) && (t[j] > Clef) && ++f) {
      t[j + 1] = t[j];
      j = j - 1;
    }

    /* insertion de la clef */
    t[j + 1] = Clef;
  }
  //printf("f=%i\n ",f);
}

void swap(int t[], int i, int j) {
  int tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}

int partition(int t[], int p, int q) {
 int pivot = t[p];
 int petit = p + 1;
 int grand = q;
 while(petit <= grand) {
  f++;
  if(t[petit] <= pivot)
    petit = petit + 1;
  else {
    swap(t, petit, grand);
    grand = grand - 1;
  }
 }
 swap(t, p, grand);
 return grand;
}

/*
tri_segmentation
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : le tableau t est trie en ordre croissant
*/
void tri_segmentation(int t[], int p, int q) {
  if(p < q) {
    int r = partition(t, p, q);
    tri_segmentation(t, p, r-1);
    tri_segmentation(t, r+1, q);
  }
}

void lancer_mesures() {

  unsigned int germe;
  int T[NMAX];
  int N;
  int res;
  int X;

  //printf("Valeur du germe pour la fonction de tirage aleatoire ? ") ;
  res = scanf("%d", & germe);
  //printf("Valeur de X : (nb de répétitions du tri) ") ;
  res = scanf("%i", & X);
  int tabf[X];
  long int moyf[X];
  long int moyff = 0;
  float ecart_type = 0;
  assert(res == 1);
  srand(germe);

  do {
    //printf("Valeur de N ? ") ;
    res = scanf("%d", & N);
    assert(res == 1);
  } while (N < 1 || N > NMAX);

  for (int k = 0; k < X; ++k) {
    germe = rand();

    for (int j = 0; j < X; ++j) {
      f = 0;
      generation_aleatoire(T, N); /* initialisation du tableau T */
      tri_segmentation(T, 0, N); /* tri de T */
      // tri_insertion(T, N);
      // printf("f = %d\n", f);
      tabf[j] = f;
      printf("%i\n", tabf[j]);
      moyf[k] += tabf[j];
    }

    moyf[k] = moyf[k] / X;
    printf("%ld\n ", moyf[k]);
    moyff += moyf[k];
    //printf("La moyenne est : %ld\n",moyf);
  }
  moyff = moyff / X;
  for (int i = 0; i < X; ++i) {
    ecart_type += (moyf[i] - moyff) * (moyf[i] - moyff);
  }
  ecart_type /= X;
  ecart_type = sqrt(ecart_type);
  //printf("%f\n",ecart_type);printf("%ld\n",moyff);
}