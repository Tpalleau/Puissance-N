#include <stdio.h>
#include <stdlib.h>
#include "function.h"

//save the game if you quit
void save_file(grid matrix, int num_players, int turn, int unusable_column){
    FILE *data;

    data = fopen("data", "w");

    //write the data on the file
    if (data != 0){
        fprintf(data, "%d\n", num_players);
        fprintf(data, "%d\n", turn);
        fprintf(data, "%d\n", unusable_column);
        fprintf(data, "%d",matrix.size);
        for (int line = 0; line < matrix.size; ++line) {
            fprintf(data, "\n");
            for (int column = 0; column < matrix.size; ++column) {
                fprintf(data ,"%c", matrix.list[line][column]);
            }
        }
    }else{
        printf("error saving\n");
    }

    fclose(data);
}

//load a game if you have one
void load_file(grid *matrix, int *num_players, int *turn, int *unusable_column){
    FILE *data;
    int size;

    data = fopen("data"," r");

    //read the data
    fscanf(data, "%d", *&num_players);
    fscanf(data, "%d", *&turn);
    fscanf(data, "%d", *&unusable_column);
    fscanf(data, "%d", &size);
    matrix->size = size;

    //rewrite on the grid
    char letter;
    for (int i = 0; i < size; ++i) {
        letter = getc(data);
        for (int j = 0; j < size; ++j) {
            letter = getc(data);
            matrix->list[i][j] = letter;
        }
    }

    fclose(data);
}

#ifndef PUISSANCE_N_SAVE_FUNC_H
#define PUISSANCE_N_SAVE_FUNC_H

#endif //PUISSANCE_N_SAVE_FUNC_H

