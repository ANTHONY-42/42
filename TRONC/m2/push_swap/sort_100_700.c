#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_node *current = stack->head;  // Pointeur pour parcourir chaque élément de la pile
	t_node *compare;                // Pointeur pour comparer avec les autres éléments
	int index;                      // Stocke l'indice pour chaque élément

	while (current)                 // Boucle sur chaque élément de la pile
	{
		index = 0;                  // On initialise l'index à 0 pour chaque élément
		compare = stack->head;      // On recommence à comparer depuis le début de la pile

		while (compare)             // Boucle pour comparer l'élément actuel avec les autres
		{
			if (current->value > compare->value)
				index++;            // Si current est plus grand, on incrémente l'index
			compare = compare->next; // Passe à l'élément suivant pour comparer
		}

		current->index = index;     // On attribue l'index final à l'élément actuel
		current = current->next;    // Passe à l'élément suivant dans la pile
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max_bits = 0;
	int size = stack_a->size;
	int i, j;

	// Trouver le nombre de bits nécessaires pour représenter l'élément le plus grand
	int max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;

	for (i = 0; i < max_bits; i++)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->head->index >> i) & 1) == 1)
				ra(stack_a);       // Si le bit est 1, on fait une rotation
			else
				pb(stack_a, stack_b);  // Si le bit est 0, on pousse dans stack_b
			j++;
		}

		while (stack_b->size > 0)
			pa(stack_a, stack_b);  // On ramène tous les éléments dans stack_a
	}


