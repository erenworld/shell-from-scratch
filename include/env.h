/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** my
*/

#ifndef ENV_H
    #define ENV_H

typedef struct env_list_s {
    char *name;
    char *value;
    struct env_list_s *next;
} env_list_t;

int my_unsetenv(env_list_t **head, const char *name);
int delete_node(env_list_t **head, const char *name);
int is_args_unsetenv(char **argv, env_list_t *env);
void my_printenv(env_list_t *head);
char *my_getenv(env_list_t *env, const char *keystr);
void print_env(void);
void free_env(env_list_t *head);
env_list_t *find_key(env_list_t *head, const char *name);
env_list_t *create_node(const char *name, const char *value);
int my_setenv(env_list_t **head, const char *name, const char *value);
void my_printenv(env_list_t *head);

#endif
