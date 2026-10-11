 /*
 Rewrite the function lower, which converts upper case letters to lower case, 
with a conditional expression instead of if-else. 
 */
 #include <stdio.h>
 int lower(int c);
 
 main(){
  int c;
  while((c=getchar())!=EOF)
     printf("C=%c lower() is :%c\n",c,lower(c));
}
 /* lower:  convert c to lower case; ASCII only */ 
   int lower(int c) { 
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c ;
   }