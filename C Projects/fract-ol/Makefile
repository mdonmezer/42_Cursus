CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I minilibx-linux
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
NAME = fractol

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) \
            $(wildcard $(SRC_DIR)/events/*.c) \
            $(wildcard $(SRC_DIR)/init/*.c) \
            $(wildcard $(SRC_DIR)/render/*.c)

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re