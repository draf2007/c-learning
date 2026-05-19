#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256

int main(int argc, char *argv[]) {
    /*Открываем поток, для записи*/
    FILE *fp=fopen("output.txt","w");
    /*Проверка на возможность работы с файлами*/
    if (!fp){
        perror("Не удалось открыть файл!");
        return 1;
    }
    /*Функция fputs пишет строку в файл до конца строки символ "\0"*/
    fputs("Первая заметка\n", fp);
    fputs("Вторая заметка\n", fp);
    fputs("Третья заметка\n", fp);
    fputs("Четвёртая заметка\n", fp);
    fputs("Пятая заметка\n", fp);

    fclose(fp);

    fp=fopen("output.txt","r");

    char buffer[MAX_LINE]; //создаем буфер для записи (массив символов)
    int line_number = 1;

    while (fgets(buffer,MAX_LINE,fp)!=NULL) //читаем в буфер из потока fp строку размером MAX_LINE до символа "\n" сравниваем с NULL(либо конец файла, либо ошибка типа)
    {
        printf("%d: %s", line_number++,buffer); //выводим прчитанную строку на экран
    }
    
    fclose(fp);
    fp = NULL;

    return 0;
}