NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/local/opt/readline/include
LDFLAGS = -lreadline -L/usr/local/opt/readline/lib

SRCS = main.c main_utils.c shell_cleanup.c signals.c parser_utils.c parser_utils2.c parser_utils4.c parser_utils3.c parser_utils_extra.c parser_utils3_extra.c parser.c executor.c executor_utils.c executor_path_utils.c executor_path_utils2.c executor_exec_utils.c builtins/pwd.c \
		redirections.c redirections_utils.c builtins/built.c builtins/cd.c builtins/env.c builtins/exit.c \
		lexer.c lexer2.c builtins/env_utils.c builtins/echo.c builtins/export.c builtins/unset.c \
		expand.c expand2.c parse_heredoc.c parse_heredoc2.c parse_heredoc_utils.c builtins/export_utils.c \
		builtins/cd_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all

leaks:
	@valgrind	--leak-check=full \
				--suppressions=readline.supp \
				--show-leak-kinds=all \
				--track-origins=yes \
				--track-fds=yes \
				--verbose \
				./$(NAME)

.PHONY: all clean fclean re
