#include <stdio.h>
#include <stdlib.h>


/*создаем шаблон структуры*/
typedef struct {
    int x;
    int y;
}point;
/*Передача структуры в функцию по имени*/
/*Функция получает имя структуры, создаёт копию структуры на стеке меняет значение x в КОПИИ структуры, основная структура остаётся неизменной!!!*/
void draw(point p){
    p.x += 1;
    printf("Pass to value\nCopy p1 x = %d\n",p.x);
}
/*Передача структуры в функцию по указателю*/
/*Функция получает указатель на структуру, основная структура изменяется!!! Так как работаем с указателем на фдрес ячейки памяти оригинальной структуры*/
void draw_p(point *ptr){
    ptr->x = 15;
}

/*Передача структуры в функцию по указателю только для чтения с защитой от записи*/
/*Функция получает указатель на структуру, основная структура неизменяется!!! Защита от записи обеспечивается const*/
void draw_const(const point *p){
    printf("\nConst pointer only read\nx = %d  y = %d",p->x,p->y);
}

int main(int argc, char *argv[]) {
    
    point p1 = {5,15};
    point *ptr = &p1;

    draw(p1);
    printf("Orig p1 x = %d\n",p1.x);

    draw_p(ptr);
    printf("\nPass to pointer\nx = %d\n",p1.x);

    draw_const(ptr);

    return 0;
}