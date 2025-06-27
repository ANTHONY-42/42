#include "minishell.h"

char	*tokeniz(char *str)
{
	if ((str[i] == " " || str[i] == "\t") && str[i + 1])
		i++;

	if (str[i] == "|" && str[i])
	{
		if (str[i + 1] == "|")
			perror("error double pipe");
		i++;
	}

	if (str[i] == ">" && str[i] == "<")

}
