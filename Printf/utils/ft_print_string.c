/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:45:16 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/14 13:07:21 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prints.h"

size_t	ft_print_string(char *str)
{
	if(!str)
		return (0);
	while(*str)
		write(1, str++, 1);
	return(ft_strlen(str));
}
