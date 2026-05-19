/*Работа с файлами в C по сути состоит из 4 частей
1. Открыть поток с помощью указателя FILE *fp = fopen("file_name.txt","w(Запись)r(Чтение)a(Дозапись)r+(Чтение+Запись)w+(Запись+Чтение)a+(Дозапись+Чтение)") 
2. Проверка на возможность работы с файлом
    if (!fp){
        perror("Не удалось открыть файл!");
        return 1;
    }
3. Собственно сами операции над содержимым файла
    посимвольное чтение fgetc()
    int symbol = fgetc(fp); читает не символ а его код, в переменную symbol поместится код первого символа из потока fp

    посимвольная запись fputc()
    fputc(symbol, fp); запись кода символа в поток fp

    построчное чтение файла fgets()
    char string[255]; массив буфер для чтения
    fgets(string,255,fp); читаем строку длинной 255 символов или до "\n" включительно, в массив string, из потока fp
    
    построчная запись в файл fputs()
    fputs("Первая заметка\n", fp); строка для записи, поток в который надо записать (писать надо вместе с "\n" иначе строки "слипнуться")
4. Закрытие потоков и обнуление указателей
    fclose(fp);
    fp = NULL;*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 255

int main(int argc, char *argv[]) {
    
    FILE *fp = fopen("quotes.txt","w");
    
    if (!fp){
        perror("Не удалось открыть файл!");
        return 1;
    }

    fputs("Первая цитата\n",fp);
    fputs("Вторая цитата\n",fp);
    fputs("Третья цитата\n",fp);

    fclose(fp);

    fp = fopen("quotes.txt","r");
    
    char buffer[MAX_LINE];
    while (fgets(buffer,MAX_LINE,fp) != NULL)
    {
        printf("> %s", buffer);
    }
    

    return 0;
}