/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** .
*/

#include "../include/sokoban.h"

int nbr_letters(char *str)
{
    int a = 0;

    for (;str[a] != '\n';a++);
    return a;
}

int nb_words(char *str)
{
    int x = 0;

    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] == '\n' && str[i - 1] == '\n')
            break;
        if (str[i] == '\n') {
            x++;
        }
    }
    return x;
}

int is_good(char c)
{
    if ((c == ' ' || c == '#' || c == 'O' || c == 'X' || c == 'P'))
        return (1);
    else
        return (0);
}

char **my_str_to_word_array(char *str)
{
    int nbr_words = nb_words(str);
    char **new = malloc(sizeof(char *) * (nbr_words + 100));
    if (!new)
        perror("malloc");
    int k = 0;
    int y = 0;
    int i = 0;

    for (;i < nbr_words;i++) {
        while (is_good(str[k]) != 1)
            k++;
        if (is_good(str[k]) == 1)
            new[i] = malloc(sizeof(char)*(nbr_letters(str) + 100));
                if (!new[i])
                    perror("malloc");
        while (is_good(str[k]) == 1) {
            new[i][y] = str[k];
            k++;
            y++;
        }
        new[i][y] ='\0';
        y = 0;
    }
    new[i] = NULL;
    return new;
}