/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** free
*/

#include "../../include/my.h"

void free_env(env_list_t *head)
{
    env_list_t *temp = head;
    env_list_t *next;

    while (temp != NULL) {
        next = temp->next;
        free(temp->name);
        free(temp->value);
        free(temp);
        temp = next;
    }
}
