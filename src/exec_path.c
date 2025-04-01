/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** exec_path
*/

#include "../include/parser.h"
#include "../include/colors.h"
#include "../lib/libmy.h"
#include "builtin/builtin.h"
#include "env/env.h"
#include <stdlib.h>
#include <unistd.h>

int check_cmd_existence(char **argv, char **tab, char **env)
{
    char *cmd;

    if (!tab || !argv || !argv[0])
        return 1;
    for (int i = 0; tab[i] != NULL; i++) {
        cmd = malloc(my_strlen(tab[i]) + my_strlen(argv[0]) + 2);
        if (!cmd)
            return 1;
        my_strcpy(cmd, tab[i]);
        my_strcat(cmd, "/");
        my_strcat(cmd, argv[0]);
        if (access(cmd, X_OK) == 0) {
            execve(cmd, argv, env);
            free(cmd);
            return 1;
        }
        free(cmd);
    }
    return 1;
}

int exec_path(char **argv, env_list_t *env, char **env_array)
{
    char *path = my_getenv(env, "PATH");
    char **tab;

    if (!path)
        return 1;
    tab = split_string(path, ':');
    if (!tab)
        return 1;
    if (check_cmd_existence(argv, tab, env_array) != 0) {
        free(tab);
        return 1;
    }
    free(tab);
    return 0;
}

int exec_path_redir(char **argv, env_list_t *env, char **env_array)
{
    char *path = my_getenv(env, "PATH");
    char **tab;

    if (!path)
        return 1;
    tab = split_string(path, ':');
    if (!tab)
        return 1;
    if (check_cmd_existence(argv, tab, env_array) != 0) {
        free(tab);
        return 1;
    }
    free(tab);
    return 0;
}
