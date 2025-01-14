# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 11:56:55 by egelma-b          #+#    #+#              #
#    Updated: 2025/01/14 13:45:12 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prints.a
AR= ar -rcs
RM= rm -rf
SRC = ft_print_char.c ft_print_string.c ft_print_percent.c ft_print_hex_pointer.c
SRC_UTILS = utils/ft_strlen.c
OBJECTS = $(SRC:.c=.o)
OBJECTS_UTILS= $(SRC_UTILS:.c=.o)
HEADER = prints.h

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_UTILS) $(HEADER)
	$(AR) $(NAME) *.o

%.o: %.c Makefile $(HEADER) 
	cc -Wall -Wextra -Werror -c $(SRC) $(SRC_UTILS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
