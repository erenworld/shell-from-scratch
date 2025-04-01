/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** processus handler
*/

#include "../include/my.h"

int tcsh_processus(char **argv, env_list_t *env)
{
    pid_t pid;
    int status;
    int exit_code;

    pid = fork();
    if (pid == -1) {
        return 1;
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        exit_code = check_signal(status);
        return exit_code;
    } else {
        child_processus(argv, env);
        exit(1);
    }
}
