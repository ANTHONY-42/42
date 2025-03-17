#include "push_swap.h"

void free_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
	    return;

	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void free_stack(t_stack **stack)
{
    t_node *current;
    t_node *tmp;

    if (!stack || !*stack)
        return;

    current = (*stack)->start;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }

    free(*stack);
    *stack = NULL;
}

void free_full(t_stack **stack_a, t_stack **stack_b, char **tab)
{
	if (tab)
		free_tab(tab);

	if (stack_a && *stack_a)
		free_stack(stack_a);
	
	if (stack_b && *stack_b)
		free_stack(stack_b);
}
