/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:14:03 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/17 17:14:06 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack_1, t_stack *stack_2)
{
	t_node	*tmp;

	if (!stack_1 || !stack_2 || !stack_2->start)
		return (0);
	tmp = stack_2->start;
	stack_2->start = stack_2->start->next;
	tmp->next = stack_1->start;
	stack_1->start = tmp;
	stack_1->size++;
	stack_2->size--;
	return (1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b))
		printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a))
		printf("pb\n");
}
