.PHONY: all clean fclean re
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
HEADER_DIR = includes
SRCS = $(addprefix $(SRCS_DIR)/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJS = $(SRCS:.c=.o)

all: ${NAME}
clean: 
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(INC_DIR)/ft.h
	gcc $(CFLAG) -I $(INC_DIR) -c $< -o $@

re: fclean all
