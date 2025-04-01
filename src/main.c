/*
** EPITECH PROJECT, 2025
** SHELL
** File description:
** main
*/

#include "../include/my.h"

void parse_env(env_list_t **env, const char *envstr)
{
    char *equal = my_strchr(envstr, '=');
    char *name;

    if (!equal)
        return;
    name = malloc(strlen(envstr) + 1);
    if (!name)
        return;
    my_strcpy(name, envstr);
    name[equal - envstr] = '\0';
    my_setenv(env, name, equal + 1);
    free(name);
}

int main(int argc, char **argv, char **environ)
{
    env_list_t *env = NULL;

    (void)argc;
    (void)argv;
    for (char **env_ptr = environ; *env_ptr; env_ptr++)
        parse_env(&env, *env_ptr);
    tcshloop(env);
    free_env(env);
    return 0;
}
