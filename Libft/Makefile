# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:40:01 by elfo              #+#    #+#              #
#    Updated: 2025/01/05 16:13:15 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRC_BONUS = ft_lstnew.c
OBJECTS = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)
HEADER = .

all: $(NAME)

$(NAME): Makefile
	cc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER) 
	ar -rv $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: Makefile
	cc -Wall -Wextra -Werror -c $(SRC_BONUS) $(SRC) -I $(HEADER)
	ar -rv $(NAME) $(OBJECTS_BONUS) $(OBJECTS)
	ranlib $(NAME)
clean :
	rm -rf $(OBJECTS)
	rm -rf $(OBJECT_BONUS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
