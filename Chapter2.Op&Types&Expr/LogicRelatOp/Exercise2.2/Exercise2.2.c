/*
Write a loop equivalent to the for loop above without using && or ||. 
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
       s[i] = c;
*/
#include <stdio.h>
#define MAX_LIMIT 1000

main(){
  char s[MAX_LIMIT];
  char c=0;
  int  i=0;
  for(i=0;i<MAX_LIMIT;++i){
    if      ((c=getchar())==EOF) break;
    else if (c=='\n')            break;
    else                        s[i]=c;
  }
  s[i]='\0';
  printf("Message is:%s",s);
}