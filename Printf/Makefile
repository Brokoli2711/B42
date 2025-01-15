# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 11:56:55 by egelma-b          #+#    #+#              #
#    Updated: 2025/01/15 13:11:50 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_LIBFT= libft.a
AR= ar -rcs
RM= rm -rf
SRC = ft_print_char.c ft_print_string.c ft_print_percent.c ft_print_hex_pointer.c \
	ft_print_int.c ft_print_unsigned_int.c ft_print_Mhex_num.c ft_print_mhex_num.c \
	ft_printf.c
OBJECTS = $(SRC:.c=.o)
HEADER = libftprintf.h
PATH_LIBFT= utils/Libft

all: $(NAME_LIBFT) $(NAME)

$(NAME_LIBFT):
	make -C utils/Libft
	cp utils/Libft/libft.a $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_UTILS) $(HEADER)
	$(AR) $(NAME) *.o 

%.o: %.c Makefile $(HEADER) 
	cc -Wall -Wextra -Werror -c $(SRC)

clean:
	make -C utils/Libft clean
	$(RM) *.o

fclean: clean
	make -C utils/Libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
