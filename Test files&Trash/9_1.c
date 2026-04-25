#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_u (size_t size, void* a,void* b) {

    if (size>0)
    {
        
    }
    else
    {
        exit(1);
    }

    if (a==NULL) {
        perror("out of memmory");
        exit(1);
    }
    if (b==NULL) {
        perror("out of memmory");
        exit(1);
    }

    void* ptemp = malloc(size);

    if (ptemp==NULL) {
        perror("out of memmory");
        exit(1);
    }

    memcpy(ptemp, a, size);
    memcpy(a,b,size);
    memcpy(b,ptemp,size);
    free(ptemp);
    ptemp = NULL;

}

int main(int argc, char *argv[]) {
    
    int a = 5;
    int b = 10;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    void* pa = &a;
    void* pb = &b;
    size_t n = sizeof(a);
    swap_u(n,pa,pb);
    printf("a = %d\n",a);
    printf("b = %d\n",b);

    return 0;
}