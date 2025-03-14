#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	int	index;
	t_node	*current;
	t_node	*cmp;

	if (!stack || !stack->start)
		return;

	current = stack->start;
	while (current)
	{
		index = 0;
		cmp = stack->start;
		while (cmp)
		{
			if (current->value > cmp->value)
				index++;
			cmp = cmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	count_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = stack_a->size;
	max_bits = count_bits((size - 1));

	index_stack(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->start->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
