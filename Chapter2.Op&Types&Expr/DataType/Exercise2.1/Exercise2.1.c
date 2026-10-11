/*
Write a program to determine the ranges of char, short, int, and long 
variables, both signed and unsigned, by printing appropriate values from standard headers 
and by direct computation. Harder if you compute them: determine the ranges of the various 
floating-point types.  
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

main(){
 char a=0;
 short int b=0;
 int c=0;
 long int d=0;
 long long int e=0;

 printf("Signed char range:\n");
 printf("Min=%d\n",SCHAR_MIN);
 printf("Max=%d\n",SCHAR_MAX);
 printf("Unsigned char range:\n");
 printf("Min=%d\n",0);
 printf("Max=%d\n",UCHAR_MAX);
 printf("Char has :%d bytes",(int)sizeof(a));
 printf("--------------------\n");
 printf("Signed short range:\n");
 printf("Min=%d\n",SHRT_MIN);
 printf("Max=%d\n",SHRT_MAX);
 printf("Unsigned short range:\n");
 printf("Min=%d\n",0);
 printf("Max=%d\n",USHRT_MAX);
 printf("Short int has :%d bytes",(int)sizeof(b));
 printf("--------------------\n");
 printf("Signed int range:\n");
 printf("Min=%d\n",INT_MAX);
 printf("Max=%d\n",INT_MIN);
 printf("Unsigned int range:\n");
 printf("Min=%d\n",0);
 printf("Max=%u\n",UINT_MAX);
 printf("Int has :%d bytes",(int)sizeof(c));
 printf("--------------------\n");
 printf("Signed long range:\n");
 printf("Min=%ld\n",LONG_MAX);
 printf("Max=%ld\n",LONG_MIN);
 printf("Unsigned long range:\n");
 printf("Min=%ld\n",0);
 printf("Max=%lu\n",ULONG_MAX);
 printf("Long int has :%d bytes",(int)sizeof(d));
 printf("-----------------------\n");
 printf("Signed long long range:\n");
 printf("Min=%lld\n",LLONG_MAX);
 printf("Max=%lld\n",LLONG_MIN);
 printf("Unsigned long range:\n");
 printf("Min=%d\n",0);
 printf("Max=%llu\n",ULLONG_MAX);
 printf("Long long int has :%d bytes",(int)sizeof(e));


}