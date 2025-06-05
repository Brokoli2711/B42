/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/06/04 10:55:30 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current)
	{
		free(current->string);
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

void	add_node(t_list **list, char *str)
{
	t_list	*new_node;
	t_list	*last_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (str != NULL)
		new_node->string = malloc(ft_strlen(str) + 1);
	if (new_node->string == NULL)
		return (free(new_node));
	new_node->next = NULL;
	i = -1;
	while (str[++i] != '\0')
		new_node->string[i] = str[i];
	new_node->string[i] = '\0';
	last_node = find_last_node(*list);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

int	make_list(t_list **list, int fd)
{
	ssize_t	bytes_read;
	char	*buffer;

	while (check_newline(list) == false)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (-1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == 0)
				return (0);
			return (-1);
		}
		if (bytes_read <= BUFFER_SIZE)
			buffer[bytes_read] = '\0';
		add_node(list, buffer);
		free(buffer);
	}
	return (0);
}

void	end_node(t_list **list, t_list *last_node, int i)
{
	t_list	*current_node;
	int		j;

	current_node = malloc(sizeof(t_list));
	if (current_node == NULL)
		return ;
	current_node->next = NULL;
	while (last_node->string[i] != '\n' && last_node->string[i] != '\0')
		i++;
	if (last_node->string[i] == '\n' && last_node->string[++i] != '\0')
	{
		current_node->string = malloc(ft_strlen(last_node->string) - i + 1);
		if (current_node->string == NULL)
			return (free(current_node));
		j = 0;
		while (last_node->string[i] != '\0')
			current_node->string[j++] = last_node->string[i++];
		current_node->string[j] = '\0';
		free_list(list);
		*list = current_node;
		return ;
	}
	free(current_node);
	free_list(list);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*last_node;
	char			*next_line;
	int				check;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	check = make_list(&list, fd);
	if (list == NULL || check == -1)
		return (NULL);
	next_line = extract_line(list);
	last_node = find_last_node(list);
	end_node(&list, last_node, 0);
	return (next_line);
}
