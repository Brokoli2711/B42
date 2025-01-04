/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:40:44 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/04 16:44:39 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*s;

	s = (char *)str;
	len = ft_strlen(s);
	if (c == '\0')
		return (&s[len]);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return (&s[len]);
		len--;
	}
	return (NULL);
}
