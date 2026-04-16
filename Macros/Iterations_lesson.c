#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "S_C_MATH.h"
/*#define PI 3.1415
#define S_CIRCLE(a) ((PI*(r*r)))
#define C_CIRCLE(b) (((2*PI)*b))*/

int main() {
	float r = 0;
	printf("Введите радиус окружности:\n");
	scanf("%f", &r);
	float s = S_CIRCLE(r);
	float c = C_CIRCLE(r);
	printf("S = %f\nC = %f\n",s,c);
    
	return 0;
}