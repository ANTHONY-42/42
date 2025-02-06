#include "push_swap.h"

// verifie si c'est un nombre;
int     is_number(char *str)
{
        int     i;
        i = 0;

        if (str[i] == '-' || str[i] == '+')
                i++;
        if (!str[i])
                return (0);

        while (str[i])
        {
                if (!(str[i] >= '0' && str[i] <= '9'))
                        return (0);
                i++;
        }
        return (1);
}

// verifie si c'est un int;
int	is_int(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

// verifie si c'est un double;
int	is_double(int nb, t_stack *a)
{
	t_node	*check_double;
	check_double = a->head;
	if (!a)
		return (0);
	while (check_double)
	{
		if (check_double->value == nb)
			return (1);
		check_double = check_double->next;
	}
	return (0);
}

// appel de fonction : verifie si c'est un nombre;
int	number_valid(char *argv, t_stack *stack_a)
{
	if (!(is_number(argv)))
		return (0);

	if (!(is_int(argv)))
		return (0);

	if (is_double(ft_atoi(argv), stack_a))
		return (0);
	return (1);
}
