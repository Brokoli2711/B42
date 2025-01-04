/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:39:24 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/02 13:34:17 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *str, size_t n)
{
	char	*sr;
	char	*s;
	size_t	i;
	size_t	j;

	sr = (char *)src;
	s = (char *)str;
	i = 0;
	if (*s == '\0')
		return ((char *)src);
	while (*sr != '\0' && i < n)
	{
		j = 0;
		while ((sr[j] == s[j]) && (i + j) < n)
		{
			if (s[j + 1] == '\0')
				return (sr);
			j++;
		}
		sr++;
		i++;
	}
	return ((char *)src);
}
