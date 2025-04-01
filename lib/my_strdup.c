/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** strdup
*/

#include "libmy.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
    int len = 0;
    char *new;

    if (src == NULL) {
        return NULL;
    }
    for (; src[len] != '\0'; len++);
    new = malloc(len + 1);
    if (new == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        new[i] = src[i];
    }
    new[len] = '\0';
    return new;
}
