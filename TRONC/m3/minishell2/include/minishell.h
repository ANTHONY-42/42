#ifndef		MINISHELL_H
# define	MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct  s_cmd
{
        char    **av;
	char	*input;
	char	*output
	int	append;
        struct  s_cmd   *next;
}       t_cmd;


void    free_path(char **path);
char    *absolute_path(char **path, char *cmd);
char    *get_path(char *cmd, char **envp);
void    exec_cmd(char **av, char **envp);
void    executor(t_cmd *cmds, char **envp);
void    *ft_memcpy(void *dst, const void *src, size_t n);
ssize_t ft_strlen(const char *s);
char    *ft_strdup(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
char    **ft_split(const char *s, char c);

#endif
