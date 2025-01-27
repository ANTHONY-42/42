# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	main(int argc, char **argv)
{
	//t_stack	*stack_a;
	//t_stack	*stack_b;

	if (argc < 2)
		return (perror("Erreur : argc < 2"), 1);

	stack_a = initialize_stack(argv);
	if (!stack_a)
	{
		free_stack(stack_a);
		ft_putstr_fd("Erreur : Memory allocation failed\n", 2);
		return (1);
	}

	stack_b = creat_stack(stack_a->size);
	if (!stack_b)
	{
		free_stack(stack_a);
		return (perror("Erreur : memoire stack_b"), 1);
	}

	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}


}
