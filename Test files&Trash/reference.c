
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a,b;
    a=10;
    b=15;
    int *ptr;
    ptr = &a;
    printf("addr ptr = %p value ptr = %d",ptr,*ptr);
    return 0;
}