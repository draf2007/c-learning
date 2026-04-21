#include <stdio.h>
#include <stdlib.h>

//int globalZ = 20; // так делать нельзя не может быть двойной декларации надо использовать модификатор extern
extern int globalZ; // надо декларировать переменную вот так, мы говорим что переменная внешняя по отношению к этому модулю
void print_global_var(){
    printf("call to function print_global_var() module.c globalZ = %d\n", globalZ);
}

// int moduleGlobal=5; // moduleGlobal время жизни - глобально*/
                       // moduleGlobal область видимости - глобально*/
                       // так делать нельзя потому что в другом модуле может быть создана такая же переменная или
                       // её поменяют в другом модуле

static int moduleGlobal=50;  // надо объявлять вот так
                       // тогда область видимости moduleGlobal будет ограничена текущим модулем
                       // но
                       //moduleGlobal время жизни - глобально
                       //moduleGlobal область видимости - локально
int addValue(int k){
    int m = k + moduleGlobal;
    return m;
}

int minusValue(int k){
    int m = k - moduleGlobal;
    return m;
}