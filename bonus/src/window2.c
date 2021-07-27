/*
** EPITECH PROJECT, 2021
** window
** File description:
** window
*/

#include "../include/sokoban.h"
void no_map(struct my_game *map_all);

void score_game(struct my_game *map_all)
{
    char *s = "score = 5555";

    attron(COLOR_PAIR(6));
    mvprintw(LINES / 2 , COLS / 2 - my_strlen(map_all->map[0]) -
    my_strlen(s), "score = %d", map_all->score);
    attroff(COLOR_PAIR(6));
}

void free_all(struct my_game *map_all)
{
    sfMusic_destroy(map_all->song);
    sfSound_destroy(map_all->sound);
    sfSoundBuffer_destroy(map_all->buffer);
    free(map_all->map_origin);
    free(map_all->map);
    free(map_all->pos_o);
    free(map_all);
}

void check_my_arg(char *argv, struct my_game *map_all)
{
    int fd = 0;

    if (argv == NULL)
        no_map(map_all);
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        no_map(map_all);
}

void no_map(struct my_game *map_all)
{
    char *string3 = "Press [<-] to exit";

    clear();
    attron(COLOR_PAIR(3));
    box(stdscr, '!', '!');
    attroff(COLOR_PAIR(3));
    attron(A_BOLD);
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen("Map not found")
    / 2, "Map not found");
    attroff(A_BOLD);
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(string3) / 2, string3);
    attroff(COLOR_PAIR(3));
    int a = getch();
    if (a == 263) {
        free_all(map_all);
        endwin();
        exit(0);
    }
    else
        my_algo(NULL);
}