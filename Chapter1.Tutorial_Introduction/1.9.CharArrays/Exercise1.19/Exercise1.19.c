/*
Write a function reverse(s) that reverses the character string s. Use it to 
write a program that reverses its input a line at a time. 
*/
#include <stdio.h>
#define MAXLINE 40 //Limit of characters in each line.

/*Declare function 'getline()'*/
int getline(char line[], int maxline);
/*Function 'revline()'*/ 
int revline(char line[],char linerev[],int lenline);

/* print the longest input line */ 
main() 
{ 
  int len;            /* current line length */ 
  int max;            /* maximum length seen so far */ 
  char line[MAXLINE];    /* current input line */ 
  char linerev[MAXLINE];    /* current input line */ 
  max = 0; 
  while ((len = getline(line, MAXLINE)) > 0) 
    if (len > 0) {  /* there was a line */
      printf("%s", line);
      printf("len:%d",len);
      revline(line,linerev,len);
      printf("%s", linerev);
    } 
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

/* revline:  read a line into s, return length  */ 
int revline(char line[],char revline[],int lenline) { 
  int i; 
  for (i=0; i < lenline; ++i) 
    revline[lenline-i-1] = line[i];
  revline[i]='\n';
  ++i;
  revline[i]='\0';
  return 0; 
}
