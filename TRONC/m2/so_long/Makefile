# **************************************************************************** #
#                                 MAKEFILE 2.1                                 #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g \
              -Iinclude \
              -Iinclude/libft_x \
              -Iinclude/mlx_linux

# === Dossiers ===
OBJ_DIR     = obj
SRC_DIR     = src
LIBFT_X_DIR = include/libft_x
MLX_DIR     = include/mlx_linux

# === Fichiers sources ===
SRC_FILES   = main.c \
	      init_mlx.c \
              parsing/parsing.c \
              parsing/check_map.c \
              parsing/flood_fill.c \
              utils/free.c \
              utils/utils.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

# Compile .c to .o, crée les dossiers obj/ nécessaires
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

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

