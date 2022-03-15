#include "timer.h"

// timer 3
char timer_heure;
char timer_minute;
char timer_seconde;

// timer 4
double timer_sec;

void timer_init(){
  timer_heure = 0;
  timer_minute = 0;
  timer_seconde = 0;
}

void timer_tick(){
  timer_seconde +=1;
  if(timer_seconde==60) {
    timer_minute += 1;
    timer_seconde = 0;
  }
  if(timer_minute==60) {
    timer_heure += 1;
    timer_minute = 0;
  }
}


void timer_print(){
  printf("timer: %ih %im %is\n", timer_heure, timer_minute, timer_seconde);
}
