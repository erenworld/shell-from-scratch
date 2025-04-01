/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** parser
*/

#include "../src/env/env.h"
#include <stdbool.h>

#ifndef PARSER_H
    #define PARSER_H

void free_tab(char **tab);

int check_signal(int *status);
void free_tokens(char **tab);

char **parse_tokens(char *line, env_list_t *env);
char *my_getline(void);
void tcshloop(env_list_t *env);

int tcsh_exec(char **args, env_list_t *env);
int check_cmd_existence(char **argv, char **tab, char **env);
int exec_path(char **argv, env_list_t *env, char **env_array);
int exec_path_redir(char **argv, env_list_t *env, char **env_array);
void exec_redir_right(char **tab, env_list_t *env, char **env_array);

void remove_quotes(char **args);
char *skip_space(char *str);

#endif
