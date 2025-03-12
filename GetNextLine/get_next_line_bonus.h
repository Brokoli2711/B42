/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:51:32 by egelma-b          #+#    #+#             */
/*   Updated: 2025/03/12 12:44:33 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_BUFF_SIZE 2147483646
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE > 2147483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE MAX_BUFF_SIZE
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char				*get_next_line(int fd);
unsigned long		ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *sline, int c);
void				*ft_calloc(unsigned long int size, unsigned long int c);
#endif
