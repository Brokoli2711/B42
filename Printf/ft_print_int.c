/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:12:09 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/27 12:15:07 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int c)
{
	char	*num;
	int		i;

	num = ft_itoa(c);
	i = 0;
	while (num[i])
		if (write(1, &num[i++], 1) == -1)
			return (-1);
	free(num);
	return (i);
}
