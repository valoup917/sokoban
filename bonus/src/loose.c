/*
** EPITECH PROJECT, 2021
** loose.c
** File description:
** .
*/

#include "../include/sokoban.h"
void loose_screen(struct my_game *map_all);
void restart_or_quit(struct my_game *map_all);

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
        clear();
        loose_screen(map_all);
        free_all(map_all);
        endwin();
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

void loose_screen(struct my_game *map_all)
{
    char *sl = "You loose";
    char *se = "Press [<-] to exit";
    char *sr = "Press enter to restart";

    attron(A_BOLD | A_UNDERLINE);
    attron(COLOR_PAIR(3));
    box(stdscr, '*', '*');
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(sl) / 2, sl);
    attroff(COLOR_PAIR(3));
    attroff(A_BOLD | A_UNDERLINE);
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 + 3, COLS / 2 - my_strlen(se) / 2 - 20, se);
    attroff(COLOR_PAIR(3));
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2 + 3, COLS / 2 - my_strlen(sr) / 2 + 20, sr);
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);
    restart_or_quit(map_all);
}