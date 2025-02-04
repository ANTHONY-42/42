#include <unistd.h>

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
		current->next = = new_node;
	}
	stack->size++;
}

// 	INITIALISE LA STACK
t_stack	*init_stack(char **argv)
{
	t_stack	*stack;
	t_node	*new_node;

	int	i;
	int	value;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);

	stack->head = NULL;
	stack->size = 0;
	i = 1; // On commence à argv[1] car argv[0] est le nom du programme
	
	
	while (argv[i])
	{
		if (!is_valid_number(argv[i], &a))
		{
			free_stack(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}


		value = ft_atoi(argv[i]);
		new_node = creat_node(value);
		if (!new_node)
		{
			free_stack(stack);
			exit(1);
		}
		add_node_back(stack, new_node);
		i++;
	}
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
