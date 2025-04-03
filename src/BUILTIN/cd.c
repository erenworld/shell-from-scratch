/*
** EPITECH PROJECT, 2025
** SHELL
** File description:
** cd
*/

#include "../../include/my.h"

int check_cd_args(char **argv)
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

int error_handling_cd_two(char **argv)
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

int handle_oldpwd_error(char *oldpwd, char *actual)
{
    if (!oldpwd) {
        my_puts("cd: OLDPWD not set\n");
        return 1;
    }
    (void)actual;
    if (chdir(oldpwd) != 0) {
        my_puts("cd: cannot change directory to ");
        my_puts(oldpwd);
        my_puts(": No such file or directory\n");
        return 1;
    }
    return 0;
}

int cd_oldpwd(char **argv, env_list_t **head, env_list_t *env, char *actual)
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

int cd_home(char **argv, env_list_t **head, char *actual, char *home)
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
