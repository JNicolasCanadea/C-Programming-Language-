/*
Exercise 1-12: Write a program that prints its input one word per line.  
*/
#include <stdio.h>
#include <stdbool.h>
#define OUT 0
#define IN  1
#define CLEAR 0

main(){
  int c_in,nc=CLEAR;
  bool STATE=OUT;
  while((c_in = getchar()) != EOF){
    if(!((c_in == ' ') || (c_in == '\t'))){
      putchar(c_in);
      STATE=IN;
      ++nc;
    }
    else STATE=OUT;
    if(STATE==OUT && nc>0) {
      putchar('\n');
      nc=CLEAR;
    }
  }
}

