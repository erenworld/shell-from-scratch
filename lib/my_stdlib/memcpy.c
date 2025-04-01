/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** memcpy
*/

#include "../libmy.h"

void *my_memcpy(void *dest, const void *src, size_t size)
{
    char *c_dest = dest;
    const char *c_src = src;

    for (size_t i = 0; i < size; i++) {
        c_dest[i] = c_src[i];
    }
    return dest;
}
