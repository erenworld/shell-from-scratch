/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** my
*/

#ifndef LIB_H
    #define LIB_H

int my_isspace(int chr);
char *my_strchr(const char *str, int searched_char);
void my_puts(char const *str);
char *my_strdup(const char *src);
int pprintf(const char *format, ...);
int my_putnbr(int nb);
int my_atoi(const char *str);
void my_putchar(char c);
void my_putstr(char const *str);
char **split_string(char *str, char delimiter);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_isalpha(char s);
int my_isalpha_str(char *str);

#endif
