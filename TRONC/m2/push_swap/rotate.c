#include "push_swap.c"

void	ra(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || stack_a->head->next)
		return;

	t_node *tmp = stack_a->head;

	stack_a->head = stack_a->head->next;
	tmp->next = NULL;

	t_node *current = stack_a->head;
	while (current->next)
		current = current->next;

	current->next = tmp;
}


void	rb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return;

	t_node *tmp = stack_b->head;
	
	stack_b->head = stack_b->head->next;
	tmp->next = NULL;

	t_node *current = stack_b->head;
	while (current->next)
		current = current->next;

	current->next = tmp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
