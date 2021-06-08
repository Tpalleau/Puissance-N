void save_file(grid matrix){
    FILE *data;

    data = fopen("data", "w");

    if (data != 0){
        for (int line = 0; line < matrix.size; ++line) {
            for (int column = 0; column < matrix.size; ++column) {
                fprintf(data, "%c,",matrix.list[line][column]);
            }
            fprintf(data,"\n");
        }
    }else{
        printf("error");
    }
}

#ifndef PUISSANCE_N_SAVE_FUNC_H
#define PUISSANCE_N_SAVE_FUNC_H

#endif //PUISSANCE_N_SAVE_FUNC_H
