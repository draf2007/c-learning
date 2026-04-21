#include <stdio.h>
#include <stdlib.h>

void swap(int **pptr1, int **pptr2) {
    int *temp = *pptr1;
    *pptr1 = *pptr2;
    *pptr2=temp;
    
    //return *ptr1, *ptr2; 
}

int main(int argc, char *argv[]) {
    int x=5,y=10;
    int *ptr1 = &x;
    int *ptr2 = &y;
    printf("x = %d y = %d\n",x,y);
    printf("ptr1 = %d ptr2 = %d\n",*ptr1,*ptr2);
    swap(&ptr1,&ptr2);
    printf("x = %d y = %d\n",x,y);
    printf("ptr1 = %d ptr2 = %d\n",*ptr1,*ptr2);
    return 0;
}