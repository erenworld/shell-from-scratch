/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** read input
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../lib/libmy.h"

char *my_getline(void)
{
    char *input = NULL;
    size_t bufsize = 0;
    size_t input_len;

    if (getline(&input, &bufsize, stdin) == -1) {
        free(input);
        return NULL;
    }
    input_len = strlen(input);
    if (input_len > 0 && input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
    }
    return input;
}
