/*
Our binary search makes two tests inside the loop, when one would suffice (at 
the price of more tests outside.) Write a version with only one test inside the loop and 
measure the difference in run-time. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50
#define MAX_LIMIT 100
#define MIN_LIMIT 0
// Function declarations-----------
int binsearch (int x,int v[],int n);
int binsearch2(int x,int v[],int n);
void sort(int arr[],int size);
int get_0_99(void);
// Global variables----------------
int v[ARRAY_SIZE];

main(){
  int rand_num;
  int c_in=0;
  int idx=0;
  int in_num=0;
  long clocks;
  int iterations = 100000; // 1 millón de veces

  for(int i=0;i<ARRAY_SIZE;i++) {
    //while((rand_num=rand()) >= MIN_LIMIT) {
    //  v[i]=rand_num%MAX_LIMIT;
    //  break;
    //}
    v[i]=i;
  }
  for(int i=0;i<ARRAY_SIZE;i++) printf("|%d",v[i]);
  sort(v,ARRAY_SIZE);
  printf("\n");
  printf("Array sorted:\n");
  for(int i=0;i<ARRAY_SIZE;i++) printf("|%d",v[i]);
  printf("\n");
  printf("Enter a number from 0 to 99:");
  in_num=get_0_99();
  if(in_num>=0) printf("The input number is:%d\n",in_num);
  else          printf("Wrong input, out of range 0-99!\n");
  clocks = clock();
  for (int i = 0; i < iterations; i++) {
      idx=binsearch_kr(in_num,v,ARRAY_SIZE); 
    }
  clocks = clock();
  printf("The index is:%d and value v[%d]=%d \n",idx,idx,v[idx]);
  printf("%lu clocks binsearch_kr (%.4f seconds) \n", clocks,(double)clocks/CLOCKS_PER_SEC);

  clocks = clock();
  for (int i = 0; i < iterations; i++) {
      idx=binsearch(in_num,v,ARRAY_SIZE); 
    }
  clocks = clock();
  printf("The index is:%d and value v[%d]=%d \n",idx,idx,v[idx]);
  printf("%lu clocks binsearch (%.4f seconds) \n", clocks,(double)clocks/CLOCKS_PER_SEC);
  
}

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int binsearch_kr(int x, int v[], int n) 
{ 
  int low, high, mid; 
  low = 0; 
  high = n - 1; 
  while (low <= high) { 
    mid = (low+high)/2; 
    if (x < v[mid]) 
      high = mid-1; 
    else if (x  > v[mid]) 
      low = mid+1; 
    else    /* found match */ 
      return mid;
  } 
  return -1;   /* no match */ 
}

/* binsearch2:  find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int binsearch(int x, int v[], int n) 
{ 
  int low, high, mid; 
  low = 0; 
  high = n - 1;
  while (low<=high) {
    mid = (low+high)/2;   
    if (x<v[mid]) 
      high = mid-1;
    else 
      low  = mid;
  }
  if((x==v[low-1])) return (low-1);
  return -1;   /* no match */ 
}

/*Sort an int array elements in increasing order*/
void sort(int arr[],int size) {
  int temp=0;
  for(int u=0;u<size-1;u++) {
    for(int j=0;j<size-u-1;j++) {
      if(arr[j]>arr[j+1]) {
        temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
};

/*Get a number from 0 to 99*/
int get_0_99(void){
  int number_digits=0;
  int c_in=0;
  int num=0;
  const int TWO_DIGITS=2;
  while((c_in=getchar())!=EOF && c_in!='\n' && c_in!=' '){
    if(c_in>='0' && c_in<='9' && number_digits<=TWO_DIGITS){
      number_digits++;
      num=num*10+(c_in-'0');
    }
  }
  if(num>=0 && num<=99) return num;
  else                  return -1;
}