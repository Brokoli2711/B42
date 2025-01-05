/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:38:22 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/05 01:16:00 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_if_symbols(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static size_t	count_size(int n)
{
	size_t	count;

	count = 0;
	if (check_if_symbols(n) == 1)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_size(n);
	ptr = (char *)malloc(size * sizeof(char) + 1);
	ptr[size] = '\0';
	if (check_if_symbols(n) == 1)
	{
		ptr[0] = '-';
		n *= -1;
	}
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
