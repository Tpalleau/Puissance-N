#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

int main(void) {

    printf("   ____     __     _   _   _   _    _____    _____   _______     _   _\n"
           " / ____|  / __ \\  | \\ | | | \\ | | |  ____|  / ____| |__   __|   | \\ | |\n"
           "| |      | |  | | |  \\| | |  \\| | | |__    | |         | |      |  \\| |\n"
           "| |      | |  | | | . ` | | . ` | |  __|   | |         | |      | . ` |\n"
           "| |____  | |__| | | |\\  | | |\\  | | |____  | |____     | |      | |\\  |\n"
           " \\_____|  \\____/  |_| \\_| |_| \\_| |______|  \\_____|    |_|      |_| \\_|\n");

// loops
    int run_program = 1;
    int play;

// output func variables
    int line = 0;
    int menu_choice;
    int num_player = 0;
    int grid_size = 0;
    int unusable_column = -1;

// main variables
    int player;


    grid tableau;

    srand(time(0));

    //app loop
    while (run_program){
        reset(&tableau);

        // play/load/quit
        menu_choice = menu();

        switch (menu_choice) {
            case 1:
                //num of player and grid size
                game_options(&num_player, &grid_size);
                tableau.size = grid_size;
                break;

            case 2:
                //load file
                load_file(&tableau, &num_player, &player, &unusable_column);
                break;

            case 3:
                //exit game
                run_program=0;
                continue;

        }
        play = 1;
        player = 1;

        //game loop
        while (play){
            show_grid(tableau);
            printf("\nplayer %d's turn to play\n\n", player);

            play = menu_play(&tableau, player, &line, num_player, &unusable_column);

            //check if the player is alone or not
            if (player == 1){
                if (num_player == 1){
                    AI(&tableau, &unusable_column);
                }else{
                    player = 2;
                }

            }else if (player == 2){
                player = 1;
            }

        }
    }
}
