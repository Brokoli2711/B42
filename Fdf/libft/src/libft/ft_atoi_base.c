/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:13:19 by elfo              #+#    #+#             */
/*   Updated: 2025/06/04 16:13:21 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	parse_base(const char *str, int result, int i, int base)
{
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * base + (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * base + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * base + (str[i] - 'a' + 10);
		else
			break ;
		i++;
	}
	return (result);
}

int	ft_atoi_base(const char *str, int base)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'x'))
		i += 2;
	result = parse_base(str, result, i, base);
	return (result * sign);
}
