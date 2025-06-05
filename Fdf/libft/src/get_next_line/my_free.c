/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:18:45 by egelma-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:22:36 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_free_strjoin(char *sline, char *temp)
{
	char	*new;

	new = ft_strjoin(sline, temp);
	free(sline);
	return (new);
}

char	*free_sline(char *sline)
{
	free(sline);
	return (NULL);
}
