NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC =	error_validation.c \
		integer_conversion.c \
		libft_utils.c \
		memory_cleanup.c \
		node_preparation.c \
		node_search.c \
		push_commands.c \
		push_swap.c \
		reverse_rotate.c \
		rotate.c \
		split.c \
		stack_a_init.c \
		stack_b_prep.c \
		stack_operations.c \
		stack_sort.c \
		swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
