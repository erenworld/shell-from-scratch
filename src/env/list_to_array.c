/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** list_to_array
*/
#include "../../lib/libmy.h"
#include "env.h"
#include <stdlib.h>

static int count_element_list(env_list_t *curr)
{
    int count = 0;

    while (curr != NULL) {
        count += 1;
        curr = curr->next;
    }
    return count;
}

static void free_arr_i(char **arr, int i)
{
    while (i) {
        i--;
        free(arr[i]);
    }
    free(arr);
}

static void copy_in_array(env_list_t *curr, char **arr)
{
    int len;
    int i = 0;

    while (curr != NULL) {
        len = my_strlen(curr->name) + my_strlen(curr->value) + 2;
        arr[i] = malloc(len);
        if (!arr[i]) {
            free_arr_i(arr, i);
        }
        my_strcpy(arr[i], curr->name);
        my_strcpy(arr[i], "=");
        my_strcpy(arr[i], curr->value);
        curr = curr->next;
        i++;
    }
    arr[i] = NULL;
}

char **list_to_array(env_list_t *env)
{
    env_list_t *curr = env;
    int count = count_element_list(curr);
    char **arr = malloc(sizeof(char *) * (count + 1));

    if (!arr) {
        return NULL;
    }
    copy_in_array(curr, arr);
    return arr;
}
