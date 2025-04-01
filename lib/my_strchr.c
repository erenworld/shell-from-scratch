/*
** EPITECH PROJECT, 2024
** powerful function
** File description:
** strchr
*/

#include "libmy.h"
#include <stdlib.h>

char *my_strchr(const char *str, int chr)
{
    while (*str != '\0') {
        if (*str == chr) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
