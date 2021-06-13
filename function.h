#define list_length 20

typedef struct{

    int size;
    char list [list_length][list_length]; //initialisation de la grille de taille N+2

} grid;


void reset(grid *matrix);
void show_grid(grid matrix);

int menu();
void game_options(int *num_player ,int *grid_size);

int win_column(grid *matrix, int column);
int win_line(grid *matrix,int column,int *line);
int win_diag(grid *matrix,int column,int *line);
int add_token(grid *tableau, int column, int *line, int player);
int remove_token(grid *tableau, int column);
int menu_play(grid *tableau, int player, int *line, int num_players, int *unusable_column);
void AI(grid *matrix,int *unusable_column);

void save_file(grid matrix, int num_players, int turn, int unusable_column);
void load_file(grid *matrix, int *num_players, int *turn, int *unusable_column);

#ifndef PUISSANCE_N_FUNCTION_H
#define PUISSANCE_N_FUNCTION_H

#endif //PUISSANCE_N_FUNCTION_H
