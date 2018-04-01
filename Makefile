SERVER	=	server
CLIENT	=	client

CLIENT_C	=	client_src/main.c
SERVER_C	=	server_src/main.c \
				server_src/clients.c 

CLIENT_O	=	$(CLIENT_C:.c=.o)
SERVER_O	=	$(SERVER_C:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

LIBFT       =   libft/libft.a

all:			$(SERVER) $(CLIENT)

$(SERVER):		$(SERVER_O)
			make -C ./libft
			gcc $(FLAGS) -o $(SERVER) $(SERVER_O) $(LIBFT)

$(CLIENT):		$(CLIENT_O)
			make -C ./libft
			gcc $(FLAGS) -o $(CLIENT) $(CLIENT_O) $(LIBFT)

clean:
			/bin/rm -f $(SERVER_O) $(CLIENT_O)
			make -C ./libft clean

fclean:			clean
			/bin/rm -f $(SERVER) $(CLIENT)
			make -C ./libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re