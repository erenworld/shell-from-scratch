/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** my
*/

#include <stddef.h>

#ifndef LIB_H
    #define LIB_H

const char *my_strstr(const char *full_string, const char *substring);
char **split_string(char *str, const char delimiter);
int my_atoi(const char *str);
int my_isspace(int chr);
void *my_memcpy(void *dest, const void *src, size_t size);
void *my_calloc(size_t count, size_t size);
void *my_realloc(void *ptr, size_t oldsize, size_t size);
char *my_strchr(const char *str, int searched_char);
void my_puts(char const *str);
char *my_strdup(const char *src);
int pprintf(const char *format, ...);
int my_putnbr(int nb);
int my_atoi(const char *str);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t len);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_isalpha(char s);
int my_isalpha_str(char *str);

#endif
