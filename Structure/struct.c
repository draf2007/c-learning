#include <stdio.h>
#include <stdlib.h>

/*Вот так объявляется структура*/
/*Это шаблон по которому будет создаваться пользовательский тип данных Point*/
struct Point{
    int x;
    int y;
};
/*Для доступа к структуре постоянно приходится писать struct Point point1
Но можно упростить вызов структуры в коде при помощи typedef*/
typedef struct {
    int x;
    int y;
} Point_t;

/*Шаблон структуры для демонстрации выравнивания (padding) размера ячеек памяти при использовании стуктуры*/
typedef struct {
    int x;
    double y;
    int z;
} pading_struct_t;

int main(int argc, char *argv[]) {
    /*Пример создания 3 пользовательских типов данных по шаблону Point*/
    struct Point point1 = {1,5}; /*Примеры создания и заполнения*/
    struct Point point2 = {.x=30, .y=20};/*Это по стандарту C99*/
    /*Можно сначала объявить*/
    struct Point point3;
    /*Потом заполнить, но так лучше не делать,до заполнения в ячейках будет мусор*/
    printf("Point3 x = %d, Point3 y = %d\n\n", point3.x, point3.y);
    point3.x=5;
    point3.y=10;

    /* Для доступа к структуре данных созданной по шаблону Point_t с помощью typedef теперь 
    можно просто писать Point_t */
    Point_t p1 = {11, 25};
    
    printf("Point1 x = %d, Point1 y = %d\n", point1.x, point1.y);
    printf("Point2 x = %d, Point2 y = %d\n", point2.x, point2.y);
    printf("Point3 x = %d, Point3 y = %d\n", point3.x, point3.y);
    printf("\n");
    printf("p1 x = %d, p1 y = %d\n", p1.x, p1.y);

/*Пример выравнивания размера ячеек в памяти при использовании структуры*/

    /* создаём структуру типа pading_struct_t и заполняем её*/
    pading_struct_t pading1 = {.x=2, .y=12.0, .z=5}; 
    /*Печатаем размер каждой ячейки*/
    printf("sizeof x = %d\n",sizeof(pading1.x)); /*4 байта int*/
    printf("sizeof y = %d\n",sizeof(pading1.y)); /*8 байт double*/
    printf("sizeof z = %d\n",sizeof(pading1.z)); /*4 байта int*/


    /*Печатаем размер всей структуры и он 24 байта хотя должен быть 16 байт. 24-16 = 8 байт, по 4 байта выравнивания на каждую ячейку типа int
    При создании структуры размер ячейки для отдельного значения создается размером с самую большую ячейку в структуре
    это нужно для доступа к элементу структуры по имени или адресу
    так быстрее потому что процессор обращается к памяти по блокам 4 или 8 байт*/
    printf("sizeof padding_struct_t = %d\n",sizeof(pading_struct_t));

    return 0;
}