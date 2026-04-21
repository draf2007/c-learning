#include <stdio.h>
#include <stdlib.h>

int swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    (*ptr2)=temp;
    
    return *ptr1, *ptr2; 
}

int main(int argc, char *argv[]) {
    int x=5,y=10;
    printf("%d\n %d\n",swap(&x,&y));
    return 0;
}