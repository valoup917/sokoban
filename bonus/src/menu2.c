/*
** EPITECH PROJECT, 2021
** menu2
** File description:
** .
*/

#include "../include/sokoban.h"

int my_menu(struct my_game *map_all);
void map1(void);
void map2(void);
void map3(void);
void map4(void);

void change_map_color(int map)
{
    attron(COLOR_PAIR(1));
    if (map == 1)
        map1();
    if (map == 2)
        map2();
    if (map == 3)
        map3();
    if (map == 4)
        map4();
    attroff(COLOR_PAIR(1));
}

void map1(void)
{
    char *map1 = " mini-map ";
    char *map2 = " normal map ";
    char *map3 = " giant map ";
    char *map4 = "my map";

    attron(A_STANDOUT);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map1) / 2 - 25, map1);
    attroff(A_STANDOUT);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map2) / 2, map2);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map3) / 2 + 25, map3);
    mvprintw(LINES / 2 + 6, COLS / 2 - my_strlen(map4) / 2, map4);
}

void map2(void)
{
    char *map1 = " mini-map ";
    char *map2 = " normal map ";
    char *map3 = " giant map ";
    char *map4 = "my map";

    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map1) / 2 - 25, map1);
    attron(A_STANDOUT);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map2) / 2, map2);
    attroff(A_STANDOUT);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map3) / 2 + 25, map3);
    mvprintw(LINES / 2 + 6, COLS / 2 - my_strlen(map4) / 2, map4);
}

void map3(void)
{
    char *map1 = " mini-map ";
    char *map2 = " normal map ";
    char *map3 = " giant map ";
    char *map4 = "my map";

    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map1) / 2 - 25, map1);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map2) / 2, map2);
    attron(A_STANDOUT);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map3) / 2 + 25, map3);
    attroff(A_STANDOUT);
    mvprintw(LINES / 2 + 6, COLS / 2 - my_strlen(map4) / 2, map4);
}

void map4(void)
{
    char *map1 = " mini-map ";
    char *map2 = " normal map ";
    char *map3 = " giant map ";
    char *map4 = "my map";

    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map1) / 2 - 25, map1);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map2) / 2, map2);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(map3) / 2 + 25, map3);
    attron(A_STANDOUT);
    mvprintw(LINES / 2 + 6, COLS / 2 - my_strlen(map4) / 2, map4);
    attroff(A_STANDOUT);
}