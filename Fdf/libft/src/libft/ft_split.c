/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:26:46 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/05 14:25:30 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_free_split(char	**ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static size_t	ft_words(const char *s, char c)
{
	size_t	count;

	if (*s == '\0')
		return (0);
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static int	check_if_null(char **ptr, char *str)
{
	if (!str)
	{
		ft_free_split(ptr);
		return (0);
	}
	return (1);
}

static size_t	set_word_len(const char *s, char c)
{
	if (!ft_strchr((char *)s, c))
	{
		return (ft_strlen((char *)s));
	}
	return (ft_strchr((char *)s, c) - s);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	w_len;
	int		i;

	ptr = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			w_len = set_word_len(s, c);
			ptr[i++] = ft_substr(s, 0, w_len);
			if (!check_if_null(ptr, ptr[i - 1]))
				return (NULL);
			s += w_len;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}

/*int	main()
{
	char	*str = "hola como estas";
	char	**ptr;
	char	c = ' ';
	size_t	i;

	i = 0;
	ptr = ft_split(str, c);
	while(ptr[i])
	{
		printf("%s\n", ptr[i]);
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}*/
