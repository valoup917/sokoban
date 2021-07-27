/*
** EPITECH PROJECT, 2021
** print x map win
** File description:
** .
*/

#include "../include/sokoban.h"
int check_x_y(struct my_game *map_all, int a, int b);

int check_x_y(struct my_game *map_all, int a, int b)
{
    for (int i = 0;map_all->pos_o[i];i++) {
        if (map_all->pos_o[i][0] == a && map_all->pos_o[i][1] == b)
            return 1;
    }
    return 0;
}

void print_map2(char **map)
{
    int cols_size = 0;
    int lines_size = 0;

    for (;map[lines_size];lines_size++);

    for (int i = 0;map[i];i++) {
        cols_size = my_strlen(map[i]);
        mvprintw(LINES / 2 - lines_size / 2 + i, COLS
        / 2 - cols_size / 2, map[i]);
    }
}

void find_my_o(struct my_game *map_all)
{
    int n = count_my_o(map_all->map);
    int a = 0;

    map_all->pos_o = malloc(sizeof(int *) * (n + 1));
    if (!map_all->pos_o)
        perror("malloc");
    for (int i = 0;map_all->map[i];i++) {
        for (int y = 0;map_all->map[i][y] != '\0';y++) {
            if (map_all->map[i][y] == 'O') {
                map_all->pos_o[a] = malloc(sizeof(int) * 5);
                if (!map_all->pos_o[a])
                    perror("malloc");
                map_all->pos_o[a][0] = i;
                map_all->pos_o[a][1] = y;
                a++;
            }
        }
    }
    map_all->pos_o[a] = NULL;
}