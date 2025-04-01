/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** printenv
*/

#include "../../include/my.h"

void my_printenv(env_list_t *head)
{
    env_list_t *temp = head;

    while (temp != NULL) {
        pprintf("%s=%s\n", temp->name, temp->value);
        temp = temp->next;
    }
}
