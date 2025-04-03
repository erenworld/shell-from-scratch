/*
** EPITECH PROJECT, 2024
** powerful function
** File description:
** strchr
*/

#include "../include/my.h"

char *my_strchr(const char *str, int searched_char)
{
    while (*str != '\0') {
        if (*str == searched_char) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
