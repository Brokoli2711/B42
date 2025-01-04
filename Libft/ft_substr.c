/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:41:54 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/02 13:35:00 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
