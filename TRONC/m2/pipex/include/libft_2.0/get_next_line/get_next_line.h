/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:45:31 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/22 19:42:47 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// BIBLIOTHEQUE
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

//	get_next_line_utils
// int		ft_strlen(char *str);
// char	*ft_strcpy(char *s1, char *s2);
// char	*ft_strchr(const char *str, int c);
// char	*ft_strdup(const char *str);
// char	*ft_strjoin(char *trace, char *buffer);

//	get_next_line
char	*extract_trace(int fd, char *buffer, char *trace);
char	*extract_line(char *trace);
char	*maj_trace(char *trace);
char	*machine(int fd, char *buffer, char **trace, char *line);
char	*get_next_line(int fd);
int		file_exists(const char *filename);
#endif
