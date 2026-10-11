/*
Write the function any(s1,s2), which returns the first location in a string s1 
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
(The standard library function strpbrk does the same job but returns a pointer to the 
location.) 
*/
#include <stdio.h>
#include <limits.h>
// Symbolic variables------------
#define STR_MAX 10
// String definitions------------
char s1[STR_MAX],s2[STR_MAX];
// Function prototypes-----------
int getstr(char s[],int lim);
int any(char s1[],char s2[]);

main(){
  getstr(s1,STR_MAX);
  getstr(s2,STR_MAX);
  if(any(s1,s2)>=0)printf("The first character matched in s2 by s1 has index:%d\n",any(s1,s2));
  else             printf("None character is matched between s1 and s2\n");
}
/* Squeeze strings*/
int any(char s1[],char s2[]){
  int i1,i2,i3;
  for(i1=0;i1<(sizeof(s1)-1);i1++){
    for(i2=0;i2<(sizeof(s2)-1);i2++){
      if(s2[i2]==s1[i1]) 
        break;
    }
    if(s2[i2]==s1[i1]) 
      break;
  }
  return i1;
}
/*Fill string input.*/
int getstr(char s[],int lim){
  int i,val;
  char c;
  val=0;
  printf("Hi! Write an string from up to 9 ASCIIs and press Enter key:");
  for(i=0;i<INT_MAX;i++) {
    c=getchar();
    if(i<lim-1) {
      if(c=='\n') {
        s[i]='\0';
        printf("The string was succesful uploaded.\n");
        val=1;
        break;
      }
      else 
        s[i]=c;
    }
    else if(i==lim-1) {
      if(c!='\n') {
        printf("The string size is overloaded.\n");
        val=-1;
        break;
      }
      else {
        printf("The string was succesful uploaded.\n");
        val=1;
        break;
      }
      s[i]='\0';
    }
  }
  return val;
}
