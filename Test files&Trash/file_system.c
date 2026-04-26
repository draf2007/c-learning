#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* fname_1="test.txt";
const char* fname_2="test2.txt";

int main(int argc, char *argv[]) {

    FILE* f = fopen(fname_1,"r");
    if (f == NULL)
    {
        perror(fname_1);
        exit(1);
    }
    
    puts("Read by char");
    int byte;

    while ((byte = fgetc(f))!=EOF)
    {
        putchar(byte);
    }

#define MAX_STR_SIZE 65535

    char str[65535];
    while (fgets(str,MAX_STR_SIZE,f)!=NULL)
    {
        str[strlen(str)-1] = '\0';
        puts(str);
    }
    
    fseek(f, 0, SEEK_END);
    long f_size = ftell(f);
    printf("\nFile size: %ld\n",f_size);

    puts("");
    
    fclose(f);
/*-------------------------------------*/
    puts("Write file");
    FILE* f2 = fopen(fname_2, "a");

    if (f == NULL)
    {
        perror(fname_2);
        exit(3);
    }

    for (int i = 0; i <= 4; i++)
    {
        fprintf(f2, "Line %d\n",i);
    }
    
fclose(f2);
    return 0;
}