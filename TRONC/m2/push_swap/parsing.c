#include "push_swap.h"

void	error(t_stack **stack_a, t_stack **stack_b, char **tab)
{
	free_full(stack_a, stack_b, tab);
	write(2, "Error\n", 6);
	exit(1);
}

void	parsing(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	int	split;

	split = 0;
	if (ac < 2)
		exit(1);
	if (ac == 2)
	{
		tab = ft_split(av[1]);
		if (!tab)
			error(NULL, NULL, tab);
		split++;
	}
	else
		tab = &av[1];
	check_arg(tab, split);
	*stack_a = create_stack_a(tab);
	*stack_b = create_stack_b();
	if (split)
		free_tab(tab);
	if (!stack_a || !stack_b)
		error(stack_a, stack_b, NULL);
}
