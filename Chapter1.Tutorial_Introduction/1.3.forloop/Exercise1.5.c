#include <stdio.h>
/*this program print conversion temperature Fahrenheit-Celsius from 300°F to 0°F*/
/*Constants:*/
#define LOWER_LIM 0     /*set lower Fahrenheir temperature limit*/
#define UPPER_LIM 300   /*set upper Fahrenheit temperature limit*/
#define STEP      20    /*temperature resolution*/
main(){
  float celsius=0.0;
  printf("Temperature conversion Fahrenheit-Celsius:\n");
  for(int fahr=LOWER_LIM;fahr<=UPPER_LIM;fahr+=STEP)
    printf("%3d \t %3.2f \n",fahr,(5.0/9.0)*(fahr-32));
}