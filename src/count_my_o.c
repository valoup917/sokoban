/*
** EPITECH PROJECT, 2021
** count o
** File description:
** .
*/

#include <sokoban.h>

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