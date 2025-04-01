/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** tcsh_exec
*/

#include "../include/parser.h"
#include "../include/colors.h"
#include "../lib/libmy.h"
#include "builtin/builtin.h"
#include "env/env.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

static int exec_child_proc(env_list_t *env, char **argv)
{
    char **env_array = list_to_array(env);

    if (exec_path(argv, env, env_array) != 0) {
        my_puts(argv[0]);
        my_puts(": Command not found.\n");
        free_env_array(env_array);
        return 127;
    }
    return 0;
}

static int tcsh_processus(char **argv, env_list_t *env)
{
    pid_t pid;
    int status;
    int exit_code;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        exit_code = check_signal(&status);
        return exit_code;
    } else {
        exit_code = exec_child_proc(env, argv);
        return exit_code;
    }
}

int tcsh_exec(char **argv, env_list_t *env)
{
    int code;

    if (!argv) {
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
