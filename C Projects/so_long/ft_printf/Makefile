NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_print.c ft_bghex.c ft_pointer.c ft_smhex.c \
	   ft_putchar.c ft_putnbr.c ft_putstr.c ft_unnbr.c

OBJS = $(SRCS:.c=.o)
			
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
		
fclean:	clean
	$(RM) $(NAME)
		
re: fclean all

.PHONY : all clean fclean re
