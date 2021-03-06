#include <stdio.h>
#include <stdlib.h>
#include "function.h"


//check if the grid is full
int check_draw(grid matrix){
    int draw = 1;
    //loop to check if there have empty case
    for (int line = 0; line < matrix.size - 1; ++line) {
        for (int column = 0; column < matrix.size - 1; ++column) {
            if (matrix.list[line][column == ' ']){
                draw = 0;
            }
        }

    }
    return draw;
}

//check all the posiblity of win
int check_win(grid *matrix,int player, int column, int *line){
    int win;
    //check if one of the three posibility is true
    if (win_column(*&matrix, column) == 1 || win_line(*&matrix, column, *&line) == 1 ||
        win_diag(*&matrix, column, *&line)) {
        if(player == 1 ){
            win = 0;
        } else {
            win = 1; //for player 2
        }

    } else {
        win = -1;
    }
    return win;
}

//check only column win
int win_column(grid *matrix, int column){ // token_win = number of token you need to win
    int win;
    int i = matrix->size - 1 ; // because the coordonate of the grid start at 0
    int check = 0; // initialize the check win to 0
    int token_win = matrix->size - 3; //for win you just need to compairs each pair of n-1
    while(i <= matrix->size && check != token_win && matrix->list[i][column] != ' '){ //do the check only if the column exist and if if doesn't win yet and if the case isn't empty
        if (matrix->list[i][column] == matrix->list[i-1][column]) // check if the token if the same than above
        {
            check++; //+1 if yes
        } else {
            check = 0;//return to 0 if no
        }
        i--;

    }
    if(check == token_win){//it's for say if it's a win or not

        win = 1;

    } else {
        win = 0;

    }


    return win;

}

//check only line win
int win_line(grid *matrix,int column,int *line) {

    int win; //same as the column
    int i = column; //which column he play
    int check = 0;
    int token_win = matrix->size - 3;
    while (i <= matrix->size && check != token_win && matrix->list[*line][i] != ' ') {
        if (matrix->list[*line][i] == matrix->list[*line][i + 1]) { //check for the right
            check++;
            i++;
        } else { // if the token isn't the same check in the other direction start for where he play
            check = 0;
            i = column; //reset which column he play
            while (i <= matrix->size && check != token_win && i > 0 && matrix->list[*line][i] != ' ') { //check for the left
                if (matrix->list[*line][i] == matrix->list[*line][i -1]) {
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

//check only diagonal win
int win_diag(grid *matrix,int column,int *line) {

    int win = 0;
    int l = *line; //for the diagonal we need to change the value of the line and the column
    int c = column;
    int i = - (matrix->size - 3);
    int check = 0;
    int token_win = matrix->size - 2; //num of compared times needed to win


    //bottom left to top right
    while (check != token_win && i < token_win) { //while no victory or checked more than win range
        if (l - i <= matrix->size - 1 && c + i>= 0) { //check only in grid range
            if (l - i >= 0 && c + i<= matrix->size - 1){
                if (matrix->list[l][c] == matrix->list[l - i][c + i]) {//if is equal to player token check +1
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

            if (l + i >= 0 && c + i>= 0) { //check of start in range else pass
                if (l + i <= matrix->size - 1 && c + i<= matrix->size - 1){//check of end in range else quit
                    if (matrix->list[l][c] == matrix->list[l + i][c + i]) {
                        check++;
                    }else{
                        check = 0;//reset to 0 if not
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

//when the player want to add a token
int add_token(grid *tableau, int column, int *line, int player) {
    int not_added = 1;
    //loop until there is a blank to add a token (start bottom to top)
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

//When the player want ot remove a token
int remove_token(grid *tableau, int column){
    int not_removed = 1;
    //loop until see a token to remove (from top to bottom)
    for ( int line = 0; line < tableau->size; ++line) {
        if (tableau->list[line][column] != ' ' && not_removed){
            if (tableau->list[line][column]){
                tableau->list[line][column] = ' ';
            }
            not_removed = 0;
        }

    }
    return not_removed;
}

//Menu in game
int menu_play(grid *tableau, int player, int *line, int num_players, int *unusable_column) {

    //intialise variables
    int continu_game = 1;
    int choice = 0;
    int column = 0;
    int action_impossible = 0;


    // check if action is possible
    do {

        // check if correct input
        do {
            printf("[1] : Add a token\n"
                   "[2] : Remove a token\n"
                   "[3] : Save & quit the game\n");
            printf("Please chose an option by typing the corresponding number:\n");
            scanf("%d", &choice);

        } while (choice < 1 || choice > 3);


        // for option 1 & 2 check if column is valid
        if (choice != 3) {
            do {
                printf("please chose a column\n");
                scanf("%d", &column);
            } while (column < 1 || column > tableau->size);
            column -= 1;
        }

        // call corresponding func to action chosen
        switch (choice) {
            case 1:
                if (*unusable_column != column) {
                    action_impossible = add_token(*&tableau, column, *&line, player);
                    *unusable_column = -1;
                } else {
                    printf("other player removed in this column before\n");
                    action_impossible = 1;
                }
                break;
            case 2:
                action_impossible = remove_token(*&tableau, column);
                if (!action_impossible) {
                    *unusable_column = column;
                }
                break;
            case 3:
                save_file(*tableau, num_players, player, *unusable_column);
                continu_game = 0;
                break;
        }

        // give error message
        if (action_impossible == 0) {
            printf("action is not possible...\n");
        }


    } while (action_impossible);

    if (check_win(*&tableau, player, column, *&line) == 0 && choice == 1) { //check only if token added
        show_grid(*tableau);
        printf("The player 1 win !!");
        continu_game = 0;

    }if (check_win(*&tableau, player, column, *&line) == 1 && choice == 1) { //check only if token added
        show_grid(*tableau);
        printf("The player 2 win !!");
        continu_game = 0;
    }

    if(check_draw(*tableau) == 1){//check if the grid is full
        show_grid(*tableau);
        printf("Draw : %d", check_draw(*tableau));
        printf("This is a draw !!");
        continu_game = 0;
    }

    return continu_game;
}

//the robot who play if you are alone
void AI(grid *matrix,int *unusable_column){

    //initialise variables
    int choice;
    int column;
    int action_impossible;
    int line;


    do {
        //the AI thicks about his moove...
        choice = rand() % 2;
        column = rand() % matrix->size;

        //...and do the moove
        switch (choice){
            case 0:
                if (column != *unusable_column){
                    action_impossible = add_token(*&matrix, column, &line, 2);
                    *unusable_column = -1;
                    printf("the AI has added a token\n");
                }else{
                    action_impossible = 1;
                }
                break;

            case 1:
                action_impossible = remove_token(*&matrix,column);
                if( !action_impossible){
                    *unusable_column = column;
                    printf("the AI has removed a token, column %d\n", *unusable_column + 1);
                }

        }
    }while(action_impossible);
}