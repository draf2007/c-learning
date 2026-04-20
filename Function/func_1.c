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
    int n [] = {18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
    say_hello();
    hello_name("draf2007");
    hello_name_age("draf2007", 25);
    double avg = my_average(10, 11);
    printf("avg = %f\n",avg);
    printf("avg = %f\n",my_average(10,11));
    printf("func_average_n %.2f\n", average_n(16, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12));    
    return 0;
}