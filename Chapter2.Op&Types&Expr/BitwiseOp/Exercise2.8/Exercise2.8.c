/*
Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n positions.  
*/
#include <stdio.h>
/*---------Function declaration---------*/
unsigned int rightrot(unsigned int x, unsigned char n);

main(){
unsigned int x=0xf000f000;
unsigned int y=0x00000000;
unsigned char n=12;
y=rightrot(x,n);
printf("X=%08x is right rotated by n=%d giving Y=%08x",x,n,y);
}

unsigned int rightrot(unsigned int x, unsigned char n){
  return x>>n;
}