#include "chrono_fib.h"


// CHRONOMÉTRAGE D'UNE EXÉCUTION

void chrono_fib(int n){
  // mesure du temps d'exécution avec 2 mécanismes de mesure du temps

  // = TIMER START

  // === 1. timer_clock en utilisant des fonctions système de la biliothèque time.c
  clock_t start_time = clock();

  // === 2. timer_hms en utilisant une structure et une interruption
  hms t0;
  hms_get(&t0);

  // DANS CE TP ON SE CONCENTRE SUR LA VERSION 3 et 4
  // === 3. timer en utilisant des variables externes et une interruption
  int h0 = timer_heure ;
  int m0 = timer_minute;
  int s0 = timer_seconde;

  // === 4. timer_sec en utilisant une unique variable et une interruption
  double sd0 = timer_sec;

  // = COMPUTATIONS
  int i;
  for(i=0;i<4;i++){
    // QUESTION Q1 : pourquoi fait-on plusieurs fois le calcul ?
    fib(0,n);
    // à remplacer par la version mémoizée (à compléter): memo_fib(0,n)
  }

  // = TIMER STOP

  // === timer_hms. stop
  hms t1;
  hms_get(&t1);

  // === timer. stop
  // QUESTION Q2 : que se passe-t'il si l'interruption se produit ici à t = 0h 59m 59s
  // on verra t = 0h 59m 59s
  int s1 = timer_seconde;
  // QUESTION Q3 : que se passe-t'il si l'interruption se produit ici à t = 0h 59m 59s
  // on verra t = 1h 0m 59s donc on fera une erreur de ...
  int m1 = timer_minute;
  // QUESTION Q4: que se passe-t'il si l'interruption se produit ici à t = 0h 59m 59s
  // on verra t = 1h 59m 59s donc on fera une erreur de ...
  int h1 = timer_heure;
  // QUESTION Q5 : que se passe-t'il si l'interruption se produit ici à t = 0h 59m 59s
  // on verra t = 0h 59m 59s donc ...

  // === timer_sec. stop
  double sd1 = timer_sec;

  // === timer_clock. stop
  clock_t stop_time = clock();


  // = AFFICHAGE DU TEMPS DE CALCULS

  printf("\n");
  // === timer_clock.
  printf("\nDuration timer 1: %f seconds", (double)(stop_time - start_time) / CLOCKS_PER_SEC );
  // === timer_hms.
  hms d;
  hms_diff(&d,t1,t0);
  printf("\nDuration timer 2:"); hms_print(d);
  // === timer : h0,h1,m0,m1,s0,s1
  printf("\nDuration timer 3: %ds", (h1 * 3600) - (h0 * 3600) + (m1 * 60) - (m0 * 60) + (s1 - s0));
  // === timer_sec.
  printf("\nDuration timer 4: %fs", sd1-sd0);

  printf("\n");
}
