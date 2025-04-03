/*
** EPITECH PROJECT, 2025
** SHELL
** File description:
** cd
*/

#include "../../include/my.h"

int my_cd(char **argv, env_list_t *env)
{
    env_list_t **head = &env;
    char *home = my_getenv(env, "HOME");
    char *actual = getcwd(NULL, 0);
    int result;

    if (!argv || !env)
        return 1;
    result = cd_home(argv, head, actual, home);
    if (result == 0)
        return 0;
    result = cd_oldpwd(argv, head, env, actual);
    if (result == 0)
        return 0;
    if (error_handling_cd_two(argv) != 0)
        return 1;
    my_setenv(head, "OLDPWD", actual);
    my_setenv(head, "PWD", getcwd(NULL, 0));
    return 0;
}
