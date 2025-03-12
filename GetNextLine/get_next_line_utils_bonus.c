/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:58:08 by egelma-b          #+#    #+#             */
/*   Updated: 2025/02/11 12:06:47 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long	ft_strlen(char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *sline, int c)
{
	unsigned long int	i;

	i = 0;
	while (sline[i] != c && sline[i] != '\0')
		i++;
	if (sline[i] == c)
		return (sline);
	return (NULL);
}

void	ft_bzero(void *str, unsigned long int n)
{
	char			*s;
	unsigned long	i;

	s = (char *)str;
	i = 0;
	while (i < n)
		s[i++] = '\0';
}

void	*ft_calloc(unsigned long int size, unsigned long int c)
{
	char	*result;

	result = malloc(size * c);
	if (!result)
		return (NULL);
	ft_bzero(result, (size * c));
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
