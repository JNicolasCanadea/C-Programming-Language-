#include <stdio.h>
/*check return value from getchar()*/

main(){
char ch;
printf("Print a keyword for check compare condition false or true or out with ctrl+z:\n");
while((ch=getchar())!=EOF) 
  printf("you has entered EOF? False=%d\n",ch!=EOF);
printf("you has entered ctrl+z or EOF? True:%d",ch==EOF);
}