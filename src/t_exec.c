/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** exec
*/

#include "../include/my.h"
#include <fcntl.h>

static int tcsh_exec_builtins(char **argv, env_list_t *env)
{
    if (!argv || !argv[0])
        return 1;
    if (my_strcmp(argv[0], "exit") == 0) {
        if (argv[1] != NULL)
            my_exit(argv[1]);
        else
            my_exit(NULL);
    }
    if (my_strcmp(argv[0], "cd") == 0)
        return my_cd(argv, env);
    if (my_strcmp(argv[0], "env") == 0) {
        my_printenv(env);
        return 0;
    }
    if (my_strcmp(argv[0], "setenv") == 0 && !argv[1]) {
        my_printenv(env);
        return 0;
    }
    return 1;
}

int tcsh_exec(char **argv, env_list_t *env)
{
    int code;

    if (!argv || !argv[0]) {
        return 1;
    }
    code = tcsh_exec_builtins(argv, env);
    if (code != 1)
        return code;
    if (is_args_setenv(argv, env) == 0)
        return 0;
    if (is_args_unsetenv(argv, env) == 0)
        return 0;
    return tcsh_processus(argv, env);
}
