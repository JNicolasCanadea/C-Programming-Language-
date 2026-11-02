/*
Define a macro swap(t,x,y) that interchanges two arguments of type t.
*/
#include <stdio.h>
#define swap(t,x,y) { \
    t tmp_ = x;       \
    x = y;            \
    y = tmp_;         \
}

main() {
    int a = 5, b = 10;
    printf("Variables before swap a=%d y b=%d \n",a,b);
    swap(int,a,b);
    printf("Variables after swap a=%d y b=%d \n",a,b);
}