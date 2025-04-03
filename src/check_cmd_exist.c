/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** check_signal
*/

#include "../include/my.h"

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
