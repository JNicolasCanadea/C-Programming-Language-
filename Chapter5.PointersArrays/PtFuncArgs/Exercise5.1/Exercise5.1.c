/*
As written, getint treats a + or - not followed by a digit as a valid 
representation of zero. Fix it to push such a character back on the input. 
*/
#include <stdio.h>
#include <ctype.h>
#define SIZE 10 
int getint(int *pn);
main() {
    int n, result;
    printf("Write integers numbers (use space between then or Enter):\n");
    while ((result = getint(&n)) != EOF) {
        if (result> 0) {
            printf("Number has read succesfully: %d\n", n);
        } else {
            printf("Ignored no valid input.\n");
            getch(); 
        }
    }
    
    printf("End of file has got (EOF).\n");
}

int getch(void); 
void ungetch(int); 
/* getint:  get next integer from input into *pn */ 
int getint(int *pn) { 
    int c, sign; 
    while (isspace(c = getch()))   /* skip white space */ 
        ; 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
        ungetch(c);  /* it is not a number */ 
        return 0;
    } 
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-') 
        c = getch();
    if(isdigit(c)) {
        for (*pn = 0; isdigit(c); c = getch()) 
            *pn = 10 * *pn + (c - '0'); 
        *pn *= sign;
        if (c != EOF) 
            ungetch(c); 
        return c;
    }
    else {
        if (c != EOF) {        
            ungetch(c);
            return 0;
        }
        else 
            return c;
    }

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