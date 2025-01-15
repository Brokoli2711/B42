/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:12:09 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/15 13:13:27 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_int(int c)
{
	char	*num;
	int	i;

	num = ft_itoa(c);
	i = 0;
	while (num[i])
		write(1, &num[i++], 1);
	free(num);
	return (i);
}
