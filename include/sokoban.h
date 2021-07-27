/*
** EPITECH PROJECT, 2021
** include
** File description:
** .
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct my_game
{
    char *map_origin;
    char **map;
    int pos_x_p;
    int pos_y_p;
    int **pos_o;
} my_game1;

/*LIB*/
char **my_str_to_word_array(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

/*SRC*/
/*main.c*/
char *open_read_file(char const *filepath);
void my_algo(char const *file);
int my_window(struct my_game *map_all);
void free_all(struct my_game *map_all);
void my_mov(struct my_game *map_all);

/*helper*/
void helper(void);

/*win*/
void do_i_win(struct my_game *map_all);

/*loose*/
void main_loose(struct my_game *map_all);
int check_x_box(struct my_game *map_all, int x, int y);
int count_x(struct my_game *map_all);

/*manage_o*/
void manage_my_o(struct my_game *map_all);
int count_my_o(char **map);
int count_my_struct_o(struct my_game *map_all);
void find_my_o(struct my_game *map_all);
int o_pos_x(char **map);
int o_pos_y(char **map);

/*map_management*/
void check_my_map(char *string);
int map_y_size(struct my_game *map_all);
int map_x_size(struct my_game *map_all);
void print_map(char **map);

/*my_movement1*/
int check_map_x_up(struct my_game *map_all);
int move_x_up(struct my_game *map_all, int x, int y);
int check_map_x_down(struct my_game *map_all);
int move_x_down(struct my_game *map_all, int x, int y);

/*my_movement2*/
int check_map_y_left(struct my_game *map_all);
int move_x_left(struct my_game *map_all, int x, int y);
int check_map_y_right(struct my_game *map_all);
int move_x_right(struct my_game *map_all, int x, int y);

/*p_management*/
void print_my_p(struct my_game *map_all);
void move_p(struct my_game *map_all, int a);
void p_suppression(struct my_game *map_all);
int p_pos_x(char **map);
int p_pos_y(char **map);