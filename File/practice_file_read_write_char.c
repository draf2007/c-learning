#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int summ = 0;
    /*Открываем 2 потока, один для чтения(in), второй для записи(out)*/
    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");
    
    /*Проверка на возможность работы с файлами*/
    if (!in || !out)
    {
        printf("Невозможно открыть файл!");
        return 1;
    }

    int ch;//переменная в которую будет писаться код символа, так же её будем использовать для нахождения конца файла
    while ((ch = fgetc(in))!=EOF)//Условие для выполнения цикла выполняется пока не придёт код символа EOF
    {
        fputc(ch, out);//функция записи кода символа(ch) в поток out
        summ++;
    }
    printf("Считано %d символа", summ);
    /*Закрываем потоки*/
     fclose(in);
     fclose(out);
     /*Обнуляем указатели*/
    in=NULL;
    out=NULL;

    return 0;
}