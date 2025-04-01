/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** free_tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
