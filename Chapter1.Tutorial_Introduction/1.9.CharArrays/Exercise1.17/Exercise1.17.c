/*
Write a program to print all input lines that are longer than 80 characters.
*/
#include <stdio.h>

#define MAXLINE_PRINT 80 //Longest line size to print.
#define MAXLINE     1000 //Max line size.

/*Declare function 'getline()'*/
int getline(char line[], int maxline); 

/* print the longest input line */ 
main() 
{ 
  int len;            /* current line length */ 
  int max;            /* maximum length seen so far */ 
  char line[MAXLINE];    /* current input line */ 
  max = 0; 
  while ((len = getline(line, MAXLINE)) > 0) 
    if (len > MAXLINE_PRINT)  /* there was a line */ 
      printf("%s", line); 
  return 0;
} 

/* getline:  read a line into s, return length  */ 
int getline(char s[],int lim) { 
  int c, i; 
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
    s[i] = c; 
  if (c == '\n') { 
    s[i] = c; 
    ++i; 
  } 
  s[i] = '\0'; 
  return i; 
} 


