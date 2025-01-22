/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:53:38 by egelma-b          #+#    #+#             */
/*   Updated: 2025/01/22 11:21:45 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTS_H
# define PRINTS_H
#include "utils/Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_percent(void);
int	ft_print_hex_pointer(void *);
int	ft_print_int(int c);
int	ft_print_unsigned_int(int c);
int	ft_print_Mhex_num(unsigned int c);
int	ft_print_mhex_num(unsigned int c);
int	ft_printf(const char *str, ...);
#endif
