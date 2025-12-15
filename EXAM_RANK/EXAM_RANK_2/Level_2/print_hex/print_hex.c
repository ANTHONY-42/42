#include <unistd.h>

void	ft_putnbr(int nb)
{
	char *hex = "0123456789abcdef";
	
	if (nb >= 16)
		ft_putnbr(nb / 16);
	write(1, &hex[nb % 16], 1);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	int i = 0;
	int  nb;

	if (argc == 2)
	{
		nb = ft_atoi(&argv[1][i]);
		ft_putnbr(nb);
	}
	write(1, "\n", 1);
	return (0);
}
