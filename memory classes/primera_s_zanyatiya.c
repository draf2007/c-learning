#include <stdio.h>
#include <stdlib.h>
#include "module.h"
//#include "module.c"

/*время жизни globalZ до конца работы программы и видна во всём теле программы*/
int globalZ = 50; // размещается в сегменте данных (data segment), доступна как в main так и в функциях
/*------------Функция печати globalZ----------------*/
void print_global_var_this_file(){
    printf("call to function print_global_var_this_file() this file globalZ = %d\n", globalZ);
}
/*--------------------------------------------------*/

/*--------------------------------------------------*/
int add_to_register(register int a, register int b){   // модификатор register можно использовать в передаваемых функии парамтрах
    return a+b;                                        // если функия простая, как в данном случае это экономит место на стеке, 
                                                       // так как туда не копируются значения переменных, и ускоряет работу функции и программы в целом
}                                                      // так как регистровый сегмент памяти быстрый, но пропадает возможность работать с адресом переменных.
/*--------------------------------------------------*/ 
int main(int argc, char *argv[]) {

    auto double pi = 3.1415; // модифкатор auto - выделенеие памяти под переменную на стеке (для локальных переменных класс памят по умолчаню)
    //int x = 5; // auto без указаня это тип int по умолчанию (размещаетя на стеке)

    register int y = 10; // команда на размещене переменной в сегменте регистров, 
                         // но в современном стандарте модифкатор register это рекомендация компилятору разместить переменную в максимально быстрой памяти
                         // у переменной размещенной в регистровой памяти невозможно взять адрес
                         // т.е. следующий код вызовет ошибку
                         // register int y = 10;
                         // int* py = &y;

    int summ = add_to_register(1, 2);
    printf("print a+b=%d\n",summ);

    print_global_var_this_file();//вызов функции печати глобальной переменной globalZ из функции print_global_var() расположенной в текущем файле

    print_global_var(); //вызов функции print_global_var() печатающей глобальную переменную globalZ из модуля module.c 

    printf("call to function main(). Print globalZ = %d\n", globalZ); //вызов глобальной переменной globalZ из main

    printf("addValue moduleGlobal = %d\n",addValue(2));
    printf("minusValue moduleGlobal = %d\n",minusValue(69));
    //printf("%d\n",moduleGlobal); // не сработает moduleGlobal statatic в module.c
    return 0;
}