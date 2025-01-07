/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:34:42 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/07 18:07:31 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		dest_len;
	size_t		src_len;
	size_t		i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (n <= dest_len)
		return (src_len + n);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (n - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*int	main()
{
	char	dest[12] = "pafanadass";
	const char	*src = "ADIIIIRU";
	char	dest2[12] = "pafanadass";
	const char	*src2 = "ADIIIIRU";
	size_t	n = 12;

	printf("%li\n", ft_strlcat(dest, src, n));
	printf("%s\n", dest);
	printf("%li\n", strlcat(dest2, src2, n));
	printf("%s\n", dest2);
	return (0);
}*/
