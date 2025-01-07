/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:00:23 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/06 11:20:39 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*alst;

	if (!del || !*lst)
		return ;
	while (*lst)
	{
		alst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = alst;
	}
}
