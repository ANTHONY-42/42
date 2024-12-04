/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:20:38 by anturtsc          #+#    #+#             */
/*   Updated: 2024/09/28 17:27:06 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int main()
{
	char dest[10];
	char src[] = "strncpy";
	int n = 100;
	ft_strncpy(dest, src, n);
	printf("DEST = %s \n----TEST----\nSRC = %s \nN = %d", dest, src, n);
}*/
		/*printf("src[%d] : %c\n",i,src[i]);
		dest[i] = src[i];
		printf("dest[%d] : %c\n",i,dest[i]);
		i++;*/
