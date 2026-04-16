#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;
    return arg1 - arg2;
}

int main(void) {
    int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17};
    int f = 21;
    int arr_len = sizeof(n) / sizeof(n[0]);

    
    qsort(n, arr_len, sizeof(int), compare_int);

    printf("\nSorted array:\n");
    for (int i = 0; i < arr_len; ++i) {
        printf("%d ", n[i]);
    }

    
    int left = 0;
    int right = arr_len - 1;
    int found_idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (n[mid] == f) {
            found_idx = mid;
            break; // 
        } else if (f < n[mid]) {
            right = mid - 1; 
        } else {
            left = mid + 1;  
        }
    }

    if (found_idx != -1) {
        printf("\n%d найден по индексу %d\n", f, found_idx);
    } else {
        printf("\n%d не найден\n", f);
    }

    return 0;
}