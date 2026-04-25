#include <stdio.h>
#include <stdlib.h>
int varian_qsort(int arg1,int arg2) {
    int oe_arg1 = arg1;
    int oe_arg2 = arg2;
    int even_odd_arg1=0;
    int even_odd_arg2=0;
    int variant = 0;
    
    if (oe_arg1 % 2 == 0)
    {
        even_odd_arg1 = 1;
    }
    if (oe_arg2 % 2 == 0)
    {
        even_odd_arg2 = 1;
    }

    if (even_odd_arg1 == 0 && even_odd_arg2 == 0)
    {
        variant = 1;
    }
    
    if (even_odd_arg1 == 1 && even_odd_arg2 == 0)
    {
        variant = 2;
    }
    
    if (even_odd_arg1 == 1 && even_odd_arg2 == 1)
    {
        variant = 3;
    }
    
    if (even_odd_arg1 == 0 && even_odd_arg2 == 1)
    {
        variant = 4;
    }
    return variant;

}

int comparator(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;
    int variant = varian_qsort(arg1,arg2);
    switch (variant)
    {
    case 1: if (arg1>arg2) return -1;
            if (arg1<arg2) return 1;
            return 0;
            break;
    case 2: return -1;
            
    case 3: if (arg1<arg2) return -1;
            if (arg1>arg2) return 1;
            return 0;
            break;
    case 4: return 1;
    
    default:
        break;
    }


}

int main(int argc, char *argv[]) {
    
    int l_array = 0;

    printf("Введите размер массива\n");
    scanf("%d",&l_array);
    if (l_array<=0)
    {
        printf("Размер массива должен быть больше 0!");
        exit(1);
    }

    int array[l_array];
    for (int i = 0; i < l_array; i++)
    {
        array[i]=0;
    }
    
    printf("Введите элементы массива\n");
    for (int i = 0; i < l_array; i++)
    {
        printf("[%d/%d>]",i,l_array);
        scanf("%d",&array[i]);
    }

    qsort(array, sizeof(array)/sizeof(int),sizeof(int),comparator);
    
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ",array[i]);
    }
    

    return 0;
}