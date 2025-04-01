/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** my_strstr
*/

#include "libmy.h"

const char *my_strstr(const char *full_string, const char *substring)
{
    int len = my_strlen(substring);

    if (*substring == '\0')
        return full_string;
    if (*full_string == '\0' || len > my_strlen(full_string)) {
        return NULL;
    }
    while (*full_string) {
        if (my_strlen(full_string) < len)
            return NULL;
        if (my_strncmp(full_string, substring, len) == 0)
            return full_string;
        full_string++;
    }
    return NULL;
}
