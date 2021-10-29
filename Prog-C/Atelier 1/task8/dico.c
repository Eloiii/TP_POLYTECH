#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "../task4/string.c"

#define SOLVED

#define STDIN   0  // Standard input (stdin)
#define BUFFER_SIZE 80
char* buffer=NULL;

/*
 * Cette fonction lit une ligne de texte dans le fichier 
 * passé en argument. Une ligne de texte est une séquence d'octets, 
 * dont la valeur de chaque octet est considérée comme le code ASCII 
 * d'un caractère. Une ligne de texte se termine par la fin de fichier
 * ou le code ASCII pour le caractère '\n'.
 */
char* read_line(int fd) {
  // Not Yet Implemented
  return NULL;
}

/*
 * Cette fonction va écrire la chaîne de caractère passée en argument
 * dans le fichier passé en argument, en écrivant le code ASCII correspondant
 * à chaque caractère de la chaîne, et en terminant la ligne de texte par le 
 * code ASCII du caractère '\n'.
 */
void write_line(int fd, char *line) {
  // Not Yet Implemented
}

void create_dictionary(char *filename) {
  // on enlève le buffering pour la sortie standard
  // afin de voir l'invite '?' pour le prochain mot.
  setbuf(stdout, NULL);
  // on va créer le fichier si il n'existe pas
  // ou l'ouvrir en écriture si il existe, en forçant
  // sa longeur à zéro, s'assurant qu'il est donc vide.
  int fd = open(filename,O_RDWR | O_CREAT | O_TRUNC);
  if (fd<0) {
    perror("PANIC:");
    exit(-1);
  }
  // maintenant la boucle pour lire l'entrée standard
  // et écrire dans le fichier.
  printf("Please enter one word per line:\n");
  printf("  (enter an empty line to quit)\n");  
  while (1) {
    printf("? ");
    char *line = read_line(STDIN);
    if (line==NULL)
      break;
    int len = string_length(line); 
    if (len==0)
      break;
    write_line(fd,line);
    free(line);
  }
  close(fd);
}

/* 
 * Cette fonction va lire un dictionnaire 
 * dans le fichier dont le nom est passé en argument
 * et afficher tous les mots lus à l'écran.
 */
void read_dictionary(char *filename) {
  // Not Yet Implemented
}

void usage() {
  printf("Usage: ./dico -d dico\n");
  exit(-1);
}

int main(int nargs, char** args) {
  // allouons le buffer pour la lecture du clavier.
  buffer = malloc(BUFFER_SIZE);
  if (nargs != 3)
    usage();
  char* filename=NULL;
  for (int i=0; i<nargs; i++) {
    if (string_cmp("-d",args[i])==0) {
      i = i +1;
      filename = args[i];
    }
  }
  if (filename==NULL)
    usage();

  create_dictionary(filename);
  
  read_dictionary(filename);
  
  printf("Bye.\n");
}

