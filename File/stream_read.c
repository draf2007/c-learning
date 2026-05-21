#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float gpa;
}Student;

int main(int argc, char *argv[]) {
    
    FILE* in = fopen("students.bin","rb");
    if (!in)
    {
        perror("Не возможно открыть файл для чтения!");
        return 1;
    }
    Student temp;

    while (fread(&temp,sizeof(Student),1,in)==1)//кол-во элементов для чтнеия должно быть 1 так как мы не знаем сколько элементов в потоке
    {
        printf("ID: %d | Name: %s | Age: %.2f \n",temp.id,temp.name,temp.gpa);
        
    }
    fclose(in);
    in=NULL;

    return 0;
}