/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:34:21 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/17 17:34:31 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack || !stack->start || !stack->start->next)
		return (0);
	current = stack->start;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = stack->start;
	stack->start = tmp;
	return (1);
}

void	rra(t_stack *stack_a)
{
	if (reverse_rotate(stack_a))
		printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	if (reverse_rotate(stack_b))
		printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	rr_a;
	int	rr_b;

	rr_a = reverse_rotate(stack_a);
	rr_b = reverse_rotate(stack_b);
	if (rr_a || rr_b)
		printf("rrr\n");
}
