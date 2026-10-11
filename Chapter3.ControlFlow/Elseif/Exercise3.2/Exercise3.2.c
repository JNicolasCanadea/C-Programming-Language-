/*
Write a function escape(s,t) that converts characters like newline and tab 
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write 
a function for the other direction as well, converting escape sequences into the real characters.  
*/
#include <stdio.h>
#define MAX_SIZE 50
void escape(char t[MAX_SIZE], char s[MAX_SIZE]);
char t[MAX_SIZE],s[MAX_SIZE];
int c_in=0;
main(){
  int i=0;
  while((c_in=getchar())!=EOF && i<MAX_SIZE) {
    t[i++]=(char)c_in;
  }
  printf("Input text:%s",t);
  escape(t,s);
  printf("Escape text:%s",s);
}

void escape(char t[MAX_SIZE], char s[MAX_SIZE]){
  int idx_t=0;
  int idx_s=0;
  while(idx_t<MAX_SIZE){
    switch (t[idx_t])
    {
    case '\t': 
      s[idx_s++]='\\';
      s[idx_s++]='t';
      break;
    case '\n':
      s[idx_s++]='\\';
      s[idx_s++]='n';
      break;
    default: 
      s[idx_s++]=t[idx_t];
      break;
    }
    idx_t++;
  }
}