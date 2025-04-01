/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** array
*/

#include "../include/my.h"

int count_element_list(env_list_t *curr)
{
    int count = 0;

    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

void free_arr_i(char **arr, int i)
{
    while (i) {
        i--;
        free(arr[i]);
    }
    free(arr);
    return;
}

void copy_in_array(env_list_t *curr, char **arr)
{
    size_t len;
    int i = 0;

    while (curr) {
        len = strlen(curr->name) + strlen(curr->value) + 2;
        arr[i] = malloc(len);
        if (!arr[i]) {
            free_arr_i(arr, i);
        }
        my_strcpy(arr[i], curr->name);
        my_strcat(arr[i], "=");
        my_strcat(arr[i], curr->value);
        curr = curr->next;
        i++;
    }
    arr[i] = NULL;
}

char **list_to_array(env_list_t *env)
{
    env_list_t *curr = env;
    int count = count_element_list(curr);
    char **arr = malloc((count + 1) * sizeof(char *));

    if (!arr)
        return NULL;
    copy_in_array(curr, arr);
    return arr;
}
