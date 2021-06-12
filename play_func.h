#include "save_func.h"

int win_column(grid *matrix, int column, int *line){ // token_win = number of token you need to win

    int win = 0;
    int i = 0;
    int check = 0;
    int token_win = matrix->size - 2; //num of compared times needed to win


    //from left to right
    while (check != token_win && i < token_win) { //while no victory or checked more than win range
        if (*line + i <= matrix->size - 1) { //check in grid from left else pass to next

            if (matrix->list[*line][column] == matrix->list[*line + 1][column]) {//if is equal to player token check +1
                check++;
            }else{//else reset to 0
                check = 0;
            }

        }else{
            i = token_win;
            continue;
        }
        i++;
    }
    //if win skip check on other diag
    if (check == token_win){
        win = 1;
    }
    return win;
}

int win_line(grid *matrix,int column,int *line) {

    int win = 0;
    int i = - (matrix->size - 3);
    int check = 0;
    int token_win = matrix->size - 2; //num of compared times needed to win


    //from left to right
    while (check != token_win && i < token_win) { //while no victory or checked more than win range
        if (column + i>= 0) { //check in grid from left else pass to next
            if (column + i<= matrix->size - 1){//check if in grid from right else quit
                if (matrix->list[*line][column] == matrix->list[*line][column + i]) {//if is equal to player token check +1
                    check++;
                }else{//else reset to 0
                    check = 0;
                }
            }else{
                i = token_win;
                continue;
            }
        }
        i++;
    }
    //if win skip check on other diag
    if (check == token_win){
        win = 1;
    }
    return win;
}

int win_diag(grid *matrix,int column,int *line) {

    int win = 0;
    int i = - (matrix->size - 3);
    int check = 0;
    int token_win = matrix->size - 2; //num of compared times needed to win


    //bottom left to top right
    while (check != token_win && i < token_win) { //while no victory or checked more than win range
        if (*line - i <= matrix->size - 1 && column + i>= 0) { //check in grid from left else pass to next
            if (*line - i >= 0 && column + i<= matrix->size - 1){//check if in grid from right else quit
                if (matrix->list[*line][column] == matrix->list[*line - i][column + i]) {//if is equal to player token check +1
                    check++;
                }else{//else reset to 0
                    check = 0;
                }
            }else{
                i = token_win;
                continue;
            }
        }
        i++;
    }
    //if win skip check on other diag
    if (check == token_win){
        win = 1;
    }else{

        //reset values
        i = - (matrix->size - 3);
        check = 0;

        //top left to bottom right
        while (check != token_win && i < token_win) { //while no victory or checked more than win range

            if (*line + i >= 0 && column + i>= 0) { //check in grid from left else pass
                if (*line + i <= matrix->size - 1 && column + i<= matrix->size - 1){//check in grid from right else quit
                    if (matrix->list[*line][column] == matrix->list[*line + i][column + i]) {
                        check++;
                    }else{
                        check = 0;
                    }
                }else{
                    i = token_win;
                    continue;
                }
            }
            i++;
        }
    }
    if (check == token_win) {
        win = 1;
    }

    return win;
}


int add_token(grid *tableau, int column, int *line, int player) {
    int not_added = 1;
    for ( int i = tableau->size -1; i > -1; i-=1) {
        if (tableau->list[i][column] == ' ' && not_added){
            *line = i;
            if (player == 1){
                tableau->list[i][column] = 'X';
            }else{
                tableau->list[i][column] = 'O';
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
                if (!action_impossible){
                    *unusable_column = column;
                }
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
    if(win_column(*&tableau, column, *&line) || win_line(*&tableau, column, *&line) || win_diag(*&tableau, column, *&line)){
        printf("The player %d win !!", player);
        exit(EXIT_SUCCESS);
    } else {

    }

    return continu_game;
}

void AI(grid *matrix,int *unusable_column){
    int choice;
    int column;
    int action_impossible;
    int line;


    do {
        choice = rand() % 2;
        column = rand() % matrix->size;

        switch (choice){
            case 0:
                if (column != *unusable_column){
                    action_impossible = add_token(*&matrix, column, &line, 2);
                    *unusable_column = -1;
                }else{
                    action_impossible = 1;
                }
                break;

            case 1:
                action_impossible = remove_token(*&matrix,column);
                if( !action_impossible){
                    unusable_column = column;
                }

        }
    }while(action_impossible);
}



#ifndef PUISSANCE_N_GRID_H
#define PUISSANCE_N_GRID_H

#endif //PUISSANCE_N_GRID_H
