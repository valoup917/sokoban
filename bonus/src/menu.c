/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** .
*/

#include "../include/sokoban.h"

void put_my_text(void);
int choose_my_map(int map, int a);
void change_map_color(int map);
void helper_print(struct my_game *mapp_all);
void manage_my_input(int a, struct my_game *mapp_all);
void helper_print2(void);

int my_menu(struct my_game *map_all)
{
    fill_my_sound(map_all);
    int map = 1;
    for (int a = 'z';a != 10;a = getch()) {
        clear();
        box(stdscr, '~', '|');
        map = choose_my_map(map, a);
        map_all->map_nbr = map;
        manage_my_input(a, map_all);
        change_map_color(map);
        put_my_text();
        refresh();
    }
    return map;
}

void manage_my_input(int a, struct my_game *mapp_all)
{
    if (a == 263) {
        free_all(mapp_all);
        endwin();
        exit(0);
    }
    if (a == 'h')
        helper_print(mapp_all);
}

int choose_my_map(int map, int a)
{
    if (a == KEY_RIGHT && map < 4)
        map++;
    else if (a == KEY_LEFT && map > 1)
        map--;
    return map;
}

void put_my_text(void)
{
    char *string1 = "Welcome to my_sokoban";
    char *string2 = "Press [H] to learn how to play";
    char *string3 = "Press [<-] to exit";
    char *string4 = "Choose a map :";

    attron(A_BOLD | A_UNDERLINE);
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(string1) / 2, string1);
    attroff(A_BOLD | A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvprintw(LINES / 2 - 3, COLS / 2 - my_strlen(string2) / 2, string2);
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen(string3) / 2, string3);
    attroff(COLOR_PAIR(3));
    mvprintw(LINES / 2 + 1, COLS / 2 - my_strlen(string4) / 2, string4);
}