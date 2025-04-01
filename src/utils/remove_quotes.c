/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** remove_quotes
*/

#include "../../lib/libmy.h"

static char *skip_quotes(char *string)
{
    int len = my_strlen(string);

    if (len < 2)
        return string;
    if (string[0] == '"' && string[len - 1] == '"') {
        string[len - 1] = '\0';
        return string + 1;
    }
    return string;
}

void remove_quotes(char **args)
{
    for (int i = 0; args[i]; i++) {
        args[i] = skip_quotes(args[i]);
    }
}
