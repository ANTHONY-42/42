#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (perror("Erreur : argc < 2"), 1);


	stack_a = init_stack_a(argv);
	if (!stack_a)
	{
		free_stack(stack_a);
		return (perror("Erreur : malloc stack_a\n"), 1);
	}

	stack_b = create_stack_b(stack_a->size);
	if (!stack_b)
	{
		free_stack(stack_a);
		return (perror("Erreur : malloc stack_b"), 1);
	}
	/*
	   if (is_sorted(stack_a))
	   {
	   free_stack(stack_a);
	   free_stack(stack_b);
	   return (0);
	   }*/

	printf("Stack A :\n");
	print_stack(stack_a);
	printf("Stack B (vide) :\n");
	print_stack(stack_b);

	// Libération de la mémoire
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
