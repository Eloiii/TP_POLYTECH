#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../task3/math.c"
#include "string.c"

void test_string_length() {
  char *s1 = "Hello World";
  int len = string_length(s1);
  printf("length(\"%s\")=%d\n",s1,len);

}


void test_string_copy() {
  char *s1 = "Hello World";
  char *s2 = malloc(sizeof(s1));
  string_copy(s2, s1);
  printf("string_copy(s2, 'Hellow Word')=%s\n", s2);

}

void test_string_concat() {
  char *s1 = "Hello";
  char *s2 = "World";

  // Il nous faut allouer une zone mémoire pour accueillir cette concaténation,
  // et cette zone mémoire doit être assez grande pour contenir tous les caractères
  // de la chaîne s1 et ceux de la chaîne s2. N'oubliez pas l'indicateur de fin
  // de chaîne (un byte de valeur zéro).
  int len = string_length(s1) + string_length(s2) + 1;

  // voici la fonction pour allouer une zone mémoire, l'argument donne le nombre
  // d'octets souhaité:
  char *s3 = malloc(len);
  
  string_concat(s3,s1);
  string_concat(s3,s2);
  printf("string_concat(\"%s\",\"%s\")=%s\n",s1,s2,s3);

  free(s3);
}

void test_string_cmp() {
  char *s1 = "Hello";
  char *s2 = "World";
  int i = string_cmp(s1,s1);
  printf("string_cmp(\"%s\",\"%s\")=%d\n", s1,s1,i);

  i = string_cmp(s1,s2);
  printf("string_cmp(\"%s\",\"%s\")=%d\n", s1,s2,i);

  i = string_cmp(s2,s1);
  printf("string_cmp(\"%s\",\"%s\")=%d\n", s2,s1,i);
}

void test_string_substring() {
  char *s = "HelloWorld";

  // nous voulons couper la chaîne en deux mots: "Hello" et "World"
  int len = string_length(s);
  int pos = string_index_of(s,0,'W');

  // maintenant que nous connaissons la position (pos) du caractère 'W'
  // nous pouvons allouer les deux zones mémoires pour les deux chaînes
  // qui contiendront les deux mots "Hello" et "World"
  char *s1 = malloc(pos+1);
  char *s2 = malloc(len-pos+1);

  // faisons le découpage de la chaîne "HelloWorld"
  string_substring(s1,0,s,0,5);
  string_substring(s2,0,s,5,5);

  printf("substring(s1,0,\"%s\",0,5)=%s\n",s,s1);
  printf("substring(s1,0,\"%s\",5,5)=%s\n",s,s2);

  free(s1);
  free(s2);
}
/*
 * Notre point d'entrée habituel.
 * Maintenant nous pouvons reconnaître que c'est une fonction, 
 * comme les autres, c'est seulement la première appelée:
 */
int main(int nargs, char** args) {

  // En premier, testons la fonction string_length:
  test_string_length();

  test_string_copy();

  // nous allons maintenant tester la concaténation des deux strings s1 et s2,
  test_string_concat();

  // testons maintenant la comparaison de string
  test_string_cmp();

  // testons  maintenant l'extraction de sous-chaîne, ce qui test aussi
  // la recherche de l'index d'un caractère dans une chaîne.
  test_string_substring();
  
  return 0; 
}
