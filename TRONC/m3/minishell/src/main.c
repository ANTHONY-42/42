#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char	*input;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
		{
			printf("exit\n");
			break;
		}
		add_history(input);
		printf("%s\n", input);
		free(input);
	}
	return (0);
}
