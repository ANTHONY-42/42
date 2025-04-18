# **************************************************************************** #
#                                 MAKEFILE                                     #
# **************************************************************************** #

NAME		= so_long

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
LIBFT_DIR	= $(INC_DIR)/libft_x

# Platform detection (automatic)
UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_DIR		= $(INC_DIR)/minilibx_opengl
	MLX_FLAGS	= -framework OpenGL -framework AppKit -L$(MLX_DIR) -lmlx
else
	MLX_DIR		= $(INC_DIR)/minilibx-linux
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Sources (explicit listing, no wildcard)
SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing/check_map.c \
	$(SRC_DIR)/parsing/flood_fill.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/play/move_player.c \
	$(SRC_DIR)/play/start_window.c \
	$(SRC_DIR)/utils/free.c \
	$(SRC_DIR)/utils/utils.c

# Objects
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libs
LIBX_DIR = include/libft_x/
LIBX_LIB = include/libft_x/libft_x.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

# Colors
GREEN		= \033[0;32m
RESET		= \033[0m

# ==============================================================================
#                                    RULES
# ==============================================================================

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBX_LIB) $(OBJS)
	@echo "$(GREEN)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBX_LIB) $(MLX_FLAGS) -o $@

# Object compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBX_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Build MiniLibX
$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

# Cleaning
clean:
	@$(MAKE) -C $(LIBX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBX_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
