6. Makefile

    Contient les règles pour compiler le programme et gérer les dépendances.
        Exemple de cibles :
            all : Compile le projet.
            clean : Supprime les fichiers objets.
            fclean : Supprime les fichiers objets et l'exécutable.
            re : Recompile tout.

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/parsing.c src/operations.c src/sort.c src/utils.c src/error.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
