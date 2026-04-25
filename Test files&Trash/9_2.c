#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Функция сравнения для qsort*/
int compare_int(const void* p1, const void* p2) {
    int arg1 = *(const int*)p1;
    int arg2 = *(const int*)p2;

    return arg1-arg2;
}
/*---------------------------*/


/*Основная функция для работы с массивом*/
void find_array (int* const pn, size_t n_size, int *pn_max, int *pn_min, double *pn_mediana, double *pn_avg) {
    /*Проверка входных данных*/
    if (n_size>0) {
        
    }
    else
    {
        exit(1);
    }

    if (pn==NULL) {
        perror("out of memmory");
        exit(1);
    }

    if (pn_max == NULL || pn_min == NULL || pn_mediana == NULL || pn_avg == NULL) {
        printf ("Error input data");
        exit(1);
    }
    /*---------------------------------------*/
    /*Выделяем память и копируем туда массив*/
    int* array_copy = malloc(n_size * sizeof(int));
    memcpy(array_copy,pn,n_size*sizeof(int));
    /*--------------------------------------*/
    
/*Поиск min max*/
    *pn_min=array_copy[0];
    *pn_max=array_copy[0];
    for (int i = 0; i < n_size; i++){
    if (array_copy[i]<*pn_min)
        {
            *pn_min=array_copy[i];
        }
    if (array_copy[i]>*pn_max)
        {
            *pn_max=array_copy[i];
        }
    }
/*--------------------------------------*/

/*Поиск медианны*/
    qsort(array_copy, n_size, sizeof(int), compare_int);
    /*Определяем четное кол-во элементов в массиве или нет*/
    puts("");
    int par_array = 0;
    if (n_size % 2 != 0)
    {
        par_array = 1;// в массиве нечетное кол-во элементов
    }
    /*Ищем медианное значение*/
    switch (par_array)
    {
    case 0:{
        /*Четное кол-во->берём среднее арифметическое двух средних элементов*/
        *pn_mediana = (array_copy[n_size / 2 - 1] + array_copy[n_size / 2]) / 2.0;
    }
        break;
    
    case 1:{
        /*Нечетное кол-во->берём значение среднего элемента*/
        *pn_mediana=array_copy[(n_size)/2];
    }
    default:
        break;
    }
/*--------------------------------------------------*/

/*Рассчет среднего математического элементов массива*/
double summ = 0.0;
for (int i = 0; i < n_size; i++)
    {
        summ+=array_copy[i];
    }
*pn_avg=summ/n_size;    
/*----------------------------------------------------*/

/*!!!!!ОБЯЗАТЕЛЬНО!!!!!*/
/*Очищаем память и обнуляем указатель*/
free(array_copy);
array_copy=NULL;
/*-----------------------------------*/
}
/*------------------Конец основной функции------------------------*/


int main(int argc, char *argv[]) {
    
    int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17, 127};
    int n_max, n_min;
    double n_mediana, n_avg; 
    n_max=n_min = 0;
    n_mediana=n_avg = 0.0;
    int *pn_max = &n_max;
    int *pn_min = &n_min;
    double *pn_mediana = &n_mediana;
    double *pn_avg = &n_avg;
    int* const pn = n;
    
    size_t n_size = sizeof(n)/sizeof(int);

    find_array(pn,n_size,pn_max,pn_min,pn_mediana,pn_avg);

    printf("Array min = %d\n",*(pn_min));
    printf("Array max = %d\n",*(pn_max));
    printf("Array mediana = %.2lf\n",*(pn_mediana));
    printf("Array avg = %.2lf\n",*(pn_avg));    
    printf("Array\n");
    for (int i = 0; i < sizeof(n)/sizeof(int); i++)
    {
        printf("%d ",n[i]);
    }
    

    return 0;
}