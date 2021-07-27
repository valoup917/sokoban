/*
** EPITECH PROJECT, 2021
** final score
** File description:
** .
*/

#include "../include/sokoban.h"

void score_map1(struct my_game *map_all)
{
    char *str = "Horrible!     (score = 5555)";

    attron(COLOR_PAIR(5));
    attron(A_BOLD);
    if (map_all->score <= 30)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "PERFECT!     (score = %d)", map_all->score);
    else if (map_all->score <= 34)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "GOOD!     (score = %d)", map_all->score);
    else if (map_all->score <= 38)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "BAD!     (score = %d)", map_all->score);
    else
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "HORRIBLE!     (score = %d)", map_all->score);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(5));
}

void score_map2(struct my_game *map_all)
{
    char *str = "Horrible!     (score = 5555)";

    attron(COLOR_PAIR(5));
    attron(A_BOLD);
    if (map_all->score <= 103)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "PERFECT!     (score = %d)", map_all->score);
    else if (map_all->score <= 110)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "GOOD!     (score = %d)", map_all->score);
    else if (map_all->score <= 117)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "BAD!     (score = %d)", map_all->score);
    else
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "HORRIBLE!     (score = %d)", map_all->score);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(5));
}

void score_map3(struct my_game *map_all)
{
    char *str = "Horrible!     (score = 5555)";

    attron(COLOR_PAIR(5));
    attron(A_BOLD);
    if (map_all->score <= 600)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "PERFECT!     (score = %d)", map_all->score);
    else if (map_all->score <= 620)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "GOOD!     (score = %d)", map_all->score);
    else if (map_all->score <= 650)
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "BAD!     (score = %d)", map_all->score);
    else
        mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(str) / 2,
        "HORRIBLE!     (score = %d)", map_all->score);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(5));
}