/*
** EPITECH PROJECT, 2025
** B-PSU-200-NCY-2-1-minishell2-eren.turkoglu
** File description:
** check_signal
*/

#include "../include/parser.h"
#include "../lib/libmy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int signal_switch(int signal, int core)
{
    char *signal_msg = strsignal(signal);

    if (!signal_msg)
        signal_msg = "Unknown signal";
    write(2, signal_msg, my_strlen(signal_msg));
    if (core)
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
    return 128 + signal;
}

int check_signal(int *status)
{
    int signal;

    if (WIFEXITED(*status))
        return WEXITSTATUS(*status);
    if (WIFSIGNALED(*status)) {
        signal = WTERMSIG(*status);
        return signal_switch(signal, WCOREDUMP(*status));
    }
    if (WIFSTOPPED(*status))
        return WSTOPSIG(*status);
    return 0;
}
