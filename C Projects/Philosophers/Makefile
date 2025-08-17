CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

NAME = philo

SRCS = main.c init.c routine.c utils.c time.c monitor.c monitor_helper.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
