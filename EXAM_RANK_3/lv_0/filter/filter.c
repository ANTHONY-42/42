#include <unistd.h>
#include <stdlib.h>
#include <string.h>
# define BUFFER_SIZE	1

void	error(char *str)
{
	int	i;

	i = 0;
	write(2, "Error: ", 7);

	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	len = (strlen(s1) + strlen(s2));
	char	*result = malloc(len + 1);
	if (!result)
		error("malloc");
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char 	*get_str(char *buffer)
{
	char	*str = malloc(1);
	int	len;

	if (!str)
		error("malloc");
	str[0] = 0;

	while ((len = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[len] = 0;
		str = ft_strjoin(str, buffer);
	}
	if (len < 0)
		error("READ");
	return (str);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (strlen(av[1]) == 0)
		return (1);

	char	buffer[BUFFER_SIZE + 1];
	char	*str = get_str(buffer);
	int	wlen = strlen(av[1]);

	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		while (ft_strstr(&str[i], av[1]))
		{
			j = 0;
			while (j < wlen)
			{
				write(1, "*", 1);
				j++;
			}
			i += wlen;
		}
		write(1, &str[i], 1);
		i++;
	}
	free (str);
}
