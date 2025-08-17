NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/main.c srcs/map_reader.c srcs/map_validator.c srcs/mlx_init.c srcs/render.c \
		srcs/player_move.c srcs/path_validator.c
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
MLX = minilibx-linux/libmlx.a

INCLUDES = -I./includes -I./libft -I./ft_printf -I./get_next_line -Iminilibx-linux
LIBS = -L./libft -lft -L./ft_printf -lftprintf -Lminilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS) $(GNL_OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) created!"

$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(MLX):
	@make -C minilibx-linux

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS) $(GNL_OBJS)
	@make -C ./libft clean
	@make -C ./ft_printf clean
	@make -C minilibx-linux clean

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
