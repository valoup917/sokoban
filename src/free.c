/*
** EPITECH PROJECT, 2021
** free
** File description:
** .
*/

#include <sokoban.h>

void free_all(struct my_game *map_all)
{
    free(map_all->map_origin);
    free(map_all->map);
    free(map_all->pos_o);
    free(map_all);
}