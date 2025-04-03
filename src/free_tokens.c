/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** free_args
*/

#include "../include/my.h"

void free_tokens(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
