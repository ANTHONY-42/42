#include <unistd.h>

ssize_t	ft_strlen(char *str)
{
	ssize_t	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, ssize_t len)
{
	write(1, str, len);
	write(1, "\n", 1);
}

void	ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort(char *str)
{
	ssize_t		i = 0;
	ssize_t		j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	ft_permute(char *str, ssize_t l, ssize_t r)
{
	ssize_t	i = l;
	if (l == r)
	{
		ssize_t	len = r + 1;
		ft_putstr(str, len);
		return ;
	}

	while (i <= r)
	{
		ft_sort(&str[l]);
		ft_swap(&str[i], &str[l]);
		ft_permute(str, l + 1, r);
		ft_swap(&str[i], &str[l]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char		*str = av[1];
	ssize_t		len = ft_strlen(av[1]);

	ft_sort(str);
	ft_permute(str, 0, len - 1);
}
