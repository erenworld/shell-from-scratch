/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/parser.h"
#include "../include/colors.h"
#include "../lib/libmy.h"
#include "env/env.h"

void parse_env(env_list_t **head, const char *envstr)
{
    char *equal = my_strchr(envstr, '=');
    char *name = NULL;

    if (equal == NULL)
        return;
    name = malloc(strlen(envstr) + 1);
    if (name == NULL)
        return;
    my_strcpy(name, envstr);
    name[equal - envstr] = '\0';
    my_setenv(head, name, equal + 1);
    free(name);
}

int main(int argc, char **argv, char **environ)
{
    env_list_t *env = NULL;

    (void)argc;
    (void)argv;
    for (char **env_ptr = environ; *env_ptr; env_ptr++)
        parse_env(&env, *env_ptr);
    tcshloop(env);
    free_env(env);
    return 0;
}
