/*
Write a program entab that replaces strings of blanks by the minimum 
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which should be given 
preference? 
*/

#include <stdio.h>
#include <limits.h>
/* Symbolic parameters*/
#define TAB_N_SPACES  8 /* number of spaces for each TAB*/
#define MAXLINE    1000 /* maximum input line length */ 
// Global variables
int str_idx_w = 0;

/*Function prototype*/
int getline_entab(char s[], int a);

main(){
  int len=0;
  int idx=0;
  char s[MAXLINE];
  if((len=getline_entab(s,MAXLINE))>0){
    printf("%s",s);
    printf("Original lenght string is:%d\n",len);
    printf("Detab lenght string is:%d\n",str_idx_w);
  } 
  else if (len<0)
    printf("String lenght has been overwhelmed");
  else 
    printf("No line input.");
  return 0;
}

/* getline:  read a line into s, return length  */ 
int getline_entab(char s[],int lim) 
{ 
  /*Automatic variables*/
  int u, str_idx_c, ret_val,diff,c,blk_cnt,diff_stored;
  str_idx_c = 0;
  ret_val = 0;
  diff = 0;
  blk_cnt = 0;
  diff_stored = 0; 
  while (str_idx_c < INT_MAX && (c=getchar())!=EOF && c!='\n') {
    diff=TAB_N_SPACES-(str_idx_c%TAB_N_SPACES);
    str_idx_c++;
    if(c == ' ') {
      blk_cnt++;
      if(blk_cnt==1) diff_stored=diff;
      if((blk_cnt == diff_stored) && blk_cnt>1){
        s[str_idx_w++] = '\t';
        blk_cnt = 0;
        diff_stored = 0;
      }
    }
    else {
      if(blk_cnt>=1) 
        for(u=str_idx_w;u<str_idx_w+blk_cnt;u++)
        s[u]=' ';
        str_idx_w+=blk_cnt;
      s[str_idx_w++] = c; /*When str character isn't \t.*/
      blk_cnt = 0;
      diff_stored = 0;
    }
  }

  if (c == '\n')   /*When enter key has pressed, add character.*/
    s[str_idx_w++] = c;  

  s[str_idx_w] = '\0'; /*Final string character*/

  if(str_idx_c>lim) ret_val = -1;      /*If string size is greather than INT_MAX raise flag*/
  else              ret_val = str_idx_c;
  return ret_val; 
}