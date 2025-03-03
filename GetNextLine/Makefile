# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:33:19 by egelma-b          #+#    #+#              #
#    Updated: 2025/03/03 13:14:19 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
AR= ar -rcs
RM= rm -rf
SRC = get_next_line.c get_next_line_utils.c
OBJECTS = $(SRC:.c=.o)
HEADER = get_next_line.h

all:  $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(NAME) *.o 

%.o: %.c Makefile $(HEADER) 
	cc -Wall -Wextra -Werror -c $(SRC)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
