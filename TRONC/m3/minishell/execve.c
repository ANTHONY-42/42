#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int ac, char **av, char **envp)
{
	execve(av[1], &av[1], envp);
}
