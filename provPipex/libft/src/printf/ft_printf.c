/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:06:54 by egelma-b          #+#    #+#             */
/*   Updated: 2025/03/24 12:58:07 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_selection(va_list args, const char *str)
{
	if (*str == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (*str == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_print_hex_pointer(va_arg(args, void *)));
	else if (*str == 'i' || *str == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_print_unsigned_int(va_arg(args, int)));
	else if (*str == 'x')
		return (ft_print_mhex_num(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_print_mayorhex_num(va_arg(args, unsigned long long)));
	else if (*str == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			length;
	static int	selection = 0;

	va_start(args, str);
	length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (!str[1])
				return (-1);
			selection = print_selection(args, ++str);
			if (selection == -1)
				return (-1);
			length += selection - 1;
		}
		else if (write(1, str, 1) == -1)
			return (-1);
		length++;
		str++;
	}
	va_end(args);
	return (length);
}
