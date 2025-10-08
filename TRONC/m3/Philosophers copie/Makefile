NAME	= philo
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread -Iinclude

SRC	= src/main.c\
	  src/philo.c\
	  src/monitoring.c\
	  src/utils.c
OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
