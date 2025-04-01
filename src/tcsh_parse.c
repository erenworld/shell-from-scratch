/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** tcsh_parse
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/parser.h"
#include "../lib/libmy.h"
#include "env/env.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

char **parse_tokens(char *line, env_list_t *env)
{
    char **first_tab = get_tokens(line);
    bool check = false;

    if (first_tab == NULL)
        return NULL;
    for (int i = 0; first_tab[i]; i++) {
        if (my_strchr(first_tab[i], '>'))
            check = true;
    }
    if (check)
        exec_redir_right(first_tab, env, list_to_array(env));
    return first_tab;
}
