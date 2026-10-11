/*
Write a program detab that replaces tabs in the input with the proper number 
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter? 
Answer: It should be a symbolic parameter because doesn't use memory and no change.
*/

#include <stdio.h>
#include <limits.h>
/* Symbolic parameters*/
#define TAB_N_SPACES  8 /* number of spaces for each TAB*/
#define MAXLINE    1000 /* maximum input line length */ 

/*Function prototype*/
int getlinedetab(char s[], int a);

main(){
  int len=0;
  int idx=0;
  char s[MAXLINE];
  if((len=getlinedetab(s,MAXLINE))>0)
    printf("%s",s); 
  else if (len<0)
    printf("String lenght has been overwhelmed");
  else 
    printf("No line input.");

  return 0;
}

/* getline:  read a line into s, return length  */ 
int getlinedetab(char s[],int lim) 
{ 
  /*Automatic variables*/
  int u, str_cnt, ret_val,diff,c;
  str_cnt=0;
  ret_val=0;
  diff=0; 
  while (str_cnt < INT_MAX && (c=getchar())!=EOF && c!='\n') {
    diff=TAB_N_SPACES-(str_cnt%TAB_N_SPACES);
    if(c=='\t') {
      for(u=0;u<diff;u++) s[str_cnt+u]=' ';
      str_cnt+=diff;
    }
    else {
      s[str_cnt] = c; /*When str character isn't \t.*/
      str_cnt++;
    }
  } 
  if (c == '\n') {  /*When enter key has pressed, add character.*/
    s[str_cnt] = c; 
    ++str_cnt; 
  } 
  s[str_cnt] = '\0'; /*Final string character*/

  if(str_cnt>lim) ret_val=-1;      /*If string size is greather than INT_MAX raise flag*/
  else            ret_val=str_cnt;
  return ret_val; 
}