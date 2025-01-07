/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:09:16 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/06 11:11:30 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*alst;
	t_list	*nlst;
 
	if (!f || !del)
		return (NULL);
	alst = NULL;
	while (lst)
	{
		if (!(nlst = ft_lstnew((*f)(lst->content))))
		{
			while (alst)
			{
				nlst = alst->next;
				ft_lstdelone(alst, del);
				alst = nlst;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&alst,nlst);
		lst = lst->next;
	}
	return (alst);
}
