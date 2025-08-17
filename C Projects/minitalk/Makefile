NAME = minitalk
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = utils.c
SRC_BONUS = utils_bonus.c

all: $(NAME)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c $(SRC)
	$(CC) $(CFLAGS) -o $(SERVER) server.c $(SRC)

$(CLIENT): client.c $(SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) client.c $(SRC)

$(SERVER_BONUS): server_bonus.c $(SRC_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) server_bonus.c $(SRC_BONUS)

$(CLIENT_BONUS): client_bonus.c $(SRC_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) client_bonus.c $(SRC_BONUS)

clean:
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
