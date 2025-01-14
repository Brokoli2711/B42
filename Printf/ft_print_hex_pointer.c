/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:17:52 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/14 19:38:37 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prints.h"
#include "utils/Libft/libft.h"

static char	*pointer_to_hex(int *iptr, char *hex)
{
	unsigned int hex_value;
	int	i;
	unsigned int	digit;

	hex_value = (unsigned int)*iptr;
	i = 0;
	while (hex_value != 0)
	{
		digit = hex_value % 16;
		if (digit < 10)
			hex[i++] = '0' + digit;
		else
			hex[i++] = 'a' + (digit - 10);
		hex_value /= 16;
	}
	return (hex);
}

static	int print_hex_pointer(char *hex)
{
	int	len;

	len = ft_strlen(hex);
	write(1, "0x", 2);
	while(len > 0)
		write(1, &hex[len--], 1);
	return(ft_strlen(hex));
}

int	ft_print_hex_pointer(void *ptr)
{
	int	*iptr;
	char	*hex;
	int	len;

	iptr =	ptr;
	hex = (char *)malloc(20);
	if(!hex)
		return (0);
	pointer_to_hex(iptr, hex);
	len = print_hex_pointer(hex);
	free(hex);
	return(len);
}
