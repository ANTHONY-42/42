NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Wextra -Werro

FILES = ft_display_file.c
OBJS = $(FILES:.c=.O)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
