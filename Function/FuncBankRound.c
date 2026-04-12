#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Banc_round_func.h"
#include "Bank_round_func.c"

double bank_round (double x);

int main(int argc, char *argv[]) {
    
    /*printf("round %.1lf : %.1lf\n", 1.1, round(1.1));
    printf("round %.1lf : %.1lf\n", 1.9, round(1.9));
    printf("round %.1lf : %.1lf\n", 1.5, round(1.5));
    printf("round %.1lf : %.1lf\n", 2.5, round(2.5));
    
    printf("round %.1lf : %.1lf\n", -1.1, round(-1.1));
    printf("round %.1lf : %.1lf\n", -1.9, round(-1.9));
    printf("round %.1lf : %.1lf\n", -1.5, round(-1.5));
    printf("round %.1lf : %.1lf\n", -2.5, round(-2.5));

    printf("floor %.1lf : %.1lf\n", 1.9, floor(1.9));
    printf("ceil %.1lf : %.1lf\n", 1.1, ceil(1.1));
    
    printf("floor %.1lf : %.1lf\n", -1.9, floor(-1.9));
    printf("ceil %.1lf : %.1lf\n", -1.1, ceil(-1.1));

    double d = -1.5;
    printf("|d|=%f\n",fabs(d));*/
    
    bank_round(-11.7);
    
    return 0;


}