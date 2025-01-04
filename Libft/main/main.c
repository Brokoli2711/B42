/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:15:15 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/04 23:11:47 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

#define HOLA "Hola"
#define PATATA "Patata"

static void p_strlen(void)
{
	char	*str;

	str = HOLA;
	printf("The length of %s is %i\n", str, ft_strlen(str));
}

static void p_memmove(void)
{
	char    str1[] = PATATA;
        char    str2[] = HOLA;

        printf("The first string is %s. ", str1);
        ft_memmove(str1, str2, strlen(str2) + 1);
        printf("But after 'memmove is' %s\n", str1);
}

static void p_strlcpy(void)
{
	char	str1[] = PATATA;
	char	str2[] = HOLA;

        printf("The first string is %s. ", str1);
	printf("After passing 'strlcpy' the size is %li and string is %s\n", ft_strlcpy(str1, str2, ft_strlen(str2)), str1);
}

static void	p_strlcat(void)
{
	char	str1[10] = PATATA;
	const char	str2[] = HOLA;
	size_t	result;

	printf("The strings are %s and %s. ", str1, str2);
	result = ft_strlcat(str1, str2, 10);
	printf("The size of concatenated string is %li: %s\n", result, str1);
}

static void	p_strchr(void)
{
	char	str[] = "tripoulette";

	printf("%c, %i", 't' + 256, 't' + 256);
	printf("The string is %s and the first character %c is in position: %p ", str, 'o', ft_strchr(str, 't' + 256));
        printf("The string is %s and the last character %c is in position: %p ", str, 'o', ft_strrchr(str, 'o'));

}

static void	p_strncmp(void)
{
	char	str1[] = HOLA;
	char	str2[] = "Holila";

	printf("The strings comparated are %s and %s, and the difference with size '%i'is: %i\n", str1, str2, 3, ft_strncmp(str1, str2, 3));
	printf("The strings comparated are %s and %s, and the difference with size '%i'is: %i\n", str1, str2, 5, ft_strncmp(str1, str2, 5));

}

static void	p_memchr(void)
{
	
}

static void	p_memcmp(void)
{
	char	str1[] = HOLA;
	char	str2[] = "Holila";

	printf("The strings comparated are %s and %s, and the difference with size '%i'is: %i\n", str1, str2, 3, ft_memcmp(str1, str2, 3));
	printf("The strings comparated are %s and %s, and the difference with size '%i'is: %i\n", str1, str2, 5, ft_memcmp(str1, str2, 5));
}

static void	p_strnstr(void)
{
	char	src[] = "hohola";
	char	str[] = "hola";

	printf("%p", src + 2);
	printf("The string '%s' in the src '%s' is in position: '%p'\n", str, src, ft_strnstr(src, str, ft_strlen(src)));
}

static void	p_calloc(void)
{
	void	*p = ft_calloc(0, 1);

	free(p);
}

static void	p_strdup(void)
{
	char	str[] = PATATA;

	printf("The string is %s and the duplicated is: %s\n", str, ft_strdup(str));
}

static void	p_substr(void)
{
	char	str[] = PATATA;
	unsigned int	start = 2;
	size_t		len = 5;
	
	printf("The substring of %s beggining in %u position with %li length is: %s\n", str, start, len, ft_substr(str, start, len));
}

static void	p_strjoin(void)
{
	char	s1[] = PATATA;
	char	s2[] = HOLA;

	printf("The join string of %s and %s is: %s\n", s1, s2, ft_strjoin(s1, s2));
}

static void	p_strtrim(void)
{
	char	s1[] = PATATA;
	char	set[] = "ta";

	printf("The string is %s and the trimed string is '%s': %s\n", s1, set, ft_strtrim(s1, set));
}

static void	p_split(void)
{
	char	s1[] = "Hola como estas";

	char	**split = ft_split(s1, ' ');
	printf("The string is '%s' and the separator is '%c'. The split is: %s, %s, %s\n", s1, ' ', split[0], split[1], split[2]);
}

static void	p_itoa(void)
{
	int	nN = -2345;
	int	n0 = 0;
	int	n = 12345;

	printf ("the number %i is : %s. ", nN, ft_itoa(nN));
	printf ("the number %i is : %s. ", n0, ft_itoa(n0));
	printf ("the number %i is : %s.\n", n, ft_itoa(n));
}

int	main(void)
{
	p_strlen();
	p_memmove();
	p_strlcpy();
	p_strlcat();
	p_strchr();
	p_strncmp();
	p_memchr();
	p_memcmp();
	p_strnstr();
	p_calloc();
	p_strdup();
	p_substr();
	p_strjoin();
	p_strtrim();
	p_split();
	p_itoa();
}
