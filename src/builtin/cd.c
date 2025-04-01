/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** exec_cd
*/

#include "../../lib/libmy.h"
#include "../env/env.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

static int check_cd_args(char **argv)
{
    struct stat st;

    if (argv[2] != NULL) {
        my_puts("cd: Too many arguments.\n");
        return 1;
    }
    if (stat(argv[1], &st) != 0) {
        my_puts(argv[1]);
        my_puts(": No such file or directory.\n");
        return 1;
    }
    return 0;
}

static int error_handling_cd_two(char **argv)
{
    struct stat st;

    if (check_cd_args(argv) == 1)
        return 1;
    stat(argv[1], &st);
    if (!S_ISDIR(st.st_mode)) {
        my_puts(argv[1]);
        my_puts(": Not a directory.\n");
        return 1;
    }
    if (chdir(argv[1]) != 0) {
        my_puts("Error: cannot open path\n");
        return 1;
    }
    return 0;
}

static int handle_oldpwd_error(char *oldpwd, char *actual)
{
    (void)actual;
    if (!oldpwd) {
        my_puts("cd: OLDPWD not set\n");
        return 1;
    }
    if (chdir(oldpwd) != 0) {
        my_puts("cd: cannot change directory to ");
        my_puts(oldpwd);
        my_puts(": No such file or directory\n");
        return 1;
    }
    return 0;
}

static int cd_oldpwd(char **argv, env_list_t **head, env_list_t *env,
    char *actual)
{
    char *oldpwd = NULL;

    if (my_strcmp(argv[1], "-") != 0)
        return 1;
    oldpwd = my_getenv(env, "OLDPWD");
    if (handle_oldpwd_error(oldpwd, actual) == 1)
        return 1;
    my_puts(oldpwd);
    my_puts("\n");
    my_setenv(head, "OLDPWD", actual);
    my_setenv(head, "PWD", getcwd(NULL, 0));
    return 0;
}

static int cd_home(char **argv, env_list_t **head, char *actual, char *home)
{
    if (argv[1] != NULL)
        return 1;
    if (!home) {
        my_puts("Error: HOME is not set.\n");
        return 1;
    }
    if (chdir(home) != 0) {
        my_puts("cd: cannot change directory to HOME: ");
        my_puts(home);
        my_puts("\n");
        return 1;
    }
    my_setenv(head, "OLDPWD", actual);
    my_setenv(head, "PWD", getcwd(NULL, 0));
    return 0;
}

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
