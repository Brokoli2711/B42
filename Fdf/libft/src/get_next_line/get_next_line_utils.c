/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/06/04 10:59:35 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*find_last_node(t_list *list)
{
	t_list	*temp;

	temp = list;
	if (list == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

bool	check_newline(t_list **list)
{
	int		i;
	t_list	*last_node;

	i = 0;
	if (*list == NULL)
		return (false);
	last_node = find_last_node(*list);
	if (last_node == NULL || last_node->string == NULL)
		return (false);
	while (last_node->string[i] != '\0')
	{
		if (last_node->string[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

static char	*make_line(t_list *temp, int length)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	while (temp != NULL)
	{
		j = 0;
		while (temp->string[j] && temp->string[j] != '\n' && i < length)
			str[i++] = temp->string[j++];
		if (temp->string[j] == '\n' && i < length)
		{
			str[i++] = '\n';
			break ;
		}
		temp = temp->next;
	}
	str[i] = '\0';
	return (str);
}

//Calcula la llagarda de la linea i crea amb la funcio make_line
char	*extract_line(t_list *head)
{
	t_list	*temp;
	char	*str;
	int		length;
	int		i;

	temp = head;
	length = 0;
	if (head == NULL || head->string == NULL)
		return (NULL);
	while (temp != NULL)
	{
		i = 0;
		while (temp->string[i] && temp->string[i++] != '\n')
			length++;
		if (temp->string[i - 1] == '\n')
		{
			length++;
			break ;
		}
		temp = temp->next;
	}
	temp = head;
	str = make_line(temp, length);
	return (str);
}
