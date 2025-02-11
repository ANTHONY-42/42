#include <unistd.h>

t_stack	push_swap(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	if (!parsing(ac, av))
		return (0);

	if (ac < 1 || ac > 500)
		return (printf("erreur : ac"), 1);
	
	else if (ac >= 2 && ac <= 3)
		return ((sort_3(stack_a)), 0);

	else if (ac >= 4 && ac <= 5)
		return (sort_4_5(stack_a, stack_b), 0);
	
	else if (ac > 5 && ac <= 100)
		return (sort_100(stack_a, stack_b), 0);

	else if (ac > 100 && ac <= 500)
		return (sort_500(stack_a, stack_b));
}
