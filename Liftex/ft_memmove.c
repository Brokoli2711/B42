/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:25:27 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/02 13:27:51 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*lastd;
	unsigned char	*lasts;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		lastd = d + (n - 1);
		lasts = s + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "patata";
	char	str2[] = "hola";

	ft_memmove(str1, str2, strlen(str2) + 1);
	printf("%s", str1);
	return (0);
}*/
