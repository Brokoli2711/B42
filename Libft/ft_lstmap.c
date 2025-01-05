/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:09:16 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/05 22:25:33 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**nlst;
	t_list	*alst;
	size_t	size;
	size_t	i;
	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	nlst == (**t_list)malloc(size * sizeof(t_list));
	i = 0;
	while (i < size)
	{
		alst = ft_lstnew(f(lst->content));
		alst->next = lst->next;

	}
}
