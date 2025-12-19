# **************************************************************************** #
#                                                                              #
#                         Makefile for ex02                                   #
#                                                                              #
# **************************************************************************** #

NAME = test

SRCFILES = tests.cpp Account.cpp

OBJFILES = $(SRCFILES:.cpp=.o)

COMPILER = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJFILES)
	$(COMPILER) $(CFLAGS) $(OBJFILES) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
