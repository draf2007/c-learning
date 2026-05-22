#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[20];
    float gpa;
}Student;

int main(int argc, char *argv[]) {

    FILE* in = fopen("students.bin","rb");
    FILE* out = fopen("studnets_new.bin","wb");

    if (!in || !out)
    {
        perror("Не возможно открыть файлы для чтения или записи");
        return 1;
    }
    
    Student buf;
    size_t r_count,w_count;
    r_count=w_count=0;
    while (fread(&buf,sizeof(Student),1,in)==1)
    {
        if (fwrite(&buf,sizeof(Student),1,out) != 1)
        {
            printf("Ошибка записи");
        }
        else{w_count++;}
        
        r_count++;
    }
    
    printf("Прочитанно %d\n",r_count);
    printf("Записанно %d\n",w_count);

    fclose(in);
    in=NULL;
    fclose(out);
    out=NULL;
    
    return 0;
}