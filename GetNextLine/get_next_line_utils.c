/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:58:08 by egelma-b          #+#    #+#             */
/*   Updated: 2025/02/03 14:12:27 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(char *s)
{
	unsigned long int	i;

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
	char	*s;
	unsigned long int	i;

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

char	*ft_strcat(char *s1, char *s2)
{
	char	*s;
	int	i;

	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s || !s1 || !s2)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	i = -1;
	while (s2[++i] !0 '\0')
		s[ft_strlen(s1) + i] = s2[i];
	s[ft_strlen(s1) + 1] = '\0';
	return (s);
}
