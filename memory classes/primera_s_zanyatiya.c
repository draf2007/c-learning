#include <stdio.h>
#include <stdlib.h>
#include "module.h"
#include "module.c"

int visitCouter() { // 
                                //
    static int vCounter;        //статическая локальная переменная видна только в функции, но время жизни у неё глобальное
    vCounter++;                 //поэтому вызов её в main будет добавлять к ней +1 и сохраняться она хранится в сегменте данных 
    return vCounter;            //поэтому она не уничтожается после вызова функции и сохраняет значение при каждом вызове в данном случае 
                                //при первом вызове vCounter=1, при втором vCounter = 1+1 = 2, при третьем vCounter = 1+1+1 = 3 и так далее

}

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
    
    
    printf("Visit Counter = %d\n",visitCouter());
    printf("Visit Counter = %d\n",visitCouter());
    printf("Visit Counter = %d\n",visitCouter()); 
    

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


    const double var_pi = 3.1415;       //пример работы с константными переменными, для компилятора они read-only,и напрямую их поменять нельзя
    //var_pi=3.25;
    printf("var_pi = %fl\n",var_pi);    
    double *ppi = &var_pi;              //но если взять адрес такой переменной, и поместить его в указатель 
    (*ppi) = 4.000;                     //потом перейдти по аресу указателя и присвоить другое значение `более подробный вид (double* ppi = (double*)&pi) тут мы приводим const double* -> double*
    printf("var_pi = %fl\n",var_pi);    //то значение константной переменной измениться, именно по этому их называют константной переменной, она защищена от
                                        //смены значения напрямую
    


    return 0;

}