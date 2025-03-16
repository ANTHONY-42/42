#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->start;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (is_sorted(stack_a))
	{
		printf("is_sorted");
		exit(1);
	}
	else if (size > 1 && size <= 5)
		sort_5(stack_a, stack_b);
	else
		k_sort(stack_a, stack_b);
}
