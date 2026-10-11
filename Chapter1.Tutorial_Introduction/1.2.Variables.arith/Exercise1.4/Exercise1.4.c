#include <stdio.h>

/* Print Celsius-Fahrenheit table for fahr=0,20,40,.....,300; floating point version*/

main(){
  float fahr,celsius;
  float lower,upper,step;
  lower=0;          /*lower limit of temperature scale*/
  upper=300;        /*upper lmit*/
  step=20;          /*step seize*/

  celsius=lower;
  printf("Conversion table from Celsius to Fahrenheit: \n");
  while(celsius<upper){
    fahr=((9.0/5.0)*celsius)+32.0;
    printf("%3.0f \t %4.2f \n",celsius,fahr);
    celsius+=step;  
  }
}