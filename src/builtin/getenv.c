/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** getenv
*/

#include "../../include/my.h"

char *my_getenv(env_list_t *env, const char *key)
{
    env_list_t *current = env;

    if (!env || !key)
        return NULL;
    while (current != NULL) {
        if (my_strcmp(current->name, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
