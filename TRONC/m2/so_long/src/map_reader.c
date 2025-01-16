#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **map_read(const char *file_path)
{
    int fd;
    char **map;
    char buffer[1024];
    int bytes_read;
    int i;

    i = 0;
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur ouverture map");
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
