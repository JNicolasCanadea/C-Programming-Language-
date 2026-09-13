#include <stdio.h>
/*This exercise from its stream inputs clear blank characters of two or more of its outputs*/
main(){
  char c_in;
  int cnt=0;
  /*Note:The getchar() function in C reads input from a standard memory buffer one character 
    at a time, waiting until you press the Enter key (\n) before releasing the line for proce-
    ssing.*/
  printf("Type any stream:\n");
  while((c_in=getchar())!=EOF){
    if   (c_in !=' ') {
      putchar(c_in);
      cnt=0;
    }
    else if(c_in==32) {
      if(cnt==0) {
        putchar(c_in);
        ++cnt;
      }
      else ++cnt;
    }
  }
}
