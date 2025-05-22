/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:20:59 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/06 12:35:57 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_memb, size_t size)
{
	void	*ptr;

	if (size != 0)
		if (n_memb > SIZE_MAX / size)
			return (NULL);
	ptr = malloc(n_memb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n_memb * size);
	return (ptr);
}
