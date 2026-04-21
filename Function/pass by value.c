#include <stdio.h>
#include <stdlib.h>

int pass_by_value (int v) {
    v++;
    return v;
}

int main(int argc, char *argv[]) {
    int x = 5;
    printf("До передачи в функцию x = %d\n",x);
    x = pass_by_value(x); // возврат значения из функции возможен через какое то действие, напрмер присваивание
    printf("После передачи в функциюx = %d",x);
    return 0;
}