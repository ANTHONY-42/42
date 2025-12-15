#include "minishell.h"

void    free_path(char **path)
{
        int     i;

        i = 0;
	if (!path)
		return;
        while (path[i])
                free(path[i++]);
        free(path);
}

char    *absolute_path(char **path, char *cmd)
{
        int             i;
        char    *pathname;
        char    *path_tmp;

        i = 0;
        while (path[i])
        {
                path_tmp = ft_strjoin(path[i], "/");
                pathname = ft_strjoin(path_tmp, cmd);
                free(path_tmp);
                if (access(pathname, X_OK) == 0)
                        return (pathname);
                free(pathname);
                i++;
        }
        return (NULL);
}

char    *get_path(char *cmd, char **envp)
{
        int             i;
        char    **path;
        char    *pathname;

        i = 0;
        if (access(cmd, X_OK) == 0)
                return (cmd);
        while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
                i++;
        if (!envp[i])
                return (NULL);
        path = ft_split(envp[i] + 5, ':');
        if (!path)
                return (NULL);
        pathname = absolute_path(path, cmd);
        free_path(path);
        return (pathname);
}

void	exec_cmd(char **av, char **envp)
{
        pid_t   pid;
        int     status;
	char	*cmd_path;


	if (ft_strchr(av[0], '/'))
		cmd_path = ft_strdup(av[0]);
	else
		cmd_path = get_path(av[0], envp);
	if (!cmd_path)
	{
		perror("cmd not found");
		exit (1);
	}
        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                exit(1);
        }

        if (pid == 0)
        {
		apply_redir(cmd);
                execve(av[0], &av[0], envp);
                perror("execve");
                exit(1);
        }

        if (waitpid(pid, &status, 0) == -1)
        {
                perror("waitpid");
                exit(1);
        }
}

void	executor(t_cmd *cmds, char **envp)
{
	while (cmds)
	{
		exec_cmd(cmds->av, envp);
		cmds = cmds->next;
	}
}

int main(int ac, char **av, char **envp)
{
	if (ac != 1 && av[6])
		return (1);
	char	*cmd1_av[] = {"/bin/echo", "Hello", NULL};
	char	*cmd2_av[] = {"/bin/ls", "-l", NULL};
	char	*cmd3_av[] = {"/bin/pwd", NULL};
	
	t_cmd	cmd3 = {cmd3_av, NULL};
	t_cmd	cmd2 = {cmd2_av, &cmd3};
	t_cmd	cmd1 = {cmd1_av, &cmd2};
	executor(&cmd1, envp);
	return (0);
}

