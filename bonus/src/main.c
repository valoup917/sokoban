/*
** EPITECH PROJECT, 2021
** main
** File description:
** .
*/

#include "../include/sokoban.h"
int my_menu(struct my_game *map_all);
void score_game(struct my_game *map_all);
void check_my_arg(char *argv, struct my_game *map_all);
void easter_egg_administration(struct my_game *map_all, const char *path, int p);
void check_easter_egg2(struct my_game *map_all, int a);
void print_map_easter_egg(char **map, struct my_game *map_all);

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' &&
        argv[1][1] == 'h' && argv[1][2] == '\0')
        helper();
    if (argc == 1)
        my_algo(NULL);
    else
        my_algo(argv[1]);
    return 0;
}

char *open_read_file(char const *filepath)
{
    struct stat buf;
    char *string;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "map not found\n", 14);
        endwin();
        exit(84);
    }
    stat(filepath, &buf);
    string = malloc(sizeof(char)*(buf.st_size+1));
    if (!string)
        exit(84);
    if (read(fd, string, buf.st_size) == -1) {
        write(2, "map can't be read\n", 18);
        endwin();
        exit(84);
    }
    string[buf.st_size] = '\0';
    close(fd);
    return string;
}

void my_algo(char *argv)
{
    int choice = 0;
    struct my_game *map_all = malloc(sizeof(struct my_game));
    if (!map_all)
        exit(84);
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_RED);
    move(LINES - 1, COLS - 1);
    keypad(stdscr, TRUE);

    choice = my_menu(map_all);
    if (choice == 1)
        map_all->map_origin = open_read_file("map/map1.txt");
    if (choice == 2)
        map_all->map_origin = open_read_file("map/map2.txt");
    if (choice == 3)
        map_all->map_origin = open_read_file("map/map3.txt");
    if (choice == 4) {
        check_my_arg(argv, map_all);
        map_all->map_origin = open_read_file(argv);
    }

    check_my_map(map_all->map_origin);
    map_all->map = my_str_to_word_array(map_all->map_origin);
    map_all->song = sfMusic_createFromFile("songs/naruto.wav");
    //sfMusic_play(map_all->song);

    my_window(map_all);
}

int my_window(struct my_game *map_all)
{
    int cols_size = my_strlen("ANGRANDI LA FENETRE");
    int x;
    int y;
    int x_map = map_x_size(map_all);
    int y_map = map_y_size(map_all);

    clear();
    refresh();
    getmaxyx(stdscr, x, y);
    while (x < x_map || y < y_map) {
        getmaxyx(stdscr, x, y);
        clear();
        mvprintw(LINES / 2, COLS / 2 - cols_size / 2, "ANGRANDIS LA FENETRE");
        refresh();
    }
    my_mov(map_all);
    return 0;
}

void check_easter_egg(struct my_game *map_all, int a)
{
    int nbr = map_all->map_nbr;
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (nbr == 3 && x == 19 && y == 1 && a == KEY_DOWN) {
        easter_egg_administration(map_all, "map/easter1.txt", 1);
    }
}

void check_easter_eggbis(struct my_game *map_all, int a)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (x == 1 && y == 76 && a == KEY_RIGHT)
        easter_egg_administration(map_all, "map/easter1bis.txt", 2);
}

void check_easter_eggbis2(struct my_game *map_all, int a)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (x == 1 && y == 113 && a == KEY_RIGHT)
        easter_egg_administration(map_all, "map/easter1bis2.txt", 3);
}

void check_easter_egg2(struct my_game *map_all, int a)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;
    if (x == 1 && y == 74 && a == KEY_RIGHT)
        easter_egg_administration(map_all, "map/easter2.txt", 4);
}

void check_back(struct my_game *map_all, int a)
{
    int x = map_all->pos_x_p;
    int y = map_all->pos_y_p;

    if (x == 5 && y == 168 && a == KEY_RIGHT) {
        map_all->map_origin = open_read_file("map/secret_map.txt");
        map_all->map = my_str_to_word_array(map_all->map_origin);
        my_mov(map_all);
    }
}

void easter_egg_administration(struct my_game *map_all, const char *path, int p)
{
    clear();
    map_all->map_origin = open_read_file(path);
    map_all->map = my_str_to_word_array(map_all->map_origin);
    map_all->pos_x_p = p_pos_x(map_all->map);
    map_all->pos_y_p = p_pos_y(map_all->map);
    print_map_easter_egg(map_all->map, map_all);
    for (int a = 'z';a != KEY_F(2);a = getch()) {
        clear();
        move_p(map_all, a);
        print_my_p(map_all);
        print_map_easter_egg(map_all->map, map_all);
        if (p == 1)
            check_easter_eggbis(map_all, a);
        if (p == 2)
            check_easter_eggbis2(map_all, a);
        if (p == 3)
            check_easter_egg2(map_all, a);
        if (p == 4)
            check_back(map_all, a);
        refresh();
    }
}

void my_mov(struct my_game *map_all)
{
    map_all->score = 0;
    map_all->pos_x_p = p_pos_x(map_all->map);
    map_all->pos_y_p = p_pos_y(map_all->map);
    find_my_o(map_all);
    print_map(map_all->map, map_all);
    do_i_win(map_all);
    main_loose(map_all);
    for (int a = 'z';a != KEY_F(2);a = getch()) {
        clear();
        check_easter_egg(map_all, a);
        move_p(map_all, a);
        print_my_p(map_all);
        manage_my_o(map_all);
        print_map(map_all->map, map_all);
        score_game(map_all);
        do_i_win(map_all);
        main_loose(map_all);
        refresh();
    }
}