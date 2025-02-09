#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node *current = stack->head;
	int min = current->value;

	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return min;
}

void	sort_3(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;

	if (first > second && second < third && first < third)
		sa(stack_a);                  // Cas: [2, 1, 3] → [1, 2, 3]

	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);                 // Cas: [3, 2, 1] → [1, 2, 3]
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);                  // Cas: [2, 3, 1] → [1, 2, 3]

	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);                  // Cas: [1, 3, 2] → [1, 2, 3]
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);                 // Cas: [3, 1, 2] → [1, 2, 3]
}

void	sort_4_5(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		int min = find_min(stack_a);

		// Si le plus petit est en haut de la pile
		if (stack_a->head->value == min)
			pb(stack_a, stack_b);  // Déplacer le plus petit dans stack_b
		else
			ra(stack_a);           // Tourner jusqu'à avoir le plus petit en haut
	}

	sort_3(stack_a);               // Trier les 3 éléments restants

	while (stack_b->size > 0)
		pa(stack_a, stack_b);      // Ramener les éléments de stack_b à stack_a
}
