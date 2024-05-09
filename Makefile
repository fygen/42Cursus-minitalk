NAME	= minitalk
SERVER	= server
CLIENT	= client
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c minitalk.h
	$(CC) $(CFLAGS) -o server server.c common.c -L./libft -lft

$(CLIENT): client.c minitalk.h
	$(CC) $(CFLAGS) -o client client.c common.c -L./libft -lft

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all $(NAME) clean fclean re
