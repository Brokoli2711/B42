/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:12:01 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/15 13:14:28 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned_int(unsigned int c)
{
	char	*num;
	int	i;
	
	num = ft_itoa((int)c);
	i = 0;
	while (num[i])
		write(1, &num[i++], 1);
	free(num);
	return (i);
}
