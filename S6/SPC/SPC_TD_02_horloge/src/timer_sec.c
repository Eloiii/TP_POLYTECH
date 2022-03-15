#include "timer_sec.h"

// double timer_sec;

void timer_sec_init(){
  timer_sec = 0.0;
}

void timer_sec_tick(){
  timer_sec += 1.0;
}
