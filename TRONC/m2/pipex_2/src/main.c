int main(int ac, char **av, char **envp)
{
	if (ac != 5)
		error("ac != 5");
	
	int	input;
	int	output;

	input = open(av[1], O_RDONLY);
	if (input < 0)
		error("open input");
	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output < 0)
		error("open output");

	pipex(ac, av, envp, input, output);
	close(input);
	close(output);
	return (0);
}
