/*
 * Vous pouvez ignorer les deux lignes suivantes.
 */
#include <stdint.h>
#include <stdio.h>

/*
 * Voici une nouvelle version de la fonction "string_length". 
 * Elle calcule aussi la longueur de la chaîne de caractère passée en argument,
 * mais cette implémentation vous montre que les arguments sont bien copiés.
 */
int32_t string_length(char *str) {
  // noter l'argument "str", c'est le même nom que la variable dans la fonction main.
  // vérifiez le par la commande "where" puis "up" et "down", pour imprimer la valeur
  // de la variable "str" de la fonction "string_length" versus la valeur de la
  // variable de la fonction "main".
  // vous allez voir que nous modifions celle de la fonction "string_length"
  // et que celle de la fonction "main" conserve sa valeur, il y a bien une
  // copie de la valeur lors de l'appel
  int len = 0;
  char c = *str;
  while (c!=0) {
    len = len + 1;
    str = str + 1; // ici on change la valeur de la variable "str"
                   // vérifiez avec gdb que celle de la variable "str"
                   // de la fonction "main" ne change pas.
                   // Il y a bien deux variables "str", l'une pour
                   // la fonction "main" et l'autre pour la fonction
                   // "string_legnth".
                   // Pour vous convaincre, affichez les adresses des
                   // deux variables "str", vous verrez, elles ne sont pas
                   // les mêmes. Attention, nous parlons bien des adresses
                   // des variables "str" via:
                   //   (gdb) "print &str
                   // et non pas de l'affichage de la valeur qu'elles
                   // contiennent par:
                   //   (gdb) print str
    c = *str;
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
      // rechercher les détails de c
      printf("  args[%d]=\"%s\" \tlength=%d\n",i,arg,len);
    }
    i = i + 1;
  }
  return 0; // 0 veut dire succès, une valeur négative voudrait dire une erreur
}
