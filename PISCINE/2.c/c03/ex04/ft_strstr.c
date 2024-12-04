/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:08:47 by anturtsc          #+#    #+#             */
/*   Updated: 2024/10/02 15:56:35 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (&str[i]);
			}
			j++;
		}
	j = 0;
	i++;
	}
	return (0);
}

/*#include <stdio.h>
#include<string.h>
int main()
{
        char    str[] = "";
        char    to_find[] = "";

        printf("moi:%s\n", ft_strstr(str, to_find));
        printf("vraie:%s", strstr(str, to_find));

}*/
