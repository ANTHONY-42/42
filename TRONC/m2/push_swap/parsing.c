#include "push_swap.h"

void	error()
{
	free_full(stack_a, stack_b, tab);
	write(2, "Error\n", 6);
	exit(1);
}

void	parsing(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	int	arg_valid;

	if (ac < 2)
		exit(1);
	else if (ac == 2)
		tab = ft_split(av[1]);
	else if (ac > 2)
		tab = &av[1];
	check_arg(tab);
	*stack_a = create_stack_a(tab);
	*stack_b = create_stack_b();
	if (!*stack_a || !*stack_b)
	{
		free_full(stack_a, stack_b, tab);
		write(1, "Error\n", 6);
		exit(1);
	}
}
