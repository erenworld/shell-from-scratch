/*
** EPITECH PROJECT, 2024
** day07
** File description:
** my atoi
*/
#include "../libmy.h"

int powerten(int nb)
{
    int result = 1;

    for (int i = 0; i < nb; i++) {
        result *= 10;
    }
    return result;
}

int my_atoi(const char *str)
{
    int result = 0;
    int i = 0;
    int str_len = my_strlen(str) - 1;
    int ten = powerten(str_len);

    while (str[i] >= '0' && str[i] <= '9') {
        result += ten * (str[i] - '0');
        ten = ten / 10;
        i++;
    }
    return result;
}
