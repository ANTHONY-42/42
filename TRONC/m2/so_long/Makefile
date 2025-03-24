CC       = gcc
CFLAGS   = -Wall -Wextra -Werror

SRC_DIR  = src
OBJ_DIR  = obj

SRC_FILES = main.c \
	parsing.c \
	free.c \

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIB_DIR = libft
LIB_LIB = libft/libft.a

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIB_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIB_LIB)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
