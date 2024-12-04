SRCS = ft_printf.c\
      ft_put_c.c\
      ft_put_s.c\
      ft_put_p.c\
      ft_put_d.c\
      ft_put_i.c\
      ft_put_u.c\
      ft_put_xmin.c\
      ft_put_xmaj.c\
      ft_put_100.c\

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)


re: fclean all
