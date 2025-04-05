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

# Sources
SRCS		= $(shell find $(SRC_DIR) -name '*.c')
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libs
LIBFT		= $(LIBFT_DIR)/libft_x.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

# Colors
GREEN		= \033[0;32m
RESET		= \033[0m

# ==============================================================================
#                                    RULES
# ==============================================================================

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	@echo "$(GREEN)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $@

# Object compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build MiniLibX
$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

# Cleaning
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
