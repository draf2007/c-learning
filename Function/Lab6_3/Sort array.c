#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int nums[]={2, 15, 17, 3, 21, 1000, 30, 34, 12};

    //bubble sort
    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i)
    {
        printf("%d ",nums[i]);
    }

    puts("\n--------------------------");
    
    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i)
    {
        for (int j = i+1; j < sizeof(nums)/sizeof(int); ++j)
        {
            if (nums[i]>nums[j])
            {
                int buff = nums[i];
                nums[i]=nums[j];
                nums[j]=buff;
            }
            
        }
        
    }
    
    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i)
    {
        printf("%d ",nums[i]);
    }
    

    return 0;
}