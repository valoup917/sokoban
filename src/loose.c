/*
** EPITECH PROJECT, 2021
** loose.c
** File description:
** .
*/

#include <sokoban.h>

void main_loose(struct my_game *map_all)
{
    int n = count_x(map_all);
    int count = 0;

    for (int x = 0;map_all->map[x];x++) {
        for (int y = 0;map_all->map[x][y] != '\0';y++) {
            if (map_all->map[x][y] == 'X' && check_x_box(map_all, x, y) == 1)
                count++;
        }
    }
    if (n == count) {
        refresh();
        print_map(map_all->map);
        endwin();
        free_all(map_all);
        exit(1);
    }
}

int check_x_box(struct my_game *map_all, int x, int y)
{
    int crit = 0;

    if ((map_all->map[x][y - 1] == '#' || map_all->map[x][y - 1] == 'X')
        && (map_all->map[x - 1][y] == '#' || map_all->map[x - 1][y] == 'X'))
        crit++;
    if ((map_all->map[x][y + 1] == '#' || map_all->map[x][y + 1] == 'X')
        && (map_all->map[x - 1][y] == '#' || map_all->map[x - 1][y] == 'X'))
        crit++;
    if ((map_all->map[x][y - 1] == '#' || map_all->map[x][y - 1] == 'X')
        && (map_all->map[x + 1][y] == '#' || map_all->map[x + 1][y] == 'X'))
        crit++;
    if ((map_all->map[x][y + 1] == '#' || map_all->map[x][y + 1] == 'X')
        && (map_all->map[x + 1][y] == '#' || map_all->map[x + 1][y] == 'X'))
        crit++;
    if (crit >= 1)
        return 1;
    return 0;
}

int count_x(struct my_game *map_all)
{
    int x = 0;
    int y = 0;
    int count = 0;

    while (map_all->map[x]) {
        while (map_all->map[x][y] != '\0') {
            if (map_all->map[x][y] == 'X')
                count++;
            y++;
        }
        y = 0;
        x++;
    }
    return count;
}