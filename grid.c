#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void reset(grid *matrix){

    //empty list
    for (int i = 0; i < list_length; ++i) {
        for (int j = 0; j < list_length - 1; ++j) {
            matrix->list[i][j] = ' ';
        }
    }
}
void show_grid(grid matrix){
    //top part of the table
    printf("\n%c", 201);
    for (int element = 0; element < matrix.size - 1; ++element) {
        printf("%c%c%c%c",205, 205, 205, 203);
    }
    printf("%c%c%c%c \n",205, 205, 205, 187);


    for (int line = 0; line < matrix.size; ++line) {
        //line with values
        for (int j = 0; j < matrix.size; ++j) {
            printf("%c %c ",186, matrix.list[line][j]);
        }
        //end of line and beginning of next
        printf("%c\n", 186);

        //lines between values except last line
        if (line < matrix.size - 1){
            printf("%c", 204);
            for (int j = 0; j < matrix.size  - 1; ++j) {
                printf("%c%c%c%c",205, 205, 205, 206);
            }
            printf("%c%c%c%c \n",205, 205, 205, 185);
        }
    }

    //last line
    printf("%c", 200);
    for (int length = 0; length < matrix.size - 1; ++length) {
        printf("%c%c%c%c",205, 205, 205, 202);
    }
    printf("%c%c%c%c \n",205, 205, 205, 188);

    for (int i = 1; i <= matrix.size; ++i) {
        if(i < 10){
            printf("| %d ", i);
        } else {
            printf("| %d", i);
        }

    }
    printf("|\n");
}

