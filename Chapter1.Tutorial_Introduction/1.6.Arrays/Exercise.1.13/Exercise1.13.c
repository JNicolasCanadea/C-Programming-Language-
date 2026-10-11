/*
Write a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is 
more challenging.
*/
#include <stdio.h>

main(){
  int i,idx,c_in,lett_cnt[10],cnt,nother;

  /*Clear array called lett_cnt[10]*/
  for (i=0;i<(sizeof(lett_cnt)/sizeof(lett_cnt[0]));i++){
    lett_cnt[i]=0;
  }
  cnt=0;
  nother=0;
  idx=0;
  while((c_in=getchar())!=EOF){
    if((c_in>='A' && c_in<='Z')||(c_in>='a' && c_in<='z')){
      ++cnt;
    }
    else{
      if(cnt>0 && cnt<=(sizeof(lett_cnt)/sizeof(lett_cnt[0]))){
        ++lett_cnt[cnt-1];
        cnt=0;
      }
      else
        ++nother;
    }
  }
  printf("Word's lenght histogram:\n");
  for(i=0;i<(sizeof(lett_cnt)/sizeof(lett_cnt[0]));i++){
    printf("%d:",i+1);
    for(idx=0;idx<lett_cnt[i];idx++)
      printf("#");
    printf("\n");
  }
  printf("nother:");
  for(idx=0;idx<nother;idx++)
      printf("#");
  printf("\n");

}