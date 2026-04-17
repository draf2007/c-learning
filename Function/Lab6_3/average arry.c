#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int nums[]={18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
    int summa = 0;
    
    for (int i = 0; i < sizeof(nums)/ sizeof(int); i++)
    {
        summa += nums[i];
    }
    double avr = (double) summa/(sizeof(nums)/sizeof(int));

    printf("Summa = %d\n",summa);
    printf("Average = %.2lf\n",avr);
    return 0;
}