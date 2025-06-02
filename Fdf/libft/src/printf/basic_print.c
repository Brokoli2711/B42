/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:04:04 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:08:29 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_print_char(int c)
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
