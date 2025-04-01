/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** my_strncmp
*/

#include "libmy.h"

int my_strncmp(char const *s1, char const *s2, size_t length)
{
    size_t i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    if (i == length)
        return 0;
    return s1[i] - s2[i];
}
