/*
** EPITECH PROJECT, 2021
** manage my O
** File description:
** .
*/

#include <sokoban.h>

void manage_my_o(struct my_game *map_all)
{
    int x = 0;
    int y = 0;
    int n = count_my_struct_o(map_all);

    for (int i = 0;i != n;i++) {
        x = map_all->pos_o[i][0];
        y = map_all->pos_o[i][1];
        if (map_all->map[x][y] != 'P' && map_all->map[x][y] != 'X')
            map_all->map[x][y] = 'O';
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