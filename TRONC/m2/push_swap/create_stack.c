#include "push_swap.h"

void    index_stack(t_stack *stack)
{
        int     index;
        t_node  *current;
        t_node  *cmp;

        current = stack->start;
        while (current)
        {
                index = 0;
                cmp = stack->start;
                while (cmp)
                {
                        if (current->value > cmp->value)
                                index++;
                        cmp = cmp->next;
                }
                current->index = index;
                current = current->next;
        }
}

void	add_node(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack->start)
		stack->start = new_node;
	else
	{
		current = stack->start;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error();
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*create_stack_b(void)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		error();
	stack_b->start = NULL;
	stack_b->size = 0;
	return (stack_b);
}

t_stack	*create_stack_a(char **tab)
{
	int		i;
	int		value;
	t_node	*new_node;
	t_stack	*stack_a;

	i = 0;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		error();
	stack_a->start = NULL;
	stack_a->size = 0;
	while (tab[i])
	{
		value = ft_atoi(tab[i]);
		new_node = create_node(value);
		if (!new_node)
			error();
		add_node(stack_a, new_node);
		i++;
	}
	index_stack(stack_a);
	return (stack_a);
}
