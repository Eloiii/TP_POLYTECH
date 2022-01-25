#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN   0  // Standard input (stdin)
#define STDOUT  1  // Standard output (stdout)
#define STDERR  2  // Standard error (stderr)

/*
 * Lire un caractère de l'entrée standard qui est le clavier 
 * dans notre cas puisque le program est lancé depuis le shell
 * dans un terminal. 
 * Attention: cette méthode fait l'hypothèse que l'utilisateur 
 * n'utilisera que des caractères ASCII, encodé sur 8 bits. 
 * Donc ne saisissez pas de caractères accentués.
 * Retourne le nombre de caractères lus ou -1 en cas d'erreur.
 */ 
int read_char(char* ch) {
  return read(STDIN, ch, 1);
}

/*
 * Définissons un buffer global pour lire les caractères entrés au clavier.
 * Ce buffer est un tableau d'octets en mémoire, d'une longueur de 80 octets.
 * Il est unique et alloué au début de la fonction "main"
 */
#define BUFFER_SIZE 80
char* buffer=NULL;

/*
 * Cette fonction va lire une ligne depuis le clavier, c'est à dire tous les
 * caractères tapés jusqu'àu caractère "ENTER", qui s'écrit '\n'.
 */
char* read_line() {
  int len = 0;
  char *str;
  char ch;
  do {
    // sommes nous en train de déborder de notre buffer?
    // si c'est le cas, simulons l'entrée du caractère
    // de fin de ligne (ENTER)
    if (len >= BUFFER_SIZE)
      break;
    // lire le prochaing caractère et le rajouter au buffer
    // mais seulement si on a lu un caractère, sinon on simule
    // une fin de ligne en sortant de la boucle.
    if (read_char(&ch)!=1) {
      if (len==0)
        return NULL;
      break;
    }
    buffer[len] = ch;
    len = len + 1;
  } while (ch!='\n');
  // Nota Bene: nous avons comme dernier caractère '\n'
  // mais nous devons le remplacer par '\0' pour indiquer
  // la fin de la chaîne de caractère:
  len = len - 1;
  buffer[len]='\0';
  // Nota Bene: nous devons faire une copie de la chaîne lue
  //            dans une nouvelle zone mémoire pour que l'on
  //            puisse réutiliser le buffer pour la prochaine
  //            lecture d'une autre ligne.
  str = malloc(len+1);
  for (int i=0;i<=len;i++)
    str[i] = buffer[i];
  return str;
}

/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {

  // allouons le buffer pour la lecture du clavier.
  buffer = malloc(BUFFER_SIZE);
  // la sortie standard n'imprime pas toujours immédiatement,
  // l'impression attends souvent le caractère de fin de ligne "\n'.
  // Mais ici, on souhaite afficher un point d'intérogation en
  // début de ligne pour indiquer à l'utilisateur que la machine
  // attends qu'il tape une ligne au clavier.
  setbuf(stdout, NULL);
  
  printf("This is an echo program, it echoes what you type.\n");
  printf("Enter an empty line to quit.\n");
  while (1) {
    // imprimons l'invite pour l'utilisateur qui va s'imprimer
    // car nous avons appelé: setbuf(stdout, NULL);
    printf("? ");
    // lire la ligne entrée par l'utilisateur:
    char *str = read_line();
    if (str==NULL)
      break;
    // si la ligne est vide, cela indique la volonté de quitter
    // nous allons donc arrêter le programme.
    if (str[0]==0)
      break;

    // c'est l'écho tant attendu ! ;-)
    printf("-> %s\n", str);

    // la chaîne de caractère a été allouée et nous allons l'oubliée,
    // donc il est important de la libérée pour récupérer la zone
    // mémoire et ne pas laisser trainer en mémoire des zones allouées
    // mais qui ne servent plus à rien.
    free(str);
  }
  printf("Bye.\n");
  return 0; 
}
