/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:48:03 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/22 10:50:04 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static size_t	count_size(unsigned n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	size_t	size;

	size = count_size(n);
	ptr = (char *)malloc(size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr[size] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}

/*int	main()
{
	int	n;
	char	*str;

	n = 16793;
	str = ft_itoa(n);
	printf("%s\n", str);
	return (0);
}*/
