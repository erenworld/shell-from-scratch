/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/

#include "../include/my.h"

int my_putnbr(int nb)
{
    int power = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    while (nb / power >= 10) {
        power *= 10;
    }
    while (power > 0) {
        my_putchar((nb / power) % 10 + '0');
        power = power / 10;
    }
    return 0;
}
