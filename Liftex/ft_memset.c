/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:29:19 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/02 13:28:07 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	value;

	p = (unsigned char *)s;
	value = (unsigned char)c;
	while (n--)
		*p++ = value;
	return (s);
}
/*
int	main(void)
{
	char	str[5];

	str = "hola"
	ft_memset(str, 'A', 5);
	printf("%s", str);
}*/
