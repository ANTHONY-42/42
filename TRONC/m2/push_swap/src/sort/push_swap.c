/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:41:13 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/18 10:20:51 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		free_stack(&stack_a);
		free_stack(&stack_b);
		exit(1);
	}
	else if (size == 2)
		sa(stack_a);	
	else if (size > 2 && size <= 5)
		sort_5(stack_a, stack_b);
	else
		k_sort(stack_a, stack_b);
}
