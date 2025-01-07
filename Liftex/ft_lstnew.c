/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:08:59 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/05 11:25:08 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if(!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
