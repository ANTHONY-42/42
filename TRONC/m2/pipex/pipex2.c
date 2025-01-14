#include <stdio.h>
#include <unistd.h> 

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	pid[2];
	int	i;
	char	**env;
	
	/*i = 0;
	while (envp[i])
	{
		env = ft_split(envp, '=');
		while (env[j])
		{
			if (ft_strncmp(env[j], "PATH", 4) == 0)
			{
				printf("%s", );
			}
		}
		printf("%s\n", envp[i]);
		i++;
	}*/

	if (access(argv[1], F_OK) == 0)
		printf("ok");
	return 0;
}
