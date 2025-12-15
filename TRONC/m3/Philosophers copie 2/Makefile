NAME	= philo
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread -Iinclude -g

SRC	= src/main.c\
	  src/pars_arg.c\
	  src/init.c\
	  src/philo.c\
	  src/monitoring.c\
	  src/lock_unlock.c\
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
