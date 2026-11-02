/*
Add access to library functions like sin, exp, and pow. See <math.h> in 
Appendix B, Section 4
*/
#include <stdio.h> 
#include <stdlib.h>  /* for  atof() */ 
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAXOP   100  /* max size of operand or operator */ 
#define MAXSTR   10  /* max size of operand or operator */ 
#define NUMBER  '0'  /* signal that a number was found */
#define ADD_HOC  64 
int getop(char []); 
void push(double); 
double pop(void);
int print_stack(void);
int duplicate_stack(void);
int swap_stack(void);
int clear_stack(void);

/* reverse Polish calculator */ 
main() {   
    int type; 
    double op2; 
    char s[MAXOP]; 
    while ((type = getop(s)) != EOF) { 
        switch (type) { 
        case NUMBER: 
            push(atof(s)); 
            break; 
        case '+': 
            push(pop() + pop()); 
            break; 
        case '*': 
            push(pop() * pop()); 
            break; 
        case '-': 
            op2 = pop();
            push(pop() - op2); 
            break; 
        case '/': 
            op2 = pop(); 
            if (op2 != 0.0) 
                push(pop() / op2); 
            else 
                printf("error: zero divisor\n"); 
            break; 
        case '%': 
            op2 = pop(); 
            if ((int)op2 != 0) 
                push((int)pop() % (int)op2); 
            else 
                printf("error: zero divisor\n"); 
            break;
        case '~': 
            push(-pop()); 
            break;
        case '\n': 
            printf("\t%.8g\n", pop()); 
            break;
        case ADD_HOC:
            {
                if(strcmp(s,"print") == 0)
                    print_stack();
                else if(strcmp(s,"double") == 0)
                    duplicate_stack();
                else if(strcmp(s,"swap") == 0)
                    swap_stack();
                else if(strcmp(s,"clear") == 0)
                    clear_stack();
                else if(strcmp(s,"sin") == 0)
                    push(sin(pop()));   
                else if(strcmp(s,"exp") == 0)
                    push(exp(pop()));
                else if(strcmp(s,"pow") == 0)
                    push(pow(pop(),pop()));   
                else
                    printf(" %s isn't defined as ad hoc command or function\n",s); 
            }
            break;
        default: 
            printf("error: unknown command %s\n", s); 
            break; 
        }
    } 
    return 0;
  }

#define MAXVAL  100  /* maximum depth of val stack */ 
int sp = 0;          /* next free stack position */ 
double val[MAXVAL];  /* value stack */ 
/* push:  push f onto value stack */ 
void push(double f) 
{ 
    if (sp < MAXVAL) 
        val[sp++] = f; 
    else 
        printf("error: stack full, can't push %g\n", f); 
} 
/* pop:  pop and return top value from stack */ 
double pop(void) 
{ 
    if (sp > 0) 
        return val[--sp]; 
    else { 
        printf("error: stack empty\n"); 
        return 0.0; 
    }
}
/* print_stack:  print the top values from stack */ 
int print_stack(void) 
{ 
    if (sp > 0) {
        for(int i=0; i<sp;i++)
            printf("val[%d]=%g \n",i,val[i]);
        return 1;
    }
    else { 
        printf("error: stack empty\n"); 
        return 0; 
    }
}
/* duplicate_stack:  duplicate elements from stack */ 
int duplicate_stack(void) 
{ 
    int spx2=0;
    if (sp > 0) {
        spx2 = 2*sp;
        for(sp; sp < spx2; sp++)
            val[sp] = val[sp-(spx2/2)];
        return 1;
    }
    else { 
        printf("error: stack empty\n"); 
        return 0; 
    }
}

/* swap_top:  swap top elements from stack */ 
int swap_stack(void) 
{ 
    double tmp=0.0;
    if (sp > 0) {
        tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp;
        return 1;
    }
    else { 
        printf("error: stack empty\n"); 
        return 0; 
    }
}

/* clear_stack:  clear stack */ 
int clear_stack(void) 
{ 
    if (sp > 0) {
        for(sp;sp>=0;sp--)
            val[sp];
        return 1;
    }
    else { 
        printf("error: stack empty\n"); 
        return 0; 
    }
}

#include <ctype.h> 
int getch(void); 
void ungetch(int); 
/* getop:  get next character or numeric operand */ 
int getop(char s[]) 
{ 
    int i, c; 
    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ; 
    s[1] = '\0';
    if(isalpha(c)) {
        i = 0;
        while(isalpha(c=getch())) {
            s[++i] = c;
        }
        s[++i] = '\0';
        ungetch(c);
        return ADD_HOC;
    }   
    if (!isdigit(c) && c != '.') 
        return c;      /* not a number */ 
    i = 0; 
    if (isdigit(c))    /* collect integer part */ 
        while (isdigit(s[++i] = c = getch())) 
            ; 
    if (c == '.')      /* collect fraction part */ 
        while (isdigit(s[++i] = c = getch())) 
            ; 
    s[i] = '\0';
    if (c != EOF) 
        ungetch(c);
    return NUMBER; 
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