/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:30:52 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/07 11:51:33 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned long		i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*int	main(void)
{
	char	str1[] = "Hola";
	char	str2[] = "NAU";

	//printf("%s", str1);
	ft_memcpy(str1, str2, strlen(str2) + 1);
	printf("%s", str1);
	return (0);
}*/
