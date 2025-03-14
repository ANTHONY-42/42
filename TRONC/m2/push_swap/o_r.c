#include "push_swap.h"

int	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack || !stack->start || !stack->start->next)
		return (0);
	
	tmp = stack->start;
	stack->start = stack->start->next;
	
	current = stack->start;
	while (current->next)
		current = current->next;
	
	current->next = tmp;
	tmp->next = NULL;
	return (1);
}

void	ra(t_stack *stack_a)
{
	if (rotate(stack_a))
		printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	if (rotate(stack_b))
		printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	rot_a;
	int	rot_b;

	rot_a = rotate(stack_a);
	rot_b = rotate(stack_b);
	if (rot_a || rot_b)
		printf("rr\n");
}
