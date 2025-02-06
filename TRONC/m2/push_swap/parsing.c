#include <unistd.h>
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (stack)
	{
		current = stack->head;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		free(stack);
	}
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack->head)
		stack->head = new_node;
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

//	CREER UN STACK VIDE
t_stack	*create_stack_b(int size)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	stack_b->head = NULL;
	stack_b->size = size;

	return (stack_b);
}

// 	INITIALISE LA STACK
t_stack	*init_stack_a(char **argv)
{
	t_stack	*stack_a;
	t_node	*new_node;

	int	i;
	int	value;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);

	stack_a->head = NULL;
	stack_a->size = 0;
	i = 1; 
	
	
	while (argv[i])
	{
		if (!number_valid(argv[i], stack_a))
		{
			free_stack(stack_a);
			perror("Erreur : init stack_a\n");
			exit(1);
		}

		value = ft_atoi(argv[i]);
		new_node = create_node(value);
		if (!new_node)
		{
			free_stack(stack_a);
			exit(1);
		}
		add_node_back(stack_a, new_node);
		i++;
	}
	return (stack_a);
}


//	VERIFIE SI LA PILE ES DEJA TRIER
int	is_sorted(t_stack *stack)
{
	
}

