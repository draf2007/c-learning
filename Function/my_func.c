#include <stdio.h>

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