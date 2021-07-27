/*
** EPITECH PROJECT, 2021
** movement all 2
** File description:
** .
*/

#include "../include/sokoban.h"

int check_map_y_left(struct my_game *map_all)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (map_all->map[x][y-1] == '#')
        return 1;
    if (map_all->map[x][y-1] == 'X' && move_x_left(map_all, x, y) == 1)
        return 1;
    return 0;
}

int move_x_left(struct my_game *map_all, int x, int y)
{
    if (map_all->map[x][y-2] == '#' || map_all->map[x][y - 2] == 'X')
        return 1;
    if (map_all->map[x][y-2] == 'O')
        sfSound_play(map_all->sound);
    map_all->map[x][y-2] = 'X';
    map_all->map[x][y-1] = ' ';
    return 0;
}

int check_map_y_right(struct my_game *map_all)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (map_all->map[x][y+1] == '#')
        return 1;
    if (map_all->map[x][y+1] == 'X' && move_x_right(map_all, x, y) == 1)
        return 1;
    return 0;
}

int move_x_right(struct my_game *map_all, int x, int y)
{
    if (map_all->map[x][y+2] == '#' || map_all->map[x][y + 2] == 'X')
        return 1;
    if (map_all->map[x][y+2] == 'O')
        sfSound_play(map_all->sound);
    map_all->map[x][y+2] = 'X';
    map_all->map[x][y+1] = ' ';
    return 0;
}

void fill_my_sound(struct my_game *map_all)
{
    map_all->buffer = sfSoundBuffer_createFromFile("songs/win.wav");
    map_all->sound = sfSound_create();
    sfSound_setBuffer(map_all->sound, map_all->buffer);
    sfSound_setVolume(map_all->sound, 30);
}