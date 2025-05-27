/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:10:33 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:17:21 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_print_hex_pointer(void *ptr)
{
	unsigned long long	iptr;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	iptr = (unsigned long long)ptr;
	if (write(1, "0x", 2) == -1 || point_to_hex(iptr) == -1)
		return (-1);
	return (len_hex(iptr));
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

int	ft_print_mayorhex_num(unsigned int num)
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
