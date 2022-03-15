#include "int_of_string.h"

// conversion string -> int utilisant le schéma de Horner (cf. A&G)

int int_of_string(char string[]){
  int n=0;
  int i=0;
  int digit;
  while(string[i]!='\0'){
    digit=0;
    switch(string[i]){
      case '9' : digit++;
      case '8' : digit++;
      case '7' : digit++;
      case '6' : digit++;
      case '5' : digit++;
      case '4' : digit++;
      case '3' : digit++;
      case '2' : digit++;
      case '1' : digit++;
      default: break;
    }
    n = n*10 + digit;
    i++;
  }
  return n;
}
