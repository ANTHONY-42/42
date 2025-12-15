NAME	= minishell
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -Iinclude -g

SRC	= src/main.c\
	  src/fonction_utils1.c\
	  src/fonction_utils2.c
OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
