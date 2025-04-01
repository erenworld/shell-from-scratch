/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** unsetenv
*/

#include "../../lib/libmy.h"
#include "env.h"
#include <stdlib.h>
#include <unistd.h>

static int delete_node(env_list_t **head, const char *name)
{
    env_list_t *temp = *head;
    env_list_t *prev = NULL;

    if (!head || !name)
        return 1;
    while (temp != NULL) {
        if (my_strcmp(temp->name, name) == 0) {
            prev->next = temp->next;
            free(temp->name);
            free(temp->value);
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

int my_unsetenv(env_list_t **head, const char *name)
{
    if (!name || !head) {
        return 1;
    }
    return delete_node(head, name);
}
