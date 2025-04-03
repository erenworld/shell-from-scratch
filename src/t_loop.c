/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** loop
*/

#include "../include/my.h"

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
    int last_status = 0;

    while (1) {
        if (isatty(STDIN_FILENO))
            pprintf("%s[%d] | %serenpadex%s@%s/home/eren/ʕ•ᴥ•ʔ>%s ",
            RED, last_status, GREEN, YEL, BLUE, WHITE);
        line = my_getline();
        if (!line)
            return;
        argv = parse_tokens(line);
        if (!argv) {
            free_tokens(argv);
            break;
        }
        last_status = tcsh_exec_loop(argv, env);
        free(line);
        free_tokens(argv);
    }
}
