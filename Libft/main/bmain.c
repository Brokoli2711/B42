/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:38:54 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/05 11:46:45 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void p_lstnew(void)
{
	t_list	*list;

	list = ft_lstnew((void *)42);
	printf("%p", list[0].content);
}

int	main(void)
{
	p_lstnew();
	return (0);
}
