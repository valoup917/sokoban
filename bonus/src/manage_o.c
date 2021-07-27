/*
** EPITECH PROJECT, 2021
** manage my O
** File description:
** .
*/

#include "../include/sokoban.h"

void manage_my_o(struct my_game *map_all)
{
    int x = 0;
    int y = 0;
    int n = count_my_struct_o(map_all);

    for (int i = 0;i != n;i++) {
        x = map_all->pos_o[i][0];
        y = map_all->pos_o[i][1];
        if (map_all->map[x][y] == 'X') {
            attron(COLOR_PAIR(1));
            map_all->map[x][y] = 'X';
            attroff(COLOR_PAIR(1));
        }
        else if (map_all->map[x][y] != 'P')
            map_all->map[x][y] = 'O';
    }
}

int count_my_o(char **map)
{
    int count = 0;

    for (int x = 0;map[x];x++) {
        for (int y = 0;map[x][y] != '\0';y++) {
            if (map[x][y] == 'O')
                count++;
        }
    }
    return count;
}

int count_my_struct_o(struct my_game *map_all)
{
    int i = 0;
    while (map_all->pos_o[i])
        i++;
    return i;
}

int o_pos_x(char **map)
{
    int x = 0;
    int y = 0;

    while (map[x]) {
        while (map[x][y] != '\0') {
            if (map[x][y] == 'O')
                return x;
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}

int o_pos_y(char **map)
{
    int x = 0;
    int y = 0;

    while (map[x]) {
        while (map[x][y] != '\0') {
            if (map[x][y] == 'O')
                return y;
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}