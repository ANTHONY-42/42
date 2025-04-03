# **************************************************************************** #
#                                 MAKEFILE 2.1                                 #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g \
              -Iinclude \
              -Iinclude/libft_x \
              -Iinclude/minilibx_opengl

# === Dossiers ===
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_X_DIR = include/libft_x
MLX_DIR     = include/minilibx_opengl

# === Fichiers sources ===
SRC_FILES   = main.c \
              parsing/parsing.c \
              parsing/check_map.c \
              parsing/flood_fill.c \
	      play/start_window.c \
	      play/mouv.c \
              utils/free.c \
              utils/utils.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# === Librairies ===
LIBFT_X_A   = $(LIBFT_X_DIR)/libft_x.a
MLX_A       = $(MLX_DIR)/libmlx.a

# === Liens dynamiques ===
MLX         = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# === Règles ===
all: $(MLX_A) $(LIBFT_X_A) $(NAME)

$(LIBFT_X_A):
	@$(MAKE) -C $(LIBFT_X_DIR)

$(MLX_A):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_X_A) $(MLX) -o $(NAME)
	@echo "✅ Compilation terminée : $(NAME)"

# Compile .c to .o, crée les dossiers obj/ nécessaires
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_X_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "🧹 Clean terminé."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_X_DIR)
	@echo "🧹 Fclean terminé."

re: fclean all

.PHONY: all clean fclean re
