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
int32_t string_length(char *str) {
  int len = 0;
  // faite: (gdb) where
  // cela va vous montrer la pile des appels, elle est expliquée dans le readme.
  char c = *str;
  while (c!=0) {      // notez la construction "while" qui fait que l'exécution
    len = len + 1;    // boucle tant que la condition est vrai (c!=0).
    c = *(str + len);   // Notez ici le calcul arithmetique sur le pointeur s.
  }
  return len;
}

/*
 * Notre point d'entrée habituel:
 *  (gdb) break main
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
void main(void) {
  char *str = "Hello!";
  // à la ligne suivante, si vous faites
  //  (gdb) next
  // gdb va exécuter la fonction mais vous ne pourrez pas observer cette exécution.
  // Par contre, si vous utilisez:
  //  (gdb) step
  // vous allez suivre l'exécution pas-à-pas de l'appel de la fonction.
  int len = string_length(str);

  // Ici vous ne pouvez faire "step", ce n'est pas une de vos fonctions,
  // c'est une fonction de la librairie C et vous n'avez pas les sources.
  // Faite "next" pour exécuter l'appel mais ne pas en voir les details.
  printf("string=\"%s\" length=%d\n",str,len);

  // Faites "continue" ici pour laisser se terminer l'exécution
  return;
}
