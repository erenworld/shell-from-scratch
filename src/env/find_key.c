/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** setenv
*/

#include "../../lib/libmy.h"
#include "env.h"
#include <stdlib.h>
#include <unistd.h>

env_list_t *find_key(env_list_t *head, const char *name)
{
    while (head != NULL) {
        if (my_strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
