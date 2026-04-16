#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double bank_round (double x)
{

    long num = (long)x;
    double fPart = x-num;
    if (num % 2 == 0 && fPart >= 0.5)
    {
        printf("round to up %.2lf\n", floor(x));
    }
    else if (num % 2 != 0 && fPart >= 0.5)
    {
        printf("round to up %.2lf\n", ceil(x));
    }
    else
    {
        printf("round to down %.2lf\n", ceil(x));
    }
    /*printf("%ld\n",num);
    printf("%lf\n",fPart);*/

}