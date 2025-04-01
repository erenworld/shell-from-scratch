/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** split_string
*/

#include <stdlib.h>
#include "libmy.h"

int is_delimiter(char c, char delimiter)
{
    return (c == delimiter || c == '\n' || c == '\t' || c == '\0');
}

int counter(char *str, char delimiter)
{
    int result = 0;
    int in_word = 0;

    for (int i = 0; str[i]; i++) {
        if (is_delimiter(str[i], delimiter)) {
            in_word = 0;
        }
        if (!is_delimiter(str[i], delimiter) && in_word == 0) {
            in_word = 1;
            result++;
        }
    }
    return result;
}

void fill_array(char **tab, char *str, char delimiter, int str_len)
{
    int word_start = -1;
    int word_index = 0;
    int each_len;

    for (int i = 0; i <= str_len; i++) {
        if (is_delimiter(str[i], delimiter) && word_start != -1) {
            each_len = i - word_start;
            tab[word_index] = malloc(sizeof(char) * (each_len + 1));
            if (tab[word_index] == NULL)
                return;
            my_strncpy(tab[word_index], str + word_start, each_len);
            tab[word_index][each_len] = '\0';
            word_index++;
            word_start = -1;
        }
        if (!is_delimiter(str[i], delimiter) && word_start == -1)
            word_start = i;
    }
    tab[word_index] = NULL;
}

char **split_string(char *str, char delimiter)
{
    int str_len;
    int total_words;
    char **tab;

    if (str == NULL)
        return NULL;
    str_len = my_strlen(str);
    total_words = counter(str, delimiter);
    tab = malloc(sizeof(char *) * (total_words + 1));
    if (!tab)
        return NULL;
    fill_array(tab, str, delimiter, str_len);
    return tab;
}
