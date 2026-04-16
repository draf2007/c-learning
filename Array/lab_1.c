#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;

    return arg1-arg2;
}

int main(int argc, char *argv[]) {
    int accum_nums=0;
    int n[]={10,15,7,3,21,1000,18,30,14,17};

    printf("Unsorted massive\n");
    for (int i = 0; i < (sizeof(n)/sizeof(int)); ++i)
    {
        printf("%d ", n[i]);
     
    }

    qsort(n, (sizeof(n)/sizeof(int)), sizeof(int), compare_int);

    printf("\nSorted massive\n");
    for (int i = 0; i < (sizeof(n)/sizeof(int)); ++i)
    {
        printf("%d ", n[i]);
        accum_nums++;

    }
    
    if (accum_nums % 2 == 0)
    {
        int el_1 = accum_nums / 2;
        int el_2 = el_1-1;
        int mediana = (n[el_1]+n[el_2])/2;
        printf ("\nMediana %d", mediana);
    }
    else {
        int el_1 = accum_nums / 2;
        
        printf("\n%d", n[el_1]);
    }
    

    return 0;
}