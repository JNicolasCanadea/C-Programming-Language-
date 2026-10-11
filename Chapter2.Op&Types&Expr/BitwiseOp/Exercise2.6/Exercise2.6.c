/*
Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
#include <stdio.h>
/*---------Function declaration---------*/
unsigned int stbits(unsigned char p, unsigned char n, unsigned int y);

main(){
unsigned int y=0x0000ff00;
unsigned int x=0;
x=stbits(5,3,y);
printf("y=%x,p=5,n=3,x=%x",y,x);
}

unsigned int stbits(unsigned char p, unsigned char n, unsigned int y){
  
  return y | ~(~0 << n)<<(p+1-n);
}