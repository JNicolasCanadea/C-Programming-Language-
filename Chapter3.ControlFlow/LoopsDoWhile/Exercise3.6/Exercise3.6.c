/*
Write a version of itoa that accepts three arguments instead of two. The third 
argument is a minimum field width; the converted number must be padded with blanks on the 
left if necessary to make it wide enough.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_NUM 20
#define WIDTH   10 
void itoa(int n, char s[],int w);
void reverse(char s[]);
main(){
int nb2conv=10e3;
char s[MAX_NUM];
for(int u=0;u<MAX_NUM;u++) s[u]='\0';
itoa(nb2conv,s,WIDTH);
printf("The converted number  %d to string %s width field %d\n",nb2conv,s,WIDTH);
nb2conv=-10e3;
itoa(nb2conv,s,WIDTH);
printf("The converted number %d to string %s width field %d\n",nb2conv,s,WIDTH);
}

/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[], int w) { 
  int i, sign;
  unsigned int n_; 
  if ((sign = n) < 0)  /* record sign */ 
     n_ = -n;          /* make n positive */
  else 
     n_ = n;
  i = 0; 
  do {      /* generate digits in reverse order */ 
      s[i++] = n_ % 10 + '0';  /* get next digit */ 
  } while ((n_ /= 10) > 0);    /* delete it */ 
  if (sign < 0) 
      s[i++] = '-';
  while((WIDTH-i)>0) s[i++] = ' ' ; 
  s[i] = '\0'; 
  reverse(s); 
} 

/* reverse:  reverse string s in place */ 
void reverse(char s[]) { 
  int c, i, j; 
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) { 
      c = s[i]; 
      s[i] = s[j]; 
      s[j] = c; 
  } 
}
