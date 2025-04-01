/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/

#include "libmy.h"

int my_isalpha(char s)
{
    return ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) ? 1 : 0;
}

int my_isalpha_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')) {
            i++;
        } else {
            return 1;
        }
    }
    return 0;
}
