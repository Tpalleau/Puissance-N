int menu(){
    int choice=0;

    printf("\nWelcome to Connect N!\n");
    printf("[1] : Start a new game\n"
           "[2] : Load an existing game\n"
           "[3] : Quit the game\n");
    do {
        printf("Please chose an option by typing the corresponding number:\n");
        scanf("%d", &choice);

    } while (choice < 1 || choice > 3);

    return choice;
}

void game_options(int *num_player ,int *grid_size){

    do {
        printf("number of players (1 or 2):\n");
        scanf("%d", num_player);

    } while (*num_player < 1 || *num_player > 2);

    do {
        printf("chose number of alligned points to win: \n");
        scanf("%d", grid_size);

    } while (*grid_size < 4 || *grid_size > 20);

    *grid_size += 2;
}



#ifndef PUISSANCE_N_MENU_FUNC_H
#define PUISSANCE_N_MENU_FUNC_H

#endif //PUISSANCE_N_MENU_FUNC_H
