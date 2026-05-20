#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char code[10];
    int qty;
    float price;
}item;

int main(int argc, char *argv[]) {
    int total_item = 0;
    float total_cost = 0.0;
    item item_1 = {"Notebook", 5, 85000.50};
    item item_2 = {"PC", 3, 185000.50};
    item item_3 = {"Mouse", 155, 500.50};
    
    FILE *in = fopen("item.txt","w");
    if (!in)
    {
        perror("Ошибка записи в файл!");
        return 1;
    }
    
    fprintf(in, "%s %d %.2f\n", item_1.code, item_1.qty, item_1.price);
    fprintf(in, "%s %d %.2f\n", item_2.code, item_2.qty, item_2.price);
    fprintf(in, "%s %d %.2f\n", item_3.code, item_3.qty, item_3.price);
    fclose(in);

    in = fopen("item.txt","r");
    
    if (!in)
    {
        perror("Ошибка ошибка чтения из файла!");
        return 1;
    }

    char code[10];
    int qty = 0;
    float price = 0.0;
    
    while (fscanf(in, "%9s %d %f", code, &qty, &price)==3)
    {
        printf("Товар [%9s]: %d шт. %.2f руб.\n", code,qty,price);
        total_cost += qty * price;
        total_item++;
    }
    
    printf("Общая стоимость склада %.2f\n",total_cost);

    fclose(in);
    in=NULL;

    return 0;
}