/*
** EPITECH PROJECT, 2021
** main
** File description:
** .
*/

#include <sokoban.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (argc == 2 && argv[1][0] == '-'
        && argv[1][1] == 'h' && argv[1][2] == '\0')
        helper();
    else
        my_algo(argv[1]);
    return 0;
}