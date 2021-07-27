/*
** EPITECH PROJECT, 2021
** win
** File description:
** .
*/

#include <sokoban.h>

void do_i_win(struct my_game *map_all)
{
    int x = 0;
    int y = 0;
    int cdt = 0;
    int n = count_my_struct_o(map_all);

    for (int i = 0;i != n;i++) {
        x = map_all->pos_o[i][0];
        y = map_all->pos_o[i][1];
        if (map_all->map[x][y] == 'X')
            cdt++;
    }
    if (cdt == n) {
        refresh();
        print_map(map_all->map);
        endwin();
        free_all(map_all);
        exit(0);
    }
}