/*
Write a program to print a histogram of the frequencies of different characters 
in its input. 
*/
#include <stdio.h>
int c_in,i,idx,aascii[128];
main(){
/*clear table*/
for(i=0;i<(sizeof(aascii)/sizeof(aascii[0]));i++)
  aascii[i]=0;

while((c_in=getchar())!=EOF)
  ++aascii[c_in];

printf("Character's frequency:\n");
for(i=0;i<(sizeof(aascii)/sizeof(aascii[0]));i++){
  if(aascii[i]>0){
    printf("'%c':",i);
    for(idx=0;idx<aascii[i];idx++)
      printf("#");
    printf("\n");  
  }
}
}