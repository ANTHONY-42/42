#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*buffer;	
	int	*nbr_read;


	nbr_read = read(fd, buffer, BUFFER_SIZE);
	return (nbr_read);
}

int main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break;
	}
	//printf("%s", line);
	free(line);
}
