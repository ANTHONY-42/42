# =========================
#         MAKEFILE
# =========================

NAME	= pipex

# Répertoires
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= include
LIBFT_DIR = $(INC_DIR)/libft_2.0/libft

# Fichiers source
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/pipex.c \
	$(SRC_DIR)/error.c \
	$(SRC_DIR)/path.c

# Objets générés
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -g

# Libft
LIBFT_A	= $(LIBFT_DIR)/libft.a

# Couleurs
GREEN	= \033[0;32m
RESET	= \033[0m

# =========================
#         RÈGLES
# =========================

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@echo "$(GREEN)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de la libft
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# Nettoyage
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
