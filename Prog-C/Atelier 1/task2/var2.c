/*
 * Vous pouvez ignorer les deux lignes suivantes.
 */
#include <stdint.h>
#include <stdio.h>

/*
 * Notre point d'entrée pour l'exécution.
 * Rappel: l'exécution commence toujours par la fonction main.
 */
void main(void) {

  // définissons un pointeur sur un charactère:
  char* s;

  // sa valeur est inconnu, elle peut être n'importe quoi,
  // puisque nous n'avons pas encore assigné de valeur à la variable s.
  //   (gdb) p s
  //   $1 = 0x0
  //
  // Notez que gdb imprime les pointeurs en hexadécimal, cela permet
  // d'indiquer que c'est une adresse et non une valeur entière.

  s = 0x0;

  // Peut-on lire ou écrire à n'importe quelle adresse? 
  //   (gdb) p *s
  //   Cannot access memory at address 0x0
  // Pas vraiment...
  
  s = "abc";

  // parcourons la chaîne de caractères, pour cela, on va
  // utiliser deux nouvelles variables, l'une pour contenir
  // le caractère courant et l'autre l'adresse en mémoire
  // où ce caractère se trouve.
  char c;
  char* pos;

  // suivez l'exécution pas-à-pas en regardant les valeurs
  // des variables "s" et "pos". Rappelez vous, utilisez
  // la commande print de gdb. Notez encore une fois que
  // la variable entière est affichée comme un entier
  // en base 10 alors que l'adresse est affichée en base 16.
  pos = s;
  c = *pos;
  pos = s + 1;
  c = *pos;
  pos = s + 2;
  c = *pos;
  pos = s + 3;
  c = *pos;
  
  // Nota Bene: gdb vous montre la valeur d'une variable de type
  // "char" comme un caractère mais aussi comme un entier,
  // c'est la valeur de l'encodage ASCII du caractère:
  //    c = 98 'b'
  // Notez aussi que gdb fait de même avec le pointeur sur
  // un caractère, qu'il interprète comme pointant sur une chaîne:
  //    pos = 0x4006b6 "c"
  
  // Nota Bene: notez que la chaîne de caractères "abc" est terminée
  // par un caractère "\0' qui marque la fin de la chaîne
  // en mémoire, d'ou l'évolution de l'affichage de la chaîne
  // alors que l'adresse dans le pointeur augmente:
  // pos = 0x4006c4 "abc"
  // pos = 0x4006c5 "bc"
  // pos = 0x4006c6 "c"
  // pos = 0x4006c7 ""

  // les lignes précédentes s'écrivent aussi comme cela:
  pos = s;
  c = *pos;
  c = *(pos+1);
  c = *(pos+2);
  c = *(pos+3);

  // les lignes précédentes s'écrivent aussi comme cela:
  pos = s;
  c = pos[0];
  c = pos[1];
  c = pos[2];
  c = pos[3];

  return;
}
