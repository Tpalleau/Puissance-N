void save_file(grid matrix, int num_players, int turn){
    FILE *data;

    data = fopen("data", "w");

    if (data != 0){
        fprintf(data, "%d\n", num_players);
        fprintf(data, "%d\n", turn);
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

void load_file(grid *matrix, int *num_players, int *turn){
    FILE *data;
    int size;

    data = fopen("data"," r");

    fscanf(data, "%d", *&num_players);
    fscanf(data, "%d", *&turn);
    fscanf(data, "%d", &size);
    matrix->size = size;

    char letter;
    for (int i = 0; i < 7; ++i) {
        letter = getc(data);
        for (int j = 0; j < 7; ++j) {
            letter = getc(data);
            matrix->list[i][j] = letter;
        }
    }

//    for (int i = 0; i < size; ++i) {
//        fgets(letter, size, data);
//        for (int j = 0; j < size; ++j) {
//            matrix->list[i][j] = letter[j+1];
//            printf("%c", letter[j+1]);
//
//        }
//        printf("\n///\n");
//    }
    fclose(data);
}

#ifndef PUISSANCE_N_SAVE_FUNC_H
#define PUISSANCE_N_SAVE_FUNC_H

#endif //PUISSANCE_N_SAVE_FUNC_H
