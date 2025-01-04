/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:26:46 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/02 13:29:25 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words(const char *s, char c)
{
	size_t	count;

	if (*s == '\0')
		return (0);
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	w_len;
	int		i;

	ptr = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!ptr || !s)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			if (!ft_strchr((char *)s, c))
				w_len = ft_strlen((char *)s);
			else
				w_len = ft_strchr((char *)s, c) - s;
			ptr[i++] = ft_substr((char *)s, 0, w_len);
			s += w_len;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
