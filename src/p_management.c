/*
** EPITECH PROJECT, 2021
** p management
** File description:
** .
*/

#include <sokoban.h>

void print_my_p(struct my_game *map_all)
{
    int x = 0;
    int y = 0;

    for (; x != map_all->pos_x_p; x++);
    for (; y != map_all->pos_y_p; y++);
    map_all->map[x][y] = 'P';
}

void move_p(struct my_game *map_all, int a)
{
    if (a == KEY_UP && check_map_x_up(map_all) == 0) {
        p_suppression(map_all);
        map_all->pos_x_p -= 1;
    }
    if (a == KEY_DOWN && check_map_x_down(map_all) == 0) {
        p_suppression(map_all);
        map_all->pos_x_p += 1;
    }
    if (a == KEY_LEFT && check_map_y_left(map_all) == 0) {
        p_suppression(map_all);
        map_all->pos_y_p -= 1;
    }
    if (a == KEY_RIGHT && check_map_y_right(map_all) == 0) {
        p_suppression(map_all);
        map_all->pos_y_p += 1;
    }
    if (a == 32) {
        map_all->map = my_str_to_word_array(map_all->map_origin);
        my_mov(map_all);
    }
}

void p_suppression(struct my_game *map_all)
{
    int x = 0;
    int y = 0;

    while (map_all->map[x]) {
        while (map_all->map[x][y] != '\0') {
            if (map_all->map[x][y] == 'P') {
                map_all->map[x][y] = ' ';
            }
            y++;
        }
        y = 0;
        x++;
    }
}

int p_pos_x(char **map)
{
    int x = 0;
    int y = 0;

    while (map[x]) {
        while (map[x][y] != '\0') {
            if (map[x][y] == 'P')
                return x;
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}

int p_pos_y(char **map)
{
    int x = 0;
    int y = 0;

    while (map[x]) {
        while (map[x][y] != '\0') {
            if (map[x][y] == 'P')
                return y;
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}