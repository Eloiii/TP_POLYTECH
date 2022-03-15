#include "main.h"


void traitant(int sig_num){
  alarm(1);     // demande d'envoi du signal SIGALRM dans ~1 seconde.
  printf("\e[1;95m interruption %d \e[m\n", sig_num);
  timer_tick();
  timer_print();
}


int main(int nb_args, char* args[])
{
  timer_init(); // version variable sec
  hms_init();   // version struct h,m,s

  // demande d'envoi du signal SIGALRM dans ~1 seconde.
  alarm(1);
  // association du signal au traitant
  signal (SIGALRM, traitant);

  // récupération des arguments de la ligne de commande
  // run 42 donne nb_args = 2 et args = { "run" , "42" }

  // Utilisez int_of_string.c pour récupérer la valeur de l'entier
  // >> ... À COMPLÉTER ... <<
  if(nb_args > 1)
    chrono_fib(int_of_string(args[1]));

  return 0;
}
