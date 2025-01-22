# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egelma-b <egelma-b@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 13:08:25 by egelma-b          #+#    #+#              #
#    Updated: 2025/01/22 10:51:22 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_uitoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
OBJECTS = $(SRC:.c=.o)
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(OBJECTS_BONUS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS_BONUS) $(OBJECTS)

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c -o $@ $<
clean :
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_BONUS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
