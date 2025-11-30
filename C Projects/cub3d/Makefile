NAME    := cub3D
MLX_DIR := minilibx-linux
MLX_LIB	:= $(MLX_DIR)/libmlx.a

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g -I include -I . -I $(MLX_DIR)
IFLAGS  := -I include -I $(MLX_DIR)
LFLAGS  := -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCDIR  := src
OBJDIR  := obj

# Sources
SRCS    :=\
			src/draw_utils.c            src/mlx_setup.c             src/parser_map_utils.c      src/player.c	src/spawn.c	src/collision.c	\
			src/event_handler.c         src/parser_file_reader.c    src/parser_map.c            src/renderer.c			\
			src/garbage_collector.c     src/parser_grid_utils.c     src/parser_rgb.c            src/string_utils.c		\
			src/main.c                  src/parser_identifiers.c    src/parser_scene.c          src/texture_utils.c		\
			src/parser_map_extra.c      src/parser.c                src/validation_utils.c	\
			src/parser_core.c			src/parser_context.c  src/ft_calloc.c \
			src/renderer_extra.c \
			src/garbage_collector_utils.c \
			src/event_handler_utils.c \
			src/string_utils_extra.c \
			src/parser_file_reader_utils.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

OBJS    := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

RESET   := \033[0m
BOLD    := \033[1m
DIM     := \033[2m
BLUE    := \033[34m
GREEN   := \033[92m
YELLOW  := \033[93m
RED     := \033[91m
CYAN    := \033[96m
MAGENTA := \033[95m
GRAY    := \033[90m

.PHONY: all clean fclean re run header

all: header $(NAME)

header:
	@echo "$(BOLD)$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(BOLD)$(MAGENTA) Cub3D $(RESET) $(DIM)– build system$(RESET)"
	@echo "$(BOLD)$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)[CC]$(RESET) %s\n" "$<"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJDIR)/gnl/%.o: gnl/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)[CC]$(RESET) %s\n" "$<"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MLX_LIB)
	@printf "$(GREEN)[LD]$(RESET) %s\n" "$@"
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@printf "$(BOLD)$(GREEN)[OK]$(RESET) Built %s\n" "$(NAME)"

$(MLX_LIB):
	@make -C $(MLX_DIR)

run: all
	@./$(NAME)

clean:
	@printf "$(YELLOW)[CLEAN]$(RESET) object files\n"
	@rm -rf $(OBJDIR)
	@make -C $(MLX_DIR) clean

fclean: clean
	@printf "$(YELLOW)[FCLEAN]$(RESET) $(NAME)\n"
	@rm -f $(NAME)

re: fclean all


