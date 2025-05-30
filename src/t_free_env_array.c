/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** free env array
*/

#include "../include/my.h"

void free_env_array(char **env_array)
{
    if (!env_array)
        return;
    for (int i = 0; env_array[i] != NULL; i++)
        free(env_array[i]);
    free(env_array);
}
