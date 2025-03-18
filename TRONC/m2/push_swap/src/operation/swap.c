/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:38:21 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/17 17:38:33 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->start || !stack->start->next)
		return (0);
	tmp = stack->start->next;
	stack->start->next = tmp->next;
	tmp->next = stack->start;
	stack->start = tmp;
	return (1);
}

void	sa(t_stack *stack_a)
{
	if (swap(stack_a))
		printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	if (swap(stack_b))
		printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	swap_a;
	int	swap_b;

	swap_a = swap(stack_a);
	swap_b = swap(stack_b);
	if (swap_a || swap_b)
		printf("ss\n");
}
