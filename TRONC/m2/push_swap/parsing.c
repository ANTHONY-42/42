#include "push_swap.h"

void	parsing(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;

	if (ac < 2)
	{
		perror("error : ac < 2");
		exit(1);
	}
	else if (ac == 2)
		tab = ft_split(av[1]);
	else if (ac > 2)
		tab = &av[1];
	check_arg(tab);
	*stack_a = create_stack_a(tab);
	*stack_b = create_stack_b();
}
