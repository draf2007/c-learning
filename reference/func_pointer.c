#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Передача функции как параметра в другой функции
простой пример пример функция Qsort которая пользуется данными возвращаемыми внешней функцией сравнения для принятия решения переставлять элементы местами или нет

qsort(nums, sizeof(nums)/sizeof(int),sizeof(int),compare_int);

compare_int в примере и есть внешняя функция сравненеия, переданная в qsort как параметр
---------------------------------------------------*/

/*Общий пример создания типа указателя на функцию
<тип данных возвращаемый по указателю> (*имя создаваемой переменной типа указатель на функцию)(имя функции на которую будет указывать создаваямая переменная типа указатель)
                int                             (*f_poiner)                                                           (int function);

в результате получаем 
int (*f_pointer)(int function);
но так мы создали тоько переменную указатель на функцию int function(), 
но пользоваться её нельзя она не содержит адрес по которому находится фукнкция int function(),
далее в эту переменную указатель надо положить адрес функции int function(), делается это простым присваиванием
f_pointer = &function;
или
f_pointer = function;
получаем шаблон создания переменной типа указатель на функцию с передачей в неё адреса функции
int (*f_pointer)(int function);
f_pointer = &function;
Для чего всё это используется:
можно на например не вызвать функию через это указатель
int y = f_pointer(); прямой вызов функйии через указатель 
int y = (*f_pointer)(); вызов функции через разыменование указателя на нее.
Что это нам даёт в результате? Мы можем передать указатель на функцию другой функции (отдалённо напоминает вложенные циклы)

можно так же создать псевдоним типа указателя при помощи typedef
Берём заголовок функции которую хоти предавать в тип указатель
double x2(double x)
вместо имени пишем новое имя но со *
double (*MathFunction)(double x);
и теперь имя MathFunction можно использовать как обычный тип
и теперь в заголовке функции где я указываю параметры для передачи функции можно использовать MathFunction с указанием имени параметра
double integral (MathFunction pointerToFunc, double lower, double upper){

    double w = (upper-lower)/STEPS;
    double summa = 0.0;
    for (int i = 0; i < STEPS; i++)
    {
        double x = lower + w * i + w / 2.0;
        double h = pointerToFunc(x);
        summa+= h * w;
    }
    
    return summa;
    
}

----------------------------------------------------*/
/*!!!ВАЖНО!!!*/
/*!!!ПО УКАЗАТЕЛЮ МОЖНО ПЕРЕДАВАТЬ ФУНКЦИИ ВОЗВРАЩАЮЩИЕ ОДИН И ТОТ ЖЕ ТИП ДАННЫХ, ЧТО И В ПЕРЕМЕННОЙ УКАЗАТЕЛЕ НА ФУНКЦИЮ!!!*/
/*Т.е. int (*f_pointer)(int function);
function() в результате выполнения должна возвращать данные типа int*/
/*внешние функции которые хотим передавать как параметр*/
typedef double (*MathFunction)(double x);
#define STEPS 1000000

double x2(double x) {
    return x*x;
}
/*---------------------------------------------------*/
/*Функция вычисления интеграла
В таком виде функция  вычисляет интеграл от sin(x)
но можно сделать её универсальной предавая ей третьим параметром указатель на функцию из math.h (sin,cos... и т.д.)
double integral (double lower, double upper){

    double w = (upper-lower)/STEPS;
    double summa = 0.0;
    for (int i = 0; i < STEPS; i++)
    {
        double x = lower + w * i + w / 2.0;
        double h = sin(x);
        summa+= h * w;
    }
    
    return summa;
    
}*/
/*Теперь добавил третий параметр передаваемый функции рассчета интеграла.
в заголовке мы создали переменную указатель на функцию которую мы передадим привызове функции integral в теле main,
а саму переменную указатель на функцию(я же её передал при вызове) буду изпользовать в теле функции integral() для дальнейших рассчётов*/
double integral (double (*pointerToFunc)(double x), double lower, double upper){

    double w = (upper-lower)/STEPS;
    double summa = 0.0;
    for (int i = 0; i < STEPS; i++)
    {
        double x = lower + w * i + w / 2.0;
        double h = pointerToFunc(x);
        summa+= h * w;
    }
    
    return summa;
    
}


int main(int argc, char *argv[]) {
    
    double (*pf)(double x2); // создаём указатель на функцию
    pf = &x2;// || x2 

    double y = (*pf)(10);
    //double y = pf(3);
    
    double r1 = integral(&sin, 0.0, (M_PI/2));
    printf("integral sin = %.14lf\n", r1);
    double r2 = integral(&cos, 0.0, (M_PI/2));
    printf("integral  cos = %.14lf\n", r2);
    /*Интеграл X^2, рассчет x^2 делается в функции x2() которая находится выше*/
    double r3 = integral(&x2, 0.0, 1);
    printf("integral  x^2 = %.14lf\n", r3);

    printf("%.4lf\n",y);
    

    return 0;
}