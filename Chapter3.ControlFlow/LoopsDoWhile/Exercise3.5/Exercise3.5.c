/*
Write the function itob(n,s,b) that converts the integer n into a base b 
character representation in the string s. In particular, itob(n,s,16) formats s as a 
hexadecimal integer in s. 
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_NUM 20
#define DIGIT_DEC_MAX 9
#define HEX 16
#define OCTAL 8
#define DECIMAL 10

void itob(int n, char s[],int b);
void reverse(char s[]);
main(){
int Number = -10e3;
char s[MAX_NUM];
for(int u=0;u<MAX_NUM;u++) s[u]='\0';
itob(Number,s,DECIMAL);
printf("The converted number 10e3 in decimal is: DEC%s \n",s);
itob(Number,s,HEX);
printf("The converted number 10e3 in hexadecimal is: 0x%s \n",s);
itob(Number,s,OCTAL);
printf("The converted number 10e3 in octal is: O%s \n",s);
}

/* itoa:  convert n to characters in s */ 
void itob(int n, char s[],int b) { 
  int i, sign;
  unsigned int n_; 
  if ((sign = n) < 0)  /* record sign */ 
     n_ = -n;          /* make n positive */
  else 
     n_ = n;
  i = 0; 
  do {      /* generate digits in reverse order */ 
    s[i++] = ((n_ % b) > DIGIT_DEC_MAX) ? ((n_ % b) - DECIMAL) + 'A' : (n_ % b) + '0';  /* get next digit */          
  } while ((n_ /= b) > 0);    /* delete it */ 
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