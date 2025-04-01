/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** tcsh_loop
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/parser.h"
#include "../include/colors.h"
#include "../lib/libmy.h"
#include "env/env.h"

static int tcsh_exec_loop(char **argv, env_list_t *env)
{
    char **cmd = NULL;
    int status = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        cmd = split_string(argv[i], ' ');
        if (cmd && cmd[0]) {
            status = tcsh_exec(cmd, env);
        }
        free_tokens(cmd);
    }
    return status;
}

void tcshloop(env_list_t *env)
{
    char *line = NULL;
    char **argv = NULL;
    int status = 0;

    while (1) {
        if (isatty(STDIN_FILENO))
            pprintf("(%d) | SHELL ʕ•ᴥ•ʔ  > ", status);
        line = my_getline();
        if (!line)
            return;
        argv = parse_tokens(line, env);
        if (!argv) {
            free_tokens(argv);
            break;
        }
        status = tcsh_exec_loop(argv, env);
        free(line);
        free_tokens(argv);
    }
}
