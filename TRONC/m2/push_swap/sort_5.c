#include "push_swap.h"

int	ft_min(t_stack *stack)
{
	t_node	*current;
	int	min;

	current = stack->start;
	min = stack->start->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	min_pos(t_stack *stack, int min)
{
	t_node	*current = stack->start;
	int	pos;
	
	pos= 0;
	while (current)
	{
		if (current->value == min)
			return (pos);
		current = current->next;
		pos++;
	}
	return (0);
}

void	sort_3(t_stack *stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stack_a->start->value;
	n2 = stack_a->start->next->value;
	n3 = stack_a->start->next->next->value;
	if ((n1 < n2) && (n1 < n3) && (n2 > n3))	//[1, 3, 2]
		return (sa(stack_a), ra(stack_a));
	else if ((n1 > n2) && (n1 < n3) && (n2 < n3))	//[2, 1, 3]
		return (sa(stack_a));
	else if ((n1 < n2) && (n1 > n3) && (n2 > n3))	//[2, 3, 1]
		return (rra(stack_a));
	else if ((n1 > n2) && (n1 > n3) && (n2 < n3))	//[3, 1, 2]
		return (ra(stack_a));
	else if ((n1 > n2) && (n1 > n3) && (n2 > n3))	//[3, 2, 1]
		return (sa(stack_a), rra(stack_a));
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	pos;

	while (stack_a->size > 3)
	{
		min = ft_min(stack_a);
		pos = min_pos(stack_a, min);

		if (pos <= stack_a->size / 2)
		{
			while (stack_a->start->value != min)
				ra(stack_a);
		}
		else
		{
			while (stack_a->start->value != min)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
