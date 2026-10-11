/*
In a two's complement number representation, our version of itoa does not 
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why 
not. Modify it to print that value correctly, regardless of the machine on which it runs.  
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_NUM 20 
void itoa(int n, char s[]);
void reverse(char s[]);
main(){
printf("The largest positive int number is : %d \n",INT_MAX);
int Number=INT_MAX;
char s[MAX_NUM];
for(int u=0;u<MAX_NUM;u++) s[u]='\0';
itoa(Number,s);
printf("The converted number is INT_MAX=%s",s);

}

/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[]) { 
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