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

SRC	=	./src/main.c \
	./src/split_args.c \
	./src/check_signal.c \
	./src/is_args_setenv.c \
	./src/t_free_env_array.c \
	./src/check_cmd_exist.c \
	./src/BUILTIN/getenv.c \
	./src/BUILTIN/unsetenv.c \
	./src/BUILTIN/printenv.c \
	./src/BUILTIN/setenv.c \
	./src/BUILTIN/free_env.c \
	./src/getline.c \
	./src/t_array.c \
	./src/t_loop.c \
	./src/t_exec.c \
	./src/t_proc.c \
	./src/t_childproc.c \
	./src/free_tokens.c \
	./src/BUILTIN/cd.c \
	./src/BUILTIN/cd_main.c \
	./src/BUILTIN/exit.c \
	./lib/my_putchar.c \
	./lib/my_putnbr.c \
	./lib/my_putstr.c \
	./lib/my_strcat.c \
	./lib/my_strchr.c \
	./lib/my_strcmp.c \
	./lib/my_strcpy.c \
	./lib/my_strdup.c \
	./lib/my_strncpy.c \
	./lib/my_strlen.c \
	./lib/my_atoi.c \
	./lib/my_isalpha.c \
	./lib/split_string.c \
	./lib/my_isspace.c \
	./lib/printf.c \

OBJ	=	$(SRC:.c=.o)

all: $(NAME)
	@echo -e "$(GREEN)Compilation Successful !$(RESET)"

%.o: %.c
	@echo -e "$(YELLOW)Compilation of $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo -e "$(BLUE)Exec created: $(NAME)$(RESET)"

clean:
	@echo -e "$(RED)Delete files...$(RESET)"
	rm -f $(OBJ)
	rm -f mysh
	find . -name "*.o" -type f -delete
	rm -f *.gcno *.gcda a.out

fclean: clean

re: fclean all

.PHONY: all clean fclean re
