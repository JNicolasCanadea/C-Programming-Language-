/*
  Write a function expand(s1,s2) that expands shorthand notations like a-z in 
  the string s1 into the equivalent complete list abc...xyz in s2. Allow for 
  letters of either case and digits, and be prepared to handle cases like a-b-c 
  and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.  
*/
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
// Function prototypes:
void expand(char s1[MAX_SIZE],char s2[MAX_SIZE]);
char s1[MAX_SIZE];
char s2[MAX_SIZE];
main(){
   for(int idx=0;idx<MAX_SIZE;idx++) {
    s1[idx]='\0',s2[idx]='\0';
  }
  printf("Write a string: ");
  scanf("%[^\n]",s1);
  printf("\n"),printf("You've written : %s \n",s1);
  expand(s1,s2);
  printf("Expanded s2 string is : %s ",s2);
}


void expand(char s1[MAX_SIZE],char s2[MAX_SIZE]){
  int offset=0;
  int tmp=0;
  printf("strlen=%d\n",(int)strlen(s1));
  for(int i=0;i<(int)strlen(s1);i++){
    if(s1[i]=='-'){
      printf("s1[i]=%c into loop s1[i-1]=%d , s1[i+1]=%d \n",s1[i],s1[i-1],s1[i+1]);
      if(!((s1[i-1]<=47) || (58<=s1[i-1] && s1[i-1]<=96) || (s1[i-1]>=123)) && !((s1[i+1]<=47) || (58<=s1[i+1] && s1[i+1]<=96) || (s1[i+1]>=123))){
        printf("s1[i-1]=%c \n",s1[i-1]);
        for(int u=0;u<s1[i+1]-s1[i-1]-1;u++) {s2[i+u+offset]=s1[i-1]+(char)(u+1);
        printf("s2[%d]=%c\n",i+u,s2[i+u]);}
        offset+=s1[i+1]-s1[i-1]-2;
      }
      else s2[i+offset]=s1[i];
    }
    else {s2[i+offset]=s1[i],printf("s1[%d]=%c, s2[%d]=%c\n",i,s1[i],i+offset,s2[offset+i]);}
  }
}