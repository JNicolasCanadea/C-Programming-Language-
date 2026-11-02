/*
Write the function strindex(s,t) which returns the position of the rightmost 
occurrence of t in s, or -1 if there is none. 
*/
#include <stdio.h> 
#define MAXLINE 1000 /* maximum input line length */ 
int getline(char line[], int max); 
int strindex(char source[], char searchfor[]); 
char pattern[] = "ould";   /* pattern to search for */ 
/* find all lines matching pattern */ 
main() 
{  
  char line[MAXLINE]; 
  int found = 0;
  int idx_str=0; 
  while (getline(line, MAXLINE) > 0) 
    if ((idx_str=strindex(line, pattern)) >= 0) { 
      printf("%s", line);
      printf("right index=%d\n",idx_str);
      found++; 
    } 
  return found; 
}

/* getline:  get line into s, return length */ 
int getline(char s[], int lim) 
{ 
  int c, i; 
  i = 0; 
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
    s[i++] = c; 
  if (c == '\n') 
    s[i++] = c; 
  s[i] = '\0'; 
  return i;
} 

/* strindex:  return index of t in s, -1 if none */ 
int strindex(char s[], char t[]) 
{ 
  int i, j, k;
  int rightmost_idx=0;
  int times=0; 
  for (i = 0; s[i] != '\0'; i++) { 
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
      ;
    if (k > 0 && t[k] == '\0') 
      rightmost_idx=i+k-1;
  } 
  return (rightmost_idx>0) ? rightmost_idx : -1; 
} 