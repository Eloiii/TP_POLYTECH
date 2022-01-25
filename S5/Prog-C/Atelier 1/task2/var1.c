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

  // Définitions deux variables et deux pointeurs:
  int8_t v1;
  int32_t v2;
  int8_t* v1_ptr = &v1;
  int32_t* v2_ptr = &v2;

  // Assignons un valeur à la variable v1
  v1 = 12;

  // la valeur de v1 est maintenant 0
  // afficher cette valeur sous gdb, avec la commande print
  // (gdb) print v1

  // Alors? Gdb affiche bien la valeur de v1, n'est-ce pas?
  // Ouf, c'est confirmé, la valeur est bien 12.

  // Afficher maintenant la valeur de la variable v1_ptr
  // (gdb) p v1_ptr
  // La réponse sera quelque chose comme cela:
  //
  //   $2 = (int8_t *) 0x60104c <v1> ""
  //
  // Gdb est trop fort, il vous montre l'adresse mais il vous
  // indique aussi que c'est effectivement l'adresse de v1.
  
  int8_t* addr = v1_ptr;

  // Faisons le print de addr
  // (gdb) p addr
  // $3 = (int8_t *) 0x60104c <v1> "\002"
  //
  // Gdb vous montre toujours la même adresse, bien sûr,
  // et il est toujours capable de se rendre compte que l'adresse
  // correspond à la zone mémoire nommée pas la variable v1.

  // Maintenant, utilisons les adresses pour manipuler la mémoire,
  // plutôt que les variables. Rappelez vous, une variable est un
  // nom, un simplication pour vous, le développeur.
  // Faire next sous gdb:
  // (gbd) n
  
  *v1_ptr = 2;

  // la valeur de v1 est maintenant 2, à confirmer sous gdb avec print
  // (gdb) print v1
  // Puis vous pouvez confirmer aussi via l'adresse:
  // (gdb) print *v1_ptr

  // Maintenant, faisons les mêmes étapes avec la variable v2,
  // en affichant par programme les valeurs.
  
  v2 = 123456789;

  // skip over these call sites to the function "printf":
  //   (gdb) next
  printf("La valeur de v2 est %d \n",v2);
  printf("L'adresse nommée par v2 est %p \n",v2_ptr);
  
  *v2_ptr = 987654321;

  // skip over these call sites to the function "printf":
  //   (gdb) next
  printf("La valeur de v2 est %d \n",v2);
  printf(" via l'adresse, la valeur est %d \n",*v2_ptr);

  *&v2 = 1234;
	
  // skip over these call sites to the function "printf":
  //   (gdb) next
  printf("La valeur de v2 est %d \n",v2);
  printf("La valeur de v2 est bien %d \n",*&v2);
  printf("L'adresse nommée par v2 est %p \n",&v2);
  
  return;
}
