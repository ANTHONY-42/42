#include <unistd.h>
#include <stdlib.h>

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE	42
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	nb_read		= 0;
	static int	pos_buff	= 0;
	char	*line		= malloc(70000);

	if (!line)
		return (NULL);

	while (1)
	{
		if (pos_buff >= nb_read)
		{
			nb_read = read(fd, buffer, BUFFER_SIZE);
			if (nb_read <= 0)
				break;
			pos_buffer = 0;
		}
		line[i++] = buffer[pos_buff++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
