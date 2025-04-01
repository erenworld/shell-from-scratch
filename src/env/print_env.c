/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** printenv
*/

#include "../../lib/libmy.h"
#include "env.h"
#include <stdlib.h>

void my_printenv(env_list_t *head)
{
    env_list_t *temp = head;

    while (temp != NULL) {
        pprintf("%s=%s\n", temp->name, temp->value);
        temp = temp->next;
    }
}
