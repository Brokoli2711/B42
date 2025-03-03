/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:45:03 by egelma-b          #+#    #+#             */
/*   Updated: 2025/03/03 13:33:22 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int	check_equals(char *file1, char *file2)
{
	char	*temp1;
	char	*temp2;
	int	f1;
	int	f2;
	
	f1 = open(file1, O_RDONLY);
	f2 = open(file2, O_RDONLY);
	if (f1 == -1 || f2 == -1)
	{
		if (f1 == -1) close(f1);
		if (f2 == -1) close(f2);
		return (-1);
	}
	while((temp1 = get_next_line(f1)) != NULL)
	{
		/*temp2 = get_next_line(f2);
		if(!strcmp(temp1, temp2))
			return (0);*/
		if (temp2 == NULL || strcmp(temp1, temp2) != 0)
		{                                      
			free(temp1);
			if (temp2) free(temp2);
			close(f1);
			close(f2);
			return (0);
		}
		free(temp1);
		free(temp2);
	}
	if (get_next_line(f2) != NULL)
	{
		close(f2);
		close(f1);
		return (0);
	}
	close(f1);
	close(f2);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if(check_equals(argv[1], argv[2]))
			printf("They are equals");
		else
			printf("Not equals");
	}
	return (0);
}
