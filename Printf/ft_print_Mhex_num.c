/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_Mhex_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:27:44 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/15 13:23:07 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*num_to_hex(unsigned int num, char *hex)
{
	int	i;
	unsigned int	digit;

	i = 0;
	if (num == 0)
		hex[i] = '0';
	while (num != 0)
	{
		digit = num % 16;
		if (digit < 10)
			hex[i++] = '0' + digit;
		else
			hex[i++] = 'A' + (digit - 10);
		num = num / 16;
	}
	return (hex);
}

static void	print_hex_num(char *hex)
{
	int	len;

	len = strlen(hex);
	while (len >= 0)
		write(1, &hex[len--], 1);
}

int	ft_print_Mhex_num(unsigned int num)
{
	char	*hex;
	int	len;

	hex = (char *)malloc(20);
	if (!hex)
		return (0);
	num_to_hex(num, hex);
	print_hex_num(hex);
	len = strlen(hex);
	free(hex);
	return (len);
}
