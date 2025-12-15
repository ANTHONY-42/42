#include <unistd.h>
#include <stdio.h>

int	 main(int ac, char **av)
{
	if (ac > 1)
	{
		int	i = 0;
		int	j = 0;
		int	k = 0;
		int	l = 0;
		char 	*str;
		str = av[1];
		while (str[i] && str[i] <= ' ')
			i++;
		j = i;
		while (str[j] && str[j] > ' ')
			j++;
		while (str[j] && str[j] <= ' ')
			j++;
		if (j == '\0' || str[j] > ' ')
		{
			l = 1;
		}

		while (str[k])
			k++;
		k--;
		while (str[k] <= ' ')
			k--;

		while (str[j] && j <= k)
		{
			if (str[j] <= ' ')
			{
				while (str[j] <= ' ')
				{
					if (j == k)
						break;
					j++;
				}
				write(1, " ", 1);
			}
			write(1, &str[j], 1);
			j++;
		}
		if (l == 1)
		{
			write(1, " ", 1);
		}
		while (str[i] > ' ')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);

}
