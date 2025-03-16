#include "push_swap.h"

int    define_tolerance(t_stack *stack_a)
{
	int    size_a;
	int    tolerance;

	size_a = stack_a->size;
	if (size_a <= 20)
		tolerance = 7;
	else if (size_a <= 50)
		tolerance = 12;
	else if (size_a <= 100)
		tolerance = 17;
	else if (size_a <= 150)
		tolerance = 22;
	else if (size_a <= 200)
		tolerance = 27;
	else if (size_a <= 250)
		tolerance = 32;
	else if (size_a <= 300)
		tolerance = 35;
	else if (size_a > 300)
		tolerance = 45;
	return (tolerance);
}

int	pos_max(t_stack *stack_b, int max)
{
	int	index;
	int	count;
	t_node *current;

	count = 0;
	current = stack_b->start;
	while (current)
	{
		index = current->index;
		if (index == max)
			return (count);
		current = current->next;
		count++;
	}
	return (-1);
}

void	pa_max(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	max;

	max = ((stack_b->size) -1);
	while (stack_b->size)
	{
		index = stack_b->start->index;
		if (index == max || index == (max - 1))
		{
			pa(stack_a, stack_b);
			if (stack_a->start->index == max)
				max--;
			if (stack_a->size > 1 && (stack_a->start->index) > (stack_a->start->next->index))
			{
				sa(stack_a);
				max--;
			}
		}
		else
		{
			if ((pos_max(stack_b, max)) < ((stack_b->size) / 2))
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	pb_min(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	pushed;
	int	tolerance;
	int	max;

	pushed = 0;
	tolerance = define_tolerance(stack_a);
	while (stack_a->size)
	{
		index = stack_a->start->index;
		if (index <= (pushed + tolerance))
		{
			pb(stack_a, stack_b);
			if (index < pushed && stack_b->size > 1)
				rb(stack_b);
			pushed++;
			tolerance = define_tolerance(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	k_sort(t_stack *stack_a, t_stack *stack_b)
{
	pb_min(stack_a, stack_b);
	pa_max(stack_a, stack_b);
}
