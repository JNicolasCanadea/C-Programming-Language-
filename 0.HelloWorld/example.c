#include <stdio.h>

float test1()
{
  int x = 3;
  int y = 0;  
  return x + y;  
}

float test2()
{
  int x = 3;
  int y = 1;
  return x / y;
}

float test3()
{
  int x = 3;
  int y = 0;
  return x * y;
}

int main() {
  printf("Test 1 = %.1f\n",test1());
  printf("Test 2 = %.1f\n",test2());
  printf("Test 3 = %.1f\n",test3());
}
