#include <stdio.h>

// hms = STRUCTURE À 3 CHAMPS : h (heure), m (minute), s (seconde)
typedef
  struct{
    char h;
    char m;
    char s;
  }
  hms;

// VARIABLE GLOBALE / PARTAGÉE
extern hms _global_hms;

// FONCTIONS
void hms_init();
void hms_print(hms t);
void hms_get(hms* t);
void hms_tick();
void hms_diff(hms* delta, hms t0, hms t1);
void hms_div(hms* duration, int divisor);
