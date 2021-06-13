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
    int play = 1;

// output func variables
    int line = 0;
    int menu_choice = 0;
    int num_player = 0;
    int grid_size = 0;
    int unusable_column = -1;

// main variables
    int player = 1;


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

            case 2: load_file(&tableau, &num_player, &player, &unusable_column);
                break;

            case 3: run_program=0;
                continue;
        }
        // show the rules



        //game loop
        while (play){
            printf("\nplayer %d's turn to play\n\n", player);
            show_grid(tableau);

            play = menu_play(&tableau, player, &line, num_player, &unusable_column);

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

        run_program = 0;
    }
}
