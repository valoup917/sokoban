/*
** EPITECH PROJECT, 2021
** helper.c
** File description:
** .
*/

#include "../include/sokoban.h"

void helper_print2(void);
int my_menu(struct my_game *map_all);

void helper(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file\
representing the warehouse map, containing ‘#’ for walls,\n\t‘P’\
for the player, ‘X’ for boxes and ‘O’ for storage locations.\n");
    return;
}

void helper_print(struct my_game *mapp_all)
{
    char *str1 = "You can move up, down, left and right. You can't pass\
through walls (#) or boxes (X). Your player can push\
only one box at a time, never pull.";
    char *str2 = "The goal is to place all the boxs on the storage\
    location (O), you lose if you can't move any boxes.";

    clear();
    box(stdscr, '?', '?');
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(str1) / 2, str1);
    mvprintw(LINES / 2, COLS / 2 - my_strlen(str2) / 2, str2);
    helper_print2();
    refresh();
    if (getch() == 263) {
        free_all(mapp_all);
        endwin();
        exit(0);
    }
    my_menu(mapp_all);
}

void helper_print2(void)
{
    char *str0 = "Helper";
    char *str3 = "To move use the arrows on your keyboard.";
    char *string1 = "Press [<-] to exit";
    char *string2 = "Press any key to continue";

    attron(COLOR_PAIR(2));
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str0) / 2, str0);
    attroff(COLOR_PAIR(2));
    mvprintw(LINES / 2 + 2, COLS / 2 - my_strlen(str3) / 2, str3);
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(string1) / 2 - 20, string1);
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(string2) / 2 + 20, string2);
    attroff(COLOR_PAIR(1));
}