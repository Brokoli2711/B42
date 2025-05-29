/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:31:44 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/29 12:44:53 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	count_args(const char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		count++;
		if (str[i++] == '\"')
		{
			while (str[i] && str[i] != '\"')
				i++;
			if (str[i] == '\"')
				i++;
		}
		else
			while (str[i] && str[i] != ' ')
				i++;
	}
	return (count);
}

static void	str_init_len(const char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

static char	*extract_token(const char *str, int *i)
{
	int		start;
	int		len;
	char	*token;

	len = 0;
	str_init_len(str, i);
	if (str[*i] == '\"')
	{
		start = ++(*i);
		while (str[*i + len] && str[(*i + len)] != '\"')
			len++;
		token = ft_strndup(str + start, len);
		*i += len;
		if (str[*i] == '\"')
			(*i)++;
	}
	else
	{
		start = *i;
		while (str[*i + len] && str[(*i + len)] != ' ')
			len++;
		token = ft_strndup(str + start, len);
		*i += len;
	}
	return (token);
}

char	**pipex_split(const char *str)
{
	int		i;
	int		j;
	int		arg_count;
	char	**args;

	i = 0;
	j = 0;
	arg_count = count_args(str);
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	while (j < arg_count)
		args[j++] = extract_token(str, &i);
	args[j] = NULL;
	return (args);
}
