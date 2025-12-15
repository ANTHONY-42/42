#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int main()
{
	char *line;

	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		if (line)
			printf("Tu as tapé : %s\n", line);
		free(line);
	}
	return (0);
}
