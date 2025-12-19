NAME = zombie

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.cpp \
	  $(SRC_DIR)/Zombie.cpp \
	  $(SRC_DIR)/newZombie.cpp \
	  $(SRC_DIR)/randomChump.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
