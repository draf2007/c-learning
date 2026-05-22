#include <stdio.h>
#include <stdlib.h>
/*Работа со структурой и перемещение внутри файла*/
/*fseek() - перемещение на указанную позицию в файле
    fseek(stream, offset, whence)
    stream - указатель на поток с которым работаем
    offset - смещение в байтах на сколько переститься
    whence - точка отсчета для перемещения
             может принимать значения
             SEEK_SET (0) → начало файла
             SEEK_CUR (1) → текущая позиция
             SEEK_END (2) → конец файла
  fseek() - возвращает int 0 при успехе и int !=0 при ошибке перемещения*/

/*ftell() - возвращает текущее смещение в байтах от начала файла, или -1L при ошибке тип возвращаемых данных long
    ftell(stream)
    stream - поток с которым работаем*/
  
/*rewind(stream) - возврат в начало файла или потока со сбросом флага ошибок
  stream - указатель на поток с которым работаем*/


/*Создаём тип структуры для чтения из файла*/
typedef struct
{
    int id;
    char name[20];
    float gpa;
}Student;

int main(int argc, char *argv[]) {
    long file_size = 0; //размер файла всегда делаем long для файлов 2ГбЮ произойдёт обрезание значения на 64 битных системах
    int index = 0;//переменная для индексирования записей
    float new_record = 0.0;//новое значение для поля gpa
    long offset = 0;//оффсет для fseek
    /*Открываем поток в бинарном режиме для чтения/записи*/
    FILE* fp=fopen("students.bin","rb+");
    /*Проверяем файл для возможности записи/чтения*/
    if (!fp)
    {
        perror("Не возможно открыть файл!");
        return 1;
    }
    /*переходим в конец файла*/
    fseek(fp,0,SEEK_END);
    /*Записываем в переменную размер*/
    file_size=ftell(fp);
    /*возвращаемся в началао файла*/
    rewind(fp);
    /*Проверяем поврежден ли файл путём взятия остатка от деления размера файла на размер структуры
    так как результат в таком случае не может быть равен 0*/
    if (file_size % sizeof(Student) != 0)
    {
        printf("Файл повреждён или содержит неполную запись!\n");
    }
    else {
        /*Рассчитываем кол-во записей*/
        size_t count = file_size / sizeof(Student);
        printf("Кол-во записей: %zu\nРазмер файла: %ld байт\n", count, file_size);
    }
    /*Создаем структуру типа Studen для буфера чтения из файла*/
    Student buf;
    printf("index|  id  |   Name   |   gpa   |\n");
    /*Тут в цикле читаем все записи до конца файла и вывоводим на экран*/
    while (fread(&buf,sizeof(Student),1,fp) == 1)
    {
        printf("%d    |  %d  |   %s   |   %.2f   |\n",index,buf.id,buf.name,buf.gpa);
        index++;
    }
    /*Возвращаемся в начало файла*/
    rewind(fp);
    

    printf("Введиите индекс записи для изменения: ");
    scanf("%ld", &offset);
    /*Проверяем что выбранная запись существует*/
    if (offset >= index || offset < 0)
    {
        printf("Выбрана несуществующая запись!!!");
        return 1;
    }

    printf("Введиите новое значение gpa в формате xx.xx: ");
    scanf("%f", &new_record);
    /*Создаем еще одну структуру типа Studend что бы прочитать в неё указанную пользователем запись из файла*/
    Student buf_2;
    /*Переходим в начало указанной записи*/
    fseek(fp,sizeof(Student)*offset,SEEK_SET);
    /*Читаем её в buf_2*/
    fread(&buf_2,sizeof(Student),1,fp);
    printf("Старые данные:\n");
    printf("index|  id  |   Name   |   gpa   |\n");
    printf("%ld    |  %d  |   %s   |   %.2f   |\n",offset,buf_2.id,buf_2.name,buf_2.gpa);
    /*Меняем значение элемента в структуре на указанное пользователем*/
    buf_2.gpa = new_record;
    /*Тут прямой доступ к структуре но можно работать и через указатель вот так
    Student *ptr_buf_2 = &buf_2; - Создали тип указатель на структуру
    ptr_buf_2->gpa = new_record; - разыменовали и изменили*/
    /*Переходим в начало указанной записи*/
    fseek(fp,sizeof(Student)*offset,SEEK_SET);
    /*Записываем обновленную структуру вместо старой*/
    fwrite(&buf_2,sizeof(Student),1,fp);
    /*Переходим в начало указанной записи*/
    fseek(fp,sizeof(Student)*offset,SEEK_SET);
    /*Читаем обновленную структуру и выводим на экран*/
    fread(&buf_2,sizeof(Student),1,fp);
    
    printf("Новые данные:\n");
    printf("index|  id  |   Name   |   gpa   |\n");
    printf("%ld    |  %d  |   %s   |   %.2f   |\n",offset,buf_2.id,buf_2.name,buf_2.gpa);
    fclose(fp);
    fp=fopen("students.bin","rb");
    index = 0;
    printf("Проверьте изменения:\n");
    printf("index|  id  |   Name   |   gpa   |\n");
    while (fread(&buf,sizeof(Student),1,fp) == 1)
    {
        printf("%d    |  %d  |   %s   |   %.2f   |\n",index,buf.id,buf.name,buf.gpa);
        index++;
    }

    fclose(fp);
    fp=NULL;
    return 0;
}