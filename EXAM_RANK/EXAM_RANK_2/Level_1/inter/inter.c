#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	char repeat[256];

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	while (repeat[k])
	{
		repeat[k] = 0;
		k++;
	}
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{
				if (repeat[argv[1][i]] == 0)
				{
					write(1, &argv[1][i], 1);
					repeat[argv[1][i]] = 1;
				}
			}
		j++;
		}
	i++;
	}
	write(1, "\n", 1);
}
