#include <stdio.h>
#include <stdlib.h>

#include <string.h>
//#include <ctype.h>
//#include <wchar.h>

char* concat_strings(const char* pstr1, const char* pstr2) {
    int cat_strlen = strlen(pstr1) + strlen(pstr2)+1;
    char* result = malloc(cat_strlen);
    strcpy(result,pstr1);
    strcat(result,pstr2);
    return result;
}

int main(int argc, char *argv[]) {
    
    char* str1="Hello ";
    char* str2="World";
    char* result = concat_strings(str1,str2);
    printf("%s",result);
    free(result);
    result=NULL;
    return 0;
}