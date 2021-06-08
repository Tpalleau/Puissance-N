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
    grid tableau;

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

            case 2: break;

            case 3: run_program=0;
                continue;
        }
        // afficher les règles



        //game loop
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
