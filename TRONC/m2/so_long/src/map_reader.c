#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **read_map(const char *file_path)
{
    char **map;
    char buffer[1024];
    int bytes_read;
    int i;
    int fd;

    i = 0;
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (NULL);
    }

    map = malloc(100 * sizeof(char *)); // Maximum de 100 lignes pour l'exemple

    while ((bytes_read = read(fd, buffer, 1023)) > 0)
    {
        buffer[bytes_read] = '\0';
        map[i] = strdup(buffer);
        i++;
    }
    map[i] = NULL; // Terminez par un pointeur NULL
    close(fd);

    return (map);
}
