/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:06:54 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/14 13:13:38 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "prints.h"

static int	print_selection(va_list args, const char *str)
{
	str++;
	if (*str == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	else if (*str == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_print_hex_pointer(va_arg(args, void *)));
	else if (*str == 'd')
		return (0);
	else if (*str == 'i')
		return (0);
	else if (*str == 'u')
		return (0);
	else if (*str == 'x')
		return (0);
	else if (*str == 'X')
		return (0);
	else if (*str == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	size_t	length;

	va_start(args, str);
	length = 0;
	while(*str)
	{
		if (*str == '%')
			length += print_selection(args, str++);
		else
		{
			write(1, str, 1);
			length++;
		}
		str++;
	}
	va_end(args);
	return (0);
}

int	main()
{
	ft_printf("%c con %s", 'a', "patatas");
	return(0);
}
