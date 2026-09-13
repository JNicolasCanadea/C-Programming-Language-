#include <stdio.h>

/* Print Fahrenheit-Celsius table for fahr=0,20,40,.....,300; floating point version*/

main(){
  float fahr,celsius;
  float lower,upper,step;
  lower=0;          /*lower limit of temperature scale*/
  upper=300;        /*upper lmit*/
  step=20;          /*step seize*/

  fahr=lower;
  printf("Conversion table from Fahrenheit to Celsius: \n");
  while(fahr<upper){
    celsius=(5.0/9.0)*(fahr-32.0);
    printf("%3.0f \t %4.2f \n",fahr,celsius);
    fahr+=step;  
  }
}