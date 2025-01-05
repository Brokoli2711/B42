/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:10:03 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/05 10:42:32 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if(n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if(n >= 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/*
void	ft_putnbr_fd(int n, int fd)
{
	char	*str_num;

	str_num = ft_itoa(n);
	ft_putstr_fd(str_num, fd);
}*/
