/*
Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. 
*/
#include <stdio.h>
#define MAXLINE 40 //Limit of characters in each line.

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
    if ((len > 0) && !(line[0]=='\n'))  /* there was a line */ 
      printf("%s", line); 
  return 0;
} 

/* getline:  read a line into s, return length  */ 
int getline(char s[],int lim) { 
  int c, i; 
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n' && c!=' ' && c!='\t'; ++i) 
    s[i] = c;
  
  if (c == '\n') { 
    s[i] = c; 
    ++i; 
  } 
  s[i] = '\0'; 
  return i; 
} 
