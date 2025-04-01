/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** child
*/

#include "../include/my.h"

void handle_exec_error(char **argv)
{
    if (errno == ENOEXEC) {
        my_puts(argv[0]);
        my_puts(": Exec format error. Binary file not executable.\n");
    }
    if (errno == ENOENT) {
        my_puts(argv[0]);
        my_puts(": Command not found.\n");
    }
    if (errno == EACCES) {
        my_puts(argv[0]);
        my_puts(": Permission denied.\n");
    }
}

int exec_direct(char **argv, char **env_array)
{
    if (!argv)
        return 1;
    if (argv[0][0] == '/' || argv[0][0] == '.' || access(argv[0], X_OK) == 0) {
        if (execve(argv[0], argv, env_array) == -1) {
            handle_exec_error(argv);
            exit(1);
        }
        free_env_array(env_array);
        exit(1);
    }
    return 1;
}

int exec_path(char **argv, env_list_t *env, char **env_array)
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

int child_processus(char **argv, env_list_t *env)
{
    char **env_array = list_to_array(env);

    if (!env_array)
        exit(1);
    if (exec_direct(argv, env_array) == 0)
        return 0;
    if (exec_path(argv, env, env_array) != 0) {
        free_env_array(env_array);
        exit(1);
    }
    free_env_array(env_array);
    return 0;
}
