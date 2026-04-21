#include <stdio.h>
#include <stdlib.h>
#define ASIZE (sizeof(n) / sizeof(int))

int compare_int(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;
    return arg1-arg2;
}

int main(int argc, char *argv[]) {
    
    int n [] = {18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
    int new_arr [ASIZE]={0};
    int new_arr_count = 0;
    qsort(n, sizeof(n)/sizeof(int),sizeof(int),compare_int);

    new_arr[new_arr_count] = n[0];
    new_arr_count++;
    for (int i = 1; i < ASIZE; i++) {
        if (n[i] != n[i - 1]) {
            new_arr[new_arr_count] = n[i];
            new_arr_count++;
        }
    }

    
    for (int i = 0; i < ASIZE; i++)
    {
        printf("%d ",n[i]);
    }
    puts("");
    for (int i = 0; i < new_arr_count; i++)
    {
        printf("%d ",new_arr[i]);
    }
    

    puts("");
    printf("%d", new_arr_count);
    return 0;
}