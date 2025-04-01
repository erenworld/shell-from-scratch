/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/

#include "libmy.h"

int my_strlen(char const *str)
{
    int index = 0;
    int length = 0;

    while (str[index] != '\0') {
        length++;
        index++;
    }
    return length;
}
