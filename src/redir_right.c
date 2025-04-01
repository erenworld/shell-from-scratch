/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** redir_right
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/parser.h"
#include "../lib/libmy.h"
#include "env/env.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int open_file(char *file)
{
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
    }
    return fd;
}

static void dup_file(int fd)
{
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        close(fd);
        exit(1);
    }
}

static void exec_cmd(char **args, env_list_t *env, char **env_array)
{
    if (exec_path_redir(args, env, env_array) != 0) {
        my_puts(args[0]);
        my_puts(": Command not found.\n");
        free_env_array(env_array);
        exit(1);
    }
}

static void handle_fork(int fd, char **args, env_list_t *env, char **env_array)
{
    pid_t pid = fork();

    if (pid == 0) {
        dup_file(fd);
        close(fd);
        exec_cmd(args, env, env_array);
    } else if (pid > 0) {
        close(fd);
        wait(NULL);
    } else {
        perror("fork");
        close(fd);
    }
}

static void exec_proc_redir(char **args, char *file, env_list_t *env,
    char **env_array)
{
    int fd = open_file(file);

    if (fd == -1)
        return;
    handle_fork(fd, args, env, env_array);
}

static char **get_tokens_redir(char *line)
{
    char **tab = NULL;
    char *space = NULL;

    tab = split_string(line, '>');
    if (tab == NULL)
        return NULL;
    for (int i = 0; tab[i]; i++) {
        space = skip_space(tab[i]);
        if (space == NULL)
            return NULL;
        tab[i] = my_strdup(space);
        if (tab[i] == NULL) {
            free_tokens(tab);
            return NULL;
        }
    }
    return tab;
}

void exec_redir_right(char **tab, env_list_t *env, char **env_array)
{
    char **second_tab = NULL;
    char *file = NULL;
    char **args = NULL;

    for (int i = 0; tab[i]; i++) {
        if (!my_strchr(tab[i], '>'))
            return;
        second_tab = get_tokens_redir(tab[i]);
        if (second_tab == NULL)
            return;
        if (second_tab[1])
            file = second_tab[1];
        args = split_string(second_tab[0], ' ');
        if (args == NULL)
            return;
        remove_quotes(args);
        exec_proc_redir(args, file, env, env_array);
        return;
    }
}
