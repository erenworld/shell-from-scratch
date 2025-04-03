/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** split args
*/

#include "../include/my.h"

static char *skip_space(char *str)
{
    while (*str && my_isspace(*str))
        str++;
    return str;
}

static char **get_tokens(char *line)
{
    char **tab = NULL;
    char *space = NULL;

    tab = split_string(line, ';');
    if (tab == NULL)
        return NULL;
    for (int i = 0; tab[i]; i++) {
        space = skip_space(tab[i]);
        if (space == NULL)
            return NULL;
        tab[i] = my_strdup(space);
        if (tab[i] == NULL) {
            free_tokens(tab);
            return NULL;
        }
    }
    return tab;
}

char **parse_tokens(char *line)
{
    char **first_tab = get_tokens(line);

    if (first_tab == NULL)
        return NULL;
    return first_tab;
}
