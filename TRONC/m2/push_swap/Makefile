CC       = gcc
CFLAGS   = -Wall -Wextra -Werror

SRC_DIR  = src
OBJ_DIR  = obj
INC_DIR  = include

SRC_FILES = \
	main.c \
	operation/push.c \
	operation/rotate.c \
	operation/r_rotate.c \
	operation/swap.c \
	parcing/check_arg.c \
	parcing/create_stack.c \
	parcing/ft_split.c \
	parcing/parsing.c \
	sort/k_sort.c \
	sort/push_swap.c \
	sort/radix_sort.c \
	sort/sort_5.c \
	utils/free.c \
	utils/utils.c

OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

DEP_FILES = $(OBJ_FILES:.o=.d)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP_FILES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
