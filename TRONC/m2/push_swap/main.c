#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing(ac, av, &stack_a, &stack_b);
	push_swap(stack_a, stack_b);
//	print_stack(stack_a);
	free_full(&stack_a, &stack_b, NULL);
	system("leaks a.out");
	return (0);
}
