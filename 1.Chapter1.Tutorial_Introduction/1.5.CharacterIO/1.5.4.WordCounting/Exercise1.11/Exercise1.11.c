#include <stdio.h>

/*
1) How would you test the word count program?
2) What kinds of inputs are most likely to uncover bugs if there are any?
*/
#define IN   1  /* inside a word */ 
#define OUT  0  /* outside a word */ 
/* count lines, words, and characters in input */ 
main() { 
  int c, nl, nw, nc, state; 
  state = OUT; 
  nl = nw = nc = 0; 
  while ((c = getchar()) != EOF) { 
    ++nc; 
    if (c == '\n') 
      ++nl; 
    if (c == ' ' || c == '\n' || c == '\t') 
      state = OUT; 
    else if (state == OUT) { 
      state = IN; 
      ++nw; 
      } 
  } 
  printf("%d %d %d\n", nl, nw, nc);
}