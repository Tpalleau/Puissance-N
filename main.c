#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "grid.h"
#include "menu_func.h"
#include "play_func.h"

int main(void) {
    // loops
    int run_program = 1;
    int play = 1;

    // output func variables
    int menu_choice = 0;
    int num_player = 0;
    int grid_size = 0;

    // main variables
    int player = 2;

    while (run_program){
        // play/load/quit
        menu_choice = menu();

        if (menu_choice == 3){
            run_program = 0;
            continue;
        }else{
            game_options(&num_player, &grid_size);
        }
        // afficher les règles
        grid tableau = {grid_size};
        reset(&tableau);

        while (play){
            if (player == 1){
                if (num_player == 1){
                    printf("find a friend the computer doesnt want to play with you\n");
                }else{
                    player = 2;
                }

            }else if (player == 2){
                player = 1;
            }

            printf("\nplayer %d's turn to play and %d\n\n", player, play);
            draw(tableau);

            play = menu_play(&tableau, player);
        }

        run_program = 0;
    }
}
