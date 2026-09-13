#include <stdio.h> 
   /* count special characters: blanks, tabs and newlines. */ 
   main() {
    int n1=0;
    char c;
    while((c=getchar())!=EOF)
      if(c==(' ' || '/n' || '/t')) ++n1; 
   } 
       