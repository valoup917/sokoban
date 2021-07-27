/*
** EPITECH PROJECT, 2021
** map management
** File description:
** .
*/

#include "../include/sokoban.h"
void print_char_map(char c, int lines_size, int cols_size, int i, int y);
int check_x_y(struct my_game *map_all, int a, int b);
void print_char_map_easter_egg(char c, int lines, int cols, int i, int y);

void check_my_map(char *string)
{
    for (int i = 0;string[i] != '\0';i++) {
        if (string[i] != ' ' && string[i] != '\n' && string[i] != 'P' &&
        string[i] != 'O' && string[i] != '#' && string[i] != 'X') {
            write(2, "invalide map\n", 13);
            exit(84);
        }
    }
}

int map_y_size(struct my_game *map_all)
{
    int max = 0;
    int tmp = 0;

    for (int i = 0;map_all->map[i];i++) {
        tmp = my_strlen(map_all->map[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

int map_x_size(struct my_game *map_all)
{
    int i = 0;

    for (;map_all->map[i];i++);
    return i;
}

void print_map(char **map, struct my_game *map_all)
{
    int cols_size = 0;
    int lines_size = 0;

    for (; map[lines_size]; lines_size++);
    for (int i = 0;map[i];i++) {
        for (int y = 0;map[i][y] != '\0';y++) {
            cols_size = my_strlen(map[i]);
            mvprintw(LINES / 2 - lines_size / 2 + i, COLS
            / 2 - cols_size / 2 + y, "%c", map[i][y]);
            print_char_map(map[i][y], lines_size, cols_size, i, y);
            if (map[i][y] == 'X' && check_x_y(map_all, i, y) == 1) {
                attron(COLOR_PAIR(1));
                mvaddch(LINES / 2 - lines_size / 2 + i, COLS
                / 2 - cols_size / 2 + y, map[i][y]);
                attroff(COLOR_PAIR(1));
            } else if (map[i][y] == 'X' && check_x_y(map_all, i, y) == 0)
                mvaddch(LINES / 2 - lines_size / 2 + i, COLS
                / 2 - cols_size / 2 + y, map[i][y]);
        }
        printw("\n");
    }
}

void print_map_easter_egg(char **map, struct my_game *map_all)
{
    int cols_size = 0;
    int lines_size = 0;

    for (; map[lines_size]; lines_size++);
    for (int i = 0;map[i];i++) {
        for (int y = 0;map[i][y] != '\0';y++) {
            cols_size = my_strlen(map[i]);
            mvprintw(LINES / 2 - lines_size / 2 + i, COLS
            / 2 - cols_size / 2 + y, "%c", map[i][y]);
            print_char_map_easter_egg(map[i][y], lines_size, cols_size, i, y);
            if (map[i][y] == 'X' && check_x_y(map_all, i, y) == 1) {
                attron(COLOR_PAIR(3));
                mvaddch(LINES / 2 - lines_size / 2 + i, COLS
                / 2 - cols_size / 2 + y, map[i][y]);
                attroff(COLOR_PAIR(3));
            } else if (map[i][y] == 'X' && check_x_y(map_all, i, y) == 0)
                mvaddch(LINES / 2 - lines_size / 2 + i, COLS
                / 2 - cols_size / 2 + y, map[i][y]);
        }
        printw("\n");
    }
}

void print_char_map_easter_egg(char c, int lines, int cols, int i, int y)
{
    if (c == '#') {
        attron(COLOR_PAIR(7));
        mvaddch(LINES / 2 - lines / 2 + i, COLS / 2 - cols / 2 + y, c);
        attroff(COLOR_PAIR(7));
    }
    else if (c == 'O') {
        attron(COLOR_PAIR(3));
        mvaddch(LINES / 2 - lines / 2 + i, COLS / 2 - cols / 2 + y, c);
        attroff(COLOR_PAIR(3));
    }
}


void print_char_map(char c, int lines, int cols, int i, int y)
{
    if (c == '#') {
        attron(COLOR_PAIR(4));
        mvaddch(LINES / 2 - lines / 2 + i, COLS / 2 - cols / 2 + y, c);
        attroff(COLOR_PAIR(4));
    }
    else if (c == 'O') {
        attron(COLOR_PAIR(3));
        mvaddch(LINES / 2 - lines / 2 + i, COLS / 2 - cols / 2 + y, c);
        attroff(COLOR_PAIR(3));
    }
}