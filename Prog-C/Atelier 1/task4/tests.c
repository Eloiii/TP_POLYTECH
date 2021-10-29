#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../task3/math.c"
#include "string.c"

void ensure(int cond) {
  if (cond==0) {
    printf("Tests failed.\n");
    exit(-1);
  }
}

void strTest01() {
  char* s = "";
  printf("%d", string_length(s));
  ensure(string_length(s) == 0);
}

void strTest02() {

  char* s = "abc def"; 
  int len = string_length(s);
  ensure(len == 7);
}

void strTest03() {
  char* s = "abc";
  int r = string_cmp(s, s);
  ensure(r == 0);
}

void strTest04() {
  char* s1 = "abc";
  char* s2 = malloc(4);
  strcpy(s2,s1);
  int r = string_cmp(s1, s2);
  ensure(r == 0);
  free(s2);
}

void strTest05() {
  char* s1 = "abc";
  char* s2 = "abcd";
  int r = string_cmp(s1, s2);
  ensure(r < 0);
  r = string_cmp(s2, s1);
  ensure(r > 0);
}

void strTest06() {
  char* s1 = malloc(4);
  char* s2 = "abd";
  string_copy(s1, s2);
  int r = string_cmp(s1, s2);
  ensure(r == 0);
}

void strTest07() {
  char* dst = malloc(12);
  char* src = "abc";
  string_concat(dst, src);
  int len = string_length(dst);
  ensure(len == 3);
  ensure(dst[0] == 'a');
  ensure(dst[1] == 'b');
  ensure(dst[2] == 'c');
  ensure(dst[3] == '\0');
}

void strTest08() {
  char* s2 = "def";
  char* s1 = malloc(10);
  strcpy(s1,"abc");
  string_concat(s1, s2);
  int len = string_length(s1);
  ensure(len == 6);
  char *s = "abcdef";
  for (int i = 0; i < len+1; i++)
    ensure(s1[i] == s[i]);

  s = "def";
  for (int i = 0; i < 4; i++)
    ensure(s2[i] == s[i]);  
}

void strTest09() {
  char* src = "abc";
  char* dst = malloc(4);
  string_substring(dst, 0, src, 0, 3);
  int len = string_length(dst);
  ensure(len == 3);
  char *s = "abc";
  for (int i = 0; i < len+1; i++)
    ensure(dst[i] == s[i]);
  free(dst);
}

void strTest10() {
  char* src = "abc";
  char* dst = malloc(4);
  string_substring(dst, 0, src, 0, 0);
  int len = string_length(dst);
  ensure(len == 0);
  free(dst);
}

void strTest11() {
  char* dst = malloc(7);
  strcpy(dst,"abc");
  char* src = "defg";

  string_substring(dst, 3, src, 0, 3);
  int len = string_length(dst);
  ensure(len == 6);
  char *s = "abcdef";
  for (int i = 0; i < len+1; i++)
    ensure(dst[i] == s[i]);
}

void strTest12() {
  char* s = "abcabc";
  int idx;
  idx = string_index_of(s, 0, 'b');
  ensure(idx == 1);
  idx = string_index_of(s, 2, 'b');
  ensure(idx == 4);
}

void main(void) {
  strTest01();
  strTest02();
  strTest03();
  strTest04();
  strTest05();
  strTest06();
  strTest07();
  strTest08();
  strTest09();
  strTest10();
  strTest11();
  strTest12();
  printf("All tests passed\n");

}

