#include <stdio.h>
#include <stdlib.h>
//#define ASIZE (sizeof(nums) / sizeof(int))

int compare_int(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;

    return arg1-arg2;
}
int main(int argc, char *argv[]) {
    int num_elements = 0;
    
    printf("Введите кол-во элементов массива:\n");
    scanf("%d",&num_elements);
    printf("Введите значения элементов массива:\n");
    int nums[num_elements]={};

/*---------------------------Заполняем массив 0-----------------------------------*/

    for (int i = 0; i < num_elements; i++)
    {
        nums[i]=0;
    }
    
/*---------------Заполняем массив введёными пользователем данными-----------------*/

    for(int i = 0; i < num_elements; ++i) {
    scanf("%d", &nums[i]);
    }

/*-----------------------Вывод несортированного массива---------------------------*/
    
    printf("Unsorted array\n");
    for (int i = 0; i < num_elements; ++i)
    {
        
        printf("%d ",nums[i]);
    }
/*---------------------------Сортировка массива-----------------------------------*/

    qsort(nums, num_elements,sizeof(int),compare_int);

/*-----------------------Вывод сортированного массива-----------------------------*/

    puts("");
    printf("\nSorted array\n");
    for (int i = 0; i < num_elements; ++i)
    {
        
        printf("%d ",nums[i]);
    }

/*--------Определение четности или нечетности кол-ва элементов массива------------*/

    puts("");
    int par_array = 0;
    if (num_elements % 2 != 0)
    {
        par_array = 1;// в массиве нечетное кол-во элементов
    }
    
    switch (par_array)
    {
    case 0:{
        /*Четное кол-во->берём среднее арифметическое двух средних элементов*/
        double mediana = (nums[num_elements / 2 - 1] + nums[num_elements / 2] / 2);
        printf("\nMediana = %.2f\n",mediana);        

    }
        break;
    
    case 1:{
        /*Нечетное кол-во->берём значение среднего элемента*/
        printf("\nMediana = %d\n",nums[(num_elements)/2]);
    }
    default:
        break;
    }

    return 0;
}