/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** realloc
*/

#include <stdlib.h>
#include "../libmy.h"

void *my_realloc(void *ptr, size_t old_size, size_t size)
{
    void *newptr;

    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(size);
    newptr = malloc(size);
    if (newptr == NULL)
        return NULL;
    my_memcpy(newptr, ptr, (old_size < size) ? old_size : size);
    free(ptr);
    return newptr;
}
