CFLAGS := -Wall -Wextra -Werror

HEADER_BONUS := minitalk_bonus.h
SERVER_BONUS :=  server_bonus
CLIENT_BONUS := client_bonus
UTILS_BONUS := utils_bonus.c

SERVER :=  server
CLIENT := client
HEADER := minitalk.h
UTILS := utils.c

NAME := $(SERVER) $(CLIENT)

all: $(NAME) $(HEADER)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS) $(HEADER_BONUS)

$(SERVER): server.c $(UTILS)
	$(CC) $(CFLAGS) server.c $(UTILS) -o $(SERVER)

$(CLIENT): client.c $(UTILS)
	$(CC) $(CFLAGS) client.c $(UTILS) -o $(CLIENT)

$(SERVER_BONUS): server_bonus.c $(UTILS_BONUS)
	$(CC) $(CFLAGS) server_bonus.c $(UTILS_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.c $(UTILS_BONUS)
	$(CC) $(CFLAGS) client_bonus.c $(UTILS_BONUS) -o $(CLIENT_BONUS)

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean
	rm -rf $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all