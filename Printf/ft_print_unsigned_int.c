/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:12:01 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/27 12:26:18 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(int c)
{
	char			*num;
	unsigned int	unum;
	int				i;

	unum = (unsigned int)c;
	num = ft_uitoa(unum);
	if (!num)
		return (-1);
	i = 0;
	while (num[i])
		if (write(1, &num[i++], 1) == -1)
			return (-1);
	free(num);
	return (i);
}
