# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:40:01 by elfo              #+#    #+#              #
#    Updated: 2025/01/02 13:36:09 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OBJECTS = *.o
HEADER = .

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	ar -rv $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
