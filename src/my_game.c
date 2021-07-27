/*
** EPITECH PROJECT, 2021
** main
** File description:
** .
*/

#include <sokoban.h>

char *open_read_file(char const *filepath)
{
    struct stat buf;
    char *string;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "map not found\n", 14);
        exit(84);
    }
    stat(filepath, &buf);
    string = malloc(sizeof(char)*(buf.st_size+1));
    if (!string)
        perror("malloc");
    if (read(fd, string, buf.st_size) == -1) {
        write(2, "map can't be read\n", 18);
        exit(84);
    }
    string[buf.st_size] = '\0';
    close(fd);
    return string;
}

void my_algo(char const *file)
{
    struct my_game *map_all = malloc(sizeof(struct my_game));
    if (!map_all)
        perror("malloc");

    map_all->map_origin = open_read_file(file);
    check_my_map(map_all->map_origin);
    map_all->map = my_str_to_word_array(map_all->map_origin);
    my_window(map_all);
}

int my_window(struct my_game *map_all)
{
    int cols_size = my_strlen("ANGRANDI LA FENETRE");
    int x;
    int y;
    int x_map = map_x_size(map_all);
    int y_map = map_y_size(map_all);

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, x, y);
    while (x < x_map || y < y_map) {
        getmaxyx(stdscr, x, y);
        clear();
        mvprintw(LINES / 2, COLS / 2 - cols_size / 2, "ANGRANDI LA FENETRE");
        refresh();
    }
    my_mov(map_all);
    endwin();
    return 0;
}

void my_mov(struct my_game *map_all)
{
    map_all->pos_x_p = p_pos_x(map_all->map);
    map_all->pos_y_p = p_pos_y(map_all->map);
    find_my_o(map_all);
    print_map(map_all->map);
    do_i_win(map_all);
    main_loose(map_all);
    for (int a = 'z';a != KEY_F(2);a = getch()) {
        clear();
        move_p(map_all, a);
        print_my_p(map_all);
        manage_my_o(map_all);
        print_map(map_all->map);
        do_i_win(map_all);
        main_loose(map_all);
        refresh();
    }
}