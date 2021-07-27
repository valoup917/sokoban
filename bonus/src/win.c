/*
** EPITECH PROJECT, 2021
** win
** File description:
** .
*/

#include "../include/sokoban.h"

void win_screen(struct my_game *map_all);
void restart_or_quit(struct my_game *map_all);
void score_end(struct my_game *map_all);
void score_map1(struct my_game *map_all);
void score_map2(struct my_game *map_all);
void score_map3(struct my_game *map_all);

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
        score_end(map_all);
        win_screen(map_all);
        free_all(map_all);
        endwin();
        exit(0);
    }
}

void win_screen(struct my_game *map_all)
{
    char *string_win = "You win";
    char *string_exit = "Press [<-] to exit";
    char *string_restart = "Press enter to restart";

    attron(A_BOLD | A_UNDERLINE);
    attron(COLOR_PAIR(1));
    box(stdscr, '*', '*');
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(string_win) / 2, string_win);
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD | A_UNDERLINE);
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 + 3, COLS / 2 - my_strlen(string_exit)
    / 2 - 20, string_exit);
    attroff(COLOR_PAIR(3));
    attron(A_BOLD);
    mvprintw(LINES / 2 + 3, COLS / 2 - my_strlen(string_restart)
    / 2 + 20, string_restart);
    attroff(A_BOLD);
    restart_or_quit(map_all);
}

void restart_or_quit(struct my_game *map_all)
{
    int a = getch();
    if (a == 263) {
        free_all(map_all);
        endwin();
        exit(0);
    }
    if (a == 10) {
        map_all->map = my_str_to_word_array(map_all->map_origin);
        my_mov(map_all);
    }

}

void score_end(struct my_game *map_all)
{
    clear();
    if (map_all->map_nbr == 1)
        score_map1(map_all);
    if (map_all->map_nbr == 2)
        score_map2(map_all);
    if (map_all->map_nbr == 3)
        score_map3(map_all);
}