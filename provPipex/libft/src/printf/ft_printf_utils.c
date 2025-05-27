/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:59:10 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:15:35 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	len_hex(unsigned long long iptr)
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

int	point_to_hex(unsigned long long iptr)
{
	unsigned long long	digit;
	char				cdigit;

	if (iptr == 0)
		return (0);
	if (point_to_hex(iptr / 16) == -1)
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

int	num_to_hex(unsigned int num)
{
	unsigned int	digit;
	char			ndigit;

	if (num == 0)
		return (0);
	if (num_to_hex(num / 16) == -1)
		return (-1);
	digit = num % 16;
	if (digit < 10)
		ndigit = '0' + digit;
	else
		ndigit = 'a' + (digit - 10);
	if (write(1, &ndigit, 1) == -1)
		return (-1);
	return (0);
}
