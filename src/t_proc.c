/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** processus handler
*/

#include <fcntl.h>
#include "../include/my.h"

static int exec_path(char **argv, env_list_t *env, char **env_array)
{
    char *path = my_getenv(env, "PATH");
    char **tab;

    if (!path)
        return 1;
    tab = split_string(path, ':');
    if (!tab)
        return 1;
    if (check_cmd_existence(argv, tab, env_array) != 0) {
        free(tab);
        return 1;
    }
    free(tab);
    return 0;
}

static int exec_redir_output(char **argv, char *file, env_list_t *env)
{
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char **env_array = list_to_array(env);

    if (fd == -1)
        return 1;
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        close(fd);
        return 1;
    }
    close(fd);
    if (exec_path(argv, env, env_array) != 0) {
        my_puts(argv[0]);
        my_puts(": Command not found.\n");
        free_env_array(env_array);
        return 127;
    }
    free_env_array(env_array);
    return 0;
}

static int exec_redir_append(char **argv, char *file, env_list_t *env)
{
    int fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    char **env_array = list_to_array(env);

    if (fd == -1)
        return 1;
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        close(fd);
        return 1;
    }
    close(fd);
    if (exec_path(argv, env, env_array) != 0) {
        my_puts(argv[0]);
        my_puts(": Command not found.\n");
        free_env_array(env_array);
        return 127;
    }
    free_env_array(env_array);
    return 0;
}

static int exec_redir_entry(char **argv, char *file, env_list_t *env)
{
    int fd = open(file, O_RDONLY);
    char **env_array = list_to_array(env);

    if (fd == -1)
        return 1;
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        close(fd);
        return 1;
    }
    close(fd);
    if (exec_path(argv, env, env_array) != 0) {
        my_puts(argv[0]);
        my_puts(": Command not found.\n");
        free_env_array(env_array);
        return 127;
    }
    free_env_array(env_array);
    return 0;
}

int handle_redirection(char **argv, env_list_t *env)
{
    for (int i = 0; argv[i]; i++) {
        if (my_strcmp(argv[i], ">") == 0 && argv[i + 1]) {
            argv[i] = NULL;
            return exec_redir_output(argv, argv[i + 1], env);
        }
        if (my_strcmp(argv[i], ">>") == 0 && argv[i + 1]) {
            argv[i] = NULL;
            return exec_redir_append(argv, argv[i + 1], env);
        }
        if (my_strcmp(argv[i], "<") == 0 && argv[i + 1]) {
            argv[i] = NULL;
            return exec_redir_entry(argv, argv[i + 1], env);
        }
    }
    return 1;
}

int tcsh_processus(char **argv, env_list_t *env)
{
    pid_t pid;
    int status;
    int exit_code;

    pid = fork();
    switch (pid) {
        case -1:
            return 1;
        case 0:
            if (handle_redirection(argv, env) == 1)
                child_processus(argv, env);
            return 1;
        default:
            waitpid(pid, &status, 0);
            exit_code = check_signal(status);
            return exit_code;
    }
}
