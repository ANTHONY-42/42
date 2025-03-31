NAME = libft_x.a

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/ft_printf.a
GNL_A = $(GNL_DIR)/gnl.a

all: $(LIBFT_A) $(PRINTF_A) $(GNL_A)
	cp $(LIBFT_A) $(NAME)
	ar -x $(PRINTF_A)
	ar -x $(GNL_A)
	ar rcs $(NAME) *.o
	rm -f *.o
	@echo "\033[38;5;198m 888      8888888 888888b.   8888888888 88888888888                 Y88b   d88P\033[0m"
	@echo "\033[38;5;199m 888        888   888  \"88b  888            888                      Y88b d88P \033[0m"
	@echo "\033[38;5;200m 888        888   888  .88P  888            888                       Y88o88P  \033[0m"
	@echo "\033[38;5;201m 888        888   8888888K.  8888888        888            888  888    Y888P   \033[0m"
	@echo "\033[38;5;207m 888        888   888  \"Y88b 888            888            \`Y8bd8P'    d888b   \033[0m"
	@echo "\033[38;5;206m 888        888   888    888 888            888              X88K     d88888b  \033[0m"
	@echo "\033[38;5;205m 888        888   888   d88P 888            888            .d8\"\"8b.  d88P Y88b \033[0m"
	@echo "\033[38;5;198m 88888888 8888888 8888888P\"  888            888   88888888 888  888 d88P   Y88b\033[0m"
	@echo "✅ \033[1;32mlibft_x.a compilée avec succès !\033[0m"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL_A):
	@$(MAKE) -C $(GNL_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	rm -f *.o

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re: fclean all

