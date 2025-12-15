#include <stdio.h>
#include <limits.h>

int max(int* tab, unsigned int len)
{
	int	i;
	int	nb;

	i = 0;
	nb = tab[i];

	if (len == 0)
		return (0);

	while (i < len)
	{
		if (tab[i] > nb)
			nb = tab[i];
		i++;
	}
	return (nb);
}
