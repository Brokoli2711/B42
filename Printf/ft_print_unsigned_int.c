/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:12:01 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/21 13:13:55 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long pow(int x, int y)
{
	int	i;
	int	num;

	i = 0;
	num = x;
	while (i < y)
	{
		x *= num;
		i++;
	}
	return (x);
}

int	ft_print_unsigned_int(unsigned int c)
{
	char	*num;
	int	i;
	
	if (c < 0) 
		c = pow(2, 32) + c;
	num = ft_itoa(c);
	i = 0;
	while (num[i])
		write(1, &num[i++], 1);
	free(num);
	return (i);
}
