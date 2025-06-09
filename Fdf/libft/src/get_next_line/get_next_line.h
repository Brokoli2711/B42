/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/06/09 14:46:46 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2097152
# endif

typedef struct s_list
{
	char			*string;
	struct s_list	*next;
}		t_list;

t_list	*find_last_node(t_list *list);
int		make_list(t_list **list, int fd);
bool	check_newline(t_list **list);
void	add_node(t_list **list, char *str);
void	free_list(t_list **list);
char	*extract_line(t_list *head);
char	*get_next_line(int fd);
int		ft_strcat(char *dest, char *src);
int		ft_strlen(const char *str);

#endif
