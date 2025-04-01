/*
** EPITECH PROJECT, 2025
** MINISHELL
** File description:
** check_signal
*/
#include "../include/my.h"

int signal_switch(int signal_number)
{
    switch (signal_number) {
        case SIGSEGV:
            write(2, "Segmentation fault\n", 19);
            return 139;
        case SIGFPE:
            write(2, "Floating point exception\n", 25);
            return 136;
        case SIGBUS:
            write(2, "Bus error\n", 10);
            return 138;
        case SIGTRAP:
            write(2, "Trace trap\n", 11);
            return 133;
        default:
            write(2, "Terminated by signal\n", 21);
            return 128 + signal_number;
        }
}

int check_signal(int status)
{
    int signal_number;

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status)) {
        signal_number = WTERMSIG(status);
        return signal_switch(signal_number);
    }
    if (WIFSTOPPED(status)) {
        return WSTOPSIG(status);
    }
    return 0;
}
