#include <stdio.h>
#include <stdarg.h>

/*Декларация (объявление) функции*/
void say_hello() {
    puts("Hello!");
}

void hello_name(const char* name) {
    printf("Hello, %s!\n",name);
}

void hello_name_age(const char* name, int age) {
    printf("Hello, %s - %d\n",name,age);
}

/*void average_m(int  m_size, int m[]) {
    long long summa = 0;
    for (int i = 0; i < m_size; ++i)
    {
        summa += m[i];
        
    }
    return (double)summa / m_size;
}*/

double average_n(int n,...) {
    long long summa = 0;

    va_list params;
    va_start(params,n);

    for (int i = 0; i < n; i++)
    {
        int k = va_arg(params,int);
        summa +=k;
    }
    va_end(params);

    return (double)summa / n;
}