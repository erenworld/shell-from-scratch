/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** skip_space
*/

#include "../../lib/libmy.h"

char *skip_space(char *str)
{
    while (*str && my_isspace(*str))
        str++;
    return str;
}
