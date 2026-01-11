NAME		= MoarBrainz

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -I include

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

SRC			= $(SRC_DIR)/main.cpp \
			  $(SRC_DIR)/Zombie.cpp \
			  $(SRC_DIR)/zombieHorde.cpp

OBJ			= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

HEADER		= $(INC_DIR)/Zombie.hpp

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp $(HEADER)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
