/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** my_isspace
*/

#include <ctype.h>

int my_isspace(int chr)
{
    return (chr == ' ' || chr == '\t' ||
            chr == '\n' || chr == '\v' ||
            chr == '\r' || chr == '\f');
}
