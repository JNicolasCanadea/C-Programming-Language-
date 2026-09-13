#include <stdio.h>
/*Write a program to copy its input to its output, replacing each tab by \t, each 
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an 
unambiguous way. */
main(){
  char c_in;
while((c_in=_getch())!='\r'){
  if      (c_in=='\t') {
    putchar('\\');
    putchar('t');
  }
  else if (c_in == 8 || c_in == '\b') {
    putchar('\\');
    putchar('b');
  }
  else if (c_in=='\\'){
    putchar('\\');
    putchar('\\');
  }
  else putchar(c_in);
}
}