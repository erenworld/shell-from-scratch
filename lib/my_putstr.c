/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/
#include "../include/my.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_puts(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        my_putchar_error(str[i]);
    }
}

void my_putstr(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        my_putchar(str[i]);
    }
}
