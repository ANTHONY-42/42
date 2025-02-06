#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return;

	t_node *current = stack_a->head;
	t_node *tmp = NULL;

	while (current->next->next)
		current = current->next;

	tmp = current->next;
	current->next = NULL;

	tmp->next = stack_b->head;
	stack_b->head = tmp;
}

void	rrb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return;

	t_node *current = stack_b->head;
	t_node *tmp = NULL;

	while (current->next->next)
		current = current->next;

	tmp = current->next;
	current->next = NULL;

	tmp->next = stack_b->head;
	stack_b->head = tmp;
}

void	rrr(t_stack *stack_a, t_stack stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
