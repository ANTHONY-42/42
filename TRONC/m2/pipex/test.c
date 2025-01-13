#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid;
	int pipe_fd[2];

	pipe(pipe_fd);
	// pipe_fd[0]
	// pipe_fd[1]
	pipe_fd[1] = open("file.txt", O_WRONLY);
	pipe_fd[0] = open("file.txt", O_RDONLY);
	write(pipe_fd[1], "salut", 5);
	char *buf = malloc(5);
	read(pipe_fd[0], buf, 5);
	printf("%s\n", buf);
	
	pid = fork();
	if (pid == 0)
	{
		//dup2 donne la valeur du deuxieme au premier
		dup2(pipe_fd[1], 1);
		printf("salut");
	}
	else 
	{
		wait(NULL);
		dup2(pipe_fd[0], 0);
	}
	
		// write(1, "salut", 5);
}