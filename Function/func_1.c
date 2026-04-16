#include <stdio.h>
#include <stdlib.h>
#include "my_func.c"
#include "my_func.h"

double my_average (int a, int b){
    double r = (a + b)/2.0;
    return(r); /*|| return (a + b)/2.0;*/
}

int main(int argc, char *argv[]) {
    /*Вызов функци*/
    say_hello();
    hello_name("draf2007");
    hello_name_age("draf2007", 25);
    double avg = my_average(10, 11);
    printf("avg = %f\n",avg);
    printf("avg = %f\n",my_average(10,11));
    return 0;
}