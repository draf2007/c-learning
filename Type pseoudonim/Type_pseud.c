#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String; // такая кострукция создаёт псевдоним для типа
typedef const char* CString; // || typedef const String CString;

int main(int argc, char *argv[]) {
    
    {
        char* s = "abc"; //указатель (на первый элемент массива символов, указатель на массив всегда указыввет на первый элемент массива тип данных char), аналог типа String в других языках
        
        const char* name = "Andrey"; //константный указатель на массив символов типа char 

        char* names[] = {"Anna", "Bred", "Pit"}; //указатель на массив типа char (по сути это многомерный массив из указателей на указатели)

        char** strArray = names; // указатель на указатель массива символов типа char
    }

    {
        String s = "abc";

        CString name = "Andrey";

        String names[] = {"Andrey","Bred", "Pit"};

        String* strArray = names;
    }
    {
        CString s = "5789";
        int k = atoi(s); // atoi переводит строку в число

        printf("%d\n",k);
    }

    return 0;
}