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
	ar -rcs $(NAME) *.o
	rm -f *.o
		@echo -e "\033[38;5;196m              ██╗     ██╗\033[38;5;202m██████╗ \033[38;5;208m███████╗\033[38;5;214m████████╗"
	@echo -e "\033[38;5;202m              ██║     ██║\033[38;5;208m██╔══██╗\033[38;5;214m██╔════╝\033[38;5;220m╚══██╔══╝"
	@echo -e "\033[38;5;208m              ██║     ██║\033[38;5;214m██████╔╝\033[38;5;220m█████╗  \033[38;5;190m   ██║   "
	@echo -e "\033[38;5;154m              ██║     ██║\033[38;5;118m██╔══██╗\033[38;5;82m██╔══╝  \033[38;5;46m   ██║   "
	@echo -e "\033[38;5;50m              ███████╗██║\033[38;5;51m██████╔╝\033[38;5;45m██║     \033[38;5;39m   ██║   "
	@echo -e "\033[38;5;201m              ╚══════╝╚═╝\033[38;5;207m╚═════╝ \033[38;5;213m╚═╝     \033[38;5;213m   ╚═╝   \033[0m"
	@echo -e "\033[38;5;33m                          ██╗  ██████╗     ██████╗ "
	@echo -e "\033[38;5;33m                          ╚██╗ ╚════██╗   ██╔═████╗"
	@echo -e "\033[38;5;33m                    █████╗ ╚██╗ █████╔╝   ██║██╔██║"
	@echo -e "\033[38;5;33m                    ╚════╝ ██╔╝██╔═══╝    ████╔╝██║"
	@echo -e "\033[38;5;33m                          ██╔╝ ███████╗██╗╚██████╔╝"
	@echo -e "\033[38;5;33m                          ╚═╝  ╚══════╝╚═╝ ╚═════╝ \033[0m"
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

