#include "push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->head)
		return;

	t_node *tmp = stack_a->head;
	stack_a->head = stack_a->head->next;

	tmp->next = stack_b->head;
	stack_b->head = tmp;

	stack_a->size--;
	stack_b->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b || !stack_b->head)
		return;

	t_node *tmp = stack_b->head;
	stack_b->head = stack_b->head->next;

	tmp->next = stack_a->head;
	stack_a->head = tmp;

	stack_b->size--;
	stack_a->size++;
}
