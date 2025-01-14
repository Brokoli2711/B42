/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:53:38 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/14 13:17:19 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTS_H
# define PRINTS_H
#include <unistd.h>

size_t	ft_print_char(char c);
size_t	ft_print_string(char *str);
size_t	ft_strlen(const char *str);
size_t	ft_print_percent(void);
size_t	ft_print_hex_pointer(void *);
#endif
