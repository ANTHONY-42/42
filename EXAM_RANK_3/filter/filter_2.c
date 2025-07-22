#include <unistd.h>
#include <stdlib.h>
#define	BUFFER_SIZE 4096

void	error(char *str)
{
	int	 i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	exit (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (1);
}

char	*read_stdin(char *buf)
{
	ssize_t	len;

	len = read(0, buf, BUFFER_SIZE - 1);
	if (len <= 0)
		return (NULL);
	buf[len] = '\0';
	return (buf);
}

int	main(int ac, char **av)
{
	char	buf[BUFFER_SIZE];
	char	*str;
	char	next;
	int	wlen;
	int	j;
	ssize_t	i;

	i = 0;
	if (ac != 2)
		error("Error arg");

	str = read_stdin(buf);
	if (!str)
		error("Error txt");

	wlen = ft_strlen(av[1]);
	while (str[i])
	{
		if (ft_strncmp(&str[i], av[1], wlen) == 0)
		{
			next = str[i + wlen];
			if (next == ' ' || next == '\n' || next == '\0')
			{
				j = 0;
				while (j++ < wlen)
					write(1, "*", 1);
				i += wlen;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
}
