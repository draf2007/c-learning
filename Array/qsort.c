#include <stdio.h>
#include <stdlib.h>
/*Функция сравнения для qsort*/
int compare_int(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;
/*Функция должна возвращать положительное значение если arg1 > arg2*/
/*Функция должна возвращать отрицательное значение если arg1 < arg2*/
/*Функция должна возвращать 0 если arg1 = arg2*/
    /*if (arg1 > arg2) return 1;
    if (arg1 < arg2) return -1;
    if (arg1 == arg2) return 0;*/
/*Можно использовать такое выражение
порядок операндов определяет направление сортировки*/
    return arg1-arg2;
/*по убыванию
    return arg2-arg1;*/
/*по возрастанию
    return arg1-arg2;*/
    

}

int main(int argc, char *argv[]) {
    int nums[]={2, 15, 17, 3, 21, 1000, 30, 34, 12};

    /*шаблон qsort(массив для сортировки, кол-во элементов массива, размер элемента массива в байтах,функция сравнения)*/
    qsort(nums, sizeof(nums)/sizeof(int),sizeof(int),compare_int);

    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i)
    {
        printf("%d ",nums[i]);
    }

    return 0;
}