#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int fd = open("test.c", O_RDONLY);
	printf("%d\n", fd);
	char *buf = malloc(40);
	while (1)
		read(0, buf, 40);
}