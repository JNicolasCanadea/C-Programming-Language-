/*
In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount.  
*/
#include <stdio.h>
int bitcount(unsigned int x);
int bitcount2(unsigned int x);
main(){
unsigned int x=0x0f00ffff;
printf("Count bit for x=%08x is %d\n",x,bitcount(x));
printf("Count bit 2 for x=%08x is %d\n",x,bitcount2(x));
}
/* bitcount:  count 1 bits in x */ 
   int bitcount(unsigned int x) 
   { 
       int b; 
       for (b = 0; x != 0; x >>= 1) 
           if (x & 01) 
               b++; 
       return b; 
   }

/* bitcount2:  count 1 bits in x */ 
   int bitcount2(unsigned int x) 
   { 
       int b=1; 
      while((x&=(x-1))!=0)
               b++; 
       return b; 
   }