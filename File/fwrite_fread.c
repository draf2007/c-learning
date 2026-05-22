#include <stdio.h>
#include <stdlib.h>
/*Бинарная запсиь структур в файл и бинарное чтнеие из него*/
/*Описание fwrite() - бинарная запись, возвращает кол-во успешно записанных элементов или EOF(конец файла)
    fwrite(pointer data, size of element, number of elements, stream)
        pointer data - указатель на адрес(&addr) памяти откуда брать данные для записи
        size of element - размер одного элемента для записи (например в случае структуры берётся размер всей структуры)
        number of elements кол-во элементов для записи
        stream - указатель на адрес потока куда писать данные из pointer data
    Пример:
    ---создаём структуру---
    typedef struct 
    {
        int id;
        char name[20];
        float gpa;
    }Student;
    ---Создаём одномерный массив типа Student состоящий из экземпляров структуры Student---
    Student Students[3] = {{10,"Kolin",12.5},{11,"alex",14.5},{12,"Tom",18.5}};
    ---открываем поток для бинарной записи в файл---
    FILE *in = fopen("item.bin","wb");
    ---Проверка на возможность работы с потоком---
    if (!in)
    {
        perror("Ошибка записи в файл!");
        return 1;
    }
    ---записываем массив структур в файл---
    fwrite(Students,sizeof(Student),3,fb);
    ---ОБЯЗАТЕЛЬНО закрываем поток и обнуляем указатель!!!--
    fclose(in);
    in=NULL;
*/

/*Описание fread()
    fwrite(pointer data, size of element, number of elements, stream) - бинарное чтение, возвращает кол-во успешно прочитанных полей или EOF(конец файла)
    fwrite(pointer data, size of element, number of elements, stream)
        pointer data - указатель на адрес(&addr) памяти куда записывать данные
        size of element - размер одного элемента для чтения (например в случае структуры берётся размер всей структуры)
        number of elements кол-во элементов для записи
        stream - указатель на адрес потока от куда читать данные в pointer data
    Пример:
    ---создаём структуру---
    typedef struct 
    {
        int id;
        char name[20];
        float gpa;
    }Student;
    ---Создаём одномерный массив типа Student состоящий из экземпляров структуры Student---
    Student Students[3] = {{10,"Kolin",12.5},{11,"alex",14.5},{12,"Tom",18.5}};
    ---открываем поток для бинарной записи в файл---
    FILE *in = fopen("item.txt","wb");
    ---Проверка на возможность работы с потоком---
    if (!in)
    {
        perror("Ошибка записи в файл!");
        return 1;
    }
    ---записываем массив структур в файл---
    fwrite(Students,sizeof(Student),3,fb);
    ---закрываем поток--
    fclose(in);
    ---открываем поток для чтения в бинарном режиме---
    in = fopen("students.bin","rb");
    ---создаём массив структур типа Student для записи того что прочитаем---
    Student st_buf[3];
    ---читаем из потока в созданный массив структур---
    size_t readed = fread(&st_buf,sizeof(Student),3,fb);
    ---так как fread() возвращает колличество успешно прочитанных элементов, проверяем удачно прочиталось именно 3 элемента---
    if (readed != 3) {
        printf("Read error! Read %zu\n", readed);//если кол-во прочитанных элементов не равно 3 выводим ошибку
    }
    else{
        //цикл для вывода на экран прочитанных элементов
        for (size_t i = 0; i < 3; i++)
        {
            printf("ID: %-4d | Name: %-8s | GPA: %.1f\n",st_buf[i].id, st_buf[i].name, st_buf[i].gpa);       
        }
    
    }
    ---ОБЯЗАТЕЛЬНО закрываем поток и обнуляем указатель!!!---
    fclose(fb);
    in=NULL;
    */

typedef struct 
{
    int id;
    char name[20];
    float gpa;
}Student;

int main(int argc, char *argv[]) {

    Student Students[3] = {{10,"Kolin",12.5},{11,"alex",14.5},{12,"Tom",18.5}};
    FILE *fb = fopen("students.bin","wb");
    if (!fb)
    {
        perror("Ошибка записи в файл!");
        return 1;
    }
    fwrite(Students,sizeof(Student),3,fb);

    fclose(fb);

    fb = fopen("students.bin","rb");
    
    Student st_buf[3];

    size_t readed = fread(&st_buf,sizeof(Student),3,fb);
    if (readed != 3) {
        printf("Read error! Read %zu\n", readed);
    }
    else{
        for (size_t i = 0; i < 3; i++)
        {
            printf("ID: %-4d | Name: %-8s | GPA: %.1f\n",st_buf[i].id, st_buf[i].name, st_buf[i].gpa);       
        }
    
    }
    fclose(fb);
    fb=NULL;

    return 0;
}