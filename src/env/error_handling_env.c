/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** check if setenv is hereee
*/

#include "../../lib/libmy.h"
#include "env.h"
#include <stdlib.h>
#include <unistd.h>

int is_invalid_setenv_args(char **argv)
{
    if (!my_isalpha(argv[1][0]) && argv[2]) {
        my_puts("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (argv[1] && argv[2] && my_isalpha_str(argv[1])) {
        my_puts("setenv: Variable name must contain "
                "alphanumeric characters.\n");
        return 1;
    }
    if (argv[1] && argv[2] && argv[3]) {
        my_puts("setenv: Too many arguments.\n");
        return 1;
    }
    return 0;
}

int is_args_setenv(char **argv, env_list_t *env)
{
    if (my_strcmp(argv[0], "setenv") == 0) {
        if (is_invalid_setenv_args(argv))
            return 1;
        if (my_isalpha(argv[1][0]) && argv[1] && argv[2]) {
            my_setenv(&env, argv[1], argv[2]);
            return 0;
        }
        if (my_isalpha(argv[1][0]) && argv[1] && !argv[2]) {
            my_setenv(&env, argv[1], "");
            return 0;
        }
    }
    return 1;
}

int is_args_unsetenv(char **argv, env_list_t *env)
{
    if (!argv || !argv[0] || my_strcmp(argv[0], "unsetenv") != 0)
        return 1;
    if (!argv[1]) {
        my_puts("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i]) {
            my_unsetenv(&env, argv[i]);
            continue;
        }
    }
    return 0;
}
