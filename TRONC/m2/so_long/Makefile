# Nom de l'exécutable
NAME = so_long

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
MLX_DIR = mlx_linux

# Fichiers
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR)

# Liens MiniLibX (Linux)
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Règles de compilation
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)  # Compile MiniLibX
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBS)
	@echo "Compilation réussie de $(NAME) !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_DIR)
	@echo "Objets supprimés !"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(MLX_DIR)
	@echo "Exécutable supprimé !"

re: fclean all

.PHONY: all clean fclean re
