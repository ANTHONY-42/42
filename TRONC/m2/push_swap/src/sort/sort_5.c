/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:42:18 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/18 10:04:08 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *stack)
{
	int		min;
	t_node	*current;

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
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack->start;
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
	if ((n1 < n2) && (n1 < n3) && (n2 > n3))
		return (sa(stack_a), ra(stack_a));
	else if ((n1 > n2) && (n1 < n3) && (n2 < n3))
		return (sa(stack_a));
	else if ((n1 < n2) && (n1 > n3) && (n2 > n3))
		return (rra(stack_a));
	else if ((n1 > n2) && (n1 > n3) && (n2 < n3))
		return (ra(stack_a));
	else if ((n1 > n2) && (n1 > n3) && (n2 > n3))
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
