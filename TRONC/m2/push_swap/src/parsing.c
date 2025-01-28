#include <unistd.h>

// 	INITIALISE LA STACK
t_stack	*init_stack(char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

//	CREER UN STACK VIDE
t_stack	*create_stack(int size)
{
	
}

//	VERIFIE SI LA PILE ES DEJA TRIER
int	is_sorted(t_stack *stack)
{
	
}

void	free_stack(t_stack *stack)
{
	
}
