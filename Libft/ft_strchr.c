/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:32:47 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/04 16:30:36 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	if (c == '\0')
		return (&s[strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (s);
		s++;
		i++;
	}
	return (NULL);
}
