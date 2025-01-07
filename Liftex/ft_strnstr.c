/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:39:24 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/04 23:26:06 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *str, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str[i] == '\0')
		return ((char *)src);
	while (src[i] != '\0' && i < n)
	{
		j = 0;
		while ((src[i + j] == str[j]) && (i + j) < n)
		{
			if (str[j + 1] == '\0')
				return ((char *)&src[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
