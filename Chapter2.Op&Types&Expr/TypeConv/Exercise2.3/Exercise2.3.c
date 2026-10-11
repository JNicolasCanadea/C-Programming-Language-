/*
Write a function htoi(s), which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A through F. 
*/
#include <stdio.h>
#include <limits.h>
#define MAX_LINE 10
char s[MAX_LINE];
char c='0';
/*------Function custom------*/
int fillstr(char s[],int lim,char c);
int htoi(char s[]);
main(){
//while(c!=EOF){
  fillstr(s,MAX_LINE,c);
  printf("THe input is %s and his int equivalent is:%d\n",s,htoi(s));
//}
}
/*Fill string input.*/
int fillstr(char s[],int lim,char c){
  int i,val;
  val=0;
  printf("Hi! Write an hex number of 7 digits {e.g:0x(or X)+value[h0h1..h6]} and next press Enter key:");
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

/*Hexa string to int convertion.*/
int htoi(char s[]){
  int u;
  int val=0;
  printf("Converter hexadecimal running...\n");
  for(u=0;u<MAX_LINE;++u){
    if(u==0) {
      if(s[u]!='0') {
        printf("The first character must be '0'\n");
        val=-1;
        break;
      }     
    }
    else if (u==1) {
      if(s[u]!='x' && s[u]!='X') {
        printf("The second character must be 'x' or 'X'\n");
        val=-1;
        break;
      }
    }
    else if (u>=2 && s[u]!='\0')
      val=16*val+(s[u]-'0');
    else
    ;
  }
  return val;
}

