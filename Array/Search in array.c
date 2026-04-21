#include <stdio.h>
#include <stdlib.h>
#define PRINT_INTS {for (int i = 0; i < (sizeof(nums)/ sizeof(int)); ++i) printf("%d ",nums[i]);}

int main(int argc, char *argv[]) {
    
    int nums[]={18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
    //PRINT_INTS(nums);
    int search = 1000;
    int found_index = -1;

    for (int i = 0; i < sizeof(nums)/ sizeof(int); ++i)
    {
        if (nums[i]==search)
        {
            found_index=i;
            break;
        } 
    }
if (found_index != -1)
    {
        printf("Value %d found in position %d\n", search, found_index);
    }
    else
    {
        printf("Value %d not found\n",search);
    }
        
return 0;
}