#include <stdio.h>
#include <stdlib.h>
#define ROWS 16
#define COLS 16

int main(int argc, char *argv[]) {
    int accum_ascii_num=33;
    int ascii_array[ROWS][COLS];

    for (int rows = 0; rows < ROWS; rows++)
    {
        for (int cols  = 0; cols < COLS; cols++)
        {
            ascii_array[rows][cols]=accum_ascii_num;
            printf("%c",ascii_array[rows][cols]);
            accum_ascii_num++;
        }
       printf("\n"); 
    }
    
    return 0;
}