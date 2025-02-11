#include "push_swap.h"

void index_stack(t_stack *stack)
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

void print_stack(t_stack *stack)
{
    t_node *current = stack->head;
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;

	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result  = result * 10 + (str[i] - '0');
			i++;
	}
	return (result * sign);
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
