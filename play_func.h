#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//#include "grid.h"

int add_token(grid *tableau, int column, int player) {
    int not_added = 1;
    for (int i = tableau->size -1; i > -1; i-=1) {
        if (tableau->list[i][column] == ' ' && not_added){
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
    for (int i = tableau->size; i > -1; i-=1) {
        if (tableau->list[i][column] != ' ' && not_removed){
            if (tableau->list[i][column]){
                tableau->list[i][column] = ' ';
            }
            not_removed = 0;
        }

    }
    return (not_removed);
}

int menu_play(grid *tableau, int player){

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

        } while (choice < 0 || choice > 4);


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
                action_impossible = add_token(*&tableau, column, player);
                break;
            case 2:
                action_impossible = remove_token(*&tableau, column);
                break;
            case 3:
                continu_game = 0;
                break;
        }

            // give error message
            if (action_impossible){
                printf("action is not possible...\n");
            }


    } while (action_impossible);
    return continu_game;
}

#ifndef PUISSANCE_N_GRID_H
#define PUISSANCE_N_GRID_H

#endif //PUISSANCE_N_GRID_H
