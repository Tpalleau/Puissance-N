#define list_length 20

typedef struct{

    int size;
    char list [list_length][list_length]; //initialize the grid

} grid;

//function for grid.c
void reset(grid *matrix);
void show_grid(grid matrix);

//function for menu_func.c
int menu();
void game_options(int *num_player ,int *grid_size);

//function for play_func.c
int check_draw(grid *matrix);
int check_win(grid *matrix,int player, int column, int *line);
int win_column(grid *matrix, int column);
int win_line(grid *matrix,int column,int *line);
int win_diag(grid *matrix,int column,int *line);
int add_token(grid *tableau, int column, int *line, int player);
int remove_token(grid *tableau, int column);
int menu_play(grid *tableau, int player, int *line, int num_players, int *unusable_column);
void AI(grid *matrix,int *unusable_column);

//function for save_func.c
void save_file(grid matrix, int num_players, int turn, int unusable_column);
void load_file(grid *matrix, int *num_players, int *turn, int *unusable_column);

#ifndef PUISSANCE_N_FUNCTION_H
#define PUISSANCE_N_FUNCTION_H

#endif //PUISSANCE_N_FUNCTION_H
