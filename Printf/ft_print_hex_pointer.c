/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:17:52 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/21 12:43:16 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned long long iptr)
{
	int	i;

	i = 0;
	if (iptr == 0)
		return (3);
	while (iptr != 0)
	{
		i++;
		iptr /= 16;
	}
	return (i + 2);
}

static int	point_to_hex(unsigned long long iptr)
{
	unsigned long long	digit;
	char	cdigit;
	if (iptr == 0)
		return (0);
	if (point_to_hex(iptr/16) == -1)
		return (-1);
	digit = iptr % 16;
	if (digit < 10)
		cdigit = '0' + digit;
	else
		cdigit = 'a' + (digit - 10);
	if (write(1, &cdigit, 1) == -1)
		return (-1);
	return (0);
}

int	ft_print_hex_pointer(void *ptr)
{
	unsigned long long	iptr;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	iptr =	(unsigned long long)ptr;
	if(write(1, "0x", 2) == -1 || point_to_hex(iptr) == -1)
		return (-1);
	return(len_hex(iptr));
}
