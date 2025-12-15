#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i;
		int	j;

		i = 0;
		j = 0;

		if (!av[1][i])
		{
			write(1, "\n", 1);
			return (0);
		}
		while (av[1][i] <= ' ')
			i++;
		//j = strlen(av[1]) - 1;
		while (av[1][j + 1])
			j++;
		
		while (j > i && av[1][j] <= ' ')
			j--;
		
		if (j < i)
		{
			write(1, "\n", 1);
			return (0);
		}
		while (i <= j)
		{
			if (av[1][i] <= ' ')
			{
				while (i <= j && av[1][i] <= ' ')
					i++;
				if (i <= j)
					write(1, "   ", 3);
			}
			if (i <= j && av[1][i] > ' ')
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
