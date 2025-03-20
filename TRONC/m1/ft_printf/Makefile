# **************************************************************************** #
#                                 MAKEFILE 2.0                                 #
# **************************************************************************** #

################################## SETTINGS #####################################

NAME			= libftprintf.a
TYPEFILE		= library

SRCS			= ft_printf.c \
				  ft_put_c.c \
				  ft_put_s.c \
				  ft_put_p.c \
				  ft_put_d.c \
				  ft_put_i.c \
				  ft_put_u.c \
				  ft_put_xmin.c \
				  ft_put_xmaj.c \
				  ft_put_100.c

OBJS_DIR		= obj
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

BONUS_SRCS		= ft_printf_bonus.c
BONUS_OBJS		= $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs
RM				= rm -f

################################## MESSAGES #####################################

BOLD			= \033[1m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
END				= \033[0m
CLEAR_LINE		= \r\033[K  # Efface la ligne précédente

SUCCESS_MSG		= \033[1m\033[32m[SUCCESS]\033[0m
FAILURE_MSG		= \033[1m\033[31m[FAILURE]\033[0m

# Vérifie si l'option detail est activée
DETAIL		:= $(filter detail,$(MAKECMDGOALS))

################################## RULES #####################################

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf "$(GREEN)%-50s$(END)\t$(SUCCESS_MSG)\n" "Generating all files / .o"
	@printf "$(GREEN)%-50s$(END)\t$(SUCCESS_MSG)\n" "Generating libftprintf.a library..."
	@$(AR) $(NAME) $(OBJS) || (printf "$(FAILURE_MSG)\n"; exit 1)

# Création du dossier obj (uniquement en mode detail)
$(OBJS_DIR):
	@if [ "$(DETAIL)" = "detail" ]; then \
		printf "$(YELLOW)%-50s$(END)\t$(SUCCESS_MSG)\n" "Creating library objs directory..."; \
	fi
	@mkdir -p $(OBJS_DIR) || (printf "$(FAILURE_MSG)\n"; exit 1)

# Compilation des fichiers objets avec `[SUCCESS]`
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@tput civis
	@if [ "$(DETAIL)" = "detail" ]; then \
		printf "$(YELLOW)%-50s$(END)" "Generating $< / .o"; \
	else \
		printf "$(CLEAR_LINE)$(YELLOW)Generating $< / .o$(END)"; \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@ || (printf "\n$(FAILURE_MSG)\n"; exit 1)
	@sleep 0.05
	@tput cnorm
	@if [ "$(DETAIL)" = "detail" ]; then \
		printf "$(CLEAR_LINE)$(YELLOW)%-50s$(END)\t$(SUCCESS_MSG)\n" "Generating $< / .o"; \
	else \
		printf "$(CLEAR_LINE)"; \
	fi

################################## CLEAN #####################################

clean:
	@tput civis
	@if [ -d "$(OBJS_DIR)" ]; then \
		for file in $(OBJS); do \
			if [ -f $$file ]; then \
				if [ "$(DETAIL)" = "detail" ]; then \
					printf "$(RED)%-50s$(END)\t$(SUCCESS_MSG)\n" "Removing $$file"; \
				else \
					printf "$(CLEAR_LINE)$(RED)Removing $$file$(END)"; \
				fi; \
				$(RM) $$file; \
				sleep 0.05; \
			fi; \
		done; \
		if [ "$(DETAIL)" != "detail" ]; then \
			printf "$(CLEAR_LINE)$(RED)Removing library objs directory...$(END)"; \
		fi; \
		$(RM) -r $(OBJS_DIR); \
		if [ "$(DETAIL)" = "detail" ]; then \
			printf "$(RED)%-50s$(END)\t$(SUCCESS_MSG)\n" "Removing library objs directory..."; \
		else \
			printf "$(CLEAR_LINE)$(RED)%-50s$(END)\t$(SUCCESS_MSG)\n" "Removing library objs directory..."; \
		fi; \
	fi
	@tput cnorm

fclean: clean
	@tput civis
	@if [ -f "$(NAME)" ]; then \
		if [ "$(DETAIL)" = "detail" ]; then \
			printf "$(RED)%-50s$(END)\t$(SUCCESS_MSG)\n" "Removing $(NAME)"; \
		else \
			printf "$(CLEAR_LINE)$(RED)Removing $(NAME)$(END)"; \
		fi; \
		$(RM) $(NAME); \
		sleep 0.1; \
	fi
	@printf "$(CLEAR_LINE)$(RED)%-50s$(END)\t$(SUCCESS_MSG)\n" "Removing library..."
	@tput cnorm

re: fclean all

# Empêche le message parasite "Nothing to be done for `detail`"
detail: ;

.PHONY: all clean fclean re bonus detail
