/*
** EPITECH PROJECT, 2025
** SHELL
** File description:
** exit
*/

#include "../../lib/libmy.h"
#include <stdlib.h>

int my_exit(char *arg)
{
    if (arg == NULL)
        exit(0);
    exit(my_atoi(arg));
    return 0;
}
