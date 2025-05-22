/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:59:10 by egelma-b          #+#    #+#             */
/*   Updated: 2025/03/24 12:58:17 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_hex(unsigned long long iptr)
{
	int	i;

	i = 0;
	if (iptr == 0)
		return (3);
	while (iptr != 0)
	{
		i++;
		iptr /= 16;
	}
	return (i + 2);
}

static int	point_to_hex(unsigned long long iptr)
{
	unsigned long long	digit;
	char				cdigit;

	if (iptr == 0)
		return (0);
	if (point_to_hex(iptr / 16) == -1)
		return (-1);
	digit = iptr % 16;
	if (digit < 10)
		cdigit = '0' + digit;
	else
		cdigit = 'a' + (digit - 10);
	if (write(1, &cdigit, 1) == -1)
		return (-1);
	return (0);
}

static int	num_to_hex(unsigned int num)
{
	unsigned int	digit;
	char			ndigit;

	if (num == 0)
		return (0);
	if (num_to_hex(num / 16) == -1)
		return (-1);
	digit = num % 16;
	if (digit < 10)
		ndigit = '0' + digit;
	else
		ndigit = 'a' + (digit - 10);
	if (write(1, &ndigit, 1) == -1)
		return (-1);
	return (0);
}

int     ft_print_char(int c)
{
     if (write(1, &c, 1) == -1)
                return (-1);
       return (1);   
}

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

int	ft_print_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_string(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[len])
		write(1, &str[len++], 1);
	return (ft_strlen(str));
}

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
