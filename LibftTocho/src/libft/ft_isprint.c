/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:28:51 by egelma-b          #+#    #+#             */
/*   Updated: 2024/12/27 12:58:13 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
