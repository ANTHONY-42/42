# **************************************************************************** #
#                                 MAKEFILE 2.0                                 #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I. -Imlx_linux -Ilibft_x

# === Dossiers ===
OBJ_DIR     = obj
SRC_DIR     = .
LIBFT_X_DIR = ./libft_x
MLX_DIR     = ./mlx_linux

# === Fichiers sources ===
SRCS        = main.c parsing.c check_map.c flood_fill.c \
              free.c utils.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# === Librairies ===
LIBFT_X_A   = $(LIBFT_X_DIR)/libft_x.a
MLX         = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# === Règles ===
all: $(LIBFT_X_A) $(NAME)

$(LIBFT_X_A):
	@$(MAKE) -C $(LIBFT_X_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_X_A) $(MLX) -o $(NAME)
	@echo "✅ Compilation terminée : $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_X_DIR)
	@echo "🧹 Clean terminé."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_X_DIR)
	@echo "🧹 Fclean terminé."

re: fclean all

.PHONY: all clean fclean re

