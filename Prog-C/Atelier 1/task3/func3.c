/*
 * Vous pouvez ignorer les deux lignes suivantes.
 */
#include <stdint.h>
#include <stdio.h>

/*
 * Voici une fonction, avec un seul argument "s".
 * Le but de la fonction est de calculer la longueur d'une chaîne de caractère.
 * Rappelez vous, une chaîne de caractère est une séquence de caractère en mémoire
 * dont la fin est indiquée par le caractère '\000' de valeur entière 0.
 *
 * Nous allons parcourir la chaîne donnée en paramêtre en comptant le nombre
 * de caractère lu avant de rencontrer la valeur de fin ('\000'). 
 */
int32_t string_length(char *s) {
  // noter l'argument "s", qui est manipulé comme une variable.
  // vous pouvez demander à gdb d'imprimer leur valeur, comme
  // pour les variables locales définies ci-dssous:
  int len = 0;
  char c = *s;
  while (c!=0) {
    len = len + 1;
    c = *(s + len);
  }
  return len;
}

/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {
  int i=0;
  printf("Printing the arguments:\n");
  while (i<nargs) {
    // notez la variable "args" qui locale au bloc lexical de
    // cette boucle (while). Le bloc lexical est délimité par
    // les accolades "{" et "}".
    char *arg = args[i];
    if (arg!=NULL) {
      // notez le test du pointer "arg" contre la valeur NULL
      // qui désigne un pointeur invalide car l'adresse NULL
      // ne correspond jamais à une adresse utilisable en mémoire.
      int len = string_length(arg);
      // ici nous allons appelé une fonction de la librarie standard
      // qui sait comment imprimer tous les types du language C.
      // rechercher les détails de cette fonction sur le Web.
      printf("  args[%d]=\"%s\" \tlength=%d\n",i,arg,len);
    }
    i = i + 1;
  }
  return 0; // 0 veut dire succès, une valeur négative voudrait dire une erreur
}
