##
## EPITECH PROJECT, 2025
## Title
## File description:
## Makefile
##

GREEN=\033[0;32m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RESET=\033[0m

NAME = mysh

CC = gcc

CFLAGS = -W -Wall -Wextra -std=gnu99

SRC = ./src/main.c \
	./src/check_signal.c \
	./src/tcsh_loop.c \
	./src/tcsh_parse.c \
	./src/tcsh_exec.c \
	./src/exec_path.c \
	./src/redir_right.c \
	./src/tcsh_free_tokens.c \
	./src/utils/remove_quotes.c \
	./src/utils/skip_space.c \
	./src/utils/getline.c \
	./src/utils/free_tab.c \
	./src/env/free_env.c \
	./src/env/get_env.c \
	./src/env/find_key.c \
	./src/env/free_env_array.c \
	./src/env/list_to_array.c \
	./src/env/print_env.c \
	./src/env/setenv.c \
	./src/env/unsetenv.c \
	./src/env/error_handling_env.c \
	./src/builtin/exit.c \
	./src/builtin/cd.c \
	./lib/my_putchar.c \
	./lib/my_putnbr.c \
	./lib/my_putstr.c \
	./lib/my_strcat.c \
	./lib/my_strchr.c \
	./lib/my_strcmp.c \
	./lib/my_strncmp.c \
	./lib/my_strcpy.c \
	./lib/my_strstr.c \
	./lib/my_strdup.c \
	./lib/my_strncpy.c \
	./lib/my_strlen.c \
	./lib/my_isalpha.c \
	./lib/printf.c \
	./lib/split_string.c \
	./lib/my_isspace.c \
	./lib/my_stdlib/realloc.c \
	./lib/my_stdlib/my_atoi.c \
	./lib/my_stdlib/memcpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo -e "$(GREEN)Compilation Successful !$(RESET)"

%.o: %.c
	@echo -e "$(YELLOW)Compilation of $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -fsanitize=address -g
	@echo -e "$(BLUE)Exec created: $(NAME)$(RESET)"

clean:
	@echo -e "$(RED)Delete files...$(RESET)"
	rm -f $(OBJ)
	rm -f mysh
	find . -name "*.o" -type f -delete
	rm -f *.gcno *.gcda a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
