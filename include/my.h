/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    #pragma once
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include <errno.h>
    #include <stdarg.h>
    #include "env.h"
    #include "lib.h"

    #define BLUE  "\x1B[34m"
    #define MAG  "\x1B[35m"
    #define CYAN  "\x1B[36m"
    #define WHITE  "\x1B[37m"
    #define GREEN  "\x1B[32m"
    #define YEL  "\x1B[33m"
    #define RED  "\x1B[31m"

// PARSING
char **split_args(char *line);
char *my_getline(void);
int is_args_setenv(char **argv, env_list_t *env);
int check_cmd_existence(char **argv, char **tab, char **env);

// SIGNAL
int check_signal(int status);

// BUILTIN
int my_cd(char **argv, env_list_t *env);
int my_cd(char **argv, env_list_t *env);
int my_exit(char *arg);
int cd_home(char **argv, env_list_t **head, char *actual, char *home);
int cd_oldpwd(char **argv, env_list_t **head, env_list_t *env, char *actual);
int error_handling_cd_two(char **argv);

void tcshloop(env_list_t *env);
int tcsh_exec(char **argv, env_list_t *env);
int tcsh_processus(char **argv, env_list_t *env);
int child_processus(char **argv, env_list_t *env);

char **list_to_array(env_list_t *env);
void free_env_array(char **env_array);

// ALLOCATION
void free_tokens(char **tab);

char **parse_tokens(char *line);


#endif
