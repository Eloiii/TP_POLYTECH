#include "hms.h"

hms _global_hms;

void hms_init(){
	_global_hms.h = 0;
	_global_hms.m = 0;
	_global_hms.s = 0;
}

void hms_print(hms t){
	printf("%2dh%2dm%2ds", t.h, t.m, t.s);
}

void hms_get(hms* t){
	(*t) = _global_hms; // create a copy/clone
}

void hms_tick(){
	char sec = _global_hms.s;
	char min = _global_hms.m;
	char hr  = _global_hms.h;
	sec +=1;
	min += (sec == 60) ? 1 : 0;
	hr += (min == 60) ? 1 : 0;
	_global_hms.h = hr;
	_global_hms.m = min;
	_global_hms.s = sec;
}

void hms_diff(hms* delta, hms t1, hms t0){
	char hr  = t1.h - t0.h;
	char min = t1.m - t0.m;
	char sec = t1.s - t0.s;
	if (sec<0){ sec+=60; min-=1; }
  if (min<0){ min+=60; hr -=1; }
	delta->h = hr;
	delta->m = min;
	delta->s = sec;
}

void hms_div(hms* duration, int divisor){
	char r; // remainder
	char h,m,s;
	// >> ... À COMPLÉTER ... <<
	duration->h = h;
	duration->m = m;
	duration->s = s;
}
