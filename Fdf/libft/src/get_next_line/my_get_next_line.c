/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:49:50 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/02 16:50:59 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*make_rest(char *sline)
{
	int		i;
	int		n;
	char	*new_sline;

	i = 0;
	while (sline[i] != '\0' && sline[i] != '\n')
		i++;
	if (sline[i] == '\0')
	{
		return (free_sline(sline));
	}
	new_sline = ft_calloc(sizeof(char), (ft_strlen(sline) - i + 1));
	if (!new_sline)
		return (NULL);
	i++;
	n = 0;
	while (sline[i] != '\0')
		new_sline[n++] = sline[i++];
	free(sline);
	return (new_sline);
}

static char	*make_line(char *sline)
{
	int		i;
	char	*line;

	i = 0;
	if (sline[i] == '\0')
		return (NULL);
	while (sline[i] != '\0' && sline[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (sline[i] != '\0' && sline[i] != '\n')
	{
		line[i] = sline[i];
		i++;
	}
	if (sline[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*read_line(int fd, char *sline)
{
	int		n_char;
	char	*temp;

	if (!sline)
		sline = ft_calloc(1, 1);
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp)
		return (free_sline(sline));
	n_char = 1;
	while (n_char > 0)
	{
		n_char = read(fd, temp, BUFFER_SIZE);
		if (n_char == -1)
		{
			free(temp);
			return (free_sline(sline));
		}
		temp[n_char] = '\0';
		sline = ft_free_strjoin(sline, temp);
		if (ft_strchr(sline, '\n'))
			break ;
	}
	return (free(temp), sline);
}

void	free_static(void)
{
	static char	*sline;

	sline = NULL;
	if (sline)
		free(sline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*sline;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	sline = read_line(fd, sline);
	if (sline == NULL)
		return (free_sline(sline));
	line = make_line(sline);
	sline = make_rest(sline);
	return (line);
}
