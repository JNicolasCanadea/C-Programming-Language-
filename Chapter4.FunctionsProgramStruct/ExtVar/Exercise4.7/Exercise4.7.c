/*
Write a routine ungets(s) that will push back an entire string onto the input. 
Should ungets know about buf and bufp, or should it just use ungetch? 
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>  /* for  atof() */ 
#include <ctype.h>
#define MAX_STR 100 
int  getch(void); 
void ungetch(int);
void gets(char s[],int lim);
void ungets(char s[]);
main() {
char s[MAX_STR];
char tmp[MAX_STR];
gets(s,MAX_STR);
printf("Got string is: %s \n",s);
ungets(s);
gets(tmp,strlen(tmp));
printf("Unget string is: %s \n",tmp);
}

#define BUFSIZE 100 
char buf[BUFSIZE];    /* buffer for ungetch */ 
int bufp = 0;         /* next free position in buf */ 
int getch(void)  /* get a (possibly pushed-back) character */ 
{ 
    return (bufp > 0) ? buf[--bufp] : getchar(); 
} 

void ungetch(int c)   /* push character back on input */ 
{ 
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else 
        buf[bufp++] = c; 
}

void gets(char s[], int lim) {
    char c,i = 0;
    while(--lim>0 && (c = getch())!=EOF && c!='\n')
        s[i++] = c;
    s[i] = '\0';
}

void ungets(char s[]) {
    int size=strlen(s);
    for(int u=0;u<size+1;++u)
        ungetch(s[size-u]);
}



