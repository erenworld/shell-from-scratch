/*
** EPITECH PROJECT, 2024
** day
** File description:
** project
*/

#include "../include/my.h"

void verify_type(char c, va_list *args)
{
    if (c == 's')
        my_putstr(va_arg(*args, char *));
    if (c == 'c')
        my_putchar(va_arg(*args, int));
    if (c == 'i' || c == 'd')
        my_putnbr(va_arg(*args, int));
    if (c == '%')
        my_putchar('%');
}

int pprintf(const char *format, ...)
{
    int counter = 0;
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1]) {
            i++;
            verify_type(format[i], &args);
            counter++;
        } else {
            my_putchar(format[i]);
            counter++;
        }
    }
    va_end(args);
    return counter;
}
