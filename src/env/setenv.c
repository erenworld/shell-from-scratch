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

static env_list_t *create_node(const char *name, const char *value)
{
    env_list_t *new_node = malloc(sizeof(env_list_t));

    if (!new_node) {
        write(2, "Memory allocation failed in create_node\n", 40);
        return NULL;
    }
    new_node->name = my_strdup(name);
    new_node->value = my_strdup(value);
    new_node->next = NULL;
    return new_node;
}

static void append_to_end(env_list_t **head, env_list_t *new_node,
    env_list_t *temp)
{
    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

static int add_newnode(env_list_t **head, const char *name, const char *value)
{
    env_list_t *new_node = create_node(name, value);
    env_list_t *temp = NULL;

    if (!new_node || !name || !value)
        return 1;
    if (*head == NULL) {
        *head = new_node;
        return 0;
    } else {
        append_to_end(head, new_node, temp);
    }
    return 0;
}

int my_setenv(env_list_t **head, const char *name, const char *value)
{
    env_list_t *is_node_exist = find_key(*head, name);

    if (!name || !value) {
        my_puts("Arguments failed in setenv\n");
        return 1;
    }
    if (is_node_exist) {
        free(is_node_exist->value);
        is_node_exist->value = my_strdup(value);
        return 0;
    }
    return add_newnode(head, name, value);
}
