/*
Adapt the ideas of printd to write a recursive version of itoa; that is, convert 
an integer into a string by calling a recursive routine. 
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_NUM 20 
void itoa(int n, char s[]);
void printd(int n);
main() {
    char s[MAX_NUM];
    int nmb = -1000;
    printf("Choose an int nmb =  %d \n", nmb);
    itoa(nmb,s);
    printf("Converted number is : d%s \n",s);
}

/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[]) { 
    static int i  = 0;
    int n_ = 0; 
    if ((n_ = n) < 0) {  /* record sign */ 
        n_ = -n;           /* make n positive */
        s[i++] = '-';        /* negative symbol */
    }
    if(n_ / 10) 
        itoa(n_ / 10,s);
    s[i++] = n_ % 10 + '0';
    s[i]='\0';
} 

/* printd:  print n in decimal */ 
void printd(int n) 
{ 
    if (n < 0) { 
        putchar('-'); 
        n = -n; 
    } 
    if (n / 10) 
        printd(n / 10); 
    putchar(n % 10 + '0'); 
} 