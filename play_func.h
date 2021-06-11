#include "save_func.h"

int win_column(grid *ptr, int column, int i);
int win_line(grid *ptr, int column,int *line, int i);
int win_diag(grid *ptr, int column,int *line, int i);


int add_token(grid *tableau, int column, int *line, int player) {
    int not_added = 1;
    for ( *line = tableau->size -1; *line > -1; *line-=1) {
        if (tableau->list[*line][column] == ' ' && not_added){
            if (player == 1){
                tableau->list[*line][column] = 'X';
            }else{
                tableau->list[*line][column] = 'O';
            }
            not_added = 0;
        }
    }
    return not_added;
}

int remove_token(grid *tableau, int column){
    int not_removed = 1;
    for ( int line = 0; line < tableau->size; ++line) {
        if (tableau->list[line][column] != ' ' && not_removed){
            if (tableau->list[line][column]){
                tableau->list[line][column] = ' ';
            }
            not_removed = 0;
        }

    }
    return (not_removed);
}

int menu_play(grid *tableau, int player, int *line, int num_players, int *unusable_column){

    int continu_game = 1;
    int choice = 0;
    int column = 0;
    int action_impossible = 0;


    // check if action is possible
    do {

        // check if correct input
        do  {
            printf("[1] : Add a token\n"
                   "[2] : Remove a token\n"
                   "[3] : Save & quit the game\n");
            printf("Please chose an option by typing the corresponding number:\n");
            scanf("%d", &choice);

        } while (choice < 1 || choice > 3);


        // for option 1 & 2 check if column is valid
        if (choice != 3){
            do {
                printf("please chose a column \n");
                scanf("%d", &column);
            } while (column<1 || column > tableau->size);
            column -= 1;
        }

        // call corresponding func to action chosen
        switch (choice) {
            case 1:
                if (*unusable_column != column){
                    action_impossible = add_token(*&tableau, column, *&line, player);
                    *unusable_column = -1;
                }else{
                    action_impossible = 1;
                }
                break;
            case 2:
                action_impossible = remove_token(*&tableau, column);
                *unusable_column = column;
                break;
            case 3:
                save_file(*tableau, num_players, player, *unusable_column);
                continu_game = 0;
                break;
        }

            // give error message
            if (action_impossible){
                printf("action is not possible...\n");
            }


    } while (action_impossible);

    //win_diag(*&tableau, column, *&line, tableau->size) == 1
    //win_column(*&tableau, column, tableau->size) == 1 || win_line(*&tableau, column, *&line, tableau->size) == 1
    if(win_line(*&tableau, column, *&line, tableau->size) == 1){
        printf("Win");
    } else {
        printf("No win");
    }

    return continu_game;
}



int win_column(grid *matrix, int column, int token_win){ // token_win = nombre de jeton qu'il faut aligner pour gagner
    int win;
    int i = matrix->size;
    int check = 0;
    token_win = token_win-3; // for the number to win

    while(i <= matrix->size && check != token_win && matrix->list[i][column] != ' '){
        if (matrix->list[i][column] == matrix->list[i-1][column])
        {
            check++;
        } else {
            check = 0;
        }
        i--;
        printf("%d", check);

    }
    if(check == token_win){

        win = 1;

    } else {
        win = 0;

    }


    return win;

}

int win_line(grid *matrix,int column,int *line, int token_win) {

    int win;
    int i = *line;
    int check = 0;
    token_win = token_win - 3;

    while (i <= matrix->size && check != token_win && matrix->list[i][column] != ' ') {
        if (matrix->list[i][column] == matrix->list[i + 1][column]) {
            check++;
            i++;
        } else {
            check = 0;
            i = *line;
            while (i <= matrix->size && check != token_win && i > 0) {
                if (matrix->list[i][column] == matrix->list[i - 1][column]) {
                    check++;
                } else {
                    check = 0;
                }
                i--;
            }
        }

        if (check == token_win) {

            win = 1;

        } else {

            win = 0;

        }


        return win;
    }
}

int win_diag(grid *matrix,int column,int *line, int token_win) {

    int win;
    int i = *line;
    int check = 0;
    token_win = token_win - 3;
    while (i <= matrix->size && check != token_win && matrix->list[i][column] != ' ') {
        printf("1 : %c // 2 : %c\n", matrix->list[i][column], matrix->list[i + 1][column - 1]);
        if (matrix->list[i][column] == matrix->list[i + 1][column - 1]) {
            check++;
            i++;
        } else {
            check = 0;
            i = *line;
            printf("1 : %c // 2 : %c\n", matrix->list[i][column], matrix->list[i - 1][column + 1]);
            while (i <= matrix->size && check != token_win && i > 0) {
                if (matrix->list[i][column] == matrix->list[i - 1][column + 1]) {
                    check++;
                } else {
                    check = 0;
                }
                i--;
            }
        }

        if (check == token_win) {

            win = 1;

        } else {

            win = 0;

        }


        return win;
    }
}

#ifndef PUISSANCE_N_GRID_H
#define PUISSANCE_N_GRID_H

#endif //PUISSANCE_N_GRID_H
