#include <stdio.h>
/*check return value from EOF*/
main(){
char ch;
printf("Press a keyboard ctrl+z to see EOF value:\n");
while((ch=getchar())!=EOF) 
  printf("you hasn't entered EOF!");
printf("EOF=%d",ch);
}