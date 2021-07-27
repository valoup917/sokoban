/*
** EPITECH PROJECT, 2021
** map management
** File description:
** .
*/

#include <sokoban.h>

void check_my_map(char *string)
{
    for (int i = 0;string[i] != '\0';i++) {
        if (string[i] != ' ' && string[i] != '\n' && string[i] != 'P' &&
        string[i] != 'O' && string[i] != '#' && string[i] != 'X') {
            write(2, "invalide map\n", 13);
            exit(84);
        }
    }
}

int map_y_size(struct my_game *map_all)
{
    int max = 0;
    int tmp = 0;

    for (int i = 0;map_all->map[i];i++) {
        tmp = my_strlen(map_all->map[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

int map_x_size(struct my_game *map_all)
{
    int i = 0;

    for (;map_all->map[i];i++);
    return i;
}

void print_map(char **map)
{
    int cols_size = 0;
    int lines_size = 0;

    for (;map[lines_size];lines_size++);

    for (int i = 0;map[i];i++) {
        cols_size = my_strlen(map[i]);
        mvprintw(LINES / 2 - lines_size / 2 + i,
        COLS / 2 - cols_size / 2, map[i]);
    }
}