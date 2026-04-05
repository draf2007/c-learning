#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    #define ASIZE 3
    //int nums[3];
    int nums[ASIZE] = {100, 200, 300};
    //int nums[3] = {100, 200};
    //int nums[3] = {}; // Заполнение 0
    //nums[0] = 100;
    //nums[1] = 103;
    //nums[0] = 104;
    /*printf("nums[0]= %d\n", nums[0]);
    printf("nums[1]= %d\n", nums[1]);
    printf("nums[2]= %d\n", nums[2]);*/

    for (int i = 0; i < ASIZE; ++i)
    {
        printf("nums[%d]= %d\n", i, nums[i]);
    }
    

    return 0;
}