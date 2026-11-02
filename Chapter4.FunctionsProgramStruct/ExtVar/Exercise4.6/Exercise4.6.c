/*
Add commands for handling variables. (It's easy to provide twenty-six variables 
with single-letter names.) Add a variable for the most recently printed value.  
*/
#include <stdio.h> 
#include <stdlib.h>  /* for  atof() */ 
#include <ctype.h>
#include <string.h>
#include <math.h>
#define  MAXOP   100  /* max size of operand or operator */ 
#define  MAXSTR   10  /* max size of operand or operator */ 
#define  NUMBER  '0'  /* signal that a number was found */
#define  ADD_HOC  64 
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
    double A,B,V;
    char var_sel = '\0', last_op = '\0', op = '\0'; 
    char s[MAXOP]; 
    while ((type = getop(s)) != EOF) { 
        switch (type) { 
        case NUMBER: 
            push(atof(s)); 
            break; 
        case '+': 
            V = A + B; 
            break; 
        case '*': 
            V = A * B;  
            break; 
        case '-': 
            op2 = pop();
            if(last_op == 'B') V = A - B;
            else               V = B - A;
            break; 
        case '/':
            if(last_op == 'B') {
                if (B != 0.0) 
                    V = A/B;
                else
                    printf("error: zero divisor\n"); 
            } 
            else  {          
                if (A != 0.0) 
                    V = B/A;
                else
                    printf("error: zero divisor\n");
            } 
            break; 
        case '%': 
            if(last_op == 'B') {
                if ((int)B != 0) 
                    V = (int)A%(int)B;
                else
                    printf("error: zero divisor\n"); 
            } 
            else  {          
                if ((int)A != 0) 
                    V = (int)B%(int)A;
                else
                    printf("error: zero divisor\n");
            }  
            break;
        case '~': 
            push(-pop()); 
            break;
        case '=': 
            if(var_sel == 'A') 
                A = pop();
            else if (var_sel == 'B')
                B = pop();
            else {
                printf("No variable has selected");
                var_sel = '\0'; 
            }
            break;    
        case '\n': 
            printf("A = %.8g B = %.8g\n V = \t%.8g\n",A,B,V);
            var_sel = '\0';
            A = NAN;
            B = NAN;
            V = NAN;
            last_op = '\0';
            op = '\0';
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
                else if(strcmp(s,"sin") == 0) {
                    if(last_op == 'B') 
                        V = sin(B);
                    else if (last_op == 'A')
                        V = sin(A);
                    else
                        printf("Doesn't exist an operand.");
                }   
                else if(strcmp(s,"exp") == 0) {
                    if(last_op == 'B') 
                        V = exp(B);
                    else if (last_op == 'A')
                        V = exp(A);
                    else
                        printf("Doesn't exist an operand.");
                }
                else if(strcmp(s,"pow") == 0) {
                    if(last_op == 'B') 
                        V = pow(A,B);
                    else if (last_op == 'A')
                        V = pow(B,A);
                    else
                        printf("Doesn't exist an operand.");
                } 
                else if(strcmp(s,"A") == 0) {
                    var_sel = 'A';
                    last_op = 'A';
                }
                else if(strcmp(s,"B") == 0) {
                    var_sel = 'B';
                    last_op = 'B';
                }   
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