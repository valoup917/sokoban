/*
** EPITECH PROJECT, 2021
** movement all 1
** File description:
** .
*/

#include <sokoban.h>

int check_map_x_up(struct my_game *map_all)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (map_all->map[x-1][y] == '#')
        return 1;
    if (map_all->map[x-1][y] == 'X' && move_x_up(map_all, x, y) == 1)
        return 1;
    return 0;
}

int move_x_up(struct my_game *map_all, int x, int y)
{
    if (map_all->map[x-2][y] == '#' || map_all->map[x-2][y] == 'X')
        return 1;
    map_all->map[x-2][y] = 'X';
    map_all->map[x-1][y] = ' ';
    return 0;
}

int check_map_x_down(struct my_game *map_all)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (map_all->map[x+1][y] == '#')
        return 1;
    if (map_all->map[x+1][y] == 'X' && move_x_down(map_all, x, y) == 1)
        return 1;
    return 0;
}

int move_x_down(struct my_game *map_all, int x, int y)
{
    if (map_all->map[x+2][y] == '#' || map_all->map[x+2][y] == 'X')
        return 1;
    map_all->map[x+2][y] = 'X';
    map_all->map[x+1][y] = ' ';
    return 0;
}