/*
Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2.
*/
#include <stdio.h>
#include <limits.h>
// Symbolic variables------------
#define STR_MAX 10
// String definitions------------
char s1[STR_MAX],s2[STR_MAX];
// Function prototypes-----------
int getstr(char s[],int lim);
int squeeze(char s1[],char s2[]);

main(){
  printf("Write a first string s1:\n");
  getstr(s1,STR_MAX);
  printf("Write a second string s2:\n");
  getstr(s2,STR_MAX);
  printf("Squeeze function applied:\n");
  squeeze(s1,s2);
}
/* Squeeze strings*/
int squeeze(char s1[],char s2[]){
  int i1,i2,i3;
  for(i1=0;i1<((sizeof(s1)/sizeof(s1[0]))-1);i1++){
    for(i2=0;i2<((sizeof(s2)/sizeof(s2[0]))-1);i2++){
      if(s2[i2]==s1[i1]){
        for(i3=i1;i3<((sizeof(s1)/sizeof(s1[0]))-1);i3++)
          s1[i3]=s1[i3+1];
      }
    }
  }
  printf("String s1 is:%s",s1);
  return 0;
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
