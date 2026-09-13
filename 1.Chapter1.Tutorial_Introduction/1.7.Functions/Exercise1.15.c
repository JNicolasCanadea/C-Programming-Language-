/*
Rewrite the temperature conversion program of Section 1.2
for conversion.  
*/
#include <stdio.h>
/*Function declaration*/
float Fahr2Celsius(float);
main(){
  float Fahr;
  for(Fahr=0;Fahr<300;Fahr+=20)
    printf("Fahrenheit %3.1f degrees are equivalent to %3.1f Celsius\n",Fahr,Fahr2Celsius(Fahr));
}

/*Function definition: translate Celsius degrees to Fahrenheit*/
float Fahr2Celsius(float F){
  return (5.0/9.0)*(F-32.0);
}