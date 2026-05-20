#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 255

/*Функция проверки строки на пустоту*/
int is_empty (const char *buff){ //берём именно const что бы не изменять исходную строку, так как массив передается по укзктелю, а значит в функции мы работаем с исходной строкой
    while (*buff) //бесконечный цикл работает до конца переданной строки или до '\0'
    {
        if (*buff != ' ' && *buff !='\n' && *buff != '\t') //проверка полученного из массива символов элемента на пустоту(пробел) перенос строки('\n') или табуляцию ('\t') 
        {
            return 0; //если полученный элемент символ значит строка не пустая возвращаем 0
        }
        buff++; //берм следующий элемент, и так делаем доконца строки
    }
    return 1; //если элементы полученного массива пусты или это символы переноса или табуляции возвращвем 1 значит строка пустая
}

int main(int argc, char *argv[]) {
    int skip_str = 0;
    char buffer[MAX_LINE];
    FILE *in = fopen("input_filt.txt","w");
    FILE *out = fopen("output_filt.txt","w");
    
    if (!in || !out){
        perror("Не удалось открыть файл!");
        return 1;
    }

    fputs("Citate one\n",in);
    fputs("\n",in);
    fputs(" Citate two\n",in);
    fputs(" ",in);
    fputs("\nCitate one two three\n",in);
    fclose(in);
    in = fopen("input_filt.txt","r");
    while (fgets(buffer,MAX_LINE,in) != NULL)
    {
        int empty = is_empty(buffer);
        if (!empty)
        {
            fputs(buffer,out);
        }
        else {
            skip_str++;            
        }
                
    }
    printf("При записи пропущено %d строк\n",skip_str);

    fclose(in);
    fclose(out);
    in=NULL;
    out=NULL;

    return 0;
}