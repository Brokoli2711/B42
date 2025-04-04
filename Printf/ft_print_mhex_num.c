/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mhex_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:51:42 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/27 12:25:22 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_to_hex(unsigned int num)
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

static int	len_hex(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		i++;
		num /= 16;
	}
	return (i);
}

int	ft_print_mhex_num(unsigned int num)
{
	int	len;

	if (num_to_hex(num) == -1)
		return (-1);
	if (num == 0)
		if (write(1, "0", 1) == -1)
			return (-1);
	len = len_hex(num);
	return (len);
}
