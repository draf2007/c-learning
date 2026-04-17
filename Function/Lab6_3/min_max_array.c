#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int nums[]={2, 15, 17, 3, 21, 1000, 30, 34, 12};
    int min=nums[1];
    int max=nums[1];
        
    for (int i = 0; i < sizeof(nums)/ sizeof(int); i++)
    {
        if (nums[i]<min)
        {
            min=nums[i];
        }
        if (nums[i]>max)
        {
            max=nums[i];
        }
        
    }
    
    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
    return 0;
}