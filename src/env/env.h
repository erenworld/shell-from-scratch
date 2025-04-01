/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** env
*/

#ifndef ENV_H
    #define ENV_H

typedef struct env_list_s {
    char *name;
    char *value;
    struct env_list_s *next;
} env_list_t;

env_list_t *find_key(env_list_t *head, const char *name);
void my_printenv(env_list_t *head);
char *my_getenv(env_list_t *env, const char *key);
int my_setenv(env_list_t **head, const char *name, const char *value);
int my_unsetenv(env_list_t **head, const char *name);
void free_env(env_list_t *head);
void free_env_array(char **env_array);
char **list_to_array(env_list_t *env);

int is_args_unsetenv(char **argv, env_list_t *env);
int is_args_setenv(char **argv, env_list_t *env);
int is_invalid_setenv_args(char **argv);

#endif
