#define list_length 20

typedef struct{

    int size;
    char list [list_length][list_length]; //initialisation de la grille de taille N+2

} grid;

grid reset(grid *matrix){

    //empty list
    for (int i = 0; i < list_length; ++i) {
        for (int j = 0; j < list_length - 1; ++j) {
            matrix->list[i][j] = ' ';
        }
    }
}

grid draw(grid *matrix){

    printf("\n");
    for (int i = 0; i < matrix->size; ++i) {
        for (int j = 0; j < matrix->size ; ++j) {
            printf(" ---");
        }
        printf("\n");
        for (int j = 0; j < matrix->size; ++j) {
            printf("| %c ", matrix->list[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < matrix->size  ; ++j) {
        printf(" ---");
    }
    printf("\n");
    for (int i = 1; i <= matrix->size; ++i) {
        if(i < 10){
            printf("| %d ", i);
        } else {
            printf("| %d", i);
        }

    }
    printf("|\n");
}


#ifndef PUISSANCE_N_GRID_H
#define PUISSANCE_N_GRID_H

#endif //PUISSANCE_N_GRID_H
