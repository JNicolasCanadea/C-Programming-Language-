/*
Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the 
others unchanged.  
*/
#include <stdio.h>
/*---------Function declaration---------*/
unsigned int invert(unsigned char p, unsigned char n, unsigned int y);

main(){
unsigned int y=0x000fff00;
unsigned int x=0;
unsigned char p=3;
unsigned char n=4;
x=invert(p,n,y);
printf("y=%x,p=%d,n=%d,x=%x",y,p,n,x);
}

unsigned int invert(unsigned char p, unsigned char n, unsigned int y){
  unsigned int mask_ones     = 0;
  unsigned int mask_zeros    = 0;
  unsigned int bits_inverted = 0;
  unsigned int y_cleared     = 0;
  mask_ones     = ~(~0 << n)<<(p+1-n);
  printf("mask_ones=%x\n",mask_ones);
  mask_zeros    = ~ mask_ones;
  printf("mask_zeros=%x\n",mask_zeros);
  bits_inverted = ~y & mask_ones;
  printf("bits_inverted=%x\n",bits_inverted);
  y_cleared     = y & mask_zeros;
  printf("y_cleared=%x\n",y_cleared);
  return y_cleared | bits_inverted;
}