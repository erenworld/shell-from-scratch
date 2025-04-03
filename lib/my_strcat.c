/*
** EPITECH PROJECT, 2024
** day07
** File description:
** strcat
*/
#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
